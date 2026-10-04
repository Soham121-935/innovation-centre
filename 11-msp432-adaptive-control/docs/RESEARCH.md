# P11 — Research Plan

**State:** requirements-only; physical plant and software are absent/unidentified. No implementation/simulation/result.

## Question

For a known, safe, verified plant with varying dynamics, does a constrained adaptation rule improve tracking over a validated fixed PI/PID baseline without violating process limits? Current inventory cannot test this question.

## Required future method

First document plant transfer/step response, sensor units/cadence/noise, actuator range/saturation, constraints, and independent process measurement. Establish repeatable safe baseline with fixed PI/PID. Only then compare one bounded/slow adaptation rule against that baseline, with explicit adaptation freeze, timeout, saturation, and manual safe-state criteria. Do not online-tune an unknown plant or use an LED/MCU self-temperature as substitute plant.

## Proposed metrics

Tracking IAE/RMSE, overshoot, settling time, control effort/saturation, repeatability, stability/fault events, and constraint violations. Targets require measured plant limits and a safe approved test procedure.

## Current blocker / references

Only MSP432P401R boards are listed; no plant, actuator, process sensor, reference, computer, or simulator is identified. No dependencies should be purchased or borrowed. References: [TI LaunchPad](https://www.ti.com/tool/MSP-EXP432P401R), Åström & Hägglund, *Advanced PID Control*, and Slotine & Li, *Applied Nonlinear Control*.