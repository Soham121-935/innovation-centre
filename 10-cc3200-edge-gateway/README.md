# Project 10 — CC3200 Autonomous Industrial IoT Edge Gateway (Local-Only MVP)

**Status:** 🟡 In Development — the listed CC3200SF LaunchPads are a strong candidate for standalone sensing/Wi-Fi; exact board revisions, sensor population, SDK and USB host access are unverified.<br>
**Inventory:** 2 CC3200SF LaunchPads; P10 can use one or two sequentially. No external router, client, sensors, or computer is listed.<br>
**Evidence:** TI SWRU372C documents the CC3200-LAUNCHXL integrated MCU/Wi-Fi, BMA222 accelerometer, and a TMP008 temperature sensor that is DNP on newer builds. No board has been inspected or tested.

> Use only verified onboard sensors. If the physical board matches, treat the BMA222 as conditional; use TMP008 only if physically populated. A two-board local AP/server + station/client test may avoid a router/browser, but SDK/USB access remains unconfirmed. No cloud, external sensors, or downloads. Continue to P11 if blocked.

## 1. Problem statement

Evaluate a small self-contained edge node that samples verified onboard motion/temperature sensors, validates data locally, and—if the existing software supports it—exchanges a compact status record between two listed CC3200 LaunchPads over a local Wi-Fi link.

## 2. Real-world application

A local edge monitor can flag motion-state changes and sensor faults without internet access. It is a lab proof of concept, not a calibrated industrial gateway, remote alarm, or production IoT deployment.

## 3. Why the problem matters

Edge processing can limit data volume and continue during internet outages, but sensor fitment, timestamps, power, Wi-Fi loss, and invalid readings must be visible. “Gateway” does not imply an available client, router, cloud, or sensor network.

## 4. Project objectives

1. Confirm the physical LaunchPad model/revision and sensor population on each listed CC3200SF board.
2. Use only onboard sensors physically present and described by matching TI documentation.
3. If the existing SDK/host/USB setup is already available, characterize local sensor reads and faults.
4. Optionally use the second listed CC3200 board for isolated AP/server-to-station/client telemetry; no external router/browser.
5. Separate local sensing/indicator capability from network/dashboard capability; record unavailable pieces rather than assuming them.

## 5. System requirements

- Exact board revision and sensor-population inspection required. SWRU372C says Rev3.2 references mostly apply to Rev4.1, with changes documented separately; inventory revision is unknown.
- TI guide identifies BMA222 accelerometer and TMP008 temperature sensor; it notes TMP008 U6 is DNP on newer board builds. Verify presence physically before using any temperature channel.
- Built-in MCU/Wi-Fi and FTDI emulator are conditional on board match; USB cable/toolchain are not confirmed by inventory.
- CC3200 can operate as Wi-Fi AP or station, but compatible firmware/software is not confirmed.
- No phone, computer/browser, router, internet, broker, extra sensors, or cloud access assumed.
- RF operation requires local lab approval; do not join institutional networks or expose a service outside the isolated test.

## 6. Hardware used

| Inventory item | Quantity | Proposed use | Status |
|---|---:|---|---|
| CC3200SF LaunchPad | 1–2 of 2 | Local edge sensor node; optionally second peer for AP/station test | Exact LaunchPad revision/MCU/condition unknown |
| BMA222 | 0–2 if physically fitted | Board acceleration input | Conditional on matching board and sensor population |
| TMP008 | 0–2 if physically populated | Temperature-sensor input | SWRU372C states U6 is DNP on newer builds; inspect |
| USB cable/computer/SDK | 0 listed separately | Program/debug only if already present | Not assumed |

TI guide also documents two user buttons, three LEDs, onboard emulator, and USB power/debug for matching CC3200-LAUNCHXL; these are conditional on exact board match.

## 7. Hardware not required

No external temperature/IMU sensor, router, phone, PC browser, cloud broker, motor, gateway, or remote server is in scope. No other project's sensor hub or generic sensor set is borrowed.

## 8. External components required

None planned. If the board revision lacks a sensor, or software/USB access is absent, the affected sensing/network step is blocked; do not add a replacement sensor or acquire tools.

## 9. Estimated additional cost

Planned external cost: **$0**. Existing hardware/software acquisition cost is unknown.

## 10. System architecture

Local sensor node: verified BMA222 and optional fitted TMP008 → on-board CC3200 MCU → range/freshness/fault gate → local LED/status. Optional two-board test: node A hosts local Wi-Fi AP/endpoint; node B joins as station and validates status age/content. No internet path, external client, or cloud service.

## 11. Connection diagram

See diagrams. No external wiring is planned. Do not add BoosterPacks or connect a sensor until exact host/header compatibility is checked.

## 12. Pin mapping

No lab pin map is established. SWRU372C provides a pinout for CC3200-LAUNCHXL revisions; only use after exact board/revision match. Sensor I²C jumpers and GPIO mapping are conditional. No external wiring instructions are given.

## 13. Communication protocol

No Wi-Fi channel, SSID, credentials, HTTP route, or broker is configured. If the installed TI SDK already supports a local endpoint, use a bounded status schema: board/node ID, sequence, sample age, motion state, temperature only if sensor fitted, and validity bits. Do not join public/institutional Wi-Fi.

## 14. Software architecture

After gates: board-specific sensor drivers → local sample timestamps/validity → simple motion/temperature state logic → on-board status → optional CC3200 local network interface → second-node freshness/timeout parser. No code or software package is selected.

## 15. Algorithm

For BMA222, use a transparent stationary/motion indicator based on documented accelerometer samples and measured baseline; do not infer machine fault or human activity. For temperature, retain sensor-native units and mark unavailable if TMP008 is not populated. For network exchange, use sequence and age checks. No ML or unsupported anomaly model.

## 16. Working principle

Sample only physically present sensors; attach time and validity; indicate invalid/stale data explicitly. A local client response is accepted only if sequence/age checks pass. Link loss becomes “unknown,” not a safe or healthy state. No actuation.

## 17. Step-by-step build procedure

See [docs/TUTORIAL.md](docs/TUTORIAL.md): identify revision → inspect sensor population/jumpers → verify existing SDK/USB → characterize onboard sensors → optionally test two-node AP/station → record link/fault metrics. Stop if tools or sensors are unavailable.

## 18. Firmware setup

No firmware is written or flashed. Use only a matching board profile and an already-provided authorized SDK; no downloads/install. CC3200 SOP/JTAG settings are not to be changed without exact guide and supervisor approval.

## 19. Software setup

TI lists Code Composer Studio/IAR and CC3200 examples; none are confirmed in the lab inventory. Do not install or download. If missing, record blocker and proceed to P11.

## 20. Web interface setup

No browser UI is in scope because no browser client is listed. The second CC3200 may verify local application data transport only if existing software supports it; do not claim a web dashboard or browser test.

## 21. Testing procedure

No tests have run. Proposed: board/sensor identity; safe stationary accelerometer read; temperature channel only if fitted; sensor validity; local LED state; isolated two-board AP/station data-age and reconnect if software exists. No external instrument or network.

## 22. Expected output

If gates pass: a local status/validity indicator and optional two-node timestamped status exchange. No measured values, accuracy, browser dashboard, or results are supplied.

## 23. Troubleshooting

See [docs/TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md). Do not change board jumpers or probe pin connections unless the matching revision guide explicitly requires it.

## 24. Performance metrics

Proposed: per-sensor sample availability/errors, stationary acceleration variance, movement-detection latency, TMP008 availability/repeatability if populated, node-to-node status age/latency, packet loss/reconnect, and false-valid indications. No absolute accuracy claim without a listed reference.

## 25. Limitations

CC3200 LaunchPad revision is unknown; onboard temperature sensor may be absent (U6 DNP on newer builds). BMA222 and TMP008 are board-level demonstration sensors, not industrial/calibrated instruments. Software/computer/USB availability unknown. No browser or cloud client; no external sensor, machine, or site network.

## 26. Future improvements

Only with existing board/software: compare local-only versus two-node mode, record sensor fault handling, and evaluate disconnected state. No new sensors, client, router, cloud, or mobile app.

## 27. Research opportunities

Can simple on-device validity and sequence/freshness checks preserve trustworthy local state across Wi-Fi loss on a verified two-board CC3200 setup? This is blocked until physical and software gates pass.

## 28. References

- TI, [CC3200 LaunchPad Hardware Guide SWRU372C](https://www.ti.com/lit/ug/swru372c/swru372c.pdf) — board features, BMA222, TMP008 fitment caveat, revisions, power/debug.
- TI, [CC3200 datasheet](https://www.ti.com/lit/ds/symlink/cc3200.pdf) — integrated MCU/Wi-Fi capabilities; board-level details remain conditional.
- TI, [CC3200 SDK/software page](https://www.ti.com/tool/CC3200SDK) — reference only, not an assumed download.
- [Supplied inventory](../HARDWARE_INVENTORY.md).

## 29. License

See root [LICENSE](../LICENSE); repository license decision pending. Follow TI SDK/firmware terms and local wireless/network policies.

## Reproducibility checklist

- [ ] Exact CC3200SF board revisions recorded
- [ ] BMA222/TMP008 physical population checked individually
- [ ] Existing SDK/computer/USB access confirmed
- [ ] No unlisted client, router, sensor, or cloud path assumed
- [ ] RF/network setup isolated and locally approved
- [ ] Sensor, freshness, and reconnection metrics documented
