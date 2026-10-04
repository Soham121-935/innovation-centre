# Project 01 — Autonomous Industrial Mobile Robot

**Status:** 🟡 In Development — inventory-only desk research documented; physical build blocked pending stock verification; sequential documentation has proceeded through P14<br>
**Hardware evidence:** TI-RSLK MAX capabilities below are documented but **conditional**. The lab entry only says “RSLK”; its exact family, chassis revision, controller, accessories, condition, and sensor-set contents have not been physically verified.<br>
**Firmware/results:** none generated; no bench tests have been performed.

> **Build gate:** Do not wire or flash the conditional MAX pin map until the actual kit is identified. The TI-RSLK MAX and older/classic TI-RSLK Maze Edition are not assumed to share the same chassis, power board, sensors, or pin map. Start at [hardware/VERIFICATION.md](hardware/VERIFICATION.md).

## 1. Problem statement

Demonstrate a small autonomous mobile-robot system that can execute a mapped indoor inspection/delivery mission, estimate where it is on a known route, detect an obstacle before contact, stop safely, and select a safe alternate route when one exists. This is a controlled laboratory prototype, not an industrially certified autonomous mobile robot.

## 2. Real-world application

A low-speed warehouse/factory inspection or sample-delivery route is the application analogy. A bounded course with named checkpoints would represent aisles/work cells, but no course or floor-marking materials are listed or assumed; route testing remains blocked unless such a resource is explicitly provided. A detected obstacle would represent a temporarily blocked route edge only if compatible non-contact sensing is in stock.

## 3. Why the problem matters

A useful mobile robot needs more than motion: wheel slip creates odometry drift, sensors have false alarms and blind spots, and a mission needs explicit recovery behavior. The project makes these limitations measurable using an existing differential-drive platform, rather than claiming precise localization or dependable obstacle avoidance from a line sensor alone.

## 4. Project objectives

1. Identify the exact RSLK and every sensor/actuator used from lab stock.
2. Characterize the motor/encoder platform and calibrate a wheel-speed loop.
3. Build route localization from wheel odometry corrected at verified floor landmarks.
4. Detect non-contact obstacles using a verified range sensor; keep bump switches as a last-resort stop.
5. Plan a mission over a small known route graph and re-route around a blocked edge when possible.
6. Add fault handling, serial event logs, reproducible trials, and quantitative performance measures.
7. Use only listed inventory; if required range sensing or power items are not found in stock, mark the affected MVP/test blocked and proceed without purchasing or substituting parts.

## 5. System requirements

- Low-speed operation indoors on a flat, bounded, non-slip test track.
- Differential-drive wheel-speed control with independent left/right feedback if the verified platform has its documented encoders.
- A known route map with detectable checkpoint/junction landmarks; the map is supplied/configured, not learned by SLAM.
- A verified non-contact front obstacle sensor for the obstacle-detection MVP. Contact bump switches alone do **not** satisfy this requirement.
- Safe-stop behavior on a bump, stale/invalid range data, encoder stall/no-motion timeout, or explicit operator stop.
- A simple, deterministic route planner; mission state and fault reason available in a local log.
- No wireless, cloud service, display, external MCU, or external motor driver required for the MVP.

## 6. Hardware used

### Planned from the supplied inventory (not yet checked out)

| Item | Inventory quantity | Planned use | Evidence |
|---|---:|---|---|
| Robotics System Lab Kit (RSLK) | 10 | One platform for P01 | Family and version unverified |
| RSLK Sensors | 3 sets | Inspect first for compatible non-contact range sensors | Contents/part numbers unverified |
| MSP432P401R LaunchPad | 2 in inventory | Use only if the verified RSLK kit lacks its own compatible LaunchPad | Exact revision and kit contents unverified |

### Conditional reference configuration: TI-RSLK MAX / TIRSLK-EVM

TI documentation describes the MAX reference configuration as a modified MSP-EXP432P401R LaunchPad plus a Romi-based TI-RSLK chassis board; dual DRV8838 motor drivers; two gearmotors with magnetic Hall-effect encoder assemblies; two bumper-switch boards (six normally-open contacts); an eight-channel QTRX reflectance array; chassis LEDs and power regulation. The MAX guide says six AA cells are required but not included. Three Sharp GP2Y0A21YK0F analog range sensors are listed as optional/not included.

**MSP432P401R MCU capabilities (only if this is the fitted target):** 32-bit Arm Cortex-M4F up to 48 MHz; up to 256 KB flash and 64 KB SRAM; 14-bit, 1-MSPS SAR ADC; timer/PWM-capable Timer_A and 32-bit timers; GPIO; eUSCI UART/SPI/I²C; DMA; comparators; and CRC/AES hardware. The MCU datasheet does not list an integrated CAN controller, DAC, Wi-Fi, or BLE radio. The MSP-EXP432P401R LaunchPad adds an XDS110-ET debug/programming interface, USB debug/backchannel, buttons, and LEDs; USB is not being claimed as a native MSP432 USB peripheral.

The RSLK MAX chassis has motor/power/sensor interfacing; it is **not** a range scanner, IMU, camera, GNSS receiver, or localization system. The base MAX line array measures surface reflectance, not distance to a forward obstacle. The official MAX user guide is the source for all conditional component and pin-map claims; see [hardware/VERIFICATION.md](hardware/VERIFICATION.md) and [hardware/pin-map.md](hardware/pin-map.md).

## 7. Hardware not required

No Arduino, ESP32/ESP8266, Raspberry Pi, separate motor driver, second MCU, IMU, camera, GPS, screen, cloud service, or radio is part of this inventory-only plan. Do not introduce unlisted alternatives; if the verified platform cannot meet a requirement with listed stock, mark that requirement blocked.

## 8. External components required

**No external component purchases are in scope.** Use only items present in the supplied inventory. First inspect the RSLK kit and all three RSLK Sensors sets. Batteries, route/floor markers, and a prepared course are not listed; compatible non-contact range sensing is unverified. If required power, sensing, or landmarks are not explicitly provided in the supplied stock, mark the affected subsystem and the full P01 MVP blocked; do not substitute, fabricate, or order missing items.

For the conditional TI-RSLK MAX reference, the published kit guide says six AA cells are required but not included, and its Sharp range sensors are optional. This means a MAX robot can only be powered if suitable cells are already in the lab, and the required non-contact obstacle-detection feature can only be demonstrated if a compatible sensor is already in the listed stock. Bump switches alone are contact detection and do not satisfy that feature.

## 9. Estimated additional cost

**Planned external purchases: $0.** Existing hardware acquisition cost is unknown. Any component not in the supplied inventory is excluded; if it proves essential to the selected RSLK configuration, mark the affected build/test as blocked rather than purchasing a substitute. The inventory and compatibility check must still determine whether the listed hardware is complete and usable. See [BOM/bom.md](BOM/bom.md).

## 10. System architecture

The proposed platform separates sensing, wheel-speed control, route localization, mission planning, and safety supervision. The conditional MAX implementation uses the onboard MSP432 and chassis drivers. A known route graph and physical landmarks are required; neither a prepared course nor marker materials are listed, so route-localization is blocked unless such a course is explicitly provided. Encoder odometry and the reflectance array can only correct route position at verified landmarks. A compatible range sensor triggers stop/replan only if physically confirmed in listed stock. Without provided landmarks and in-stock range sensing, the full P01 MVP remains blocked; no markers or alternate sensors are added. The detailed control loops, navigation state, safety state machine, and algorithm trade-offs are in [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md).

## 11. Connection diagram

See [system block diagram](diagrams/01-system-block-diagram.md), [hardware connection diagram](diagrams/02-hardware-connection.md), [data flow](diagrams/03-data-flow.md), and [software architecture](diagrams/04-software-architecture.md). Pin-level connections are conditional and in [hardware/pin-map.md](hardware/pin-map.md).

## 12. Pin mapping

No universal RSLK pin map can be asserted from the inventory label. A conditional TI-RSLK MAX reference table is provided in [hardware/pin-map.md](hardware/pin-map.md), sourced from TI's MAX user guide. It applies only after the physical chassis/LaunchPad match is confirmed. Classic Maze Edition or a custom kit requires a separate source-backed mapping.

## 13. Communication protocol

The MVP is local and autonomous. Use the LaunchPad's documented USB/XDS110 backchannel for development logs and operator commands. The exact UART port/settings will be taken from the physical LaunchPad revision and TI guide; no radio protocol or network dependency is proposed. A concise telemetry record should include timestamp, mission state, checkpoint, encoder counts/estimated pose, range validity/value, bump state, and fault/event code.

## 14. Software architecture

Planned modules: `board_profile/`, `drivers/{motor,encoder,reflectance,bump,range}/`, `processing/{filter,calibration}/`, `control/{wheel_speed,odometry}/`, `navigation/{route_graph,planner,landmark_localization}/`, `application/{mission_fsm,fault_manager,telemetry}/`. Hardware-specific code is isolated behind a MAX profile only if the exact MAX target is confirmed.

## 15. Algorithm

- Sample sensors at bounded intervals; reject invalid/stale values and use small median/hysteresis/persistence filters where appropriate.
- Run independent wheel-speed PI loops using encoder feedback after bench identification and tuning.
- Compute differential-drive dead-reckoning between landmarks; correct/reset the topological pose at known route markers.
- Represent the test route as a small graph. Use breadth-first search for equal edge cost or Dijkstra for measured, nonnegative edge costs.
- Stop and mark the current edge blocked when the range condition persists for a calibrated number/time of samples. Re-plan only on the known graph; do not steer blindly around the obstacle. If no safe path exists, stay stopped.
- Use bump switches, watchdog/freshness checks, and encoder no-motion checks as independent fault conditions. Do not infer motor current or temperature because these are not confirmed in the base kit.

No ML is proposed: the state is small and observable, and deterministic filtering, odometry, graph search, and control are easier to validate with limited data.

## 16. Working principle

A mission chooses a sequence of named route nodes. The wheel controller produces calibrated left/right motion; encoders estimate travel. When the floor array sees a known marker/junction, the localizer snaps the discrete route state to that landmark, limiting accumulated drift. The range sensor watches the forward path; persistent detection causes a controlled stop and blocked-edge update. A graph search either finds a permitted alternate path or ends the mission in a safe stopped state. Logs allow repeatability and analysis.

## 17. Step-by-step build procedure

Follow the gated sequence in [docs/TUTORIAL.md](docs/TUTORIAL.md). The first step is physical model/revision identification, not wiring. Then verify the LaunchPad independently, inspect the power jumper and battery stock, test sensors without motion, verify encoders, and test motors on blocks at low speed. Only after those checks should navigation firmware be integrated. Stop at any mismatch between the actual kit and the conditional MAX reference.

## 18. Firmware setup

The conditional MAX target uses MSP432P401R, for which TI documents CCS and RSLK C starter resources. These are references, not confirmation that software is supplied. Use only a compatible toolchain already available after identifying the LaunchPad revision; if absent, defer firmware. The MAX reference LaunchPad includes an XDS110-ET programmer/debugger, conditional on physical identification.

**There is no firmware source yet.** The prompt asks for an initial test firmware but also says not to start coding and requires the exact board to be verified first. The hardware gate takes precedence: the first source file should be a no-motion LaunchPad smoke test only after the target is confirmed; motor-control code follows after the physical safety and pin-map checks. See [firmware/README.md](firmware/README.md).

## 19. Software setup

No PC application is required by the proposed MVP. Use CCS/RSLK examples only if a compatible toolchain is already provided and available for the verified target; record versions if so. Do not download, install, purchase, or substitute unprovided software. If the required toolchain is absent, firmware work is blocked and the project sequence continues.

## 20. Web interface setup

Not applicable to the MVP. A local dashboard would add complexity without improving navigation or safety; serial telemetry is sufficient for initial testing.

## 21. Testing procedure

Use the test matrix in [tests/README.md](tests/README.md) only when every required device/tool/course is physically part of the provided setup and verified: identity/power checks; board-only program; individually verified sensors; motors with wheels raised; wheel calibration; speed control; then mapped missions/obstacle trials. If required power, range sensing, course/landmarks, or compatible software is not in the supplied setup, mark the affected test and full MVP blocked and continue to the next project—do not add a dependency. No test has yet been run.

## 22. Expected output

During operation, expect a defined boot/self-test state, then mission state/checkpoint updates, valid encoder/range telemetry, and an explicit stop or route-replan event when an obstacle/fault occurs. These are **design expectations only**; they have not been observed on lab hardware.

## 23. Troubleshooting

See [docs/TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md). Any electrical or board-revision mismatch is a stop-and-verify condition, not a reason to try alternate pins experimentally.

## 24. Performance metrics

Proposed measurements (not results):

- Mission success rate: completed missions / total valid trials.
- Checkpoint localization error: distance between estimated/expected and measured checkpoint pose.
- Path efficiency: shortest feasible mapped route length / actual traveled length.
- Obstacle detection rate and false stops: detected placed obstacles and false stops per trial.
- Reaction latency: timestamp from first valid obstacle threshold crossing to motor-stop command.
- Contact count: bumper activations in non-contact obstacle trials.
- Wheel-speed tracking: steady-state error, settling time, and left/right mismatch.
- Fault recovery: correct safe-stop/replan behavior across injected sensor-stale, blocked-route, and no-motion cases.

Initial acceptance targets must be set after sensor characterization and safety review; do not claim any target as achieved until measured over repeatable trials. A suggested early gate is 20 controlled mission runs with repeat count and failure causes reported, then choose thresholds based on the baseline.

## 25. Limitations

- Exact lab RSLK is unknown; the architecture/pin map may need substantial revision.
- Base MAX hardware does not include the optional Sharp range sensors; compatible stock range capability is unconfirmed.
- No route course or floor markers are listed, so landmark-corrected localization cannot be tested unless they are explicitly provided.
- Wheel odometry drifts with slip, wheel mismatch, floor changes, and missed pulses. Landmark corrections would make this topological, not precise metric localization.
- No IMU, compass, camera, lidar, depth sensor, absolute-position reference, motor-current sensor, or safety-rated scanner is confirmed.
- Even if one or more compatible range sensors are found in stock, their constrained coverage would not provide industrial-grade perception for all materials, angles, lighting, or moving obstacles; no external sensor kit is part of this plan.
- The robot is a small educational platform; it is not suitable for people, payload handling, production machinery, or unsupervised operation.

## 26. Future improvements

1. Calibrate effective wheel radii, wheelbase, and encoder scale per robot.
2. Add marker confidence and recovery behavior for missed/ambiguous floor landmarks.
3. Evaluate multiple range-sensor viewpoints only if compatible units are already present in the listed stock and tests show a blind spot; do not add sensors.
4. Test battery-dependent motor behavior and robust stale-data/fault handling.
5. Compare additional localization signals only if such sensors are found in the supplied inventory and verified; do not claim SLAM without required sensing and validation.
6. Custom PCBs and any unlisted hardware are out of scope.

## 27. Research opportunities

The main research question is whether wheel-encoder odometry corrected by low-cost route landmarks improves repeatable route completion and checkpoint localization versus encoder-only motion, while a range-triggered stop/replan policy reduces contact events on a small known map. See [docs/RESEARCH.md](docs/RESEARCH.md) for the hypothesis, variables, trial plan, and literature.

## 28. References

- TI, [TIRSLK-EVM product page](https://www.ti.com/product/TIRSLK-EVM/part-details/TIRSLK-EVM?ds_k=TIRSLK-EVM&DCM=yes).
- TI, [TI-RSLK MAX User Guide, SEKP166](https://www.ti.com/lit/ml/sekp166/sekp166.pdf).
- TI, [TI-RSLK MAX Construction Guide, SEKP164](https://www.ti.com/lit/ml/sekp164/sekp164.pdf).
- TI, [MSP432P401R/MSP432P401M datasheet, SLAS826](https://www.ti.com/lit/ds/slas826e/slas826e.pdf).
- TI, [MSP-EXP432P401R documentation/download page (includes User's Guide SLAU597)](https://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP-EXP432P401R/latest/index_FDS.html).
- TI, [RSLK MAX motor speed/control lab, SEKP146](https://www.ti.com/lit/pdf/sekp146).
- TI, [DRV8838 datasheet](https://www.ti.com/lit/ds/symlink/drv8838.pdf).
- Pololu, [Sharp/Socle GP2Y0A21YK0F datasheet](https://www.pololu.com/file/0j85/gp2y0a21yk0f.pdf) — consult only if a sensor with this exact model is identified in the supplied stock; not a sourcing recommendation.
- D. Fox, W. Burgard, and S. Thrun, “The Dynamic Window Approach to Collision Avoidance,” *IEEE Robotics & Automation Magazine*, 4(1), 23–33, 1997, [doi:10.1109/100.580977](https://doi.org/10.1109/100.580977).
- J. Borenstein and L. Feng, “Measurement and Correction of Systematic Odometry Errors in Mobile Robots,” *IEEE Transactions on Robotics and Automation*, 12(6), 869–880, 1996, [doi:10.1109/70.544770](https://doi.org/10.1109/70.544770).

## 29. License

Repository license selection is pending. See the root [LICENSE](../LICENSE); do not distribute this project as open source until the owner chooses a license and third-party terms are checked.

## Build versions

- **Version 1 — Proposed MVP, currently blocked:** would require a verified in-stock front range sensor, provided route/course landmarks, matched power/hardware, and supported software; no missing dependency is to be added.
- **Version 2 — Advanced research only:** characterize additional viewpoints only if multiple compatible sensors are already in the supplied stock; other extensions remain limited to verified listed hardware and measurements.
- **Version 3 — Research/product prototype:** uncertainty-aware route/speed selection and robust landmark recovery evaluated against measured baselines; optional custom PCB only after interface/requirements freeze. This remains an educational prototype, not a safety-certified AMR.
