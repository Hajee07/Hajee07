# ZYREN / BlueStacks diagnostic collector

Prepared by static review in Linux. **This PowerShell script has not been
executed or validated on Windows.** Windows PowerShell 5.1 or PowerShell 7 is
the intended runtime.

1. In the BlueStacks instance that fails, enable its **Android Debug Bridge**
   option manually under Settings → Advanced. Copy the displayed local endpoint
   (for example `127.0.0.1:5555`; your instance may use another port).
2. Close the app normally in BlueStacks so the next launch can reproduce the
   failure. Keep the BlueStacks instance running.
3. From PowerShell in this folder, run:

   ```powershell
   .\Collect-ZyrenDiagnostics.ps1 -AdbAddress '127.0.0.1:5555'
   ```

   If ADB is installed somewhere else, provide its executable explicitly:

   ```powershell
   .\Collect-ZyrenDiagnostics.ps1 -AdbAddress '127.0.0.1:5555' -AdbPath 'D:\BlueStacks_nxt\HD-Adb.exe'
   ```

The script checks common BlueStacks installation paths and then `adb` on PATH.
It accepts only a loopback endpoint (`127.0.0.1` or `localhost` with a port).
It does not change execution policy or automatically enable any setting. If
Windows blocks script execution, keep the block and report the displayed error;
the collector does not need root or security protections disabled.

A new `ZYREN-diagnostics-…` folder is created on the Desktop. An optional
`-OutputDirectory 'D:\Diagnostics'` selects another base folder. Existing files
are not overwritten.

The folder contains:

- ADB version, connection result and selected device state.
- The `com.NovaX` package dump, including any reported ABI/native-library paths.
- CPU ABI and supported ABI list.
- `am start -W` output for `com.NovaX/com.NovaX.MainActivity`.
- The most recent 200 lines from Android's crash buffer, without clearing it.
- `SUMMARY.json`, with each command's real exit code and capture status.

The package/class identity stays `com.NovaX` in the branded binary rebuild
because the protected code and native JNI bindings use that identity.

No files are uploaded, apps uninstalled, data deleted, logs cleared or root
requested. The script starts the selected app; it does not force-stop it.
The recent crash buffer can contain older crashes, so its entries must be
matched to the launch time and package rather than assumed to be new.

Exit codes: **0** = collection completed; **1** = collector/tool/file error;
**2** = the selected ADB device is unavailable; **3** = partial collection or
an error reported by the launch/package checks. A zero collector exit code
does not mean the app opened successfully or that its features work.

For diagnosis, share the new capture folder's files with the APK rebuild task.
