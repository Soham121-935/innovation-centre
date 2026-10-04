# P08 — Research Plan

**State:** two-node BLE system is plausible from supplied radios/hosts, but physical revision, software/USB access and local test authorization are unverified. No data exists.

## Question

Does a sequence/freshness/timeout state machine reduce false “peer available” indications compared with displaying the last received status on a two-node BLE HMI?

## Scope / method

If exact BOOSTXL-CC2650MA + MSP-EXP432P401R pairs match and existing TI host examples/SDK are available, use one node as status advertiser/server and the other as receiver/client only if the verified stack documents these roles. Keep a small status and monotonically changing sequence. The receiver marks disconnected/unknown on timeout; no actuation or phone is used. BLE/HMI operation must be approved locally.

## Hypothesis / metrics

Freshness validation will prevent stale values being presented as current, with a measurable timeout delay. Record connection establishment, message loss/delivery, sequence errors, end-to-end update latency, stale timeout, reconnection time, false-fresh indication, RSSI distribution if exposed, and local indicator delay. RSSI must not be converted to distance. Set threshold after a no-loss baseline.

## Blockers / references

Both listed MSP432 LaunchPads are provisionally reserved for P08, then released; P11 may reuse one later. P09 uses the documented MSP430F5529 host candidate. Software, PC, cable and local RF approval are not confirmed. Sources: [BOOSTXL-CC2650MA TI page](https://www.ti.com/tool/BOOSTXL-CC2650MA), [SWRU486A](https://www.ti.com/lit/ug/swru486a/swru486a.pdf), [inventory](../../HARDWARE_INVENTORY.md).