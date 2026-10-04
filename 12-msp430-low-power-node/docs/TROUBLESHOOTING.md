# P12 — Troubleshooting

| Symptom | Possible cause | Safe action |
|---|---|---|
| No current reading | No meter, wrong range, open/incorrect jumper gap | Stop; do not bypass or short rails; check exact manual/instrument specs |
| Reading includes USB/emulator | Wrong measurement boundary | Follow SLAU533D and identify included target-side loads; do not claim MCU-only current |
| Unstable reading | Active current transients, meter burden, USB/backchannel or external load | Record limitation; measure only within meter specifications |
| Excessive current | Floating pins, active peripherals, wiring error | Disconnect safely; review exact board and I/O states |
| EnergyTrace requested | F5529LP eZ-FET Lite does not support EnergyTrace per TI support | Do not claim it; only use existing suitable instrument |
| Toolchain absent | Not in inventory | Stop; no download/install/purchase |

No measurement or remedy is bench-verified.