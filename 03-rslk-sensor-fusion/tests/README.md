# P03 — Test Plan

**Host software test:** the hardware-independent fusion core's synthetic unit tests pass; see [`firmware/tests/README.md`](../firmware/tests/README.md). This is not evidence of RSLK hardware compatibility or sensor performance.

**Physical tests:** none have run. The following remain gated proposals. No unlisted instrumentation, course, software, or sensors are permitted.

| ID | Test | Gate / proposed acceptance |
|---|---|---|
| V01 | RSLK identity | Exact chassis/controller profile matches manufacturer docs; otherwise stop |
| V02 | Sensor inventory | Exact model/interface of each used stock sensor recorded; no assumed modalities |
| S01 | Individual sensor validity | Each confirmed sensor gives repeatable documented output while stationary |
| S02 | Time alignment | Timestamp skew/dropouts measured; callback/sample timing must be sourced |
| F01 | Single vs fused decision | Compare state error and false-accept/uncertain rates against independent truth; only with two modalities and a provided reference |
| F02 | Fault/degraded input | Stale/disconnected input yields invalid/uncertain state, never a fabricated estimate |
| R01 | Route trial | Only after P01 verifies robot, provided course and safe operation; report all outcomes |

Metrics: `availability = valid_duration/total_duration`; `false_accept = incorrect confident updates/ground-truth opportunities`; report sensor timestamp skew, error distribution, uncertain-state rate, and fault latency. Numeric thresholds await hardware characterization. **No physical data/results exist.**
