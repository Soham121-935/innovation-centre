# P12 — Test Plan

No measurements/tests have run. Quantitative energy testing is blocked unless a suitable current instrument and existing host/toolchain are physically confirmed.

| Test | Gate / method | Metric |
|---|---|---|
| H01 board identity | Exact MSP-EXP430F5529LP revision | Model/revision/accessories recorded |
| M01 instrument | Verify meter range, resolution, burden voltage, safe leads | Instrument specification and calibration status |
| M02 target boundary | Follow SLAU533D 3.3 V isolation-jumper procedure | Target-only current boundary documented |
| W01 baseline | Same active workload and supply, repeated | Current/time trace and variation |
| W02 low-power | Same workload with defined periodic sleep | Average current, charge/energy per cycle, wake latency |
| V01 validity | Avoid floating pins and uncounted target loads | Repeatability/uncertainty; no invalid comparison |

If no instrument exists, mark all numerical current/energy tests blocked. No EnergyTrace result is accepted from the F5529 eZ-FET Lite.