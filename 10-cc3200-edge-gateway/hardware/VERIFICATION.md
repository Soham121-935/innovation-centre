# P10 — Hardware Verification

Inventory lists two “CC3200SF LaunchPad” units, but exact board/revision/condition and sensor population are unknown. TI's SWRU372C guide covers CC3200-LAUNCHXL Rev3.2 and says most details also apply to Rev4.1 subject to documented changes. Match each physical unit before applying the guide.

For a matching board, the guide describes integrated CC3200 MCU/Wi-Fi, FTDI-based onboard JTAG/serial, USB, buttons, LEDs, and onboard sensors. It identifies an accelerometer BMA222 and temperature sensor TMP008 at U6 (I²C addresses shown by TI); **U6/TMP008 is DNP on newer CC3200-LAUNCHXL builds**. Therefore use the accelerometer only after physical match and the temperature sensor only if visibly populated. Do not substitute the commonly confused TMP006.

The guide states USB is used for power/debug and includes a micro-USB cable in the evaluated kit contents; the generic inventory entry does not prove the cable is present. Development environments/examples must be available already. No external network/client or sensor is listed.

**Blocker:** exact revision, sensor population, USB cable/software availability and local Wi-Fi approval. If unresolved, no programming/transmission; continue to P11.

Sources: [TI SWRU372C](https://www.ti.com/lit/ug/swru372c/swru372c.pdf), [CC3200 datasheet](https://www.ti.com/lit/ds/symlink/cc3200.pdf), [inventory](../../HARDWARE_INVENTORY.md).