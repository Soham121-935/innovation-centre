# P06 — BOOSTXL-SENSHUB Board-Level Signals (Conditional)

The following are BoosterPack connector signals from TI's BOOSTXL-SENSHUB manual SPMU290. **They do not identify LaunchPad-side MCU pin numbers.** Use only after the physical BoosterPack matches the documented revision and the host model is approved by TI documentation. Do not use this as a wiring instruction for another board.

| Sensor Hub connector | Documented function | P06 use/status |
|---|---|---|
| J1.1 | 3.3 V IN | Nominal board supply; verify exact matched host power first |
| J1.3 / J1.4 | UART RX / UART TX | RF expansion interface; not required for P06 |
| J1.6 | Interrupt | Board interface; source/use depends on supported software |
| J1.8 | SSI TX | Board expansion signal |
| J1.9 / J1.10 | RF I²C | RF expansion, not P06 sensors |
| J2.1 | Ground | Only use with matched official connector orientation |
| J2.2 / J2.3 | Interrupt | Board interface; host mapping must be verified |
| J2.6 / J2.7 | Sensor I²C | Sensor bus, conditional exact board |
| J2.8 / J2.9 / J2.10 | SSI RX / SSI SS / SSI CLK | Expansion signals |
| J3.5 | User LED | Local status only if board/host profile verified |
| J3.6 / J3.7 | User buttons | Local input only if profile verified |
| J4.4 / J4.5 | UART RTS / UART CTS | RF expansion only |
| J4.6 / J4.7 | RF shutdown / RF reset | RF expansion, not used |

Blank/unlisted connector positions are not assigned here. Verify all host-side connections in the exact LaunchPad schematic. The board nominally uses 3.3 V via its BoosterPack interface; never apply external power from this table.

Source: [TI SPMU290](https://www.ti.com/lit/ug/spmu290/spmu290.pdf).