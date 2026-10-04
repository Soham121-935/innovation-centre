# P08 — Troubleshooting

| Symptom | Check | Safe action |
|---|---|---|
| Module does not enumerate/respond | Exact CC2650 BoosterPack/host match and factory NWP state | Stop; use only TI revision-specific procedure |
| Host UART/HCI fails | SWRU486 mapping, host SDK/version, exact MSP432 revision | Do not swap pins or flash module by trial |
| BLE link unavailable | Role/support in installed SDK, approved RF environment, power | Stop; no smartphone/third radio substitute |
| Stale status appears fresh | Sequence/timeout handling | Mark unknown, isolate and review state logic; no actuation |
| RSSI fluctuates | Multipath/orientation/interference | Report distribution; never estimate safe distance |
| RF interference or unexpected behavior | Local radio environment or wrong configuration | Stop RF test and notify supervisor |

No remedy is bench-verified; no safety role is allowed.