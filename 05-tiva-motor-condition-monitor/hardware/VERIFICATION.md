# P05 — Hardware Verification

Inventory lists five “TIVA LaunchPad” boards but no exact part/revision, motor, compatible driver, current sensor, vibration sensor, or test plant. A possible plant is an RSLK motor/encoder set, but the RSLK family and any TIVA-compatible interface are unknown; do not connect boards by assumption.

The TI EK-TM4C123GXL guide documents one specific Tiva C LaunchPad (TM4C123GH6PMI). It is a candidate only if physical markings match. PWM/QEI features of that MCU do not provide a motor driver, current measurement, or vibration measurement by themselves.

**Blockers:** exact TIVA; in-stock motor/driver; safe compatible feedback; existing toolchain/host. If any are absent, mark the physical MVP blocked and continue to P06. No purchases or substitutes.

Sources: [TI EK-TM4C123GXL guide](https://www.ti.com/lit/pdf/spmu296); [TM4C123G LaunchPad product page](https://www.ti.com/tool/EK-TM4C123GXL); [inventory](../../HARDWARE_INVENTORY.md).