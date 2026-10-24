# ZYREN — recovered APK function code

Recovered from the supplied **NX AIMKILL PVT 1.2.apk** and the supplied smaller recovery ZIP. Prepared 2026-10-24. No Windows EXE was provided; this package concerns that Android APK.

**This is partial recovery, not 100% original source and not a complete rebuildable project.** The Python files translate recovered native behavior; they are not Python source extracted from the APK. C files are inferred decompiler pseudocode, with inferred types and retained warnings. No app/game was launched in Android or BlueStacks during validation.

தமிழில்: ஒவ்வொரு button-க்கும் தனி code file உள்ளது. Request அனுப்பும் code-யும், கிடைத்த native dispatcher code-யும் சேர்த்துள்ளோம். முழு gameplay algorithm, protected Java source, வேலை செய்யும் முழுமையான app project இன்னும் மீட்கப்படவில்லை.

## Start here

| What you need | File or directory |
|---|---|
| One readable file per control: Python handler + available native server case | `per_button_code/button_01_*.txt` through `button_51_*.txt` |
| The 51 separate Python handler modules | `menu_dispatcher/buttons/` |
| All 51 handlers together, with inspection commands | `menu_dispatcher/all_functions.py` |
| Labels, option IDs, exact request IDs, source lines and unresolved behavior | `helpers/PER-CONTROL-IMPLEMENTATION.md` and `.json` |
| `LockPlayer`, `getEnemyList`, `getMatchTimerStatus` Python translations | `helpers/lock_player.py`, `get_enemy_list.py`, `get_match_timer_status.py` |
| Native request dispatcher, text-command parser and two large initializers | `native_server/1012d110.c`, `10189534.c`, `1010e708.c`, `10111bfc.c` |
| Main thread's 11,047 disassembled instructions and 76,944 Ghidra P-code operations | `native_server/thread1/10177c20.asm` and `.pcode` |
| Two freshly recovered native analysis memory images, original libraries and replay script | `unpack/` |
| Earlier supplied static native decompilation, quality flags and reports | `inherited_native_analysis/` |
| Visible loader Java/smali and the preserved encrypted/protected Java trailer | `visible_java/` and `protected_java/` |
| Hashes, comparison results, download checks and reproduction evidence | `SHA256SUMS`, `validation/`, and helper validation JSON files |

## What the control recovery establishes

There are **51 recovered controls**: 50 switches and one height slider. **41 controls have corresponding recovered native request-dispatch cases**, covering 43 distinct menu request IDs. With the separate `LockPlayer` request, the native map has 44 cases. The other controls are seven local display flags and three keybind options that fall through in the visible native dispatcher; their protected Java behavior remains unknown.

A dispatcher case may only update a state byte or numeric variable. Finding that case does **not** establish the full code that performs the named gameplay effect. Source snippets, resolved snapshot addresses and limitations are recorded per control. In particular, the original client/server numeric interpretation differs for request IDs 104 and 5660; the original behavior is preserved and the discrepancy is documented in `native_server/request_field_instruction_checks.json`.

The three JNI helper translations preserve concrete recovered behavior:

- `getEnemyList`: request dimensions 1920×1080, fixed response layout, alternating name / unsigned 64-bit ID strings, and native NULL represented as Python `None`.
- `LockPlayer`: 32-byte command 525 with the target ID at offset 24 and a conditional response read. This wrapper is not a standalone target-lock algorithm.
- `getMatchTimerStatus`: a signed **int[2]**, read from two native globals; no invented countdown. Response-to-global assignments are included separately.

Python bounds, timeout, EOF and encoding checks added for safe use are identified in the helper documentation.

## Native recovery and transports

Both library DT_INIT routines were emulated from the original packaged ARM ELF files using bounded Unicorn emulation with modeled imports/syscalls. Both returned successfully in that model. Replaying the saved recovery script produced byte-identical memory images; eight exported menu JNI bodies also match the supplied recovered machine-code evidence. These images are **analysis snapshots**, not rewritten loadable shared libraries. Later constructor emulation stopped on an unresolved indirect call; complete real Android initialization was not established.

The fresh core analysis recovered high-level pseudocode for the request dispatcher, a separate text-command thread and two large Thumb initializers. The main hook thread timed out in high-level decompilation at both 90 and 180 seconds. Its assembly and P-code are retained, including two unresolved instruction addresses. First-pass/P-code completion does not mean original C source was recovered.

The menu transport is a length-framed **local abstract Unix socket**. `helpers/local_unix_ipc.py` is its explicit client adapter, requiring a compatible server in the same relevant Linux/Android namespace. It does not automatically connect from Windows into BlueStacks.

A separate core text-command thread contains an **AF_INET/SOCK_STREAM listener on 0.0.0.0:21405** and 33 recovered command literals. Its static parser and state-write mappings are supplied; runtime reachability is unverified. It is not a recovered HTTP code-download service. No plaintext main-code download URL was established by the inspected data; encrypted or runtime-generated URLs remain possible.

## Inspection and validation

Python 3.10+ is sufficient for inspection and the standard-library helper checks:

```bash
python3 menu_dispatcher/all_functions.py --list
python3 menu_dispatcher/all_functions.py --show 1
python3 helpers/validate_helpers.py
python3 helpers/test_local_unix_ipc.py
python3 helpers/test_menu_runtime_integration.py --handlers-dir menu_dispatcher
```

The Unix tests use a synthetic local server. They do not contact a game. On systems supporting Linux abstract Unix sockets, ten framing/transport checks and one Enable All integration check passed.

For bounded ARM comparisons, install `validation/requirements.txt` in your own virtual environment, then:

```bash
python3 helpers/verify_wrappers_against_arm.py --snapshot unpack/libNOVA_MENU.so.dt_init_memory.bin
python3 menu_dispatcher/validation/validate_against_arm.py
```

Twelve fresh ARM/JNI wrapper comparisons and 464 menu-dispatch comparison cases passed under documented models. Ten crafted helper byte-vector checks also passed. These check exact bytes, values and call behavior under the models; they do not prove live gameplay, Android rendering or app startup. `validation/NATIVE-UNPACK-REPLAY.json` records byte-identical recovery replay; the original recovery script can be run in a scratch copy of `unpack/` after reviewing its model.

Earlier public APK/ZIP links were downloaded and checked against their recorded hashes. The earlier APK could be reproduced byte-for-byte from the downloaded build recipe; this is packaging reproducibility, not an app-launch result. This delivery does not contain a newly runtime-verified APK.

## Still missing

The protected `MainActivity`/menu Java bodies, complete high-level main hook thread, complete runtime state and full gameplay implementations remain unresolved. The preserved 781,311-byte VBPD trailer is protected data, not decrypted application source. Original comments, exact original types/names, build configuration and original source identity cannot be reconstructed merely from successful pseudocode output.

No 100% recovery or fully working ZYREN rebuild is claimed. A working Android runtime capture or original unprotected source would be needed to pursue the missing protected code and verify actual startup. The larger uploaded ZIP was not read because of the 32 MiB transfer limit; the two native memory images in this delivery were independently recovered from the original APK.
