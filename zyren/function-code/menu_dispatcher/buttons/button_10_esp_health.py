"""ESP / ESP Health — recovered menu ID 3.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1711-1713.
Write one byte at snapshot 0x100E3A6B; true only when value == 1.
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_10_esp_health(runtime: MenuRuntime, value: int) -> None:
    runtime.write_u8(0x100E3A6B, int(u32(value) == 1))
