# P05 — Gated Tutorial

No motor test or code is authorized by this document.

1. Read the physical TIVA model/revision and compare with official documentation. Stop if ambiguous.
2. Identify an actual motor, driver, feedback sensor, and power path physically present in supplied stock. Do not assume RSLK compatibility with TIVA.
3. Verify voltage, current, connector, and isolation requirements from exact schematics. Do not power unknown wiring.
4. Confirm a matching toolchain and safe lab procedure are already provided. If not, record blocker and continue to P06.
5. Characterize any feedback independently, with motor output disabled and only if safe tools are available.
6. Define a repeatable baseline; do not stall, overheat, or mechanically fault the motor.
7. Only later, after hardware gates pass, compare baseline speed residuals and software-level fault cases. No physical fault seeding or real-time protection claims.
