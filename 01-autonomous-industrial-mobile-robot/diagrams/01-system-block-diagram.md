# 01 — Conditional system block diagram

**Applicability:** research reference only, conditional on physical confirmation of TI-RSLK MAX / TIRSLK-EVM. Nothing in this diagram confirms that the lab owns that variant. Cells, route markers/course, compatible range sensing, host software, and exact sensor contents are not established by the supplied inventory; no additions are planned.

```mermaid
flowchart LR
    Cells["Power cells<br/>only if already provided and matched"] --> Chassis["Verified RSLK chassis<br/>variant/revision gate"]
    LaunchPad["LaunchPad/controller<br/>only if included or listed and verified"] <-->|"headers/power path conditional on exact model"| Chassis
    Chassis --> MotorDrivers["Onboard motor drivers<br/>only if verified on selected chassis"]
    MotorDrivers --> Wheels["Differential-drive motors<br/>if included"]
    Wheels --> Encoders["Wheel encoders<br/>if present and verified"]
    Encoders --> MCU["Controller / speed loop<br/>conditional on model"]
    Reflectance["Reflectance array<br/>if present and verified"] --> MCU
    Bump["Contact switches<br/>if present"] --> Safety["Safety/fault supervisor"]
    Range["Non-contact range sensor<br/>only if found in supplied stock"] -. "no compatible unit confirmed" .-> MCU
    MCU --> Safety
    Safety --> MotorDrivers
    Course["Provided marked course / landmarks<br/>none listed"] -. "required for route-localization; otherwise blocked" .-> Route["Known-map planner / landmark correction"]
    MCU --> Route
    Route --> Mission["Mission state machine<br/>proposed only"]
    Mission --> Safety
```

## Interpretation

- RSLK identity, component presence, controller, and wiring are unverified; the MAX-specific diagram is conditional.
- The inventory does not list a prepared course or floor markers. Without explicitly provided landmarks, route-localization tests are blocked.
- A compatible non-contact range sensor has not been found in supplied stock. Without one, the obstacle-detection MVP is blocked; bump switches are contact-only.
- No external sensor kit, additional MCU, PC/software, or other hardware is included in this plan. No system test or data have been recorded.
