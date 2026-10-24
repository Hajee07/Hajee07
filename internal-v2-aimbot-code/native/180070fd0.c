/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong recovered_180070fd0(void)

{
  code *pcVar1;
  undefined auVar2 [16];
  undefined8 uVar3;
  ulonglong uVar4;
  bool bVar5;
  undefined auStack_18 [8];
  undefined8 uStack_10;
  
  uStack_10 = auStack_18;
  uVar4 = 0;
  LOCK();
  bVar5 = DAT_181b4efd1 == 0;
  if (bVar5) {
    DAT_181b4efd1 = 1;
  }
  else {
    uVar4 = (ulonglong)DAT_181b4efd1;
  }
  UNLOCK();
  if (!bVar5) {
    return uVar4;
  }
  DAT_181b4efd2 = 0;
  uVar3 = func_0x000180127a94(1);
  auStack_18 = (undefined  [8])_beginthreadex(0,0,&DAT_180079e20,uVar3,0,auStack_18 + 8);
  if (auStack_18 != (undefined  [8])0x0) {
    if (_DAT_181b50930 != 0) {
      terminate();
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    _DAT_181b50930 = uStack_10;
    _DAT_181b50928 = auStack_18;
    auVar2 = ZEXT816(0);
    if ((int)uStack_10 != 0) {
      uVar4 = _Thrd_detach(auStack_18);
      auVar2 = _auStack_18;
      if ((int)uVar4 == 0) {
        _DAT_181b50928 = ZEXT816(0);
        return uVar4;
      }
    }
    _auStack_18 = auVar2;
    __Throw_Cpp_error_std__YAXH_Z(1);
  }
  uStack_10._0_4_ = 0;
  __Throw_Cpp_error_std__YAXH_Z(6);
  pcVar1 = (code *)swi(3);
  uVar4 = (*pcVar1)();
  return uVar4;
}

