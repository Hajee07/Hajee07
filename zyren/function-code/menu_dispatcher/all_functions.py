"""Support for the translated, recovered menu dispatcher.

The addresses below identify locations in the supplied analysis snapshot.
They are NOT addresses in a live BlueStacks process. No process is opened.
Native game implementations and an Android/JNI bridge are not recovered here.
"""
from __future__ import annotations

import operator
import struct
from typing import Protocol


SNAPSHOT_CHANNEL = 0x100E1020
MAX_REPLY_BYTES = 0x2960


def u32(value: int) -> int:
    """Reproduce the original 32-bit integer argument."""
    return operator.index(value) & 0xFFFFFFFF


def s32(value: int) -> int:
    number = u32(value)
    return number if number < 0x80000000 else number - 0x100000000


class NativeBackendRequired(RuntimeError):
    pass


class UnknownInitialState(RuntimeError):
    pass


class Transport(Protocol):
    """Caller-provided implementation of the recovered native send/receive calls."""

    def send(self, channel: int, payload: bytes) -> bool: ...

    def receive(self, channel: int, max_bytes: int) -> bytes: ...


class RecordingTransport:
    """Analysis-only transport. Records bytes; it does not connect to a game."""

    def __init__(self, send_ok: bool = True):
        self.send_ok = send_ok
        self.packets: list[tuple[int, bytes]] = []
        self.receives: list[int] = []

    def send(self, channel: int, payload: bytes) -> bool:
        self.packets.append((channel, payload))
        return self.send_ok

    def receive(self, channel: int, max_bytes: int) -> bytes:
        self.receives.append(channel)
        return b""


class MenuRuntime:
    """Byte-addressed state model plus explicit, caller-supplied native backend.

    Pure local handlers update this model. Request handlers require a Transport.
    The model is useful for inspecting the recovered logic; it is not a game
    memory accessor. Initial state is never silently assumed for toggle handlers.
    """

    def __init__(self, transport: Transport | None = None,
                 initial_bytes: dict[int, int] | None = None):
        self.transport = transport
        self.memory: dict[int, int] = {}
        for address, byte in (initial_bytes or {}).items():
            if not 0 <= byte <= 255:
                raise ValueError("Initial bytes must be in 0..255")
            self.memory[address] = byte
        self.events: list[dict] = []

    def read_u8(self, address: int) -> int:
        try:
            return self.memory[address]
        except KeyError:
            raise UnknownInitialState(
                f"Supply the existing byte at snapshot location {address:#x}; "
                "its initial value has not been established."
            ) from None

    def write_u8(self, address: int, value: int) -> None:
        byte = operator.index(value) & 0xFF
        self.memory[address] = byte
        self.events.append({"type": "write", "address": address,
                            "size": 1, "value": byte})

    def write_f32(self, address: int, value: float) -> None:
        data = struct.pack("<f", value)
        for offset, byte in enumerate(data):
            self.memory[address + offset] = byte
        self.events.append({"type": "write", "address": address, "size": 4,
                            "value": struct.unpack("<I", data)[0]})

    def request(self, command_id: int, enabled_byte: int = 0,
                float_value: float = 0.0) -> bool:
        """Reproduce the recovered 32-byte request and conditional reply read.

        Offset 0: little-endian uint32 command. Offset 4: one byte.
        Offset 8: little-endian float32. Other bytes are zero in these handlers.
        FUN_1009d8f4 adds a big-endian uint32 length before writing the payload;
        that framing belongs to the caller's native Transport implementation.
        """
        if self.transport is None:
            raise NativeBackendRequired(
                "This handler calls the original native backend. Supply a real "
                "Transport, or use RecordingTransport only to inspect requests."
            )
        packet = struct.pack("<IB3xf20x", u32(command_id),
                             operator.index(enabled_byte) & 0xFF, float_value)
        self.events.append({"type": "send", "channel": SNAPSHOT_CHANNEL,
                            "payload": packet.hex()})
        sent = self.transport.send(SNAPSHOT_CHANNEL, packet)
        if sent:
            self.events.append({"type": "receive", "channel": SNAPSHOT_CHANNEL})
            self.transport.receive(SNAPSHOT_CHANNEL, MAX_REPLY_BYTES)
        return sent


def frame_payload(payload: bytes) -> bytes:
    """Length framing recovered from FUN_1009d8f4; no connection is created."""
    return struct.pack(">I", len(payload)) + payload


# ---- buttons/button_01_enable_all.py ----
"""AIM / Enable All — recovered menu ID 102.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1797-1807,2048-2066.
Write local flag; send commands 102 and 3, in that order. Does not enable every ESP flag.
Native game-side execution is not implemented or verified here.
"""


def button_01_enable_all(runtime: MenuRuntime, value: int) -> None:
    enabled = int(u32(value) == 1)
    runtime.write_u8(0x1010DDE0, enabled)
    runtime.request(102, enabled)
    runtime.request(3, runtime.read_u8(0x1010DDE0))


# ---- buttons/button_02_aimkill_multitarget.py ----
"""AIM / Aimkill MultiTarget — recovered menu ID 110.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 2345-2353,2594-2602,2843-2857.
Send 1049, then 1048; write 2000.0/0.0 locally; send float command 104. No invented aiming algorithm.
Native game-side execution is not implemented or verified here.
"""


def button_02_aimkill_multitarget(runtime: MenuRuntime, value: int) -> None:
    enabled = int(u32(value) == 1)
    runtime.request(1049, enabled)
    runtime.request(1048, enabled)
    amount = 2000.0 if enabled else 0.0
    runtime.write_f32(0x100E1004, amount)
    runtime.request(104, 0, amount)


# ---- buttons/button_03_speed_timer.py ----
"""AIM / Speed Timer — recovered menu ID 517.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1606-1609.
Send command 517; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""


def button_03_speed_timer(runtime: MenuRuntime, value: int) -> None:
    runtime.request(517, int(u32(value) == 1))


# ---- buttons/button_04_speed_slow_v2.py ----
"""AIM / Speed Slow V2 — recovered menu ID 1099.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1254-1258.
Send command 1099; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""


def button_04_speed_slow_v2(runtime: MenuRuntime, value: int) -> None:
    runtime.request(1099, int(u32(value) == 1))


# ---- buttons/button_05_speed_run.py ----
"""AIM / Speed Run — recovered menu ID 507.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1547-1549,2868-2874.
Send command 507; byte is int(u32(value) != 0).
Native game-side execution is not implemented or verified here.
"""


def button_05_speed_run(runtime: MenuRuntime, value: int) -> None:
    runtime.request(507, int(u32(value) != 0))


# ---- buttons/button_06_auto_target.py ----
"""AIM / Auto Target — recovered menu ID 34834.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 438-443.
Send command 34834; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""


def button_06_auto_target(runtime: MenuRuntime, value: int) -> None:
    runtime.request(34834, int(u32(value) == 1))


# ---- buttons/button_07_auto_revive.py ----
"""AIM / Auto Revive — recovered menu ID 7896.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 430-433.
Send command 7896; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""


def button_07_auto_revive(runtime: MenuRuntime, value: int) -> None:
    runtime.request(7896, int(u32(value) == 1))


# ---- buttons/button_08_esp_line.py ----
"""ESP / ESP Line — recovered menu ID 1.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1705-1707.
Write one byte at snapshot 0x100E3A68; true only when value == 1.
Native game-side execution is not implemented or verified here.
"""


def button_08_esp_line(runtime: MenuRuntime, value: int) -> None:
    runtime.write_u8(0x100E3A68, int(u32(value) == 1))


# ---- buttons/button_09_esp_box.py ----
"""ESP / ESP Box — recovered menu ID 2.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1708-1710.
Write one byte at snapshot 0x100E3A69; true only when value == 1.
Native game-side execution is not implemented or verified here.
"""


def button_09_esp_box(runtime: MenuRuntime, value: int) -> None:
    runtime.write_u8(0x100E3A69, int(u32(value) == 1))


# ---- buttons/button_10_esp_health.py ----
"""ESP / ESP Health — recovered menu ID 3.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1711-1713.
Write one byte at snapshot 0x100E3A6B; true only when value == 1.
Native game-side execution is not implemented or verified here.
"""


def button_10_esp_health(runtime: MenuRuntime, value: int) -> None:
    runtime.write_u8(0x100E3A6B, int(u32(value) == 1))


# ---- buttons/button_11_esp_weapon_icon.py ----
"""ESP / ESP Weapon Icon — recovered menu ID 32.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1784-1786.
Write one byte at snapshot 0x100E3A82; true only when value == 1.
Native game-side execution is not implemented or verified here.
"""


def button_11_esp_weapon_icon(runtime: MenuRuntime, value: int) -> None:
    runtime.write_u8(0x100E3A82, int(u32(value) == 1))


# ---- buttons/button_12_esp_distance.py ----
"""ESP / ESP Distance — recovered menu ID 4.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1714-1716.
Write one byte at snapshot 0x100E3A6A; true only when value == 1.
Native game-side execution is not implemented or verified here.
"""


def button_12_esp_distance(runtime: MenuRuntime, value: int) -> None:
    runtime.write_u8(0x100E3A6A, int(u32(value) == 1))


# ---- buttons/button_13_esp_grenade.py ----
"""ESP / ESP Grenade — recovered menu ID 33.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1787-1792,2878-2886.
Write local grenade flag and send command 33.
Native game-side execution is not implemented or verified here.
"""


def button_13_esp_grenade(runtime: MenuRuntime, value: int) -> None:
    enabled = int(u32(value) == 1)
    runtime.write_u8(0x100E3A8D, enabled)
    runtime.request(33, enabled)


# ---- buttons/button_14_draw_fov.py ----
"""ESP / Draw FOV — recovered menu ID 16.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1775-1777.
Write one byte at snapshot 0x100E3A6C; true only when value == 1.
Native game-side execution is not implemented or verified here.
"""


def button_14_draw_fov(runtime: MenuRuntime, value: int) -> None:
    runtime.write_u8(0x100E3A6C, int(u32(value) == 1))


# ---- buttons/button_15_enable_look_changer.py ----
"""LOOK / Enable Look Changer — recovered menu ID 7100.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1146-1149.
Send command 7100; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""


def button_15_enable_look_changer(runtime: MenuRuntime, value: int) -> None:
    runtime.request(7100, int(u32(value) == 1))


# ---- buttons/button_16_show_for_others_os.py ----
"""LOOK / Show For Others (OS) — recovered menu ID 7101.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1150-1153.
Send command 7101; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""


def button_16_show_for_others_os(runtime: MenuRuntime, value: int) -> None:
    runtime.request(7101, int(u32(value) == 1))


# ---- buttons/button_17_look_1_rampage.py ----
"""LOOK / Look 1 - Rampage — recovered menu ID 7102.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7102 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_17_look_1_rampage(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7102, 1)


# ---- buttons/button_18_look_2_cobra.py ----
"""LOOK / Look 2 - Cobra — recovered menu ID 7103.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7103 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_18_look_2_cobra(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7103, 1)


# ---- buttons/button_19_look_3_criminal_red.py ----
"""LOOK / Look 3 - Criminal Red — recovered menu ID 7104.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7104 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_19_look_3_criminal_red(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7104, 1)


# ---- buttons/button_20_look_4_sakura.py ----
"""LOOK / Look 4 - Sakura — recovered menu ID 7105.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7105 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_20_look_4_sakura(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7105, 1)


# ---- buttons/button_21_look_5_venom.py ----
"""LOOK / Look 5 - Venom — recovered menu ID 7106.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7106 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_21_look_5_venom(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7106, 1)


# ---- buttons/button_22_look_6_titan.py ----
"""LOOK / Look 6 - Titan — recovered menu ID 7107.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7107 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_22_look_6_titan(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7107, 1)


# ---- buttons/button_23_look_7_hip_hop.py ----
"""LOOK / Look 7 - Hip Hop — recovered menu ID 7108.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7108 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_23_look_7_hip_hop(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7108, 1)


# ---- buttons/button_24_look_8_bunny_warrior.py ----
"""LOOK / Look 8 - Bunny Warrior — recovered menu ID 7109.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7109 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_24_look_8_bunny_warrior(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7109, 1)


# ---- buttons/button_25_look_9_breakdancer.py ----
"""LOOK / Look 9 - Breakdancer — recovered menu ID 7110.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7110 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_25_look_9_breakdancer(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7110, 1)


# ---- buttons/button_26_look_10_arctic_blue.py ----
"""LOOK / Look 10 - Arctic Blue — recovered menu ID 7111.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7111 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_26_look_10_arctic_blue(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7111, 1)


# ---- buttons/button_27_look_11_naruto.py ----
"""LOOK / Look 11 - Naruto — recovered menu ID 7112.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7112 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_27_look_11_naruto(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7112, 1)


# ---- buttons/button_28_look_12_sasuke.py ----
"""LOOK / Look 12 - Sasuke — recovered menu ID 7113.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7113 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_28_look_12_sasuke(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7113, 1)


# ---- buttons/button_29_look_13_kakashi.py ----
"""LOOK / Look 13 - Kakashi — recovered menu ID 7114.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7114 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_29_look_13_kakashi(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7114, 1)


# ---- buttons/button_30_look_14_saitama.py ----
"""LOOK / Look 14 - Saitama — recovered menu ID 7115.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7115 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_30_look_14_saitama(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7115, 1)


# ---- buttons/button_31_look_15_dino.py ----
"""LOOK / Look 15 - Dino — recovered menu ID 7116.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7116 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_31_look_15_dino(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7116, 1)


# ---- buttons/button_32_look_16_old_man.py ----
"""LOOK / Look 16 - Old Man — recovered menu ID 7117.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7117 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_32_look_16_old_man(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7117, 1)


# ---- buttons/button_33_look_17_criminal_blue.py ----
"""LOOK / Look 17 - Criminal Blue — recovered menu ID 7118.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7118 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_33_look_17_criminal_blue(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7118, 1)


# ---- buttons/button_34_look_18_criminal_green.py ----
"""LOOK / Look 18 - Criminal Green — recovered menu ID 7119.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7119 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_34_look_18_criminal_green(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7119, 1)


# ---- buttons/button_35_look_19_angelic_set.py ----
"""LOOK / Look 19 - Angelic Set — recovered menu ID 7120.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7120 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_35_look_19_angelic_set(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7120, 1)


# ---- buttons/button_36_look_20_galaxy_set.py ----
"""LOOK / Look 20 - Galaxy Set — recovered menu ID 7121.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7121 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""


def button_36_look_20_galaxy_set(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7121, 1)


# ---- buttons/button_37_fly_lock.py ----
"""BRTL / Fly Lock — recovered menu ID 5194.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1537-1542,469-472.
Ignore argument; XOR previous byte at 0x1010DDDC with 1; send command 5194.
Native game-side execution is not implemented or verified here.
"""


def button_37_fly_lock(runtime: MenuRuntime, value: int) -> None:
    # The native handler ignores value and XORs its previous byte with 1.
    enabled = runtime.read_u8(0x1010DDDC) ^ 1
    runtime.write_u8(0x1010DDDC, enabled)
    runtime.request(5194, enabled)


# ---- buttons/button_38_rise_up.py ----
"""BRTL / Rise Up — recovered menu ID 111.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 2858-2861.
Send command 5657; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""


def button_38_rise_up(runtime: MenuRuntime, value: int) -> None:
    runtime.request(5657, int(u32(value) == 1))


# ---- buttons/button_39_rise_up_new_height.py ----
"""BRTL / Rise Up New Height — recovered menu ID 5660.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1180-1185,493-507.
Convert signed 32-bit value to float32; send command 5660. UI declares 15..100 M.
Native game-side execution is not implemented or verified here.
"""


def button_39_rise_up_new_height(runtime: MenuRuntime, value: int) -> None:
    # UI range is 15..100 M; this native handler itself does not clamp.
    runtime.request(5660, 0, float(s32(value)))


# ---- buttons/button_40_tp_anywhere.py ----
"""BRTL / Tp Anywhere — recovered menu ID 5198.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 452-472.
Ignore argument; XOR previous byte at 0x1010DDD4 with 1; send command 5198.
Native game-side execution is not implemented or verified here.
"""


def button_40_tp_anywhere(runtime: MenuRuntime, value: int) -> None:
    # The native handler ignores value and XORs its previous byte with 1.
    enabled = runtime.read_u8(0x1010DDD4) ^ 1
    runtime.write_u8(0x1010DDD4, enabled)
    runtime.request(5198, enabled)


# ---- buttons/button_41_telespot_manual.py ----
"""BRTL / TeleSpot [MANUAL] — recovered menu ID 59910.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 307-311.
Send command 59910; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""


def button_41_telespot_manual(runtime: MenuRuntime, value: int) -> None:
    runtime.request(59910, int(u32(value) == 1))


# ---- buttons/button_42_telespot_auto.py ----
"""BRTL / TeleSpot [AUTO] — recovered menu ID 59912.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 302-305,311.
Send command 59912; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""


def button_42_telespot_auto(runtime: MenuRuntime, value: int) -> None:
    runtime.request(59912, int(u32(value) == 1))


# ---- buttons/button_43_wide_camera.py ----
"""BRTL / Wide Camera — recovered menu ID 7003.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 481-484.
Send command 7003; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""


def button_43_wide_camera(runtime: MenuRuntime, value: int) -> None:
    runtime.request(7003, int(u32(value) == 1))


# ---- buttons/button_44_invisible_kill.py ----
"""BRTL / Invisible Kill — recovered menu ID 532.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1677-1680.
Send command 532; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""


def button_44_invisible_kill(runtime: MenuRuntime, value: int) -> None:
    runtime.request(532, int(u32(value) == 1))


# ---- buttons/button_45_black_sky.py ----
"""BRTL / Black Sky — recovered menu ID 7001.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 2326-2329.
Send command 7001; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""


def button_45_black_sky(runtime: MenuRuntime, value: int) -> None:
    runtime.request(7001, int(u32(value) == 1))


# ---- buttons/button_46_downkill.py ----
"""BRTL / Downkill — recovered menu ID 5658.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 452-464.
Send command 504; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""


def button_46_downkill(runtime: MenuRuntime, value: int) -> None:
    runtime.request(504, int(u32(value) == 1))


# ---- buttons/button_47_joystick_speed.py ----
"""BRTL / Joystick Speed — recovered menu ID 114.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 2866-2874.
Send command 507; byte is int(u32(value) != 0).
Native game-side execution is not implemented or verified here.
"""


def button_47_joystick_speed(runtime: MenuRuntime, value: int) -> None:
    runtime.request(507, int(u32(value) != 0))


# ---- buttons/button_48_show_keybinds.py ----
"""SET / Show Keybinds — recovered menu ID 6002.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1180-1190,3134-3140.
No action in the recovered native dispatcher. Java keybind behavior has not been recovered.
Native game-side execution is not implemented or verified here.
"""


def button_48_show_keybinds(runtime: MenuRuntime, value: int) -> None:
    # No matching ChangesID branch was recovered for this ID.
    # The original protected Java keybind implementation remains unavailable.
    return None


# ---- buttons/button_49_enable_keybind_system.py ----
"""SET / Enable Keybind System — recovered menu ID 6000.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1180-1190,3134-3140.
No action in the recovered native dispatcher. Java keybind behavior has not been recovered.
Native game-side execution is not implemented or verified here.
"""


def button_49_enable_keybind_system(runtime: MenuRuntime, value: int) -> None:
    # No matching ChangesID branch was recovered for this ID.
    # The original protected Java keybind implementation remains unavailable.
    return None


# ---- buttons/button_50_show_match_timer.py ----
"""SET / Show Match Timer — recovered menu ID 6003.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1187-1190.
Write one byte at snapshot 0x100E3A83; true only when value == 1.
Native game-side execution is not implemented or verified here.
"""


def button_50_show_match_timer(runtime: MenuRuntime, value: int) -> None:
    runtime.write_u8(0x100E3A83, int(u32(value) == 1))


# ---- buttons/button_51_clear_all_keybinds.py ----
"""SET / Clear All Keybinds — recovered menu ID 6001.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1180-1190,3134-3140.
No action in the recovered native dispatcher. Java keybind behavior has not been recovered.
Native game-side execution is not implemented or verified here.
"""


def button_51_clear_all_keybinds(runtime: MenuRuntime, value: int) -> None:
    # No matching ChangesID branch was recovered for this ID.
    # The original protected Java keybind implementation remains unavailable.
    return None


BUTTONS = [{'number': 1, 'id': 102, 'tab': 'AIM', 'label': 'Enable All', 'control': 'addSwitch', 'function': 'button_01_enable_all', 'file': 'buttons/button_01_enable_all.py', 'status': 'recovered_requests_backend_missing', 'behavior': 'Write local flag; send commands 102 and 3, in that order. Does not enable every ESP flag.', 'source_lines': '1797-1807,2048-2066', 'ui_arguments': ['Enable All', 102]}, {'number': 2, 'id': 110, 'tab': 'AIM', 'label': 'Aimkill MultiTarget', 'control': 'addSwitch', 'function': 'button_02_aimkill_multitarget', 'file': 'buttons/button_02_aimkill_multitarget.py', 'status': 'recovered_requests_backend_missing', 'behavior': 'Send 1049, then 1048; write 2000.0/0.0 locally; send float command 104. No invented aiming algorithm.', 'source_lines': '2345-2353,2594-2602,2843-2857', 'ui_arguments': ['Aimkill MultiTarget', 110]}, {'number': 3, 'id': 517, 'tab': 'AIM', 'label': 'Speed Timer', 'control': 'addSwitch', 'function': 'button_03_speed_timer', 'file': 'buttons/button_03_speed_timer.py', 'status': 'recovered_requests_backend_missing', 'behavior': 'Send command 517; byte is int(u32(value) == 1).', 'source_lines': '1606-1609', 'ui_arguments': ['Speed Timer', 517]}, {'number': 4, 'id': 1099, 'tab': 'AIM', 'label': 'Speed Slow V2', 'control': 'addSwitch', 'function': 'button_04_speed_slow_v2', 'file': 'buttons/button_04_speed_slow_v2.py', 'status': 'recovered_requests_backend_missing', 'behavior': 'Send command 1099; byte is int(u32(value) == 1).', 'source_lines': '1254-1258', 'ui_arguments': ['Speed Slow V2', 1099]}, {'number': 5, 'id': 507, 'tab': 'AIM', 'label': 'Speed Run', 'control': 'addSwitch', 'function': 'button_05_speed_run', 'file': 'buttons/button_05_speed_run.py', 'status': 'recovered_requests_backend_missing', 'behavior': 'Send command 507; byte is int(u32(value) != 0).', 'source_lines': '1547-1549,2868-2874', 'ui_arguments': ['Speed Run', 507]}, {'number': 6, 'id': 34834, 'tab': 'AIM', 'label': 'Auto Target', 'control': 'addSwitch', 'function': 'button_06_auto_target', 'file': 'buttons/button_06_auto_target.py', 'status': 'recovered_requests_backend_missing', 'behavior': 'Send command 34834; byte is int(u32(value) == 1).', 'source_lines': '438-443', 'ui_arguments': ['Auto Target', 34834]}, {'number': 7, 'id': 7896, 'tab': 'AIM', 'label': 'Auto Revive', 'control': 'addSwitch', 'function': 'button_07_auto_revive', 'file': 'buttons/button_07_auto_revive.py', 'status': 'recovered_requests_backend_missing', 'behavior': 'Send command 7896; byte is int(u32(value) == 1).', 'source_lines': '430-433', 'ui_arguments': ['Auto Revive', 7896]}, {'number': 8, 'id': 1, 'tab': 'ESP', 'label': 'ESP Line', 'control': 'addSwitch', 'function': 'button_08_esp_line', 'file': 'buttons/button_08_esp_line.py', 'status': 'recovered_local_flag', 'behavior': 'Write one byte at snapshot 0x100E3A68; true only when value == 1.', 'source_lines': '1705-1707', 'ui_arguments': ['ESP Line', 1]}, {'number': 9, 'id': 2, 'tab': 'ESP', 'label': 'ESP Box', 'control': 'addSwitch', 'function': 'button_09_esp_box', 'file': 'buttons/button_09_esp_box.py', 'status': 'recovered_local_flag', 'behavior': 'Write one byte at snapshot 0x100E3A69; true only when value == 1.', 'source_lines': '1708-1710', 'ui_arguments': ['ESP Box', 2]}, {'number': 10, 'id': 3, 'tab': 'ESP', 'label': 'ESP Health', 'control': 'addSwitch', 'function': 'button_10_esp_health', 'file': 'buttons/button_10_esp_health.py', 'status': 'recovered_local_flag', 'behavior': 'Write one byte at snapshot 0x100E3A6B; true only when value == 1.', 'source_lines': '1711-1713', 'ui_arguments': ['ESP Health', 3]}, {'number': 11, 'id': 32, 'tab': 'ESP', 'label': 'ESP Weapon Icon', 'control': 'addSwitch', 'function': 'button_11_esp_weapon_icon', 'file': 'buttons/button_11_esp_weapon_icon.py', 'status': 'recovered_local_flag', 'behavior': 'Write one byte at snapshot 0x100E3A82; true only when value == 1.', 'source_lines': '1784-1786', 'ui_arguments': ['ESP Weapon Icon', 32]}, {'number': 12, 'id': 4, 'tab': 'ESP', 'label': 'ESP Distance', 'control': 'addSwitch', 'function': 'button_12_esp_distance', 'file': 'buttons/button_12_esp_distance.py', 'status': 'recovered_local_flag', 'behavior': 'Write one byte at snapshot 0x100E3A6A; true only when value == 1.', 'source_lines': '1714-1716', 'ui_arguments': ['ESP Distance', 4]}, {'number': 13, 'id': 33, 'tab': 'ESP', 'label': 'ESP Grenade', 'control': 'addSwitch', 'function': 'button_13_esp_grenade', 'file': 'buttons/button_13_esp_grenade.py', 'status': 'recovered_local_flag_and_request_backend_missing', 'behavior': 'Write local grenade flag and send command 33.', 'source_lines': '1787-1792,2878-2886', 'ui_arguments': ['ESP Grenade', 33]}, {'number': 14, 'id': 16, 'tab': 'ESP', 'label': 'Draw FOV', 'control': 'addSwitch', 'function': 'button_14_draw_fov', 'file': 'buttons/button_14_draw_fov.py', 'status': 'recovered_local_flag', 'behavior': 'Write one byte at snapshot 0x100E3A6C; true only when value == 1.', 'source_lines': '1775-1777', 'ui_arguments': ['Draw FOV', 16]}, {'number': 15, 'id': 7100, 'tab': 'LOOK', 'label': 'Enable Look Changer', 'control': 'addSwitch', 'function': 'button_15_enable_look_changer', 'file': 'buttons/button_15_enable_look_changer.py', 'status': 'recovered_requests_backend_missing', 'behavior': 'Send command 7100; byte is int(u32(value) == 1).', 'source_lines': '1146-1149', 'ui_arguments': ['Enable Look Changer', 7100]}, {'number': 16, 'id': 7101, 'tab': 'LOOK', 'label': 'Show For Others (OS)', 'control': 'addSwitch', 'function': 'button_16_show_for_others_os', 'file': 'buttons/button_16_show_for_others_os.py', 'status': 'recovered_requests_backend_missing', 'behavior': 'Send command 7101; byte is int(u32(value) == 1).', 'source_lines': '1150-1153', 'ui_arguments': ['Show For Others (OS)', 7101]}, {'number': 17, 'id': 7102, 'tab': 'LOOK', 'label': 'Look 1 - Rampage', 'control': 'addSwitch', 'function': 'button_17_look_1_rampage', 'file': 'buttons/button_17_look_1_rampage.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7102 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 1 - Rampage', 7102]}, {'number': 18, 'id': 7103, 'tab': 'LOOK', 'label': 'Look 2 - Cobra', 'control': 'addSwitch', 'function': 'button_18_look_2_cobra', 'file': 'buttons/button_18_look_2_cobra.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7103 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 2 - Cobra', 7103]}, {'number': 19, 'id': 7104, 'tab': 'LOOK', 'label': 'Look 3 - Criminal Red', 'control': 'addSwitch', 'function': 'button_19_look_3_criminal_red', 'file': 'buttons/button_19_look_3_criminal_red.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7104 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 3 - Criminal Red', 7104]}, {'number': 20, 'id': 7105, 'tab': 'LOOK', 'label': 'Look 4 - Sakura', 'control': 'addSwitch', 'function': 'button_20_look_4_sakura', 'file': 'buttons/button_20_look_4_sakura.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7105 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 4 - Sakura', 7105]}, {'number': 21, 'id': 7106, 'tab': 'LOOK', 'label': 'Look 5 - Venom', 'control': 'addSwitch', 'function': 'button_21_look_5_venom', 'file': 'buttons/button_21_look_5_venom.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7106 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 5 - Venom', 7106]}, {'number': 22, 'id': 7107, 'tab': 'LOOK', 'label': 'Look 6 - Titan', 'control': 'addSwitch', 'function': 'button_22_look_6_titan', 'file': 'buttons/button_22_look_6_titan.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7107 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 6 - Titan', 7107]}, {'number': 23, 'id': 7108, 'tab': 'LOOK', 'label': 'Look 7 - Hip Hop', 'control': 'addSwitch', 'function': 'button_23_look_7_hip_hop', 'file': 'buttons/button_23_look_7_hip_hop.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7108 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 7 - Hip Hop', 7108]}, {'number': 24, 'id': 7109, 'tab': 'LOOK', 'label': 'Look 8 - Bunny Warrior', 'control': 'addSwitch', 'function': 'button_24_look_8_bunny_warrior', 'file': 'buttons/button_24_look_8_bunny_warrior.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7109 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 8 - Bunny Warrior', 7109]}, {'number': 25, 'id': 7110, 'tab': 'LOOK', 'label': 'Look 9 - Breakdancer', 'control': 'addSwitch', 'function': 'button_25_look_9_breakdancer', 'file': 'buttons/button_25_look_9_breakdancer.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7110 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 9 - Breakdancer', 7110]}, {'number': 26, 'id': 7111, 'tab': 'LOOK', 'label': 'Look 10 - Arctic Blue', 'control': 'addSwitch', 'function': 'button_26_look_10_arctic_blue', 'file': 'buttons/button_26_look_10_arctic_blue.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7111 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 10 - Arctic Blue', 7111]}, {'number': 27, 'id': 7112, 'tab': 'LOOK', 'label': 'Look 11 - Naruto', 'control': 'addSwitch', 'function': 'button_27_look_11_naruto', 'file': 'buttons/button_27_look_11_naruto.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7112 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 11 - Naruto', 7112]}, {'number': 28, 'id': 7113, 'tab': 'LOOK', 'label': 'Look 12 - Sasuke', 'control': 'addSwitch', 'function': 'button_28_look_12_sasuke', 'file': 'buttons/button_28_look_12_sasuke.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7113 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 12 - Sasuke', 7113]}, {'number': 29, 'id': 7114, 'tab': 'LOOK', 'label': 'Look 13 - Kakashi', 'control': 'addSwitch', 'function': 'button_29_look_13_kakashi', 'file': 'buttons/button_29_look_13_kakashi.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7114 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 13 - Kakashi', 7114]}, {'number': 30, 'id': 7115, 'tab': 'LOOK', 'label': 'Look 14 - Saitama', 'control': 'addSwitch', 'function': 'button_30_look_14_saitama', 'file': 'buttons/button_30_look_14_saitama.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7115 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 14 - Saitama', 7115]}, {'number': 31, 'id': 7116, 'tab': 'LOOK', 'label': 'Look 15 - Dino', 'control': 'addSwitch', 'function': 'button_31_look_15_dino', 'file': 'buttons/button_31_look_15_dino.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7116 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 15 - Dino', 7116]}, {'number': 32, 'id': 7117, 'tab': 'LOOK', 'label': 'Look 16 - Old Man', 'control': 'addSwitch', 'function': 'button_32_look_16_old_man', 'file': 'buttons/button_32_look_16_old_man.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7117 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 16 - Old Man', 7117]}, {'number': 33, 'id': 7118, 'tab': 'LOOK', 'label': 'Look 17 - Criminal Blue', 'control': 'addSwitch', 'function': 'button_33_look_17_criminal_blue', 'file': 'buttons/button_33_look_17_criminal_blue.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7118 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 17 - Criminal Blue', 7118]}, {'number': 34, 'id': 7119, 'tab': 'LOOK', 'label': 'Look 18 - Criminal Green', 'control': 'addSwitch', 'function': 'button_34_look_18_criminal_green', 'file': 'buttons/button_34_look_18_criminal_green.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7119 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 18 - Criminal Green', 7119]}, {'number': 35, 'id': 7120, 'tab': 'LOOK', 'label': 'Look 19 - Angelic Set', 'control': 'addSwitch', 'function': 'button_35_look_19_angelic_set', 'file': 'buttons/button_35_look_19_angelic_set.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7120 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 19 - Angelic Set', 7120]}, {'number': 36, 'id': 7121, 'tab': 'LOOK', 'label': 'Look 20 - Galaxy Set', 'control': 'addSwitch', 'function': 'button_36_look_20_galaxy_set', 'file': 'buttons/button_36_look_20_galaxy_set.py', 'status': 'recovered_enable_only_request_backend_missing', 'behavior': 'Send command 7121 only when value == 1; otherwise no native action.', 'source_lines': '1154-1179,530-532,2881-2886', 'ui_arguments': ['Look 20 - Galaxy Set', 7121]}, {'number': 37, 'id': 5194, 'tab': 'BRTL', 'label': 'Fly Lock', 'control': 'addSwitch', 'function': 'button_37_fly_lock', 'file': 'buttons/button_37_fly_lock.py', 'status': 'recovered_toggle_initial_state_and_backend_required', 'behavior': 'Ignore argument; XOR previous byte at 0x1010DDDC with 1; send command 5194.', 'source_lines': '1537-1542,469-472', 'ui_arguments': ['Fly Lock', 5194]}, {'number': 38, 'id': 111, 'tab': 'BRTL', 'label': 'Rise Up', 'control': 'addSwitch', 'function': 'button_38_rise_up', 'file': 'buttons/button_38_rise_up.py', 'status': 'recovered_requests_backend_missing', 'behavior': 'Send command 5657; byte is int(u32(value) == 1).', 'source_lines': '2858-2861', 'ui_arguments': ['Rise Up', 111]}, {'number': 39, 'id': 5660, 'tab': 'BRTL', 'label': 'Rise Up New Height', 'control': 'addSeekBar', 'function': 'button_39_rise_up_new_height', 'file': 'buttons/button_39_rise_up_new_height.py', 'status': 'recovered_requests_backend_missing', 'behavior': 'Convert signed 32-bit value to float32; send command 5660. UI declares 15..100 M.', 'source_lines': '1180-1185,493-507', 'ui_arguments': ['Rise Up New Height', 15, 100, 'M', 5660]}, {'number': 40, 'id': 5198, 'tab': 'BRTL', 'label': 'Tp Anywhere', 'control': 'addSwitch', 'function': 'button_40_tp_anywhere', 'file': 'buttons/button_40_tp_anywhere.py', 'status': 'recovered_toggle_initial_state_and_backend_required', 'behavior': 'Ignore argument; XOR previous byte at 0x1010DDD4 with 1; send command 5198.', 'source_lines': '452-472', 'ui_arguments': ['Tp Anywhere', 5198]}, {'number': 41, 'id': 59910, 'tab': 'BRTL', 'label': 'TeleSpot [MANUAL]', 'control': 'addSwitch', 'function': 'button_41_telespot_manual', 'file': 'buttons/button_41_telespot_manual.py', 'status': 'recovered_requests_backend_missing', 'behavior': 'Send command 59910; byte is int(u32(value) == 1).', 'source_lines': '307-311', 'ui_arguments': ['TeleSpot [MANUAL]', 59910]}, {'number': 42, 'id': 59912, 'tab': 'BRTL', 'label': 'TeleSpot [AUTO]', 'control': 'addSwitch', 'function': 'button_42_telespot_auto', 'file': 'buttons/button_42_telespot_auto.py', 'status': 'recovered_requests_backend_missing', 'behavior': 'Send command 59912; byte is int(u32(value) == 1).', 'source_lines': '302-305,311', 'ui_arguments': ['TeleSpot [AUTO]', 59912]}, {'number': 43, 'id': 7003, 'tab': 'BRTL', 'label': 'Wide Camera', 'control': 'addSwitch', 'function': 'button_43_wide_camera', 'file': 'buttons/button_43_wide_camera.py', 'status': 'recovered_requests_backend_missing', 'behavior': 'Send command 7003; byte is int(u32(value) == 1).', 'source_lines': '481-484', 'ui_arguments': ['Wide Camera', 7003]}, {'number': 44, 'id': 532, 'tab': 'BRTL', 'label': 'Invisible Kill', 'control': 'addSwitch', 'function': 'button_44_invisible_kill', 'file': 'buttons/button_44_invisible_kill.py', 'status': 'recovered_requests_backend_missing', 'behavior': 'Send command 532; byte is int(u32(value) == 1).', 'source_lines': '1677-1680', 'ui_arguments': ['Invisible Kill', 532]}, {'number': 45, 'id': 7001, 'tab': 'BRTL', 'label': 'Black Sky', 'control': 'addSwitch', 'function': 'button_45_black_sky', 'file': 'buttons/button_45_black_sky.py', 'status': 'recovered_requests_backend_missing', 'behavior': 'Send command 7001; byte is int(u32(value) == 1).', 'source_lines': '2326-2329', 'ui_arguments': ['Black Sky', 7001]}, {'number': 46, 'id': 5658, 'tab': 'BRTL', 'label': 'Downkill', 'control': 'addSwitch', 'function': 'button_46_downkill', 'file': 'buttons/button_46_downkill.py', 'status': 'recovered_requests_backend_missing', 'behavior': 'Send command 504; byte is int(u32(value) == 1).', 'source_lines': '452-464', 'ui_arguments': ['Downkill', 5658]}, {'number': 47, 'id': 114, 'tab': 'BRTL', 'label': 'Joystick Speed', 'control': 'addSwitch', 'function': 'button_47_joystick_speed', 'file': 'buttons/button_47_joystick_speed.py', 'status': 'recovered_requests_backend_missing', 'behavior': 'Send command 507; byte is int(u32(value) != 0).', 'source_lines': '2866-2874', 'ui_arguments': ['Joystick Speed', 114]}, {'number': 48, 'id': 6002, 'tab': 'SET', 'label': 'Show Keybinds', 'control': 'addSwitch', 'function': 'button_48_show_keybinds', 'file': 'buttons/button_48_show_keybinds.py', 'status': 'no_native_action_java_behavior_unrecovered', 'behavior': 'No action in the recovered native dispatcher. Java keybind behavior has not been recovered.', 'source_lines': '1180-1190,3134-3140', 'ui_arguments': ['Show Keybinds', 6002]}, {'number': 49, 'id': 6000, 'tab': 'SET', 'label': 'Enable Keybind System', 'control': 'addSwitch', 'function': 'button_49_enable_keybind_system', 'file': 'buttons/button_49_enable_keybind_system.py', 'status': 'no_native_action_java_behavior_unrecovered', 'behavior': 'No action in the recovered native dispatcher. Java keybind behavior has not been recovered.', 'source_lines': '1180-1190,3134-3140', 'ui_arguments': ['Enable Keybind System', 6000]}, {'number': 50, 'id': 6003, 'tab': 'SET', 'label': 'Show Match Timer', 'control': 'addSwitch', 'function': 'button_50_show_match_timer', 'file': 'buttons/button_50_show_match_timer.py', 'status': 'recovered_local_flag', 'behavior': 'Write one byte at snapshot 0x100E3A83; true only when value == 1.', 'source_lines': '1187-1190', 'ui_arguments': ['Show Match Timer', 6003]}, {'number': 51, 'id': 6001, 'tab': 'SET', 'label': 'Clear All Keybinds', 'control': 'addSwitch', 'function': 'button_51_clear_all_keybinds', 'file': 'buttons/button_51_clear_all_keybinds.py', 'status': 'no_native_action_java_behavior_unrecovered', 'behavior': 'No action in the recovered native dispatcher. Java keybind behavior has not been recovered.', 'source_lines': '1180-1190,3134-3140', 'ui_arguments': ['Clear All Keybinds', 6001]}]
BY_ID = {
    102: button_01_enable_all,
    110: button_02_aimkill_multitarget,
    517: button_03_speed_timer,
    1099: button_04_speed_slow_v2,
    507: button_05_speed_run,
    34834: button_06_auto_target,
    7896: button_07_auto_revive,
    1: button_08_esp_line,
    2: button_09_esp_box,
    3: button_10_esp_health,
    32: button_11_esp_weapon_icon,
    4: button_12_esp_distance,
    33: button_13_esp_grenade,
    16: button_14_draw_fov,
    7100: button_15_enable_look_changer,
    7101: button_16_show_for_others_os,
    7102: button_17_look_1_rampage,
    7103: button_18_look_2_cobra,
    7104: button_19_look_3_criminal_red,
    7105: button_20_look_4_sakura,
    7106: button_21_look_5_venom,
    7107: button_22_look_6_titan,
    7108: button_23_look_7_hip_hop,
    7109: button_24_look_8_bunny_warrior,
    7110: button_25_look_9_breakdancer,
    7111: button_26_look_10_arctic_blue,
    7112: button_27_look_11_naruto,
    7113: button_28_look_12_sasuke,
    7114: button_29_look_13_kakashi,
    7115: button_30_look_14_saitama,
    7116: button_31_look_15_dino,
    7117: button_32_look_16_old_man,
    7118: button_33_look_17_criminal_blue,
    7119: button_34_look_18_criminal_green,
    7120: button_35_look_19_angelic_set,
    7121: button_36_look_20_galaxy_set,
    5194: button_37_fly_lock,
    111: button_38_rise_up,
    5660: button_39_rise_up_new_height,
    5198: button_40_tp_anywhere,
    59910: button_41_telespot_manual,
    59912: button_42_telespot_auto,
    7003: button_43_wide_camera,
    532: button_44_invisible_kill,
    7001: button_45_black_sky,
    5658: button_46_downkill,
    114: button_47_joystick_speed,
    6002: button_48_show_keybinds,
    6000: button_49_enable_keybind_system,
    6003: button_50_show_match_timer,
    6001: button_51_clear_all_keybinds,
}


def main():
    import argparse
    import inspect
    import json
    parser = argparse.ArgumentParser(description="Inspect the 51 translated recovered handlers; no game connection.")
    group = parser.add_mutually_exclusive_group()
    group.add_argument("--list", action="store_true")
    group.add_argument("--show", type=int, metavar="BUTTON_NUMBER")
    group.add_argument("--trace", type=int, metavar="BUTTON_NUMBER")
    parser.add_argument("--value", type=int, default=1)
    parser.add_argument("--initial-toggle-byte", type=int, default=None)
    args = parser.parse_args()
    selected = args.show if args.show is not None else args.trace
    if selected is None:
        for row in BUTTONS:
            print(f'{row["number"]:02d} | {row["tab"]:4s} | ID {row["id"]:5d} | {row["label"]}')
        return
    if not 1 <= selected <= len(BUTTONS):
        parser.error("Button number must be 1..51, following recovered menu order")
    row = BUTTONS[selected - 1]
    function = BY_ID[row["id"]]
    if args.show is not None:
        print(row["behavior"])
        print(inspect.getsource(function))
        return
    initial = {}
    addresses = {5194:0x1010DDDC,5198:0x1010DDD4}
    if row["id"] in addresses:
        if args.initial_toggle_byte is None:
            parser.error("This toggle requires an explicit --initial-toggle-byte; actual initial state is unknown")
        if not 0 <= args.initial_toggle_byte <= 255:
            parser.error("Initial toggle byte must be 0..255")
        initial[addresses[row["id"]]] = args.initial_toggle_byte
    runtime = MenuRuntime(RecordingTransport(), initial)
    function(runtime,args.value)
    print(json.dumps({"analysis_only":True,"game_connected":False,
                      "button":selected,"id":row["id"],"label":row["label"],
                      "events":runtime.events},indent=2))


if __name__ == "__main__":
    main()
