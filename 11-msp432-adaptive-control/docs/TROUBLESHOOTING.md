# P11 — Blocker Handling

| Proposal/symptom | Why blocked | Action |
|---|---|---|
| No process response | No plant or actuator in inventory | Do not invent/connect a load; record blocker |
| Use LED as output plant | Does not represent process dynamics | Reject as adaptive process-control result |
| Use MCU temperature as feedback | Self-heating is not a controlled/independent plant | Reject substitute |
| Borrow robot/motor from P01/P05 | Separate project allocation; no approved host/driver/safety mapping | Do not reassign or connect |
| Adaptive tuning unstable | Unknown plant/safe envelope | Stop immediately; no tuning on physical equipment |
| Toolchain/simulation absent | Not listed/verified | Record blocker; no download or purchase |

No remedy exists until the inventory and safety preconditions change.