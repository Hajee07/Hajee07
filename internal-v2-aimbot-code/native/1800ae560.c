/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined (*) [16] recovered_1800ae560(undefined (*param_1) [16])

{
  code *pcVar1;
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined auVar4 [12];
  longlong lVar5;
  int iVar6;
  undefined (*pauVar7) [16];
  undefined *puVar8;
  longlong lVar9;
  undefined auStack_1a8 [16];
  undefined auStack_198 [8];
  undefined8 uStack_190;
  undefined auStack_188 [8];
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined auStack_178 [8];
  undefined8 uStack_170;
  undefined auStack_160 [16];
  undefined auStack_150 [8];
  undefined8 uStack_148;
  undefined auStack_140 [16];
  undefined auStack_130 [24];
  char acStack_118 [272];
  longlong lVar10;
  
  func_0x0001801ca899(acStack_118,0,0x104);
  iVar6 = SHGetFolderPathA(0,0x1c,0,0,acStack_118);
  auStack_160 = ZEXT816(0);
  if (iVar6 < 0) {
    *param_1 = auStack_160;
    *(undefined8 *)param_1[1] = 8;
    *(undefined8 *)(param_1[1] + 8) = 0xf;
    *(undefined8 *)*param_1 = 0x6574695861766f4e;
    (*param_1)[8] = 0;
  }
  else {
    _auStack_150 = ZEXT816(0);
    lVar10 = -1;
    do {
      lVar5 = lVar10 + 1;
      lVar10 = lVar10 + 1;
    } while (acStack_118[lVar5] != '\0');
    recovered_180066cc0(auStack_160,acStack_118);
    pauVar7 = (undefined (*) [16])recovered_180066ec0(auStack_160,&UNK_1819dce78,0x12);
    _auStack_188 = *pauVar7;
    _auStack_178 = pauVar7[1];
    *(undefined8 *)pauVar7[1] = 0;
    *(undefined8 *)(pauVar7[1] + 8) = 0xf;
    (*pauVar7)[0] = 0;
    if (0xf < uStack_148) {
      if (0xfff < uStack_148 + 1) {
        if (0x1f < (auStack_160._0_8_ - *(longlong *)(auStack_160._0_8_ + -8)) - 8U) {
          _invoke_watson(0,0,0,0,0);
          pcVar1 = (code *)swi(3);
          pauVar7 = (undefined (*) [16])(*pcVar1)();
          return pauVar7;
        }
      }
      func_0x000180127e40();
    }
    auStack_150._4_4_ = _UNK_181a03534;
    auStack_150._0_4_ = _DAT_181a03530;
    uStack_148._0_4_ = _UNK_181a03538;
    uStack_148._4_4_ = _UNK_181a0353c;
    auVar2[15] = 0;
    auVar2._0_15_ = auStack_160._1_15_;
    auStack_160 = auVar2 << 8;
    auStack_140 = ZEXT816(0);
    auStack_130._0_16_ = ZEXT816(0);
    lVar10 = -1;
    do {
      lVar9 = lVar10 + 1;
      lVar5 = lVar10 + 1;
      lVar10 = lVar9;
    } while (acStack_118[lVar5] != '\0');
    recovered_180066cc0(auStack_140,acStack_118,lVar9);
    pauVar7 = (undefined (*) [16])recovered_180066ec0(auStack_140,&UNK_1819dcea8,9);
    auVar4 = *(undefined (*) [12])*pauVar7;
    auVar2 = *pauVar7;
    _auStack_198 = pauVar7[1];
    *(undefined8 *)pauVar7[1] = 0;
    *(undefined8 *)(pauVar7[1] + 8) = 0xf;
    (*pauVar7)[0] = 0;
    auStack_1a8._0_8_ = auStack_1a8;
    if (0xf < uStack_190) {
      auStack_1a8._0_8_ = auVar4._0_8_;
    }
    puVar8 = (undefined *)auStack_1a8._0_8_;
    auStack_1a8 = auVar2;
    CreateDirectoryA(puVar8,0);
    if (0xf < uStack_190) {
      if (0xfff < uStack_190 + 1) {
        if (0x1f < (auStack_1a8._0_8_ - *(longlong *)(auStack_1a8._0_8_ + -8)) - 8U) {
          _invoke_watson(0,0,0,0,0);
          pcVar1 = (code *)swi(3);
          pauVar7 = (undefined (*) [16])(*pcVar1)();
          return pauVar7;
        }
      }
      func_0x000180127e40();
    }
    auStack_198._4_4_ = _UNK_181a03534;
    auStack_198._0_4_ = _DAT_181a03530;
    uStack_190._4_4_ = _UNK_181a0353c;
    uStack_190._0_4_ = _UNK_181a03538;
    auVar3[15] = 0;
    auVar3._0_15_ = auStack_1a8._1_15_;
    auStack_1a8 = auVar3 << 8;
    if (0xf < (ulonglong)auStack_130._8_8_) {
      if (0xfff < auStack_130._8_8_ + 1) {
        if (0x1f < (auStack_140._0_8_ - *(longlong *)(auStack_140._0_8_ + -8)) - 8U) {
          _invoke_watson(0,0,0,0,0);
          pcVar1 = (code *)swi(3);
          pauVar7 = (undefined (*) [16])(*pcVar1)();
          return pauVar7;
        }
      }
      func_0x000180127e40();
    }
    puVar8 = auStack_188;
    if (0xf < uStack_170) {
      puVar8 = (undefined *)auStack_188;
    }
    CreateDirectoryA(puVar8,0);
    *(undefined4 *)*param_1 = auStack_188._0_4_;
    *(undefined4 *)(*param_1 + 4) = auStack_188._4_4_;
    *(undefined4 *)(*param_1 + 8) = uStack_180;
    *(undefined4 *)(*param_1 + 0xc) = uStack_17c;
    *(undefined4 *)param_1[1] = auStack_178._0_4_;
    *(undefined4 *)(param_1[1] + 4) = auStack_178._4_4_;
    *(undefined4 *)(param_1[1] + 8) = (undefined4)uStack_170;
    *(undefined4 *)(param_1[1] + 0xc) = uStack_170._4_4_;
  }
  return param_1;
}

