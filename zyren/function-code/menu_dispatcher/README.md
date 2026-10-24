# NX recovered menu handlers in Python

This directory is the earlier menu-only translation. In this combined package,
`../helpers/` adds a recovered Unix transport and JNI helpers, and
`../native_server/` contains newly recovered native dispatch pseudocode.
Read the top-level README for the current recovery status.

51 separate functions translate the supplied recovered native menu dispatcher:
50 switches and one height slider, across AIM, ESP, LOOK, BRTL and SET.

Each control has its own file under `buttons/`. `all_functions.py` contains
all 51 functions and their runtime support in a single file. The actual labels,
native option IDs, source references and recovery status are in `BUTTONS.md`,
`button_mapping.csv` and `button_mapping.json`.

**This translates the recovered menu handlers. It does not restore the full
protected Java application or implement the game-side features.** The supplied
archive itself describes a partial, modeled recovery. Its report is retained
under `evidence/INPUT-RECOVERY-REPORT.md`.

## Read and inspect the code

Python 3.10 or newer; the translated handlers use only the standard library.

```bash
python all_functions.py --list
python all_functions.py --show 1
python all_functions.py --show 2
```

Numbers 01–51 follow the recovered menu order. They are not the native option
IDs: button 01 is Enable All / ID 102; ESP Line is button 08 / ID 1.

Optional request inspection, using an explicitly analysis-only recording backend:

```bash
python all_functions.py --trace 1 --value 1
python all_functions.py --trace 2 --value 1
python all_functions.py --trace 37 --value 1 --initial-toggle-byte 0
```

The last command explicitly assumes a previous Fly Lock byte of zero for that
trace. The actual initial byte in the original application has not been proven.

For modular use, import functions from `all_buttons.py` and support classes
from `runtime.py`. Request handlers require an explicit Transport implementation;
without one, they raise `NativeBackendRequired`. RecordingTransport records
requests for analysis and never connects to a game. This menu directory does not connect to Android/JNI or BlueStacks by itself.
The combined package supplies the recovered local Unix client adapter under
`../helpers/`; a compatible live server and its runtime reachability remain
unverified. Complete hooked gameplay behavior remains unresolved.

## Recovered behavior preserved

- Enable All / 102 changes one local flag and sends 102, then 3. It does not
  set every ESP flag in this dispatcher.
- Aimkill MultiTarget / 110 sends 1049, then 1048, then float command 104.
  Its float and local value are 2000.0 when the argument equals 1, else 0.0.
  No aiming algorithm has been invented in its place.
- ESP Line, Box, Health, Weapon Icon, Distance and Draw FOV update separate
  local flags. ESP Grenade also sends a request.
- Fly Lock and Tp Anywhere ignore the argument and XOR their previous local
  byte with 1. Unknown initial state raises `UnknownInitialState`.
- Rise Up / 111 sends command 5657. Downkill / 5658 sends command 504.
- Joystick Speed / 114 and Speed Run / 507 send 507 and treat any nonzero
  32-bit argument as enabled. Most other switches require exactly 1.
- Look presets 7102–7121 send requests only for value 1. Switching one off
  does not send an invented reset request.
- The height slider converts a signed 32-bit integer to float32. The native
  handler has no clamp; its recovered UI declares a range of 15–100 M.
- Show Keybinds / 6002, Enable Keybind System / 6000 and Clear All Keybinds /
  6001 have no action in the recovered native dispatcher. Their protected Java
  behavior remains unavailable; the corresponding functions say so explicitly.
- Show Match Timer / 6003 changes a local display flag. It does not invent a
  match timer or start a new countdown.

Addresses such as 0x100E1020 are identifiers in the supplied analysis snapshot,
not live BlueStacks addresses. `MenuRuntime.memory` is a Python byte map, not a
process-memory accessor. It also does not implement the Android drawing/render
loop that consumes the local flags. The native packet fields and length framing
are represented. The newly recovered endpoint is documented in `../helpers/`;
authentication, game integration and unresolved implementations are not guessed.

## Validation

464 comparison cases passed against bounded ARM emulation of the supplied
`Java_com_NovaX_Menu_ChangesID.bin`, with zero event mismatches. Comparisons cover
all 51 IDs, enable/disable/non-boolean values, signed slider limits, toggle
starting bytes, and successful/failed sends. Tests compare exact request bytes,
write locations/values, event order and conditional reply reads. Supporting native
I/O and memory clearing are modeled; no game or app initializer is executed.

The reproducible oracle and results are in `validation/`. To rerun:

```bash
python -m pip install -r validation/requirements.txt
python validation/validate_against_arm.py
```

This establishes consistency with the supplied recovered dispatcher under the
documented test conditions. It does not establish original-source identity,
live Android behavior, visual rendering or functioning gameplay features.

The earlier menu translation used NX-Recovered-Code-20261023.zip; its input
and dispatcher hashes remain in `PROVENANCE.json`. The combined package also
independently unpacks both native libraries from the original APK. The larger
uploaded recovery ZIP was not transferred, but is no longer required for those
two recovered native memory images.
