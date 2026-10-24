/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18009bbb0(undefined8 param_1,longlong param_2,ulonglong param_3,undefined4 *param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined auVar4 [16];
  undefined auVar5 [16];
  undefined4 *puVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined4 uVar9;
  ulonglong auStackX_18 [2];
  undefined auStack_28 [4];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined auStack_18 [8];
  undefined8 uStack_10;
  
  _auStack_28 = ZEXT816(0);
  _auStack_18 = ZEXT816(0);
  lVar8 = -1;
  do {
    lVar8 = lVar8 + 1;
  } while (*(char *)(param_2 + lVar8) != '\0');
  auStackX_18[0] = param_3;
  recovered_180066cc0(auStack_28);
  puVar6 = _DAT_181b302b0;
  if (_DAT_181b302b0 == _DAT_181b302b8) {
    uVar9 = func_0x0001800baad0(&DAT_181b302a8,_DAT_181b302b0,auStack_28);
    uVar7 = uStack_10;
  }
  else {
    uVar9 = auStack_28;
    *_DAT_181b302b0 = auStack_28;
    puVar6[1] = uStack_24;
    puVar6[2] = uStack_20;
    puVar6[3] = uStack_1c;
    puVar6[4] = auStack_18._0_4_;
    puVar6[5] = auStack_18._4_4_;
    puVar6[6] = (undefined4)uStack_10;
    puVar6[7] = uStack_10._4_4_;
    auVar4[15] = 0;
    auVar4._0_15_ = stack0xffffffffffffffd9;
    _auStack_28 = auVar4 << 8;
    _DAT_181b302b0 = _DAT_181b302b0 + 8;
    uVar7 = 0xf;
  }
  if (0xf < uVar7) {
    if (0xfff < uVar7 + 1) {
      if (0x1f < (_auStack_28 - *(longlong *)(_auStack_28 + -8)) - 8U) goto LAB_18009bd41;
    }
    uVar9 = func_0x000180127e40();
  }
  puVar6 = _DAT_181b2f698;
  if (_DAT_181b2f698 == _DAT_181b2f6a0) {
    func_0x0001800ba940(uVar9,_DAT_181b2f698,param_4);
  }
  else {
    uVar9 = param_4[1];
    uVar2 = param_4[2];
    uVar3 = param_4[3];
    *_DAT_181b2f698 = *param_4;
    puVar6[1] = uVar9;
    puVar6[2] = uVar2;
    puVar6[3] = uVar3;
    _DAT_181b2f698 = _DAT_181b2f698 + 4;
  }
  _auStack_28 = ZEXT816(0);
  _auStack_18 = ZEXT816(0);
  recovered_180066cc0(auStack_28,&UNK_1819dcb88,3);
  puVar6 = _DAT_181b2f6b0;
  if (_DAT_181b2f6b0 == _DAT_181b2f6b8) {
    uVar9 = func_0x0001800baad0(&DAT_181b2f6a8,_DAT_181b2f6b0,auStack_28);
    uVar7 = uStack_10;
  }
  else {
    uVar9 = auStack_28;
    *_DAT_181b2f6b0 = auStack_28;
    puVar6[1] = uStack_24;
    puVar6[2] = uStack_20;
    puVar6[3] = uStack_1c;
    puVar6[4] = auStack_18._0_4_;
    puVar6[5] = auStack_18._4_4_;
    puVar6[6] = (undefined4)uStack_10;
    puVar6[7] = uStack_10._4_4_;
    auVar5[15] = 0;
    auVar5._0_15_ = stack0xffffffffffffffd9;
    _auStack_28 = auVar5 << 8;
    _DAT_181b2f6b0 = _DAT_181b2f6b0 + 8;
    uVar7 = 0xf;
  }
  if (0xf < uVar7) {
    if (0xfff < uVar7 + 1) {
      if (0x1f < (_auStack_28 - *(longlong *)(_auStack_28 + -8)) - 8U) {
LAB_18009bd41:
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
    }
    uVar9 = func_0x000180127e40();
  }
  auStackX_18[0] = auStackX_18[0] & 0xffffffff00000000;
  if (_DAT_181b2f6c8 == _DAT_181b2f6d0) {
    func_0x0001800ba620(uVar9,_DAT_181b2f6c8,auStackX_18);
  }
  else {
    *_DAT_181b2f6c8 = 0;
    _DAT_181b2f6c8 = _DAT_181b2f6c8 + 1;
  }
  auStackX_18[0] = (ulonglong)_DAT_181a034ac;
  if (_DAT_181b2f8b8 != _DAT_181b2f8c0) {
    *_DAT_181b2f8b8 = (ulonglong)_DAT_181a034ac;
    _DAT_181b2f8b8 = _DAT_181b2f8b8 + 1;
    return;
  }
  func_0x0001800ba7b0(_DAT_181a034ac,_DAT_181b2f8b8,auStackX_18);
  return;
}

