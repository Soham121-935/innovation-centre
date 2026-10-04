# P07 — Research Plan

**State:** conditional two-node link study. Board/host match, regional RF approval, and software access are unresolved; no emissions/data/results.

## Question

Under an approved local RF profile and verified BOOSTXL-CC1125 + MSP-EXP430F5529 pairs, how reliably can a sequence/freshness-aware receiver identify a recent peer link compared with raw packet reception?

## Scope and hypothesis

Use exactly two nodes. A fresh valid sequence and timeout should reduce false link-present states caused by stale/duplicate packets; it cannot determine position. Record RSSI distribution as link quality only; no range inference. No Sigfox service is assumed despite TI's EU-license note.

## Method and metrics

Only after physical matches, existing supported host/software, and qualified regional authorization: send non-critical numbered packets in a controlled approved environment; log transmit/receive/ack timestamps, sequence, RSSI/LQI only if documented, retries, timeouts, duplicates, and recoveries. Measure packet-delivery ratio, stale/duplicate rejection, false link-up/down, latency and reconnect time. Set thresholds after a legal baseline. Do not intentionally interfere with other users.

## Blockers / references

Regional profile (TI report cites US/EU ranges), exact module/jumper/antenna, existing PC/USB/software, and local approval remain unverified. Two nodes cannot support multilateration. Sources: [TI SWRA520](https://www.ti.com/lit/an/swra520/swra520.pdf), [CC1125 datasheet](https://www.ti.com/lit/ds/symlink/cc1125.pdf), [inventory](../../HARDWARE_INVENTORY.md).