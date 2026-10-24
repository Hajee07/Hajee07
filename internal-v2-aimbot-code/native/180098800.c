/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Removing unreachable block (ram,0x000180098af2) */
/* WARNING: Removing unreachable block (ram,0x000180098a82) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180098800(char *param_1)

{
  code *pcVar1;
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined auVar4 [16];
  int iVar5;
  undefined (*pauVar6) [16];
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined *puVar10;
  longlong lVar11;
  undefined *puVar12;
  undefined8 in_stack_fffffffffffffea8;
  uint uVar13;
  longlong lStack_128;
  undefined *puStack_120;
  undefined auStack_110 [8];
  undefined4 uStack_108;
  undefined uStack_104;
  undefined3 uStack_103;
  undefined8 uStack_100;
  ulonglong uStack_f8;
  undefined auStack_f0 [16];
  undefined auStack_e0 [16];
  undefined auStack_d0 [16];
  undefined auStack_c0 [16];
  undefined auStack_b0 [16];
  undefined8 uStack_a0;
  undefined auStack_98 [16];
  undefined auStack_88 [16];
  undefined auStack_78 [16];
  undefined auStack_68 [16];
  undefined auStack_58 [16];
  undefined auStack_48 [16];
  undefined8 uStack_38;
  
  uVar13 = (uint)((ulonglong)in_stack_fffffffffffffea8 >> 0x20);
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    auStack_b0 = ZEXT816(0);
    uStack_38 = 0;
    uStack_a0 = 0;
    auStack_98._4_12_ = auStack_b0._4_12_;
    auStack_98._0_4_ = 0x68;
    auStack_68._0_12_ = auStack_b0._0_12_;
    auStack_68._12_4_ = 1;
    auStack_58._2_14_ = auStack_b0._2_14_;
    auVar2._14_2_ = 0;
    auVar2._0_14_ = auStack_58._2_14_;
    auStack_58 = auVar2 << 0x10;
    uStack_100 = _DAT_181a035e0;
    uStack_f8 = _UNK_181a035e8;
    uStack_108 = _DAT_1819d8e60;
    auStack_110 = (undefined  [8])_DAT_1819d8e58;
    uStack_104 = DAT_1819d8e64;
    uStack_103 = 0;
    lVar11 = -1;
    do {
      lVar11 = lVar11 + 1;
    } while (param_1[lVar11] != '\0');
    auStack_88 = auStack_b0;
    auStack_78 = auStack_b0;
    auStack_48 = auStack_b0;
    pauVar6 = (undefined (*) [16])recovered_180066ec0(auStack_110,param_1);
    auStack_d0 = *pauVar6;
    auStack_c0 = pauVar6[1];
    *(undefined8 *)pauVar6[1] = 0;
    *(undefined8 *)(pauVar6[1] + 8) = 0xf;
    (*pauVar6)[0] = 0;
    pauVar6 = (undefined (*) [16])recovered_180066ec0(auStack_d0,&UNK_1819d8e50,6);
    auStack_f0 = *pauVar6;
    auStack_e0 = pauVar6[1];
    *(undefined8 *)pauVar6[1] = 0;
    *(undefined8 *)(pauVar6[1] + 8) = 0xf;
    (*pauVar6)[0] = 0;
    if (0xf < (ulonglong)auStack_c0._8_8_) {
      if ((0xfff < auStack_c0._8_8_ + 1) &&
         (0x1f < (auStack_d0._0_8_ - *(longlong *)(auStack_d0._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    auStack_c0._8_8_ = _UNK_181a03538;
    auStack_c0._0_8_ = _DAT_181a03530;
    auVar3[15] = 0;
    auVar3._0_15_ = auStack_d0._1_15_;
    auStack_d0 = auVar3 << 8;
    if (0xf < uStack_f8) {
      if ((0xfff < uStack_f8 + 1) &&
         (0x1f < ((longlong)auStack_110 - *(longlong *)((longlong)auStack_110 + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    uStack_100 = _DAT_181a03530;
    uStack_f8 = _UNK_181a03538;
    auVar4[15] = 0;
    auVar4._0_15_ = stack0xfffffffffffffef1;
    _auStack_110 = auVar4 << 8;
    puVar10 = auStack_f0;
    if (0xf < (ulonglong)auStack_e0._8_8_) {
      puVar10 = (undefined *)auStack_f0._0_8_;
    }
    puVar12 = auStack_f0;
    if (0xf < (ulonglong)auStack_e0._8_8_) {
      puVar12 = (undefined *)auStack_f0._0_8_;
    }
    lStack_128 = 0;
    puStack_120 = (undefined *)0x0;
    puVar10 = puVar10 + (auStack_e0._0_8_ - (longlong)puVar12);
    if (puVar10 != (undefined *)0x0) {
      if ((undefined *)0x7fffffffffffffff < puVar10) goto LAB_180098ca6;
      lStack_128 = func_0x000180024110(puVar10);
      puStack_120 = puVar10 + lStack_128;
      func_0x0001801ca893(lStack_128,puVar12,puVar10);
    }
    lVar11 = (longlong)puStack_120 - lStack_128;
    if (lVar11 == 0x7fffffffffffffff) {
      recovered_18006aad0();
LAB_180098ca6:
      recovered_18006aad0();
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar8 = (longlong)puStack_120 - lStack_128;
    uVar9 = 0x7fffffffffffffff;
    if ((uVar8 <= 0x7fffffffffffffff - (uVar8 >> 1)) &&
       (uVar9 = uVar8 + (uVar8 >> 1), uVar9 < lVar11 + 1U)) {
      uVar9 = lVar11 + 1U;
    }
    lVar7 = func_0x000180024110(uVar9);
    *(undefined *)(lVar7 + lVar11) = 0;
    func_0x0001801ca893(lVar7,lStack_128,(longlong)puStack_120 - lStack_128);
    if (lStack_128 != 0) {
      if ((0xfff < (ulonglong)((longlong)puStack_120 - lStack_128)) &&
         (0x1f < (lStack_128 - *(longlong *)(lStack_128 + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    iVar5 = CreateProcessA(0,lVar7,0,0,(ulonglong)uVar13 << 0x20,0x8000000,0,0,auStack_98,auStack_b0
                          );
    if (iVar5 != 0) {
      WaitForSingleObject(auStack_b0._0_8_,5000);
      CloseHandle(auStack_b0._0_8_);
      CloseHandle(auStack_b0._8_8_);
    }
    if (lVar7 != 0) {
      if ((0xfff < uVar9) && (0x1f < (lVar7 - *(longlong *)(lVar7 + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    if (0xf < (ulonglong)auStack_e0._8_8_) {
      if ((0xfff < auStack_e0._8_8_ + 1) &&
         (0x1f < (auStack_f0._0_8_ - *(longlong *)(auStack_f0._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
  }
  return;
}

