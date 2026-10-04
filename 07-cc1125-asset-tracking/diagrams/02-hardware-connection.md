# Sub-GHz Industrial Asset Tracking and Telemetry — Hardware Connection Boundary

```mermaid
flowchart LR
    I["Listed stock: Two BOOSTXL-CC1125 modules and four MSP430F5529 LaunchPads."] -. exact identity/interface unknown .-> T["Two listed MSP430F5529 LaunchPads, conditional on exact physical match"]
    T -. only after official compatibility and safety checks .-> E["Binary recent-link/unknown status; no coordinates or distance"]
```

No wiring, pin map, power setting, or RF emission is authorized by this diagram. See `hardware/VERIFICATION.md`.
