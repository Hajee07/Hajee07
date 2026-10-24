# Single-file Python translation of recovered aim routines

Download `nova_aimbot_recovered.py`. It uses only the Python3.10+ standard library and contains four translated routines: mode dispatch, world-to-screen projection, mode0 worker and mode1 worker. These are translations of recovered native branches, not all151 exported analysis routines.

An explicit `NativeBackend` must provide state, key input, native guest-address resolution/read/write and rotation output. No live process/game connection is bundled. The file documents exact method contracts and analysis-address mapping requirements. Running it directly prints its documentation and available functions; it does not pretend to attach to a game.

41 comparisons against original x64 machine code passed with modeled key/cache/engine/math dependencies, including the unresolved rotation-helper adapter. See `VALIDATION.json`. Live Windows/game behavior and original-source identity are unverified.
