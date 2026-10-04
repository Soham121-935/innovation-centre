# P09 — Hardware Verification

Inventory: 2 “SimpleLink Wi-Fi CC3100 Booster Pack,” 4 MSP430F5529 LaunchPads. The CC3100 pack's exact SKU/revision is unspecified (possible CC3100BOOST or CC3100MODBOOST family); the physical units have not been inspected. TI lists MSP-EXP430F5529LP examples for CC3100BOOST, and TI's separate CC3100 module product page also lists the F5529 LaunchPad as the main host. Match the exact physical board and manual before connection.

For the CC3100BOOST match, SWRU371B documents an on-board antenna/U.FL test connector, buttons, LEDs, serial flash, USB power connector and power-selection jumper. It notes Wi-Fi peak current up to 400 mA at 3.3 V and possible need for a separate USB feed, plus a LaunchPad debug USB connection. No suitable cables/host PC are listed. Do not connect external power or move jumpers based on a generic description. CC31XXEMUBOOST is required for some firmware-update/advanced-debug paths and is not listed.

At IC level, CC3100 supports station, AP, and Wi-Fi Direct modes; an application still requires compatible host software. A browser client, router, sensor, SDK installation, and internet are not confirmed. No external device is assumed.

**Blockers:** exact SKU, matching host profile, peak-current power/cables, available SDK/host, browser client. Local-only two-node test may proceed only if the first four are physically/operationally available from supplied stock; otherwise log blocker and continue to P10.

Sources: [TI CC3100BOOST](https://www.ti.com/tool/CC3100BOOST), [SWRU371B](https://www.ti.com/lit/ug/swru371b/swru371b.pdf), [SWRU368C](https://www.ti.com/lit/ug/swru368c/swru368c.pdf), [inventory](../../HARDWARE_INVENTORY.md).