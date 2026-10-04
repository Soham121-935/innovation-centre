# P07 — Hardware Verification

Inventory lists two BOOSTXL-CC1125 modules and four MSP430F5529 LaunchPads. The radio modules and host revisions/condition have not been inspected. TI SWRA520 identifies MSP-EXP430F5529 and MSP-EXP430G2553 as supported hosts; two listed MSP430F5529 LaunchPads are a plausible sequential allocation, subject to physical matching/release.

SWRA520 describes the BOOSTXL-CC1125 with integrated PCB trace antenna operating in its documented US 902–928 MHz and Europe 868–870 MHz bands, and says the board's operating frequency range is 850–950 MHz. It documents LaunchPad and SmartRF Studio configurations and board power-source jumper behavior. Do not change jumpers/power or transmit until exact revision and host match. These bands are not evidence of permitted local use in India. Qualified local authorization is a hard precondition for any RF emission. The Sigfox EU/licensing statement is not applicable to this plan; no network/license is assumed.

**Blocker:** local RF approval, existing computer/software/USB access, and physical module/host match. If any is unresolved, no emission; continue to P08.

Sources: [TI SWRA520](https://www.ti.com/lit/an/swra520/swra520.pdf), [CC1125 datasheet](https://www.ti.com/lit/ds/symlink/cc1125.pdf), [inventory](../../HARDWARE_INVENTORY.md).