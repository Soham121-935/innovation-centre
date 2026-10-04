# P10 — Conditional CC3200-LAUNCHXL Signals

No lab board pin map is verified. The inventory says CC3200SF LaunchPad but gives no hardware revision. TI SWRU372C applies to CC3200-LAUNCHXL Rev3.2 and mostly to Rev4.1 with revision-specific caveats. Verify the exact silkscreen/schematic before any pin or jumper reference.

Conditional sensor interface from the guide: BMA222 and TMP008 use I²C; the TMP008 at U6 is DNP on newer builds. J2/J3 connect SDA/SCL to onboard sensors and their pullups; J4 routes the accelerometer interrupt. Do not change/remove jumpers or attach external wiring from this summary. The exact board manual and schematics control.

No sensor measurement or pin-level value is confirmed for P10. Source: [TI SWRU372C](https://www.ti.com/lit/ug/swru372c/swru372c.pdf).