# P07 — Conditional BOOSTXL-CC1125 Interface

No pin-level map is validated for lab hardware. TI SWRA520 documents the BOOSTXL-CC1125 connection to MSP-EXP430F5529/MSP-EXP430G2553 LaunchPads and the SmartRF Studio setup. Match the physical module revision and exact host schematic before wiring. The CC1125 IC's SPI/IRQ needs do not determine the BoosterPack connector pinout.

**Power/jumper caution:** SWRA520 describes separate LaunchPad and USB/SmartRF Studio power configurations and a board power-source jumper. Do not move the jumper or connect USB power based on this text; follow the exact matching TI guide. No TX until local RF authorization.

No frequency, GPIO, SPI, interrupt, or power pin is listed here because the lab board revision is unknown. Source: [TI SWRA520](https://www.ti.com/lit/an/swra520/swra520.pdf).