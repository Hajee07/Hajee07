/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined (*) [16] recovered_1800963a0(undefined (*param_1) [16],longlong param_2)

{
  undefined *puVar1;
  ulonglong uVar2;
  code *pcVar3;
  undefined auVar4 [16];
  undefined auVar5 [16];
  undefined auVar6 [16];
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  char cVar10;
  int iVar11;
  undefined4 *puVar12;
  longlong lVar13;
  longlong lVar14;
  char *pcVar15;
  undefined *puVar16;
  undefined8 *puVar17;
  undefined8 uVar18;
  undefined (*pauVar19) [16];
  undefined *puVar20;
  undefined8 *******pppppppuVar21;
  ulonglong uVar22;
  char *pcVar23;
  ulonglong uVar24;
  char *pcVar25;
  int aiStackX_10 [2];
  uint auStackX_18 [4];
  undefined auStack_728 [16];
  ulonglong uStack_718;
  ulonglong uStack_710;
  undefined4 uStack_708;
  undefined auStack_700 [8];
  undefined8 uStack_6f8;
  ulonglong uStack_6f0;
  ulonglong uStack_6e8;
  undefined auStack_6e0 [16];
  undefined8 uStack_6d0;
  ulonglong uStack_6c8;
  undefined auStack_6c0 [16];
  ulonglong uStack_6b0;
  ulonglong uStack_6a8;
  undefined auStack_6a0 [16];
  ulonglong uStack_690;
  ulonglong uStack_688;
  undefined auStack_680 [16];
  undefined8 uStack_670;
  ulonglong uStack_668;
  undefined8 *******apppppppuStack_660 [2];
  longlong lStack_650;
  ulonglong uStack_648;
  int iStack_63c;
  undefined *apuStack_638 [2];
  undefined auStack_628 [16];
  longlong *plStack_618;
  longlong *plStack_610;
  longlong *plStack_5f8;
  ulonglong *puStack_5f0;
  int *piStack_5e0;
  ulonglong uStack_5c8;
  uint uStack_5c0;
  undefined auStack_5b0 [104];
  char acStack_548 [256];
  undefined auStack_448 [1040];
  
  uStack_708 = 0;
  if (param_2 == 0) {
    *param_1 = ZEXT816(0);
    *(undefined8 *)param_1[1] = 0;
    *(undefined8 *)(param_1[1] + 8) = 0;
    puVar12 = (undefined4 *)func_0x000180024110(0x20);
    *(undefined4 **)*param_1 = puVar12;
    *(undefined8 *)param_1[1] = 0x11;
    *(undefined8 *)(param_1[1] + 8) = 0x1f;
    uVar9 = _UNK_1819d8c04;
    uVar8 = _UNK_1819d8c00;
    uVar7 = _UNK_1819d8bfc;
    *puVar12 = _DAT_1819d8bf8;
    puVar12[1] = uVar7;
    puVar12[2] = uVar8;
    puVar12[3] = uVar9;
    *(undefined *)(puVar12 + 4) = DAT_1819d8c08;
    *(undefined *)((longlong)puVar12 + 0x11) = 0;
    return param_1;
  }
  func_0x0001801ca899(acStack_548,0,0x100);
  GetWindowTextA(param_2,acStack_548,0xff);
  auStack_6a0 = ZEXT816(0);
  uStack_690 = 0;
  uStack_688 = 0;
  lVar13 = -1;
  do {
    lVar14 = lVar13 + 1;
    lVar13 = lVar13 + 1;
  } while (acStack_548[lVar14] != '\0');
  recovered_180066cc0(auStack_6a0,acStack_548);
  aiStackX_10[0] = 0;
  GetWindowThreadProcessId(param_2,aiStackX_10);
  if ((aiStackX_10[0] == 0) || (lVar13 = OpenProcess(0x1000,0), lVar13 == 0)) {
    uStack_6b0 = 0;
    uStack_6a8 = 0xf;
    auStack_6c0._1_15_ = SUB1615(ZEXT816(0),1);
    auVar5[15] = 0;
    auVar5._0_15_ = auStack_6c0._1_15_;
    auStack_6c0 = auVar5 << 8;
  }
  else {
    func_0x0001801ca899(auStack_448,0,0x410);
    auStackX_18[0] = 0x410;
    uStack_6f0 = 0;
    uStack_6e8 = 0xf;
    stack0xfffffffffffff901 = SUB1615(ZEXT816(0),1);
    auVar4[15] = 0;
    auVar4._0_15_ = stack0xfffffffffffff901;
    _auStack_700 = auVar4 << 8;
    iVar11 = QueryFullProcessImageNameA(lVar13,0,auStack_448,auStackX_18);
    if (iVar11 != 0) {
      uVar24 = (ulonglong)auStackX_18[0];
      if (uVar24 < 0x10) {
        uStack_6f0 = uVar24;
        func_0x0001801ca893(auStack_700,auStack_448,auStackX_18[0]);
        auStack_700[uVar24] = 0;
      }
      else {
        uVar22 = uVar24 | 0xf;
        if (uVar22 < 0x16) {
          uVar22 = 0x16;
        }
        lVar14 = func_0x000180024110(uVar22 + 1);
        uStack_6f0 = uVar24;
        uStack_6e8 = uVar22;
        func_0x0001801ca88d(lVar14,auStack_448,uVar24);
        *(undefined *)(lVar14 + uVar24) = 0;
        auStack_700 = (undefined  [8])lVar14;
      }
    }
    CloseHandle(lVar13);
    auStack_6c0 = _auStack_700;
    uStack_6b0 = uStack_6f0;
    uStack_6a8 = uStack_6e8;
  }
  recovered_180095fb0(apppppppuStack_660,auStack_6c0);
  uVar24 = uStack_690;
  uStack_6d0 = 7;
  uStack_6c8 = 0xf;
  auStack_6e0 = ZEXT716((uint7)CONCAT16(DAT_18020e776,CONCAT24(_DAT_18020e774,_DAT_18020e770)));
  auStack_728 = ZEXT816(0);
  uStack_718 = 0;
  uStack_710 = 0;
  pauVar19 = &auStack_6a0;
  if (0xf < uStack_688) {
    pauVar19 = (undefined (*) [16])auStack_6a0._0_8_;
  }
  if (0x7fffffffffffffff < uStack_690) {
    func_0x000180052a50();
    pcVar3 = (code *)swi(3);
    pauVar19 = (undefined (*) [16])(*pcVar3)();
    return pauVar19;
  }
  if (uStack_690 < 0x10) {
    uStack_718 = uStack_690;
    uStack_710 = 0xf;
    auStack_728 = *pauVar19;
  }
  else {
    uVar22 = uStack_690 | 0xf;
    if (uVar22 < 0x8000000000000000) {
      if (uVar22 < 0x16) {
        uVar22 = 0x16;
      }
    }
    else {
      uVar22 = 0x7fffffffffffffff;
    }
    uVar18 = func_0x000180024110(uVar22 + 1);
    auStack_728._0_8_ = uVar18;
    uStack_718 = uVar24;
    uStack_710 = uVar22;
    func_0x0001801ca88d(uVar18,pauVar19,uVar24 + 1);
  }
  pcVar23 = auStack_728;
  if (0xf < uStack_710) {
    pcVar23 = (char *)auStack_728._0_8_;
  }
  pcVar25 = auStack_728;
  if (0xf < uStack_710) {
    pcVar25 = (char *)auStack_728._0_8_;
  }
  pcVar25 = pcVar25 + uStack_718;
  if (pcVar23 != pcVar25) {
    do {
      cVar10 = tolower((int)*pcVar23);
      *pcVar23 = cVar10;
      pcVar23 = pcVar23 + 1;
    } while (pcVar23 != pcVar25);
  }
  pcVar23 = auStack_728;
  if (0xf < uStack_710) {
    pcVar23 = (char *)auStack_728._0_8_;
  }
  pcVar25 = (char *)auStack_728._0_8_;
  if (uStack_718 < 10) {
LAB_180096733:
    puVar20 = auStack_6c0;
    if (0xf < uStack_6a8) {
      puVar20 = (undefined *)auStack_6c0._0_8_;
    }
    if (9 < uStack_6b0) {
      puVar1 = puVar20 + uStack_6b0;
      puVar16 = (undefined *)func_0x0001801278a0(puVar20,puVar1,&UNK_1819d8c20,10);
      if ((puVar16 != puVar1) && ((longlong)puVar16 - (longlong)puVar20 != -1)) goto LAB_180096775;
      pcVar25 = (char *)auStack_728._0_8_;
    }
    pcVar23 = auStack_728;
    if (0xf < uStack_710) {
      pcVar23 = pcVar25;
    }
    if (((uStack_718 < 3) ||
        (pcVar25 = pcVar23 + uStack_718,
        pcVar15 = (char *)func_0x0001801278a0(pcVar23,pcVar25,&UNK_1819d8c2c,3), pcVar15 == pcVar25)
        ) || ((longlong)pcVar15 - (longlong)pcVar23 == -1)) {
      puVar20 = auStack_6c0;
      if (0xf < uStack_6a8) {
        puVar20 = (undefined *)auStack_6c0._0_8_;
      }
      if (((uStack_6b0 < 3) ||
          (puVar1 = puVar20 + uStack_6b0,
          puVar16 = (undefined *)func_0x0001801278a0(puVar20,puVar1,&UNK_1819d8c30,3),
          puVar16 == puVar1)) || ((longlong)puVar16 - (longlong)puVar20 == -1)) goto LAB_18009691b;
    }
    uVar24 = uStack_6c8;
    if (uStack_6c8 < 0xe) {
      uVar22 = 0x7fffffffffffffff;
      if (uStack_6c8 <= 0x7fffffffffffffff - (uStack_6c8 >> 1)) {
        uVar2 = uStack_6c8 + (uStack_6c8 >> 1);
        uVar22 = 0xf;
        if (0xf < uVar2) {
          uVar22 = uVar2;
        }
      }
      puVar17 = (undefined8 *)func_0x000180024110(uVar22 + 1);
      uStack_6d0 = 0xe;
      *puVar17 = _DAT_1819d8c38;
      *(undefined4 *)(puVar17 + 1) = _DAT_1819d8c40;
      *(undefined2 *)((longlong)puVar17 + 0xc) = _DAT_1819d8c44;
      *(undefined *)((longlong)puVar17 + 0xe) = 0;
      uStack_6c8 = uVar22;
      if (0xf < uVar24) {
        if ((0xfff < uVar24 + 1) &&
           (0x1f < (auStack_6e0._0_8_ - *(longlong *)(auStack_6e0._0_8_ + -8)) - 8U)) {
          _invoke_watson(0,0,0,0,0);
          pcVar3 = (code *)swi(3);
          pauVar19 = (undefined (*) [16])(*pcVar3)();
          return pauVar19;
        }
        func_0x000180127e40();
      }
      auStack_6e0._0_8_ = puVar17;
    }
    else {
      puVar20 = auStack_6e0;
      if (0xf < uStack_6c8) {
        puVar20 = (undefined *)auStack_6e0._0_8_;
      }
      uStack_6d0 = 0xe;
      func_0x0001801ca893(puVar20,&DAT_1819d8c38,0xe);
      puVar20[0xe] = 0;
    }
  }
  else {
    pcVar25 = pcVar23 + uStack_718;
    pcVar15 = (char *)func_0x0001801278a0(pcVar23,pcVar25,&UNK_1819d8c10,10);
    if ((pcVar15 == pcVar25) || ((longlong)pcVar15 - (longlong)pcVar23 == -1)) {
      pcVar25 = (char *)auStack_728._0_8_;
      goto LAB_180096733;
    }
LAB_180096775:
    recovered_1800676d0(auStack_6e0,&UNK_1819d8c20,10);
  }
LAB_18009691b:
  apuStack_638[0] = &UNK_1819d8e48;
  __0__basic_ios_DU__char_traits_D_std___std__IEAA_XZ(auStack_5b0);
  uStack_708 = 0x22;
  __0__basic_ostream_DU__char_traits_D_std___std__QEAA_PEAV__basic_streambuf_DU__char_traits_D_std___1__N_Z
            (apuStack_638,apuStack_638 + 1,0,0);
  *(undefined **)((longlong)apuStack_638 + (longlong)*(int *)(apuStack_638[0] + 4)) = &UNK_180201ff8
  ;
  *(int *)((longlong)&iStack_63c + (longlong)*(int *)(apuStack_638[0] + 4)) =
       *(int *)(apuStack_638[0] + 4) + -0x88;
  __0__basic_streambuf_DU__char_traits_D_std___std__IEAA_XZ(apuStack_638 + 1);
  apuStack_638[1] = &UNK_1801f2638;
  uStack_5c8 = 0;
  uStack_5c0 = 4;
  puVar20 = auStack_6e0;
  if (0xf < uStack_6c8) {
    puVar20 = (undefined *)auStack_6e0._0_8_;
  }
  recovered_180078870(apuStack_638,puVar20,uStack_6d0);
  if (lStack_650 != 0) {
    uVar18 = recovered_180069ac0(apuStack_638,&UNK_1819d8c48);
    pppppppuVar21 = apppppppuStack_660;
    if (0xf < uStack_648) {
      pppppppuVar21 = apppppppuStack_660[0];
    }
    recovered_180078870(uVar18,pppppppuVar21,lStack_650);
  }
  uStack_670 = _DAT_181a03530;
  uStack_668 = _UNK_181a03538;
  auStack_680._1_15_ = SUB1615(ZEXT816(0),1);
  auVar6[15] = 0;
  auVar6._0_15_ = auStack_680._1_15_;
  auStack_680 = auVar6 << 8;
  uStack_708 = 0x2a;
  uStack_6f0 = 0;
  if ((((byte)uStack_5c0 & 0x22) == 2) || (uVar24 = *puStack_5f0, uVar24 == 0)) {
    if (((uStack_5c0 & 4) == 0) && (*plStack_5f8 != 0)) {
      auStack_700 = (undefined  [8])*plStack_618;
      uStack_6f8 = ((longlong)*piStack_5e0 - (longlong)auStack_700) + *plStack_5f8;
    }
    else {
      uStack_6f8 = 0;
      auStack_700 = (undefined  [8])0x0;
    }
  }
  else {
    auStack_700 = (undefined  [8])*plStack_610;
    if (uVar24 < uStack_5c8) {
      uVar24 = uStack_5c8;
    }
    uStack_6f8 = uVar24 - (longlong)auStack_700;
  }
  if (auStack_700 != (undefined  [8])0x0) {
    lVar13 = uStack_6f8;
    _auStack_700 = ZEXT816(0);
    recovered_1800676d0(auStack_680,_DAT_181a03530,lVar13);
  }
  uStack_6f0 = _DAT_181a035b0;
  uStack_6e8 = _UNK_181a035b8;
  uStack_6f8._0_2_ = _DAT_1819d8c58;
  auStack_700 = (undefined  [8])_DAT_1819d8c50;
  uStack_6f8._2_6_ = 0;
  recovered_180079c40(param_1,(undefined)aiStackX_10[0],auStack_700,auStack_680);
  if (0xf < uStack_6e8) {
    if ((0xfff < uStack_6e8 + 1) &&
       (0x1f < ((longlong)auStack_700 - *(longlong *)((longlong)auStack_700 + -8)) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar3 = (code *)swi(3);
      pauVar19 = (undefined (*) [16])(*pcVar3)();
      return pauVar19;
    }
    func_0x000180127e40();
  }
  if (0xf < uStack_668) {
    if ((0xfff < uStack_668 + 1) &&
       (0x1f < (auStack_680._0_8_ - *(longlong *)(auStack_680._0_8_ + -8)) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar3 = (code *)swi(3);
      pauVar19 = (undefined (*) [16])(*pcVar3)();
      return pauVar19;
    }
    func_0x000180127e40();
  }
  *(undefined **)((longlong)apuStack_638 + (longlong)*(int *)(apuStack_638[0] + 4)) = &UNK_180201ff8
  ;
  *(int *)((longlong)&iStack_63c + (longlong)*(int *)(apuStack_638[0] + 4)) =
       *(int *)(apuStack_638[0] + 4) + -0x88;
  apuStack_638[1] = &UNK_1801f2638;
  recovered_1800985e0(apuStack_638 + 1);
  __1__basic_streambuf_DU__char_traits_D_std___std__UEAA_XZ(apuStack_638 + 1);
  __1__basic_ostream_DU__char_traits_D_std___std__UEAA_XZ(auStack_628);
  __1__basic_ios_DU__char_traits_D_std___std__UEAA_XZ(auStack_5b0);
  recovered_180066e40(auStack_728);
  recovered_180066e40(auStack_6e0);
  recovered_180066e40(apppppppuStack_660);
  recovered_180066e40(auStack_6c0);
  recovered_180066e40(auStack_6a0);
  return param_1;
}

