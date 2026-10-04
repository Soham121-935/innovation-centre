# P12 — Conditional Measurement Tutorial

1. Identify the physical MSP-EXP430F5529LP revision/condition and record the isolation jumper layout.
2. Check supplied inventory for a suitable ammeter/current instrument and compatible computer/toolchain. None is confirmed. Do not borrow/buy tools; if absent, stop and continue to P13.
3. Do not assume EnergyTrace: verify debugger hardware; F5529LP eZ-FET Lite is not supported for EnergyTrace according to TI support.
4. Review TI SLAU533D section 2.3 before measuring. Its target-domain method uses the 3.3 V isolation jumper, with warnings about host/target loads, backchannel, and floating pins.
5. Do not remove any jumper or connect a meter until the exact board/meter ranges and safe procedure are reviewed. Never short the rail.
6. If all gates pass later, compare identical active and periodic-sleep workloads over repeatable cycles and log current/time/uncertainty. Code remains deferred; no tests have run.
