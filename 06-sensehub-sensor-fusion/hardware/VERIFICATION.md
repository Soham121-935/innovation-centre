# P06 — Hardware Verification

Inventory: 2 “SenseHUB Booster Pack”; 5 “TIVA LaunchPad.” No SKU/revision or physical inspection is recorded. Candidate exact device is TI BOOSTXL-SENSHUB. TI's SPMU295 guide says it is fully compatible with EK-TM4C123GXL and older EK-LM4F120XL. The generic inventory label does not prove either host is present.

If the physical board matches BOOSTXL-SENSHUB, TI SPMU290 identifies: TMP006 IR object-temperature; MPU9150 3-axis accelerometer, gyroscope and magnetometer; BMP180 pressure; ISL29023 ambient/IR light; SHT21 humidity/ambient temperature; two buttons, a user LED and a power LED. Sensor readings and the interface below are conditional until physical match.

TI SPMU290 specifies nominal 3.3 V from the BoosterPack interface and a 2.7–5.5 V board range; do not supply power separately or infer host pin assignments from this note. TI's setup guide requires TivaWare, LMFlashProgrammer, a compatible PC and USB cables; those are not in the inventory, so no demo/build is assumed.

**Blocker:** physical SKU/host/software/computer/cable availability. If identity/access is unresolved, do not power or download tools; document the blocker and continue to P07.

Sources: [SPMU290](https://www.ti.com/lit/ug/spmu290/spmu290.pdf), [SPMU295](https://www.ti.com/lit/ug/spmu295/spmu295.pdf), [inventory](../../HARDWARE_INVENTORY.md).