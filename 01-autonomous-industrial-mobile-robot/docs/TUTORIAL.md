# Project 01 — Step-by-Step Tutorial

> **This is the build sequence, not a claim that the lab kit is already verified.** Stop at any mismatch. The published MAX pin map and steps below are conditional on the lab having TI-RSLK MAX/TIRSLK-EVM hardware. Do not connect unidentified boards or sensors. No firmware source has been created yet because the exact target is unknown.

## 1. What we are building

A low-speed robot that follows a known, marked route network, estimates its route position with wheel encoders between landmarks, detects a forward obstacle with a verified non-contact range sensor, and stops or chooses a known alternate route. It is an indoor lab demonstration, not a production AMR.

## 2. How the system works

The robot is a differential drive. Each wheel has a speed loop; encoder counts estimate wheel travel. A floor landmark (line/junction code) resets the topological route position periodically. A graph planner selects a route to a named station. A valid, persistent range reading marks the current edge blocked; the robot stops before contact, replans on the known graph, or reports “blocked” and stays stopped. A bumper is only the last-resort contact input.

## 3. Hardware explanation

For the conditional TI-RSLK MAX reference, the MCU is an MSP432P401R LaunchPad; a chassis board provides power and two DRV8838 motor drivers; the kit includes two motors/encoder assemblies, bump switches, and an eight-channel reflectance array. The MAX guide says the three Sharp GP2Y0A21YK0F analog range sensors and six AA cells are not included. Read [hardware/VERIFICATION.md](../hardware/VERIFICATION.md) and [hardware/pin-map.md](../hardware/pin-map.md) before touching the hardware.

## 4. Software explanation

The intended embedded program is a deterministic C application with small drivers, periodic encoder/sensor sampling, wheel-speed PI control, landmark-corrected route localization, graph search, a mission state machine, a safety supervisor, and local telemetry. No RTOS, web app, cloud service, wireless link, or ML is needed for the MVP.

## 5. Required tools

The supplied inventory does not list these tools/software/course resources, so none is assumed available. They are not purchase recommendations. If a step depends on any resource not explicitly provided in the supplied inventory, mark that step blocked and continue to the next project:

- Existing workstation with a supported USB data connection.
- Already-available TI Code Composer Studio (CCS), verified MCU/device support, and board-matched TI SDK or RSLK starter examples.
- The LaunchPad's documented USB/debug cable, if included and known-good.
- Existing digital multimeter and any supervised bench supply, oscilloscope/logic analyzer, or test tools required by the official procedure.
- Correct cells already in stock for the identified chassis, safe test blocks, bounded floor area, and measuring tools already available.
- Small mechanical tools already available and required by the exact construction guide.

The exact software/tool versions must be recorded if present. Do not install, buy, or substitute unprovided software or equipment as part of this inventory-only phase.

## 6. Check existing software (no new installation in this phase)

1. Check whether CCS, the exact device-family/debug-probe support, and the board-matched TI SDK/RSLK starter examples are already available on an existing workstation.
2. If any required software is missing or its license/access is unavailable, record that gate as blocked. Do not download, install, purchase, or substitute unprovided software under the inventory-only scope; continue to the next project.
3. If the matching software is already available, record CCS, compiler, device-support, SDK, operating-system, and driver versions in the lab notebook.
4. If the available software cannot identify the exact target/debugger, stop; do not select a different board profile.

## 7. Board programming — first safe check

1. Keep the LaunchPad detached from motor power/chassis during the first program test unless the exact guide explicitly specifies otherwise.
2. Connect the verified LaunchPad to the PC. Confirm the correct device and debugger appear in CCS/device manager.
3. Import and build the official no-motion out-of-box/LED example for the exact target; do not initialize chassis pins or motor outputs.
4. Start a debug session, flash, run, and observe the documented LED or serial behavior. Record the full build/debug log and software versions.
5. If the board does not enumerate, the debugger cannot connect, or the example does not build/run, stop and use [TROUBLESHOOTING.md](TROUBLESHOOTING.md).

**Expected verification:** target identification, successful build/flash/debug, and the exact documented onboard LED/serial response. No movement should occur. The expected response is not a result until observed.

## 8. Wiring and mechanical assembly

1. First pass the physical identity gate in [hardware/VERIFICATION.md](../hardware/VERIFICATION.md). If the kit is not the MAX reference, this tutorial's pin map and MAX assembly steps do not apply.
2. With every power source removed, inspect the chassis and controller for damage, bent pins, corrosion, and correct headers.
3. If and only if the confirmed kit is TI-RSLK MAX, follow TI's [construction guide](https://www.ti.com/lit/ml/sekp164/sekp164.pdf) exactly. In particular, verify the LaunchPad +5 V jumper is removed before mating it to the chassis; the MAX guide warns an incorrect jumper configuration can damage the boards.
4. Confirm the motor/encoder plugs, bumper-board orientation, reflectance array orientation, and battery polarity from the guide. Do not infer orientation from this text alone.
5. Do not attach optional range sensors until their exact model, the chassis filter/input path, and the analog output range are confirmed.

## 9. First chassis test — no motion

1. Keep the wheels clear of the bench and motor commands disabled.
2. Verify the battery set, polarity, switch, and chassis rails only at points documented for the exact board. Use the board guide and lab-supervisor procedure; do not probe unknown pins.
3. Confirm that the MCU boots and that the board-only program still runs from the intended power source.
4. Turn the system off and remove power before the next wiring change.

**Expected verification:** no unexpected heating, resets, smoke, or motor movement; stable MCU operation. Stop on any abnormal behavior.

## 10. Individual module test — bumper switches

1. With motor outputs disabled, load the official/verified bumper-input test for the exact board.
2. Observe each switch separately and record its input bit, idle state, pressed state, and any bounce.
3. Confirm the expected negative-logic behavior from the MAX guide only if the MAX board is confirmed.
4. Verify the safety state can latch a motor-disabled fault. Do not use the bump switch as the normal way to find obstacles.

**Expected verification:** each physically installed switch is individually distinguishable and a press requests safe stop. If the sensor set differs, stop and remap from its own guide.

## 11. Individual module test — reflectance array

1. Place the unpowered or motor-disabled robot on a flat, non-reflective test surface.
2. Verify the array orientation and height against its own datasheet/assembly guide.
3. Read each channel over a known light surface and a known dark mark; log raw timing/count values.
4. Check channel order (robot right to left) against the verified MAX guide. Repeat while moving the robot by hand over a test landmark.
5. Record ambient-light/surface sensitivity and choose marker geometry only after observing the real readings.

**Expected verification:** channels change reproducibly between the selected floor and marker. Do not interpret reflectance readings as obstacle distance.

## 12. Individual module test — wheel encoders

1. Raise and secure the chassis so the wheels cannot touch the work surface.
2. Read left/right encoder channels separately while turning one wheel by hand slowly.
3. Confirm channel transitions, direction sequence if the board exposes quadrature, and no false counts while stationary.
4. Rotate the wheel through a measured revolution and compare observed counts to the manufacturer reference; record the software count convention.

**Expected verification:** independent, monotonic counts for each wheel. Calibrate counts-per-wheel-revolution on the actual unit; do not copy a nominal number blindly.

## 13. Individual module test — non-contact range sensor

1. Inventory each “RSLK Sensors” set and record every label/part number. If no compatible non-contact range sensor is present in the supplied stock, mark obstacle sensing and the P01 obstacle-detection MVP blocked, skip this section, and continue to the next project in sequence; do not acquire a substitute.
2. If a sensor is in stock, use its exact manufacturer documentation. For a physically identified Sharp GP2Y0A21YK0F only, verify its documented 4.5–5.5 V supply and analog-output range, and verify that the selected RSLK has the compatible filtered analog input path. Its published range/update/current specifications apply only to that exact model; check whether the physical assembly already includes any required power conditioning.
3. Keep the MCU input within the exact datasheet limit. Do not connect a 5 V supply rail to an ADC pin. Use a chassis filter/connector only if the physical schematic confirms it.
4. If the verified in-stock sensor and existing test equipment permit, measure safe, diffuse targets at known distances within its valid range. Record raw readings and characterize nonlinearity, blind zone, material/angle sensitivity, and update latency. Otherwise mark that measurement gate blocked; do not add equipment.
5. Build a calibrated lookup/threshold table only from measurements. A single sample is not an obstacle event; persistence/hysteresis and data freshness must be defined.

**Expected verification:** stable, repeatable readings for the chosen test targets and a conservative invalid/out-of-range state. No distance estimate is valid outside the sensor's tested envelope.

## 14. Integration and motor tests

1. With power off, check motor direction and driver wiring against the exact board profile.
2. Raise the robot, clear the area, keep a hand at the physical power switch, and test one motor at the lowest safe/verified command. Stop if the motor stalls, chatters, overheats, or an encoder does not respond.
3. Repeat for the other motor, then both at low speed. Confirm zero command produces a safe stopped state.
4. Close the encoder speed loop at a low setpoint. Record speed steps, steady-state error, settling time, motor asymmetry, and controller update interval. Tune from measured values; do not copy someone else's constants.
5. Only after raised-wheel tests pass, move to a bounded flat floor. Keep speed low and use an operator stop.

**Expected verification:** predictable direction, encoder feedback, bounded speed, and a safe stop. Motors must never be stalled against a wall during testing.

## 15. Calibration, navigation, and full-system performance

1. Calibrate effective wheel radii/count scale from measured straight-line runs and calibrate effective wheelbase/turn error from repeated turns or square paths.
2. Use a marked course/surface only if it is explicitly part of the provided lab resources and has been verified. No course or route markers are listed in the supplied hardware inventory. If none is explicitly provided, mark route-localization/full MVP tests blocked and continue to the next project; do not create, buy, or improvise markers.
3. Verify localization at each landmark without a mission planner; then verify odometry between landmarks. Compare with measured floor marks.
4. Add the graph planner and mission state machine. First run with no obstacles; then place a safe, static, high-contrast obstacle in a controlled test location, with an alternate path available.
5. Test no-alternate-route behavior: the robot must stop and report blocked, not improvise off the known path.
6. Measure detection-to-stop latency and actual stopping distance at each test speed. The clear distance must exceed measured latency travel plus braking distance and a safety margin: `d_required >= v × latency + v²/(2 × a_min) + margin`, where `a_min` is measured conservative deceleration.
7. Repeat trials and preserve all success and failure runs. Use the metrics in [tests/README.md](../tests/README.md); publish no unmeasured performance claim.

## 16. Debugging and next-step workflow

- If a gate fails, stop there, save logs/photos, and troubleshoot before continuing.
- Record exact part markings and measured outputs; do not swap pins to “see if it works.”
- Once the first hardware test passes, update the project status/changelog and add its actual firmware source, build settings, and test record.
- Proceed to the next subsystem only after its predecessor's criterion is met.

## 17. Advanced improvements

After the MVP is stable, compare encoder-only localization with landmark-corrected odometry; evaluate multi-point range sensing only if multiple compatible units already exist in the supplied stock and a blind spot is measured; improve route confidence and failure recovery; and quantify performance under controlled battery, floor, and obstacle changes. Do not add SLAM, precise ranging, or ML unless the physical sensors and collected dataset support the claim. No unlisted hardware is to be added.
