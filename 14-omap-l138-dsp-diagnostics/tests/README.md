# P14 — Test Plan

No DSP/audio tests have run. Requires exact kit identity, compatible external emulator, existing host/toolchain, safe signal source/microphone, and matching cables.

| Test | Gate / procedure | Proposed metric |
|---|---|---|
| H01 variant | Identify LCDK/EVM type and revision | Exact manual/schematic match |
| H02 emulator | Confirm physically available, supported external emulator | JTAG/debug connectivity; otherwise blocked |
| A01 input chain | Known safe source and documented connector/level | Sample rate, clipping, dropout, channel noise |
| D01 baseline | Repeated same-condition signal | RMS/spectral-feature repeatability |
| D02 anomaly | Known, nonhazardous and independently labelled input change | Detection delay, false/missed alarms |
| P01 timing | Fixed block/window and existing profiler | Processing latency/buffer overrun |

No machine, fault-injection, hazardous signal, external audio generator, or reference dataset is assumed. No performance threshold is achieved.