/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18006f9b0(void)

{
  code *pcVar1;
  undefined auVar2 [16];
  undefined auVar3 [16];
  int iVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined auStack_18 [8];
  undefined8 uStack_10;
  
  uStack_10 = auStack_18;
  if (DAT_181b2f6d8 != '\0') {
    return;
  }
  LOCK();
  DAT_181b2f6d8 = 1;
  UNLOCK();
  DAT_181b2b5ef = 1;
  puVar5 = (undefined8 *)func_0x000180127a94(8);
  *puVar5 = &DAT_18006f340;
  auStack_18 = (undefined  [8])_beginthreadex(0,0,&DAT_180079df0,puVar5,0,auStack_18 + 8);
  if (auStack_18 != (undefined  [8])0x0) {
    if (_DAT_181b2f520 != 0) {
      terminate();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _DAT_181b2f520 = uStack_10;
    _DAT_181b2f518 = auStack_18;
    auVar3 = ZEXT816(0);
    if ((int)uStack_10 != 0) {
      iVar4 = _Thrd_detach(auStack_18);
      auVar3 = _auStack_18;
      if (iVar4 == 0) {
        _DAT_181b2f518 = ZEXT816(0);
        puVar5 = (undefined8 *)func_0x000180127a94(8);
        *puVar5 = &DAT_18006f380;
        lVar6 = _beginthreadex(0,0,&DAT_180079df0,puVar5,0,auStack_18 + 8);
        auVar2 = _auStack_18;
        auStack_18 = (undefined  [8])lVar6;
        if (lVar6 == 0) {
          uStack_10._4_4_ = auVar2._12_4_;
          _auStack_18 = ZEXT812(0);
          __Throw_Cpp_error_std__YAXH_Z(6);
          auVar3 = _auStack_18;
        }
        else {
          if (_DAT_181b2f530 != 0) {
            terminate();
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
          }
          _DAT_181b2f530 = uStack_10;
          _DAT_181b2f528 = lVar6;
          auVar3 = ZEXT816(0);
          if (auVar2._8_4_ != 0) {
            iVar4 = _Thrd_detach(auStack_18);
            auVar3 = _auStack_18;
            if (iVar4 == 0) {
              _DAT_181b2f528 = ZEXT816(0);
              return;
            }
          }
        }
      }
    }
    _auStack_18 = auVar3;
    __Throw_Cpp_error_std__YAXH_Z(1);
  }
  uStack_10._0_4_ = 0;
  __Throw_Cpp_error_std__YAXH_Z(6);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

