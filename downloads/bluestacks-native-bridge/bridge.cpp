#include "bridge.hpp"
#include <cstdio>
#include <cstring>
#include <limits>

namespace bridge {
namespace {
bool space(char c) { return c == ' ' || c == '\t' || c == '\r' || c == '\n'; }
void skip(const char*& p) { while (space(*p)) ++p; }
bool word(const char*& p, const char* expected) {
    const auto n = std::strlen(expected);
    if (std::strncmp(p, expected, n) != 0 || (p[n] && !space(p[n]))) return false;
    p += n;
    skip(p);
    return true;
}
bool number(const char*& p, std::uint64_t& value) {
    unsigned base = 10;
    if (p[0] == '0' && (p[1] == 'x' || p[1] == 'X')) { base = 16; p += 2; }
    const char* start = p;
    value = 0;
    for (; *p && !space(*p); ++p) {
        unsigned digit;
        if (*p >= '0' && *p <= '9') digit = static_cast<unsigned>(*p - '0');
        else if (*p >= 'a' && *p <= 'f') digit = static_cast<unsigned>(*p - 'a' + 10);
        else if (*p >= 'A' && *p <= 'F') digit = static_cast<unsigned>(*p - 'A' + 10);
        else return false;
        if (digit >= base || value > (std::numeric_limits<std::uint64_t>::max() - digit) / base) return false;
        value = value * base + digit;
    }
    if (p == start) return false;
    skip(p);
    return true;
}
}

int initialize(State& state, void* uvm, const Api& api, std::uintptr_t version) {
    if (!uvm || version != kVersion || state.active || !api.add || !api.remove || !api.physical || !api.read)
        return kInvalid;
    state.uvm = uvm;
    state.api = api;
    const int rc = api.add(uvm, kName, "Read-only bridge: status, probe, readphys ADDRESS COUNT (1..4096).", info, &state);
    if (rc < 0) { state = {}; return rc; }
    state.active = true;
    return 0;
}

int terminate(State& state, void* uvm) {
    if (!state.active || state.uvm != uvm) return kInvalid;
    const int rc = state.api.remove(uvm, kName);
    if (rc >= 0) state = {};
    return rc;
}

void info(void* user, const InfoHelper* output, const char* arguments) {
    if (!output || !output->print) return;
    auto* state = static_cast<State*>(user);
    if (!state || !state->active) { output->print(output, "BridgeError=INACTIVE\n"); return; }
    const char* p = arguments ? arguments : "";
    skip(p);
    if (!*p || (word(p, "status") && !*p)) {
        output->print(output, "BridgeStatus=READY Protocol=1 ReadOnly=1 MaximumRead=4096\n");
        return;
    }
    // Parse from the original string after trying status.
    p = arguments ? arguments : ""; skip(p);
    bool probe = false;
    std::uint64_t address = 0, count = 1;
    if (word(p, "probe") && !*p) probe = true;
    else {
        p = arguments ? arguments : ""; skip(p);
        if (!word(p, "readphys") || !number(p, address) || !number(p, count) || *p ||
            count == 0 || count > 4096 || address > std::numeric_limits<std::uint64_t>::max() - (count - 1)) {
            output->print(output, "BridgeError=INVALID_COMMAND\n"); return;
        }
    }
    Address source{};
    if (state->api.physical(state->uvm, &source, address) != &source ||
        source.flat != address || (source.flags & 7u) != 4u) {
        output->print(output, "BridgeError=ADDRESS_CONTRACT\n"); return;
    }
    unsigned char bytes[4096]{};
    const int rc = state->api.read(state->uvm, 0, &source, bytes, static_cast<std::size_t>(count));
    if (rc != 0) {
        output->print(output, "%s=FAIL VBoxStatus=%d\n", probe ? "BridgeProbe" : "BridgeRead", rc);
        return;
    }
    if (probe) {
        output->print(output, "BridgeProbe=PASS BytesRead=1 Contents=OMITTED\n");
        return;
    }
    char hex[8193];
    constexpr char digits[] = "0123456789abcdef";
    for (std::size_t i = 0; i < count; ++i) { hex[i * 2] = digits[bytes[i] >> 4]; hex[i * 2 + 1] = digits[bytes[i] & 15]; }
    hex[count * 2] = 0;
    output->print(output, "BridgeRead=PASS BytesRead=%u Hex=%s\n", static_cast<unsigned>(count), hex);
}
}
