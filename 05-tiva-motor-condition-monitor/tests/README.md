# P05 — Test Plan

No tests have run. All tests depend on exact TIVA identity and a compatible motor/feedback path in supplied stock.

| Test | Gate | Proposed metric |
|---|---|---|
| Identity | TIVA and motor/driver labels match docs | Exact configuration recorded |
| Feedback stationary check | Sensor/interface physically present and safe | Noise, dropout, stale status |
| Healthy baseline | Verified plant, existing test area/tools, low-risk procedure | Speed error and residual distribution over repeats |
| Software fault replay | Implemented offline harness only | Dropout detection rate and latency; no physical fault |
| Repeatability | Same stock platform and documented conditions | Per-run error/false flags, no cherry-picking |

No current, vibration, bearing, or thermal diagnosis metric is available unless the corresponding sensor is confirmed in inventory. Do not run a physical stall/load test.