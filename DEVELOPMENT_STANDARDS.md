# Development Standards

These standards apply to all 14 projects and are intended to keep the repository reproducible, hardware-grounded, and easy to split into separate repositories later.

## 1. Evidence labels

Every hardware-dependent statement must be distinguishable as one of:

- **Documented** — supported by a cited manufacturer/user-guide source, but not yet checked against lab stock.
- **Conditional** — accurate only if the physical item is the named model/revision. Conditional pin maps must be clearly marked and must not be used as wiring instructions.
- **Unverified** — the inventory label or available evidence is insufficient to assert a capability.
- **Bench-verified** — tested on the exact physical unit; include date, hardware ID/revision, toolchain version, procedure, raw data/log, and result.

Never change a claim to bench-verified merely because code compiles or a simulation passes. Do not invent a part number, pin, sensor, protocol, test result, price, or reference.

## 2. Project gates and work order

Work through projects 01–14 in the root README order. For a project, record the board and module labels, board revisions, included accessories, and exact quantities before fixing a design. A project cannot be marked 🟢 Working until its MVP passes documented physical tests. A software-only test must be labeled as such.

Within each project, progress through: hardware research → architecture → documentation/diagrams → minimum implementation → individual bench checks → integration → PC/web tools if justified → system test → optimization → advanced/research extension. Do not bypass a failing verification gate. Pure hardware-independent algorithms may still be implemented and host-tested with clearly labelled synthetic fixtures while target identity is blocked; this does not authorize a board adapter or target claim. If a gate is blocked by missing stock, model identity, authorized software, or other information, record the blocker and work completed in the repository, then continue sequentially to the next project.

## 3. Source and hardware accuracy

- Prefer manufacturer datasheets, evaluation-board guides, schematics, and official curriculum material.
- Cite the exact document and relevant board/device revision near pin tables and electrical assumptions.
- Separate the MCU's features from those of the LaunchPad, BoosterPack, chassis, and optional accessories.
- A LaunchPad/BoosterPack family resemblance does not establish electrical compatibility. Verify connector, pin multiplexing, voltage, power, and software support for the actual combination.
- State when a signal is routed through a board connector/filter rather than implying a loose-wire connection.
- Never drive an MCU pin outside its specified electrical limits. Verify analog output range and common ground before connecting sensors.

## 4. Documentation and measurements

Each project must maintain a README, sequential tutorial, hardware list, architecture/connection/data-flow/software diagrams, research plan, troubleshooting guide, tests, BOM, and semantic-version changelog. Use plain language, identify assumptions, and give a checkpoint and expected observation at every physical build step.

Separate **proposed acceptance criteria**, **expected behavior**, and **measured results**. No results directory may contain simulated or illustrative values labeled as measured. Preserve raw logs, test configuration, calibration parameters, and a short summary of processing scripts. Include failures and repeat counts rather than reporting only a best run.

## 5. Firmware and software

- Use the toolchain documented for the exact board for board-specific code; record compiler/SDK/IDE version and build settings. Hardware-independent algorithms may be compiled/tested with an available host compiler, but label that evidence and do not infer target compatibility.
- Keep embedded code modular (drivers, sensing, processing, control, communication, application). Avoid a monolithic `main.c`.
- Include a clean build procedure, target configuration, flash/debug procedure, expected output, and a no-motion/safe startup state.
- Keep board-specific pin and clock configuration in a named profile. Fail compilation or halt safely when a required profile/configuration is missing.
- Add unit tests for pure algorithms and bench tests for hardware interfaces. Simulation is supplementary, not a substitute for hardware tests.
- Add a browser interface or backend only when the project actually needs one. Prefer lightweight, local-first tools and no cloud dependency.
- Never commit personal credentials. Keep `config.example.*` templates; keep real secrets in ignored local files.

## 6. BOM and costs

Every BOM must show quantity, stock status, requirement, cost source/date, and reason. Classify listed stock as **A** (in the supplied inventory); if useful, mark unlisted items as out of scope rather than additions. “Not yet checked” is not the same as “available.” Existing inventory cost is unknown unless the lab provides it; report it as unknown/sunk cost rather than fabricating a number. Under the current inventory-only scope, planned purchases of unlisted hardware/software are **$0**. If a missing item blocks buildability, record the blocker and continue to the next project instead of proposing, pricing, or sourcing a substitute.

## 7. Repository hygiene and extraction

Keep each project self-contained: its own docs, code, tests, BOM, and changelog. Avoid cross-project imports or symlinks that would break when a folder is extracted. Shared standards may be copied during later extraction. Do not commit generated binaries, CCS build output, large raw datasets, or temporary logs unless a project explicitly needs a small reproducible sample. Keep larger data outside Git and document how to obtain it.

## 8. Status and versioning

Use the root status vocabulary: 🔴 Not Started / Blocked, 🟡 In Development, 🟢 Working, 🔵 Advanced, ⚫ Archived. Mark a blocked project 🟡 only when substantive research/documentation is actively progressing; distinguish a gate from an implementation claim. Project `CHANGELOG.md` files use semantic versions (`v0.1.0`, `v0.2.0`, `v1.0.0`). Record hardware changes, firmware/algorithm changes, test evidence, and known limitations. A status change needs a corresponding changelog and test record.

## 9. Engineering restraint

Use the simplest algorithm that provides a measurable advantage. Do not add ML, an RTOS, a web stack, extra radios, sensors, or any hardware/software absent from the supplied inventory just to increase apparent complexity. If a required capability cannot be observed with listed stock, state the limitation, mark the affected MVP/test blocked, and continue to the next project in order.

## 10. Repository verification

- Run `make test` before reporting repository-level completion. It checks the 14-project structure and documentation and runs the hardware-independent host tests that currently exist.
- `make test-p03-sanitized` is an optional host-only memory/undefined-behavior check where the compiler supports sanitizers.
- These checks do not establish target-toolchain compatibility, hardware identity, safe wiring, or physical performance. Record those as separate gates.
