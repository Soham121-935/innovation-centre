# P12 — Target Current Measurement Boundary

No application GPIO map is selected. TI SLAU533D describes the F5529 LaunchPad's isolation jumper block and target-domain boundary. For target-current measurement, TI's procedure removes the 3.3 V jumper and places a suitable ammeter across that gap; it cautions that target-side loads, backchannel and floating I/O affect current.

This is **not** a wiring instruction for unverified equipment. The inventory does not confirm an ammeter or its range/burden voltage. Do not remove a jumper or connect a meter until the physical LaunchPad revision, meter capability, exact guide, and lab safety procedure are checked. Never short 3.3 V to ground.

Source: [TI SLAU533D, section 2.3](https://www.ti.com/lit/ug/slau533d/slau533d.pdf).