/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180077c40(void)

{
  code *pcVar1;
  undefined auVar2 [16];
  int iVar3;
  undefined8 *puVar4;
  undefined auStack_18 [8];
  undefined8 uStack_10;
  
  uStack_10 = auStack_18;
  if (DAT_181b2f64a != '\0') {
    return;
  }
  LOCK();
  DAT_181b2f64a = 1;
  UNLOCK();
  DAT_181b2f64b = 0;
  puVar4 = (undefined8 *)func_0x000180127a94(8);
  *puVar4 = &DAT_180077be0;
  auStack_18 = (undefined  [8])_beginthreadex(0,0,&DAT_180079df0,puVar4,0,auStack_18 + 8);
  if (auStack_18 != (undefined  [8])0x0) {
    if (_DAT_181b2f500 != 0) {
      terminate();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _DAT_181b2f500 = uStack_10;
    _DAT_181b2f4f8 = auStack_18;
    auVar2 = ZEXT816(0);
    if ((int)uStack_10 != 0) {
      iVar3 = _Thrd_detach(auStack_18);
      auVar2 = _auStack_18;
      if (iVar3 == 0) {
        _DAT_181b2f4f8 = ZEXT816(0);
        return;
      }
    }
    _auStack_18 = auVar2;
    __Throw_Cpp_error_std__YAXH_Z(1);
  }
  uStack_10._0_4_ = 0;
  __Throw_Cpp_error_std__YAXH_Z(6);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

