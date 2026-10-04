# 02 — Conditional hardware connection diagram

**Conditional drawing:** reference only if the physical unit is verified as TI-RSLK MAX. The inventory does not confirm that platform. No wiring instruction is valid until board and revision match the official source. Do not add or substitute parts.

```mermaid
flowchart TB
    Cells["Matching cells<br/>only if already provided"] -. "otherwise power test blocked" .-> Power["Verified RSLK chassis power section"]
    Host["Existing approved host/cable<br/>not listed; optional for debug only"] -.-> XDS["XDS110-ET<br/>only if physically verified"]
    XDS <-->|"debug/program via documented interface; no code in this phase"| LP["Matched LaunchPad<br/>only if present/compatible"]
    LP <-->|"mating headers; MAX +5 V jumper rule applies only after identity gate"| Chassis["Verified chassis revision"]
    Chassis --> LDRV["Left driver<br/>if present"]
    Chassis --> RDRV["Right driver<br/>if present"]
    LDRV --> LM["Left motor<br/>if included"]
    RDRV --> RM["Right motor<br/>if included"]
    LE["Left encoder<br/>if present"] --> Chassis
    RE["Right encoder<br/>if present"] --> Chassis
    QTR["Reflectance array<br/>if present"] --> Chassis
    Bump["Contact switches<br/>if present"] --> Chassis
    StockRange["Compatible range sensor<br/>only if found in supplied stock"] -. "no purchase / none verified" .-> Filter["Matched chassis filter/input path<br/>only if documented for exact revision"]
    Filter -. "only after electrical limits checked" .-> LP
```

## Connection constraints

- Do not mate boards or power the robot until the exact model/revision and official construction/power instructions are verified.
- For a confirmed MAX only, follow TI's guide for the LaunchPad header and +5 V jumper. Do not transfer that instruction to a different chassis without its own manual.
- Do not connect an unidentified sensor. Use a sensor's datasheet and chassis schematic only if the exact sensor is already in the supplied stock and the interface matches.
- A sensor/power/course/software absence is a blocker, not a reason to add a part or find a substitute.
- The conditional logical signal mappings are in [hardware/pin-map.md](../hardware/pin-map.md); there is no universal RSLK pin map.
