# Project 01 — Bill of Materials (Inventory-Only Scope)

**Policy:** use only hardware present in the supplied Innovation Center inventory. No external hardware purchases or substitutions are planned. The model, condition, and contents of each inventory entry still need physical verification. If a required item is absent, mark that subsystem/build as blocked and continue to the next project rather than sourcing an unlisted part.

| Component | Quantity | Already available? | Required? | Estimated cost | Class | Reason / source |
|---|---:|---|---|---:|:---:|---|
| Robotics System Lab Kit (RSLK) | 1 | Listed: 10 total; exact variant/condition unknown | Yes | Existing cost unknown | A | P01 platform; identify family, controller, chassis revision, motors, and included sensors |
| RSLK Sensors | Up to 1 set | Listed: 3 sets; exact contents unknown | Only if it contains compatible sensors needed by the selected RSLK | Existing cost unknown | A | Inventory contents are not assumed; identify each sensor/interface first |
| MSP432P401R LaunchPad | 0 or 1 | Listed: 2; may already be included in the RSLK kit | Only if the verified platform requires it and one is not already included | Existing cost unknown | A | Use the listed board only if model/revision/headers are compatible; do not double-count it |
| Six matching AA cells | 6 | Not listed separately; physical stock unknown | Required only for the documented TI-RSLK MAX battery-powered configuration | $0 planned purchase; verify stock | Unlisted dependency | The MAX guide says cells are not included in its kit. If no suitable cells are already in lab stock, mark the MAX power test blocked; do not procure them under the inventory-only scope. |
| Compatible non-contact range sensor | Only what is found in existing RSLK/Sensors stock | Unknown | Required for non-contact obstacle detection | $0 planned purchase | A only if physically present | If no compatible range sensor is found, obstacle-detection MVP is blocked; bump switches remain contact-only and are not a substitute. |
| Route/floor landmarks or test course | 0 listed | Not present in the supplied hardware inventory | Required by the proposed landmark-corrected route MVP | $0; excluded | Out of scope | Do not assume tape, markers, or a prepared course. Without a course/landmarks explicitly provided, route-localization and full P01 navigation tests are blocked; do not create or buy markers. |
| External sensor, sensor kit, separate motor driver, MCU, display, radio, or cloud service | 0 | Not in supplied inventory list | No | $0 | Out of scope | Do not add or purchase these components. |

## Cost summary

- **Existing hardware acquisition cost:** unknown institutional/sunk cost.
- **Planned external purchase cost:** **$0**.
- **Additional project cost:** **$0 planned**; missing stock items block the affected test rather than triggering a purchase.
- **Inventory gaps to resolve:** exact RSLK variant, included LaunchPad, sensor-set contents, and usable cells for the verified chassis.

## Reference-only hardware documentation

These links are for identifying/validating an item **if it is found in existing stock**; they are not purchase recommendations:

- [TI-RSLK MAX User Guide](https://www.ti.com/lit/ml/sekp166/sekp166.pdf) — identifies MAX base contents and optional/not-included distance sensors.
- [Sharp/Socle GP2Y0A21YK0F datasheet](https://www.pololu.com/file/0j85/gp2y0a21yk0f.pdf) — consult only if an inventory sensor label matches this model.
