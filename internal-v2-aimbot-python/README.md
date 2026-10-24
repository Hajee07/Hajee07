# One-file Python aim translation and HD-Player process attachment

Download `nova_aimbot_recovered.zip` and extract `nova_aimbot_recovered.py`. Python3.10+64-bit on Windows, standard library only.

```console
python nova_aimbot_recovered.py --list-hd-player
python nova_aimbot_recovered.py --attach-hd-player --modules
python nova_aimbot_recovered.py --attach-hd-player --pid 1234 --modules
```

Use an actual PID from the listing when multiple emulator instances exist.

The file enumerates exact HD-Player.exe matches, verifies the selected process image, opens a query/read handle, lists Windows modules and provides `HDPlayerProcess.read_process_memory(host_address,size)`. It handles process exit, access denial, partial reads and handle cleanup. Twelve portable layout/mock-WinAPI checks passed; live Windows/HD-Player was not tested.

The four previously translated aim routines are unchanged;41 modeled x64 comparisons remain applicable to those core definitions. This does not translate all151 native analysis routines or connect a complete game backend.

**Full game memory mapping and native engine integration remain unresolved.** Original native code uses BstkVMM.dll exports(PGMPhysRead, VMMGetCpuById, PGMPhysGCPtr2GCPhys, PGMPhysSimpleWriteGCPhys), live VM/CPU context and cached state. Analysis addresses, Windows host virtual addresses and Android guest addresses are distinct. No guessed mapping or fake VM context is substituted. Guest-memory reads/writes, native rotation and state-cache integration still require a real NativeBackend adapter.

An attachment-success message only confirms the process handle. It reports `native_game_backend_connected:false`. This is not a fully working standalone Aimbot. The BlueStacks host version/build and runtime evidence are needed for further compatibility/recovery work.
