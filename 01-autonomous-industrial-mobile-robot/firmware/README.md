# Project 01 — Firmware Plan (No Source Yet)

## Status

No firmware source, build project, pin configuration, or test binary is present. The inventory label “RSLK” does not identify an exact hardware target, and the MAX pin map is conditional. The explicit project instruction says not to begin coding before the RSLK is identified. Producing a speculative `main.c` now would be unsafe and not honestly buildable.

## Expected target if TI-RSLK MAX is confirmed

- MCU: MSP432P401R fitted to the verified MSP-EXP432P401R LaunchPad.
- Debug/programming: onboard XDS110-ET via the LaunchPad's USB connection.
- IDE/toolchain: TI Code Composer Studio (CCS) with MSP432 device support; use the TI RSLK C starter resources and/or SimpleLink MSP432P4 SDK only after checking the board revision, lab OS, and package compatibility.
- Base language: C; no RTOS needed for the initial deterministic state machine and periodic control loop.
- Source profile: a separately named MAX chassis profile only after matching the official MAX user guide and physical PCB.

If the lab has classic TI-RSLK Maze Edition, a custom assembly, or another MCU, reselect the target from its own official docs before writing code.

## Planned module boundaries

```text
src/
  application/     mission state machine, fault manager, event logging
  board/           exact verified hardware profile; clocks and pin configuration
  communication/   local debug/backchannel telemetry and operator stop
  control/         wheel-speed PI, saturation/anti-windup, motion primitives
  drivers/         motor, encoder, bump, reflectance, verified range interfaces
  navigation/      route graph, path search, landmark correction, odometry
  processing/      sensor calibration, filters, validity checks
include/           public interfaces and typed configuration
config/            safe defaults and example-only local overrides
tests/             pure algorithm tests and documented bench tests
build/             generated artifacts only; binaries ignored
```

This is a planned layout, not a claim that any driver or algorithm is implemented.

## First firmware after the identity gate

1. Confirm the actual LaunchPad and MCU marking, revision, toolchain, and official example.
2. Build/flash a **no-motion LaunchPad smoke test** (documented onboard LED or backchannel check only). Do not initialize motor outputs.
3. Record board detection, debugger connection, flash success, exact IDE/compiler/SDK versions, expected LED/serial output, and any failure.
4. Add one sensor driver at a time after its physical connection has been verified.
5. Add motor control only after the safety inspection, correct power jumper state, and wheels-raised motor test plan are reviewed.

The actual source filename and complete code will be committed only at step 2, after step 1 is answered. The source must include the chosen target configuration and build/flash instructions; a pseudocode snippet or generic Arduino sketch is not a substitute.

## Build and flash

**Not available yet.** The build command, CCS project metadata, SDK version, target config, serial settings, and flash procedure depend on the physically identified board. See [hardware/VERIFICATION.md](../hardware/VERIFICATION.md), [hardware/pin-map.md](../hardware/pin-map.md), and [docs/TUTORIAL.md](../docs/TUTORIAL.md).
