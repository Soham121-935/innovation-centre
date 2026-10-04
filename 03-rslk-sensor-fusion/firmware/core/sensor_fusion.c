#include "sensor_fusion.h"

#include <math.h>

static bool p03_config_is_valid(const p03_fusion_config_t *config)
{
    size_t i;
    size_t j;

    if ((config == NULL) || (config->anchors == NULL) ||
        (config->anchor_count == 0U) ||
        !isfinite(config->max_disagreement_m) ||
        (config->max_disagreement_m < 0.0)) {
        return false;
    }

    for (i = 0U; i < config->anchor_count; ++i) {
        if (!isfinite(config->anchors[i].route_progress_m)) {
            return false;
        }
        for (j = i + 1U; j < config->anchor_count; ++j) {
            if (config->anchors[i].landmark_id ==
                config->anchors[j].landmark_id) {
                return false;
            }
        }
    }

    return true;
}

static bool p03_is_fresh(uint64_t sample_ms, uint64_t now_ms,
                         uint64_t max_age_ms)
{
    return (sample_ms <= now_ms) && ((now_ms - sample_ms) <= max_age_ms);
}

static const p03_route_anchor_t *p03_find_anchor(
    const p03_fusion_config_t *config,
    uint16_t landmark_id)
{
    size_t i;

    for (i = 0U; i < config->anchor_count; ++i) {
        if (config->anchors[i].landmark_id == landmark_id) {
            return &config->anchors[i];
        }
    }

    return NULL;
}

static void p03_set_unknown(p03_fusion_result_t *result,
                            p03_fusion_reason_t reason)
{
    result->estimate_valid = false;
    result->route_progress_m = 0.0;
    result->quality = P03_QUALITY_UNKNOWN;
    result->reason = reason;
    result->source_mask = P03_SOURCE_NONE;
}

p03_fusion_call_status_t p03_fuse_route_progress(
    const p03_fusion_config_t *config,
    const p03_fusion_observation_t *observation,
    uint64_t now_ms,
    p03_fusion_result_t *result)
{
    bool encoder_fresh;
    bool landmark_fresh;
    bool landmark_known = false;
    const p03_route_anchor_t *anchor = NULL;

    if ((observation == NULL) || (result == NULL)) {
        return P03_FUSION_CALL_INVALID_ARGUMENT;
    }

    result->evaluated_at_ms = now_ms;
    p03_set_unknown(result, P03_REASON_NO_FRESH_SOURCE);

    if (!p03_config_is_valid(config)) {
        return P03_FUSION_CALL_INVALID_CONFIG;
    }

    encoder_fresh = observation->encoder_valid &&
        isfinite(observation->encoder_progress_m) &&
        p03_is_fresh(observation->encoder_timestamp_ms, now_ms,
                     config->max_sample_age_ms);

    landmark_fresh = observation->landmark_valid &&
        p03_is_fresh(observation->landmark_timestamp_ms, now_ms,
                     config->max_sample_age_ms);

    if (landmark_fresh) {
        anchor = p03_find_anchor(config, observation->landmark_id);
        landmark_known = (anchor != NULL);
    }

    if (encoder_fresh && landmark_fresh && landmark_known) {
        const uint64_t encoder_time = observation->encoder_timestamp_ms;
        const uint64_t landmark_time = observation->landmark_timestamp_ms;
        const uint64_t time_skew_ms = (encoder_time >= landmark_time)
            ? (encoder_time - landmark_time)
            : (landmark_time - encoder_time);
        const double difference =
            fabs(observation->encoder_progress_m - anchor->route_progress_m);

        if (time_skew_ms > config->max_source_skew_ms) {
            result->estimate_valid = true;
            result->quality = P03_QUALITY_DEGRADED;
            result->reason = P03_REASON_SOURCE_TIME_SKEW;
            if (encoder_time >= landmark_time) {
                result->route_progress_m = observation->encoder_progress_m;
                result->source_mask = P03_SOURCE_ENCODER;
            } else {
                result->route_progress_m = anchor->route_progress_m;
                result->source_mask = P03_SOURCE_LANDMARK;
            }
            return P03_FUSION_CALL_OK;
        }

        result->source_mask = P03_SOURCE_ENCODER | P03_SOURCE_LANDMARK;
        if (difference > config->max_disagreement_m) {
            result->estimate_valid = false;
            result->route_progress_m = 0.0;
            result->quality = P03_QUALITY_UNCERTAIN;
            result->reason = P03_REASON_SENSOR_DISAGREEMENT;
            return P03_FUSION_CALL_OK;
        }

        result->estimate_valid = true;
        /* Halve before adding to avoid overflow for large finite inputs. */
        result->route_progress_m =
            (observation->encoder_progress_m / 2.0) +
            (anchor->route_progress_m / 2.0);
        result->quality = P03_QUALITY_FUSED;
        result->reason = P03_REASON_FUSED;
        return P03_FUSION_CALL_OK;
    }

    if (encoder_fresh) {
        result->estimate_valid = true;
        result->route_progress_m = observation->encoder_progress_m;
        result->quality = P03_QUALITY_DEGRADED;
        result->reason = (landmark_fresh && !landmark_known)
            ? P03_REASON_UNKNOWN_LANDMARK
            : P03_REASON_ENCODER_ONLY;
        result->source_mask = P03_SOURCE_ENCODER;
        return P03_FUSION_CALL_OK;
    }

    if (landmark_fresh && landmark_known) {
        result->estimate_valid = true;
        result->route_progress_m = anchor->route_progress_m;
        result->quality = P03_QUALITY_DEGRADED;
        result->reason = P03_REASON_LANDMARK_ONLY;
        result->source_mask = P03_SOURCE_LANDMARK;
        return P03_FUSION_CALL_OK;
    }

    if (landmark_fresh && !landmark_known) {
        result->reason = P03_REASON_UNKNOWN_LANDMARK;
    }

    return P03_FUSION_CALL_OK;
}
