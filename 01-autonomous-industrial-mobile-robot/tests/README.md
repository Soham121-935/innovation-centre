# Project 01 — Test Plan

**Status:** test definitions only. No hardware tests or measured results exist. These tests are conditional on required parts/tools being explicitly provided in the supplied inventory/setup. The inventory does not list a prepared course/landmarks, matched cells, host/toolchain, or compatible range sensor. If any required item is absent, mark its test and full MVP blocked and continue to the next project; do not purchase or substitute.

## Test sequence

| ID | Test | Setup / procedure | Proposed pass condition | Recorded data |
|---|---|---|---|---|
| H-01 | Hardware identity | Record RSLK SKU, chassis/LaunchPad/sensor revisions and labels | One manufacturer-documented hardware profile matches the physical parts | Photos, asset IDs, model/revisions |
| H-02 | Power/jumper safety | Power disconnected; inspect the exact kit and cells included in listed stock | All conditions match exact kit guide; if matched cells are not supplied, power test is blocked | Checklist and board markings; no power applied before gate |
| B-01 | LaunchPad smoke | Only if a compatible host and target-specific software are explicitly provided; detached/no chassis motion | Correct target debugs/flashes and documented output appears; zero motor activity | Versions/log/observation if run; otherwise record software/host blocker |
| S-01 | Bump switches | One at a time, motor outputs disabled | Every installed switch has an unambiguous idle/pressed state and requests safe stop | Raw bits, bounce, response time |
| S-02 | Reflectance array | Only if array and light/dark test surfaces are provided and verified; no test samples/course are listed | Each channel is distinguishable/repeatable enough to identify configured landmarks; otherwise mark test blocked | Raw values only if the required provided surfaces/tools exist |
| S-03 | Encoders | Raise chassis, rotate each wheel by hand, then measured wheel revolutions | Both wheel channels count; actual counts/rev convention is established; stationary false counts quantified | Edge/count logs and calibration |
| S-04 | In-stock non-contact range sensor | Only if a compatible sensor is found in supplied RSLK/Sensors inventory and its exact interface is verified | Valid envelope and calibration documented; invalid/stale samples detected; if none is in stock, mark obstacle-sensing MVP blocked | Data only if test can be safely run with provided tools; otherwise blocker |
| A-01 | Motor direction and stop | Wheels raised, low speed, one motor at a time | Correct wheel/direction; zero command stops; reachable physical power-off remains available | Command, duty, wheel response, faults |
| C-01 | Wheel-speed control | Wheels raised first, measured speed step, then bounded floor check | Stable response within predeclared speed/error limits; no sustained oscillation/stall | Setpoint, measured speed, control interval, tuning, voltage/battery |
| N-01 | Odometry calibration | Straight runs, turns/square paths, measured floor reference | Per-robot scale and systematic turn error are quantified and reproducible | Counts, distance/angle reference, pose error |
| N-02 | Landmark correction | Only if a known marked course/landmarks are explicitly provided; none are listed | Median checkpoint error and all failures reported for both modes; otherwise mark route-localization blocked | Node detections and independent measurement only if run with provided resources |
| N-03 | Route/missions | Clear route; target nodes and at least one alternate path | Mission reaches goal without manual steering; invalid graph route safely rejected | Mission state, route, completion/time, intervention |
| O-01 | Static obstacle stop/replan | Only if an in-stock compatible range sensor, provided safe course/landmarks, and all verified robot safety resources exist; these gates are unresolved | Stop-before-contact and re-route/blocked response measured; if any required item is absent, mark test/MVP blocked and do not add it | Metrics only if test is run with provided resources |
| F-01 | Fault handling | Inject only safe software-level stale sensor, no-pulse, and no-route conditions | Motors remain/return disabled and an explicit fault is logged | Fault type, detection latency, state, reset procedure |
| E-01 | Repeatability | Freeze hardware/calibration/map; repeated end-to-end runs | Report success/failures, spread, and outliers; no single-run claims | Trial IDs, conditions, full log set |

## Metric definitions

- `mission_success_rate = completed valid missions / valid mission starts`.
- `checkpoint_error_mm = distance(estimated checkpoint pose, independent measured checkpoint pose)`.
- `path_efficiency = shortest feasible route length / measured traveled route length`.
- `false_stop_rate = non-obstacle stops / trial or traveled distance` (choose and freeze denominator before collection).
- `range_detection_rate = detected placed obstacles / obstacles presented within the calibrated envelope`.
- `reaction_latency = motor-stop command time - first valid obstacle-threshold time`.
- `stopping_margin = measured obstacle clearance at rest - (speed × latency + speed²/(2 × conservative deceleration))`; require an additional safety margin established by supervised testing.
- `speed_error = commanded wheel speed - measured encoder wheel speed`; report steady-state error, settling time, and oscillations.

Proposed acceptance thresholds are not fixed until the sensor, speed, stopping distance, and measurement uncertainty are characterized. A candidate early milestone is at least 18 successful completions in 20 clear-route runs; this is a **planning target**, not measured performance or a safety guarantee. For obstacle trials, any unexpected contact is a failed trial and triggers review before further testing.

## Data and results

Use the schema in [data/README.md](../data/README.md). Preserve raw values before filtering, all failures, calibration/version metadata, and test videos only where privacy/permission allow. Store actual summaries and analysis under `results/`; do not fill in sample or fabricated results. Current result: **none**.
