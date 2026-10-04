# Project 03 — RSLK Sensor Fusion and Autonomous Perception

**Status:** 🟡 In Development — identity/blocker research recorded; no physical RSLK or sensor set has been inspected.<br>
**Inventory hardware:** RSLK (10 listed) and RSLK Sensors (3 sets); exact family, controller, sensors, revisions, accessories, and condition are unknown.<br>
**Evidence:** TI RSLK MAX documents are used only as a conditional reference. A small hardware-independent C fusion core has passed synthetic host tests; it assumes only abstract caller-supplied inputs. No pins, capabilities, source code, measurements, or results are attributed to lab hardware.

> P01 and P02 hardware gates remain unresolved, so sequential work has progressed to P03. Use only listed stock. If the physical RSLK/sensors do not provide at least two documented, useful sensing modalities, record the limitation and continue to P04. Do not buy, borrow, or substitute equipment from outside the inventory. Board-target firmware and physical integration remain gated.

## 1. Problem statement

Determine whether measurements from distinct, verified sensors already supplied with an RSLK can be fused to improve route-state confidence over a single-sensor baseline. The word “sensor fusion” does not establish that the kit contains an IMU, range sensor, or any particular sensor set.

## 2. Real-world application

A small mobile platform could use wheel motion, floor reflectance, contact state, and any verified additional stock sensor to report a more reliable route state. This is an educational, bounded-course study—not industrial perception or a safety system. No test course is listed.

## 3. Why the problem matters

Each modality observes different quantities and has different failure modes. Encoders estimate wheel travel but drift; reflectance detects surface patterns but not free-space obstacles; bump switches report contact only. Fusion is valuable only when the signals and their interfaces are physically verified and time-aligned.

## 4. Project objectives

1. Identify one RSLK variant and every included/associated sensor from the supplied inventory.
2. Build a source-backed sensor-capability and interface matrix without transferring MAX pins to another revision.
3. Define a minimal fusion MVP using only two or more confirmed independent modalities; otherwise mark the MVP blocked.
4. Compare the fused decision with each single-sensor baseline using safe, repeatable tests and explicit uncertainty/fault states.
5. Keep the robot stationary until P01 has verified the platform, power path, and safety procedure.

## 5. System requirements

- Exact chassis/controller/board revisions and sensor part numbers must be recorded before wiring or code.
- A claimed modality must be listed in inventory or explicitly documented as included with the verified RSLK kit.
- The conditional TI-RSLK MAX reference has wheel encoders, a reflectance array, and bump switches; optional range sensors are not base-kit content. None is confirmed for the lab unit.
- No external course, markers, computer, software, range sensor, IMU, camera, or wireless module is assumed.
- Missing modalities or a required test environment block the experiment; do not fill gaps with an unlisted part.
- Fault, stale-data, disagreement, and out-of-range states must be visible and fail safe.

## 6. Hardware used

| Listed item | Quantity | Proposed use | Lab status |
|---|---:|---|---|
| Robotics System Lab Kit (RSLK) | 10 | One sequential platform if released and verified | Variant/controller/condition unknown |
| RSLK Sensors | 3 sets | Inspect exact contents; use only sensors physically present | Contents/interfaces unknown |

**Conditional reference only:** TI-RSLK MAX documentation describes wheel encoders, a QTRX reflectance array, and bumper switches. The base MAX does not include the optional Sharp range sensors. Do not apply these details unless the physical kit matches the MAX reference.

## 7. Hardware not required

No additional rangefinder, IMU, camera, lidar, GPS, external MCU, wireless node, development host, marker kit, actuator, or cloud service is in scope. Do not add any unlisted sensor to make fusion possible.

## 8. External components required

None planned. If fewer than two suitable listed modalities are verified, the fused-perception MVP is blocked; do not acquire another sensor. If a computer, test course, or software not named in the supplied inventory is required, that step is also blocked.

## 9. Estimated additional cost

**Planned external cost: $0.** Acquisition cost of listed equipment is unknown. Missing stock blocks the related objective; no unlisted hardware/software is costed or recommended. See [BOM](BOM/bom.md).

## 10. System architecture

Verified sensors → timestamp/freshness checks → individual calibrated estimates → consistency/fault gate → simple deterministic fusion → route-state/confidence output. Candidate MAX modalities are conditional only. Motor control is outside the first P03 research milestone and requires P01 safety verification.

## 11. Connection diagram

See the conditional diagrams in `diagrams/`. No direct wiring is specified until the chassis and each sensor model/revision are identified.

## 12. Pin mapping

No universal RSLK map is asserted. Use a model- and revision-specific manufacturer pin table only after inspection. Current pin-map file is an identity gate, not wiring instructions.

## 13. Communication protocol

No radio protocol is planned. If the verified controller offers an existing documented local debug/status interface, it may be used only when the matching host/software is already available. Otherwise no telemetry host is assumed.

## 14. Software architecture

A portable fusion function is implemented in `firmware/core/`: it accepts caller-normalized encoder progress and a caller-mapped route landmark, checks freshness and source-time alignment before applying the disagreement gate, and reports fused/degraded/uncertain/unknown state. Synthetic host unit tests pass. This abstract API does not establish that those sensors or signals exist in lab stock. Verified board profile, sensor drivers, timebase, calibration, safety/fault integration, target build, and physical logging remain unimplemented and gated.

## 15. Algorithm

The portable prototype uses a transparent baseline: caller-supplied encoder route progress and a caller-mapped landmark are checked for freshness, inter-source time skew, and agreement; their midpoint is returned only when both are usable, time-aligned, and within the caller-supplied disagreement threshold. Excessively skewed samples use only the newer source and are marked degraded; single-source estimates are degraded, and time-aligned disagreement is uncertain. The implementation is host-tested on synthetic values only. No physical sensor model, calibration, timing, truth reference, or threshold is validated. Avoid Kalman/particle filters and ML until those measurements exist.

## 16. Working principle

Convert each sensor reading to a documented estimate with timestamp and validity. Reject stale or implausible input; compare independent estimates; update route confidence only when agreement criteria derived from measured data pass. If the sensors disagree or a required signal disappears, report uncertain/fault rather than inventing position.

## 17. Step-by-step build procedure

Follow [docs/TUTORIAL.md](docs/TUTORIAL.md): inventory identity → sensor identification → existing-documentation review → compatibility matrix → stationary signal checks if all required tools are supplied → design freeze. Stop before wiring or powering if any physical identity/power/interface is unknown.

## 18. Firmware setup

The portable host-testable core and build command are documented in [`firmware/README.md`](firmware/README.md). It is not target firmware. Board-specific startup, drivers, pin/clock configuration, and flashing instructions cannot be provided until the exact controller/sensors, safe interfaces, and an already-available compatible toolchain are confirmed. Do not copy Project 01 conditional MAX code or pin maps.

## 19. Software setup

No software installation is in scope. Use only a compatible package already provided to the lab. If absent, record the blocker and continue to P04.

## 20. Web interface setup

Not applicable. No web server or cloud service is planned.

## 21. Testing procedure

The portable C core's synthetic host unit tests pass; the command, cases, and limitations are documented in [`firmware/tests/README.md`](firmware/tests/README.md). No physical, sensor, target-compiler, or RSLK tests have run. The gated test matrix starts with identity/interface checks and stationary modality characterization; route-fusion measurement requires a provided course/reference and at least two compatible stock modalities, none currently confirmed. See [`tests/README.md`](tests/README.md).

## 22. Expected output

If all hardware gates pass, a timestamped route-state/confidence and sensor-validity record. No sample readings or results are supplied; no detection performance is claimed.

## 23. Troubleshooting

See [docs/TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md). Resolve physical identity and interface errors from exact manufacturer documentation; do not trial alternate pins or sensor substitutions.

## 24. Performance metrics

Proposed: per-modality availability/dropout, event timestamp skew, landmark detection precision/recall, route-state error against independent reference, false-accept/uncertain-state rate, and fault-detection latency. Numeric targets must be set after characterization; no measured baseline exists.

## 25. Limitations

RSLK family and sensor-set contents are unknown; the MAX description is conditional. A base reflectance array does not measure distance, and bump switches are contact-only. No course/markers, independent ground-truth system, host, or software is listed. Sensor fusion cannot compensate for missing observability.

## 26. Future improvements

Only if supported by verified listed hardware and measured limitations: characterize cross-sensor timing, compare confidence gates, and repeat on a second released RSLK. Do not add sensors, SLAM, ML, or extra compute hardware.

## 27. Research opportunities

Can a simple agreement/validity gate reduce false route-state updates versus reflectance-only or encoder-only baselines on a verified RSLK? Study only if stock modalities and a provided test route support a measurable comparison.

## 28. References

- TI, [TI-RSLK MAX User Guide, SEKP166](https://www.ti.com/lit/ml/sekp166/sekp166.pdf) — conditional MAX features, safety, and interface.
- TI, [TI-RSLK MAX motor speed/control lab, SEKP146](https://www.ti.com/lit/pdf/sekp146) — conditional encoder/motor test context.
- TI, [Classic TI-RSLK Maze Edition context, SWRP242](https://www.ti.com/lit/pdf/swrp242) — distinct classic architecture.
- [Supplied hardware inventory](../HARDWARE_INVENTORY.md) — inventory names/counts only.

## 29. License

Repository license decision is pending; see the root [LICENSE](../LICENSE). No third-party code or sensor data have been added.

## Reproducibility checklist

- [ ] Physical RSLK family/revision and sensor-set contents recorded
- [ ] Every used modality matched to official documentation
- [ ] Two independent, compatible in-stock signals verified, or blocker recorded
- [ ] No unlisted components/software assumed
- [ ] Test route/reference and safety procedure provided
- [ ] Fusion baseline, test matrix, versions, and limitations documented
- [ ] Portable host-test evidence is distinguished from target firmware, physical data, and measured results
