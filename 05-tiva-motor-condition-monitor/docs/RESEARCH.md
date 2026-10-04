# P05 — Research Plan

**State:** early conditional research. TIVA model and motor/measurement system are unverified; no code/data/results.

## Question

If a compatible motor/encoder setup already exists in supplied stock, can a simple speed-residual and freshness gate flag a persistent deviation or missing feedback without falsely diagnosing the cause?

## Approach

Use only a documented, in-stock plant and its verified feedback. Establish a healthy baseline at safe operating points, repeat runs, then inject faults only in software/log replay (e.g., drop an encoder event in a test harness) after implementation. Do not physically stall, load, damage, or alter the motor. Compare an unconditional speed estimate with a freshness/persistence gate. A residual is anomaly evidence, not a root-cause diagnosis.

## Hypothesis / metrics

A persistence threshold plus valid-feedback check will reduce transient false flags relative to a single-sample threshold while increasing detection latency. Measure speed-estimate error, baseline residual distribution, false flags/hour, software-injected dropout detection rate/latency, and repeatability. Set numeric thresholds after verified data.

## Blockers and limitations

TIVA family, motor/driver, compatible interface, sensor, and data-acquisition tools are not identified. No current/vibration signal is confirmed; predictive-maintenance claims are out of scope. If gates cannot be closed using supplied inventory, record blocker and continue to P06.

References: TI [TM4C123G LaunchPad User Guide](https://www.ti.com/lit/pdf/spmu296), [TM4C123G product page](https://www.ti.com/tool/EK-TM4C123GXL), and [supplied inventory](../../HARDWARE_INVENTORY.md).