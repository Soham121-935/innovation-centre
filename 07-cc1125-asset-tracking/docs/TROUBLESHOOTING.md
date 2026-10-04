# P07 — Troubleshooting

| Symptom | Check | Safe action |
|---|---|---|
| Module/host not recognized | Exact revision and SWRA520 compatibility | Stop; no generic pin map or alternate host |
| RF profile uncertain | Board's documented 850–950 MHz range/antenna and local rules | Do not transmit; seek qualified approval; no frequency experimentation |
| No link | Jumper/power configuration, host, exact software and approved profile | Follow only matching TI steps; do not increase power |
| RSSI changes with orientation | Antenna pattern/multipath/interference | Report link quality variability; do not convert to distance |
| Apparent asset moved but packets stop | Radio loss is not proof of movement | Report “link unknown/lost”; no location claim |
| Proposed emergency use | Scope excludes safety and alarm traffic | Reject connection; stop test |

No remedies have been bench-verified.