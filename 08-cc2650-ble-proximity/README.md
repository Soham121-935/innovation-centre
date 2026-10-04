# Project 08 — BLE Industrial Proximity and Safety System (Informational, Non-Safety MVP)

**Status:** 🟡 In Development — inventory contains two CC2650 BoosterPacks and two MSP432P401R LaunchPads; exact revisions/software and lawful test profile remain unverified.<br>
**Hardware candidate:** TI BOOSTXL-CC2650MA + MSP-EXP432P401R, one per node. TI requires an MSP432 LaunchPad for the documented host examples.<br>
**Evidence:** TI product page and SWRU486 guide. No radio has been operated; no HMI or measurements exist.

> Inventory-only scope. The two MSP432 boards are reserved together for P08, then released; P11 may use one later. P09 uses MSP430F5529 hosts instead. No smartphone, computer, router, display, network, software download, or extra third node is assumed. This is an informational HMI—not a safety control, E-stop, personnel-protection, or certified proximity system. Continue to P09 if blockers remain.

## 1. Problem statement

Assess whether two verified BLE nodes can convey a fresh, small operator/status message and expose link-loss state through existing board indicators, without an external phone or gateway.

## 2. Real-world application

A local bench HMI concept could show a peer's status and age. The status must be considered unknown when stale or disconnected; RSSI is a rough radio metric and must never be used as a safety distance.

## 3. Why the problem matters

Wireless HMI links can disconnect or become delayed. Explicit freshness and loss indication are essential, particularly because this demo is not qualified for any safety function.

## 4. Project objectives

1. Match both modules to BOOSTXL-CC2650MA and hosts to MSP-EXP432P401R.
2. Verify existing compatible TI host code/SDK and a locally approved BLE test setup; no downloads or purchases.
3. If gates pass, create a two-node BLE status exchange with sequence/freshness handling and local LED/button interaction only if supported by verified hardware/software.
4. Measure message latency, loss, timeout, recovery, and RSSI stability; no distance estimate or safety-zone threshold.
5. Release both MSP432 hosts before the later P11 checkout.

## 5. System requirements

- TI product page states the module is intended to plug into an MSP432 LaunchPad, is preprogrammed with a wireless network processor, exposes a UART interface, and has a JTAG development connection. Physical modules must match.
- Two MSP432P401R LaunchPads are listed; their exact revisions/accessories and release schedule must be confirmed.
- No phone or PC is assumed as the peer/display; two listed nodes are the entire test system.
- BLE use and test procedure must be approved under applicable local requirements; product certification statements for other regions do not establish local authorization.
- Missing host SDK/toolchain or USB host access blocks firmware work; no downloads/install.
- No safety action, robot motion, E-stop, door lock, or personnel protection.

## 6. Hardware used

| Item | Quantity | P08 allocation | Status |
|---|---:|---|---|
| BOOSTXL-CC2650MA | 2 of 2 | One per node | Exact revision/condition and included cable/sample inventory unknown |
| MSP432P401R LaunchPad | 2 of 2 | One host per node, sequential P08 reservation | Listed; exact board revision/USB accessories unknown; P11 may reuse one after P08 releases both |
| Smart device / PC / BLE gateway | 0 | None assumed | Not listed |

TI product page describes each kit as including one BoosterPack, a 10-pin JTAG debug cable, one additional CC2650 module sample, and software examples for an MSP432 application processor. Verify physical box contents; the extra module sample is not counted as a second BoosterPack node.

## 7. Hardware not required

No smartphone, third LaunchPad, CC2650 LaunchPad, router, cloud, external display, extra BLE tag/anchor, or RF module is in scope.

## 8. External components required

None planned. A matching host software package and USB/dev setup are required only if already provided; otherwise the build and tests are blocked.

## 9. Estimated additional cost

Planned external purchases: **$0**. If host SDK, computer, cable, or test environment is absent, do not obtain it; record the blocker.

## 10. System architecture

Node A: MSP432 application host ⇄ UART/HCI or TI-supported interface ⇄ CC2650 BLE module. Node B uses the same listed module/host pair. One node advertises/serves a small status characteristic; the other connects/reads/subscribes only if the verified host example supports this role. Local host-board LED indicates fresh/stale status if its exact guide supports it. No external interface.

## 11. Connection diagram

See diagrams. Physical BoosterPack insertion and UART/JTAG connections are conditional on exact module/host match and SWRU486. Do not infer signal mapping.

## 12. Pin mapping

SWRU486 lists BoosterPack signals (e.g., 3.3 V, MRDY/SRDY, TXD/RXD, reset, SPI) for the module. This is not the MSP432 MCU pin map; do not wire from a generic table. Check exact board revisions and official host schematic before connection/debug.

## 13. Communication protocol

BLE GATT/service, roles, characteristics, and update rates are not selected until existing supported examples/SDK are confirmed. Proposed payload: node/status ID, sequence, and age; reject stale or duplicate status. Do not assume a particular service or stack version.

## 14. Software architecture

After gates: MSP432 host app → TI-supported UART/HCI/SNP host library → CC2650 network processor/verified BLE stack → peer host app → freshness/timeout logic → local board indicator. TI host code is downloadable in TI documentation but not confirmed as supplied. No code exists.

## 15. Algorithm

Use a simple periodic status event, sequence/freshness validation, and timeout with a visible unknown state. If RSSI is available, record it for link characterization only; do not map it to meters or a safe zone. No ML or extra complexity.

## 16. Working principle

Node A sends or exposes current status; Node B verifies the message sequence and age and reports a fresh status while valid. Timeout, disconnect, or invalid message drives the display to “unknown/disconnected,” never a false positive. No actuation occurs.

## 17. Step-by-step build procedure

See [docs/TUTORIAL.md](docs/TUTORIAL.md): identify boards → reserve two MSP432s sequentially → verify physical accessories/software → review exact UART/HCI mapping → approve BLE test → define bench-only message → run non-safety link tests. Stop if tools are not already available.

## 18. Firmware setup

No firmware is written. Do not flash modules or MSP432 LaunchPads until exact model, preloaded firmware status, supported SDK, and manufacturer procedure are confirmed.

## 19. Software setup

The product page links host examples for MSP432. The inventory does not establish SDK/toolchain/computer/USB access. No download or install is permitted in this inventory-only scope.

## 20. Web interface setup

Not applicable. No smartphone/web/cloud interface is assumed.

## 21. Testing procedure

No BLE tests have run. If approved and supported: test advertising/connection, periodic status exchange, stale/duplicate handling, timeout, reconnect, and local indication. Use only two nodes; never evaluate safe separation or human protection.

## 22. Expected output

A local indicator/log showing fresh peer status or explicit disconnected/unknown, plus packet timing/loss/RSSI measurements if supported. No position, range, or safety result.

## 23. Troubleshooting

See [docs/TROUBLESHOOTING.md](docs/TROUBLESHOOTING.md); stop on incorrect power, unexpected behavior, RF interference, or unsupported firmware. Do not replace host boards by analogy.

## 24. Performance metrics

Proposed: connection success, status delivery ratio, median/p95 end-to-end update delay, stale detection and reconnection time, false-fresh indications, RSSI distribution, and local LED response delay. No safety distance or range target.

## 25. Limitations

No external client or third anchor; two-node BLE link only. RSSI is not a reliable distance measure. Exact module revision, SDK/host software, computer/USB access, and local BLE authorization are unconfirmed. Not safety-certified; cannot implement an E-stop or personnel-protection HMI.

## 26. Future improvements

Only with existing listed stock: evaluate deterministic freshness and reconnection under several already available lab conditions. No phone, gateway, extra node, or cloud service.

## 27. Research opportunities

Does a freshness/timeout state machine eliminate false “connected” indications after packet loss compared with a simple last-value display on a two-node BLE link? Investigate only after software and test access are verified.

## 28. References

- TI, [BOOSTXL-CC2650MA product page](https://www.ti.com/tool/BOOSTXL-CC2650MA) — compatible MSP432 host, preloaded network processor, UART/JTAG, kit contents, and example software.
- TI, [CC2650 Module BoosterPack Getting Started Guide SWRU486A](https://www.ti.com/lit/ug/swru486a/swru486a.pdf) — board signals/terms; match exact revision.
- TI, [CC2650 datasheet](https://www.ti.com/lit/ds/symlink/cc2650.pdf) — IC-level limits, not host interface.
- [Inventory](../HARDWARE_INVENTORY.md).

## 29. License

See root [LICENSE](../LICENSE); repo licensing decision pending. Follow TI software and Bluetooth qualification/license terms.

## Reproducibility checklist

- [ ] Two exact BOOSTXL-CC2650MA and MSP-EXP432P401R pairs verified
- [ ] Shared MSP432 hosts released before the later P11 use
- [ ] Existing software/host/USB access confirmed; no downloads
- [ ] Local BLE test approval complete
- [ ] Freshness, disconnect, reconnect and delivery metrics recorded
- [ ] No distance/safety/use claims
