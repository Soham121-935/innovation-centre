# Project 02 — Hardware Verification and Research Record

**Record date:** 2026-10-03<br>
**State:** Official documentation reviewed for a conditional Neeuro SenzeBand 2 candidate. No Innovation Center band has been physically inspected or tested.<br>
**Scope:** Use only listed stock. No unlisted hardware, software, account, license, or accessory is assumed or recommended for purchase.

## 1. What the inventory actually says

The supplied inventory lists **“Neuro Sense Band,” quantity 2**. It does not give manufacturer, product name, model number, hardware revision, accessories, condition, charger, host computer, operating system, Bluetooth availability, or SDK/developer access. The provisional reservation of one band to P02 is planning only.

The phrase does **not** establish that the device is a Neeuro SenzeBand or SenzeBand 2. Neeuro documentation below is a research candidate only. No physical serial number or other device identifier has been recorded here.

## 2. Conditional manufacturer candidate: Neeuro SenzeBand 2 / SB-02

The current Neeuro SenzeBand 2 Gold Edition product catalogue identifies model **SB-02** and describes these candidate specifications:

| Feature | Manufacturer-documented candidate specification | Lab status |
|---|---|---|
| EEG electrodes/channels | Seven proprietary dry electrodes; four EEG data channels (forehead and temporal placements) | Unknown; only if physical model matches |
| EEG data | 250 samples/second, 24-bit resolution | Unknown; candidate documentation only |
| Wireless | Bluetooth 5.0 | Unknown; candidate documentation only |
| Other sensors | PPG and accelerometer/gyroscope/magnetometer functions | Unknown; not required for MVP |
| Device power | Built-in rechargeable battery; catalogue specifies Type-C charging | Unknown; inspect actual unit and included accessories |
| Supported device environments | Catalogue lists iOS, Android, and Windows compatibility; the exact application/SDK version still matters | Host and software availability unknown |

**Do not apply these specifications to the lab unit until its label/model matches.** Do not infer raw-signal rate, callback rate, signal quality, classification accuracy, battery condition, or SDK entitlement from a product catalogue.

## 3. Conditional software/interface documentation

Neeuro's public NeeuroOS SenzeBand SDK manual describes (for its supported SenzeBand 2 package/version):

- platform-specific SDK/sample projects for Android, iOS, Windows, and Unity;
- BLE discovery, connection, device authentication, impedance/contact checks, data callbacks, and disconnection;
- standard-package outputs including signal/link status, vendor-derived attention/relaxation/workload outputs, sensor values, and raw/filtered EEG/PPG, subject to the actual package/API;
- a Developer Code issued through vendor registration; its manual says standard SDK authentication requires Internet access to Neeuro's servers.

P02 has **not** been given an SDK package, Developer Code, license, host computer, or network authorization in the supplied hardware inventory. These are not assumed or included in the BOM. If approved access is not already available, custom SDK integration is blocked; do not acquire a substitute.

## 4. Physical identity gate

When a unit is available for supervised inspection, record locally (keep private serial/asset details out of Git):

- [ ] Manufacturer logo and exact printed product/model name.
- [ ] Model number, revision, regulatory markings, and asset tag, if present.
- [ ] Device condition, electrode condition, included parts, and charging accessory.
- [ ] Any user guide/quick-start/manual that shipped with the actual unit.
- [ ] Battery/charge status and prescribed wear/cleaning process from the matching manual.
- [ ] Existing host make/OS, Bluetooth capability, installed vendor app/SDK version, and access status (never store credentials or Developer Code in Git).
- [ ] Whether SDK access/authentication, license, and any Internet permission are already authorized.

**Pass criterion:** physical manufacturer/model is unambiguous; exact matching primary documentation exists; the device is serviceable; and all required host/software/access is already supplied and authorized. If any gate fails, log the blocker and continue to the next project. Do not change assumptions or acquire missing items.

## 5. Interface / pin-map decision

No direct electrical pins or wiring have been confirmed. The candidate SB-02 is documented as a wearable BLE device accessed through NeeuroOS; that does not prove that the lab band has BLE or that the SDK is available. There is no board pin map, voltage rail, GPIO mapping, or supported raw BLE protocol in this record. See [pin-map.md](pin-map.md).

Do not connect the band to an MCU/BoosterPack, scan undocumented BLE characteristics, or bypass device authentication. Only the matched, officially documented host interface may be used.

## 6. Safety, privacy, and feasibility gate

- The candidate manufacturer says the product is not a medical device and must not be used to diagnose or treat a medical condition.
- No mental-state or EEG output is treated as intentional motor control. Initial P02 output is display-only and requires a separate human confirmation.
- Human signal collection requires informed consent, an approved privacy/retention plan, and institutional ethics review where applicable.
- Do not store raw EEG/PPG, names, faces, personal identifiers, device serials, credentials, or vendor codes in Git.
- If fit/condition, official instructions, consent, data approval, host, access, or connection quality cannot be verified, do not wear/test/collect; record the blocker.

## 7. Source register

1. Neeuro, [SenzeBand product page](https://www.neeuro.com/senzeband) — manufacturer's current product description.
2. Neeuro, [SenzeBand 2 Gold Edition product catalogue](https://www.neeuro.com/hubfs/20260414_SB2_Gold_Product%20Catalogue_EN.pdf?hsLang=en) — model number and candidate hardware specifications.
3. Neeuro, [NeeuroOS SenzeBand SDK developer manual](https://neeuroos.neeuro.com/manual/index.html) — SDK outputs, platform support, connection flow, and Developer Code/authentication requirements.
4. [Innovation Center supplied inventory](../../HARDWARE_INVENTORY.md) — exact wording/count only; does not identify a Neeuro device.

## 8. Unresolved blockers

1. What manufacturer and model/revision is printed on each listed band?
2. Which parts/accessories and charger are physically included and usable?
3. Is an existing supported host with a compatible OS/Bluetooth interface available?
4. Is the exact vendor app/SDK package already present and authorized?
5. Is an existing Developer Code/license and vendor authentication/network permission available, if required?
6. Can the device provide the documented status/data without unapproved raw-data retention?
7. Does the lab have an approved human-participant consent/privacy procedure?
8. If future RSLK integration is proposed, has P01 been physically verified and released, and is a supported, already-available safe interface documented?

No P02 hardware, software, signal, or robot-integration test has been performed. Do not code or claim capabilities until the relevant gates pass.
