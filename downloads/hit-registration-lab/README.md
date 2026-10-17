# Owned hit-registration laboratory

A runnable C#/.NET 8 external console client, local HTTP authoritative server and browser test game. The server owns the mannequin geometry and firing origin, recomputes ray collisions and awards classifications using its configured rule. A client `Head` claim never overrides geometry. With `convert`, every **validated collision** is awarded Head; misses, occlusion and replayed events remain rejected.

This implements the requested six-region experiment in an independently controlled environment. It does not connect to Free Fire/Free Fire MAX, BlueStacks, their memory, game protocols or production servers. It cannot establish their server implementation or guarantee body-to-headshot conversion there. See [feasibility and source review](FEASIBILITY.md), [architecture](ARCHITECTURE.md), [verification](VERIFICATION.md), [roadmap](ROADMAP.md).

## Windows 11 build and use

Install Microsoft's **.NET 8 SDK x64** from https://dotnet.microsoft.com/download/dotnet/8.0 (SDK for compilation, runtime alone for the prebuilt app). Extract the entire ZIP into a normal folder. Open PowerShell **in that folder**:

```powershell
dotnet --info
dotnet build .\HitLab.csproj -c Release
dotnet run --project .\HitLab.csproj -c Release --no-build -- test
dotnet run --project .\HitLab.csproj -c Release --no-build -- environment
```

Start the server in that window:

```powershell
dotnet run --project .\HitLab.csproj -c Release --no-build -- server --policy geometric
```

Open `http://127.0.0.1:5088/` in your local browser. Click each colored sphere. The displayed receipt preserves geometric region and awarded region separately. The dropdown deliberately lets the client make an incorrect claim; the server reports that disagreement. The canvas is an approximate perspective view, with exact server sphere-ray testing. It is a static test game, not a full animated Unity title.

In another PowerShell window in the same folder:

```powershell
dotnet run --project .\HitLab.csproj -c Release --no-build -- client --report geometric.json
```

Stop the server with Ctrl+C, restart with conversion, and run the client again:

```powershell
dotnet run --project .\HitLab.csproj -c Release --no-build -- server --policy convert
# Second window:
dotnet run --project .\HitLab.csproj -c Release --no-build -- client --report converted.json
```

All six accepted intersections should have `awardedRegion: Head`; `geometricRegion` still identifies the actual sphere. Repeat with `server --policy convert --wall` and shots should be rejected as `OCCLUDED`. `--delay-ms 50` injects server response delay; report RTT includes this delay. `--port 5089` and client `--url http://127.0.0.1:5089/` select another local port.

The ZIP's `app/` directory also contains a framework-dependent portable Release build. With .NET 8 runtime installed, `dotnet .\app\HitLab.dll test` or `dotnet .\app\HitLab.dll server --policy convert` runs it without compilation. This build ran on Linux; Windows execution still requires verification. No third-party NuGet packages are used. `NuGet.Config` clears external feeds for offline restore with an installed SDK.

`Start-Lab.ps1 -Mode server -Policy convert` builds and launches from any current directory using its own script folder. Modes: `test`, `environment`, `client`, `server`. It requires the SDK.

## Debugging

Open `HitLab.csproj` in Visual Studio 2022 with .NET 8 tooling or VS Code's C# tools. Break at `Authority.Submit`, `Geometry.First`, and the HTTP handler. Run separate server/client processes. Preserve JSON receipts and process command lines for each experiment. A server restart creates new sessions; old tokens are rejected. Never interpret client UI text as server acceptance: inspect the returned receipt.

If Windows HttpListener reports Access Denied, run the server from an Administrator PowerShell for this local test, or use an existing authorized URL reservation. No reservation is created by the application. Port-in-use means stop your prior lab server or choose another port. A browser click smoke test on Windows is pending; the automated suite exercises the actual HTTP page, sessions, shot endpoint, client and report generator on Linux.

## Scope and limits

Static server scene, one shooter origin, six sphere regions, hitscan adjudication; ballistic approximation is offline math only. No skeletal animation, dynamic lag compensation, weapons, health progression, authenticated accounts, moving target history or production rate control. Sequence replay protection and a five-minute issued-session lifetime are lab safeguards, not a production networking security design. The HTTP server handles requests serially. It binds only IPv4 loopback; no CORS, public deployment or emulator adapter is supplied.

The current camera-resume edits from the earlier task are separate and are not part of this package. No previous camera probe or pinned baseline was modified for this lab.
