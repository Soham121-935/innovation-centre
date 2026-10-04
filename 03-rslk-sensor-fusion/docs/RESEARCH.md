# P03 — Research Plan

**State:** conditional desk research; no physical unit or data. Sensor-set identity is unresolved.

## Question

On a verified RSLK and a provided route/test reference, does a simple time-aligned validity/agreement gate reduce incorrect route-state updates compared with the best single verified sensor modality?

## Candidate method

Only if the physical unit matches TI-RSLK MAX, consider encoder increments and the reflectance array as distinct wheel-motion and floor-pattern observations; bump switches indicate contact only and do not provide range. Additional sensor inputs may be included only if they are in the three supplied RSLK Sensors sets, identified, and electrically compatible. Do not assume an IMU/rangefinder. Compare (A) a single-modality baseline and (B) deterministic freshness/validity plus cross-check logic. Use no ML before noise/timing baselines exist.

## Hypothesis and method

A rule-based cross-check may reduce false landmark/state updates at the cost of more “uncertain” outputs. Test only after the RSLK, two modalities, supported existing software, safe stationary/route procedure, and independent reference are available. Record modality timestamps, freshness, per-sensor estimate, fused state, uncertainty/fault, and independent truth. If any prerequisite is absent, record the blocker and continue to P04.

## Metrics

Signal availability/dropout, timestamp skew, single-sensor and fused state error, false-accept rate, uncertainty rate, fault-detection latency, and route completion if a course is explicitly provided. Define numerical targets only after physical characterization. No dataset or results exist.

## Limitations / sources

One RSLK and an unidentified sensor set cannot establish general sensor-fusion performance. The conditional MAX reflectance array sees floor reflectance, not obstacle distance; bumpers are contact sensors. Sources: TI [RSLK MAX User Guide](https://www.ti.com/lit/ml/sekp166/sekp166.pdf), [MAX motor/control lab](https://www.ti.com/lit/pdf/sekp146), [Classic Maze Edition context](https://www.ti.com/lit/pdf/swrp242), and [Borenstein & Feng odometry calibration paper](https://doi.org/10.1109/70.544770).