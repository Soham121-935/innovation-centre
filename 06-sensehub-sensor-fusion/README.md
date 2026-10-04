# Project 06 — Distributed Sensor Fusion using SenseHUB (Environmental/Motion MVP)

**Status:** 🟡 In Development — strong conditional in-stock sensor candidate; exact booster/host identities and existing software/host access are unverified.<br>
**Inventory:** 2 “SenseHUB Booster Pack” and 5 “TIVA LaunchPad” units; exact SKUs/revisions unknown.<br>
**Evidence:** TI documents BOOSTXL-SENSHUB compatibility with EK-TM4C123GXL and EK-LM4F120XL. Apply only after physical matching. No sample data, firmware, or tests exist.

> Sequential progress after P05’s unknown motor path. Do not download/install software, assume a PC/USB cable/network, or use optional wireless accessories. If the physical Sensor Hub and TIVA do not match, or existing authorized software/host is unavailable, record the blocker and continue to P07. No code yet.

## 1. Problem statement

Determine whether multiple on-board environmental and motion sensors from a verified, listed TI Sensor Hub can provide a more trustworthy timestamped context record than isolated raw readings, using only the BoosterPack and compatible TIVA LaunchPad already listed.

## 2. Real-world application

A low-cost lab context logger could report ambient temperature/humidity, pressure trend, visible/IR light, object temperature, and board motion/orientation. It is not a calibrated weather station, environmental compliance instrument, or safety monitor.

## 3. Why the problem matters

Sensor values have different units, delays, ranges, and failure modes. Simple fusion can detect inconsistent or stale signals and make context easier to interpret. It must not turn a light or motion reading into an unsupported environmental conclusion.

## 4. Project objectives

1. Confirm the booster is BOOSTXL-SENSHUB and the host is one of its documented compatible boards.
2. Inventory existing software/host access without downloading or purchasing tools.
3. If gates pass, characterize each documented on-board sensor separately and timestamp the values.
4. For the MPU9150, compare a deterministic orientation estimate with raw accelerometer/gyro/magnetometer behavior, following the manufacturer/example limitations.
5. Compare per-sensor validity against a fused context/quality record; report missing/stale data and uncertainty.

## 5. System requirements

- Exact BoosterPack and host board/revision confirmed before connection.
- TI states full compatibility with EK-TM4C123GXL and predecessor EK-LM4F120XL; generic “TIVA LaunchPad” inventory does not confirm either.
- If BOOSTXL-SENSHUB matches, documented sensors are TMP006 IR object-temperature, MPU9150 3-axis accelerometer/gyroscope/magnetometer, BMP180 pressure, ISL29023 ambient/IR light, and SHT21 relative humidity/ambient temperature. Do not assert these exist until the physical board matches.
- Existing TivaWare/toolchain, computer, cables, power, and safe test access are not confirmed; no download/install is permitted by this inventory-only plan.
- No wireless HID/radio demo, optional module, network, or cloud service.

## 6. Hardware used

| Inventory item | Quantity | P06 use | Status |
|---|---:|---|---|
| SenseHUB Booster Pack | 1 of 2 | Candidate five-sensor board | Exact SKU/population/revision unknown |
| TIVA LaunchPad | 1 of 5 | Host only if EK-TM4C123GXL or documented compatible EK-LM4F120XL matches | Exact model unknown; P05 has separate planning reservation |

Conditional BOOSTXL-SENSHUB manual lists two user buttons, one user LED, one power LED, a wireless expansion connector, and nominal board supply through the BoosterPack interface. These are not evidence that the lab board matches.

## 7. Hardware not required

No CC2533EMK/CC2531EMK, RF link, battery BoosterPack, extra sensors, calibration instrument, PC, external display, or router is in scope. The TI Air Mouse example’s PC/HID and wireless accessories are not assumed available.

## 8. External components required

None planned. If a compatible host, existing development software/computer, cable, or required sensor is missing, the affected measurement is blocked. Do not obtain additional equipment.

## 9. Estimated additional cost

Planned external cost: **$0**. Existing software and stock acquisition cost are unknown. See the inventory-only [BOM](BOM/bom.md).

## 10. System architecture

Conditional BOOSTXL-SENSHUB sensors → verified I²C/board interface and host driver → per-channel calibration/unit/freshness checks → synchronized environmental/motion record → deterministic quality/fusion summary → local output only if the verified board/software supports it. No network output.

## 11. Connection diagram

See diagrams. The BoosterPack connector must match the physical BOOSTXL-SENSHUB and supported host. Do not wire it to a generic TIVA pin map.

## 12. Pin mapping

Board-level BoosterPack XL signals are documented in TI SPMU290; see `hardware/pin-map.md`. Host MCU pin/peripheral mapping is conditional on the exact LaunchPad and must be taken from its matching schematic. The connection table is not permission to connect an unverified board.

## 13. Communication protocol

No network protocol. Local sensor interfaces are board-level I²C plus other documented expansion signals; exact sensor instances and host mapping must be checked in SPMU290 and the matching host guide. No data are transmitted externally.

## 14. Software architecture

Proposed after gates: exact board profile → per-sensor drivers → timestamp/range/freshness checks → raw and derived units → simple fusion/quality state → local log only if an existing host method is available. TivaWare SensorLib is a documented software path, not confirmed in stock.

## 15. Algorithm

Use per-sensor validity/range and freshness checks first. For orientation, a complementary/Direct Cosine Matrix method is documented in TI's Air Mouse demonstration; use it only if the exact software and sensor variant support it. Environmental channels are reported independently with timestamps, not combined into an unvalidated “comfort” score. No ML.

## 16. Working principle

Read only verified sensors, preserve raw units, attach sample time and validity, and mark data stale/invalid on communication failure. Compare accelerometer/gyro/magnetometer consistency for orientation only after calibration. A single bad channel must not silently contaminate the whole context record.

## 17. Step-by-step build procedure

See [docs/TUTORIAL.md](docs/TUTORIAL.md): inspect stock → match BOOSTXL-SENSHUB → match supported host → verify existing software and cables → review sensor datasheets → plan stationary characterization. Stop before connection/programming if any component/access is absent.

## 18. Firmware setup

No firmware or pin configuration exists. TivaWare examples are described by TI but are not listed as supplied. Do not download or install packages; record availability blocker.

## 19. Software setup

TI guide describes TivaWare, LMFlashProgrammer and CCS and requires a Windows PC/internet for its example setup. None is in supplied inventory. Use only tools already provided; if missing, no build/run is performed.

## 20. Web interface setup

Not applicable. No web, Wi-Fi, cloud, or wireless add-on is planned.

## 21. Testing procedure

No tests have run. Proposed: physical identity; stationary per-sensor communication; repeated values under documented conditions; freshness/communication-fault handling; orientation consistency only if software/tools are already available. Do not claim calibrated accuracy without a listed reference instrument.

## 22. Expected output

If gates pass, a timestamped local record of sensor identity, raw value/unit, derived value, validity, and orientation estimate when verified. No measurements or result files exist.

## 23. Troubleshooting

See [docs/TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md). Avoid swapping BoosterPack/host pins; follow only matching TI docs. Missing software or host access is a blocker, not an invitation to download/purchase.

## 24. Performance metrics

Proposed: sample availability, I²C/driver error rate, timestamp skew, valid/stale detection latency, repeatability, sensor-to-sensor disagreement, and orientation drift over a stationary interval. Absolute accuracy requires reference instruments, not listed.

## 25. Limitations

Exact board and host are unverified; toolchain/PC/cables are not inventoried. TMP006 is an IR object-temperature sensor, not a contact probe; TMP006/SHT21 temperature readings have different measurement behavior. BMP180 pressure is not altitude without environmental context. The MPU9150’s magnetometer/orientation can be disturbed; no calibration reference is confirmed. No sensor is claimed as calibrated.

## 26. Future improvements

Only with current stock and existing tools: characterize stationary bias/repeatability, estimate sensor timing, and compare simple quality gates. No added calibration instruments, wireless accessories, or external sensors.

## 27. Research opportunities

Does a freshness/consistency layer improve completeness and fault visibility of a multi-sensor context record versus raw values alone on an identified BOOSTXL-SENSHUB? This question awaits physical/software verification.

## 28. References

- TI, [BOOSTXL-SENSHUB Sensor Hub BoosterPack User Manual SPMU290](https://www.ti.com/lit/ug/spmu290/spmu290.pdf) — sensors, electrical interface, connector signals; conditional on exact board.
- TI, [BOOSTXL-SENSHUB Getting Started Guide SPMU295](https://www.ti.com/lit/ug/spmu295/spmu295.pdf) — host compatibility and software prerequisites.
- TI, [EK-TM4C123GXL User Guide SPMU296](https://www.ti.com/lit/ug/spmu296/spmu296.pdf) — only if host matches.
- [Supplied inventory](../HARDWARE_INVENTORY.md).

## 29. License

See root [LICENSE](../LICENSE); repository licensing decision pending. Follow TI software/document license terms; no vendor source is copied.

## Reproducibility checklist

- [ ] BOOSTXL-SENSHUB SKU/revision and sensor population verified
- [ ] Host matches EK-TM4C123GXL or EK-LM4F120XL documentation
- [ ] Existing toolchain/host/cables confirmed without new downloads
- [ ] Board-level signals checked against SPMU290; no assumed host pins
- [ ] Raw units, timing, calibration limits, and tests recorded
- [ ] No accuracy/calibration claim unsupported by a listed reference
