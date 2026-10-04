# Project 14 — OMAP-L138 Real-Time DSP Machine Fault Diagnosis (Acquisition Blocked)

**Status:** 🔴 Blocked — the inventory lists one “OMAP-L138 DSP Kit,” but exact LCDK/EVM variant, emulator, audio source/microphone, software host, and acquisition accessories are unknown.<br>
**Conditional reference:** TI OMAP-L138/C6748 LCDK supports audio line-in, line-out and mic-in; its guide states no onboard emulator and requires an external emulator.<br>
**Evidence:** SPRUIL2A only applies if the physical kit matches. No machine signal, microphone, code, DSP result, or fault data is available.

> Continue sequentially through the final project. Use no unlisted emulator, microphone, source, host computer, USB/audio cable, software, or machine. Record these blockers and a source-backed signal-processing design. No firmware/code.

## 1. Problem statement

Specify a real-time DSP study that could identify changes in a machine-like acoustic/vibration signal using a verified OMAP-L138 DSP kit. Current stock does not provide an identified signal source or external emulator, so the acquisition/implementation experiment is blocked.

## 2. Real-world application

Embedded spectral monitoring could flag persistent changes in motor or machinery sound/vibration for operator investigation. It is an advisory lab concept, not a certified protective relay or diagnosis of a specific failure mode.

## 3. Why the problem matters

Spectral features are sensitive to sensor placement, sample rate, windowing, machine speed/load, and noise. A classifier trained or tuned without known-good and known-fault signals can produce misleading results.

## 4. Project objectives

1. Identify the exact DSP board/kit variant, revision, and included acquisition/emulation accessories.
2. Check whether the documented audio ports and codec exist on that physical unit.
3. Identify a signal source/microphone/line-level source and acquisition path only from supplied inventory; none is confirmed.
4. If all required hardware/software is already present, compare simple time-domain and spectral features against documented baselines.
5. Keep all diagnosis advisory; no real machine or safety function is connected.

## 5. System requirements

- Exact kit variant must be identified. TI documents TMDSLCDK6748 and TMDSLCDK138; generic “OMAP-L138 DSP Kit” does not distinguish them.
- If the board is the LCDK described by SPRUIL2A, TI documents line-in, line-out, mic-in, onboard audio codec/MCASP and a 14-pin JTAG header; no onboard emulator—external emulator required.
- Microphone/audio source, cable, emulator, host PC, SDK/IDE, and power accessories must be physically available already; inventory does not establish them.
- Audio port presence does not mean a microphone or machine-signal source is included.
- Use only safe low-level signals and manufacturer input limits; no real machinery, destructive faults, or hazardous analog wiring.

## 6. Hardware used

| Inventory item | Quantity | P14 use | Status |
|---|---:|---|---|
| OMAP-L138 DSP Kit | 1 | Candidate DSP/codec platform | Exact kit variant/revision/accessories unknown |
| External JTAG emulator | 0 confirmed | Required by LCDK guide for development/debug if board matches | Not listed; no substitute assumed |
| Microphone, line-level source, machine/vibration sensor | 0 confirmed | Signal acquisition | Not listed; no source assumed |
| PC/CCS/SDK/audio cables | Not listed | Compile, debug, capture | Availability unknown |

## 7. Hardware not required

No motor, machine, external accelerometer, microphone, audio generator, oscilloscope, JTAG emulator, camera, display, internet service, or fault simulator is in scope unless explicitly found in the listed kit/accessory inventory. Do not presume these are included.

## 8. External components required

None planned. If no source/microphone and compatible emulator/software are already supplied, DSP signal testing is blocked. Do not purchase or borrow them.

## 9. Estimated additional cost

Planned external purchases: **$0**. Existing kit/accessory cost unknown. Missing emulator and acquisition source are blockers, not purchase recommendations.

## 10. System architecture

Conditional LCDK audio codec input → verified capture/sample-rate path → block framing/windowing → time/frequency features (RMS, crest factor, spectral energy/peaks) → baseline/persistence rule → local advisory state/record if supported. Present status: board variant, input signal, emulator, and software unresolved.

## 11. Connection diagram

See diagrams. TI guide labels mic-in/line-in/line-out but no external microphone/source cable is confirmed. No audio connection instructions are provided until board and signal source are identified.

## 12. Pin mapping

No pin map is verified. Audio ports are external connectors, and JTAG is a 14-pin header on the conditional LCDK. The exact board variant and emulator pinout are unknown; do not connect an emulator or analog source from a generic table.

## 13. Communication protocol

No network/remote telemetry. Local UART-to-USB is documented on LCDK but requires an existing host and cable; neither is established. No web/cloud upload.

## 14. Software architecture

Future after gates: codec/driver configuration → bounded DMA/sample blocks if supported by matching SDK → feature extraction → anomaly score/persistence → fault/unknown state → local output/log only where supported. No code or SDK is selected.

## 15. Algorithm

Start with sample validity, RMS/energy, crest factor, and FFT band-energy/peak features over documented windows. Compare to a measured operating baseline with a simple threshold/persistence rule. Do not claim fault classification without labelled, representative signals. No ML is justified at this stage.

## 16. Working principle

Acquire a known input at a documented sample rate; verify clipping, buffer freshness, and input range; compute repeatable features; compare with a baseline for the same operating condition; output `normal`, `warning`, or `unknown`. Missing/invalid signal is not a “healthy machine.”

## 17. Step-by-step build procedure

See [docs/TUTORIAL.md](docs/TUTORIAL.md): identify kit → inspect included media/accessories → verify emulator and matching tools → identify a safe in-stock audio source → review codec/port limits → stop if any gate fails. Continue to complete documentation; no hardware purchase/code.

## 18. Firmware setup

No firmware is written or built. Exact processor/board variant, emulator, SDK and signal path must be verified first.

## 19. Software setup

TI LCDK guide points to CCS/Processor SDK; availability, version/license, host computer and internet/download access are unconfirmed. Do not download/install. No software build.

## 20. Web interface setup

Not applicable. No web/cloud interface.

## 21. Testing procedure

No audio/DSP tests have run. Required gates: exact board, emulator, existing software, source/microphone, input cable, and safe capture setup. Future tests should begin with known non-hazardous signal, sample integrity/clipping, feature repeatability, then baseline/anomaly replay. No actual machine or fault test.

## 22. Expected output

Current deliverable is an architecture, blocker log, and test plan only. No spectrum, fault labels, diagnostic result, or timing benchmark is claimed.

## 23. Troubleshooting

See [docs/TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md). Stop on unknown input amplitude, connector, ground, power sequence, or JTAG wiring; follow only exact kit guide.

## 24. Performance metrics

Future metrics: sample rate and jitter, buffer overrun/dropout, clipping, feature repeatability, window processing latency, CPU/DSP utilization, anomaly detection delay, false alarms/misses against known labels, and output freshness. No numerical targets before board/source verification.

## 25. Limitations

Exact kit variant/accessories are unknown. Conditional LCDK has no onboard emulator. No microphone/source/machine/fault dataset or host software is established. Audio line/mic ports do not establish a usable external transducer. No reference signal or labeled truth is available; fault diagnosis cannot be validated.

## 26. Future improvements

Only with verified supplied kit/accessories and safe signal source: characterize input chain and baseline stability; compare time/frequency features. No additional microphone, emulator, machine, or ML/cloud system is proposed.

## 27. Research opportunities

For a known, safe signal source and verified LCDK, do simple spectral-band and time-domain persistence features detect repeatable changes with bounded latency while maintaining a low false-alarm rate? This remains blocked pending acquisition/emulator/software.

## 28. References

- TI, [OMAP-L138/C6748 LCDK User Guide SPRUIL2A](https://www.ti.com/lit/ug/spruil2a/spruil2a.pdf) — variants, audio ports, included kit contents, and no onboard emulator; conditional match.
- TI, [TMS320C6748 datasheet](https://www.ti.com/lit/ds/symlink/tms320c6748.pdf) — only if that variant/processor is physically confirmed.
- TI, [OMAP-L138 product page](https://www.ti.com/product/OMAP-L138) — only if the ARM+DSP variant matches.
- [Supplied hardware inventory](../HARDWARE_INVENTORY.md).

## 29. License

See root [LICENSE](../LICENSE); repository licensing pending. No vendor code, firmware, or audio data included.

## Reproducibility checklist

- [ ] Exact OMAP-L138/C6748 kit variant/revision recorded
- [ ] External emulator and matching software/host confirmed already in stock
- [ ] Audio input/source/microphone/cable identified and safe
- [ ] Codec/sample rate/input range sourced from exact documents
- [ ] No actual machine/fault or safety-control claim
- [ ] Feature/test metrics and baseline defined before data collection
- [ ] No code, spectrum, data, or result claimed before verification
