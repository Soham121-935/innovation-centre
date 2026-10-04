# 04 — Conditional host software architecture

> No software has been selected, installed, or implemented. Blocks below are conceptual and apply only if the physical band, existing host, supported official SDK, and authorized access all match.

```mermaid
flowchart TB
    Vendor["Official vendor SDK/API"] --> Adapter["Device adapter<br/>documented connect/auth/data callbacks"]
    Adapter --> Status["Connection + freshness + quality gate"]
    Status -->|not ready| Safe["Fail-silent idle<br/>clear request"]
    Status -->|ready| Input["Documented vendor output"]
    Input --> Calibration["Per-user baseline/threshold"]
    Calibration --> Filter["Dwell + hysteresis + cooldown"]
    Filter -->|stable| Request["Local request display"]
    Filter -->|uncertain| Safe
    Request --> Confirm["Separate human confirm/reject"]
    Confirm --> EventLog["Pseudonymized summary logger<br/>approved fields only"]
    Confirm --> Safe
    Status --> Monitor["Local status/latency monitor"]
    EventLog --> Report["Offline analysis/report"]

    Robot["RSLK or other actuator"]
    Confirm -. "no interface in first-stage MVP" .-> Robot
```

No custom BCI classifier, web/cloud service, robot control, or firmware is included. Raw signal storage is not required for the initial request-gating evaluation and remains outside Git.
