# P03 Portable-Core Host Tests

These tests exercise `core/sensor_fusion.c` with synthetic C values. They do not use RSLK hardware, sensor captures, measured noise, or a board-specific toolchain.

## Run

From the repository root:

```sh
gcc -std=c11 -Wall -Wextra -Werror -pedantic \
  -I03-rslk-sensor-fusion/firmware/core \
  03-rslk-sensor-fusion/firmware/core/sensor_fusion.c \
  03-rslk-sensor-fusion/firmware/tests/test_sensor_fusion.c \
  -lm -o /tmp/p03-sensor-fusion-tests
/tmp/p03-sensor-fusion-tests
```

**Host verification:** passed with GCC 12.2.0 in the Arena environment, including a run with AddressSanitizer and UndefinedBehaviorSanitizer. Expected output:

```text
P03 synthetic host-unit tests passed (not physical RSLK test data)
```

## Covered behavior

- Two fresh, agreeing sources produce a fused midpoint.
- The maximum sample age and inter-source time-skew limits are inclusive; stale and future timestamps are rejected.
- Excessive inter-source skew uses only the newer source and marks the estimate degraded.
- Disagreement yields an invalid/uncertain estimate rather than silently selecting a source.
- A single fresh source is degraded, and an unknown landmark cannot override a usable encoder input.
- No fresh source yields an unknown estimate; duplicate route-anchor IDs invalidate configuration.

## Limits and next verification

The anchor map, measurements, and timestamps in the test are fabricated fixtures, not calibration data or route truth. These tests establish only the portable function's behavior under those fixtures. They do not establish sensor availability, board compatibility, units, timing, accuracy, safety, target compilation, or physical performance. Hardware integration remains gated by exact RSLK/sensor identification, verified interfaces and power, an already-available compatible toolchain, and P01 safety gates.
