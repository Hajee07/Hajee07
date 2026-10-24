/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18009a390(void)

{
  code *pcVar1;
  ulonglong uVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined8 ******ppppppuVar13;
  undefined8 *puVar14;
  longlong lVar15;
  char *pcVar16;
  longlong *plStackX_8;
  undefined4 uStackX_10;
  undefined4 uStackX_14;
  undefined8 in_stack_fffffffffffffed8;
  undefined8 in_stack_fffffffffffffef0;
  undefined4 uVar17;
  undefined auStack_e8 [16];
  undefined auStack_d8 [16];
  undefined8 ******appppppuStack_c8 [2];
  undefined8 uStack_b8;
  ulonglong uStack_b0;
  uint uStack_a8;
  int iStack_a4;
  int iStack_a0;
  int iStack_9c;
  undefined8 uStack_98;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined8 uStack_84;
  undefined8 uStack_7c;
  undefined4 uStack_74;
  undefined8 uStack_70;
  longlong lStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  char acStack_34 [12];
  
  if (DAT_181b2f2f9 == '\0') {
    uVar7 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                &UNK_1819da800);
    __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
              (uVar7,&DAT_180069ca0);
    return;
  }
  uVar4 = _time64(0);
  srand(uVar4);
  auStack_e8 = ZEXT816(0);
  auStack_d8 = ZEXT816(0);
  puVar8 = (undefined8 *)func_0x000180024110(0x20);
  uVar9 = _UNK_181a035b8;
  auStack_e8._0_8_ = puVar8;
  auStack_d8._0_8_ = _DAT_181a035b0;
  auStack_d8._8_8_ = _UNK_181a035b8;
  *puVar8 = 0;
  puVar8[1] = 0;
  *(undefined4 *)(puVar8 + 2) = 0;
  *(undefined2 *)((longlong)puVar8 + 0x14) = 0;
  puVar14 = (undefined8 *)auStack_e8;
  if (7 < uVar9) {
    puVar14 = puVar8;
  }
  lVar15 = 10;
  do {
    iVar5 = rand();
    uVar4 = (undefined4)((ulonglong)in_stack_fffffffffffffed8 >> 0x20);
    uVar17 = (undefined4)((ulonglong)in_stack_fffffffffffffef0 >> 0x20);
    uVar9 = (ulonglong)iVar5;
    lVar10 = uVar9 + ((uVar9 - uVar9 / 7 >> 1) + uVar9 / 7 >> 2) * -7;
    *(short *)puVar14 = (short)(char)(&UNK_1819da768)[lVar10];
    puVar14 = (undefined8 *)((longlong)puVar14 + 2);
    lVar15 = lVar15 + -1;
  } while (lVar15 != 0);
  puVar11 = auStack_e8;
  if (7 < (ulonglong)auStack_d8._8_8_) {
    puVar11 = (undefined *)auStack_e8._0_8_;
  }
  puVar12 = auStack_e8;
  if (7 < (ulonglong)auStack_d8._8_8_) {
    puVar12 = (undefined *)auStack_e8._0_8_;
  }
  recovered_18009ab00(lVar10,puVar12,puVar11 + auStack_d8._0_8_ * 2);
  _DAT_181b2f340 = &DAT_181ade288;
  if (0xf < _DAT_181ade2a0) {
    _DAT_181b2f340 = _DAT_181ade288;
  }
  UnregisterClassA(_DAT_181b2f340,_DAT_181b2f318);
  _DAT_181b2f300 = 0x50;
  _DAT_181b2f304 = 3;
  _DAT_181b2f308 = &DAT_18009a300;
  _DAT_181b2f310 = 0;
  _DAT_181b2f318 = GetModuleHandleA(0);
  _DAT_181b2f320 = 0;
  _DAT_181b2f328 = LoadCursorA(0,0x7f00);
  _DAT_181b2f330 = CreateSolidBrush(0);
  _DAT_181b2f338 = 0;
  _DAT_181b2f348 = 0;
  sVar3 = RegisterClassExA(&DAT_181b2f300);
  if (sVar3 == 0) {
    uVar6 = GetLastError();
    uVar7 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                &UNK_1819da840);
    pcVar16 = acStack_34 + 1;
    uVar9 = (ulonglong)uVar6;
    do {
      pcVar16 = pcVar16 + -1;
      uVar2 = uVar9 / 10;
      *pcVar16 = (char)uVar9 + (char)uVar2 * -10 + '0';
      uVar9 = uVar2;
    } while ((int)uVar2 != 0);
    recovered_180078780(appppppuStack_c8,pcVar16,acStack_34 + 1,&plStackX_8);
    ppppppuVar13 = appppppuStack_c8;
    if (0xf < uStack_b0) {
      ppppppuVar13 = appppppuStack_c8[0];
    }
    uVar7 = recovered_180078870(uVar7,ppppppuVar13,uStack_b8);
    __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
              (uVar7,&DAT_180069ca0);
    recovered_180066e40(appppppuStack_c8);
  }
  else {
    uVar7 = GetModuleHandleA(0);
    _DAT_181b2f358 =
         CreateWindowExA(0x80800a8,_DAT_181b2f340,&UNK_18020df8a,0x90000000,
                         CONCAT44(uVar4,_DAT_181b2f378),_DAT_181b2f37c,
                         _DAT_181b2f380 - _DAT_181b2f378,
                         CONCAT44(uVar17,_DAT_181b2f384 - _DAT_181b2f37c),0,0,uVar7,0);
    if (_DAT_181b2f358 == 0) {
      uVar6 = GetLastError();
      uVar7 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                  &UNK_1819da880);
      pcVar16 = acStack_34 + 1;
      uVar9 = (ulonglong)uVar6;
      do {
        pcVar16 = pcVar16 + -1;
        uVar2 = uVar9 / 10;
        *pcVar16 = (char)uVar9 + (char)uVar2 * -10 + '0';
        uVar9 = uVar2;
      } while ((int)uVar2 != 0);
      recovered_180078780(appppppuStack_c8,pcVar16,acStack_34 + 1,&plStackX_8);
      ppppppuVar13 = appppppuStack_c8;
      if (0xf < uStack_b0) {
        ppppppuVar13 = appppppuStack_c8[0];
      }
      uVar7 = recovered_180078870(uVar7,ppppppuVar13,uStack_b8);
      __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                (uVar7,&DAT_180069ca0);
      recovered_180066e40(appppppuStack_c8);
    }
    else {
      uStack_a8 = _DAT_181b2f378;
      iStack_a4 = _DAT_181b2f37c;
      iStack_a0 = _DAT_181b2f380 - _DAT_181b2f378;
      iStack_9c = _DAT_181b2f384 - _DAT_181b2f37c;
      DwmExtendFrameIntoClientArea(_DAT_181b2f358,&uStack_a8);
      SetLayeredWindowAttributes(_DAT_181b2f358,0,0xff,2);
      ShowWindow(_DAT_181b2f358,10);
      UpdateWindow(_DAT_181b2f358);
      DAT_181b2f2fa = 1;
      uStack_84 = 0;
      uStack_70 = 2;
      uStack_58 = 2;
      uStack_98 = 0;
      uStack_90 = 0x4b;
      uStack_8c = 1;
      uStack_88 = 0x1c;
      uStack_7c = 1;
      uStack_74 = 0x20;
      lStack_68 = _DAT_181b2f358;
      uStack_60 = 1;
      uStackX_10 = 0xb000;
      uStackX_14 = 0xa000;
      iVar5 = D3D11CreateDeviceAndSwapChain
                        (0,1,0,0,&uStackX_10,2,7,&uStack_98,&DAT_181b2f370,&DAT_181b2f350,
                         &plStackX_8,&DAT_181b2f360);
      pcVar1 = _cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref;
      if (iVar5 == 0) {
        DAT_181b2f2fb = '\x01';
      }
      else {
        uVar6 = GetLastError();
        uVar7 = recovered_180069ac0(pcVar1,&UNK_1819da7b0 + uVar6);
        __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                  (uVar7,&DAT_180069ca0);
        if (DAT_181b2f2fb == '\0') goto LAB_18009a922;
      }
      if (((_DAT_181b2f370 != (longlong *)0x0) && (_DAT_181b2f350 != (longlong *)0x0)) &&
         (iVar5 = (**(code **)(*_DAT_181b2f370 + 0x48))(_DAT_181b2f370,0,&UNK_1819da758,&plStackX_8)
         , -1 < iVar5)) {
        (**(code **)(*_DAT_181b2f350 + 0x48))(_DAT_181b2f350,plStackX_8,0,&DAT_181b2f388);
        (**(code **)(*plStackX_8 + 0x10))();
        DAT_181b2f2f8 = 1;
        if (_DAT_181b2f360 != (longlong *)0x0) {
          (**(code **)(*_DAT_181b2f360 + 0x108))(_DAT_181b2f360,1,&DAT_181b2f388,0);
        }
      }
    }
  }
LAB_18009a922:
  if (7 < (ulonglong)auStack_d8._8_8_) {
    if ((0xfff < auStack_d8._8_8_ * 2 + 2U) &&
       (0x1f < (auStack_e8._0_8_ - *(longlong *)(auStack_e8._0_8_ + -8)) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    func_0x000180127e40();
  }
  return;
}

