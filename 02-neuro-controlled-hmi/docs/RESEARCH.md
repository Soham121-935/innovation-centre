# Project 02 — Research Plan

**State:** Conditional desk research only. The inventory device has not been identified or tested. All device-specific methods are gated on a physical model match and already-available, authorized software. No data or results exist.

## 1. Research question

If the inventory band is confirmed as a device with a supported signal/state API, does a quality-gated threshold with persistence/hysteresis produce more stable, timely local HMI requests than a threshold-only baseline across repeated sessions, while keeping all outputs non-actuating and explicitly human-confirmed?

If the physical band does not match the candidate documentation or a compatible existing SDK cannot be accessed, this experiment is blocked; record the reason and proceed to the next project rather than adding hardware/software.

## 2. Existing approaches

- The official NeeuroOS manual says its SenzeBand 2 SDK can expose device/contact/link status and, depending on SDK/package, vendor-processed mental-state outputs and raw/filtered signals. These are statements about the vendor's documented SB-02 software, not about the inventory item until it is matched.
- The SenzeBand 2 catalogue describes a four-channel EEG device. It does not establish that its vendor state scores are intentional command classes, nor does it validate the performance of an HMI built in this lab.
- Padfield et al.'s review of endogenous EEG-based dynamic-device control describes the challenge of unstable decoder outputs and discusses shared-control/stabilization approaches [4]. This supports conservative gating as a research design choice; it does not transfer any accuracy claim to the candidate band.
- A threshold-only method is an appropriate baseline because it separates vendor data/state quality from the extra effect of persistence, hysteresis, and explicit request confirmation. No new machine-learning classifier is justified before the model, interface, and baseline signals are established.

## 3. Proposed approach

After hardware identity and SDK-access gates pass, use only documented vendor outputs. Establish a no-request baseline; calibrate a per-user candidate threshold using the exact vendor-supported method; compare a threshold-only request display with a signal-quality/freshness gate plus dwell, hysteresis, and cooldown. Both conditions remain display-only and require separate human confirmation. Invalid, stale, low-quality, disconnected, or ambiguous input produces no request.

The HMI evaluates interface stability and latency, not the ability to decode arbitrary thoughts or motor imagery. If the exact API does not expose usable status/state data, stop and record that limitation. Do not reverse-engineer radio traffic or add another sensor/host.

## 4. Hypothesis

Compared with a threshold-only display, adding documented signal-quality/freshness checks and a persistence/hysteresis gate will reduce false HMI requests during no-request intervals, while increasing request latency. This is testable only if the device model, SDK, and approved user study are available. The hypothesis may be rejected; no accuracy is assumed.

## 5. Experimental methodology

1. **Identity gate:** photograph/document (privately) device manufacturer/model/revision and match the manufacturer manual; record only non-sensitive model/version information in Git.
2. **Access gate:** verify an existing compatible host, approved vendor app/SDK, Developer Code/license (if required), and network authorization. If unavailable, stop; no purchase or substitute.
3. **Safety/privacy gate:** secure informed consent and applicable institutional ethics/privacy approval before collecting biometric signals. Use the band as directed and stop on discomfort or device damage.
4. **Baseline:** with a consenting participant seated, record three 10-minute no-request sessions using the supported interface. Prefer signal-quality/status and timestamps; store raw EEG/PPG only if essential, expressly consented, protected, and approved.
5. **Calibration:** follow the exact device/SDK procedure. Derive per-user thresholds only from separate calibration data; do not tune on the evaluation trials.
6. **Within-user comparison:** across at least three sessions, collect 20 prompted request attempts and 20 no-request epochs per session. Compare (A) threshold-only local requests and (B) freshness/quality-gated threshold with dwell/hysteresis/cooldown. Counterbalance condition order if the approved app permits; mark prompts with a supported event marker or an existing manual local event log.
7. **Confirmation:** require an explicit human confirm/reject action for every request. No request triggers movement, an external machine, or an RSLK.
8. **Fault checks:** exercise supported app-level stale/disconnect/poor-quality conditions. Confirm request suppression/clearing; do not alter band firmware or bypass vendor checks.
9. **Analysis:** report each session separately, all misses/false requests/aborted trials, data-quality availability, latency distribution, and exclusions. Do not treat repeated windows from one person as independent participants or claim population-level performance.

If the physical device, host, data interface, test consent, or safe procedures are unavailable, the associated experiment is not run. Record the blocker and continue in project order.

## 6. Variables

- **Independent:** request gate (threshold-only vs. quality/freshness + persistence/hysteresis); request/no-request task; session.
- **Dependent:** request detection rate, false-request rate, missed-request count, event-to-display latency, signal-ready availability, dropout rate, and human confirm/reject outcome.
- **Controlled:** same verified band and SDK version, participant, fit/placement per manufacturer guide, task prompts, environment, host, calibration procedure, dwell/cooldown, and session timing.
- **Recorded context:** connection status, vendor signal-quality flags, stale-data flags, interruptions, movement/artifact notes if approved, task event times, software versions, and manual interventions.

## 7. Metrics

Let `TP` be request displayed during a marked request trial, `FN` a missed request, `FP` a request during a no-request epoch, `N0` the duration of no-request observation in hours, and `t_i` the elapsed event-to-display latency.

- **Request detection rate (recall):** `TP / (TP + FN)`; report numerator/denominator by session.
- **False-request rate:** `FP / N0` requests per hour. Also report `FP / all no-request epochs`.
- **Latency:** `t_i = request-display time - prompt/event-marker time`; report median and 95th percentile, plus misses/timeouts.
- **Signal-ready availability:** valid, fresh, vendor-reported ready time / total session time, if that status exists in the matched SDK.
- **Data dropout:** number/duration of missing or stale intervals using the exact API's documented timestamp/cadence. Do not assume catalog sampling equals callback rate.
- **Fail-silent pass rate:** number of injected invalid/disconnect cases with request correctly suppressed or cleared / total cases; target 100% for defined cases.
- **Calibration/session variability:** report metric ranges across the three sessions for the same participant; do not infer general population behavior.

Initial pilot targets are in `../tests/README.md`; zero false requests in a short observation is not evidence of zero long-term risk.

## 8. Dataset requirements

No dataset exists. Preferred first dataset is an approved, pseudonymous event/summary log: random session ID, device/SDK model-version string, monotonic timestamps, event markers, connection/quality-ready status, data freshness, condition, request/confirm/reject event, latency, trial outcome, and exclusions. Do not store names, faces, raw audio/video, or serial numbers in the repository. Raw EEG/PPG is not required for the threshold/persistence comparison; if future work needs it, obtain separate consent/approval, minimize retention, restrict access, and keep it outside Git. Store only de-identified aggregates in the repository.

## 9. Expected contribution

If the gates pass, a reproducible engineering characterization of signal availability, request latency, false/missed prompts, and the effect of a simple quality/persistence gate for one verified band/software configuration. The contribution is a constrained HMI evaluation—not a new BCI decoder, clinical result, or reliable thought-to-motion system.

## 10. Possible limitations

- Device model, revision, accessories, and SDK access are all unverified.
- Vendor mental-state scores may not represent deliberate user intent; algorithm behavior is partly proprietary.
- EEG is susceptible to contact changes, eye/muscle artifacts, movement, and within-/between-session variation.
- One device and a small within-user pilot cannot establish generalizability or long-term false-command rates.
- SDK authentication, licensing, Internet access, and supported host/runtime versions may block a self-contained local app.
- Human-subject permission and sensitive-data controls may block testing.
- No robot integration, physical control, medical benefit, or safety performance is tested.

## 11. Future research

Only after measured limitations, identity/access, and approval are resolved:

- Repeat within-user sessions to quantify calibration drift and day-to-day variability.
- Compare dwell/hysteresis values against request latency and false/missed prompts.
- Study the contribution of vendor signal-quality flags to gating.
- Consider multi-user evaluation only with approved recruitment, power/sample-size rationale, and privacy review.
- Explore a human-confirmed RSLK request bridge only if P01 verifies an in-stock platform and a documented, already-available interface and physical safety path. This is not in the current experiment.

## References

1. Neeuro, [SenzeBand product page](https://www.neeuro.com/senzeband) — conditional candidate description.
2. Neeuro, [SenzeBand 2 Gold Edition product catalogue](https://www.neeuro.com/hubfs/20260414_SB2_Gold_Product%20Catalogue_EN.pdf?hsLang=en), 2026-04-14 — SB-02 manufacturer specifications; not attributed to lab hardware unless matched.
3. Neeuro, [NeeuroOS SenzeBand SDK developer manual](https://neeuroos.neeuro.com/manual/index.html) — documented SDK data/status and developer authentication requirements.
4. N. Padfield, K. Camilleri, T. Camilleri, S. Fabri, and M. Bugeja, “A Comprehensive Review of Endogenous EEG-Based BCIs for Dynamic Device Control,” *Sensors*, 22(15), 5802 (2022). [doi:10.3390/s22155802](https://doi.org/10.3390/s22155802).
5. [Supplied hardware inventory](../../HARDWARE_INVENTORY.md) — inventory label and count; no model confirmation.
