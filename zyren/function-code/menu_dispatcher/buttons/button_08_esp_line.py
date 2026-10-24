"""ESP / ESP Line — recovered menu ID 1.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1705-1707.
Write one byte at snapshot 0x100E3A68; true only when value == 1.
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_08_esp_line(runtime: MenuRuntime, value: int) -> None:
    runtime.write_u8(0x100E3A68, int(u32(value) == 1))
