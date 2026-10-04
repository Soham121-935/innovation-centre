# P03 Firmware and Portable Fusion Core

**State:** A hardware-independent C fusion core and synthetic host unit tests exist. There is **no board-target RSLK firmware, driver, board profile, pin map, startup code, or physical test result**.

## Portable core

- `core/sensor_fusion.h` and `core/sensor_fusion.c` accept caller-normalized encoder route progress and a caller-mapped landmark ID.
- Inputs, units, route anchors, timestamps, sample-age limit, source-time-skew limit, and disagreement threshold must be supplied by the caller. No sensor model, RSLK variant, signal interface, or calibration is assumed by the code.
- Fresh, time-aligned, agreeing inputs produce a midpoint estimate; one usable source is marked degraded; stale/future data, excessive source-time skew, an unknown landmark, or disagreement is surfaced explicitly. Excessively skewed inputs use only the newer source and are marked degraded; disagreeing time-aligned inputs never silently select one source.
- The module has no GPIO, sensor driver, clock, radio, motor-control, or board-library dependency. It cannot move a robot and is not a safety controller.

The encoder/landmark interface is an abstract software boundary, **not evidence that these modalities are fitted to the inventoried RSLKs**. See the project README and `hardware/VERIFICATION.md` for the unresolved identity gate.

## Host unit tests

From the repository root, with a C11 compiler and the standard math library:

```sh
gcc -std=c11 -Wall -Wextra -Werror -pedantic \
  -I03-rslk-sensor-fusion/firmware/core \
  03-rslk-sensor-fusion/firmware/core/sensor_fusion.c \
  03-rslk-sensor-fusion/firmware/tests/test_sensor_fusion.c \
  -lm -o /tmp/p03-sensor-fusion-tests
/tmp/p03-sensor-fusion-tests
```

The command passed in the Arena host environment with GCC 12.2.0. The same tests also passed with AddressSanitizer and UndefinedBehaviorSanitizer enabled. Test cases use synthetic values; **this is host logic verification only**, not an RSLK build, target-toolchain check, sensor test, calibration, or physical result. See [`tests/README.md`](tests/README.md) for coverage and limits.

## Target integration remains blocked

Do not flash a board, wire a sensor, or copy a pin map from a conditional TI-RSLK MAX reference. Before writing a board adapter, verify from supplied stock and matching manufacturer documents: the exact chassis/controller and sensor identities; actual signal interfaces, units, timing, calibration, voltage and power limits; a compatible toolchain already available to the lab; and the stationary test procedure. If any prerequisite is absent, record it as a blocker and continue sequentially. Physical motion remains gated by P01's platform and safety verification.
