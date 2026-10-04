# Project 01 — Research Plan

**State:** Research design only; no hardware trial, dataset, or result exists. All methods below are proposed.

## 1. Research question

On a small known indoor route graph, does wheel-encoder odometry corrected at reflectance-based floor landmarks improve checkpoint localization and mission completion versus encoder-only dead reckoning, and does a range-triggered stop/known-graph-replan policy reduce contact events compared with contact-switch-only behavior?

## 2. Existing approaches

- Differential-drive odometry integrates left/right wheel motion to estimate pose, but wheel-radius mismatch, effective wheelbase uncertainty, missed counts, and slip accumulate error. Borenstein and Feng describe systematic odometry calibration methods for wheelbase and unequal wheel diameters [9].
- Mobile-robot obstacle-avoidance approaches such as the Dynamic Window Approach reason about dynamically reachable velocities and collision risk [8]. This project does **not** claim to implement or validate DWA: one or three slow analog IR sensors on a constrained educational chassis do not provide the scene geometry or dynamic-obstacle observability required for a credible general-purpose controller.
- Route/landmark correction is a practical way to bound drift when the environment is known and can be marked. TI's RSLK curriculum covers encoder speed measurement/control and robot challenges but does not turn the base RSLK into a safety-certified industrial navigation system [1–6].

## 3. Proposed approach

If the verified listed RSLK has encoders and a reflectance array, use deterministic differential-drive odometry between mapped route nodes and correct the discrete route location at detected landmarks. Use a known graph and BFS/Dijkstra to select a mission path. Use a compatible forward range sensor only if one is identified in the supplied RSLK/Sensors stock; then a filtered, persistent obstacle event may stop the robot and mark a graph edge blocked. If no such sensor is present, non-contact obstacle detection and the P01 MVP are blocked—do not purchase or substitute a sensor. Bump switches, if present, provide only contact-stop behavior.

The documented MAX base does not include optional range sensors, and the inventory does not identify the RSLK variant or sensor-set contents. The proposed route-localization subsystem remains conditional on verifying listed hardware; obstacle avoidance is specifically conditional on a compatible in-stock non-contact sensor.

## 4. Hypothesis

For a repeatable marked course, landmark-corrected odometry will reduce median checkpoint-position error and improve mission completion relative to encoder-only odometry under the same speed/surface conditions. If—and only if—a compatible forward range sensor is identified in existing stock, conservative stop/replan behavior may lower contact counts in controlled static-obstacle trials compared with contact-switch-only behavior, at the cost of added mission time and possible false stops.

The obstacle-policy hypothesis is testable only if a compatible non-contact sensor is identified in existing stock. If not, defer that part of the study, record the blocker, and continue to the next project in sequence. The hypothesis may be rejected; no effect size is assumed in advance.

## 5. Experimental methodology

1. Verify and identify one physical robot and each sensor used. Use only toolchain/software already provided; if a required item is unavailable, record the affected work as blocked rather than acquiring it.
2. If the verified listed modules and existing tools permit, calibrate wheel counts, effective radii, track width, reflectance landmark signatures, and braking distance. Calibrate a range response only if a compatible range sensor is physically present in stock. Keep calibration data and configuration details.
3. Use a marked route/course only if it is explicitly provided as part of lab resources; none is listed in the supplied hardware inventory. Without it, mark landmark-navigation tests blocked and continue to the next project. Use static obstacles only if suitable safe objects are provided; otherwise defer obstacle trials.
4. Compare two localization modes on the same base route only after the relevant stock hardware/software gates pass: (A) encoder-only dead reckoning and (B) encoder odometry with landmark corrections. Randomize order when practical; hold robot, battery, speed, surface, payload, and route constant.
5. Compare obstacle policy only if an in-stock compatible non-contact sensor and an existing safe test area/obstacle are available. Use supervised, low-speed range-based stop/replan trials and a carefully bounded contact-only baseline; do not deliberately cause repeated impacts. If no compatible sensor is in stock, record obstacle-policy testing as blocked and continue to the next project.
6. Run repeated trials per configuration only when all required items are available, report all valid/aborted/failure runs, and explain exclusions. A suggested initial study uses at least 20 route trials per localization mode and a separate, smaller supervised obstacle series; increase sample size if variability is high.
7. Use independent measurements or fixed markers only if the needed existing tools/materials are available. Do not use robot odometry as ground truth. Record timestamps and raw data; no camera or other unlisted equipment is required.

## 6. Variables

- **Independent:** localization mode; obstacle policy; route length/turn count; obstacle placement; commanded speed; landmark spacing.
- **Dependent:** checkpoint position error; route completion/success; collision/contact count; false-stop count; detection-to-stop latency; stopping distance; mission time; path efficiency; number of re-plans.
- **Controlled:** physical robot and calibration, battery/cell set, payload, track surface and geometry, sensor mounting, firmware build, sampling periods, speed limit, lighting, target/obstacle material, and operator procedure.
- **Recorded context:** sensor validity, dropped/stale samples, wheel counts, failures, temperature/lighting where relevant, and any manual intervention.

## 7. Metrics

- **Checkpoint localization error:** Euclidean position difference (mm) between the estimate and independently measured checkpoint position; report median, spread, and maximum.
- **Mission success rate:** completed missions without manual correction divided by valid starts.
- **Path efficiency:** shortest feasible route length / actual measured travel length; define how detours and stops are treated.
- **Contact count:** number of bumper activations in a range-sensor obstacle trial; target is zero for a pass, but safety analysis and sample size must be defined before testing.
- **Detection latency:** time from the first valid threshold crossing to the motor-stop command, plus measured physical stopping distance.
- **False stops:** stops with no obstacle in the sensor's validated envelope per trial or travel distance.
- **Wheel-speed tracking:** steady-state absolute error, settling time, and left/right mismatch for a specified setpoint.
- **Fault handling:** correct motor-disabled state for injected stale sensor, missing encoder pulses, and no-route conditions.

For stopping safety, measure conservative deceleration and calculate `d_required = v × latency + v²/(2 × a_min) + margin`. The obstacle trigger must be placed farther away than this measured distance; the equation alone does not guarantee safety.

## 8. Dataset requirements

No dataset exists yet. Log each trial with: hardware ID/revision; software/toolchain and calibration versions; trial ID; map/route; timestamp; commanded and measured left/right speed; encoder increments; reflectance raw values/landmark confidence; range raw value/validity; bump state; mission state; node/edge; stop/replan/fault events; measured ground truth; outcome; and notes. Store raw logs unchanged; document units, sample interval, dropouts, parser version, and any exclusions. There are no personal or biometric signals in this project.

## 9. Expected contribution

A low-cost, reproducible study of how sparse floor landmarks bound differential-drive drift and how conservative range-based stop/replan logic changes route completion, false-stop rate, and contact rate on a constrained micro-robot. The contribution is an experimentally documented trade-off, not a claim of industry-ready navigation.

## 10. Possible limitations

- The RSLK version and stock sensor contents are unknown; MAX-specific assumptions may not hold.
- Reflectance landmarks require a prepared floor and favorable mounting/surface contrast.
- Encoder errors and wheel slip remain between landmarks; metric pose is not globally observable.
- Any candidate in-stock analog IR sensor may have a bounded, nonlinear response and environmental/material sensitivities; do not apply Sharp GP2Y0A21YK0F characteristics unless that exact sensor is identified. No listed non-contact sensor has been confirmed yet.
- The baseline and intervention cannot be compared safely if the bump-only condition requires repeated collision; use an abort condition and report the limitation.
- A small sample and one robot limit generalization. No certification or workplace safety performance is tested.

## 11. Future research

- Calibrate and compare systematic odometry error across multiple physical RSLK units.
- Quantify landmark spacing versus drift and false landmark recognition.
- Evaluate sensor count/mounting versus obstacle-detection blind spots and false stops only if compatible sensors are present in the supplied stock; otherwise leave that work blocked.
- Add an independent absolute localization reference only if available and verify its accuracy; compare it against route landmarks.
- Investigate uncertainty-aware speed limits based on measured stopping distance and localization confidence.
- Defer any custom interface or additional hardware; it is outside the supplied-inventory scope.

## References

1. TI, [TIRSLK-EVM product page](https://www.ti.com/product/TIRSLK-EVM/part-details/TIRSLK-EVM?ds_k=TIRSLK-EVM&DCM=yes).
2. TI, [TI-RSLK MAX User Guide, SEKP166](https://www.ti.com/lit/ml/sekp166/sekp166.pdf).
3. TI, [TI-RSLK MAX Construction Guide, SEKP164](https://www.ti.com/lit/ml/sekp164/sekp164.pdf).
4. TI, [MSP432P401R datasheet, SLAS826](https://www.ti.com/lit/ds/slas826e/slas826e.pdf).
5. TI, [RSLK MAX Motor Speed/Control Lab, SEKP146](https://www.ti.com/lit/pdf/sekp146).
6. TI, [Classic Maze Edition context: SWRP242](https://www.ti.com/lit/pdf/swrp242) and [SWRP187 DC motor lab](https://www.ti.com/lit/ml/swrp187/swrp187.pdf).
7. Pololu, [Sharp/Socle GP2Y0A21YK0F, item 136](https://www.pololu.com/product/136) and [sensor datasheet](https://www.pololu.com/file/0j85/gp2y0a21yk0f.pdf).
8. D. Fox, W. Burgard, and S. Thrun, “The Dynamic Window Approach to Collision Avoidance,” *IEEE Robotics & Automation Magazine*, 4(1), 23–33, 1997. [doi:10.1109/100.580977](https://doi.org/10.1109/100.580977).
9. J. Borenstein and L. Feng, “Measurement and Correction of Systematic Odometry Errors in Mobile Robots,” *IEEE Transactions on Robotics and Automation*, 12(6), 869–880, 1996. [doi:10.1109/70.544770](https://doi.org/10.1109/70.544770).
