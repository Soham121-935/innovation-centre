# 04 — Software architecture

```mermaid
flowchart TB
    App[Mission application / finite-state machine]
    Fault[Fault manager and safe-stop policy]
    Planner[Known graph planner: BFS/Dijkstra]
    Localizer[Landmark-corrected topological localization]
    Odom[Wheel odometry and speed estimator]
    Controller[Independent wheel-speed PI loops]
    Filters[Sensor validity, calibration, filtering]
    Telemetry[Local event/CSV telemetry]
    Board[Verified board profile]
    Drivers[Motor, encoder, reflectance, bump, optional range drivers]
    Hardware[Exact physical RSLK/LaunchPad revision]

    App --> Planner
    Planner --> Localizer
    Localizer --> Odom
    Odom --> Controller
    App --> Fault
    Planner --> Fault
    Filters --> Fault
    Drivers --> Filters
    Drivers --> Odom
    Drivers --> Controller
    Fault --> Controller
    Board --> Drivers
    Board --> Hardware
    App --> Telemetry
    Localizer --> Telemetry
    Fault --> Telemetry
    Telemetry --> PC[Verified USB debug/backchannel]
```

## Design constraints

- Keep the chassis/LaunchPad pin configuration in one explicit, revision-named profile.
- Start in motor-disabled state. Only the fault supervisor can authorize nonzero wheel setpoints.
- Keep time-critical encoder capture/control out of blocking display, logging, or PC I/O code.
- Use no RTOS until a measured requirement justifies it; the first implementation is a small deterministic C state machine.
- This is an architecture proposal. No module or code is implemented yet.
