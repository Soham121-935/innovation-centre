# P09 — Test Plan

No tests have run. Physical tests require exact CC3100 SKU, compatible MSP430F5529 hosts, existing SDK/host/USB access, approved isolated Wi-Fi configuration, and adequate documented power.

| Test | Gate / procedure | Metric |
|---|---|---|
| H01 identity | Identify both BoosterPack variants and host revisions | Exact official match |
| P01 power | Verify J8/cable/current path from exact manual | No reset/brownout; do not assume supply capability |
| N01 association | Local AP/server + second station/client only | Association success/time |
| D01 input | Read a physical board user input only if documented and app-visible | Input-to-response latency/sequence integrity |
| W01 HTTP | Request bounded local response | Success ratio, response latency, content/age validity |
| F01 fault | Timeout/stale response handling in supported test | Time to unknown/unavailable; false-fresh count |
| UI01 browser | Requires existing browser-capable client | Currently blocked; no PC/phone listed |

No internet, external sensor, security certification, or cloud test is defined.