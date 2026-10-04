# P04 — Research Plan

**State:** conditional desk research; exact radio board/host and regional RF configuration are unknown. No RF activity or result exists.

## Question

If two listed units and compatible listed hosts are physically verified and a lawful profile is approved, what packet delivery, latency, and link-quality distribution can be measured for a local, non-critical status link?

## Proposed method

Use a two-node point-to-point protocol only if the exact kit supports it. Start with numbered, short status frames, integrity/freshness validation and bounded acknowledgment/retry only when supported by the verified stack. Measure packet loss and timeouts; do not represent missing packets as alarms delivered. Compare tests only under an approved legal profile and repeat across provided conditions. No mesh/coverage design or emergency use.

## Hypothesis and metrics

A sequence/freshness check plus acknowledgement should expose loss and duplicates more reliably than a receiver display without validation, at the cost of retransmission latency. Measure packet-delivery ratio, ack ratio, median/p95 latency, RSSI/LQI where the verified hardware reports it, retry/duplicate count, timeout recovery, and node uptime. Define thresholds only after the exact hardware, region, and baseline are established.

## Blocking conditions

Physical model/antenna, compatible host, required authorized software, or compliant regional frequency not verified. No compatible MSP430G2 LaunchPad is listed for the 430BOOST candidate. If any gate cannot be closed from supplied stock, do not transmit or procure; record the blocker and continue to P05.

## Safety and references

Not an emergency system, personnel alarm, or safety interlock; no machinery or real alert path may be connected. Sources: TI [CC110L datasheet](https://www.ti.com/lit/ds/symlink/cc110l.pdf), [CC110L product page/legacy documentation](https://www.ti.com/product/CC110L), and [local inventory](../../HARDWARE_INVENTORY.md).