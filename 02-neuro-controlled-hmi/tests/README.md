# Project 02 — Test Plan

**State:** proposed only. The band model, host, official SDK, authorization, and data-collection approval are unverified. No tests have run and no data/results exist. Do not start a test or buy/install an unprovided dependency; if a gate fails, record it in `hardware/VERIFICATION.md` and continue to the next project.

## Prerequisite gates

| Gate | Pass evidence | If it fails |
|---|---|---|
| Physical identity | Manufacturer/model/revision physically read and matched to official manual | Do not use candidate specs; record blocker |
| Existing host/access | Compatible host/software already provided and approved; required SDK access/authentication available | No install or procurement; custom integration blocked |
| Safety/privacy | Manufacturer instructions, informed consent, institutional approval where required, data plan | No participant wears device and no biometric data are collected |
| Data quality | Official interface connected and reports fresh/ready data using documented status | No request logic or test data are produced |

## Proposed pilot matrix (only after all gates pass)

| Test ID | Setup / procedure | Acceptance target | Data / safety |
|---|---|---|---|
| T01 Identity/access | Record exact model, app/SDK/host version, authorization state | Exact device/manual match; all access already available | No credentials/serials in Git |
| T02 Connection | Use official interface; connect/disconnect and record status over 10 minutes | Stable supported connection; report all drops; no undocumented pairing | No HMI requests |
| T03 Signal ready | Seated 10-minute session with approved participant and exact vendor signal/contact indicator | Initial target ≥95% ready time; report per-session | Consent; minimum data only |
| T04 Idle baseline | 10-minute no-request block, three sessions | Initial target: zero false requests per block; do not imply rare events are ruled out | No robot or physical actuation |
| T05 Request trials | 20 marked request attempts plus 20 no-request epochs per session; repeat for three sessions | Initial target ≥80% request detection; false request target zero per 10-minute no-request block | Display-only; human confirms/rejects |
| T06 Gate comparison | Compare threshold-only against quality/freshness + dwell/hysteresis, both non-actuating | Report per-session false/missed request rate and latency; no pass presumed | Randomize/counterbalance where practical |
| T07 Latency | Timestamp marker to request display | Initial p95 ≤3 seconds; report p50, p95, misses and SDK timing limits | Do not remove quality gate to meet target |
| T08 Fail silent | Supported test hook for stale data, weak signal, disconnect, timeout, app restart | 100% of defined invalid-state cases suppress/clear requests | No robot connected |
| T09 Repeatability | Re-run calibration and test in three separate sessions | Report session range; do not pool repeated windows as independent users | Pseudonymous session IDs only |

Targets are initial design criteria for a small engineering pilot, not validated performance or safety limits. Adjust only before a new recorded experiment and explain the change.

## Metrics

- `request_detection_rate = true_positive_requests / (true_positive_requests + missed_requests)`
- `false_request_rate_per_hour = false_requests / no_request_observation_hours`
- `false_positive_fraction = false_requests / all_no_request_epochs`
- `latency_i = request_display_timestamp - prompt_or_event_marker_timestamp`; report median and 95th percentile
- `signal_ready_availability = vendor_ready_duration / total_session_duration`, only if the matched SDK exposes the status
- `dropout_rate = missing_or_stale_intervals / expected_intervals`, using the documented callback/timestamp cadence
- `fail_silent_pass_rate = correctly_suppressed_invalid_state_cases / injected_invalid_state_cases`

## Data handling

Keep only approved pseudonymized summaries in the repository. Do not commit raw EEG/PPG, names, participant keys, serials, credentials, or vendor Developer Codes. If raw data become essential, obtain separate consent/approval and store them outside Git under approved access controls. No tests, sample data, or results are present yet.
