# 03 — Conditional data flow

> Proposed only. The inventory model and available SDK are unknown. Exact fields, units, timestamps, callback cadence, and retention must come from the matching official SDK documentation.

```mermaid
flowchart TD
    Device["Verified band, if model matches"] --> Vendor["Official SDK/vendor interface only"]
    Vendor --> Conn["Connection/authentication status"]
    Vendor --> Quality["Contact/signal-ready status, if exposed"]
    Vendor --> Values["Documented vendor state/data outputs"]
    Conn --> Gate["Freshness + quality gate"]
    Quality --> Gate
    Values --> Gate
    Gate -->|invalid/stale| Idle["Clear request; idle; no command"]
    Gate -->|fresh/ready| Cal["Separate per-user calibration baseline"]
    Cal --> Decision["Threshold + dwell + hysteresis"]
    Decision -->|stable candidate| Request["Local request display"]
    Decision -->|ambiguous/no event| Idle
    Request --> Confirm["Human confirm/reject"]
    Confirm --> Summary["Minimal approved event summary"]
    Confirm --> Idle
    Raw["Raw EEG/PPG (not required)"] -. "store only with separate need, consent, approval, protection" .-> Restricted["Restricted storage outside Git"]
```

Suggested event-summary fields after approval: random session ID, monotonic timestamp, model/software version, connection/quality/freshness status, condition, event marker, request/confirm/reject status, latency, outcome, and exclusions. Do not store names, serials, credentials, raw personal data, or unapproved samples. No sample dataset is supplied.
