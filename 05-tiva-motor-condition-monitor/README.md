# Project 05 — Real-Time Industrial Motor Condition Monitoring

**Status:** 🟡 In Development — motor/host measurement path is blocked pending exact TIVA and compatible listed plant verification.<br>
**Inventory hardware:** 5 “TIVA LaunchPad” units; RSLK kits also listed, but no motor/driver/current-sensor pairing is confirmed for P05.<br>
**Evidence:** EK-TM4C123GXL documentation is a conditional reference. No motor has been connected, no current/vibration sensor is confirmed, and no results exist.

> Inventory-only scope. No unlisted motor, driver, current sensor, accelerometer, power supply, software, or data-acquisition instrument is assumed. If no compatible motor/feedback path exists in the supplied stock, record the blocker and proceed to P06. Do not code yet.

## 1. Problem statement

Assess whether measured motor-speed feedback from a verified, existing motor platform can identify repeatable operating deviations without adding sensors. The inventory does not identify a motor-test rig or compatible signal path.

## 2. Real-world application

A bounded lab study could monitor a low-speed drive and flag a persistent speed response outside a measured healthy baseline. It is not predictive maintenance, a protective trip, or an industrial safety system.

## 3. Why the problem matters

Motor faults can appear as changed speed, vibration, current, temperature, or sound, but a sensorless speed residual does not identify the fault cause. A project must distinguish measured variables from inferred condition.

## 4. Project objectives

1. Identify exact TIVA LaunchPad MCU/revision and any compatible, listed motor/driver/encoder assembly.
2. Check whether the RSLK stock includes an accessible motor/encoder path compatible with the verified TIVA board; do not assume cross-board wiring.
3. If verified signals exist, establish a healthy, low-risk baseline and test software-level missing/stale-feedback detection.
4. Report false alarms and fault limits; do not claim current, vibration, bearing, or predictive diagnostics without corresponding listed sensors/data.

## 5. System requirements

- Exact LaunchPad and motor/driver interfaces documented before connection.
- A motor and feedback signal must be explicitly available from supplied stock; no external motor/driver/sensor.
- No deliberate stall, destructive fault seeding, or unsafe load.
- A compatible existing toolchain/host must be available; otherwise firmware and measurements remain blocked.
- Monitoring output is advisory only and must not be used as a safety trip.

## 6. Hardware used

| Item | Inventory quantity | P05 use | Status |
|---|---:|---|---|
| TIVA LaunchPad | 5 | One controller, only after exact model/revision is read | Family/MCU/revision unknown |
| RSLK | 10 | Possible existing motor/encoder source only if verified and released | Model and controller/driver path unknown |
| Motor/current/vibration sensor | None specified | No such sensor is assumed | No current/vibration/torque measurement confirmed |

Conditional TI EK-TM4C123GXL reference documentation describes PWM/QEI-capable MCU resources; this does not establish the inventory board model or a motor driver/sensor.

## 7. Hardware not required

No added motor, VFD, current clamp, shunt, accelerometer, microphone, tachometer, separate driver, load bank, or external MCU is in scope.

## 8. External components required

None planned. If no compatible motor/encoder path exists in supplied inventory, the physical monitoring MVP is blocked. Do not procure a test motor, sensor, or driver.

## 9. Estimated additional cost

Planned additions: **$0**. Existing hardware cost is unknown. Missing plant, tools, host software, or sensors are blockers.

## 10. System architecture

Conditional path: verified TIVA board → documented interface to an in-stock motor/driver and encoder → measured command/speed response → baseline residual/fault gate → local advisory output. If no compatible listed plant/feedback is found, there is no buildable P05 hardware system.

## 11. Connection diagram

See diagrams; no actual pins or motor wiring are defined. The conditional EK-TM4C123GXL board is not proof of the lab TIVA model.

## 12. Pin mapping

Not verified. Exact TIVA part, LaunchPad revision, motor driver, and encoder are unknown. Do not use example QEI/PWM pins as wiring instructions.

## 13. Communication protocol

No radio/network protocol planned. Local serial logging is conditional on an existing host/toolchain and documented board connection; none is confirmed.

## 14. Software architecture

After gates: board profile → verified motor/encoder driver → timestamped speed estimator → baseline/residual and stale-feedback checks → advisory state/log. No source code exists.

## 15. Algorithm

Start with a simple measured speed residual against an operating-point baseline and a persistence window. It can detect deviation, not diagnose cause. A missing encoder event is a sensor/drive fault indicator, not motor-current evidence. No ML or predictive-maintenance model is justified.

## 16. Working principle

Compare commanded and measured speed under a repeatable, safe operating condition. Flag persistent deviation or missing feedback for operator review. Require valid calibration and state uncertainty when the signal is stale. No motor action is triggered.

## 17. Step-by-step build procedure

Follow `docs/TUTORIAL.md`: identify TIVA → identify stock motor/driver/feedback → validate electrical compatibility from official docs → confirm existing toolchain and safe test procedure → stationary checks → low-risk baseline only if all gates pass. Otherwise record blocker and continue to P06.

## 18. Firmware setup

No firmware. Exact board and existing toolchain are unknown. Do not write or flash code.

## 19. Software setup

No software install is planned. Use only an already-provided compatible package; missing software blocks development.

## 20. Web interface setup

Not applicable; no web/cloud system.

## 21. Testing procedure

No tests have run. Proposed tests: identity/compatibility, sensor/encoder baseline, repeated no-load speed response, safe software-level dropout detection, and repeatability. Do not intentionally stall or damage a motor. See `tests/README.md`.

## 22. Expected output

If gates pass, advisory status with speed trace, residual, valid/fault state, and timestamps. No example data or measured anomalies are supplied.

## 23. Troubleshooting

See `docs/TROUBLESHOOTING.md`; stop on unknown wiring, unexpected current/heat/noise, motor stall, or incompatible board identity.

## 24. Performance metrics

Proposed: speed estimation error, residual distribution under baseline, dropout/stale-data detection latency, false alarm rate per operating hour, missed software-injected sensor faults, and run-to-run repeatability. No current/vibration/temperature metric is available without a verified listed sensor.

## 25. Limitations

TIVA variant, plant, feedback path, host/toolchain, and measurement tools are unresolved. Speed residual alone cannot diagnose bearings, imbalance, lubrication, winding faults, or load change. No certification or protective shutdown is tested.

## 26. Future improvements

Only if supported by verified listed equipment: repeat baselines at multiple safe speed commands and evaluate drift. Do not add accelerometers/current sensors/motors or induce physical faults.

## 27. Research opportunities

Can a simple speed-residual gate distinguish ordinary repeat variation from a deliberately software-injected missing-feedback condition on an existing compatible motor/encoder setup? This question is blocked until the platform is verified.

## 28. References

- TI, [EK-TM4C123GXL LaunchPad page](https://www.ti.com/tool/EK-TM4C123GXL) and [User Guide SPMU296](https://www.ti.com/lit/pdf/spmu296) — conditional TIVA reference only.
- TI, [TM4C123GH6PM datasheet](https://www.ti.com/lit/gpn/tm4c123gh6pm) — only if this MCU matches the physical board.
- TI, [TI-RSLK MAX User Guide](https://www.ti.com/lit/ml/sekp166/sekp166.pdf) — possible stock motor/encoder reference only; P01 physical identity remains unknown.
- [Supplied hardware inventory](../HARDWARE_INVENTORY.md).

## 29. License

See root [LICENSE](../LICENSE); decision pending. No third-party code is included.

## Reproducibility checklist

- [ ] Exact TIVA model/revision recorded
- [ ] Existing motor/driver/feedback path identified and compatibility documented
- [ ] No unlisted sensor/tool/plant assumed
- [ ] Safe test and non-destructive fault protocol reviewed
- [ ] Metrics and baseline defined before any run
- [ ] No code/results claimed before verification
