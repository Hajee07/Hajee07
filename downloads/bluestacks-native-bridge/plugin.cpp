#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <wincrypt.h>
#include <cstring>
#include "bridge.hpp"

namespace {
bridge::State state;
SRWLOCK lifecycle = SRWLOCK_INIT;

bool exactVmm(HMODULE module) {
    constexpr char hashText[] = "09fcc9048aaeb610104110a1cf7a533603e423eb681f2e3db61d601869cd095a";
    static_assert(sizeof(hashText) == 65);
    wchar_t path[32768];
    const DWORD length = GetModuleFileNameW(module, path, 32768);
    if (!length || length >= 32768) return false;
    HANDLE file = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                              nullptr, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, nullptr);
    if (file == INVALID_HANDLE_VALUE) return false;
    HCRYPTPROV provider = 0;
    HCRYPTHASH hash = 0;
    bool good = false;
    if (CryptAcquireContextW(&provider, nullptr, nullptr, PROV_RSA_AES, CRYPT_VERIFYCONTEXT) &&
        CryptCreateHash(provider, CALG_SHA_256, 0, 0, &hash)) {
        BYTE buffer[16384]; DWORD count = 0;
        bool readOkay = true;
        for (;;) {
            if (!ReadFile(file, buffer, sizeof(buffer), &count, nullptr)) { readOkay = false; break; }
            if (count == 0) break;
            if (!CryptHashData(hash, buffer, count, 0)) { readOkay = false; break; }
        }
        BYTE digest[32]; DWORD size = sizeof(digest);
        if (readOkay && CryptGetHashParam(hash, HP_HASHVAL, digest, &size, 0) && size == 32) {
            char actual[65]; constexpr char hex[] = "0123456789abcdef";
            for (unsigned i = 0; i < 32; ++i) { actual[2*i] = hex[digest[i] >> 4]; actual[2*i+1] = hex[digest[i] & 15]; }
            actual[64] = 0;
            good = std::strcmp(actual, hashText) == 0;
        }
    }
    if (hash) CryptDestroyHash(hash);
    if (provider) CryptReleaseContext(provider, 0);
    CloseHandle(file);
    return good;
}

template<class T> T resolve(HMODULE module, const char* name) {
    const FARPROC raw = GetProcAddress(module, name);
    T function{};
    static_assert(sizeof(function) == sizeof(raw));
    std::memcpy(&function, &raw, sizeof(function));
    return function;
}
void pinOnCleanupFailure() {
    HMODULE retained = nullptr;
    GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN,
                      reinterpret_cast<LPCWSTR>(&state), &retained);
}
}

// The inspected BlueStacks loader passes FOUR Win64 arguments, unlike stock 6.1.
// The host owns uvm/vtable and keeps them valid for this plug-in's lifetime.
extern "C" __declspec(dllexport) int DbgPlugInEntry(
    std::uint32_t operation, void* uvm, const void* vtable, std::uintptr_t version) {
    if (!uvm || !vtable) return bridge::kInvalid;
    AcquireSRWLockExclusive(&lifecycle);
    int rc = bridge::kInvalid;
    if (operation == 1 && version == bridge::kVersion) {
        HMODULE module = GetModuleHandleW(L"BstkVMM.dll");
        if (module && exactVmm(module)) {
            bridge::Api api{};
            api.add = resolve<decltype(api.add)>(module, "DBGFR3InfoRegisterExternal");
            api.remove = resolve<decltype(api.remove)>(module, "DBGFR3InfoDeregisterExternal");
            api.physical = resolve<decltype(api.physical)>(module, "DBGFR3AddrFromPhys");
            api.read = resolve<decltype(api.read)>(module, "DBGFR3MemRead");
            rc = bridge::initialize(state, uvm, api, version);
        }
    } else if (operation == 2) {
        rc = bridge::terminate(state, uvm);
        // The host loader ignores TERM's return value. Preserve callback code if
        // deregistration failed, rather than leaving an unloaded function pointer.
        if (rc < 0 && state.active) pinOnCleanupFailure();
    }
    ReleaseSRWLockExclusive(&lifecycle);
    return rc;
}
