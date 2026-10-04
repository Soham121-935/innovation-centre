# Project Status

Status values follow the repository convention: 🔴 Not Started · 🟡 In Development · 🟢 Working · 🔵 Advanced · ⚫ Archived. **Blocked** describes a gate; a project may be 🟡 when desk research/documentation is in progress despite that gate.

**Repository readiness:** all 14 project packages are documented and structurally validated. Physical build readiness is separate and remains project-specific; no hardware integration is claimed. P03 has only a hardware-independent, synthetic-host-tested algorithm. Run `make test` for the reproducible repository checks; it does not build or flash target firmware.

| # | Project | Current phase | Status | Gate / evidence |
|---:|---|---|---|---|
| 01 | Autonomous Industrial Mobile Robot | Inventory-only architecture and source research; physical gate open | 🟡 In Development | Exact RSLK family/revision, LaunchPad pairing, sensor-set contents, power stock, and provided route/landmarks unverified/not listed. Full MVP blocked if needed stock is absent. No purchases, firmware, or bench results. |
| 02 | Neuro-Controlled Human-Robot Interface | Conditional manufacturer research and identity gate | 🟡 In Development | Inventory gives no manufacturer/model. Neeuro SenzeBand 2 / SB-02 is only a research candidate; physical label and existing SDK/developer access must be verified. No code or signal results. |
| 03 | RSLK Sensor Fusion and Autonomous Perception | Portable fusion core and synthetic host tests; sensor/variant gate | 🟡 In Development | Host unit tests pass, but use fabricated inputs only. RSLK family and RSLK Sensors contents unknown; MAX modalities are conditional only. No target build, hardware integration, physical test, or fusion result. |
| 04 | Long-Range Industrial Emergency Wireless Network | Radio documentation and safety/RF boundary | 🟡 In Development | Two CC110L BoosterPack entries, but exact SKU/host and locally approved RF profile are not verified. Not a safety/emergency system; no transmission. |
| 05 | Real-Time Industrial Motor Condition Monitoring | Measurement-path requirements; physical MVP blocked | 🔴 Blocked | TIVA model, motor/driver/encoder/current or vibration measurement path, software and safe test setup are not identified in supplied stock. |
| 06 | Distributed Sensor Fusion using SenseHUB | Conditional BOOSTXL-SENSHUB/host research | 🟡 In Development | Sensor suite and supported TIVA hosts documented conditionally; exact booster/host, existing TivaWare, computer and cables unverified. No code/data. |
| 07 | Sub-GHz Industrial Asset Tracking and Telemetry | Two-node link design; RF emission gate | 🟡 In Development | Two BOOSTXL-CC1125 and candidate F5529 hosts; regional RF authorization, board match and existing tools unverified. Scope narrowed to link presence/quality, not localization. |
| 08 | BLE Industrial Proximity and Safety System | Two-node non-safety HMI design | 🟡 In Development | Two BOOSTXL-CC2650MA and two MSP432P401R boards listed; exact revisions, existing host SDK/USB access and local BLE approval unverified. RSSI is not safety distance. |
| 09 | CC3100 Embedded Industrial Web/Data Acquisition System | Local two-node network design | 🟡 In Development | CC3100BOOST/MODBOOST model and host software/power access unknown. Browser client and sensor are not inventoried; web UI/data acquisition remains blocked. |
| 10 | CC3200 Autonomous Industrial IoT Edge Gateway | Onboard-sensor identity research | 🟡 In Development | CC3200SF LaunchPad revisions unknown. BMA222 and optional TMP008 documented conditionally; TMP008 may be unpopulated. SDK/USB access unverified; no cloud/client assumed. |
| 11 | MSP432 Real-Time Adaptive Industrial Control System | Requirements/research only; physical control blocked | 🔴 Blocked | Only MSP432 controller boards are listed. No plant, actuator, process sensor, safe power stage, independent measurement or simulator is identified. |
| 12 | MSP430 Ultra-Low-Power Industrial Sensor Node | Measurement plan; quantitative energy test blocked | 🟡 In Development | TI target-current procedure requires an ammeter across the 3.3 V isolation jumper; no ammeter listed. EnergyTrace/debugger support and host software not confirmed. |
| 13 | Industrial Climate Anomaly Detection and Automatic Response | Sensor-set identification gate | 🔴 Blocked | One generic sensor set has no identified contents/interface/host/logger/reference; no actuator for automatic response is listed. No capability assumed. |
| 14 | OMAP-L138 Real-Time DSP Machine Fault Diagnosis | Conditional LCDK/audio research; acquisition blocked | 🔴 Blocked | Exact kit variant, external emulator, audio source/microphone/cables and host software unverified. If LCDK, guide says no onboard emulator. No samples/data. |

## Sequential work log

- **2026-10-03 — P01:** Documented conditional TI-RSLK MAX research and inventory-only scope. Removed external range-sensor/battery purchase planning, set planned additions to $0, and recorded compatible range sensing/power/course as blockers if not already in stock. No physical identity or measured results.
- **2026-10-03 — P02:** Began conditional Neeuro SenzeBand 2 / SB-02 research. The inventory's “Neuro Sense Band” does not confirm the candidate; SDK/developer access is unverified. No code or signal results.
- **2026-10-03 — P03:** Completed inventory-only sensor-fusion plan; RSLK family and sensor-set identity remain unresolved. TI-RSLK MAX details are conditional; no pins/code/data.
- **2026-10-03 — P04:** Documented CC110L candidate, absent/unverified compatible host and need for local RF authorization. Explicitly excluded emergency/safety use and RF transmission.
- **2026-10-03 — P05:** Documented TIVA/motor-feedback requirements; exact board and compatible in-stock motor/driver path are not established. Physical condition monitoring blocked.
- **2026-10-03 — P06:** Researched official BOOSTXL-SENSHUB sensors and TIVA host compatibility conditionally. Exact board/host and already-available TivaWare/PC/cables unknown.
- **2026-10-03 — P07:** Researched TI BOOSTXL-CC1125/MSP430F5529 pairing. Two-node link/presence study only; local RF approval is a hard no-emission gate.
- **2026-10-03 — P08:** Documented TI BOOSTXL-CC2650MA + MSP432 host candidate as a two-node, informational, non-safety HMI. Existing SDK, USB/host and local BLE approval unverified.
- **2026-10-03 — P09:** Documented conditional CC3100BOOST host support and a local two-node design. Exact variant, current/power path, SDK, physical input, browser client and software access unresolved.
- **2026-10-03 — P10:** Corrected sensor facts from TI SWRU372C: BMA222 accelerometer, and TMP008 only when fitted (U6 DNP on newer boards). Exact board revision, SDK/USB and local Wi-Fi approval unresolved.
- **2026-10-03 — P11:** Recorded the absence of a plant, actuator, process sensor and independent reference. Kept this to requirements/research only; no LED or MCU-temperature substitute.
- **2026-10-03 — P12:** Documented TI F5529LP target-current method. No ammeter is listed; EnergyTrace is not assumed for eZ-FET Lite. Quantitative energy testing is blocked.
- **2026-10-03 — P13:** Recorded the single unnamed generic sensor set as a blocker. No sensor capability or pin is invented; P06/P10 boards are not reassigned.
- **2026-10-03 — P14:** Documented conditional OMAP-L138/C6748 LCDK audio ports and external-emulator requirement. Exact board, emulator, software, audio source and acquisition chain remain unverified.
- **2026-10-04 — P03 portable firmware core:** Added a hardware-independent C fusion function and synthetic host tests. GCC 12.2.0 strict C11 and AddressSanitizer/UndefinedBehaviorSanitizer runs pass. This is not a board-target build or physical test; RSLK/sensor identity, units, thresholds, interface, toolchain, calibration and hardware remain unverified.
- **2026-10-04 — Repository readiness:** Added dependency-free structural/Markdown validation, `make test` host-test orchestration, and GitHub Actions checks. All 14 workspaces pass repository QA; this does not change project-specific hardware gates or assert target firmware.

## Implementation policy

P03 is the limited exception: a hardware-independent algorithm core may be host-tested with synthetic fixtures before board identity is known, provided it makes no hardware claims. Target firmware, board profiles/drivers, and physical tests remain gated by project identity, safety, existing inventory, compatible software/access, and measurable test requirements. Never treat compilation, synthetic tests, or simulation as bench verification. Missing items are blockers, not purchase recommendations; otherwise record progress and move to the next project in order.
