#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"
mkdir -p build
flags=(-std=c++17 -O2 -Wall -Wextra -Werror -pedantic)
"${CXX:-g++}" "${flags[@]}" bridge.cpp tests.cpp -o build/contract-tests
./build/contract-tests
"${MINGW_CXX:-x86_64-w64-mingw32-g++}" "${flags[@]}" -shared -static-libgcc -static-libstdc++ \
    bridge.cpp plugin.cpp -ladvapi32 -Wl,--no-insert-timestamp -o VBoxDbgHeadAimBridge.dll
python3 - <<'PY'
import hashlib,json
from pathlib import Path
p=Path('VBoxDbgHeadAimBridge.dll')
Path('manifest.json').write_text(json.dumps({'plugin':p.name,'sha256':hashlib.sha256(p.read_bytes()).hexdigest(),
    'vmm_sha256':'09fcc9048aaeb610104110a1cf7a533603e423eb681f2e3db61d601869cd095a',
    'abi_version':'0x60001','info_handler':'headbridge'},indent=2)+'\n')
PY
