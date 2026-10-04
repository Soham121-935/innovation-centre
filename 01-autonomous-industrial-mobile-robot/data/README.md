# Project 01 — Data

No data have been collected.

## Planned trial log schema

One CSV row per sample or event (record which mode is used). Freeze the sampling cadence and units before collection.

| Field | Unit/type | Meaning |
|---|---|---|
| `timestamp_ms` | monotonic milliseconds | Time since boot/trial start |
| `trial_id`, `robot_asset_id`, `firmware_version`, `map_version`, `calibration_version` | string | Reproducibility metadata |
| `mission_state`, `fault_code`, `event_code` | enum/string | State and transitions |
| `node_id`, `edge_id`, `target_node`, `planned_route` | string/structured | Topological map state |
| `enc_left_delta`, `enc_right_delta` | counts / interval | Raw wheel increments |
| `speed_left`, `speed_right`, `command_left`, `command_right` | calibrated units | Measured wheel speed and command |
| `reflectance_raw_0..7` | timer ticks or documented raw unit | Individual sensor readings |
| `range_raw`, `range_valid` | ADC counts and boolean | Optional range data; do not mix raw and calibrated distance |
| `bump_bits` | bitmask | Contact-switch states |
| `pose_est_x`, `pose_est_y`, `pose_est_theta` | mm, mm, rad or deg (freeze convention) | Estimated pose; topological correction state must also be logged |
| `ground_truth_x`, `ground_truth_y`, `ground_truth_theta` | mm, mm, rad or deg | Independent measured reference, if available |
| `outcome`, `operator_note` | enum/text | Completion, failure, abort, or observed event |

Preserve an unmodified raw log and store processed outputs separately. Record exact sensor model/mounting, time base, dropped-sample behavior, calibration lookup, and analysis script/version. Do not include personal data or credentials.
