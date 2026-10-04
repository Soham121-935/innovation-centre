# Distributed Sensor Fusion using SenseHUB — Troubleshooting

> No hardware-specific remedies are verified yet. Follow safety rules and record board/SDK versions before diagnosing.

| Problem | Possible cause | Verification | Solution |
|---|---|---|---|
| Board not detected | Cable, driver, power, or wrong board selection | Check the exact board guide and operating-system device list | Use a known data cable; install only the documented driver; retry on a supported USB port |
| Programming/debug failure | Wrong target, toolchain, probe, or power configuration | Confirm board revision, target configuration, debugger selection, and power | Use the correct manufacturer's example/configuration; do not change board jumpers without the board guide |
| No serial output | Wrong port/settings, application not running, or incorrect route | Check debugger/backchannel documentation and terminal settings | Verify the correct interface and firmware status before changing pins |
| Invalid sensor data | Wiring, power, scaling, sensor variant, or calibration issue | Measure the sensor supply/output safely and compare to its datasheet | Disconnect power, correct the verified wiring/range, recalibrate, and retest |
| Unexpected timing/data | Clock, interrupt, sampling, buffer, or synchronization issue | Capture timestamps and inspect build configuration | Reduce the test to one module; instrument timing; document the corrected configuration |
| Build error | Missing SDK/device support or stale generated files | Record IDE/compiler/SDK versions and first diagnostic | Install the documented package or clean/re-import the project; preserve the original error log |

Add project-specific rows only after the cause and remedy have been reproduced.
