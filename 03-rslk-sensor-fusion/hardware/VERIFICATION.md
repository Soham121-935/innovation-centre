# Project 03 — Hardware Verification

**Status:** blocked at physical identity/sensor inventory; no unit has been inspected.

Inventory lists 10 RSLKs and 3 RSLK Sensors sets. It does not specify the RSLK family, chassis/controller revision, LaunchPad, sensor-set contents, or condition. TI-RSLK MAX documents are reference-only. If—and only if—the physical unit matches TI-RSLK MAX, TI describes wheel encoders, a reflectance array, bump switches, and chassis drivers; optional Sharp distance sensors are not base-kit contents. A classic Maze Edition uses a different MDPDB architecture.

Before using P03, record the exact kit label, chassis PCB/revision, controller marking, every sensor label/connector, included accessories, and condition. Do not power or wire from a MAX pin map before matching the kit. If two independent modalities cannot be confirmed in listed stock, mark the fusion MVP blocked and continue to P04. No sensor or host is to be added.

Sources: [TI-RSLK MAX User Guide](https://www.ti.com/lit/ml/sekp166/sekp166.pdf); [MAX motor/control lab](https://www.ti.com/lit/pdf/sekp146); [Classic Maze Edition preface](https://www.ti.com/lit/pdf/swrp242); [inventory](../../HARDWARE_INVENTORY.md).