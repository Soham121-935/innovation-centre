# P14 — Inventory-Only BOM

| Item | Quantity | Inventory evidence/status | Role | Planned additional cost |
|---|---:|---|---|---:|
| OMAP-L138 DSP Kit | 1 | Listed; exact LCDK/EVM variant, revision and condition unknown | Candidate DSP board | $0; existing cost unknown |
| External JTAG emulator | 0 confirmed | LCDK guide says no onboard emulator; external emulator required | Required only if physical kit matches LCDK and programming/debug needed | $0; no purchase—build blocked if absent |
| Microphone / line-level signal source / machine transducer | 0 confirmed | Not listed | Required for physical acquisition | $0; no purchase—measurement blocked |
| Audio/USB/JTAG cables and safe power | Not confirmed | Kit contents/accessories unknown | Required only if matching setup calls for them | $0; not assumed |
| Computer, CCS/Processor SDK | Not listed | Availability/license unknown | Build/debug/log if already supplied | $0; no download/install |

No external equipment or dataset is planned. Missing items are blockers, not recommendations.