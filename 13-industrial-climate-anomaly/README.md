# Project 13 — Industrial Climate Anomaly Detection and Automatic Response (Sensor Blocked)

**Status:** 🔴 Blocked — the only P13-specific inventory entry is one unidentified “Sensors (generic set)”; climate sensor, interface, host, and logging path are unknown.<br>
**Inventory:** Sensors (generic set), quantity 1; no physical inspection or calibration evidence recorded.<br>
**Evidence:** No specific sensor capability is asserted. P06/P10 sensor candidates are separate conditional assets and are not allocated to P13.

> Make meaningful progress at the research/design level, record exactly what is missing, and continue to P14. Do not assume an environmental sensor, reuse another project's board/sensor without release and explicit reallocation, buy a sensor, or download software. No code or data collection yet.

## 1. Problem statement

Specify an inventory-only method for detecting persistent deviations in an environmental time series once—and only once—the generic sensor set is physically identified as containing a suitable, compatible climate sensor.

## 2. Real-world application

An environmental monitor could flag unusual temperature/humidity/pressure behavior in a supervised industrial area. The lab inventory does not establish any such sensor or industrial test environment, so P13 is a blocked design/research project, not a deployed monitor.

## 3. Why the problem matters

Thresholds based on guessed sensors or short unrepresentative baselines create false alarms and miss real changes. Detection must consider units, uncertainty, cadence, missing data, drift, and time persistence.

## 4. Project objectives

1. Identify every component in the one listed generic sensor set, including exact part/revision, output/interface, power, quantity, calibration status, and included cables.
2. Confirm a matching host, existing software/toolchain, and log-storage path are already in stock.
3. If a suitable sensor is verified, develop a transparent baseline and persistence-based anomaly study; otherwise document the blocked objective.
4. Use only existing, sequentially released hardware; no new sensors, cloud, or outside datasets.
5. Record missing equipment and continue to P14.

## 5. System requirements

- No temperature, humidity, pressure, gas, vibration, or light capability is attributed to the generic set until identified.
- Manufacturer documents must match the physical sensor and revision.
- Units, resolution, accuracy, sampling cadence, mounting/orientation, and operating range must be sourced.
- A compatible host/logging path and existing software must be explicitly confirmed; none is listed.
- Baseline and thresholds must be derived from data under documented conditions. No ML without data and meaningful validation.
- No hazardous heat, steam, chemical, dust, or industrial process exposure.

## 6. Hardware used

| Inventory item | Quantity | P13 use | Status |
|---|---:|---|---|
| Sensors (generic set) | 1 set | Candidate climate sensing only if a suitable sensor is physically identified | Contents, interface, condition, calibration unknown |
| Host/controller | 0 allocated by inventory | Required only if set is not self-logging; not confirmed | Unknown |
| P06 Sensor Hub / P10 CC3200 sensors | Not allocated to P13 | Separate projects/conditional boards; reuse only after release and explicit inventory reallocation | Not assumed |

## 7. Hardware not required

No extra temperature/humidity sensor, data logger, gateway, host computer, reference thermometer/hygrometer, calibration chamber, network, cloud service, or sensor interface is in scope.

## 8. External components required

None planned. If no suitable sensor/host/logger/reference is already present, the measurement experiment is blocked. Do not procure or borrow components.

## 9. Estimated additional cost

Planned purchases: **$0**. Existing generic-set cost is unknown. All missing dependencies remain blockers.

## 10. System architecture

Future conditional: identified in-stock climate sensor → matched interface/host → timestamped, unit-preserving samples → quality/freshness checks → robust baseline/residual and persistence gate → local record/indicator only if already supported. Current build status: sensor identity and all host/logging blocks unresolved.

## 11. Connection diagram

See diagrams. They deliberately show an unidentified input; no wiring is specified.

## 12. Pin mapping

No pin map can be written until exact sensors and host are identified. Never assign connector pins by analogy to P06/P10 devices.

## 13. Communication protocol

None selected. No Wi-Fi, MQTT, USB, or browser endpoint is assumed. A local logging format may be chosen only after the actual host/storage path is verified.

## 14. Software architecture

Proposed after gates: physical sensor profile → acquisition/units → timestamp and validity → baseline updater with freeze/contamination guard → robust anomaly/persistence detector → local status/log. No code/toolchain is present or confirmed.

## 15. Algorithm

Start with transparent per-channel rolling median and median absolute deviation or a fixed limit grounded in sensor specifications and a measured baseline. Require persistence over a defined window; mark stale/out-of-range data invalid, not anomalous. Avoid complex models until representative, validated data exist.

## 16. Working principle

Acquire only a verified sensor value and its timestamp/quality. Compare to a predeclared baseline and apply a persistence condition; maintain separate `valid`, `warning`, `anomaly`, and `unknown` states. No output is currently available because the sensor/logger is unidentified.

## 17. Step-by-step build procedure

See [docs/TUTORIAL.md](docs/TUTORIAL.md): inventory generic set → identify component → match documentation → confirm host/software/logging/reference in stock → stop if any gate fails. If all pass later, characterize sensor before anomaly logic. Continue to P14 now.

## 18. Firmware setup

No firmware. Exact sensor/controller/toolchain are unknown. Do not code or flash.

## 19. Software setup

No software selected or installed. Use only software already provided. Missing toolchain/logger blocks implementation; no download/install.

## 20. Web interface setup

Not applicable. No web dashboard or cloud is assumed.

## 21. Testing procedure

No data/tests exist. Future tests require confirmed sensor, host, reference, safe ambient conditions, and a provided log path. Proposed checks: stationary repeatability, sample timestamp, missing/stale/out-of-range faults, and offline synthetic-data algorithm validation only if an existing software tool is available.

## 22. Expected output

If every dependency is confirmed: timestamped samples with sensor identity/units/validity and a transparent normal/warning/anomaly/unknown label. No sample reading or detection result is claimed.

## 23. Troubleshooting

See [docs/TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md). Do not probe unknown voltage/current or expose an unidentified sensor to an environment.

## 24. Performance metrics

Proposed: sensor availability, sample interval variation, repeatability, missing/stale detection latency, anomaly detection delay, false-alarm rate per observation period, and agreement with an independent reference. No thresholds are set without sensor datasheet and baseline.

## 25. Limitations

Generic sensor set identity, calibration, host/controller, software, logging and reference are all unknown. P06/P10 sensors are conditional and separately allocated. No data, ground truth, industrial environment, or calibration tool is listed. Any numerical accuracy/anomaly claim would be unsupported.

## 26. Future improvements

Only using verified, already-listed items after checkout/release: test a suitable identified sensor with a valid existing host/logger, document baseline drift, and compare simple robust thresholds. Do not add sensors, cloud, or ML.

## 27. Research opportunities

For an identified in-stock climate sensor and safe time series, does a persistence-gated robust residual reduce isolated-noise false alarms versus a fixed single-sample threshold while preserving detection delay? This question is blocked until the sensor and data path exist.

## 28. References

- [Supplied hardware inventory](../HARDWARE_INVENTORY.md) — identifies one generic sensor set and explicitly leaves its contents unknown.
- TI [Sensor Hub User Manual SPMU290](https://www.ti.com/lit/ug/spmu290/spmu290.pdf) and [CC3200 LaunchPad guide SWRU372C](https://www.ti.com/lit/ug/swru372c/swru372c.pdf) document separate conditional project assets only; they do not identify the generic P13 set.
- NIST/SEMATECH, [e-Handbook of Statistical Methods](https://www.itl.nist.gov/div898/handbook/) — general process data/statistical reference; no method or limit is validated for this lab.

## 29. License

See root [LICENSE](../LICENSE); project licensing decision pending. No sensor data or external code included.

## Reproducibility checklist

- [ ] Every item in generic sensor set identified from physical labels
- [ ] Manufacturer docs match the actual sensor and host
- [ ] Calibration/accuracy and logging/reference availability recorded
- [ ] No other project's hardware reused without release/reallocation
- [ ] Baseline and persistence rule fixed before analysis
- [ ] No code, data, or results claimed before verification
- [ ] Continue sequentially to P14
