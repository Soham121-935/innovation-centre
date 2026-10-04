# Project 01 — Conditional Pin Map

> **Applies only to the TI-RSLK MAX configuration described by TI's SEKP166 user guide.** It is not a general RSLK pin map. The inventory currently does not prove that the lab has this version. Confirm the LaunchPad and chassis PCB revision and verify connector alignment before using any entry below. No physical wiring has been approved from this table.

In the MAX configuration, these are logical MSP432 LaunchPad port signals routed through the mating TI-RSLK chassis board. Do not treat this as a list of jumper wires. Chassis-side signal names and the external sensor/actuator connection must match the actual board schematic/connector.

## Motor drivers (MAX only)

| Device | MSP432 signal | Chassis signal / endpoint | Function | Evidence |
|---|---|---|---|---|
| Left DRV8838 | P5.4 | DIR_L → PH | Direction | TI SEKP166 motor pin map |
| Left DRV8838 | P2.7 / TA0.4 | PWML → EN | Speed PWM | TI SEKP166 motor pin map |
| Left DRV8838 | P3.7 | nSLPL → nSLEEP | Driver enable/sleep; low disables/sleeps | TI SEKP166 motor pin map |
| Right DRV8838 | P5.5 | DIR_R → PH | Direction | TI SEKP166 motor pin map |
| Right DRV8838 | P2.6 / TA0.3 | PWMR → EN | Speed PWM | TI SEKP166 motor pin map |
| Right DRV8838 | P3.6 | nSLPR → nSLEEP | Driver enable/sleep; low disables/sleeps | TI SEKP166 motor pin map |

## Wheel encoders (MAX only)

| Device | MSP432 signal | Chassis signal | Function | Evidence |
|---|---|---|---|---|
| Left encoder channel A | P10.5 / TA3CCP1 | ELA | Encoder channel A | TI SEKP166 encoder map |
| Left encoder channel B | P5.2 / GPIO | ELB | Encoder channel B | TI SEKP166 encoder map |
| Right encoder channel A | P10.4 / TA3CCP0 | ERA | Encoder channel A | TI SEKP166 encoder map |
| Right encoder channel B | P5.0 / GPIO | ERB | Encoder channel B | TI SEKP166 encoder map |

The TI MAX guide reports 1,440 incremental steps per wheel revolution for its motor/encoder assembly. Count convention (edges, quadrature decoding mode, gear/wheel assembly) and actual scale must be measured on the lab unit; calibrate rather than assuming this value in navigation.

## Reflectance array and bump switches (MAX only)

| Device | MSP432 signal | Function / direction | Notes |
|---|---|---|---|
| QTRX even-channel IR illumination | P5.3 | LED control output | Reflectance LED illumination for even channels per TI guide |
| QTRX odd-channel IR illumination | P9.2 | LED control output | Reflectance LED illumination for odd channels per TI guide |
| QTRX channel 0 | P7.0 | Floor reflectance input, robot-right end | Eight-channel array; time/discharge reading is firmware-dependent |
| QTRX channel 1 | P7.1 | Floor reflectance input | Confirm physical orientation |
| QTRX channel 2 | P7.2 | Floor reflectance input | Confirm physical orientation |
| QTRX channel 3 | P7.3 | Floor reflectance input | Near center |
| QTRX channel 4 | P7.4 | Floor reflectance input | Near center |
| QTRX channel 5 | P7.5 | Floor reflectance input | Confirm physical orientation |
| QTRX channel 6 | P7.6 | Floor reflectance input | Confirm physical orientation |
| QTRX channel 7 | P7.7 | Floor reflectance input, robot-left end | Confirm physical orientation |
| Bump 0–5 | P4.0, P4.2, P4.3, P4.5, P4.6, P4.7 | Normally-open, negative-logic contact inputs | In order: BMP0 right, BMP1, BMP2, BMP3, BMP4, BMP5 left; use the MAX guide's pull-up/interrupt method after confirming board revision |

## Optional analog distance sensors (not base-kit hardware)

| Sensor location | MSP432 analog input | MAX chassis route | Requirement |
|---|---|---|---|
| Left GP2Y0A21YK0F | P9.1 / A16 | DISTL/filter path | Only if this optional sensor and corresponding chassis path are physically present |
| Center GP2Y0A21YK0F | P6.1 / A14 | DISTC/filter path | Only if present |
| Right GP2Y0A21YK0F | P9.0 / A17 | DISTR/filter path | Only if present |

The Sharp sensor is powered from its documented 4.5–5.5 V range and produces an analog output. TI's MAX materials describe chassis low-pass-filter paths and also discuss a direct analog path; use the exact board schematic and sensor datasheet to verify output limits and wiring. Keep every MSP432 input within its specified electrical range (TI RSLK lab material warns that inputs outside 0–3.3 V can damage the MCU). A sensor's 5 V supply pin is **not** an MCU signal pin. Do not power or connect an unidentified sensor from this table.

## Programming/debug and communications

The conditional MSP-EXP432P401R LaunchPad has an onboard XDS110-ET debug interface and USB backchannel documented in TI's LaunchPad guide. Use the guide for the exact LaunchPad revision to select the target, debugger, serial port, and terminal settings. No MCU UART pin mapping or baud rate is specified here because it is not necessary to establish the chassis wiring and must be verified against the physical board/toolchain.

## Source and applicability

- TI, [TI-RSLK MAX User Guide, SEKP166](https://www.ti.com/lit/ml/sekp166/sekp166.pdf), section “MSP432 pin assignments and sensor interface”.
- TI, [RSLK MAX Motor Speed/Control Lab, SEKP146](https://www.ti.com/lit/pdf/sekp146), motor/encoder tables.
- TI, [MSP432P401R datasheet, SLAS826](https://www.ti.com/lit/ds/slas826e/slas826e.pdf), device electrical limits.

If the lab unit is classic TI-RSLK Maze Edition or has a different controller/chassis, archive this as a comparison reference and create a new profile with its own sourced pin map; do not edit pins by trial and error.
