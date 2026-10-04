# P14 — Research Plan

**State:** conditional DSP/audio design only; exact board, emulator, software and input source are unknown. No code/signal/data/result.

## Research question

For a verified LCDK and safe, repeatable in-stock audio source, do simple time-domain and spectral features identify persistent changes with bounded latency and acceptable false-alarm rate versus a documented baseline?

## Candidate approach

If physical board matches TI SPRUIL2A, use its documented codec/MCASP audio input only after the exact line/mic connector, source, level, grounding, sample rate and software path are confirmed. Start with sample validity/clipping/dropout checks; compute RMS/energy, crest factor, windowed FFT band energy/peaks; compare with a baseline from the same source/operating condition using transparent persistence thresholds. Fault labels/diagnostics require representative known-state signals; none are supplied. No ML.

## Metrics

Sample-rate error/jitter, buffer overrun/dropout, clipping, window processing latency, feature repeatability, baseline variance, anomaly detection latency, false alarms/misses against independently known conditions, and CPU/DSP utilization if existing tools expose it. No numeric targets without board/source verification.

## Blockers / sources

LCDK variant, external emulator, CCS/Processor SDK, host, audio source/microphone/cables, and labeled signal data are not confirmed. No purchase or outside dataset. Sources: [TI SPRUIL2A](https://www.ti.com/lit/ug/spruil2a/spruil2a.pdf), [inventory](../../HARDWARE_INVENTORY.md).