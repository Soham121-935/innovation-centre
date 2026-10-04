# RSLK Sensor Fusion and Autonomous Perception — Software Architecture

```mermaid
flowchart TB
    I["Caller-supplied normalized observations and anchor map"] --> C["Portable C fusion core — synthetic host tests pass"]
    C --> Q["Freshness, time-skew and disagreement checks"]
    Q --> S["Fused / degraded / uncertain / unknown estimate"]
    B["Exact board profile: not verified"] --> D["Sensor drivers and interface adapter: not implemented"]
    D -. "only after identity and safety gates" .-> I
    S -. "no motion control; no hardware safety claim" .-> O["Host caller / future route-state consumer"]
```

The host-tested core is hardware-independent and takes synthetic/caller-supplied inputs. No board profile, sensor driver, interface adapter, target build, or physical test is confirmed. Do not interpret this diagram as a wiring map or as evidence of lab sensor contents.
