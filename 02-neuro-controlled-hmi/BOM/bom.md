# Project 02 — Bill of Materials (Inventory-Only Scope)

**Policy:** consider only items in the supplied inventory. No hardware or software purchases/substitutions are planned. A “Neuro Sense Band” label does not identify a manufacturer/model. If a required host, accessory, official app/SDK, developer access, license, or approval is unavailable, the affected step is blocked; do not source it.

| Component / resource | Quantity | Already available? | Required? | Estimated additional cost | Class | Notes |
|---|---:|---|---|---:|:---:|---|
| Neuro Sense Band | 1 of 2 listed | Listed; exact model, revision, condition, and accessories unknown | Yes, subject to physical identity gate | $0 planned purchase | A | At most one unit reserved for sequential P02 work; inventory name does not establish EEG, BLE, vendor, SDK, or any exact capability |
| Host computer / compatible OS | 0 listed in hardware table | Unknown; not assumed | Only if already supplied and the verified interface requires one | $0 planned purchase | Not listed | If none is already available, stop and mark host-dependent integration blocked; do not add one |
| Charging/accessory parts | 0 separately listed | Unknown; inspect what is included with the physical band | Only according to exact matched device manual | $0 planned purchase | Not listed separately | If required accessory is not already supplied, defer charging/testing; do not buy a substitute |
| Vendor app/SDK, Developer Code, license, network access | Not hardware inventory | Availability/authorization unknown | Only for custom integration and only if already provided/authorized | $0 planned purchase; terms unknown | Software/access gate | Neeuro SDK docs are conditional on SB-02; Developer Code and Internet authentication are described by vendor. Do not assume free/included access or request/procure it |
| RSLK / robot bridge | Not allocated to P02 first-stage MVP | P01 stock and identity unverified | No | $0 | Out of scope for first stage | Do not reserve or connect a robot unless P01 releases a verified platform and a separate approved interface/safety review passes |
| Extra EEG electrodes/amplifier, MCU, BLE dongle, camera, cloud service, custom circuit | 0 | Not listed | No | $0 | Out of scope | No additional hardware or service is planned |

## Cost summary

- **Existing band acquisition cost:** unknown institutional/sunk cost.
- **Planned external hardware/software purchases:** **$0**.
- **SDK/developer/license cost:** unknown, not budgeted, not assumed included. If required access is not already available, custom integration is blocked.
- **Host/accessory cost:** no estimate; these are excluded from the plan unless already provided.
- **Total additional planned cost:** **$0**; stock or access gaps stop the affected work rather than triggering procurement.
