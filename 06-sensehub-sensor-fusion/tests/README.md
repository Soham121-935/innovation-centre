# P06 — Test Plan

No tests have run. All physical tests require an exact BOOSTXL-SENSHUB match, documented compatible TIVA host, and already-available authorized software/host/cables.

| ID | Test | Proposed record / acceptance gate |
|---|---|---|
| H01 | Board identity | BoosterPack SKU/revision and host model match official docs |
| H02 | Tool/access check | TivaWare/toolchain, computer, cables already available; otherwise blocked |
| S01 | Individual sensor presence | Record sensor identity, raw units, errors and availability; no absent sensor presumed |
| S02 | Stationary repeatability | Repeated readings under documented conditions; no accuracy claim |
| S03 | Data integrity | Detect missing/stale/out-of-range input and expose invalid state |
| F01 | Quality layer comparison | Raw versus validity/freshness record; count silently accepted invalid values and unknown states |
| O01 | Orientation stability | Only if MPU9150 and supported software confirmed; drift/variance, no external heading truth assumed |

Metrics: sample availability, bus/driver errors, timestamp skew, fault-detection latency, repeatability, and orientation drift. No numerical acceptance result is available.