# P09 — Conditional Tutorial

1. Physically identify both CC3100 BoosterPacks; distinguish CC3100BOOST from CC3100MODBOOST/other module revision.
2. Check two MSP430F5529 LaunchPads against the exact TI host compatibility list. Respect P07/P12 sequential allocation and record checkout/release.
3. Inventory included cables and inspect only from the exact hardware guide. For CC3100BOOST, review peak current, J8 power jumper, USB feed, and debug cable requirements; do not power until the safe configuration is known.
4. Confirm the matching CC3100 SDK/host package and computer/USB are already supplied. Do not download/install. CC31XXEMUBOOST is not in inventory, so skip firmware update/advanced debug if it requires that board.
5. Confirm the exact revision has a documented app-visible input before using one. Otherwise P09 DAQ acquisition is blocked; do not substitute an unidentified generic sensor.
6. Only if all gates pass, configure an isolated two-node AP/server and station/client from existing supported examples. Do not use internet, institutional Wi-Fi, or outside data.
7. Test local request freshness, timeout, and recovery. Browser UI remains blocked unless a browser-capable client is already provided. No tests have run.
