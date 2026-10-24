/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 recovered_18009b420(void)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined4 **ppuVar3;
  longlong lVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puStack_68;
  undefined auStack_60 [16];
  undefined auStack_50 [16];
  undefined auStack_40 [16];
  undefined auStack_30 [16];
  undefined auStack_20 [24];
  
  auStack_50 = ZEXT816(0);
  auStack_40 = ZEXT816(0);
  recovered_180079270(auStack_50,&UNK_1819d8ef0,0xe);
  recovered_18009b020(&puStack_68,auStack_50);
  if (7 < (ulonglong)auStack_40._8_8_) {
    if ((0xfff < auStack_40._8_8_ * 2 + 2U) &&
       (0x1f < (auStack_50._0_8_ - *(longlong *)(auStack_50._0_8_ + -8)) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
    func_0x000180127e40();
  }
  puVar5 = puStack_68;
  puVar6 = (undefined4 *)auStack_60._0_8_;
  if (puStack_68 == (undefined4 *)auStack_60._0_8_) {
    auStack_30 = ZEXT816(0);
    auStack_20._0_16_ = ZEXT816(0);
    recovered_180079270(auStack_30,&UNK_1819d8e98,0xd);
    ppuVar3 = (undefined4 **)recovered_18009b020(auStack_50,auStack_30);
    if (&puStack_68 != ppuVar3) {
      if (puStack_68 != (undefined4 *)0x0) {
        if ((0xfff < (auStack_60._8_8_ - (longlong)puStack_68 & 0xfffffffffffffffcU)) &&
           (0x1f < (ulonglong)((longlong)puStack_68 + (-8 - *(longlong *)(puStack_68 + -2))))) {
          _invoke_watson(0,0,0,0,0);
          pcVar1 = (code *)swi(3);
          uVar2 = (*pcVar1)();
          return uVar2;
        }
        func_0x000180127e40();
      }
      puStack_68 = *ppuVar3;
      auStack_60 = *(undefined (*) [16])(ppuVar3 + 1);
      *ppuVar3 = (undefined4 *)0x0;
      ppuVar3[1] = (undefined4 *)0x0;
      ppuVar3[2] = (undefined4 *)0x0;
    }
    recovered_180079780(auStack_50);
    if (7 < (ulonglong)auStack_20._8_8_) {
      if ((0xfff < auStack_20._8_8_ * 2 + 2U) &&
         (0x1f < (auStack_30._0_8_ - *(longlong *)(auStack_30._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        uVar2 = (*pcVar1)();
        return uVar2;
      }
      func_0x000180127e40();
    }
    puVar5 = puStack_68;
    puVar6 = (undefined4 *)auStack_60._0_8_;
    if (puStack_68 == (undefined4 *)auStack_60._0_8_) {
      uVar2 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                  &UNK_1819da8f0);
      __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                (uVar2,&DAT_180069ca0);
      uVar2 = 0;
      goto LAB_18009b671;
    }
  }
  do {
    lVar4 = OpenProcess(0x1fffff,0,*puVar5);
    if (lVar4 != 0) {
      EnumWindows(&DAT_18009b3d0);
      CloseHandle(lVar4);
    }
    puVar5 = puVar5 + 1;
    uVar2 = _DAT_181b2f390;
  } while (puVar5 != puVar6);
LAB_18009b671:
  recovered_180079780(&puStack_68);
  return uVar2;
}

