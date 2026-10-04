# P13 — Research Plan

**State:** design-level progress only; sensor set and all measurement interfaces are unidentified. No samples or code.

## Question

For an identified climate sensor already in the generic set, does a persistence-gated robust residual reduce isolated-noise false alarms versus a single-sample threshold without unacceptable detection delay?

## Method after inventory gates

Record exact sensor/host model, units, resolution, stated accuracy/range, sampling behavior, calibration status, mounting, and data logger. Establish an ambient baseline in an already available safe environment. Keep baseline update separate/frozen during anomaly tests to avoid contaminating normal limits. Compare a datasheet-grounded absolute limit and a robust median/MAD residual with a fixed persistence window. Mark missing/stale/out-of-range samples unknown, not an anomaly. No ML without a representative labelled dataset and validation.

## Metrics

Availability, sample interval jitter, baseline median/MAD, repeatability, false alarms per defined period, anomaly detection latency, missed events, and agreement with independent reference if a suitable reference is already present in stock. No values or target thresholds are currently available.

## Blockers / references

One unnamed set; no verified host/logger/reference/software. Do not assume P06/P10 sensors. Sources: [inventory](../../HARDWARE_INVENTORY.md), [NIST/SEMATECH e-Handbook](https://www.itl.nist.gov/div898/handbook/).