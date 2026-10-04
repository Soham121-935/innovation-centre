#ifndef P03_SENSOR_FUSION_H
#define P03_SENSOR_FUSION_H

/*
 * P03 hardware-independent fusion core.
 *
 * Inputs are already-normalized route-progress observations. This module does
 * not read pins, call sensor drivers, assume an RSLK revision, or move a robot.
 * A board adapter may be written only after the physical sensors/controller
 * and their units/timing have been verified.
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint16_t landmark_id;
    double route_progress_m;
} p03_route_anchor_t;

typedef struct {
    const p03_route_anchor_t *anchors;
    size_t anchor_count;
    uint64_t max_sample_age_ms;
    uint64_t max_source_skew_ms;
    double max_disagreement_m;
} p03_fusion_config_t;

typedef struct {
    bool encoder_valid;
    double encoder_progress_m;
    uint64_t encoder_timestamp_ms;

    bool landmark_valid;
    uint16_t landmark_id;
    uint64_t landmark_timestamp_ms;
} p03_fusion_observation_t;

typedef enum {
    P03_QUALITY_UNKNOWN = 0,
    P03_QUALITY_DEGRADED,
    P03_QUALITY_FUSED,
    P03_QUALITY_UNCERTAIN
} p03_fusion_quality_t;

typedef enum {
    P03_REASON_NO_FRESH_SOURCE = 0,
    P03_REASON_ENCODER_ONLY,
    P03_REASON_LANDMARK_ONLY,
    P03_REASON_SOURCE_TIME_SKEW,
    P03_REASON_UNKNOWN_LANDMARK,
    P03_REASON_SENSOR_DISAGREEMENT,
    P03_REASON_FUSED
} p03_fusion_reason_t;

enum {
    P03_SOURCE_NONE = 0U,
    P03_SOURCE_ENCODER = 1U << 0,
    P03_SOURCE_LANDMARK = 1U << 1
};

typedef struct {
    bool estimate_valid;
    double route_progress_m;
    p03_fusion_quality_t quality;
    p03_fusion_reason_t reason;
    unsigned int source_mask;
    uint64_t evaluated_at_ms;
} p03_fusion_result_t;

typedef enum {
    P03_FUSION_CALL_OK = 0,
    P03_FUSION_CALL_INVALID_ARGUMENT,
    P03_FUSION_CALL_INVALID_CONFIG
} p03_fusion_call_status_t;

/*
 * Fuse one encoder-progress observation with a mapped route landmark.
 *
 * If both fresh sources are close enough in timestamp and agree within
 * max_disagreement_m, their unweighted midpoint is returned. If source time
 * skew exceeds max_source_skew_ms, the newer source is returned as DEGRADED.
 * If two time-aligned fresh sources disagree, return an invalid/uncertain
 * result; never silently choose one. Missing/stale sources yield UNKNOWN.
 *
 * `now_ms`, timestamps, route coordinates, age/skew limits and disagreement
 * limits are caller-defined. Thresholds must come from verified hardware data.
 */
p03_fusion_call_status_t p03_fuse_route_progress(
    const p03_fusion_config_t *config,
    const p03_fusion_observation_t *observation,
    uint64_t now_ms,
    p03_fusion_result_t *result);

#endif /* P03_SENSOR_FUSION_H */
