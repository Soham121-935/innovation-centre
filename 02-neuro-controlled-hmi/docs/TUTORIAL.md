# Project 02 — Step-by-Step Tutorial

> **Research/plan only; no physical unit has been identified or tested.** The inventory entry “Neuro Sense Band” does not confirm a Neeuro device. The SenzeBand 2 / SB-02 instructions below apply only after the physical label matches. Use only listed hardware and software already supplied; do not install, purchase, or substitute missing items. Stop at any unresolved identity, access, consent, or safety gate and record the blocker.

## 1. What we are building

If the verified band and existing manufacturer-supported interface permit it, build a local HMI that can present a stable, calibrated physiological-state-based **request** for a human to confirm or reject. The first-stage output is display/log only—no robot movement and no claim that an attention or relaxation score decodes motor intent.

## 2. How the system works

A verified band sends data through its documented vendor-supported link to an existing host. The host checks connection, freshness, and signal quality; a simple calibrated threshold with dwell/hysteresis may then present a request. A separate human action confirms/rejects it. Poor contact, stale data, disconnection, uncertain state, or failed vendor authentication must return to idle and produce no request. The interface is not a safety-rated control.

## 3. Hardware explanation

First read [hardware/VERIFICATION.md](../hardware/VERIFICATION.md). The inventory lists two “Neuro Sense Band” units but no manufacturer/model. Official Neeuro sources describe a conditional candidate: SenzeBand 2 / SB-02, four EEG data channels at 250 samples/s and 24-bit resolution, seven dry electrodes, BLE 5.0, and integrated PPG/motion functions. These specs must not be assigned to the lab band until the exact model is physically confirmed. No pins or wires are defined; the host/software path is conditional.

## 4. Software explanation

No app, SDK, host OS, or developer access is confirmed. If the unit is SB-02, the NeeuroOS manual documents native Android/iOS/Windows and Unity SDK routes, device discovery, authentication, data callbacks, and signal/contact checks. The exact supported versions and API must be checked in the already-available package. The vendor guide says a Developer Code is required and authentication uses an Internet connection; do not assume access or a license is supplied.

## 5. Required tools and prerequisites

Check that these are already available and approved before proceeding; they are not a purchase list:

- One physically identified, working listed band, plus only accessories supplied with it.
- An existing compatible host and OS with Bluetooth capability, if the documented interface requires one.
- Matching official vendor app/SDK and authorized access if already provided.
- Consent, an approved data-handling process, and any required institutional ethics review before collecting participant data.
- A safe, quiet, seated test setting, with manufacturer directions for use, cleaning, charging, and fit.

If any hardware, software, access, or approval is missing, stop and record the blocker. Do not acquire a host, adapter, cable, SDK account, or license for this project phase.

## 6. Software/access check (no new installation)

1. Inspect the lab's existing approved software list and host. Record installed app/SDK version, host OS, and Bluetooth capability only if known.
2. Compare them with the physical band's official documentation.
3. If the model does not match the documentation, do not use the SenzeBand profile or its SDK instructions.
4. If a matching SDK/app, Developer Code, license, or required network authentication is unavailable, mark custom integration blocked and continue to Project 03. Do not download, purchase, request, or substitute access/software as part of this inventory-only phase.
5. If all access is already approved and available, follow the exact vendor quick-start for that package; record its version and steps locally without storing credentials in Git.

## 7. Band firmware/programming

There is no project firmware for the band and no custom firmware step. Do not flash, jailbreak, alter, or reverse-engineer the device. For the conditional SB-02 candidate, use only manufacturer instructions and an already-provided vendor application/SDK. Any future RSLK code is a separate project and remains deferred.

## 8. Wiring and pairing

There is no pin-level wiring. Do not connect the band to an MCU, USB-UART adapter, or BoosterPack from this document. Only if the exact model is confirmed and its official instructions plus already-available host support it, use the vendor's supported pairing/discovery/authentication flow. Do not guess BLE characteristics, bypass authentication, or rely on a generic BLE scanner to collect signals.

## 9. First test — identity and safe status only

1. Record the band label/model and manufacturer; keep any serial/asset identifier in the private lab record, not the public Git repository.
2. Inspect condition and accessories; follow the exact manufacturer fit, charging, and cleaning instructions. Do not charge or wear a damaged/unknown unit.
3. Confirm consent and data permissions before any participant wears the band or signal data are collected.
4. With the vendor app already provided and access authorized, test connection and status only. Do not map a signal to a command.
5. Record whether the device is recognized, whether the SDK reports a stable connection/contact state, and any error/version. Do not invent expected signals; the physical observation remains unrecorded until performed.

**Pass criterion:** exact identity matches the documentation and the official interface reports a stable, supported connection. Otherwise stop and record the blocker; no request/control test proceeds.

## 10. Individual module tests

Complete in order, only if each gate passes:

1. **Power/status:** inspect battery/charge indication using the documented vendor UI. Use only a supplied/available charger or accessory; if absent, defer.
2. **Link:** connect/disconnect through the official app/SDK. Record reconnect time and any vendor-reported data-loss status.
3. **Signal/contact quality:** if the exact SDK exposes channel/contact-ready flags, log them without retaining raw signals unless approved. Do not rely on a state score when signal quality is false.
4. **Data freshness:** compare callback/timestamp cadence to vendor documentation and record dropouts; do not assume the catalogue sampling rate equals the delivered app/SDK callback rate.
5. **Baseline:** with informed consent, run a seated no-command session. Mark start/end using an approved local event marker if the existing interface provides one. Do not ask for a mental command yet.
6. **Vendor output check:** if approved SDK access exposes documented mental-state outputs, observe their timestamps/range over repeated sessions; do not treat an output as intent or a command.
7. If any module requires an unlisted accessory, host, app, account, or measurement instrument, stop that module and record it as blocked.

## 11. Integration — local request only

No implementation code exists. If all prerequisites are already available, develop/test one stage at a time in the host environment:

1. device adapter and verified connection;
2. signal-quality/freshness gate;
3. baseline state display with no requests;
4. per-user calibration and fixed threshold/dwell/hysteresis;
5. a visible request requiring an independent human confirm/reject action;
6. fail-silent tests for disconnect, stale data, poor signal, timeout, and application restart.

Keep the RSLK disconnected and motion disabled. Do not create an actuator bridge until P01's exact platform is verified and a separate safe integration review is complete.

## 12. Debugging

Use [TROUBLESHOOTING.md](TROUBLESHOOTING.md). First save the exact error and record physical model, official app/SDK version, host OS, and non-sensitive connection status. Do not publish serial numbers, credentials, Developer Codes, raw biometric data, or personal identifiers. Never work around poor contact by disabling a quality check.

## 13. Final request-HMI test

Only after identity, access, consent/privacy, and signal-quality gates pass:

1. Run at least three separate sessions for one consenting participant; keep participant identity outside the repository.
2. Per session, collect a 10-minute no-request block and then 20 clearly marked request attempts plus 20 no-request intervals, in randomized/counterbalanced order where practical.
3. Display a request only after the calibrated candidate state is stable for the selected dwell and data are fresh/ready.
4. Have the participant/operator confirm or reject every displayed request; an unconfirmed request has no external effect.
5. Inject safe software-level stale/disconnect/quality-false conditions using supported test hooks; verify every request is suppressed/cleared.
6. Repeat across sessions and report each session, exclusions, and limitations separately. Do not connect a robot.

If the device cannot reliably provide a stable/request-worthy output, record that result and stop; do not add a more complex classifier to force a pass.

## 14. Performance testing

Record signal-ready availability, data gaps, event-to-display latency, request detection rate, false-request rate, fail-silent checks, and between-session variability. Initial planning targets and formulas are in [tests/README.md](../tests/README.md). Report raw counts with uncertainty and avoid claiming that a short pilot proves low risk. Store only approved, de-identified summary data in the repository.

## 15. Advanced improvements

Only consider changes tied to measured failure modes, such as longer calibration, adjusted dwell/hysteresis, or a repeat-session comparison. No ML, custom radio, cloud interface, new sensors, second wearable, or RSLK actuation is planned. Any future robot handoff requires verified P01 stock, a documented existing communications interface, explicit human confirmation, and an independent physical safety path.
