# P10 — Inventory-Only BOM

| Item | Quantity | Inventory evidence / status | Role | Planned purchase |
|---|---:|---|---|---:|
| CC3200SF LaunchPad | 1–2 of 2 | Listed; board revision and sensor population unknown | Edge node; second may be local peer | $0; existing cost unknown |
| BMA222 accelerometer | 0–2 only if physically populated on matched board | TI SWRU372C conditional | Onboard motion input | $0; no added sensor |
| TMP008 temperature sensor | 0–2 only if physically populated | TI guide says U6 DNP on newer builds | Optional local input | $0; absent = unavailable |
| USB cable, host computer, CC3200 SDK/toolchain | Not listed separately | Availability unknown | Debug/programming only if already provided | $0; no download/purchase |
| Router, phone/browser, cloud broker, external sensor | 0 confirmed | Not in inventory | Not assumed | $0 |

No external purchase planned. The CC3200 LaunchPad manual lists a micro-USB cable in kit contents, but physical inventory must confirm it.