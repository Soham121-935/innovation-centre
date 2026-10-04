# P04 — Conditional host/radio interface

No board-specific pin map is verified. The exact BoosterPack and compatible LaunchPad are unknown. CC110L uses a host interface documented by its datasheet, but that does not identify the physical BoosterPack connector mapping.

Do not map the candidate SPI/interrupt signals to a TIVA, MSP432, or MSP430F5529 by analogy. A matching schematic and host guide are required before any connection or transmission. No new adapter or LaunchPad is in scope.