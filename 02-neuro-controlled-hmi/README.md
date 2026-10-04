# Project 02 — Neuro-Controlled Human-Robot Interface

**Status:** 🟡 In Development — conditional manufacturer research only; physical identity and software access are unverified<br>
**Primary inventory hardware:** “Neuro Sense Band” (2 listed; model/manufacturer/condition not given; reserve at most 1 for P02 after checkout)<br>
**Evidence state:** Neeuro SenzeBand 2 / SB-02 is a documented research candidate only, not a confirmed match. No device has been inspected or tested. No code, firmware, signal results, or robot-control claims exist.

> **Inventory-only scope:** P02 followed P01's hardware-gate blocker in the required sequence; the repository has since documented P03–P14. Use only the listed band and software/access that are already provided. Do not assume a host computer, Bluetooth adapter, charging accessory, vendor SDK, developer account, license, or robot bridge exists; if a required item is unavailable, record the blocker and continue to the next project. Do not purchase or substitute unlisted hardware/software.

**Initial concept:** If the physical band and existing manufacturer-supported interface are verified, evaluate whether its signal/state output can reliably generate a *human-confirmed command request* in a local HMI. Do not equate attention/relaxation or other measured states with decoded motor intent. Robot actuation is outside the first-stage MVP.

## 1. Problem statement

Determine whether the listed neuro-sensing band can support a repeatable, low-risk HMI interaction using only its documented, already-available interface. The inventory label is ambiguous, so the first problem is hardware and software identification—not BCI implementation.

## 2. Real-world application

A possible future application is an assistive or hands-busy interface that offers a command request to a human operator. This repository's first P02 demonstration, if the gates pass, is limited to a local visual/audio-free status/request output and explicit human confirmation. It is not an assistive medical device and does not directly command a moving robot.

## 3. Why the problem matters

Wearable EEG can be affected by electrode contact, motion, blinks, muscle activity, and user/session variability. A plausible interface must measure signal availability, latency, missed requests, and false activations—not merely display a mental-state score. Published reviews of EEG-based dynamic-device control report that decoder outputs can be unstable; shared control and conservative action gating are therefore essential [4].

## 4. Project objectives

1. Identify the exact “Neuro Sense Band” manufacturer, model, hardware revision, and included accessories from the physical unit and package.
2. Find the official documentation matching that exact model; keep other models' specifications explicitly conditional.
3. Verify whether a compatible host, vendor app/SDK, developer access, and any required network/license are already provided.
4. If the supported data interface is available, characterize signal-ready time, data dropouts, update/decision latency, repeatability, and false request rate.
5. Define a calibrated command-*request* protocol with persistence/hysteresis, an explicit reject/confirm step, and a fail-silent state.
6. Keep all initial output local and non-actuating. Consider an RSLK link only after P01 hardware is verified and a documented, already-available interface and safety path are proven.
7. Store only the minimum data needed for the approved evaluation; do not commit identifiable or raw biometric data to the repository.

## 5. System requirements

- The physical device identity must match the primary-source documentation used by the project.
- No capability (EEG channels, sample rate, processed mental states, PPG, IMU, Bluetooth version, SDK API, or pinout) is assumed from the phrase “Neuro Sense Band.”
- A host computer/OS and compatible official app/SDK must already be provided and accessible; they are not in the supplied hardware table. If not, stop at desk research and record the blocker.
- Any SDK developer code, license, vendor account, Internet authentication, or network dependency must be verified as already authorized/available. Do not assume the SDK is free or request/procure access.
- The first test produces a local request/status only. A band output can never directly energize a motor or bypass a human supervisor.
- A valid request must require fresh, signal-ready data, stable state over a measured dwell interval, calibrated thresholds, and explicit confirmation. Stale/disconnected/poor-contact data must fail silent.
- Human participation requires informed consent and institutional privacy/ethics approval where applicable. No diagnostic, therapeutic, or impairment-detection claims.
- No external sensors, electrode gel, MCU, Bluetooth dongle, robot interface, cloud service, or custom circuit is added to the plan.

## 6. Hardware used

### Listed inventory

| Item | Inventory quantity | Planned use | Evidence / gate |
|---|---:|---|---|
| Neuro Sense Band | 2 | At most 1 for P02 after physical checkout | Manufacturer, model, revision, condition, included charger/accessories, and interface unknown |
| Host computer | Not listed | Only if an existing lab host is separately confirmed as provided | OS, Bluetooth capability, and availability unknown; not assumed or budgeted |

### Conditional research candidate: Neeuro SenzeBand 2 / SB-02

Official Neeuro material identifies SenzeBand 2, model SB-02, as a non-invasive EEG headband with seven proprietary dry electrodes and four EEG data channels, 250 samples/s, 24-bit resolution, Bluetooth 5.0, and integrated PPG and motion sensors. Its vendor SDK documentation describes raw/filtered EEG and SDK-derived state/status outputs. These facts describe **SB-02 only** and apply to the Innovation Center item only if its physical model label matches. The SDK's documentation and developer-access requirements are listed in [hardware/VERIFICATION.md](hardware/VERIFICATION.md).

## 7. Hardware not required

A second band, extra EEG electrodes/amplifier, external MCU, separate BLE radio/dongle, Raspberry Pi, motor driver, robot-mounted sensor, camera, cloud service, custom PCB, or extra actuator is not part of the P02 plan. P02 does not require the RSLK to demonstrate its first-stage HMI output.

## 8. External components required

**None planned.** Use only the listed band and any host/accessories/software already present and authorized in the lab. If the unit cannot be charged, connected, or read without an unlisted cable, adapter, computer, SDK, account, or license, mark that step blocked and proceed without it. No unlisted purchase or substitute is recommended.

## 9. Estimated additional cost

- **Planned external hardware/software purchases:** **$0**.
- **Existing band/host acquisition cost:** not supplied.
- **SDK/developer access or licensing:** status and terms not verified; not budgeted or assumed to be included. If required access is not already available, custom SDK work is blocked; do not procure it under this phase.
- **Unlisted host/accessory cost:** not estimated because those items are excluded rather than planned.

See the inventory-only [BOM](BOM/bom.md).

## 10. System architecture

The conditional data path is: verified band → manufacturer-supported BLE/app interface → existing local host → signal/contact/data-quality gate → conservative state/request decision → local HMI request → human confirmation. Disconnection, stale data, weak contact, or unavailable vendor authentication clears the request and returns the interface to an idle state. The host software/API, not undocumented electrical pins, is the interface boundary. Any later RSLK connection is a separate optional phase gated by P01 verification, an existing supported bridge, and a safety review; it is not part of this MVP.

See the [system block diagram](diagrams/01-system-block-diagram.md), [conditional connection diagram](diagrams/02-hardware-connection.md), [data flow](diagrams/03-data-flow.md), and [software architecture](diagrams/04-software-architecture.md).

## 11. Connection diagram

The only candidate hardware connection is wireless communication through the band’s documented interface; for SB-02, Neeuro documents Bluetooth 5.0. Do not pair, use a BLE protocol, or assume an SDK until the model and official instructions are verified. No inter-board wires or sensor pins are defined.

## 12. Pin mapping

**Not applicable / none defined.** The listed item is described as a band, not a board exposing user pins. There is no verified connector, pin map, voltage rail, or direct MCU interface. Use only an official host SDK/API if it matches the physical device; do not reverse-engineer or invent BLE characteristics.

## 13. Communication protocol

Conditional SB-02 link: BLE 5.0 managed by NeeuroOS/official vendor software. The official SDK guide documents discovery, connection, authentication, signal/contact checks, data callbacks, and disconnection. Developer-code authentication requires a vendor-issued code and Internet access according to that guide; whether P02 has authorized access is unknown. No direct radio protocol, serial protocol, cloud data path, or RSLK message format is claimed. The initial HMI output remains local to the existing host.

## 14. Software architecture

If—and only if—the existing host, supported OS, matching vendor SDK, and authorized developer access are available:

1. **Device adapter:** use vendor discovery/connect/authentication APIs; do not create a custom transport.
2. **Quality gate:** require device connected, fresh samples, and the vendor's signal/contact-ready indicators if exposed by that exact SDK.
3. **Feature/state input:** initially consume only documented vendor outputs. Access raw EEG only when explicitly available and authorized; no custom classifier in the first pass.
4. **Decision gate:** user-calibrated threshold plus dwell, hysteresis, cooldown, and explicit human confirmation. On ambiguous or missing data, emit no request.
5. **Local HMI/log:** display connection, quality, state freshness, request/confirm/reject status, and timestamps. Minimize retained personal data.
6. **Optional later bridge:** only after P01 release and identity verification; require a separately reviewed command protocol and physical stop independent of EEG.

No host app or firmware is implemented.

## 15. Algorithm

Baseline the simplest testable method: use the manufacturer's documented state/status output (if available for the verified unit); calibrate a per-user resting/active range using the official procedure; require signal-ready and a stable threshold crossing for a measured dwell; apply hysteresis and cooldown; display a request; require an explicit separate confirmation. Thresholds are proposed parameters to measure, not validated values. Do not train a custom ML model, infer motor imagery, or label a state as intent without a validated protocol and data. If the vendor output cannot expose a stable, intended signal, stop the control experiment and report the limitation.

## 16. Working principle

A wearable sensor records physiological signals. A documented SDK may provide measured signal-quality values and/or vendor-processed state outputs. The HMI observes those outputs, rejects poor/stale data, and only presents a stable request after calibration and dwell. A human then confirms or rejects that request. The signal is not a deterministic command, a thought decoder, or a safety channel.

## 17. Step-by-step build procedure

See the [sequential tutorial](docs/TUTORIAL.md). In order: identify the device → check only already-provided accessories and host/software → verify official-app connection without custom code → establish data-quality baselines → measure a no-command baseline → evaluate request/confirmation behavior → report limitations. Stop at any unavailable model, accessory, host, vendor access, or safe test requirement. Do not procure missing items.

## 18. Firmware setup

No firmware is planned for the band. Its device firmware is manufacturer-controlled unless official documentation for the exact model says otherwise. No MSP432/RSLK firmware is part of the first P02 stage. Do not flash or modify the band or a robot based on this desk research.

## 19. Software setup

No installation has been performed or selected. Check whether a compatible official app/SDK and supported host are already provided. The NeeuroOS standard SDK manual describes platform-specific Android, iOS, Windows, and Unity support and developer-code authentication; this is conditional on SB-02 identity. If software, license, developer code, or network access is unavailable, mark custom integration blocked—do not install, purchase, or substitute another package.

## 20. Web interface setup (if applicable)

Not applicable to the first-stage MVP. No website, remote dashboard, or cloud data service is planned. A local screen in an already-available vendor app/host may be used if provided; do not build a web interface or transmit biometric data to a service.

## 21. Testing procedure

No test has run. Proposed tests, conditional on identity/access/safety gates passing:

1. Confirm exact model and documentation; record SDK/app and host versions already present.
2. Verify charge/connection and manufacturer signal-ready/contact status with no actuation.
3. Run seated, consented data-quality sessions; log timestamps, dropouts, quality flags, and only the minimum vendor output required.
4. Establish an idle/no-request baseline before mapping any state to a visible request.
5. In a controlled within-user trial, perform 20 request attempts and 20 no-request intervals across at least three sessions; randomize/counterbalance where practical and record event markers.
6. Keep output as a local on-screen request with a separate human confirm/reject action. Test stale data, disconnection, weak contact, timeout, and app restart; each must clear the request.
7. Repeat analysis across sessions. Do not connect to an RSLK or move a robot in this phase.

## 22. Expected output

A local HMI/status display and a timestamped, pseudonymized test log **only if** the necessary stock device/software gates pass. Logs should include device/SDK version, session ID not tied to a person, connection and quality state, event markers, request/confirm/reject event and latency, and test outcome. No example readings, signal accuracy, or measured results are claimed yet. Raw EEG/PPG should not be stored unless explicitly needed, consented, access-controlled, and approved under applicable institutional policy.

## 23. Troubleshooting

Use the conditional matrix in [docs/TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md). First record physical model, firmware/app/SDK versions, host OS, and the exact error. Do not change band firmware, invent a BLE characteristic, disable authentication, or substitute unsupported software to bypass a problem.

## 24. Performance metrics

Proposed engineering metrics (thresholds are **initial acceptance targets**, to be reviewed after a pilot and not medical/safety claims):

- **Signal-ready availability:** fraction of a 10-minute session with the verified SDK reporting data ready; initial target ≥95%.
- **Data dropout rate:** missing/stale samples or SDK connection gaps divided by expected observations; report per session and duration.
- **HMI latency:** event-marker-to-request display time; report median and 95th percentile, initial target p95 ≤3 s.
- **Request detection rate:** confirmed visible requests divided by 20 intended request trials; initial target ≥80% within-user, with per-session results shown.
- **False-request rate:** requests during no-request intervals per hour, plus false positives divided by no-request epochs; initial pilot target 0 observed false requests during each 10-minute no-request block. Zero observations in a short pilot do not prove a low long-term risk.
- **Fail-silent behavior:** 100% of injected stale/disconnect/poor-quality tests clear or suppress requests before display confirmation.
- **Calibration repeatability:** across three sessions, report threshold/state distribution and performance variability; do not pool users as if they were interchangeable.

No robot movement metric is applicable to the first-stage MVP.

## 25. Limitations

- The inventory label does not establish the manufacturer or model; all SenzeBand 2 details are conditional.
- Vendor-derived states are not proof of deliberate command intent. Attention/relaxation measures are not synonymous with motor imagery or a robust BCI command.
- Low channel count, electrode contact, eye/muscle artefacts, movement, user/session variation, SDK processing, authentication, and latency can limit performance.
- Developer SDK access may require vendor registration, code, Internet authentication, and licensing; none is confirmed as supplied.
- No signal-quality, usability, false-activation, or latency results exist. A short volunteer trial cannot establish clinical benefit or safe robot control.
- RSLK identity/integration is unverified and is not in P02's first-stage MVP.

## 26. Future improvements

Only after a measured limitation and only with listed/available resources: repeat calibration over more sessions, compare vendor output stability, add better state-transition/hysteresis analysis, assess within-user drift, and evaluate a robot request bridge if P01 hardware and an existing supported link are released and verified. Do not add extra sensors, hosts, radios, accounts, or compute hardware.

## 27. Research opportunities

- How stable are documented vendor state outputs across repeat sessions for one consenting user?
- How do signal-ready availability, motion/contact quality, and event-to-display latency affect false and missed HMI requests?
- Does dwell/hysteresis improve request stability without making the interface unacceptably slow?
- Which shared-control and no-action gating choices best manage unstable EEG-derived outputs? Compare only within the verified SDK/data interface and do not claim device-specific performance from the literature.

## 28. References

1. Neeuro, [SenzeBand product page](https://www.neeuro.com/senzeband) — current manufacturer description; conditional candidate only.
2. Neeuro, [SenzeBand 2 Gold Edition product catalogue (2026-04-14)](https://www.neeuro.com/hubfs/20260414_SB2_Gold_Product%20Catalogue_EN.pdf?hsLang=en) — identifies model SB-02 and manufacturer specifications; applies only if the lab unit matches.
3. Neeuro, [NeeuroOS SenzeBand SDK developer manual](https://neeuroos.neeuro.com/manual/index.html) — platform support, data fields, connection/authentication flow, and Developer Code requirements. Verify the exact package/version before use.
4. N. Padfield, K. Camilleri, T. Camilleri, S. Fabri, and M. Bugeja, “A Comprehensive Review of Endogenous EEG-Based BCIs for Dynamic Device Control,” *Sensors*, 22(15), 5802 (2022). [doi:10.3390/s22155802](https://doi.org/10.3390/s22155802) — literature context for decoder instability/shared control, not validation of this band.
5. [Innovation Center hardware inventory](../HARDWARE_INVENTORY.md) — supplied name and count only; does not establish a Neeuro model.

## 29. License

The repository's top-level [LICENSE](../LICENSE) is pending a rights-holder decision and is not currently an open-source license. Do not redistribute vendor SDK binaries, account credentials, developer codes, user data, or third-party manuals/code beyond their terms.

## Reproducibility checklist

- [ ] Exact physical band manufacturer, model/revision, serial/asset ID, condition, and included accessories recorded privately in the lab record (do not expose personal serials)
- [ ] Matching official hardware/SDK documentation and version recorded
- [ ] Existing compatible host, app/SDK, developer access, license, and network permission confirmed
- [ ] Consent/privacy/ethics and data-retention plan approved before human testing
- [ ] No unlisted hardware/software purchases or substitutions
- [ ] Local request-only architecture and fail-silent behavior reviewed
- [ ] Test matrix, event markers, metrics, and analysis plan reviewed
- [ ] No code, raw data, signal results, or robot-control claims published before verification
