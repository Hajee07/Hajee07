#pragma once
#include <cstddef>
#include <cstdint>

namespace bridge {
struct Address {
    std::uint64_t flat;
    std::uint64_t offset;
    std::uint16_t selector;
    std::uint16_t flags;
};
static_assert(sizeof(Address) == 24 && offsetof(Address, flags) == 18);
struct InfoHelper {
    void (*print)(const InfoHelper*, const char*, ...);
}; // Only the verified first member is accessed; the host owns the full helper.
using Handler = void (*)(void*, const InfoHelper*, const char*);
struct Api {
    int (*add)(void*, const char*, const char*, Handler, void*);
    int (*remove)(void*, const char*);
    Address* (*physical)(void*, Address*, std::uint64_t);
    int (*read)(void*, std::uint32_t, const Address*, void*, std::size_t);
};
struct State { void* uvm{}; Api api{}; bool active{}; };
constexpr std::uint32_t kVersion = 0x60001;
constexpr char kName[] = "headbridge";
constexpr int kInvalid = -2;
int initialize(State&, void*, const Api&, std::uintptr_t);
int terminate(State&, void*);
void info(void*, const InfoHelper*, const char*);
}
