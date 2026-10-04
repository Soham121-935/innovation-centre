# Project 09 — CC3100 Embedded Industrial Web/Data Acquisition System (Local, Digital MVP)

**Status:** 🟡 In Development — two listed CC3100 BoosterPacks have a documented MSP430F5529 host candidate; exact board model, SDK/access, host/cable condition, and browser client are unresolved.<br>
**Inventory:** 2 SimpleLink Wi-Fi CC3100 BoosterPacks; 4 MSP430F5529 LaunchPads (candidate hosts; share sequentially with P07/P12).<br>
**Evidence:** TI documentation describes the CC3100 as a network processor and supports CC3100BOOST examples with MSP-EXP430F5529LP. No network or web page has been run.

> Use two listed CC3100 nodes to avoid assuming a router/client for protocol tests. The proposed data source is only a documented board user input if the physical booster revision provides one; no generic sensor set or external sensor is assumed. A browser-facing web dashboard remains blocked because no browser client/computer is listed. No downloads, purchases, or outside network.

## 1. Problem statement

Design a local Wi-Fi web/DAQ path that can acquire a small, verified digital input and serve timestamped/status data over an isolated, two-node CC3100 test network using only listed boards.

## 2. Real-world application

A local web endpoint can expose low-rate lab status without cloud connectivity. The current inventory does not identify a physical sensor for P09; if the exact BoosterPack's supported user input is confirmed, the MVP can report input events only. This is not industrial sensor monitoring or production IoT.

## 3. Why the problem matters

A web endpoint must distinguish valid, stale, and unavailable data and remain usable without internet. Networked acquisition also introduces power, association, request-timeout, and data-integrity failure modes.

## 4. Project objectives

1. Identify whether each item is CC3100BOOST, CC3100MODBOOST, or another exact revision.
2. Verify TI-supported MSP430F5529 host compatibility and reserve two boards sequentially if required.
3. Use the CC3100's documented AP/station capabilities to test a local request/response path without a router, if existing software supports it.
4. Use only an on-board input confirmed on the physical revision; otherwise document that sensor acquisition is blocked.
5. Defer browser UI until a browser host already in the supplied environment is confirmed; no phone/PC is assumed or purchased.

## 5. System requirements

- Exact BoosterPack/host schematics and software version must match.
- TI CC3100BOOST documentation supports MSP-EXP430F5529LP examples; this is a candidate only if the physical module matches.
- CC3100 supports station/AP/Wi-Fi Direct modes at IC level; an application/server requires an existing compatible host SDK/application.
- CC3100BOOST can draw up to 400 mA peak from 3.3 V per TI hardware guide; correct power/jumper/accessory setup must be verified, no unlisted supply/cable assumed.
- Two CC3100 units and two compatible listed hosts may be used sequentially from stock. No router or external web client is assumed for internal link tests.
- No sensor values, network service, or cloud connectivity are assumed; no data leaves the local test setup.

## 6. Hardware used

| Inventory item | Quantity | P09 plan | Status |
|---|---:|---|---|
| SimpleLink Wi-Fi CC3100 Booster Pack | 2 of 2 | One AP/server candidate + one station/client candidate | Exact QFN/module SKU/revision unknown |
| MSP430F5529 LaunchPad | Up to 2 of 4 | One host per CC3100 if physical model matches TI support | Listed; share sequentially with P07 and P12 |
| User button/input | 1 only if documented on exact board | Event source for minimal acquisition test | CC3100BOOST guide lists buttons, but exact inventory board unknown |
| PC/browser/router/sensors | 0 confirmed | Not assumed | Browser/web UI and external sensor acquisition blocked |

## 7. Hardware not required

No Wi-Fi router, internet, phone/browser, cloud server, external sensor, generic sensor-set component, CC31XXEMUBOOST, wireless gateway, or display is in scope. CC31XXEMUBOOST is specifically required for some advanced flashing/debug paths; it is not listed, so those paths are excluded.

## 8. External components required

None planned. If exact hosts, adequate documented power path, compatible software, cable, or browser client is missing, that step remains blocked. Do not use another project's unverified sensors or obtain an accessory.

## 9. Estimated additional cost

Planned purchases: **$0**. Missing host tools/USB/browser/sensors are blockers and are not priced as recommendations.

## 10. System architecture

Conditional local network: MSP430F5529 + CC3100 node A in AP mode → local HTTP endpoint serving status/input data → MSP430F5529 + CC3100 node B as client performs a request/response and checks age/content. A browser UI is an optional later validation stage only if a browser-capable client is confirmed in stock. No internet/cloud.

## 11. Connection diagram

See diagrams. Use only the exact TI board/host combination and the correct power-selection jumper after matching physical revision. CC3100 BoosterPack variants do not share an assumed pin map.

## 12. Pin mapping

No lab pin map is verified. SWRU371B describes CC3100BOOST outer/inner connector signals; those tables apply only to that physical revision. CC3100MODBOOST has separate documentation. Host-side MCU pin assignments require the exact MSP430F5529 LaunchPad guide and board revision.

## 13. Communication protocol

No Wi-Fi SSID/security/channel or HTTP route is configured. Candidate private test: isolated AP, local HTTP GET of a small JSON/text response with sequence, input state, age, and validity. Security and country/channel settings must follow the installed TI stack and local lab approval. No credentials or internet access are assumed.

## 14. Software architecture

After gates: host input sampling → CC3100 network processor API → local AP/HTTP server → second node request/response parser → freshness/data-integrity check → status indicator only if verified. TIs SDK is not confirmed as installed; CC31XXEMUBOOST for advanced debug is unavailable/unlisted.

## 15. Algorithm

Sample only the documented on-board user input, debounce it using measured switch behavior, attach monotonic sequence/time/validity, and return a bounded response. The client rejects duplicate/stale responses. No external sensor fusion, analytics, or ML.

## 16. Working principle

The local AP node hosts status data and serves only a fresh response. The second listed node connects as a station, requests data, validates sequence/age, and indicates success/failure if the verified board supports an LED output. A missing reply is “unavailable,” not zero or safe state.

## 17. Step-by-step build procedure

See [docs/TUTORIAL.md](docs/TUTORIAL.md): identify board variant → verify F5529 support and two sequential hosts → confirm power and USB/tool availability → confirm AP test approval → design local request schema → internal two-node link test. Do not configure a browser UI or external sensor if absent.

## 18. Firmware setup

No host or CC3100 firmware is written. The CC3100 BoosterPack's loaded firmware state/revision must be inspected. Do not update/flash without the exact board and TI's required tool; CC31XXEMUBOOST is not in stock.

## 19. Software setup

TI documentation points to CC3100 SDK and host examples, but the inventory does not show software/computer. No downloads, installs, online service, or external repositories are assumed. Missing SDK blocks build.

## 20. Web interface setup

No browser UI has been created or tested. Local HTTP design only. A browser-capable client is not listed; the second CC3100 node may validate data transport but is not a substitute for a browser-based visual UI.

## 21. Testing procedure

No tests have run. Proposed: identity/power gate; isolated AP/station association; one supported digital input event; local request/response; stale/duplicate/timeout handling; power stability under Wi-Fi peak. Browser rendering and sensor calibration are explicitly blocked.

## 22. Expected output

If all gates pass: a small local status response and client-side valid/unavailable indicator/log. No sample response, browser screenshot, sensor reading, or network result is supplied.

## 23. Troubleshooting

See [docs/TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md). Do not change power jumpers or supply voltage based on generic documentation; stop if current/heat/power behavior is unexpected.

## 24. Performance metrics

Proposed: association success/time, request success ratio, median/p95 response delay, stale/duplicate rejection, input-to-response latency, client timeout, and supply stability. No internet throughput or sensor accuracy metric.

## 25. Limitations

Exact CC3100 BoosterPack variant, host code/toolchain, USB/computer, power accessories, and browser client are unknown. No physical analog/digital sensor is confirmed beyond conditional board controls. The project does not demonstrate cloud IoT, internet data, secure production service, or calibrated DAQ.

## 26. Future improvements

Only with existing listed hardware/software: verify HTTP response from an existing browser and add a documented listed sensor only after the sensor set is identified and electrical compatibility confirmed. No server/cloud/router or sensors may be acquired.

## 27. Research opportunities

Can a local HTTP request/response layer preserve input freshness and report outages reliably when isolated from the internet? This remains blocked until board/software/power and input identity are verified.

## 28. References

- TI, [CC3100BOOST product page](https://www.ti.com/tool/CC3100BOOST) — host examples, hardware features, and advanced emulator requirements; conditional physical match.
- TI, [CC3100 BoosterPack Hardware User Guide SWRU371B](https://www.ti.com/lit/ug/swru371b/swru371b.pdf) — connector/jumper/power; apply only to matching CC3100BOOST revision.
- TI, [CC3100/CC3200 SimpleLink Wi-Fi User Guide SWRU368C](https://www.ti.com/lit/ug/swru368c/swru368c.pdf) — station/AP roles; stack/app still required.
- TI, [CC3100 datasheet](https://www.ti.com/lit/ds/symlink/cc3100.pdf).
- [Supplied inventory](../HARDWARE_INVENTORY.md).

## 29. License

See root [LICENSE](../LICENSE); project licensing pending. Follow TI SDK/firmware and local network policy terms.

## Reproducibility checklist

- [ ] Exact CC3100 BoosterPack variant/revision and two hosts recorded
- [ ] Matching guide/pinout and peak-current power path verified
- [ ] Existing SDK/toolchain/cables confirmed, not downloaded
- [ ] No external browser/router/sensor/cloud assumed
- [ ] Input, request schema, freshness, and latency metrics defined
- [ ] No test results or web UI claimed until verified
