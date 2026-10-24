/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18009aa70(void)

{
  int iVar1;
  longlong *aplStackX_8 [4];
  
  if ((_DAT_181b2f370 != (longlong *)0x0) && (_DAT_181b2f350 != (longlong *)0x0)) {
    iVar1 = (**(code **)(*_DAT_181b2f370 + 0x48))(_DAT_181b2f370,0,&UNK_1819da758,aplStackX_8);
    if (-1 < iVar1) {
      (**(code **)(*_DAT_181b2f350 + 0x48))(_DAT_181b2f350,aplStackX_8[0],0,&DAT_181b2f388);
      (**(code **)(*aplStackX_8[0] + 0x10))();
      DAT_181b2f2f8 = 1;
      if (_DAT_181b2f360 != (longlong *)0x0) {
        (**(code **)(*_DAT_181b2f360 + 0x108))(_DAT_181b2f360,1,&DAT_181b2f388,0);
      }
    }
  }
  return;
}

