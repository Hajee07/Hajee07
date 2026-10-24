/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800aeb50(void)

{
  code *pcVar1;
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined auVar4 [16];
  char cVar5;
  int iVar6;
  undefined8 uVar7;
  undefined (*pauVar8) [16];
  longlong lVar9;
  undefined *puVar10;
  undefined auStack_1a8 [16];
  longlong lStack_198;
  ulonglong uStack_190;
  longlong lStack_188;
  undefined8 uStack_180;
  undefined auStack_178 [16];
  undefined auStack_168 [16];
  undefined8 uStack_158;
  undefined8 uStack_150;
  int iStack_13c;
  undefined *apuStack_138 [3];
  undefined auStack_120 [48];
  longlong alStack_f0 [6];
  undefined8 uStack_c0;
  undefined uStack_b7;
  undefined8 uStack_b4;
  undefined uStack_ac;
  undefined8 uStack_a8;
  undefined auStack_88 [112];
  
  uVar7 = recovered_1800ae560(&uStack_158);
  pauVar8 = (undefined (*) [16])recovered_180066ec0(uVar7,&UNK_1819dceb8,0xc);
  auStack_178 = *pauVar8;
  auStack_168 = pauVar8[1];
  *(undefined8 *)pauVar8[1] = 0;
  *(undefined8 *)(pauVar8[1] + 8) = 0xf;
  (*pauVar8)[0] = 0;
  recovered_180066e40(&uStack_158);
  puVar10 = auStack_178;
  if (0xf < (ulonglong)auStack_168._8_8_) {
    puVar10 = (undefined *)auStack_178._0_8_;
  }
  apuStack_138[0] = &UNK_1819de2c8;
  __0__basic_ios_DU__char_traits_D_std___std__IEAA_XZ(auStack_88);
  __0__basic_istream_DU__char_traits_D_std___std__QEAA_PEAV__basic_streambuf_DU__char_traits_D_std___1__N_Z
            (apuStack_138,apuStack_138 + 2,0,0);
  *(undefined **)((longlong)apuStack_138 + (longlong)*(int *)(apuStack_138[0] + 4)) = &UNK_1801f22f0
  ;
  *(int *)((longlong)&iStack_13c + (longlong)*(int *)(apuStack_138[0] + 4)) =
       *(int *)(apuStack_138[0] + 4) + -0xb0;
  __0__basic_streambuf_DU__char_traits_D_std___std__IEAA_XZ(apuStack_138 + 2);
  apuStack_138[2] = &UNK_1801f2270;
  uStack_ac = 0;
  uStack_b7 = 0;
  __Init___basic_streambuf_DU__char_traits_D_std___std__IEAAXXZ(apuStack_138 + 2);
  uStack_a8 = 0;
  uStack_b4 = _DAT_181b50d48;
  uStack_c0 = 0;
  lVar9 = func_0x0001800bbbc0(apuStack_138 + 2,puVar10,0x21,0x40);
  if (lVar9 == 0) {
    _setstate___basic_ios_DU__char_traits_D_std___std__QEAAXH_N_Z
              ((longlong)apuStack_138 + (longlong)*(int *)(apuStack_138[0] + 4),2,0);
  }
  *(undefined **)((longlong)apuStack_138 + (longlong)*(int *)(apuStack_138[0] + 4)) = &UNK_1801f22f0
  ;
  *(int *)((longlong)&iStack_13c + (longlong)*(int *)(apuStack_138[0] + 4)) =
       *(int *)(apuStack_138[0] + 4) + -0xb0;
  if (0xf < (ulonglong)auStack_168._8_8_) {
    if ((0xfff < auStack_168._8_8_ + 1) &&
       (0x1f < (auStack_178._0_8_ - *(longlong *)(auStack_178._0_8_ + -8)) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    func_0x000180127e40();
  }
  auStack_168._8_8_ = _UNK_181a03538;
  auStack_168._0_8_ = _DAT_181a03530;
  auVar2[15] = 0;
  auVar2._0_15_ = auStack_178._1_15_;
  auStack_178 = auVar2 << 8;
  cVar5 = __7ios_base_std__QEBA_NXZ
                    ((longlong)apuStack_138 + (longlong)*(int *)(apuStack_138[0] + 4));
  if (cVar5 == '\0') {
    uStack_158 = 0;
    uStack_150 = CONCAT62(uStack_150._2_6_,1);
    uVar7 = uStack_150;
    lStack_188 = *(longlong *)((longlong)alStack_f0 + (longlong)*(int *)(apuStack_138[0] + 4));
    auStack_1a8 = ZEXT816(0);
    lStack_198 = 0;
    uStack_190 = 0;
    if (lStack_188 != 0) {
      iVar6 = _sgetc___basic_streambuf_DU__char_traits_D_std___std__QEAAHXZ();
      if (iVar6 == -1) {
        lStack_188 = 0;
        uStack_180 = CONCAT71(uStack_180._1_7_,1);
      }
      else {
        uStack_180 = CONCAT71(CONCAT61(uStack_180._2_6_,(char)iVar6),1);
      }
    }
    if (lStack_188 == 0) {
      lStack_198 = 0;
      uStack_190 = 0xf;
      auVar3[15] = 0;
      auVar3._0_15_ = auStack_1a8._1_15_;
      auStack_1a8 = auVar3 << 8;
    }
    else {
      uStack_158 = 0;
      uStack_150 = uVar7;
      func_0x0001800b82b0(auStack_1a8,&lStack_188,&uStack_158);
      while (lStack_198 != 0) {
        puVar10 = auStack_1a8;
        if (0xf < uStack_190) {
          puVar10 = (undefined *)auStack_1a8._0_8_;
        }
        if (puVar10[lStack_198 + -1] != '\r') {
          puVar10 = auStack_1a8;
          if (0xf < uStack_190) {
            puVar10 = (undefined *)auStack_1a8._0_8_;
          }
          if (puVar10[lStack_198 + -1] != '\n') {
            if (lStack_198 == 0) goto LAB_1800aeecc;
            puVar10 = auStack_1a8;
            if (0xf < uStack_190) {
              puVar10 = (undefined *)auStack_1a8._0_8_;
            }
            strncpy_s(0x181b2bcf8,0x80,puVar10,0xffffffffffffffff);
            break;
          }
        }
        lStack_198 = lStack_198 + -1;
        puVar10 = auStack_1a8;
        if (0xf < uStack_190) {
          puVar10 = (undefined *)auStack_1a8._0_8_;
        }
        puVar10[lStack_198] = 0;
      }
    }
LAB_1800aeecc:
    if (0xf < uStack_190) {
      if ((0xfff < uStack_190 + 1) &&
         ((undefined *)0x1f <
          (undefined *)(auStack_1a8._0_8_ + (-8 - *(longlong *)(auStack_1a8._0_8_ + -8))))) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    lStack_198 = 0;
    uStack_190 = 0xf;
    auVar4[15] = 0;
    auVar4._0_15_ = auStack_1a8._1_15_;
    auStack_1a8 = auVar4 << 8;
  }
  *(undefined **)((longlong)apuStack_138 + (longlong)*(int *)(apuStack_138[0] + 4)) = &UNK_1801f22f0
  ;
  *(int *)((longlong)&iStack_13c + (longlong)*(int *)(apuStack_138[0] + 4)) =
       *(int *)(apuStack_138[0] + 4) + -0xb0;
  func_0x0001800b7db0(apuStack_138 + 2);
  __1__basic_istream_DU__char_traits_D_std___std__UEAA_XZ(auStack_120);
  __1__basic_ios_DU__char_traits_D_std___std__UEAA_XZ(auStack_88);
  return;
}

