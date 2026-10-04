# P10 — Test Plan

No tests have run. Requires exact CC3200 LaunchPad revision, physically fitted sensors, existing SDK/computer/USB, and local radio approval for Wi-Fi tests.

| Test | Procedure | Proposed metric |
|---|---|---|
| H01 identity | Record each board revision and sensor population | Physical match to SWRU372C |
| S01 accelerometer | Stationary reads, if BMA222 fitted | Availability, error count, stationary variance |
| S02 temperature | Only if TMP008 U6 is physically fitted | Availability, repeatability; no calibration claim |
| L01 local status | Verify validity/unknown indicators | Invalid-to-unknown latency, false-valid count |
| N01 two-node Wi-Fi | Optional isolated AP/station exchange using existing software | Association, response delay/loss, sequence/age integrity |
| F01 link loss | Supported disconnect/timeout test | Timeout and reconnect latency; stale state must be unknown |

No sensor addition, internet, browser UI, cloud, motor, or environmental chamber is assumed.