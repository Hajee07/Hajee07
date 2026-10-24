/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined (*) [16] recovered_180095fb0(undefined (*param_1) [16],undefined8 *param_2)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined (*pauVar6) [16];
  undefined8 *puVar7;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong uVar10;
  undefined4 auStackX_10 [2];
  int aiStackX_18 [2];
  longlong lStackX_20;
  longlong lStack_170;
  longlong lStack_168;
  int iStack_13c;
  undefined *apuStack_138 [2];
  undefined auStack_128 [16];
  longlong *plStack_118;
  longlong *plStack_110;
  longlong *plStack_f8;
  ulonglong *puStack_f0;
  int *piStack_e0;
  ulonglong uStack_c8;
  uint uStack_c0;
  undefined auStack_b0 [112];
  
  auStackX_10[0] = 0;
  puVar7 = param_2;
  if (0xf < (ulonglong)param_2[3]) {
    puVar7 = (undefined8 *)*param_2;
  }
  uVar2 = GetFileVersionInfoSizeA(puVar7,auStackX_10);
  uVar8 = (ulonglong)uVar2;
  if (uVar2 == 0) {
    *param_1 = ZEXT816(0);
    *(undefined8 *)param_1[1] = 0;
    *(undefined8 *)(param_1[1] + 8) = 0xf;
    (*param_1)[0] = 0;
    return param_1;
  }
  lVar4 = func_0x000180024110(uVar8);
  func_0x0001801ca899(lVar4,0,uVar8);
  if (0xf < (ulonglong)param_2[3]) {
    param_2 = (undefined8 *)*param_2;
  }
  iVar3 = GetFileVersionInfoA(param_2,auStackX_10[0],uVar8,lVar4);
  if (iVar3 != 0) {
    lStackX_20 = 0;
    aiStackX_18[0] = 0;
    iVar3 = VerQueryValueA(lVar4,&UNK_1819d8bec,&lStackX_20,aiStackX_18);
    if (((iVar3 != 0) && (aiStackX_18[0] != 0)) && (lStackX_20 != 0)) {
      apuStack_138[0] = &UNK_1819d8e48;
      __0__basic_ios_DU__char_traits_D_std___std__IEAA_XZ(auStack_b0);
      __0__basic_ostream_DU__char_traits_D_std___std__QEAA_PEAV__basic_streambuf_DU__char_traits_D_std___1__N_Z
                (apuStack_138,apuStack_138 + 1,0,0);
      *(undefined **)((longlong)apuStack_138 + (longlong)*(int *)(apuStack_138[0] + 4)) =
           &UNK_180201ff8;
      *(int *)((longlong)&iStack_13c + (longlong)*(int *)(apuStack_138[0] + 4)) =
           *(int *)(apuStack_138[0] + 4) + -0x88;
      __0__basic_streambuf_DU__char_traits_D_std___std__IEAA_XZ(apuStack_138 + 1);
      apuStack_138[1] = &UNK_1801f2638;
      uStack_c8 = 0;
      uStack_c0 = 4;
      uVar5 = __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_G_Z
                        (apuStack_138,*(undefined2 *)(lStackX_20 + 10));
      uVar5 = recovered_180069ac0(uVar5,&UNK_1819d8bf0);
      uVar5 = __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_G_Z
                        (uVar5,*(undefined2 *)(lStackX_20 + 8));
      uVar5 = recovered_180069ac0(uVar5,&UNK_1819d8bf0);
      uVar5 = __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_G_Z
                        (uVar5,*(undefined2 *)(lStackX_20 + 0xe));
      uVar5 = recovered_180069ac0(uVar5,&UNK_1819d8bf0);
      __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_G_Z
                (uVar5,*(undefined2 *)(lStackX_20 + 0xc));
      *param_1 = ZEXT816(0);
      *(undefined8 *)param_1[1] = 0;
      *(undefined8 *)(param_1[1] + 8) = 0xf;
      (*param_1)[0] = 0;
      if ((((byte)uStack_c0 & 0x22) == 2) || (uVar10 = *puStack_f0, uVar10 == 0)) {
        if (((uStack_c0 & 4) == 0) && (*plStack_f8 != 0)) {
          lStack_170 = *plStack_118;
          lStack_168 = (*piStack_e0 - lStack_170) + *plStack_f8;
        }
        else {
          lStack_168 = 0;
          lStack_170 = 0;
        }
      }
      else {
        lStack_170 = *plStack_110;
        if (uVar10 < uStack_c8) {
          uVar10 = uStack_c8;
        }
        lStack_168 = uVar10 - lStack_170;
      }
      if (lStack_170 != 0) {
        recovered_1800676d0(param_1,lStack_170,lStack_168);
      }
      *(undefined **)((longlong)apuStack_138 + (longlong)*(int *)(apuStack_138[0] + 4)) =
           &UNK_180201ff8;
      *(int *)((longlong)&iStack_13c + (longlong)*(int *)(apuStack_138[0] + 4)) =
           *(int *)(apuStack_138[0] + 4) + -0x88;
      apuStack_138[1] = &UNK_1801f2638;
      recovered_1800985e0(apuStack_138 + 1);
      __1__basic_streambuf_DU__char_traits_D_std___std__UEAA_XZ(apuStack_138 + 1);
      __1__basic_ostream_DU__char_traits_D_std___std__UEAA_XZ(auStack_128);
      __1__basic_ios_DU__char_traits_D_std___std__UEAA_XZ(auStack_b0);
      goto LAB_1800962b6;
    }
  }
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0xf;
  (*param_1)[0] = 0;
LAB_1800962b6:
  if (lVar4 != 0) {
    lVar9 = lVar4;
    if (0xfff < uVar8) {
      uVar8 = uVar8 + 0x27;
      lVar9 = *(longlong *)(lVar4 + -8);
      if (0x1f < (lVar4 - lVar9) - 8U) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        pauVar6 = (undefined (*) [16])(*pcVar1)();
        return pauVar6;
      }
    }
    func_0x000180127e40(lVar9,uVar8);
  }
  return param_1;
}

