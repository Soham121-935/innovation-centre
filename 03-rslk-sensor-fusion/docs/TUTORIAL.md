# P03 — Sequential Verification Tutorial

> Desk-research plan only. Do not power or wire unidentified RSLK hardware; no external equipment or sensors may be added.

1. Record the RSLK carton/model, chassis silkscreen/revision, controller and LaunchPad markings, and condition.
2. Inventory all three RSLK Sensors sets item by item: manufacturer, exact label, connector, supply, output, quantity. Do not infer sensor contents from the kit name.
3. Compare each physical device to its own official guide. Treat TI-RSLK MAX pin information as conditional; the classic Maze Edition uses a different architecture.
4. Build a modality matrix. If fewer than two independent compatible modalities are confirmed, document “fusion MVP blocked” and continue to P04.
5. Check that the test reference, safe area, matched power, and compatible software/tools are explicitly provided. If not, defer all physical steps; do not purchase them.
6. Only after a supervisor approves the exact platform, characterize each sensor separately with the manufacturer's safe procedure. Do not move the robot for these checks.
7. Freeze sample cadence, timebase, validity limits, and a single-sensor baseline before defining fusion logic.
8. Proceed to motion/route tests only after P01 has verified the robot, safety, and course. P03 does not override the P01 gate.
9. The portable fusion function has passed synthetic host unit tests (see `../firmware/tests/README.md`). This is not a physical or target test. Once all hardware gates pass, record actual measurements, failures, and versions; no hardware tests have been performed.
