# Project 04 — Long-Range Industrial Emergency Wireless Network

**Status:** 🟡 In Development — conditional radio research; compatible host, exact BoosterPack model, and lawful RF profile unverified.<br>
**Inventory hardware:** “CC110L Booster Pack” (2 listed); no exact SKU/revision, host LaunchPad, antenna, or included firmware is recorded.<br>
**Evidence:** TI CC110L / 430BOOST-CC110L documentation is a candidate reference only. No radio link or emergency function has been tested.

> Proceeded sequentially after P03’s RSLK/sensor identity blocker. Use only listed inventory. If exact radios cannot be hosted by existing listed boards or their operating frequency is not lawful in the test region, record the blocker and continue to P05. Do not buy LaunchPads, antennas, tools, software, or add-on parts. This project is a non-critical educational telemetry demo—not an emergency/safety system.

## 1. Problem statement

Assess whether the two listed CC110L BoosterPack items can support a local, low-rate alert/telemetry link using only compatible host hardware already in the inventory. The “CC110L Booster Pack” wording does not identify the board or complete node kit.

## 2. Real-world application

A telemetry link could convey status between two stationary lab nodes, analogous to an industrial alert channel. The demo must never carry real emergency, personnel-protection, machine-stop, or fire-alarm traffic.

## 3. Why the problem matters

Sub-GHz links can have packet loss, interference, latency, and regional spectrum constraints. An alert system must expose delivery failure and cannot claim reliability from a single successful packet.

## 4. Project objectives

1. Identify the exact BoosterPack SKU, radio module/revision, antenna, and included microcontrollers/accessories.
2. Verify a compatible host from listed LaunchPads; TI’s 430BOOST-CC110L candidate guide describes MSP430G2 LaunchPads, which are not in the supplied inventory.
3. Verify a legal regional frequency/channel, power, antenna, and firmware profile before any transmission.
4. If all gates pass, evaluate packet delivery, latency, RSSI variability, and recovery between exactly two in-stock nodes.
5. Label all output non-critical and report no safety/emergency certification.

## 5. System requirements

- Physical model and host-interface match official documentation.
- No external LaunchPad, programmer, antenna, USB adapter, PC, router, network, software, or power accessory is assumed.
- A documented, permitted local RF configuration must be selected before transmitting; US/EU example bands are not automatically lawful in India.
- Two verified nodes and their compatible hosts must exist in supplied stock; otherwise the radio-link MVP is blocked.
- Packet loss, timeout, duplicate, and stale-alert behavior must be reported; no message is treated as safety-rated.

## 6. Hardware used

| Inventory item | Quantity | Planned use | Verification |
|---|---:|---|---|
| CC110L Booster Pack | 2 | Candidate two-node link only if exact models and hosts match | SKU, board revision, RF module, antenna, included MCU/accessories unknown |
| Compatible host LaunchPad | 0 listed by CC110L name | Must be selected from another listed board only if official docs confirm electrical/software compatibility | No compatible host confirmed; MSP430G2 LaunchPad is not listed |

### Conditional 430BOOST-CC110L reference

TI’s legacy product material describes an Anaren AIR / CC110L BoosterPack candidate with integrated antenna and example 868–870 MHz (Europe) / 902–928 MHz (US) configurations, and identifies MSP430 LaunchPad support. These details apply only if the physical inventory item matches. They do not establish a legal profile for Pune/India or that host boards are present.

## 7. Hardware not required

No additional host LaunchPad, RF adapter, sensor node, external antenna, power amplifier, repeater, cloud service, cellular modem, gateway, or safety relay is in scope.

## 8. External components required

None planned. If the physical kit requires an unlisted compatible host or accessory, the project is blocked; do not substitute another LaunchPad without manufacturer evidence or purchase one.

## 9. Estimated additional cost

**Planned external purchases: $0.** Existing kit cost is unknown. A missing host, software package, or region-compliant radio configuration is a blocker, not a purchase proposal.

## 10. System architecture

Conditional two-node point-to-point packet link: verified CC110L node A ↔ verified CC110L node B. Each node requires a compatible, already-listed host and supported firmware. Use sequence number, node ID, message type, payload length, freshness timestamp, and integrity checking only if the exact device/software supports it. No gateway, cloud, location, or emergency-control path is assumed.

## 11. Connection diagram

See the conditional diagrams. Radio/host connections remain undefined until the exact module and compatible host are physically identified. Do not connect from an assumed BoosterPack pinout.

## 12. Pin mapping

Not verified. The inventory lacks board SKU and host. No GPIO/SPI/IRQ pin mapping is valid until both revisions and the official schematic are matched. Do not apply an MSP430G2 mapping to TIVA/MSP432/MSP430F5529 boards by analogy.

## 13. Communication protocol

Radio modulation/channel/packet settings remain unselected until hardware identity and local RF rules pass. Proposed application payload is a small status/alert code, node ID, sequence number, and age; add acknowledgement/retry only if supported by confirmed firmware. No deployment protocol is defined.

## 14. Software architecture

After gates: radio driver/configuration → bounded packet encoder/decoder → freshness/sequence/CRC validation → acknowledgement/timeout manager → local status indicators. No code is written; required TI/Anaren software is not established as supplied.

## 15. Algorithm

Use a minimal periodic status message and explicit acknowledgement/timeout. Report a lost/stale alert as lost—never silently present it as delivered. Avoid mesh routing, encryption claims, or adaptive algorithms until the exact stack and requirements are known.

## 16. Working principle

The transmitter encodes a bounded status payload; the receiver validates node identity, integrity, sequence, and freshness, then acknowledges if the supported protocol permits. A failed or late packet is a communication failure, not a positive alert.

## 17. Step-by-step build procedure

See [docs/TUTORIAL.md](docs/TUTORIAL.md): identify hardware → verify compatible listed hosts → confirm legal RF profile before emission → check existing software/access → only then run the vendor no-critical-load demo. Stop at any missing host, unapproved frequency, or unprovided tool.

## 18. Firmware setup

No firmware has been created. Do not flash the radio or host until exact model, host, image, and official procedure are verified. No production/alert firmware is in scope.

## 19. Software setup

No software is installed or selected. Use only a compatible package already provided. If TI/Anaren tools or a host SDK are missing, record the blocker and continue to P05.

## 20. Web interface setup

Not applicable. No web/cloud dashboard is planned.

## 21. Testing procedure

No RF test has been run. If gates pass: test two nodes in a controlled, legally compliant environment; send numbered non-critical packets; log transmit/receive/ack timestamps, RSSI/LQI when available, retries, duplicates, loss, and timeouts. Never connect to real alarms or machinery.

## 22. Expected output

A local per-node packet log and measured link statistics only if supported hardware/software are verified. No coverage/range or emergency reliability is claimed.

## 23. Troubleshooting

See [docs/TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md). Stop RF transmission on wrong band/antenna, uncertain regulatory status, overheating, or repeated failures. Do not increase transmit power or add an antenna.

## 24. Performance metrics

Proposed: packet-delivery ratio, acknowledgement success, one-way/round-trip latency, RSSI/LQI distribution, retry count, duplicate/stale rejection, and recovery after an induced safe link interruption. Set pass thresholds only after a lawful, verified baseline.

## 25. Limitations

Exact module/kit/host and RF profile are unknown. The candidate frequencies may not match regional rules. Two nodes cannot establish broad site coverage or robust emergency availability. No redundant power, gateway, supervised safety link, certification, or real emergency test is provided.

## 26. Future improvements

Only with listed, verified hardware and lawful configurations: repeat tests in existing lab locations, quantify interference sensitivity, and evaluate protocol fault behavior. No new nodes/repeaters/antennas or cloud service.

## 27. Research opportunities

Can packet-delivery and latency distributions under a permitted test profile support a bounded non-critical telemetry use case? Compare only verified configurations and do not generalize to emergency systems.

## 28. References

- TI, [CC110L datasheet](https://www.ti.com/lit/ds/symlink/cc110l.pdf) — radio IC limits/features, not a board pin map.
- TI, [CC110L product page](https://www.ti.com/product/CC110L) — datasheet and legacy BoosterPack quick-start resource.
- TI, [430BOOST-CC110L quick-start/documentation entry point](https://www.ti.com/product/CC110L) — conditional candidate; match physical SKU before use.
- TI, [RF expansion adapter product page](https://www.ti.com/tool/BOOST-CCEMADAPTER) — not in inventory; cited only to document that adapters are out of scope.
- [Supplied hardware inventory](../HARDWARE_INVENTORY.md).

## 29. License

Top-level [LICENSE](../LICENSE) decision is pending. Do not redistribute vendor firmware, drivers, or manuals outside their terms.

## Reproducibility checklist

- [ ] Physical radio/BoosterPack SKU, board revision, antenna, and included MCU recorded
- [ ] Compatible listed host identified from official documentation
- [ ] Region/channel/power/antenna profile approved before RF emission
- [ ] No unlisted host, antenna, or software assumed
- [ ] Test is non-critical and isolated from safety systems
- [ ] Packet/latency/loss metrics and versions defined
- [ ] No firmware or results claimed before verification
