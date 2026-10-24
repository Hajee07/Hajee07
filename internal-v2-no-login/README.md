# NOVA XITERS INTERNAL V2 — login screen skip build

Modified copy of the user-supplied Windows x64 EXE. **Full Windows launch and application/game operation have not been tested.** This Linux workspace has no Windows runtime. The binary was inspected statically; bounded instruction snippets were checked under Unicorn without calling Windows APIs or authentication services.

## What changed

Five fixed-size code patches, totaling22 changed bytes:

- The launcher initializes its existing current/target UI page to1 (main/product selection) and the same UI success byte used by its normal success path. Its existing fade animation brings the initially zero alpha to visible. The identified login-page saved-key handling and login worker are skipped by this initial navigation.
- The embedded panel skips its identified startup authentication-init call and jumps past its login rendering/worker block to its existing main panel. Window initialization and the once-guard release remain intact.

This changes local navigation and known authentication paths in the supplied binary. No user key is generated, recovered or submitted. Other preexisting program behavior, dependencies and indirect runtime paths have not been comprehensively verified. Existing text strings/authentication library code remain in the file; the patched navigation skips the identified login paths.

## Download and run

The Windows executable is `NOVA-XITERS-INTERNAL-V2-no-login.exe`. Extract it if you downloaded the ZIP, then open that file on Windows. This is a Windows host EXE, not an Android APK; it cannot be installed inside an Android instance.

The original upload is preserved locally and is not overwritten. If this build still fails to open, its actual Windows error/crash evidence is needed to diagnose that separate failure; this package does not establish all preexisting startup or game-integration issues as fixed.

## Verification

- Original EXE SHA256: `fb70eb9987a6a2f8a728b0eb8664c39458eafe2b566035f71808edfee4c065a0`.
- Modified EXE SHA256: `069d76f5392843bb99ce034a1f8a4de6f8b714f8c94bef16995ff13fc88b7297`.
- Size unchanged:39,441,920bytes. Only22bytes differ, within the five reviewed ranges.
- Outer/embedded PE headers and resource sizes remain intact; the original had no Authenticode signature.
- Eight checks of actual output bytes and modeled constructor/gate/init behavior passed, plus independent binary-diff review. These are not full Windows/runtime tests.

`PATCHES.json` records every byte replacement and purpose. `NOVA-XITERS-INTERNAL-V2-no-login.validation.json`, `ACTUAL-OUTPUT-VALIDATION.json` and `INDEPENDENT-REVIEW.json` retain the evidence.

To reproduce from the exact original EXE with Python3:

```bash
python3 build_no_login.py "NOVA XITERS INTERNAL V2.exe" PATCHES.json "NOVA-XITERS-INTERNAL-V2-no-login.exe"
```

The build script checks the original hash, every expected instruction byte and unchanged file size. It does not execute the EXE or contact licensing services.
