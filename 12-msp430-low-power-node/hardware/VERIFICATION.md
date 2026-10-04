# P12 — Hardware Verification

Inventory lists four MSP430F5529 LaunchPads. The exact PCB revision/accessories/condition have not been inspected. TI SLAU533D describes the MSP-EXP430F5529LP and explains target current measurement: remove the 3.3 V jumper on the isolation block and connect an ammeter across it, while considering target-side circuitry, backchannel UART, and floating pins. Do not perform this without a suitable meter already in stock and a safe, reviewed procedure.

The inventory does not list an ammeter, current probe, MSP-FET, or other energy analyzer. TI EnergyTrace requires specialized compatible debugger circuitry; the F5529 LaunchPad uses eZ-FET Lite, which TI support says does not support EnergyTrace. EnergyTrace is therefore not assumed for P12. Computer/toolchain/USB access is also not confirmed.

**Blocker:** suitable existing current instrument and host/software. If absent, no quantified energy test; record blocker and continue to P13. No purchases.

Sources: [SLAU533D](https://www.ti.com/lit/ug/slau533d/slau533d.pdf), [TI EnergyTrace](https://www.ti.com/tool/ENERGYTRACE), [TI E2E eZ-FET Lite clarification](https://e2e.ti.com/support/microcontrollers/msp-low-power-microcontrollers-group/msp430/f/msp430-low-power-microcontroller-forum/373559/ezfet-lite-1-2-firmware), [inventory](../../HARDWARE_INVENTORY.md).