# P08 — Conditional CC2650 BoosterPack Signals

SWRU486A identifies the module-side BoosterPack signals below. This is not the MSP432P401R LaunchPad pin map and not wiring authorization. Match the physical BOOSTXL-CC2650MA revision and exact host schematic first.

| BoosterPack signal | Documented module function | State |
|---|---|---|
| 3V3 / GND | Module supply/reference | Verify exact host power before insertion |
| DIO7 / MRDY | Host/module ready handshake | Host-side assignment not asserted |
| DIO0 / TXD | Module serial transmit | Cross direction only per exact guide |
| DIO1 / RXD | Module serial receive | Cross direction only per exact guide |
| DIO8 / SRDY | Module ready handshake | Host-side assignment not asserted |
| DIO9 / SPI CS; DIO10 / SPI CLK; DIO11 / MOSI; DIO12 / MISO | Module SPI signals | Not used unless verified stack requires it |
| NRESET | Module reset | Do not drive without exact guide |

No voltages beyond TI's board-level guide, pullups, timing, or alternate mapping are specified here. Check matching LaunchPad schematic and approved TI host example. Source: [SWRU486A](https://www.ti.com/lit/ug/swru486a/swru486a.pdf).