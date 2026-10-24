"""ESP / ESP Weapon Icon — recovered menu ID 32.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1784-1786.
Write one byte at snapshot 0x100E3A82; true only when value == 1.
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_11_esp_weapon_icon(runtime: MenuRuntime, value: int) -> None:
    runtime.write_u8(0x100E3A82, int(u32(value) == 1))
