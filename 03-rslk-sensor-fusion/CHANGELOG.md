# Changelog — RSLK Sensor Fusion and Autonomous Perception

## [v0.3.0] - 2026-10-04

- Added a hardware-independent C route-progress fusion core with freshness, inter-source time-skew, stale/future-sample, unknown-landmark, disagreement, and degraded/uncertain handling.
- Added synthetic host unit tests; they pass with GCC 12.2.0 using strict C11 warnings, and with AddressSanitizer/UndefinedBehaviorSanitizer.
- Updated firmware and test documentation to separate host logic verification from target firmware and physical RSLK testing.
- No board adapter, pins, sensor identity, calibration, target build, hardware integration, or physical results are claimed.

## [v0.2.0] - 2026-10-03

- Replaced generic placeholders with a conditional, inventory-only research plan and hardware identity gate.
- Recorded the shared RSLK/sensor-set blocker; TI-RSLK MAX capabilities remain conditional.
- Planned purchases remain $0. No board-target firmware, wiring, or physical tests/results are claimed.
