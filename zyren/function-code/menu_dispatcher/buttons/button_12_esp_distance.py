"""ESP / ESP Distance — recovered menu ID 4.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1714-1716.
Write one byte at snapshot 0x100E3A6A; true only when value == 1.
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_12_esp_distance(runtime: MenuRuntime, value: int) -> None:
    runtime.write_u8(0x100E3A6A, int(u32(value) == 1))
