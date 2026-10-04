# P08 — Conditional Tutorial

1. Inspect two physical BOOSTXL-CC2650MA units; record revision, labels, factory programming state, JTAG cable, and any kit samples.
2. Inspect two MSP432 LaunchPads; confirm exact MSP-EXP432P401R model/revisions. Record checkout/release so P11 reuses one host only after P08 releases both.
3. Verify matching TI host example/SDK and computer/USB debug access are already available. Do not download/install. If absent, stop and proceed to P09.
4. Match board-side signals to SWRU486A and the exact host schematic; no generic pin assumptions.
5. Obtain local approval for the BLE lab test. Product certifications for other jurisdictions do not establish local authorization.
6. After all gates pass, use only a two-node informational status exchange. Show “unknown/disconnected” on timeout; do not include robot control, locks, E-stop, human safety, or distance thresholds.
7. Measure delivery, delay, timeout, reconnect, and stale-value behavior; record software/board versions. No tests have run.
