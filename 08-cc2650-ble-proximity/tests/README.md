# P08 — Test Plan

No tests have run. Gates: exact two radio/host pairs; available official software/USB; approved local BLE test; no external phone/gateway.

| Test | Description | Proposed metric |
|---|---|---|
| H01 identity | Match two BOOSTXL-CC2650MA + MSP-EXP432P401R pairs | Physical model/revision/accessories documented |
| S01 connection | Establish documented BLE roles | Connection success/establishment time |
| M01 status | Periodic sequence/status exchange | Delivery ratio, end-to-end delay, sequence gap |
| F01 stale state | Allow a supported link timeout | Stale/unknown detection latency; false-fresh count must be zero in test |
| R01 recovery | Reconnect following normal disconnection | Recovery time and missing status count |
| I01 local indicator | Verify host/board indicator only if documented | Status-to-indicator latency |

No distance, safety-zone, emergency, or human-protection test. RSSI is recorded only as link quality.