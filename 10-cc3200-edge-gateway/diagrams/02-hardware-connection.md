# CC3200 Autonomous Industrial IoT Edge Gateway — Hardware Connection Boundary

```mermaid
flowchart LR
    I["Listed stock: Two CC3200SF LaunchPads; exact board revision and sensor population unknown."] -. exact identity/interface unknown .-> T["CC3200 integrated MCU on the exact verified LaunchPad"]
    T -. only after official compatibility and safety checks .-> E["On-board status and optional isolated peer link; no cloud or browser claim"]
```

No wiring, pin map, power setting, or RF emission is authorized by this diagram. See `hardware/VERIFICATION.md`.
