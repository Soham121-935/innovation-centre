# Project 01 — Hardware Verification and Research Record

**Record date:** 2026-10-03<br>
**State:** Conditional TI-RSLK MAX manufacturer research documented; Innovation Center units not physically inspected. Project 01 is paused at the inventory gate; no purchases of unlisted items are in scope.<br>
**Do not use this record as a checkout/connection instruction until the hardware identity gate passes.**

## 1. What the inventory actually says

The supplied list reports **Robotics System Lab Kit (RSLK), quantity 10**, and **RSLK Sensors, quantity 3 sets**. It does not identify a manufacturer SKU, version, chassis PCB revision, LaunchPad model/revision, sensor part number, battery stock, or condition. The separately listed two MSP432P401R LaunchPads may be extra boards; they must not be assumed to be the controller fitted to each RSLK.

No physical asset tag, box label, or PCB marking has been recorded here. Therefore all MAX details below are a documented reference configuration—not an assertion that the lab's RSLK is a MAX kit.

## 2. Variant distinction: MAX versus older/classic Maze Edition

### TI-RSLK MAX / TIRSLK-EVM — conditional reference

TI's product page identifies TIRSLK-EVM as the MAX kit, with an MSP432P401R LaunchPad, TI-RSLK chassis board, 8-channel QTRX reflectance sensor array, bump sensors, and two motor/encoder assemblies. The MAX guide identifies a Romi chassis and chassis board v1.0 family. The MAX chassis integrates its two motor drivers and power/sensor interface. The MAX user guide shows the MSP432P401R connected to that chassis by headers and supplies the MAX pin mapping in `pin-map.md`.

### Older/classic TI-RSLK Maze Edition — separate architecture

TI's older Maze Edition materials describe a Romi chassis with a **separate Motor Driver and Power Distribution Board (MDPDB)**, an MSP432 LaunchPad, and sensors/encoders whose exact inclusion varies by kit and lab. The older curriculum identifies a different MDPDB interface and includes optional encoder hardware in some labs. It is not valid to assume the MAX chassis PCB, plug-in arrangement, sensor wiring, or MAX pin table applies to this configuration.

### Decision

The inventory evidence does not distinguish these configurations (or a custom mix of parts). Identify the physical assembly and all board revisions before choosing the firmware target, power steps, sensor wiring, or pin map. If the kit is neither documented configuration, stop and research that exact board.

## 3. Conditional MAX bill of materials and capabilities

| Subassembly | Documented MAX reference capability | Included in the base MAX reference kit? | Lab status |
|---|---|---|---|
| TI LaunchPad | MSP-EXP432P401R with MSP432P401R MCU; user guide illustration identifies LaunchPad Rev 2.1; on-board XDS110-ET programmer/debugger, USB debug/backchannel, buttons/LEDs | Yes in TIRSLK-EVM reference | Unknown |
| MSP432P401R MCU | Arm Cortex-M4F up to 48 MHz; up to 256 KB flash/64 KB SRAM; 14-bit 1-MSPS SAR ADC; Timer_A/Timer32; UART/SPI/I²C; DMA; comparators; CRC/AES | On LaunchPad | Conditional on MCU marking |
| Chassis/power board | Romi chassis, battery interface/switching, regulated rails, LaunchPad headers, interface routing, LEDs, two DRV8838 motor drivers | Yes | Unknown; inspect board silkscreen/revision |
| Drive | Two brushed gearmotors, wheels, ball caster; dual differential drive | Yes | Unknown |
| Wheel sensing | Motor-mounted Hall-effect encoder assembly (the MAX guide reports 1,440 incremental steps per wheel revolution; actual software count convention must be confirmed/calibrated) | Yes in MAX reference | Unknown; inspect encoder headers and test |
| Contact sensing | Two bumper switch boards, three normally-open switches per board (six total in the MAX guide) | Yes | Unknown |
| Floor sensing | One 8-channel QTRX reflectance array for line/floor landmark detection | Yes | Unknown; exact QTRX board must be checked |
| Non-contact range | Three Sharp GP2Y0A21YK0F analog distance sensors, nominal measuring range 10–80 cm | **No; optional/not included in the MAX user guide** | RSLK sensor-set contents unknown |
| Power cells | Six AA cells are required for chassis-powered operation; TI states cells are not included in the kit | No | Lab stock/type/condition unknown |
| Wireless/IMU/GNSS/camera | No such item is part of the MAX base-kit contents documented in the user guide | No | Not planned for MVP |

The MSP432P401R device datasheet lists no integrated CAN controller, DAC, Wi-Fi, or BLE radio. Do not confuse the LaunchPad's USB-to-debug/backchannel facility or optional BoosterPacks with MCU-native peripherals. The MSP432 inputs are not permission to apply a sensor's 5 V rail to a pin; follow the device and sensor limits and the exact chassis interface.

## 4. Required physical identity gate

Record these items in the lab book and attach clear, non-personal photos (top and underside):

- [ ] RSLK carton label/model/SKU and lab asset tag.
- [ ] Chassis PCB silkscreen, revision, and any board/vendor number.
- [ ] Controller marking and LaunchPad board number/revision.
- [ ] Whether the LaunchPad is attached to each robot or stored separately; inspect required headers.
- [ ] Battery contacts, cell count, chemistry, and availability of a matched set.
- [ ] Motor and encoder assembly labels/connectors; verify both encoder channels per wheel if present.
- [ ] Reflectance-array part number and connector orientation.
- [ ] Every sensor in all three “RSLK Sensors” sets: manufacturer, model, connector, supply, output type, and quantity.
- [ ] Any distance/IMU/other module currently mounted, plus its board revision.
- [ ] Chassis, switches, motor clips, wheels, connectors, and boards are in safe working condition.

**Pass criterion:** one exact, source-documented hardware profile is selected and the printed/physical interconnect matches it. If any item is missing or differs, record the blocker; do not purchase or substitute unlisted items. Continue to the next project when the P01 gate cannot be resolved from supplied stock.

## 5. MSP432P401R software/debug research (conditional)

The conditional MAX target uses an MSP-EXP432P401R LaunchPad. TI's LaunchPad guide documents its XDS110-ET emulation/debug interface and backchannel UART; TI's RSLK materials document CCS and starter examples. These are software references, not proof that the lab has the toolchain or access. Use only compatible software already provided; if it is absent or unsupported, record firmware work as blocked and do not install or procure a substitute. Do not create a generic/untested build configuration and label it buildable.

The first firmware step after identity confirmation should be a **board-only, no-motor** smoke test (debugger connect, program, run, visible LED/UART check as documented). Chassis drivers follow only after power/pin verification.

## 6. Project 01 feasibility conclusions

- If the physically verified unit is a complete MAX, its documented base hardware can support differential drive, wheel-speed feedback, reflectance measurement, and a physical contact-stop input. Landmark localization additionally requires a pre-marked course, which is not listed in supplied inventory.
- The documented base MAX does **not** provide non-contact forward range sensing. That capability is usable only if a compatible sensor is found in the listed RSLK Sensors stock; otherwise the obstacle-detection MVP is blocked. No sensor is to be added.
- Encoder odometry alone is not absolute localization. The MVP uses known route nodes/floor landmarks to correct discrete route location and uses odometry only between such corrections.
- The route planner can re-route only over a known graph and known safe corridors. Sparse infrared sensors do not justify arbitrary dynamic obstacle avoidance or SLAM claims.
- There is no confirmed current sensor, so motor overload is inferred only cautiously from commanded motion versus missing encoder pulses; it is not a current measurement or predictive-maintenance claim.
- No external development board or motor driver is required when the verified MAX platform is available.

## 7. Source register

1. TI, [TIRSLK-EVM product page](https://www.ti.com/product/TIRSLK-EVM/part-details/TIRSLK-EVM?ds_k=TIRSLK-EVM&DCM=yes) — product-level MAX feature list.
2. TI, [TI-RSLK MAX User Guide, SEKP166](https://www.ti.com/lit/ml/sekp166/sekp166.pdf) — kit contents/not-included list; MAX chassis, sensors, pin map, software, and safety.
3. TI, [TI-RSLK MAX Construction Guide, SEKP164](https://www.ti.com/lit/ml/sekp164/sekp164.pdf) — assembly, required headers, and LaunchPad +5 V jumper warning.
4. TI, [MSP432P401R/MSP432P401M datasheet, SLAS826](https://www.ti.com/lit/ds/slas826e/slas826e.pdf) — MCU core, memory, peripherals, and electrical specifications.
5. TI, [MSP-EXP432P401R documentation/download page (includes User's Guide SLAU597)](https://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP-EXP432P401R/latest/index_FDS.html) — LaunchPad/debug hardware; verify exact revision against lab unit.
6. TI, [RSLK MAX motor-speed/control lab, SEKP146](https://www.ti.com/lit/pdf/sekp146) — MAX pin map, encoder/motor interface, calibration and controller test approach.
7. TI, [Classic TI-RSLK Maze Edition preface, SWRP242](https://www.ti.com/lit/pdf/swrp242) and [DC motor lab, SWRP187](https://www.ti.com/lit/ml/swrp187/swrp187.pdf) — older curriculum's separate chassis/MDPDB context; do not substitute its pins into MAX.
8. TI, [DRV8838 datasheet](https://www.ti.com/lit/ds/symlink/drv8838.pdf) — motor-driver electrical behavior (not a substitute for chassis-board current/power limits).
9. Pololu, [Sharp GP2Y0A21YK0F documentation](https://www.pololu.com/product/136) and [datasheet](https://www.pololu.com/file/0j85/gp2y0a21yk0f.pdf) — reference only if a physically present inventory sensor has that exact model; not a sourcing or purchase recommendation.

## 8. Unresolved items blocking firmware and build instructions

1. Which RSLK version and chassis PCB revision are physically in stock?
2. Is there an MSP-EXP432P401R LaunchPad with the required RSLK headers, and which board revision?
3. What exactly is in an “RSLK Sensors” set? Is a compatible non-contact distance sensor already in stock, and what is its exact model/interface? If none is present, mark obstacle sensing blocked; do not add one.
4. Are suitable power cells and any documented connection/mounting/conditioning parts already present in the supplied stock for the physically identified chassis? If not, defer the affected build; do not procure them.
5. Is a route/course with usable physical landmarks explicitly provided? None is listed in the hardware inventory; without it, route-localization/MVP tests remain blocked. Do not create or buy markers.
6. Which workstation/OS and compatible CCS/SDK versions are already provided and usable? If unavailable, defer firmware work; do not add software to the project plan.
7. Does the physical chassis expose the optional distance-sensor filter/input path described by the MAX guide?

Do not generate board-specific firmware or change a pin table to work around missing answers.
