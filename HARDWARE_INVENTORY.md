# Hardware Inventory and Provisional Allocation

## Source and verification status

This list transcribes the supplied Innovation Center inventory. It is a starting point—not a verified bill of materials for any project. Exact manufacturer part numbers, revisions, working condition, included accessories, batteries, and sensor-set contents have not all been recorded or physically verified. No units have been checked out or bench-verified by this documentation work.

Allocation figures are **planning reservations only** to avoid accidental oversubscription. “Planning balance” is stock minus the maximum planned simultaneous reservation under the documented sequential workflow, not a confirmation of available working stock. A project may use a shared item only after the previous project has recorded its configuration and release. Before projects run simultaneously, lab checkout and release dates must be recorded. Conditional host-board reservations must be revisited when the project reaches its hardware-research phase.

## Inventory and provisional allocation

| Hardware as listed | Available | Provisional project assignment | Maximum planned reserved simultaneously | Confirmed physically in use | Planning balance | Verification note |
|---|---:|---|---:|---:|---:|---|
| Robotics System Lab Kit (RSLK) | 10 | P01: 1; P03: 1 | 2 | 0 | 8 | Family/version, controller, chassis, included sensors and completeness unknown. P01/P03 units are conditional sequential assignments. |
| RSLK Sensors | 3 sets | P01: up to 1 conditional; P03: 1 conditional | 2 | 0 | 1 | Exact contents/interface unknown; P01 reservation only needed if compatible range sensors are physically in the set. |
| Neuro Sense Band | 2 | P02: 1 conditional | 1 | 0 | 1 | Exact model and signal interface unknown. |
| CC110L Booster Pack | 2 | P04: 2 | 2 | 0 | 0 | Exact SKU/revision, host MCU, regional frequency variant, antenna, and firmware support unknown; no RF transmission before local approval. |
| TIVA LaunchPad | 5 | P05: 1; P06: 1 conditional | 2 | 0 | 3 | Exact board/MCU model unknown. P06 SenseHUB host requires a documented compatible model. |
| SenseHUB Booster Pack | 2 | P06: 1 conditional | 1 | 0 | 1 | Exact sensor population/revision unknown; BOOSTXL-SENSHUB facts remain conditional until inspection. |
| BOOSTXL-CC1125 | 2 | P07: 2 | 2 | 0 | 0 | Host candidate is MSP430F5529 LaunchPad; radio variant/antenna and regional RF approval remain unresolved. |
| BOOSTXL-CC2650MA | 2 | P08: 2 | 2 | 0 | 0 | Documented TI examples require compatible MSP432 host; exact module/board revision and SDK unknown. |
| SimpleLink Wi-Fi CC3100 Booster Pack | 2 | P09: up to 2 | 2 | 0 | 0 | Exact CC3100BOOST/MODBOOST variant unknown. Two local nodes avoid assuming an external router/client; browser is not in inventory. |
| CC3200SF LaunchPad | 2 | P10: up to 2 conditional | 2 | 0 | 0 | Exact LaunchPad/MCU revision and onboard sensor population unknown; TMP008 may be absent on newer boards. |
| MSP432P401R LaunchPad | 2 | P08: 2; P11: 1 sequential reuse | 2 | 0 | 0 | P08 uses two hosts for a two-node BLE study, then releases them; P11 uses one later. P09 no longer reserves an MSP432 host. |
| MSP430F5529 LaunchPad | 4 | P07: up to 2; P09: up to 2; P12: 1 sequential reuse | 2 | 0 | 2 | TI documentation supports these as candidate hosts for P07/P09. Projects share two boards sequentially; P12 uses one after release. Exact board revision/accessories unknown. |
| Sensors (generic set) | 1 set | P13: 1 conditional | 1 | 0 | 0 | Identify each sensor and interface before claiming capability or wiring. |
| OMAP-L138 DSP Kit | 1 | P14: 1 | 1 | 0 | 0 | Exact LCDK/EVM variant and included acquisition peripherals unknown; LCDK requires an external emulator. |

### Allocation rules

1. Record physical asset/tag IDs, model/revision, condition, borrower, checkout date, and release date once the lab confirms units.
2. Do not treat a planned reservation as permission to dismantle or reconfigure a shared robot.
3. Reuse is sequential only after the first project releases the unit and documents calibration/configuration. Do not count one physical unit for simultaneous experiments.
4. The two MSP432P401R boards are provisionally reserved together for P08. P11 may use one only after P08 releases it; P09's candidate host is MSP430F5529, not MSP432.
5. P07 and P09 may each need up to two MSP430F5529 hosts for their respective two-node tests; P12 may use one after release. Maximum simultaneous host reservation is two because work is sequential.
6. P09's up-to-two CC3100 boards and P10's up-to-two CC3200 boards are conditional local two-node options to avoid assuming an external client/router. No browser, computer, network, or cable is established by the hardware count.
7. P05 and P06 use separate TIVA boards sequentially. A generic TIVA model is not automatically compatible with the SenseHUB.
8. A BoosterPack is not treated as a standalone host unless its official documentation says so. Missing host, emulator, test instrument, computer, cable, software, or sensor remains a blocker; no unlisted item is added or recommended for purchase.
9. For RF projects P04/P07/P08/P09/P10, manufacturer certification examples are not treated as local permission. Get qualified approval for the exact band, power, antenna, channel, and test setup before any transmission.

## Project 01 inventory check

The official TI-RSLK MAX reference kit includes a chassis board, LaunchPad, motors/encoders, bump switches, and an eight-channel reflectance array; its guide lists three Sharp GP2Y0A21YK0F distance sensors as **not included/optional**. The lab inventory says “RSLK” and separately lists “RSLK Sensors,” so neither the MAX kit nor the contents of the sensor sets are confirmed for this lab. See [Project 01 hardware verification](01-autonomous-industrial-mobile-robot/hardware/VERIFICATION.md).

Before checkout, wiring, or firmware work, photograph/record:

- RSLK kit label/SKU and inventory asset tag;
- chassis PCB top/underside markings and revision;
- controller board marking (for example, MSP-EXP432P401R) and LaunchPad revision;
- labels/part numbers on each RSLK sensor and connectors;
- motors/encoder assemblies, bumper switches, reflectance board, battery contacts, and any range/IMU boards;
- battery type/count and whether usable cells are physically in stock.

## Primary references

- [TI TIRSLK-EVM product page](https://www.ti.com/product/TIRSLK-EVM/part-details/TIRSLK-EVM?ds_k=TIRSLK-EVM&DCM=yes)
- [TI-RSLK MAX User Guide, SEKP166](https://www.ti.com/lit/ml/sekp166/sekp166.pdf)
- [TI-RSLK MAX Construction Guide, SEKP164](https://www.ti.com/lit/ml/sekp164/sekp164.pdf)
- [TI MSP432P401R datasheet, SLAS826](https://www.ti.com/lit/ds/slas826e/slas826e.pdf)
