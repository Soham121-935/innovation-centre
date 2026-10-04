# P04 — Test Plan

No radio tests have run. Tests are conditional on exact device identity, compatible listed hosts, authorized software, and an approved lawful RF configuration.

| Test | Procedure | Proposed metric / gate |
|---|---|---|
| Identity | Record board/radio/antenna markings and included accessories | Exact profile matched; otherwise stop |
| Host compatibility | Match official host guide to a listed LaunchPad | Must pass before pin map or emission |
| RF authorization | Verify local region/channel/power/antenna with qualified supervisor | No transmit without approval |
| Two-node packet | Non-critical numbered packets, bounded trial | PDR, ack ratio, latency distribution, RSSI/LQI if documented, retries, duplicates |
| Loss/freshness | Safe packet omission/timeout from supported test procedure | Stale/lost messages explicitly reported; no false success |
| Recovery | Restore link after approved interruption | Reconnect time and lost count |

No test target is predeclared as achieved. No real emergency, safety-control, or machinery test is allowed.