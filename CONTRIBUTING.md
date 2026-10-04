# Contributing

This repository is being developed sequentially around physical Innovation Center hardware. Contributions should make projects easier to build and verify, not merely larger.

## Before proposing a change

1. Confirm the active project and its development phase in `PROJECT_STATUS.md`.
2. Check `HARDWARE_INVENTORY.md` and the project's hardware verification notes before assuming a board, accessory, or sensor is available.
3. Cite manufacturer documentation for hardware capabilities and pin mappings. Mark unverified or revision-dependent information explicitly.
4. Use only hardware/software already listed or explicitly provided. If a required item is absent or unidentified, document the blocker and continue to the next project in order; do not propose or price an unlisted purchase.

## Documentation and code expectations

- Keep the project's standard folder structure and its own `CHANGELOG.md`.
- Provide board-specific firmware only when the exact target board/toolchain is established. Pure hardware-independent algorithms may be host-tested earlier with synthetic fixtures if their limits are explicit. Identify files, dependencies, reproducible host/target build steps, and expected output.
- Never label pseudocode, a template, a host-only core, or a compile-only example as tested target firmware.
- Give step-by-step physical instructions with safety notes and intermediate checks.
- Record proposed thresholds separately from measured results. Include raw data or a reproducible link for results; do not invent or cherry-pick outcomes.
- Add tests for algorithm changes and update troubleshooting, BOM, and research notes when affected.
- Do not add cloud services, AI/ML, external boards, displays, sensors, software, accounts, or accessories absent from the supplied inventory/provisioned environment. Missing dependencies are blockers, not procurement recommendations.

## Repository hygiene

Do not commit secrets, tokens, Wi-Fi passwords, generated binaries, temporary IDE workspaces, or unreviewed large datasets. Keep secrets in local ignored configuration. Ask before changing the repository license; the current `LICENSE` file records that a license decision is pending.

## Hardware reports

When reporting a physical test, include the kit/model and revision, sensor/module part numbers, battery/power setup, board/toolchain versions, test conditions, number of trials, logs, and any failures. A photo of silkscreen/labels is useful, but should not contain personal information.

## Pull requests

Use a focused change and describe: project/phase, what changed, why, hardware evidence, how to reproduce tests, cost impact, and remaining limitations. Run `make test` for repository checks, and state explicitly when evidence is host-only. If a project is blocked by missing stock or information, document the blocker and work completed, then proceed sequentially to the next project.
