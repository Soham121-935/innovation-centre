# P12 — Research Plan

**State:** method documented; physical current/energy experiment blocked by missing measurement instrument and unconfirmed host/software.

## Question

For a repeatable MSP430F5529 workload, what target-domain charge/energy per cycle is saved by a scheduled low-power interval while preserving response cadence?

## Method

Only with a physically verified MSP-EXP430F5529LP, existing suitable ammeter, and existing toolchain: hold workload, period, clock, peripherals, supply, and initial state constant; compare active-only versus periodic sleep. Follow SLAU533D across the 3.3 V isolation jumper. Exclude USB/emulator/backchannel where specified; ensure no floating I/O; measure complete active/sleep cycles. Use the same boundary and repeat each condition. EnergyTrace is not assumed; TI says specialized debugger circuitry is required and the F5529LP eZ-FET Lite lacks EnergyTrace support.

## Metrics

Active/sleep/average current, charge and energy per cycle, wake/response latency, missed events, run-to-run variation, instrument range/burden, and uncertainty. No targets or results before instrumentation is verified.

## Blockers / references

No ammeter/current instrument, EnergyTrace debugger, toolchain, or host computer is listed/confirmed. No procurement or borrowing. Sources: [SLAU533D](https://www.ti.com/lit/ug/slau533d/slau533d.pdf), [EnergyTrace](https://www.ti.com/tool/ENERGYTRACE), [TI eZ-FET Lite note](https://e2e.ti.com/support/microcontrollers/msp-low-power-microcontrollers-group/msp430/f/msp430-low-power-microcontroller-forum/373559/ezfet-lite-1-2-firmware).