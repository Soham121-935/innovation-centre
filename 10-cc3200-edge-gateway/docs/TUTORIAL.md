# P10 — Conditional Tutorial

1. Inspect both CC3200SF LaunchPads: record silkscreen/revision, MCU marking, condition and supplied cable. Do not assume Rev3.2/Rev4.1.
2. Inspect sensor area on each board. Verify BMA222 population; use TMP008 only if U6 is populated. TI notes U6 can be DNP on newer builds.
3. Confirm matching CC3200 SDK/toolchain, computer and USB cable are already available. Do not download/install; if absent, stop and proceed to P11.
4. Review exact board guide for USB power/debug, sensor I²C jumpers, SOP/JTAG and Wi-Fi settings. Do not change jumpers or expose signals based on a generic pin map.
5. Obtain approval for an isolated local Wi-Fi test. Do not join institutional/public networks; no internet is needed.
6. Only after gates pass, characterize sensors on a stationary board and local LED/status. If supported by existing software, use the second CC3200 as peer to test sequence/freshness and timeout/recovery.
7. Record actual data and board/software versions. No browser, calibrated accuracy, or remote/cloud claim.
