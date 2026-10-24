/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Removing unreachable block (ram,0x0001800aded0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800ad6a0(void)

{
  code *pcVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  undefined uVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 uVar14;
  char cVar15;
  undefined auVar16 [16];
  undefined auVar17 [16];
  short sVar18;
  int iVar19;
  undefined8 uVar20;
  longlong lVar21;
  bool bVar22;
  bool bVar23;
  longlong lStackX_20;
  undefined **in_stack_fffffffffffffcd8;
  longlong lStack_318;
  int iStack_310;
  undefined4 uStack_30c;
  undefined auStack_308 [8];
  undefined8 uStack_300;
  undefined auStack_2f8 [8];
  undefined8 uStack_2f0;
  undefined auStack_2e8 [8];
  undefined8 uStack_2e0;
  undefined *apuStack_2d8 [7];
  undefined **ppuStack_2a0;
  undefined *apuStack_298 [7];
  undefined **ppuStack_260;
  undefined *apuStack_258 [7];
  undefined **ppuStack_220;
  undefined *apuStack_218 [7];
  undefined **ppuStack_1e0;
  undefined *apuStack_1d8 [7];
  undefined **ppuStack_1a0;
  undefined *apuStack_198 [7];
  undefined **ppuStack_160;
  undefined *apuStack_158 [7];
  undefined **ppuStack_120;
  undefined *apuStack_118 [7];
  undefined **ppuStack_e0;
  undefined *apuStack_d8 [7];
  undefined **ppuStack_a0;
  undefined *apuStack_98 [7];
  undefined **ppuStack_60;
  
  uVar14 = _UNK_181a0393c;
  iVar13 = _UNK_181a03938;
  uVar12 = _UNK_181a03934;
  uVar11 = _DAT_181a03930;
  bVar8 = false;
  bVar9 = false;
  bVar2 = false;
  bVar3 = false;
  bVar4 = false;
  bVar5 = false;
  bVar6 = false;
  bVar22 = false;
  bVar10 = false;
  do {
    if ((_DAT_181b2f3a4 != 0) && (sVar18 = GetAsyncKeyState(), sVar18 < 0)) {
      if (bVar8) goto LAB_1800ad7b3;
      DAT_181b30590 = 1;
      uVar20 = func_0x000180127a94(1);
      in_stack_fffffffffffffcd8 =
           (undefined **)((ulonglong)in_stack_fffffffffffffcd8 & 0xffffffff00000000);
      lVar21 = _beginthreadex(0,0,&DAT_1800b9bb0,uVar20,in_stack_fffffffffffffcd8,&uStack_300);
      auVar17 = _auStack_308;
      auStack_308 = (undefined  [8])lVar21;
      auVar16 = _auStack_308;
      if (lVar21 != 0) {
        uStack_300._0_4_ = auVar17._8_4_;
        if ((int)uStack_300 != 0) {
          uStack_300._4_4_ = auVar17._12_4_;
          iStack_310 = (int)uStack_300;
          uStack_30c = uStack_300._4_4_;
          lStack_318 = lVar21;
          _auStack_308 = auVar16;
          iVar19 = _Thrd_detach(&lStack_318);
          auVar16 = _auStack_308;
          if (iVar19 == 0) {
            _auStack_308 = ZEXT816(0);
            bVar8 = true;
            goto LAB_1800ad7b3;
          }
        }
        _auStack_308 = auVar16;
        __Throw_Cpp_error_std__YAXH_Z(1);
      }
      uStack_300._0_4_ = 0;
      __Throw_Cpp_error_std__YAXH_Z(6);
      auVar17 = _auStack_2f8;
      goto LAB_1800ae40b;
    }
    bVar8 = false;
LAB_1800ad7b3:
    if ((_DAT_181b2f3a0 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      bVar9 = false;
    }
    else if (!bVar9) {
      DAT_181b30592 = 1;
      uVar20 = func_0x000180127a94(1);
      in_stack_fffffffffffffcd8 =
           (undefined **)((ulonglong)in_stack_fffffffffffffcd8 & 0xffffffff00000000);
      lVar21 = _beginthreadex(0,0,&DAT_1800b9c30,uVar20,in_stack_fffffffffffffcd8,&uStack_2f0);
      auVar16 = _auStack_2f8;
      auStack_2f8 = (undefined  [8])lVar21;
      auVar17 = _auStack_2f8;
      if (lVar21 != 0) {
        uStack_2f0._0_4_ = auVar16._8_4_;
        if ((int)uStack_2f0 != 0) {
          uStack_2f0._4_4_ = auVar16._12_4_;
          iStack_310 = (int)uStack_2f0;
          uStack_30c = uStack_2f0._4_4_;
          lStack_318 = lVar21;
          _auStack_2f8 = auVar17;
          iVar19 = _Thrd_detach(&lStack_318);
          auVar17 = _auStack_2f8;
          if (iVar19 == 0) {
            _auStack_2f8 = ZEXT816(0);
            bVar9 = true;
            goto LAB_1800ad868;
          }
        }
LAB_1800ae40b:
        _auStack_2f8 = auVar17;
        __Throw_Cpp_error_std__YAXH_Z(1);
      }
      uStack_2f0._0_4_ = 0;
      __Throw_Cpp_error_std__YAXH_Z(6);
      auVar17 = _auStack_2e8;
LAB_1800ae427:
      _auStack_2e8 = auVar17;
      __Throw_Cpp_error_std__YAXH_Z(1);
LAB_1800ae433:
      uStack_2e0._0_4_ = 0;
      __Throw_Cpp_error_std__YAXH_Z(6);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
LAB_1800ad868:
    if ((_DAT_181b32b7c == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      bVar22 = false;
      if ((_DAT_181b30424 == 2) && (DAT_181b2f8c9 != '\0')) {
        DAT_181b2f8c9 = '\x01';
LAB_1800ad94b:
        DAT_181b2b432 = 0;
        DAT_181b2b403 = 0;
        _DAT_181b2b430 = 0;
      }
    }
    else if (_DAT_181b30424 == 2) {
      if (DAT_181b2f8c9 == '\0') {
        DAT_181b2f8c9 = '\0';
        goto LAB_1800ad94b;
      }
    }
    else if (!bVar22) {
      DAT_181b2f8c9 = DAT_181b2f8c9 == '\0';
      _DAT_181b2b430 = 0;
      uVar7 = 0;
      DAT_181b2b403 = uVar7;
      DAT_181b2b432 = uVar7;
      if ((bool)DAT_181b2f8c9) {
        if (_DAT_181b30424 != 0) {
          if (_DAT_181b30424 == 1) {
            _DAT_181b2b430 = 1;
            bVar22 = true;
          }
          else {
            if (_DAT_181b30424 != 3) goto LAB_1800ad91c;
            DAT_181b2b432 = 1;
            bVar22 = true;
          }
          goto LAB_1800ad954;
        }
        DAT_181b2b403 = 1;
      }
LAB_1800ad91c:
      bVar22 = true;
    }
LAB_1800ad954:
    if ((_DAT_181b32b64 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      bVar2 = false;
    }
    else if (!bVar2) {
      apuStack_198[0] = &UNK_1819de468;
      ppuStack_160 = apuStack_198;
      apuStack_2d8[0] = &UNK_181a03050;
      ppuStack_2a0 = apuStack_2d8;
      DAT_181b3044e = DAT_181b3044e == '\0';
      in_stack_fffffffffffffcd8 = apuStack_198;
      recovered_1800abdc0(0x1e,DAT_181b3044e,&UNK_1819dcc68,apuStack_2d8,in_stack_fffffffffffffcd8);
      if (ppuStack_2a0 != (undefined **)0x0) {
        (**(code **)(*ppuStack_2a0 + 0x20))();
        ppuStack_2a0 = (undefined **)0x0;
      }
      if (ppuStack_160 != (undefined **)0x0) {
        (**(code **)(*ppuStack_160 + 0x20))();
      }
      bVar2 = true;
    }
    if ((_DAT_181b32b4c == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      bVar3 = false;
    }
    else if (!bVar3) {
      apuStack_158[0] = &UNK_1819ddf88;
      ppuStack_120 = apuStack_158;
      apuStack_298[0] = &UNK_1819de280;
      ppuStack_260 = apuStack_298;
      DAT_181b3044f = DAT_181b3044f == '\0';
      in_stack_fffffffffffffcd8 = apuStack_158;
      recovered_1800abdc0(0x1f,DAT_181b3044f,&UNK_1819dcc58,apuStack_298,in_stack_fffffffffffffcd8);
      if (ppuStack_260 != (undefined **)0x0) {
        (**(code **)(*ppuStack_260 + 0x20))();
        ppuStack_260 = (undefined **)0x0;
      }
      if (ppuStack_120 != (undefined **)0x0) {
        (**(code **)(*ppuStack_120 + 0x20))();
      }
      bVar3 = true;
    }
    if ((_DAT_181b303bc == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      bVar4 = false;
    }
    else if (!bVar4) {
      apuStack_118[0] = &UNK_1819ddc88;
      ppuStack_e0 = apuStack_118;
      apuStack_258[0] = &UNK_181a02f68;
      ppuStack_220 = apuStack_258;
      DAT_181b3049f = DAT_181b3049f == '\0';
      in_stack_fffffffffffffcd8 = apuStack_118;
      recovered_1800abdc0(0x6f,DAT_181b3049f,&UNK_1819dcc88,apuStack_258,in_stack_fffffffffffffcd8);
      if (ppuStack_220 != (undefined **)0x0) {
        (**(code **)(*ppuStack_220 + 0x20))();
        ppuStack_220 = (undefined **)0x0;
      }
      if (ppuStack_e0 != (undefined **)0x0) {
        (**(code **)(*ppuStack_e0 + 0x20))();
      }
      bVar4 = true;
    }
    if ((_DAT_181b30428 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      bVar5 = false;
    }
    else if (!bVar5) {
      apuStack_d8[0] = &UNK_1819ddd78;
      ppuStack_a0 = apuStack_d8;
      apuStack_218[0] = &UNK_1819de2d8;
      ppuStack_1e0 = apuStack_218;
      DAT_181b3055d = DAT_181b3055d == '\0';
      in_stack_fffffffffffffcd8 = apuStack_d8;
      recovered_1800abdc0(0x12d,DAT_181b3055d,&UNK_1819dcc78,apuStack_218,in_stack_fffffffffffffcd8)
      ;
      if (ppuStack_1e0 != (undefined **)0x0) {
        (**(code **)(*ppuStack_1e0 + 0x20))();
        ppuStack_1e0 = (undefined **)0x0;
      }
      if (ppuStack_a0 != (undefined **)0x0) {
        (**(code **)(*ppuStack_a0 + 0x20))();
      }
      bVar5 = true;
    }
    if ((_DAT_181b303b8 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      bVar6 = false;
    }
    else if (!bVar6) {
      apuStack_98[0] = &UNK_1819ddcf8;
      ppuStack_60 = apuStack_98;
      apuStack_1d8[0] = &UNK_1819ddf18;
      ppuStack_1a0 = apuStack_1d8;
      DAT_181b30438 = DAT_181b30438 == '\0';
      in_stack_fffffffffffffcd8 = apuStack_98;
      recovered_1800abdc0(8,DAT_181b30438,&UNK_1819dcca8,apuStack_1d8,in_stack_fffffffffffffcd8);
      if (ppuStack_1a0 != (undefined **)0x0) {
        (**(code **)(*ppuStack_1a0 + 0x20))();
        ppuStack_1a0 = (undefined **)0x0;
      }
      if (ppuStack_60 != (undefined **)0x0) {
        (**(code **)(*ppuStack_60 + 0x20))();
      }
      bVar6 = true;
    }
    if ((_DAT_181ade2b8 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      bVar10 = false;
    }
    else if (!bVar10) {
      recovered_180067b80(&lStackX_20);
      if (249999999 < lStackX_20 - _DAT_181b4f0d0) {
        _DAT_181b4f0d0 = lStackX_20;
        DAT_181b2bedd = 1;
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
        recovered_18009bbb0();
      }
      bVar10 = true;
    }
    if ((_DAT_181b2f3c8 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      DAT_181b4f115 = '\0';
    }
    else if (DAT_181b4f115 == '\0') {
      DAT_181b2bc6d = DAT_181b2bc6d == '\0';
      if ((bool)DAT_181b2bc6d) {
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
        recovered_18009bbb0();
        DAT_181b4f115 = '\x01';
      }
      else {
        lStack_318 = CONCAT44(uVar12,uVar11);
        iStack_310 = iVar13;
        uStack_30c = uVar14;
        recovered_18009bbb0();
        DAT_181b4f115 = '\x01';
      }
    }
    if ((_DAT_181b32b48 == 0) || (sVar18 = GetAsyncKeyState(), cVar15 = DAT_181b2f8cb, -1 < sVar18))
    {
      DAT_181b4f0e0 = '\0';
    }
    else if (DAT_181b4f0e0 == '\0') {
      bVar23 = DAT_181b2f6df == '\0';
      LOCK();
      DAT_181b2f8cb = '\x01';
      UNLOCK();
      DAT_181b30435 = bVar23;
      if (cVar15 == '\0') {
        if ((DAT_181b2f6df != '\0') && (DAT_181b2f6df == '\0')) {
          DAT_181b30435 = DAT_181b2f6df;
          LOCK();
          DAT_181b2f8cb = '\0';
          UNLOCK();
          DAT_181b4f0e0 = '\x01';
          goto LAB_1800adf72;
        }
        lStack_318 = func_0x000180127a94(1);
        *(bool *)lStack_318 = bVar23;
        in_stack_fffffffffffffcd8 =
             (undefined **)((ulonglong)in_stack_fffffffffffffcd8 & 0xffffffff00000000);
        lVar21 = _beginthreadex(0,0,&DAT_1800b9b80,lStack_318,in_stack_fffffffffffffcd8,&uStack_2e0)
        ;
        auVar16 = _auStack_2e8;
        auStack_2e8 = (undefined  [8])lVar21;
        auVar17 = _auStack_2e8;
        if (lVar21 == 0) goto LAB_1800ae433;
        uStack_2e0._0_4_ = auVar16._8_4_;
        if ((int)uStack_2e0 == 0) goto LAB_1800ae427;
        uStack_2e0._4_4_ = auVar16._12_4_;
        iStack_310 = (int)uStack_2e0;
        uStack_30c = uStack_2e0._4_4_;
        lStack_318 = lVar21;
        _auStack_2e8 = auVar17;
        iVar19 = _Thrd_detach(&lStack_318);
        auVar17 = _auStack_2e8;
        if (iVar19 != 0) goto LAB_1800ae427;
        _auStack_2e8 = ZEXT816(0);
      }
      DAT_181b4f0e0 = '\x01';
    }
LAB_1800adf72:
    if ((_DAT_181b2b44c == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      DAT_181b4f0e2 = '\0';
    }
    else if (DAT_181b4f0e2 == '\0') {
      DAT_181b2b444 = DAT_181b2b444 == '\0';
      if ((bool)DAT_181b2b444) {
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
        recovered_18009bbb0();
        DAT_181b4f0e2 = '\x01';
      }
      else {
        lStack_318 = CONCAT44(uVar12,uVar11);
        iStack_310 = iVar13;
        uStack_30c = uVar14;
        recovered_18009bbb0();
        DAT_181b4f0e2 = '\x01';
      }
    }
    if ((_DAT_181b32b78 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      DAT_181b4f0e3 = '\0';
    }
    else if (DAT_181b4f0e3 == '\0') {
      DAT_181b2b5e9 = DAT_181b2b5e9 == '\0';
      if ((bool)DAT_181b2b5e9) {
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
        recovered_18009bbb0();
        DAT_181b4f0e3 = '\x01';
      }
      else {
        lStack_318 = CONCAT44(uVar12,uVar11);
        iStack_310 = iVar13;
        uStack_30c = uVar14;
        recovered_18009bbb0();
        DAT_181b4f0e3 = '\x01';
      }
    }
    if ((_DAT_181b3042c == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      DAT_181b4f0b0 = '\0';
    }
    else if (DAT_181b4f0b0 == '\0') {
      DAT_181b2bedc = DAT_181b2bedc == '\0';
      if ((bool)DAT_181b2bedc) {
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
        recovered_18009bbb0();
        DAT_181b4f0b0 = '\x01';
      }
      else {
        lStack_318 = CONCAT44(uVar12,uVar11);
        iStack_310 = iVar13;
        uStack_30c = uVar14;
        recovered_18009bbb0();
        DAT_181b4f0b0 = '\x01';
      }
    }
    if ((_DAT_181b32b40 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      DAT_181b4f07c = '\0';
    }
    else if (DAT_181b4f07c == '\0') {
      DAT_181b2b5b6 = DAT_181b2b5b6 == '\0';
      if ((bool)DAT_181b2b5b6) {
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
        recovered_18009bbb0();
        DAT_181b4f07c = '\x01';
      }
      else {
        lStack_318 = CONCAT44(uVar12,uVar11);
        iStack_310 = iVar13;
        uStack_30c = uVar14;
        recovered_18009bbb0();
        DAT_181b4f07c = '\x01';
      }
    }
    if ((_DAT_181b2f39c == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      DAT_181b4f0a1 = '\0';
    }
    else if (DAT_181b4f0a1 == '\0') {
      DAT_181b2b5f1 = DAT_181b2b5f1 == '\0';
      if ((bool)DAT_181b2b5f1) {
        recovered_180077c40();
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
      }
      else {
        LOCK();
        DAT_181b2f64a = 0;
        UNLOCK();
        lStack_318 = CONCAT44(uVar12,uVar11);
        iStack_310 = iVar13;
        uStack_30c = uVar14;
      }
      recovered_18009bbb0();
      DAT_181b4f0a1 = '\x01';
    }
    if (DAT_181b2b5f1 == '\0') {
      if (DAT_181b4f114 != '\0') {
        LOCK();
        DAT_181b2f64a = 0;
        UNLOCK();
        DAT_181b4f114 = '\0';
      }
    }
    else if (DAT_181b4f114 == '\0') {
      recovered_180077c40();
      DAT_181b4f114 = '\x01';
    }
    if (((_DAT_181b30424 == 2) && (DAT_181b2f8c9 != '\0')) && (_DAT_181b2f398 != 0)) {
      sVar18 = GetAsyncKeyState();
      if (sVar18 < 0) {
        DAT_181b2b403 = 1;
        _DAT_181b2b414 = _DAT_181b2f398;
      }
      else {
        DAT_181b2b403 = 0;
        _DAT_181b2b414 = 1;
      }
    }
    if ((_DAT_181b30420 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      DAT_181b4f0a2 = '\0';
    }
    else if (DAT_181b4f0a2 == '\0') {
      DAT_181b2b5ef = DAT_181b2b5ef == '\0';
      if ((bool)DAT_181b2b5ef) {
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
        recovered_18009bbb0();
        DAT_181b4f0a2 = '\x01';
      }
      else {
        lStack_318 = CONCAT44(uVar12,uVar11);
        iStack_310 = iVar13;
        uStack_30c = uVar14;
        recovered_18009bbb0();
        DAT_181b4f0a2 = '\x01';
      }
    }
    if ((_DAT_181b32b54 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      DAT_181b4f0c1 = '\0';
    }
    else if (DAT_181b4f0c1 == '\0') {
      DAT_181b2b58d = DAT_181b2b58d == '\0';
      if ((bool)DAT_181b2b58d) {
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
        recovered_18009bbb0();
        DAT_181b4f0c1 = '\x01';
      }
      else {
        lStack_318 = CONCAT44(uVar12,uVar11);
        iStack_310 = iVar13;
        uStack_30c = uVar14;
        recovered_18009bbb0();
        DAT_181b4f0c1 = '\x01';
      }
    }
    if ((_DAT_181b32b50 == 0) || (sVar18 = GetAsyncKeyState(), -1 < sVar18)) {
      DAT_181b4f0e1 = '\0';
    }
    else if (DAT_181b4f0e1 == '\0') {
      DAT_181b2b5fc = DAT_181b2b5fc == '\0';
      if ((bool)DAT_181b2b5fc) {
        lStack_318 = CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
        iStack_310 = _DAT_181a2aff8;
        uStack_30c = _DAT_181a2affc;
        recovered_18009bbb0();
        DAT_181b4f0e1 = '\x01';
      }
      else {
        lStack_318 = CONCAT44(uVar12,uVar11);
        iStack_310 = iVar13;
        uStack_30c = uVar14;
        recovered_18009bbb0();
        DAT_181b4f0e1 = '\x01';
      }
    }
    lStack_318 = 10;
    recovered_1800693e0(&lStack_318);
  } while( true );
}

