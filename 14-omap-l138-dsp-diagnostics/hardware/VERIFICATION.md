# P14 — Hardware Verification

Inventory lists one “OMAP-L138 DSP Kit,” exact kit variant and contents unknown. TI SPRUIL2A describes two LCDK variants: TMDSLCDK6748 (C6748 DSP-only) and TMDSLCDK138 (OMAP-L138 ARM+DSP). The physical kit must be identified before using the guide.

For an exact LCDK match, SPRUIL2A documents line-in, line-out, mic-in audio ports, an onboard audio codec/MCASP path and a 14-pin JTAG header. It explicitly states there is no onboard emulator and an external emulator is required. The inventory does not confirm an emulator, microphone, signal generator, audio cable/source, or host computer/toolchain. Kit box contents in TI's guide include a mini-USB cable and micro-SD card, but the generic inventory does not establish those items are present. The input jack alone does not provide a microphone or test signal.

**Blocker:** exact variant, external emulator, matching software/host, and safe signal source/acquisition chain. No code/test; record blocker and finish P14 docs.

Source: [TI SPRUIL2A](https://www.ti.com/lit/ug/spruil2a/spruil2a.pdf), [inventory](../../HARDWARE_INVENTORY.md).