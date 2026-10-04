# Project 07 — Sub-GHz Industrial Asset Tracking and Telemetry (Two-Node Presence Scope)

**Status:** 🟡 In Development — strong conditional two-node host match; RF emissions blocked until regional authorization and board identity are confirmed.<br>
**Inventory:** 2 BOOSTXL-CC1125 modules; 4 MSP430F5529 LaunchPads (P07 proposes 2 sequential host reservations, conditional on exact model/condition).<br>
**Evidence:** TI SWRA520 documents BOOSTXL-CC1125 and MSP-EXP430F5529 compatibility. No radios have been powered or transmitted.

> The two-node inventory supports, at most, a point-to-point presence/link-quality study—not 2D/3D asset localization. TI documents the integrated PCB antenna for approximately 868–870 MHz (Europe) and 902–928 MHz (US); those example bands are not automatically permitted locally. Do not emit RF until qualified approval. No extra anchors, gateways, location tags, antenna, or software may be assumed. Continue sequentially to P08 if blocked.

## 1. Problem statement

Evaluate a low-rate CC1125 link between two verified in-stock nodes for binary “link present / link lost” status and RSSI variability. RSSI does not provide reliable distance or position by itself.

## 2. Real-world application

A supervised, non-critical lab asset-presence concept may report whether one node can hear another under a permitted test profile. It is not indoor positioning, geofencing, a certified asset tracker, or a safety/emergency link.

## 3. Why the problem matters

A radio's packet reception and RSSI fluctuate with environment, orientation, interference, antenna placement, and regional configuration. Distinguishing connectivity from physical location prevents misleading claims.

## 4. Project objectives

1. Confirm both boards are BOOSTXL-CC1125, their antenna/revision/jumper condition, and two compatible MSP-EXP430F5529 hosts from listed stock.
2. Verify an authorized local frequency/power/antenna profile before any RF activity.
3. If all gates pass, test numbered packets, packet delivery, RSSI variability, stale status, and link recovery between exactly two nodes.
4. Report only binary link presence/quality; do not infer distance, direction, coordinates, or multi-anchor location.
5. Record software/host availability and all blockers; no code yet.

## 5. System requirements

- TI documents BOOSTXL-CC1125 with MSP-EXP430F5529 or MSP-EXP430G2553; two MSP430F5529 LaunchPads are proposed from the four listed, conditional on exact model and release.
- Physical module and antenna must match the TI document.
- Board material describes integrated trace antenna for approximately US 902–928 MHz and Europe 868–870 MHz; those examples do not establish a legal Pune/India profile.
- RF emissions require approval from a qualified supervisor under applicable local requirements. No testing until authorized.
- No additional anchors/tags, test instruments, PC, USB cable, software or cloud service is assumed.
- Never use the link for emergency or protective functions.

## 6. Hardware used

| Item | Quantity | Proposed role | Status |
|---|---:|---|---|
| BOOSTXL-CC1125 | 2 of 2 | Point-to-point transceiver nodes | Exact revision/condition/jumper/antenna to inspect |
| MSP430F5529 LaunchPad | 2 of 4 | Host, if exact board matches MSP-EXP430F5529 | Listed model family; revision/accessories unknown; P09/P12 may reuse hosts sequentially |
| PC/USB/software | None listed | Not assumed; SmartRF Studio/host tools require existing access | Availability unknown |

## 7. Hardware not required

No third anchor, additional tag, RF amplifier/antenna, USB radio dongle, gateway, network server, cellular or GPS module, survey equipment, or other project's board is required/assumed.

## 8. External components required

None planned. If existing compatible hosts, a lawful RF profile, or existing software/USB setup are unavailable, the two-node experiment is blocked; do not acquire replacements.

## 9. Estimated additional cost

Planned external purchases: **$0**. Existing stock cost is unknown. Regulatory approval, software, and test setup are conditions, not purchases in this plan.

## 10. System architecture

Conditional: host A + BOOSTXL-CC1125 → numbered non-critical status packets → host B + matching module → sequence/freshness/CRC/ack validation → local link state and RSSI log. Reverse direction only if the verified protocol supports it. No gateway, position solver, cloud, or remote alarm path.

## 11. Connection diagram

See diagrams. TI SWRA520 documents a LaunchPad connection and separate SmartRF Studio USB configuration. Do not connect or move jumpers until the exact board matches the guide.

## 12. Pin mapping

No pin map is asserted. Use SWRA520 plus the exact MSP-EXP430F5529 schematic and physical board revision. The radio IC's SPI interface does not prove BoosterPack-to-host pin assignment. Do not connect to another LaunchPad by analogy.

## 13. Communication protocol

No RF channel/modulation/region profile is selected. Application packet proposal: node ID, monotonic sequence, bounded status, age, and integrity check; acknowledgements/timeouts only if supported by verified device configuration. No Sigfox service is assumed; TI notes its regional example requires a valid license.

## 14. Software architecture

After all gates: verified board profile → CC1125 configuration from approved profile → bounded packet/framing → receiver validation → link-state timeout/RSSI logging. TI mentions SmartRF Studio; its availability and licensing/install access are unknown. No code is written.

## 15. Algorithm

A single receiver can classify “recent valid packets received” versus “timed out” and report RSSI distribution. Use a timeout/hysteresis only after observed packet timing. RSSI is a link metric, not a distance estimator. No triangulation, trilateration, ML, or location claim.

## 16. Working principle

Each transmission has a sequence number and age; the receiver verifies integrity and freshness, records RSSI if exposed by the confirmed stack, and reports recent link state. Packet silence becomes unknown/lost communication—not proof that the asset moved away.

## 17. Step-by-step build procedure

See [docs/TUTORIAL.md](docs/TUTORIAL.md): identify both modules/hosts → verify exact jumper/antenna configuration → approve regional RF profile → verify existing tools → no-emission checks → authorized two-node test. Stop and continue to P08 if any gate fails.

## 18. Firmware setup

No firmware is created or flashed. Do not use example settings until board identity, legal RF profile, and host image are approved.

## 19. Software setup

No downloads/installs. Use only already supplied, compatible TI tools/SDK. SmartRF Studio requires computer/USB access not established by inventory; absence blocks setup.

## 20. Web interface setup

Not applicable. No web or cloud dashboard.

## 21. Testing procedure

No RF tests have run. After approval: transmit non-critical packets under controlled local conditions; log sequence, time, valid reception, RSSI/LQI if documented, retries, loss, and timeout/recovery. Do not intentionally interfere with other users or increase power.

## 22. Expected output

If permitted and supported: local timestamped link-up/link-lost and packet/RSSI statistics. No map, range, or positioning result is expected.

## 23. Troubleshooting

See [docs/TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md). Stop RF if band/antenna/profile is uncertain, interference occurs, or hardware is hot/damaged.

## 24. Performance metrics

Proposed: packet-delivery ratio, missed sequence count, valid-packet age, reconnect latency, RSSI distribution/variance, false link-loss and false link-present rates. No RSSI-to-distance conversion or coverage claim.

## 25. Limitations

Two nodes are insufficient for multilateration. RSSI is highly environment-dependent. Board frequency/antenna is designed for described regional bands; legal local use is unresolved. Software, PC, cables, and test measurement tools are not inventoried. No Sigfox license/service or cloud is included.

## 26. Future improvements

Only using listed stock: repeat an approved two-node test across already available lab conditions and document environmental effects. Do not add anchors or gateways.

## 27. Research opportunities

Can a sequence/freshness-aware link-state detector reduce false “present” indications compared with packet reception alone under an authorized test configuration? This is not a location-estimation experiment.

## 28. References

- TI, [BOOSTXL-CC1125 application report SWRA520](https://www.ti.com/lit/an/swra520/swra520.pdf) — antenna bands, LaunchPad hosts, interfaces, current/power/jumper guidance; conditional match.
- TI, [CC1125 datasheet](https://www.ti.com/lit/ds/symlink/cc1125.pdf) — IC features/rating, not regional authorization.
- TI, [MSP-EXP430F5529LP product/user guide entry](https://www.ti.com/tool/MSP-EXP430F5529LP) — verify physical board revision.
- [Supplied inventory](../HARDWARE_INVENTORY.md).

## 29. License

Repository license is pending; see root [LICENSE](../LICENSE). Respect TI tool, firmware, and Sigfox license terms.

## Reproducibility checklist

- [ ] Two BOOSTXL-CC1125 units/antennas and two compatible hosts verified
- [ ] Local RF approval/profile confirmed before any transmission
- [ ] Existing software, host, cables, and jumpers verified
- [ ] No extra nodes or position claims
- [ ] Packet, freshness, RSSI/loss/recovery metrics recorded
- [ ] No emergency or safety use
