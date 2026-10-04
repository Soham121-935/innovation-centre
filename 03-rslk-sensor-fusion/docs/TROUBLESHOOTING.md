# P03 — Troubleshooting

| Symptom | Possible cause | Safe action |
|---|---|---|
| RSLK identity unclear | Generic stock label/mixed kit | Stop; record physical labels and use matching TI documentation; do not apply MAX pin table |
| Sensor set contents unclear | No part numbers or mixed sensors | Inventory all three sets; do not assume range/IMU/reflectance sensors |
| Sensors disagree | Different physical quantities, timing, orientation, calibration or fault | Preserve raw values/timestamps; set fused state to uncertain; do not average incompatible signals |
| Missing/stale sample | Interface/host support or power issue | Stop the test; use only exact manufacturer debug steps; no alternate wiring |
| Fusion false accepts | Invalid data passed gate or baseline/ground truth faulty | Disable motion; inspect logs and gate; repeat only after safe review |
| Required tool/test course absent | Not in supplied inventory | Mark affected tests blocked and continue to P04; do not procure |

No remedy has been bench-verified.