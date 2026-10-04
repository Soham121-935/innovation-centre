# 02 — Conditional hardware/interface connection

> No physical device or host has been verified. No pins, wires, supply rails, or BLE characteristics are defined. This diagram shows a candidate software link only, not a confirmed lab connection.

```mermaid
flowchart LR
    Band["Inventory item: Neuro Sense Band<br/>2 listed; exact model unknown"]
    BLE["Vendor-documented wireless path<br/>only if exact model supports it"]
    SDK["Matching official vendor app/SDK<br/>only if already supplied and authorized"]
    Host["Existing compatible host<br/>not in hardware inventory"]
    UI["Local HMI request/status<br/>display-only"]

    Band -. "candidate only: Neeuro SB-02 documents BLE 5.0" .-> BLE
    BLE -. "no custom protocol or pin map" .-> SDK
    SDK -. "conditional on model/access gate" .-> Host
    Host --> UI

    No["No MCU pins or direct wiring defined"]
    Robot["RSLK / motor outputs<br/>not connected in P02 MVP"]
    No --- Band
    Host -. "no current link" .-> Robot
```

Do not wire the band to any MSP432 or BoosterPack, scan undocumented services, or connect a robot based on this drawing.
