# P13 — Troubleshooting

| Issue | Check | Safe action |
|---|---|---|
| Generic sensor identity unclear | Physical label/board and official manufacturer part number | Do not power/wire; record blocker |
| Sensor value has no unit/range | Exact datasheet and driver documentation | Do not infer physical meaning or threshold |
| No host/logger path | Inventory and checkout records | Keep project blocked; no purchase/borrowing |
| Baseline drifts | Warm-up, placement, cadence, sensor calibration/contamination | Preserve raw data; suspend threshold claim |
| One extreme sample triggers alarm | Noise/outlier/transient vs persistent change | Use predeclared persistence/quality gate; no ad-hoc retuning |
| Missing/stale sample looks normal | Fault-state handling absent | Mark unknown and stop reporting normal |
| Hazardous test proposed | No chamber/chemicals/industrial facility listed | Reject; use only safe ambient test if all gates pass |

No remedies have been bench-verified.