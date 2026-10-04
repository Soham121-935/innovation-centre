# Project 12 — MSP430 Ultra-Low-Power Industrial Sensor Node (Energy Test Blocked)

**Status:** 🟡 In Development — measurement method researched; quantified current/energy result is blocked because an ammeter or EnergyTrace-capable debugger is not confirmed in inventory.<br>
**Inventory:** 4 MSP430F5529 LaunchPads; P12 uses one after sequential P07/P09 host release. Exact board revision/accessories unknown.<br>
**Evidence:** TI SLAU533D documents ammeter measurement across the 3.3 V isolation jumper. The listed F5529 LaunchPad uses eZ-FET Lite; EnergyTrace support is not assumed. No code or measurement exists.

> Inventory-only scope. Do not buy/borrow an ammeter, MSP-FET, or other measurement tool. If none is already available, document that quantitative energy validation is blocked and continue to P13. No battery, sensor, host PC, or software is assumed; no firmware yet.

## 1. Problem statement

Characterize active-versus-sleep duty-cycle energy behavior of a verified MSP430F5529 target using measurement capability already in stock. The board is available; the measurement instrument/debugger is not confirmed.

## 2. Real-world application

An event-driven low-power node can reduce active time by sleeping between scheduled tasks. A controlled comparison can quantify energy only when target current is measured with a suitable instrument and the measurement setup is documented.

## 3. Why the problem matters

Firmware activity, debug links, floating pins, LEDs, and external circuits affect measured current. Comparing modes without isolating the target domain can produce misleading “ultra-low power” claims.

## 4. Project objectives

1. Verify exact MSP-EXP430F5529LP board/revision and isolation-jumper state.
2. Check whether a suitable ammeter/current instrument already exists in the supplied inventory; none is listed.
3. If present, follow TI's target-current procedure to compare fixed active and periodic-sleep workloads with LEDs/peripherals controlled and repeatable conditions.
4. Report target-only current/charge/energy boundary and measurement uncertainty; do not rely on EnergyTrace unless the exact debugger is supported.
5. If no meter is available, keep a documented measurement plan and mark quantitative energy tests blocked; continue to P13.

## 5. System requirements

- Exact LaunchPad revision and 3.3 V target isolation jumper documented.
- Measurement equipment must be physically in stock and appropriate for the expected current/range; no ammeter listed.
- TI guide procedure: remove the 3.3 V jumper and connect an ammeter across it; follow the exact safety/current-range directions. Do not short the rail or improvise.
- Separate eZ-FET/USB/target current and external circuitry as described by TI; floating GPIOs and backchannel connections can change readings.
- EnergyTrace requires specialized compatible debugger circuitry/software. F5529LP eZ-FET Lite is not established as EnergyTrace-capable; no EnergyTrace result assumed.
- No battery, external sensor, remote endpoint, or logging host is assumed.

## 6. Hardware used

| Inventory item | Quantity | P12 use | Status |
|---|---:|---|---|
| MSP430F5529 LaunchPad | 1 of 4 | Target board for workload/current measurement | Listed; revision/condition/cable unknown |
| Ammeter/current instrument | 0 listed | Required for quantitative current/energy measurement | Not confirmed—hard measurement blocker |
| MSP-FET / EnergyTrace-compatible debugger | 0 listed | Alternative only if exact hardware supports target | Not confirmed; not recommended to acquire |
| Computer/toolchain/USB | Not listed separately | Firmware/build/debug/logging if already supplied | Availability unknown |

## 7. Hardware not required

No battery pack, external sensor, power analyzer, MSP-FET, extra debugger, external data logger, or sensor BoosterPack is in scope.

## 8. External components required

None planned. If the ammeter and compatible measurement setup are absent, the energy experiment cannot be quantitatively validated. Do not procure or borrow a meter; continue to P13.

## 9. Estimated additional cost

Planned additions: **$0**. The existing LaunchPad cost is unknown. No unlisted instrument or software is priced or recommended.

## 10. System architecture

Conditional: host/toolchain → MSP430F5529 workload (active phase + scheduled sleep/wake) → isolated 3.3 V target rail across the documented jumper/ameter → time/current record → per-cycle charge/energy calculation. Present setup: board exists in inventory; meter/host/tools are unverified.

## 11. Connection diagram

See diagrams; no live ammeter wiring instructions beyond the manufacturer guide are given. Do not connect a meter until its range, polarity, burden voltage, and exact measurement procedure are checked.

## 12. Pin mapping

No application pin configuration is selected. TI SLAU533D defines target/isolator jumper boundaries; it does not authorize use of any specific GPIO in a future workload. Do not leave inputs floating.

## 13. Communication protocol

Not applicable. No sensor network or cloud service.

## 14. Software architecture

Future workload: initialize known clock/peripheral state → active task → timer wake → low-power mode → repeat; output event counts only if logging path is provided. Compiler/toolchain and source are not present or confirmed. No code.

## 15. Algorithm

Use identical application work and sample period while changing only the sleep/active duty cycle. Measure steady active and sleep current and integrate current over a complete repeatable cycle. Report instrumentation boundary and uncertainty. Do not infer energy from code-level estimates or LED behavior.

## 16. Working principle

The MCU spends a defined fraction in active work and the remainder in a documented low-power mode. A target-domain measurement captures current through the isolated 3.3 V jumper; multiply/integrate with recorded voltage/time only when measurement data exist. Current measurement is currently blocked.

## 17. Step-by-step build procedure

See [docs/TUTORIAL.md](docs/TUTORIAL.md): identify board → inventory meter/toolchain → review SLAU533D measurement boundary → establish known pin/clock state → perform safe current measurements only if an existing meter is available. Otherwise stop and continue to P13.

## 18. Firmware setup

No firmware is created. A repeatable workload is a later prerequisite; do not write code in this phase.

## 19. Software setup

TI documents CCS/IAR/other software, but no toolchain/host computer is listed. Do not download/install. Missing software blocks firmware and logging.

## 20. Web interface setup

Not applicable.

## 21. Testing procedure

No current, charge, or energy test has run. A future test compares repeated active-only and periodic-sleep runs with documented target-only boundaries, instrument range, sample period, supply, initial state, and uncertainty. If meter absent, all quantitative tests remain blocked.

## 22. Expected output

If a meter and toolchain are confirmed, a per-run current/time trace or samples, integrated charge/energy, repeatability, board/software versions, and measurement boundary. No result file exists.

## 23. Troubleshooting

See [docs/TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md). Avoid shorting the isolation jumper; stop on meter overload, unexpected current, heating, or unstable supply.

## 24. Performance metrics

Proposed: active/sleep current, average current, charge per cycle, energy per cycle, wake latency, missed events, run-to-run variation, and measurement uncertainty. No numerical values/targets until the instrument and board are verified.

## 25. Limitations

No ammeter/current probe or EnergyTrace-qualified debugger is in the supplied inventory. The F5529 LaunchPad eZ-FET Lite does not establish EnergyTrace capability. No battery or real sensor load is listed. USB/backchannel current must be excluded or explicitly included per test boundary. No energy result can currently be reported.

## 26. Future improvements

Only if existing hardware supports it: compare two workload duty cycles, test effects of board LEDs/backchannel, and quantify run-to-run uncertainty. Do not add a battery or sensor load.

## 27. Research opportunities

How much target-domain charge per periodic sensing cycle can be saved by reducing active duty while preserving a specified response cadence? This question requires a verified meter and remains blocked.

## 28. References

- TI, [MSP430F5529 LaunchPad User's Guide SLAU533D](https://www.ti.com/lit/ug/slau533d/slau533d.pdf) — target-current measurement across 3.3 V isolation jumper, host/peripheral effects, and board boundary.
- TI, [EnergyTrace technology](https://www.ti.com/tool/ENERGYTRACE) — specialized debugger circuitry required; not automatically available.
- TI E2E, [eZ-FET Lite and EnergyTrace clarification](https://e2e.ti.com/support/microcontrollers/msp-low-power-microcontrollers-group/msp430/f/msp430-low-power-microcontroller-forum/373559/ezfet-lite-1-2-firmware) — TI support clarifies F5529LP eZ-FET Lite does not support EnergyTrace.
- [Supplied inventory](../HARDWARE_INVENTORY.md).

## 29. License

See root [LICENSE](../LICENSE); repository license pending. No external code or datasets included.

## Reproducibility checklist

- [ ] F5529 LaunchPad revision/condition recorded
- [ ] Existing meter identified and measurement range validated—or blocker recorded
- [ ] Exact target current boundary/jumper setup follows SLAU533D
- [ ] EnergyTrace is not claimed without compatible hardware
- [ ] Workload/software/supply/timing documented before measurement
- [ ] No energy, current, or battery-life results claimed without data
