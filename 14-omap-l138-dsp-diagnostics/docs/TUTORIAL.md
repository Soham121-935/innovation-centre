# P14 — Conditional Identification Tutorial

1. Read the physical kit label and board revision; distinguish TMDSLCDK6748 from TMDSLCDK138 or other EVM.
2. Inventory included accessories physically: power supply, micro-USB/SD/media, audio cables, microphone/source, emulator. Do not assume TI guide box contents are still present.
3. For an LCDK match, verify the 14-pin JTAG requirement. SPRUIL2A states no onboard emulator; if no compatible external emulator is in supplied stock, stop—no purchase.
4. Confirm matching existing host computer, CCS/Processor SDK and software license. Do not download/install.
5. Identify a safe audio source/transducer already in stock. The board's line/mic input connector alone is not an input signal; do not connect unknown sources or machinery.
6. Review exact codec/input range/sample-rate/power documents before any connection. If source or signal levels are unknown, stop.
7. If every gate passes later, begin with a known safe signal; verify sampling/clipping before feature extraction. No machine fault or safety-control test.
