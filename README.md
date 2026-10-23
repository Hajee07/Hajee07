# APK installation fix

Download [NX-AIMKILL-PVT-1.2-install-fix.apk](NX-AIMKILL-PVT-1.2-install-fix.apk).

The launcher activity now declares `android:exported="true"`, required on Android 12+ for this app targeting SDK 34. App code, native libraries, assets, resources and SDK targets are unchanged.

The APK has been signed with a new local repair certificate. It cannot update an installation signed by the original certificate. Back up app data before uninstalling any previous installation.

APK v1/v2/v3 signatures and ZIP alignment were verified. Installation and app behavior on a physical device have not been tested. The original ARM 32-bit-only native-library limitation remains.

SHA-256: `5e0c1fdca3e05d2c48de5c088542ee737a55059b27cf92aee3aae872561a6488`

## Recovered Python menu handlers

[Download the 51-function Python package](python-buttons/NX-Recovered-Python-Buttons.zip), including individual control files, button IDs, recovered-source references and validation results.

[Single Python file](python-buttons/all_functions.py). The translated menu dispatcher matched the supplied recovered ARM binary in 464 bounded emulation cases. Full protected Java/game-side feature implementations remain unrecovered, and live gameplay has not been verified.
