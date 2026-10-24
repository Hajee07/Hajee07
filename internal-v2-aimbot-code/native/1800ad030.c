/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong recovered_1800ad030(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  puVar3 = &DAT_181ade2c0;
  if (0xf < _DAT_181ade2d8) {
    puVar3 = _DAT_181ade2c0;
  }
  if (((_DAT_181ade2d0 < (undefined *)0x6) ||
      (puVar1 = _DAT_181ade2d0 + (longlong)puVar3,
      puVar2 = (undefined *)func_0x0001801278a0(puVar3,puVar1,&UNK_1819dc9b4,6), puVar2 == puVar1))
     || (puVar2 = puVar2 + -(longlong)puVar3, puVar2 == (undefined *)0xffffffffffffffff)) {
    puVar3 = &DAT_181ade2c0;
    if (0xf < _DAT_181ade2d8) {
      puVar3 = _DAT_181ade2c0;
    }
    if (((_DAT_181ade2d0 < (undefined *)0x9) ||
        (puVar1 = _DAT_181ade2d0 + (longlong)puVar3,
        puVar2 = (undefined *)func_0x0001801278a0(puVar3,puVar1,&UNK_1819dc9a8,9), puVar2 == puVar1)
        ) || (puVar2 = puVar2 + -(longlong)puVar3, puVar2 == (undefined *)0xffffffffffffffff)) {
      puVar3 = &DAT_181ade2c0;
      if (0xf < _DAT_181ade2d8) {
        puVar3 = _DAT_181ade2c0;
      }
      if (((_DAT_181ade2d0 < (undefined *)0x9) ||
          (puVar1 = _DAT_181ade2d0 + (longlong)puVar3,
          puVar2 = (undefined *)func_0x0001801278a0(puVar3,puVar1,&UNK_1819dc9d8,9),
          puVar2 == puVar1)) ||
         (puVar2 = puVar2 + -(longlong)puVar3, puVar2 == (undefined *)0xffffffffffffffff)) {
        puVar3 = &DAT_181ade2c0;
        if (0xf < _DAT_181ade2d8) {
          puVar3 = _DAT_181ade2c0;
        }
        if (((_DAT_181ade2d0 < (undefined *)0xd) ||
            (puVar1 = puVar3 + (longlong)_DAT_181ade2d0,
            puVar2 = (undefined *)func_0x0001801278a0(puVar3,puVar1,&UNK_1819dca28,0xd),
            puVar2 == puVar1)) ||
           (puVar2 = puVar2 + -(longlong)puVar3, puVar2 == (undefined *)0xffffffffffffffff)) {
          puVar3 = &DAT_181ade2c0;
          if (0xf < _DAT_181ade2d8) {
            puVar3 = _DAT_181ade2c0;
          }
          if (((_DAT_181ade2d0 < (undefined *)0xc) ||
              (puVar1 = puVar3 + (longlong)_DAT_181ade2d0,
              puVar2 = (undefined *)func_0x0001801278a0(puVar3,puVar1,&UNK_1819dcbf0,0xc),
              puVar2 == puVar1)) ||
             (puVar2 = puVar2 + -(longlong)puVar3, puVar2 == (undefined *)0xffffffffffffffff)) {
            puVar3 = &DAT_181ade2c0;
            if (0xf < _DAT_181ade2d8) {
              puVar3 = _DAT_181ade2c0;
            }
            puVar2 = _DAT_181ade2d0;
            if (((_DAT_181ade2d0 < (undefined *)0x13) ||
                (puVar1 = puVar3 + (longlong)_DAT_181ade2d0,
                puVar2 = (undefined *)func_0x0001801278a0(puVar3,puVar1,&UNK_1819dcc20,0x13),
                puVar2 == puVar1)) ||
               (puVar2 = puVar2 + -(longlong)puVar3, puVar2 == (undefined *)0xffffffffffffffff)) {
              return (ulonglong)puVar2 & 0xffffffffffffff00;
            }
          }
        }
      }
    }
  }
  return CONCAT71((int7)((ulonglong)puVar2 >> 8),1);
}

