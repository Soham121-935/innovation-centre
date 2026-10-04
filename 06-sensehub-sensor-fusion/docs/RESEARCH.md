# P06 — Research Plan

**State:** sensor suite has a strong conditional match to TI BOOSTXL-SENSHUB; no board, host, software, or data have been verified.

## Research question

On a physically verified BOOSTXL-SENSHUB and TI-compatible listed TIVA host, does a simple time/freshness/consistency layer improve the completeness and fault visibility of an environmental/motion record compared with unqualified raw values?

## Conditional scope

SPMU290 lists TMP006, MPU9150 (accelerometer, gyroscope, magnetometer), BMP180, ISL29023, and SHT21. Keep environmental channels separate and preserve units/timestamps. Use orientation fusion only with a verified MPU9150 path and existing supported software; TI's Air Mouse example uses a Direct Cosine Matrix method, but that does not verify lab software. Do not derive a universal comfort, weather, or safety score.

## Method / hypothesis

First characterize each available sensor individually while stationary. Then compare raw-only reporting with a deterministic quality record that flags stale/out-of-range/disagreeing values. Hypothesis: quality flags reduce silent use of invalid readings, but may increase reported “unknown” states. No reference accuracy can be claimed without instruments from the supplied inventory.

## Metrics

Per-channel sample availability/error count, sample timing skew, stale/invalid detection latency, repeatability under repeated stationary conditions, orientation drift over time, and count of correctly surfaced communication faults. Accuracy/absolute calibration metrics remain blocked unless a suitable reference already exists in stock.

## Blockers and sources

BOOSTXL-SENSHUB identity, compatible EK-TM4C123GXL/EK-LM4F120XL host, TivaWare/host/USB/software not confirmed. TI's guide calls for downloads, PC and USB cables; not assume or acquire. Sources: [SPMU290](https://www.ti.com/lit/ug/spmu290/spmu290.pdf), [SPMU295](https://www.ti.com/lit/ug/spmu295/spmu295.pdf), [SPMU296](https://www.ti.com/lit/ug/spmu296/spmu296.pdf).