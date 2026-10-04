# Project 11 — MSP432 Real-Time Adaptive Industrial Control System (Plant Blocked)

**Status:** 🔴 Blocked — only controller development boards are inventoried; no process plant, actuator, or process sensor is identified.<br>
**Inventory:** 2 MSP432P401R LaunchPads; one is planned for P11 after sequential release from P08. Exact revision/condition unknown.<br>
**Evidence:** MSP432P401R is the listed MCU-family label. No control loop, plant, or simulation has been run.

> Do not substitute the LaunchPad's own LEDs, buttons, or MCU temperature for a controllable industrial process. No motor, heater, valve, sensor, driver, power stage, simulator, or PC is assumed. This project records a bounded research/design plan and blocker only, then continues to P12. No firmware or control tuning.

## 1. Problem statement

Define a safe, measurable adaptive-control experiment that could be conducted with listed equipment. The inventory currently provides a candidate controller board but no identified plant, actuator, or process feedback sensor, so no physical closed loop can be built.

## 2. Real-world application

Adaptive process control can adjust a controller when plant dynamics vary, but physical use requires a known process model, safe operating limits, independent measurement, and validated actuator interface. None of those plant-side items is inventoried for P11.

## 3. Why the problem matters

Tuning an adaptive controller on an unknown/unbounded plant can destabilize it or cause damage. A control-board demo is not a process-control result. Baseline PID/PI, plant identification, and safety limits must precede adaptation.

## 4. Project objectives

1. Record the missing plant/actuator/sensor/software information as a hard build blocker.
2. Specify the evidence required before any controller implementation: physical system identity, I/O/power compatibility, sample/actuation limits, safe envelope, and existing supported toolchain.
3. Define a future comparison of a fixed PI/PID baseline against a constrained adaptation method only if an already-listed plant becomes available and is approved.
4. Continue to P12 without buying, borrowing, or assuming a plant.

## 5. System requirements

- A named plant, compatible actuator/driver, feedback sensor, safe power path, and operating envelope must be present in the supplied inventory before physical control work.
- Sensor and actuator interfaces must be documented and physically verified; no unknown voltage/pin assumptions.
- Existing host computer/toolchain must be available; no download/install.
- A fixed, stable baseline and independent process measurement must precede adaptive control.
- Hard limits, actuator saturation, timeout, safe-state behavior, and human supervision must be designed before motion/heating/pressure.
- No real machine/process or safety loop may be controlled.

## 6. Hardware used

| Inventory item | Quantity | P11 use | Status |
|---|---:|---|---|
| MSP432P401R LaunchPad | 1 of 2 | Candidate controller board after P08 sequential release | Exact revision/condition/tools unknown |
| Plant, actuator, process sensor, driver, load | 0 identified for P11 | Required for meaningful physical control | Not established by supplied inventory |
| Computer/simulator/toolchain | 0 listed | Required for software/simulation workflow | Not confirmed |

## 7. Hardware not required

No external motor, heater, valve, pump, power stage, sensor, load, breadboard, simulator, network, or safety relay is included in scope.

## 8. External components required

None planned. Because plant-side equipment is absent/unidentified, the physical control loop is blocked. Do not acquire missing equipment or use another project's robot/motor/sensor as a substitute.

## 9. Estimated additional cost

**Planned additional cost: $0.** Missing plant, feedback, actuator, and tools are recorded blockers—not purchase suggestions.

## 10. System architecture

Future conditional architecture: verified process sensor → bounded estimator/error → fixed stable baseline controller → constrained adaptation supervisor → documented actuator interface → known plant → independent process measurement. Present status: only the controller board is listed; every plant-side block is unavailable/unverified.

## 11. Connection diagram

See diagrams. They show the missing boundary and are not wiring instructions. No external connection is specified.

## 12. Pin mapping

No P11 pin map. Exact MSP432 LaunchPad revision is unknown, and no I/O peripheral is selected. Never wire a hypothetical actuator from a generic LaunchPad pinout.

## 13. Communication protocol

Not applicable. No network or supervisory client is in inventory.

## 14. Software architecture

Paper design only: validated sensor sample → fixed controller baseline → adaptation limiter/update rule → independent safety monitor → actuator command. All runtime modules are unimplemented and blocked on plant, software, and safety requirements.

## 15. Algorithm

A future study should first characterize a known plant, then compare fixed PI/PID with a bounded, slow parameter update constrained by a verified safe region. Do not apply model-reference adaptive control or online gain updates to an unknown plant. No numeric gains or model are available.

## 16. Working principle

For a known plant, sample feedback, compute setpoint error, apply a validated baseline command, and allow adaptation only under explicit limits and independent fault supervision. In this repository, no closed loop exists; MSP432 presence alone is not a control experiment.

## 17. Step-by-step build procedure

See [docs/TUTORIAL.md](docs/TUTORIAL.md). Current steps are documentary: confirm board identity; inventory plant-side hardware and tools; list absent dependencies; stop. Continue to P12. No hardware assembly or code.

## 18. Firmware setup

Deferred. No firmware may be written until plant, I/O, safety, supported toolchain, and test plan are defined.

## 19. Software setup

No software or simulation tool is listed. No downloads/install; software work is blocked.

## 20. Web interface setup

Not applicable.

## 21. Testing procedure

No physical/simulation tests have run or are possible from current verified inventory. Only a documented requirements review can proceed. A future loop requires unit/interface tests, fixed-controller baseline, saturation/fault tests, then adaptation comparison.

## 22. Expected output

Current deliverable is a verified blocker/research specification, not a running controller or performance result.

## 23. Troubleshooting

See [docs/TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md). If someone proposes controlling a motor/heater or treating an LED as a plant, stop and correct scope.

## 24. Performance metrics

Future metrics: setpoint tracking error/IAE or RMSE, settling/overshoot, control effort/saturation, stability/fault rate, and performance over repeated plant conditions. Numerical targets cannot be set without a plant/model and reference measurement.

## 25. Limitations

No plant, actuator, process sensor, safe power stage, independent measurement, simulator, or development host is confirmed. The board alone cannot demonstrate adaptive process control. Internal MCU temperature/LED output are not a suitable physical plant for this project. No safety certification or control performance claim.

## 26. Future improvements

Only if the supplied inventory is revised with a physically present, documented, safe plant and the lab provides a supported toolchain. First establish a fixed baseline; adaptation remains optional and must be justified by measured variable dynamics.

## 27. Research opportunities

Which bounded adaptation rule improves tracking over a validated fixed PI/PID when a verified plant's parameters vary within a documented safe envelope? This is explicitly blocked until plant and measurement access are established.

## 28. References

- TI, [MSP-EXP432P401R LaunchPad product/software page](https://www.ti.com/tool/MSP-EXP432P401R) — confirms controller-board identity only, not the missing process plant.
- Åström & Hägglund, [Advanced PID Control](https://www.isa.org/products/advanced-pid-control) — baseline/tuning reference.
- Slotine & Li, [Applied Nonlinear Control](https://www.pearson.com/en-us/subject-catalog/p/applied-nonlinear-control/P200000003242/9780130408907) — adaptive-control theory; no implementation is specified.
- [Supplied inventory](../HARDWARE_INVENTORY.md).

## 29. License

See root [LICENSE](../LICENSE); repository licensing pending. No source code or external dataset is included.

## Reproducibility checklist

- [ ] Missing plant-side hardware explicitly recorded
- [ ] No other project's hardware implicitly reassigned
- [ ] Exact LaunchPad model/revision recorded before future use
- [ ] Safe operating envelope and fixed baseline required before adaptation
- [ ] No firmware, hardware connection, test, or result claimed
- [ ] Continue sequentially to P12
