# ZYREN recovery and binary rebuild

## New function-code recovery — 2026-10-24

[Download the recovered function-code ZIP](function-code/ZYREN-Actual-Function-Code.zip) or [read its current recovery status](function-code/README.md).

51 controls now have separate code files. 41 are mapped to inferred native request-dispatch cases; separate JNI helpers and two original-APK-derived native memory images are included. The large main thread has assembly/P-code but no recovered high-level C. Protected Java, full gameplay code and live Android startup remain unresolved. This is not 100% original source or a newly verified working APK.

The older rebuild/archive described below remains available. Its earlier request for native snapshots from the larger ZIP has been superseded for the two menu/core libraries: fresh snapshots were independently recovered from the original APK. Historical runtime evidence from the unavailable larger ZIP was not obtained.

This package contains every original APK ZIP entry, the available recovered
code, audit evidence and a tested, repeatable ZYREN rebuild recipe.

**The branded APK has been rebuilt and structurally verified. Full original
source recovery and successful Android/BlueStacks startup are NOT established.**

## What is included

- `original/NX-original.apk`: the original, unchanged APK.
- `original_apk_entries/`: all 159 original packaged files, with independently
  verified sizes and SHA-256 hashes.
- `recovered_code/`: the 7,943 files actually present in the smaller uploaded
  recovered-code ZIP, copied unchanged. Decompiled pseudocode is not original
  C/C++ source and is not a complete buildable application project.
- `protected_payload/`: the exact 781,311-byte opaque VBPD trailer preserved
  from the original DEX; this is not a decrypted MainActivity/Menu DEX.
- `build/`: tested Python binary resource/manifest patches and rebuild script.
- `branding/zyren-icon.png`: newly generated ZYREN branding artwork.
- `reports/`: original-file audit, actual missing-file inventory, build,
  signatures, AAPT parsing and repeatability results.
- `diagnostics/`: BlueStacks diagnostic collection instructions. This is for
  gathering the missing startup evidence; it is not a root or protection bypass.

The built `ZYREN-rebuilt.apk` is distributed separately from this archive so the
recovered-files ZIP remains smaller than the attachment transfer limit.

## Rebuild scope

The application label and `app_name` string are now **ZYREN**. All three readable
NOVA-branded PNG assets have been replaced with the new ZYREN artwork. The launcher
has `android:exported="true"` for Android 12+ installation requirements.

The package and JNI/class identity remain `com.NovaX`; renaming these without the
missing protected Java/native source would break linkage. Hidden protected menu
titles or native base64 artwork may still carry original branding. Exhaustive
in-app branding has not been verified.

151 original entries outside the five branding/manifest/resource changes and
signature metadata are preserved byte-for-byte, including classes.dex, all
native libraries and protected layouts/payloads. These protected files have been
preserved, not falsely presented as decrypted source.

The rebuilt APK is signed with the exact certificate used by the original APK.
That certificate/key is the publicly distributed AOSP test fixture, verified
against the original. It is not a private production signing key. The earlier
local-repair APK used a different certificate; Android cannot update that repair
installation with this APK. Back up any app data before removing an installed
version if a signature conflict occurs.

## Reproduce the build

Use Linux or WSL with Python 3.10+, Java 17+ and the standard Linux C/C++ runtime.
From this directory:

```bash
python3 build/build_zyren.py
```

The recipe downloads Android Build Tools 35 and the public test-signing fixture
from official Google/AOSP locations, checks pinned SHA-256 hashes with TLS
verification enabled, then writes `output/ZYREN-rebuilt.apk`. No private signing
credentials are requested or stored in this package. Downloaded tools/fixtures
are cached in `.build-cache/`; they are not included in this recovery archive.

To use already installed tools:

```bash
python3 build/build_zyren.py --tools-dir /path/to/android-build-tools
```

The script refuses any source APK whose SHA-256 is not the verified original.
Its output is a reproducible binary rebuild, not a fabricated Gradle/source
project. The recipe was exercised twice with byte-identical results, including
a run using freshly extracted checksum-verified tools.

## What passed and what remains blocked

- APK ZIP integrity, AAPT manifest/resource parsing and ZIP alignment passed.
- APK v1/v2/v3 signatures passed and the original signer identity matched.
- Two builds produced identical APK bytes.
- Original DEX/native/protected payload preservation was verified.
- App startup, rendering and gameplay were not tested on Android/BlueStacks.
  This cloud machine has no Android runtime, KVM or connected device.

The available readable DEX defines four protection/loader classes. The actual
`MainActivity` and `Menu` implementations remain protected. Native pseudocode
also contains unresolved virtualized logic. Existing recovered menu definitions
and handler translations do not supply those missing gameplay implementations.
The known BlueStacks crash has not been established as fixed by this rebuild.

The larger uploaded recovery ZIP could not be transferred because it exceeds
32 MiB. The smaller code ZIP contains only 37 of 345 prior-recovery files. A
high-value subset missing from it is 49 files, about 10.1 MB:

- `native_memory/`
- `loader_analysis/current_android_evidence/`

`reports/NEEDED-FROM-LARGE-ZIP.txt` lists exact paths, expected sizes and hashes.
Providing those folders separately would allow further native/runtime analysis;
it does not guarantee complete source recovery. Original unprotected source or
a successful runtime capture of decrypted loaded DEX is still needed to restore
the protected Java/game implementation reliably.
