# 03 — Data flow

```mermaid
flowchart LR
    Reflectance[Floor reflectance samples] --> Validity[Range and validity checks]
    Encoders[Left/right encoder edges] --> Odometry[Wheel-speed estimate and odometry]
    Range[Optional front range samples] --> Validity
    Bump[Contact switches] --> Safety[Safety and fault supervisor]
    Validity --> Landmark[Route landmark/junction detector]
    Landmark --> Localization[Topological location correction]
    Odometry --> Localization
    Localization --> Planner[Known route graph and path search]
    Planner --> Mission[Mission state machine]
    Validity --> Safety
    Mission --> Safety
    Safety -->|safe speed/direction commands| Control[Wheel speed controllers]
    Control --> Drivers[Chassis motor drivers]
    Drivers --> Motors[Left/right motors]
    Safety --> Log[Timestamped local telemetry]
    Localization --> Log
    Range --> Log
    Log --> PC[USB debug/backchannel to PC<br/>after port verification]
```

## Logging fields to freeze during implementation

`time_ms, trial_id, robot_id, mission_state, node_id, edge_id, target_node, left_encoder_delta, right_encoder_delta, left_speed, right_speed, estimated_pose, reflectance_raw, range_raw, range_valid, bump_bits, commanded_left, commanded_right, fault_code, event_code`.

Units, sampling interval, integer scales, calibration version, missing-value encoding, and firmware version must be defined before data collection. No sample data are supplied here.
