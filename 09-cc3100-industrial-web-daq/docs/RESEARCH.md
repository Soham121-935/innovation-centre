# P09 — Research Plan

**State:** conditional local two-node Wi-Fi/HTTP study. Exact BoosterPack variant, host tools, peak-current power accessories, and browser access are unresolved.

## Question

Can an isolated CC3100 AP/server and a second listed CC3100 station/client carry a fresh, bounded digital input/status record and explicitly report request timeout without relying on internet or an external router?

## Scope / hypothesis

Use exactly two CC3100 boards and up to two listed F5529 hosts, conditional on official compatibility. The CC3100 network processor supports AP/Station modes at IC level; use only an existing matching host SDK. If the physical CC3100BOOST has the documented OOB user button and the exact software exposes it, treat that button as an event input—not a general sensor. Keep the response local and small. Browser rendering remains a separate blocked requirement because no browser host is inventoried.

A sequence/freshness field should prevent stale content being treated as current. Test association, request success, response age/content, timeout, and recovery. Measure request success, association/response latency, stale/duplicate rejection, and input-to-response delay. No internet throughput, security certification, or calibrated sensor accuracy claim.

## Blockers / safety

Exact CC3100 variant and pin map; supported existing SDK; computer/USB/debug; adequate peak-current supply path; browser client. No CC31XXEMUBOOST, router, sensor, download, purchase, credentials, or outside network assumed. Isolate test to the two listed nodes, use only approved local Wi-Fi configuration, and avoid entering institutional networks.

Sources: [CC3100BOOST page](https://www.ti.com/tool/CC3100BOOST), [SWRU371B](https://www.ti.com/lit/ug/swru371b/swru371b.pdf), [SWRU368C](https://www.ti.com/lit/ug/swru368c/swru368c.pdf), [inventory](../../HARDWARE_INVENTORY.md).