# Safety

These projects are educational prototypes, not certified industrial machines, medical devices, or safety-rated systems. A software stop, RF link, or demonstration is not a substitute for an independent physical emergency stop and supervised operation.

## General electronics

- Disconnect batteries, USB, and external supplies before changing wiring or inserting/removing a board or BoosterPack.
- Inspect polarity, connector alignment, exposed conductors, damaged insulation, and loose screws before applying power. Use an ESD-safe, stable work surface and a current-limited bench supply when the exact hardware guide permits it.
- Confirm the maximum permitted voltage/current for each board, sensor output, ADC input, and supply rail from the exact part documentation. Do not assume a 5 V sensor signal is safe for a 3.3 V MCU.
- Do not probe or short battery, motor, or regulator rails. Stop immediately for unexpected heat, smell, smoke, or repeated resets; disconnect power and inspect under supervision.

## Batteries

- Use only the cell type, count, polarity, and voltage range specified for the verified chassis. Do not mix chemistries, ages, or charge levels. Do not charge cells in the robot unless the manufacturer explicitly permits it.
- Remove batteries for storage and transport where the kit guide recommends it. Keep cells away from metal tools and prevent short circuits.

## Motors and mobile robot (Project 01)

- Test with the wheels clear of the bench first, then at the lowest stable speed in a clear, bounded floor area. Secure the chassis; keep hair, fingers, clothing, cables, and loose objects away from wheels/gears.
- Do not deliberately stall or repeatedly bump the motors. TI warns that stalls can damage the gear train or overload the motor board. Use bump switches as a last-resort stop, not as the normal obstacle detector.
- Provide a reachable physical power switch and an operator who can cut power. The robot must start with motor outputs disabled and must stop on sensor/encoder faults, watchdog timeout, or an emergency event.
- Do not operate near stairs, people, fragile equipment, or active machinery. Do not carry people, heavy loads, or use the prototype for actual industrial delivery/inspection.
- If the platform is a TI-RSLK MAX, TI's guide specifically requires removal of the LaunchPad's 5 V jumper before mating it to the chassis. Verify the exact LaunchPad guide and inspect the physical board first; an incorrect power configuration can damage the LaunchPad and chassis.

## RF projects

Use only lawful frequencies, power levels, duty cycles, antennas, and test environments for the jurisdiction. Do not interfere with licensed or safety-critical systems. Do not transmit until the module variant, antenna, regional settings, and applicable rules are verified.

## Human subjects and neuro-sensing

Obtain informed consent, avoid medical/diagnostic claims, protect identifiable signal data, and follow institutional ethics and privacy requirements before any signal collection. Follow the exact manufacturer's wear, charging, and cleaning instructions after the physical band model is verified; stop if the unit is damaged or causes discomfort. Do not collect or commit raw biometric data unless specifically necessary, consented, approved, access-controlled, and stored outside Git. Do not make a robot move based on a single noisy or unvalidated neural-signal classification. Project 02's first-stage output is local and display-only, with explicit human confirmation; unavailable hardware/software/access remains a blocker, not a purchase request.

## Stop-work rule

If the exact hardware, power path, pin mapping, or safety limit is uncertain, stop and verify the manufacturer's documentation or ask a qualified lab supervisor before powering or wiring the system.
