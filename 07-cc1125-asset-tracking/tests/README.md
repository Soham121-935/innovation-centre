# P07 — Test Plan

No RF test has run. Requires exact two-node hardware, compatible listed hosts, existing software/PC/USB, and qualified regional RF approval.

| Test | Procedure | Metrics / gate |
|---|---|---|
| Identity | Match both BoosterPacks, antennas, revisions, LaunchPads | Exact documented pair or stop |
| RF compliance | Supervisor verifies local band/power/antenna/config | No transmission before approval |
| Basic link | Numbered non-critical frames, approved profile | PDR, valid packet age, sequence loss, RSSI/LQI if supported |
| Stale/duplicate | Safe software/protocol test | Stale/duplicate rejection and false link-present rate |
| Link recovery | Approved interruption without interfering with others | Timeout/reconnect latency, packet loss |

No distance/position test is defined. Metrics are not measured; thresholds await approved baseline. Do not connect to alarms/machinery.