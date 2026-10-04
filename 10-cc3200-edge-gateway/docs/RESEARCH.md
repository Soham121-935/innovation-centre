# P10 — Research Plan

**State:** conditional on CC3200-LAUNCHXL identity and sensor fitment. No code, data, or network test exists.

## Question

Can a verified CC3200 node maintain an explicit valid/unknown state for its onboard motion sensor and optional temperature channel, and communicate fresh status locally between two listed boards without an external router or internet?

## Scope and hypothesis

SWRU372C identifies BMA222 and TMP008, but notes TMP008 U6 is not populated on newer builds. Inspect each board. Establish a stationary accelerometer baseline; use a transparent magnitude/deviation rule only for motion/no-motion, not machine health. Keep any TMP008 output in native units, without calibration claims. If existing SDK supports it, run one CC3200 as local AP/server and a second as station/client, exchanging sequence and sample age. No browser/dashboard is claimed.

A freshness gate should show unknown after sensor or link timeout rather than reuse stale values. Measure sensor sample availability/errors, stationary variance, simple motion detection latency, optional temperature availability/repeatability, message delay/loss, timeout/reconnect, and false-valid indication.

## Gates / references

Exact revisions, TMP008 presence, existing SDK/computer/USB, power, and local Wi-Fi approval are unresolved. No cloud, network client, router, external sensor, download or purchase. Sources: [SWRU372C](https://www.ti.com/lit/ug/swru372c/swru372c.pdf), [CC3200 datasheet](https://www.ti.com/lit/ds/symlink/cc3200.pdf), [inventory](../../HARDWARE_INVENTORY.md).