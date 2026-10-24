"""ESP / ESP Grenade — recovered menu ID 33.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1787-1792,2878-2886.
Write local grenade flag and send command 33.
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_13_esp_grenade(runtime: MenuRuntime, value: int) -> None:
    enabled = int(u32(value) == 1)
    runtime.write_u8(0x100E3A8D, enabled)
    runtime.request(33, enabled)
