/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18006f2b0(void)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined auStackX_8 [8];
  
  recovered_1800721a0();
  puVar2 = (undefined8 *)recovered_180067b80(auStackX_8);
  _DAT_181b302e0 = *puVar2;
  recovered_180069a10(&DAT_181b2bf20);
  recovered_180078290(0x181b2be30);
  lVar1 = _DAT_181b2bde0;
  _DAT_181b2bd7c = 0;
  lVar3 = _DAT_181b2bdd8;
  if (_DAT_181b2bdd8 != _DAT_181b2bde0) {
    do {
      recovered_180066e40(lVar3 + 0x10);
      lVar3 = lVar3 + 0x38;
    } while (lVar3 != lVar1);
    _DAT_181b2bde0 = _DAT_181b2bdd8;
  }
  return;
}

