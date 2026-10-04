# P14 — Troubleshooting

| Symptom | Check | Safe action |
|---|---|---|
| Kit identity unclear | Physical board/EVM label and exact revision | Stop; do not use LCDK pin map by name alone |
| JTAG unavailable | LCDK has no onboard emulator; external emulator/accessory may be missing | Record blocker; no substitute/purchase |
| Audio input silent | Input port vs actual microphone/source/cable, codec setup | Do not raise gain or connect unknown source; exact guide only |
| Clipped/noisy signal | Input levels, ground, cable, source and codec settings | Stop; verify documented ranges before reconnecting |
| SDK/host missing | Existing CCS/Processor SDK/computer availability | No download/install; mark build blocked |
| Fault classifier inaccurate | Baseline/labels/source variability | Remove diagnosis claim; keep simple features and revalidate with known truth |
| Real-machine test proposed | No machine/source/safety plan in inventory | Reject; test is advisory and no destructive fault injection |

No remedies have been bench-verified.