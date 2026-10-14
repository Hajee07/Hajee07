#include "bridge.hpp"
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

namespace {
bridge::Handler registered{};
void* callbackUser{};
int hostToken;
int registerRc{}, removeRc{}, readRc{}, readCalls{}, addressFault{};
std::uint64_t lastAddress{};
std::size_t lastCount{};
std::string output;
void require(bool result, const char* message) {
    if (!result) { std::cerr << "FAIL: " << message << '\n'; std::exit(1); }
}
int add(void* uvm, const char* name, const char*, bridge::Handler handler, void* user) {
    require(uvm == &hostToken && std::strcmp(name, "headbridge") == 0, "registration arguments");
    if (registerRc < 0) return registerRc;
    registered = handler; callbackUser = user; return 0;
}
int remove(void* uvm, const char* name) {
    require(uvm == &hostToken && std::strcmp(name, "headbridge") == 0, "removal arguments");
    if (removeRc < 0) return removeRc;
    registered = nullptr; callbackUser = nullptr; return 0;
}
bridge::Address* physical(void* uvm, bridge::Address* address, std::uint64_t value) {
    require(uvm == &hostToken, "address UVM");
    *address = {value, value, 1, static_cast<std::uint16_t>(addressFault == 2 ? 3 : 12)};
    return addressFault == 1 ? nullptr : address;
}
int read(void* uvm, std::uint32_t cpu, const bridge::Address* address, void* bytes, std::size_t count) {
    require(uvm == &hostToken && cpu == 0, "read VM/CPU");
    require((address->flags & 7) == 4 && count >= 1 && count <= 4096, "read bounds/type");
    ++readCalls; lastAddress = address->flat; lastCount = count;
    std::memset(bytes, 0x5a, count); return readRc;
}
void print(const bridge::InfoHelper*, const char* format, ...) {
    char data[9000]; va_list args; va_start(args, format);
    const int count = std::vsnprintf(data, sizeof(data), format, args); va_end(args);
    require(count >= 0 && static_cast<std::size_t>(count) < sizeof(data), "output length");
    output += data;
}
std::string call(const char* command) {
    output.clear(); const bridge::InfoHelper helper{print};
    require(registered != nullptr, "handler exists");
    registered(callbackUser, &helper, command); return output;
}
}

int main() {
    bridge::State state{}; const bridge::Api api{add, remove, physical, read};
    require(bridge::initialize(state, &hostToken, api, 0x60000) < 0 && !registered, "reject mismatched ABI version");
    require(bridge::initialize(state, nullptr, api, bridge::kVersion) < 0, "reject null VM");
    bridge::Api incomplete = api; incomplete.read = nullptr;
    require(bridge::initialize(state, &hostToken, incomplete, bridge::kVersion) < 0, "reject missing symbol");
    registerRc = -44;
    require(bridge::initialize(state, &hostToken, api, bridge::kVersion) == -44 && !state.active && !state.uvm,
            "registration failure leaves no active context");
    registerRc = 0;
    require(bridge::initialize(state, &hostToken, api, bridge::kVersion) == 0, "initialize");
    require(bridge::initialize(state, &hostToken, api, bridge::kVersion) < 0, "reject duplicate init");
    require(call(nullptr).find("BridgeStatus=READY") == 0 && readCalls == 0, "status never reads memory");
    require(call(" \tprobe\n") == "BridgeProbe=PASS BytesRead=1 Contents=OMITTED\n" && readCalls == 1 && lastCount == 1,
            "probe reads exactly one byte and omits content");
    require(call("readphys 0x10 2") == "BridgeRead=PASS BytesRead=2 Hex=5a5a\n" && lastAddress == 16 && lastCount == 2,
            "physical address and bytes survive RPC formatting");
    const int before = readCalls;
    const char* invalid[] = {"writephys 0 1", "probe extra", "status extra", "readphys 0 0", "readphys 0 4097",
        "readphys -1 1", "readphys 0x 1", "readphys 18446744073709551616 1", "readphys 0xffffffffffffffff 2",
        "readphys 0 1 extra", "readphys 0", "readphys 1x 1"};
    for (const auto* command : invalid) require(call(command) == "BridgeError=INVALID_COMMAND\n", command);
    require(readCalls == before, "invalid requests never reach host reader");
    const auto maximum = call("readphys 0 4096");
    require(lastCount == 4096 && maximum.size() == std::strlen("BridgeRead=PASS BytesRead=4096 Hex=\n") + 8192,
            "maximum read fits output");
    require(call("readphys 0xffffffffffffffff 1").find("BridgeRead=PASS") == 0 && lastAddress == UINT64_MAX,
            "last-byte arithmetic does not overflow");
    readRc = -52;
    require(call("probe") == "BridgeProbe=FAIL VBoxStatus=-52\n", "negative read status propagates");
    require(call("readphys 0 2") == "BridgeRead=FAIL VBoxStatus=-52\n", "failed buffer contents never leak");
    readRc = 1;
    require(call("probe") == "BridgeProbe=FAIL VBoxStatus=1\n", "positive incomplete status cannot report pass");
    readRc = 0; const int earlier = readCalls;
    addressFault = 1; require(call("probe") == "BridgeError=ADDRESS_CONTRACT\n", "reject null address result");
    addressFault = 2; require(call("probe") == "BridgeError=ADDRESS_CONTRACT\n", "reject nonphysical address");
    require(readCalls == earlier, "bad address never reaches reader"); addressFault = 0;
    require(bridge::terminate(state, nullptr) < 0 && registered, "foreign VM cannot remove handler");
    removeRc = -22;
    require(bridge::terminate(state, &hostToken) == -22 && state.active && registered, "retain callback state on failed removal");
    removeRc = 0;
    require(bridge::terminate(state, &hostToken) == 0 && !state.active && !registered, "clean shutdown removes handler");
    require(bridge::initialize(state, &hostToken, api, bridge::kVersion) == 0, "reinitialization after cleanup");
    require(bridge::terminate(state, &hostToken) == 0, "second cleanup");
    std::cout << "PASS: lifecycle, bounded reads, failure propagation, and probe output (simulated host).\n";
}
