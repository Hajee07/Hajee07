# NOVA INTERNAL V2 — recovered Aimbot code

This package contains **151 linked native analysis routines** exported as inferred C-like pseudocode and x64 assembly from the embedded DLL in the supplied `NOVA XITERS INTERNAL V2.exe`. It includes actual aim-related target-selection/math routines, mode dispatch, key handling, scan/toggle paths, UI and shared helpers. It does not mean151 separate Aimbot features.

**Not100% original C++ source. Not a standalone compilable project.** Original names, structures, class definitions, headers and exact types are unavailable. Decompiled output includes inferred types, unresolved calls, partial-control-flow warnings and shared/adjacent code. No Windows, emulator or game execution was performed. Export success means the tool emitted pseudocode, not that the original source or live behavior was proven.

தமிழில்: `AIMBOT-RECOVERED-PSEUDOCODE.c` file-ல் மீட்ட functions ஒன்றாக உள்ளன. `native/` folder-ல் ஒவ்வொரு function-க்கும் தனி `.c`, `.asm` files உள்ளன. Original C++ project/build files முழுமையாக மீட்கப்படவில்லை.

## Read these first

| Function address / file stem | Recovered evidence |
|---|---|
| `1800acfd0` | Aimbot toggle/mode dispatch. Writes mode0/1/3 state bytes; preserves the original toggle behavior. |
| `180073610` | Mode0-state reader: hotkey gate, cached candidate traversal, target filtering, distance/projection calculations and associated native operations. |
| `1800731b0` | Mode1-state reader: mouse-button gate, candidate filtering, projected/FOV distance selection and associated native operations. |
| `180067e80` | Projection-related helper used by the selection routines. |
| `1800ad260` | Native path associated with Aimbot enabled/disabled and scan-failure messages. |
| `1800a8dd0` | Scan-related routine associated with the Aimbot status string. |
| `1800ad030` | Helper called from that scan/enable path. |
| `1800ad6a0` | Key/control orchestration containing aim-toggle/type handling plus other feature controls. |
| `1800b1990` | Shared panel renderer containing Aimbot, type, FOV, filtering and keybind controls, alongside other menus. |

The mode3 flag write is resolved; a direct RIP-relative read of that byte was not found in the inspected text. Its complete execution mapping remains unresolved. Other indirect references, packed/wide state accesses and external runtime behavior are not ruled out. The original UI/type-index behavior is retained rather than filled in with invented aiming code.

## Files and limitations

- `AIMBOT-RECOVERED-PSEUDOCODE.c`: all151 exported C-like routines together for reading. It is not a single compilable translation unit.
- `native/<address>.c/.asm`: separate pseudocode and disassembly. Address names are analysis labels, not original developer names.
- `native/STATUS.tsv`: per-function export completion, instruction count and tool errors.
- `QUALITY.json`: warning comments retained per function. Read the original warning headers in each source file.
- `aim-state-references.json`: concrete instruction references linking the controls/mode flags to the native routines.
- `PROVENANCE.json` and `SHA256SUMS`: exact inputs and artifact integrity.
- `RecoverAim.java` and trace scripts: analysis tooling. Scripts retain workspace paths as provenance and require adaptation to your local layout, Ghidra, Python and Capstone. The large Ghidra distribution and original EXE/DLL are not bundled.

These are recovered original-binary behaviors, not replacement demo algorithms. Some dependent SDK/Windows/math/runtime functions remain calls or pointers. Full class layouts, cached-state producers, every indirect dependency and current game-version compatibility are not established. A complete buildable Aimbot source project or fully working game integration cannot be claimed from these exports.

The input is the original uploaded EXE, before the login-navigation patch. Its embedded DLL SHA256 is recorded. The subsequent login patches affect navigation/init; this package identifies the original aim routines rather than presenting the login patch as recovered gameplay source.
