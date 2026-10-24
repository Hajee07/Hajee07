/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong recovered_18007ea60(void)

{
  int iVar1;
  ulonglong uVar2;
  
  uVar2 = func_0x00018007e9d0();
  iVar1 = (int)uVar2;
  if ((-1 < iVar1) &&
     (uVar2 = (_DAT_181b2f550 - _DAT_181b2f548) * 0xe38e38e38e38e39,
     iVar1 < (int)((_DAT_181b2f550 - _DAT_181b2f548) / 0x48))) {
    return CONCAT71((int7)(uVar2 >> 8),
                    *(char *)(_DAT_181b2f548 + 0x42 + (longlong)iVar1 * 0x48) == '\0');
  }
  return uVar2 & 0xffffffffffffff00;
}

