#include "sensor_fusion.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>

static const p03_route_anchor_t anchors[] = {
    { 10U, 1.0 },
    { 20U, 2.0 }
};

static const p03_fusion_config_t valid_config = {
    anchors,
    sizeof(anchors) / sizeof(anchors[0]),
    100U,
    10U,
    0.25
};

static void test_fresh_sources_fuse(void)
{
    const p03_fusion_observation_t observation = {
        true, 1.10, 100U,
        true, 10U, 95U
    };
    p03_fusion_result_t result;

    assert(p03_fuse_route_progress(&valid_config, &observation, 100U,
                                   &result) == P03_FUSION_CALL_OK);
    assert(result.estimate_valid);
    assert(result.quality == P03_QUALITY_FUSED);
    assert(result.reason == P03_REASON_FUSED);
    assert(result.source_mask == (P03_SOURCE_ENCODER | P03_SOURCE_LANDMARK));
    assert(fabs(result.route_progress_m - 1.05) < 1e-9);
}

static void test_sample_age_limit_is_inclusive(void)
{
    const p03_fusion_observation_t observation = {
        true, 1.25, 0U,
        false, 0U, 0U
    };
    p03_fusion_result_t result;

    assert(p03_fuse_route_progress(&valid_config, &observation, 100U,
                                   &result) == P03_FUSION_CALL_OK);
    assert(result.estimate_valid);
    assert(result.quality == P03_QUALITY_DEGRADED);
    assert(result.reason == P03_REASON_ENCODER_ONLY);
}

static void test_source_skew_limit_is_inclusive(void)
{
    const p03_fusion_observation_t observation = {
        true, 1.10, 100U,
        true, 10U, 90U
    };
    p03_fusion_result_t result;

    assert(p03_fuse_route_progress(&valid_config, &observation, 100U,
                                   &result) == P03_FUSION_CALL_OK);
    assert(result.estimate_valid);
    assert(result.quality == P03_QUALITY_FUSED);
}

static void test_excessive_source_skew_uses_newer_source_as_degraded(void)
{
    const p03_fusion_observation_t observation = {
        true, 1.30, 100U,
        true, 10U, 80U
    };
    p03_fusion_result_t result;

    assert(p03_fuse_route_progress(&valid_config, &observation, 100U,
                                   &result) == P03_FUSION_CALL_OK);
    assert(result.estimate_valid);
    assert(result.quality == P03_QUALITY_DEGRADED);
    assert(result.reason == P03_REASON_SOURCE_TIME_SKEW);
    assert(result.source_mask == P03_SOURCE_ENCODER);
    assert(fabs(result.route_progress_m - 1.30) < 1e-9);
}

static void test_disagreement_is_uncertain_not_silently_selected(void)
{
    const p03_fusion_observation_t observation = {
        true, 1.50, 100U,
        true, 10U, 100U
    };
    p03_fusion_result_t result;

    assert(p03_fuse_route_progress(&valid_config, &observation, 100U,
                                   &result) == P03_FUSION_CALL_OK);
    assert(!result.estimate_valid);
    assert(result.quality == P03_QUALITY_UNCERTAIN);
    assert(result.reason == P03_REASON_SENSOR_DISAGREEMENT);
    assert(result.source_mask == (P03_SOURCE_ENCODER | P03_SOURCE_LANDMARK));
}

static void test_single_fresh_source_is_degraded(void)
{
    const p03_fusion_observation_t observation = {
        true, 1.25, 101U,
        true, 10U, 0U
    };
    p03_fusion_result_t result;

    assert(p03_fuse_route_progress(&valid_config, &observation, 101U,
                                   &result) == P03_FUSION_CALL_OK);
    assert(result.estimate_valid);
    assert(result.quality == P03_QUALITY_DEGRADED);
    assert(result.reason == P03_REASON_ENCODER_ONLY);
    assert(result.source_mask == P03_SOURCE_ENCODER);
    assert(fabs(result.route_progress_m - 1.25) < 1e-9);
}

static void test_unknown_landmark_does_not_override_encoder(void)
{
    const p03_fusion_observation_t observation = {
        true, 1.25, 100U,
        true, 999U, 100U
    };
    p03_fusion_result_t result;

    assert(p03_fuse_route_progress(&valid_config, &observation, 100U,
                                   &result) == P03_FUSION_CALL_OK);
    assert(result.estimate_valid);
    assert(result.quality == P03_QUALITY_DEGRADED);
    assert(result.reason == P03_REASON_UNKNOWN_LANDMARK);
    assert(result.source_mask == P03_SOURCE_ENCODER);
}

static void test_no_fresh_source_is_unknown(void)
{
    const p03_fusion_observation_t observation = {
        true, 1.25, 1U,
        true, 10U, 1U
    };
    p03_fusion_result_t result;

    assert(p03_fuse_route_progress(&valid_config, &observation, 1000U,
                                   &result) == P03_FUSION_CALL_OK);
    assert(!result.estimate_valid);
    assert(result.quality == P03_QUALITY_UNKNOWN);
    assert(result.reason == P03_REASON_NO_FRESH_SOURCE);
    assert(result.source_mask == P03_SOURCE_NONE);
}

static void test_future_timestamp_is_not_fresh(void)
{
    const p03_fusion_observation_t observation = {
        true, 1.25, 101U,
        false, 0U, 0U
    };
    p03_fusion_result_t result;

    assert(p03_fuse_route_progress(&valid_config, &observation, 100U,
                                   &result) == P03_FUSION_CALL_OK);
    assert(!result.estimate_valid);
    assert(result.quality == P03_QUALITY_UNKNOWN);
}

static void test_duplicate_anchor_ids_reject_configuration(void)
{
    const p03_route_anchor_t duplicate_anchors[] = {
        { 7U, 1.0 },
        { 7U, 2.0 }
    };
    const p03_fusion_config_t bad_config = {
        duplicate_anchors,
        sizeof(duplicate_anchors) / sizeof(duplicate_anchors[0]),
        100U,
        10U,
        0.25
    };
    const p03_fusion_observation_t observation = { false, 0.0, 0U,
                                                    false, 0U, 0U };
    p03_fusion_result_t result;

    assert(p03_fuse_route_progress(&bad_config, &observation, 100U,
                                   &result) == P03_FUSION_CALL_INVALID_CONFIG);
    assert(result.quality == P03_QUALITY_UNKNOWN);
}

int main(void)
{
    test_fresh_sources_fuse();
    test_sample_age_limit_is_inclusive();
    test_source_skew_limit_is_inclusive();
    test_excessive_source_skew_uses_newer_source_as_degraded();
    test_disagreement_is_uncertain_not_silently_selected();
    test_single_fresh_source_is_degraded();
    test_unknown_landmark_does_not_override_encoder();
    test_no_fresh_source_is_unknown();
    test_future_timestamp_is_not_fresh();
    test_duplicate_anchor_ids_reject_configuration();

    puts("P03 synthetic host-unit tests passed (not physical RSLK test data)");
    return 0;
}
