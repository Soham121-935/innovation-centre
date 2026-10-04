# P08 — Hardware Verification

Inventory lists two BOOSTXL-CC2650MA modules and two MSP432P401R LaunchPads. Physical revisions/accessories/condition and tool access are unknown. TI's product page explicitly says a MSP432 LaunchPad is needed for its software examples; two hosts are proposed for two nodes, conditional on exact model match; P11 may reuse one after P08 releases both.

TI describes each BoosterPack as a CC2650 module with integrated antenna, factory network-processor software, UART interface, and JTAG connection. TI lists module + 10-pin JTAG cable + one additional CC2650 module sample in the kit; do not count the sample as a second BoosterPack. SWRU486 identifies 3.3 V, MRDY/SRDY, TXD/RXD, reset and SPI signals on the module board. Host-side MCU pins require the exact MSP432 schematic and matching board revision.

TI's product page states Bluetooth 4.2 certification and certification for FCC/IC, CE and ARIB; these statements do not independently establish authorization for use in the local jurisdiction. Confirm local lab/RF approval before transmitting. Host examples and software are not listed as installed or available; no download/install is assumed.

**Blockers:** exact revision, existing MSP432 host software/computer/USB access, local approval. If unresolved, do not flash or transmit; continue to P09.

Sources: [TI product page](https://www.ti.com/tool/BOOSTXL-CC2650MA), [SWRU486A](https://www.ti.com/lit/ug/swru486a/swru486a.pdf), [inventory](../../HARDWARE_INVENTORY.md).