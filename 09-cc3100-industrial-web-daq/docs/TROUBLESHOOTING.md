# P09 — Troubleshooting

| Issue | Check | Safe action |
|---|---|---|
| BoosterPack variant unclear | Board silkscreen/revision vs SWRU371B or module manual | Stop; do not reuse pin map |
| Host not supported | Exact F5529 LaunchPad model and TI product guide | No MSP432/Tiva substitution without official evidence |
| Brownout/reset at Wi-Fi activity | CC3100 peak-current demand and documented J8/USB power path | Disconnect; do not add an unlisted supply or change jumper by trial |
| AP/station fails | Existing SDK version, role, local configuration, isolated setup | Use matching vendor procedure only; no router/internet assumed |
| No data input | Exact board revision/user input not app-visible | Mark DAQ blocked; no generic sensor substitution |
| Browser cannot view page | No browser client in inventory | Record UI blocker; two-node transport test is not browser validation |
| Firmware update requires emulator | CC31XXEMUBOOST not listed | Skip update/advanced debug; do not procure |

No remedy has been bench-verified.