# P09 — Conditional CC3100BOOST Connector Signals

This table applies only if the physical item matches the TI CC3100BOOST revision documented by SWRU371B. The inventory could represent another CC3100 BoosterPack; do not apply this table to a module variant or other board. No host MSP430 MCU port/pin mapping is asserted.

| CC3100BOOST header signal | Function (SWRU371B) | P09 status |
|---|---|---|
| P1.1 | VCC 3.3 V | Verify exact host power capability first |
| P1.3 / P1.4 | UART1 TX / RX | Network-processor host interface |
| P1.5 | nHIB | Host control; mapping not asserted |
| P1.7 | SPI clock | Alternate host interface |
| P2.1 | GND | Connector orientation must match guide |
| P2.2 | IRQ output | Host mapping not asserted |
| P2.3 | SPI CS | Host mapping not asserted |
| P2.5 | nRESET | Do not drive absent exact guide |
| P2.6 / P2.7 | SPI MOSI / MISO | Device is SPI slave per TI guide |
| P4.4 / P4.5 | UART1 CTS / RTS | Optional flow control/interface |
| P3.1 / P3.2 | +5 V / GND | BoosterPack inner row; not a direct supply instruction |

SWRU371B describes J8 power source selection and up to 400 mA peak at 3.3 V. Exact jumper settings and supply path must be selected from the matching manual/host guide; no power-jumper change or external supply is authorized by this conditional interface summary.

Source: [TI SWRU371B](https://www.ti.com/lit/ug/swru371b/swru371b.pdf).