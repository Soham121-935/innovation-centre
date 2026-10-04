# P13 — Test Plan

No tests/data exist. All experiments depend on physical sensor-set identification, compatible existing host/logging, safe ambient test access, and any needed reference already being in stock.

| Test | Gate / method | Proposed metric |
|---|---|---|
| H01 inventory | Identify every set component and match official docs | Exact part/revision/interface recorded |
| S01 interface | Manufacturer-approved connection only | Successful samples, errors, power limits |
| S02 baseline | Repeated safe ambient readings | Median/MAD, sample jitter, repeatability |
| F01 stale/missing | Disconnect only through supported safe software/test path | Unknown-state detection latency |
| A01 anomaly | Synthetic data only if an existing analysis environment is available, then a safe physical change only if naturally available | False alarm/detection delay against predeclared truth |
| R01 reference | Use only a physically inventoried matching reference instrument | Agreement and stated uncertainty |

Do not create hazardous temperature, humidity, gas, or dust conditions. If no reference exists, do not claim absolute accuracy.