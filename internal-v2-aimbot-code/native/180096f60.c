/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180096f60(void)

{
  code *pcVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  float fVar6;
  float fVar7;
  undefined4 uVar8;
  float fVar9;
  char cVar10;
  undefined auVar11 [16];
  undefined auVar12 [16];
  short sVar13;
  int iVar14;
  undefined4 uVar15;
  uint uVar16;
  longlong lVar17;
  longlong lVar18;
  undefined8 uVar19;
  undefined (*pauVar20) [16];
  undefined8 *puVar21;
  longlong *plVar22;
  char *pcVar23;
  char *pcVar24;
  char *pcVar25;
  ulonglong uVar26;
  longlong unaff_GS_OFFSET;
  bool bVar27;
  undefined **ppuStackX_8;
  longlong lStackX_10;
  undefined8 uStackX_18;
  undefined auStackX_20 [8];
  undefined8 in_stack_fffffffffffffd98;
  longlong *plVar28;
  undefined8 *puVar29;
  undefined8 uVar30;
  undefined8 in_stack_fffffffffffffda8;
  undefined auStack_238 [8];
  undefined8 uStack_230;
  longlong lStack_228;
  longlong lStack_220;
  undefined2 uStack_210;
  undefined4 uStack_20c;
  undefined8 uStack_208;
  undefined4 uStack_1f8;
  undefined4 uStack_1f4;
  int iStack_1f0;
  undefined4 uStack_1ec;
  undefined auStack_1e8 [16];
  undefined8 uStack_1d8;
  undefined *puStack_1d0;
  undefined *puStack_1c8;
  undefined uStack_1c0;
  undefined uStack_1bf;
  undefined uStack_1be;
  undefined uStack_1bd;
  longlong *plStack_1b8;
  undefined **ppuStack_198;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined8 uStack_180;
  undefined2 uStack_178;
  undefined uStack_176;
  undefined auStack_170 [16];
  undefined auStack_160 [16];
  undefined auStack_150 [16];
  undefined auStack_140 [8];
  undefined auStack_138 [16];
  undefined auStack_128 [16];
  undefined auStack_118 [16];
  undefined auStack_108 [16];
  undefined auStack_f8 [16];
  undefined auStack_e8 [16];
  undefined auStack_d8 [16];
  undefined8 uStack_c8;
  
  pcVar25 = (char *)0x0;
  lVar17 = GetModuleHandleA(&UNK_1819d8cb0);
  uVar16 = (uint)((ulonglong)in_stack_fffffffffffffd98 >> 0x20);
  if (lVar17 != 0) {
    lVar18 = GetProcAddress(lVar17,&UNK_1819d8cc0);
    uVar16 = (uint)((ulonglong)in_stack_fffffffffffffd98 >> 0x20);
    if (lVar18 != 0) {
      LOCK();
      bVar27 = _DAT_181b2f2d8 == 0;
      if (bVar27) {
        _DAT_181b2f2d8 = 1;
      }
      UNLOCK();
      pcVar24 = pcVar25;
      while (!bVar27) {
        Sleep((char *)0x1f < pcVar24);
        pcVar24 = pcVar24 + 1;
        LOCK();
        bVar27 = _DAT_181b2f2d8 == 0;
        if (bVar27) {
          _DAT_181b2f2d8 = 1;
        }
        UNLOCK();
      }
      if (_DAT_181b2f2e0 == 0) {
        _DAT_181b2f2e0 = HeapCreate(0,0,0);
      }
      LOCK();
      _DAT_181b2f2d8 = 0;
      UNLOCK();
      iVar14 = recovered_1800954f0(lVar18);
      uVar16 = (uint)((ulonglong)in_stack_fffffffffffffd98 >> 0x20);
      if (iVar14 == 0) {
        iVar14 = recovered_1800959f0(lVar18,1);
        uVar16 = (uint)((ulonglong)in_stack_fffffffffffffd98 >> 0x20);
        if (iVar14 == 0) {
          while (_DAT_181b4f040 == 0) {
            Sleep(10);
            uVar16 = (uint)((ulonglong)in_stack_fffffffffffffd98 >> 0x20);
          }
          _DAT_181b4efa0 = (code *)GetProcAddress(lVar17,&UNK_1819d8cd0);
          if (((_DAT_181b4efa0 != (code *)0x0) &&
              (_DAT_181b4ef78 = GetProcAddress(lVar17,&UNK_1819d8ce0), _DAT_181b4ef78 != 0)) &&
             (_DAT_181b4efa8 = GetProcAddress(lVar17,&UNK_1819d8cf8), _DAT_181b4efa8 != 0)) {
            _DAT_181b4ef90 = _DAT_181b4f040;
            (*_DAT_181b4efa0)(_DAT_181b4f040,0);
            recovered_180069a10(&DAT_181b2bf20);
            uVar19 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                         ,&UNK_1819d8d18);
            uVar19 = __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_PEBX_Z
                               (uVar19,_DAT_181b4ef90);
            __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                      (uVar19,&DAT_180069ca0);
            DAT_181b2f2bd = '\x01';
            goto LAB_18009715c;
          }
        }
      }
    }
  }
  if (DAT_181b2f2bd == '\0') {
    MessageBoxW(0,&UNK_1819d8d90,&UNK_1819d8d80,0);
  }
LAB_18009715c:
  ppuStackX_8 = (undefined **)func_0x000180127a94(1);
  uVar26 = (ulonglong)uVar16 << 0x20;
  auStack_238 = (undefined  [8])_beginthreadex(0,0,&DAT_1800986d0,ppuStackX_8,uVar26,&uStack_230);
  auVar12 = _auStack_238;
  if (auStack_238 != (undefined  [8])0x0) {
    if ((int)uStack_230 != 0) {
      auStack_238._4_4_ = (undefined4)((ulonglong)auStack_238 >> 0x20);
      uStack_1f8 = auStack_238._0_4_;
      uStack_1f4 = auStack_238._4_4_;
      iStack_1f0 = (int)uStack_230;
      uStack_1ec = uStack_230._4_4_;
      _auStack_238 = auVar12;
      iVar14 = _Thrd_detach(&uStack_1f8);
      auVar12 = _auStack_238;
      if (iVar14 == 0) {
        _auStack_238 = ZEXT816(0);
        ppuStackX_8 = (undefined **)func_0x000180127a94(1);
        puVar29 = &uStack_230;
        lVar17 = _beginthreadex(0,0,&DAT_180098700,ppuStackX_8,uVar26 & 0xffffffff00000000,puVar29);
        auVar12 = _auStack_238;
        auStack_238 = (undefined  [8])lVar17;
        auVar11 = _auStack_238;
        if (lVar17 != 0) {
          uStack_230._0_4_ = auVar12._8_4_;
          if ((int)uStack_230 != 0) {
            auStack_238._0_4_ = (undefined4)lVar17;
            auStack_238._4_4_ = (undefined4)((ulonglong)lVar17 >> 0x20);
            uStack_230._4_4_ = auVar12._12_4_;
            uStack_1f8 = auStack_238._0_4_;
            uStack_1f4 = auStack_238._4_4_;
            iStack_1f0 = (int)uStack_230;
            uStack_1ec = uStack_230._4_4_;
            _auStack_238 = auVar11;
            iVar14 = _Thrd_detach(&uStack_1f8);
            auVar11 = _auStack_238;
            if (iVar14 == 0) {
              _auStack_238 = ZEXT816(0);
              _DAT_181b2f368 = recovered_18009b420();
              if (_DAT_181b2f368 != 0) {
                GetClientRect(_DAT_181b2f368,&DAT_181b2f378);
                MapWindowPoints(_DAT_181b2f368,0,&DAT_181b2f378,2);
                DAT_181b2f2f9 = 1;
              }
              recovered_18009a390();
              if (((DAT_181b2f2fa != '\0') && (DAT_181b2f2fb != '\0')) &&
                 ((DAT_181b2f2f8 != '\0' && ((_DAT_181b2f350 != 0 && (_DAT_181b2f358 != 0)))))) {
                uStack_210 = 0;
                uStack_20c = 0;
                plVar28 = _DAT_181b2f360;
                uVar19 = func_0x0001800b0520(&lStack_228,_DAT_181b2f358,_DAT_181b2f368,
                                             _DAT_181b2f350,_DAT_181b2f360);
                _DAT_181b2f2f0 = &lStack_228;
                puStack_1d0 = &UNK_1819d8e18;
                puStack_1c8 = &DAT_1800b5a10;
                uStack_1c0 = ppuStackX_8._0_1_;
                uStack_1bf = ppuStackX_8._0_1_;
                uStack_1be = ppuStackX_8._0_1_;
                uStack_1bd = ppuStackX_8._0_1_;
                plStack_1b8 = &lStack_228;
                ppuStack_198 = &puStack_1d0;
                ppuStackX_8 = &puStack_1d0;
                recovered_18009acc0(uVar19,&puStack_1d0);
                if (ppuStack_198 != (undefined **)0x0) {
                  (**(code **)(*ppuStack_198 + 0x20))(ppuStack_198,ppuStack_198 != &puStack_1d0);
                  ppuStack_198 = (undefined **)0x0;
                }
                fVar9 = _DAT_181a03454;
                uVar8 = _DAT_181a032cc;
                fVar7 = _DAT_181a032a0;
                fVar6 = _DAT_181a03298;
                uVar5 = _DAT_181a03230;
                fVar4 = _DAT_181a031bc;
                fVar3 = _DAT_181a03134;
                auStack_170 = ZEXT816(0);
                uVar26 = (ulonglong)__tls_index;
                lVar17 = *(longlong *)(unaff_GS_OFFSET + 0x58);
                auStack_160 = auStack_170;
                auStack_150 = auStack_170;
                do {
                  if (_DAT_181b2f358 == 0) {
                    uVar19 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                                 ,&UNK_1819d8dc0);
                    __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                              (uVar19,&DAT_180069ca0);
                    break;
                  }
                  plVar28 = (longlong *)CONCAT44((int)((ulonglong)plVar28 >> 0x20),1);
                  iVar14 = PeekMessageA(auStack_170,_DAT_181b2f358,0,0,plVar28);
                  if (iVar14 != 0) {
                    TranslateMessage(auStack_170);
                    DispatchMessageA(auStack_170);
                  }
                  if (_DAT_181b2f2c0 != 0) {
                    *(char *)(_DAT_181b2f2c0 + 0x60) = (char)uStack_210;
                  }
                  if ((uStack_208._4_4_ != 0) || ((int)uStack_208 != 0)) {
                    if (_DAT_181b2f388 != (longlong *)0x0) {
                      (**(code **)(*_DAT_181b2f388 + 0x10))();
                      _DAT_181b2f388 = (longlong *)0x0;
                    }
                    DAT_181b2f2f8 = '\0';
                    if (_DAT_181b2f370 != (longlong *)0x0) {
                      puVar29 = (undefined8 *)((ulonglong)puVar29 & 0xffffffff00000000);
                      plVar28 = (longlong *)((ulonglong)plVar28 & 0xffffffff00000000);
                      (**(code **)(*_DAT_181b2f370 + 0x68))
                                (_DAT_181b2f370,0,uStack_208 & 0xffffffff,uStack_208._4_4_,plVar28,
                                 puVar29);
                      uStack_208 = 0;
                      recovered_18009aa70();
                    }
                  }
                  if ((((lStack_228 != 0) && (iVar14 = IsWindow(), iVar14 != 0)) &&
                      (uStack_208._4_4_ == 0)) && ((int)uStack_208 == 0)) {
                    sVar13 = GetAsyncKeyState(_DAT_181ade1f8);
                    uVar15 = (undefined4)((ulonglong)in_stack_fffffffffffffda8 >> 0x20);
                    if (sVar13 < 0) {
                      if (DAT_181b4f0a0 == '\0') {
                        DAT_181b4f0a0 = '\x01';
                        bVar27 = (char)uStack_210 == '\0';
                        uStack_210 = CONCAT11(uStack_210._1_1_,bVar27);
                        if (bVar27) {
                          SetWindowLongPtrA();
                          SetForegroundWindow(lStack_228);
                          if (_DAT_181b2f2c0 != 0) {
                            *(undefined *)(_DAT_181b2f2c0 + 0x60) = 1;
                          }
                        }
                        else {
                          SetWindowLongPtrA(lStack_228,0xffffffec);
                          lVar18 = _DAT_181b2f2c0;
                          if (_DAT_181b2f2c0 != 0) {
                            *(undefined *)(_DAT_181b2f2c0 + 0x60) = 0;
                            *(undefined2 *)(lVar18 + 0xda) = 0;
                            func_0x00018000a180(0,0);
                          }
                          if ((lStack_220 != 0) && (iVar14 = IsWindow(), iVar14 != 0)) {
                            SetForegroundWindow(lStack_220);
                          }
                        }
                        in_stack_fffffffffffffda8 = CONCAT44(uVar15,0x33);
                        puVar29 = (undefined8 *)((ulonglong)puVar29 & 0xffffffff00000000);
                        plVar28 = (longlong *)((ulonglong)plVar28 & 0xffffffff00000000);
                        SetWindowPos(lStack_228,0xffffffffffffffff,0,0,plVar28,puVar29,
                                     in_stack_fffffffffffffda8);
                      }
                    }
                    else {
                      DAT_181b4f0a0 = '\0';
                    }
                  }
                  if ((*(int *)(*(longlong *)(lVar17 + uVar26 * 8) + 4) < _DAT_181b509a8) &&
                     (func_0x000180127a18(&DAT_181b509a8), _DAT_181b509a8 == -1)) {
                    _DAT_181b50998 = ZEXT816(0xf) << 0x40;
                    DAT_181b50988_1 = SUB1615(ZEXT816(0),1);
                    auVar12[15] = 0;
                    auVar12._0_15_ = DAT_181b50988_1;
                    _DAT_181b50988 = auVar12 << 8;
                    func_0x000180127e28(&DAT_1801d0cb0);
                    func_0x0001801279ac(&DAT_181b509a8);
                  }
                  if (DAT_181b4f060 == '\0') {
                    DAT_181b4f060 = '\x01';
                    recovered_180067b80(auStackX_20);
                    pauVar20 = (undefined (*) [16])recovered_1800963a0(&uStack_190,_DAT_181b2f368);
                    if (pauVar20 != (undefined (*) [16])&DAT_181b50988) {
                      if (0xf < _DAT_181b509a0) {
                        if ((0xfff < _DAT_181b509a0 + 1) &&
                           (0x1f < (_DAT_181b50988 - *(longlong *)(_DAT_181b50988 + -8)) - 8U)) {
                          _invoke_watson(0,0,0,0,0);
                          pcVar1 = (code *)swi(3);
                          (*pcVar1)();
                          return;
                        }
                        func_0x000180127e40();
                      }
                      _DAT_181b50988 = *pauVar20;
                      _DAT_181b50998 = pauVar20[1];
                      *(undefined8 *)pauVar20[1] = 0;
                      *(undefined8 *)(pauVar20[1] + 8) = 0xf;
                      (*pauVar20)[0] = 0;
                    }
                    recovered_180066e40(&uStack_190);
                  }
                  recovered_180067b80(&lStackX_10);
                  cVar10 = DAT_181b2f2dc;
                  if ((DAT_181b2f2dc != '\0') && (DAT_181b4f038 == '\0')) {
                    puVar21 = (undefined8 *)recovered_180067b80(auStack_140);
                    _DAT_181b4f050 = *puVar21;
                    DAT_181b4f038 = '\x01';
                  }
                  if (((DAT_181b2f2df == '\0') || (DAT_181b2f2be == '\0')) ||
                     (DAT_181b2f2dd == '\0')) {
                    if (DAT_181b4f061 != '\0') goto LAB_180097789;
                  }
                  else {
                    if (DAT_181b4f061 == '\0') {
                      if (cVar10 != '\0') goto LAB_1800978a3;
                      plVar22 = (longlong *)recovered_180067b80(auStack_138);
                      _DAT_181b4f058 = *plVar22;
                      DAT_181b4f061 = '\x01';
                    }
LAB_180097789:
                    if (((DAT_181b4f048 == '\0') && (cVar10 == '\0')) &&
                       (fVar6 <= (float)(lStackX_10 - _DAT_181b4f058) / fVar9)) {
                      auStack_1e8 = ZEXT816(0);
                      uStack_c8 = 0;
                      uStack_1d8 = 0;
                      auStack_128._4_12_ = auStack_1e8._4_12_;
                      auStack_128._0_4_ = 0x68;
                      auStack_f8._0_12_ = auStack_1e8._0_12_;
                      auStack_f8._12_4_ = 1;
                      auStack_e8._2_14_ = auStack_1e8._2_14_;
                      auVar11._14_2_ = 0;
                      auVar11._0_14_ = auStack_e8._2_14_;
                      auStack_e8 = auVar11 << 0x10;
                      uStack_190 = _DAT_1819d8df0;
                      uStack_18c = _UNK_1819d8df4;
                      uStack_188 = _UNK_1819d8df8;
                      uStack_184 = _UNK_1819d8dfc;
                      uStack_180 = _DAT_1819d8e00;
                      uStack_178 = _DAT_1819d8e08;
                      uStack_176 = DAT_1819d8e0a;
                      in_stack_fffffffffffffda8 = 0;
                      puVar29 = (undefined8 *)CONCAT44((int)((ulonglong)puVar29 >> 0x20),0x8000000);
                      plVar28 = (longlong *)((ulonglong)plVar28 & 0xffffffff00000000);
                      auStack_118 = auStack_1e8;
                      auStack_108 = auStack_1e8;
                      auStack_d8 = auStack_1e8;
                      iVar14 = CreateProcessA(0,&uStack_190,0,0,plVar28,puVar29,0,0,auStack_128,
                                              auStack_1e8);
                      if (iVar14 != 0) {
                        WaitForSingleObject(auStack_1e8._0_8_,3000);
                        CloseHandle(auStack_1e8._0_8_);
                        CloseHandle(auStack_1e8._8_8_);
                      }
                      DAT_181b4f048 = '\x01';
                    }
                  }
LAB_1800978a3:
                  recovered_18009a990();
                  if (DAT_181b2bc70 != DAT_181b4f062) {
                    DAT_181b4f062 = DAT_181b2bc70;
                    uVar15 = 0x20;
                    if (DAT_181b2bc70 != '\0') {
                      uVar15 = 0x4000;
                    }
                    uVar19 = GetCurrentProcess();
                    SetPriorityClass(uVar19,uVar15);
                  }
                  if (((_DAT_181b2bec8 < 1) || (_DAT_181b2becc < 1)) ||
                     (iVar14 = IsIconic(_DAT_181b2f368), iVar14 != 0)) {
                    uStackX_18 = 0x14;
                    recovered_1800693e0(&uStackX_18);
                  }
                  else {
                    if (DAT_181b2bc6d != DAT_181b4f049) {
                      DAT_181b4f049 = DAT_181b2bc6d;
                      SetWindowDisplayAffinity(_DAT_181b2f358,-(DAT_181b2bc6d != '\0') & 0x11);
                    }
                    pcVar24 = pcVar25;
                    if ((_DAT_181b2f2c0 == 0) ||
                       (pcVar24 = *(char **)(_DAT_181b2f2c0 + 0xa0), pcVar24 == (char *)0x0)) {
                      _wassert(&UNK_1819d69d0,&UNK_1819d62f0);
                    }
                    if (*(longlong *)(pcVar24 + 0x48) == 0) {
                      func_0x00018004ff90();
                    }
                    func_0x0001800513f0();
                    if (DAT_181b2bc70 == '\0') {
                      if (_DAT_181b2f2c0 == 0) {
                        _wassert(&UNK_18020e450,&UNK_18020daf0);
                      }
                      *(float *)(_DAT_181b2f2c0 + 0xe18) =
                           *(float *)(_DAT_181b2f2c0 + 0xe18) * fVar7;
                    }
                    func_0x00018000b290();
                    if (_DAT_181b2f2c0 == 0) {
                      _wassert(&UNK_18020e450,&UNK_18020daf0);
                    }
                    fVar2 = *(float *)(_DAT_181b2f2c0 + 0x1c);
                    if (fVar3 <= *(float *)(_DAT_181b2f2c0 + 0x1c)) {
                      fVar2 = fVar3;
                    }
                    *(float *)(_DAT_181b2f2c0 + 0x1c) = fVar2;
                    if (DAT_181b2f2bd != '\0') {
                      recovered_180073f10();
                    }
                    if (DAT_181b2b46c != '\0') {
                      recovered_180082360();
                    }
                    if (DAT_181b2bdd0 != '\0') {
                      recovered_18008d390();
                    }
                    recovered_1800b1990(&lStack_228);
                    lVar18 = _DAT_181b2f2c0;
                    if ((DAT_181b2b5b5 != '\0') && (DAT_181b2bc70 == '\0')) {
                      uStack_1f8 = _DAT_181b2b5cc;
                      uStack_1f4 = uRam0000000181b2b5d0;
                      iStack_1f0 = iRam0000000181b2b5d4;
                      uStack_1ec = uRam0000000181b2b5d8;
                      if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
                        _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
                      }
                      lVar18 = func_0x00018000a880(**(undefined8 **)(lVar18 + 0x4908),0);
                      uVar16 = func_0x000180004f90(&uStack_1f8);
                      ppuStackX_8 = (undefined **)
                                    CONCAT44((float)_DAT_181b2becc * fVar4,
                                             (float)_DAT_181b2bec8 * fVar4);
                      if (((uVar16 & 0xff000000) != 0) && (fVar4 <= _DAT_181b2b410)) {
                        uVar30 = CONCAT44((int)((ulonglong)puVar29 >> 0x20),0x167);
                        uVar19 = CONCAT44((int)((ulonglong)plVar28 >> 0x20),uVar8);
                        func_0x0001800272e0(lVar18,&ppuStackX_8,_DAT_181b2b410 - fVar4,0,uVar19,
                                            uVar30);
                        puVar29 = (undefined8 *)CONCAT44((int)((ulonglong)uVar30 >> 0x20),uVar5);
                        plVar28 = (longlong *)CONCAT44((int)((ulonglong)uVar19 >> 0x20),1);
                        func_0x0001800258f0(lVar18,*(undefined8 *)(lVar18 + 0x80),
                                            *(undefined4 *)(lVar18 + 0x78),uVar16,plVar28,puVar29);
                        *(undefined4 *)(lVar18 + 0x78) = 0;
                      }
                    }
                    func_0x00018000d260();
                    func_0x00018000d750();
                    if ((_DAT_181b2f360 != (longlong *)0x0) && (_DAT_181b2f388 != (longlong *)0x0))
                    {
                      (**(code **)(*_DAT_181b2f360 + 0x108))(_DAT_181b2f360,1,&DAT_181b2f388);
                      (**(code **)(*_DAT_181b2f360 + 400))(_DAT_181b2f360,_DAT_181b2f388);
                    }
                    lVar18 = _DAT_181b2f2c0;
                    if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
                      _wassert(&UNK_180213478,&UNK_18020d8d0);
                    }
                    pcVar23 = (char *)(**(longlong **)(lVar18 + 0x4908) + 0x48);
                    pcVar24 = pcVar25;
                    if (*pcVar23 != '\0') {
                      pcVar24 = pcVar23;
                    }
                    func_0x00018004f320(pcVar24);
                    if (_DAT_181b2f370 != (longlong *)0x0) {
                      (**(code **)(*_DAT_181b2f370 + 0x40))(_DAT_181b2f370,1);
                    }
                    uStackX_18 = 1;
                    recovered_1800693e0(&uStackX_18);
                    if ((cVar10 != '\0') && (DAT_181b4f038 != '\0')) {
                      recovered_180067b80(auStack_238);
                    }
                    if (DAT_181b2bc6c != '\0') {
                      recovered_180099200();
                      if (_DAT_181b2f2f0 != (longlong *)0x0) {
                        func_0x0001800b5a60();
                        _DAT_181b2f2f0 = (longlong *)0x0;
                      }
                      if (_DAT_181b4ef88 != 0) {
                        iVar14 = recovered_1800959f0(_DAT_181b4ef88,0);
                        if (iVar14 != 0) {
                          uVar19 = recovered_180069ac0(
                                                  _cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                                  ,&UNK_1819d8c60);
                          __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                                    (uVar19,&DAT_180069ca0);
                        }
                        iVar14 = recovered_1800957d0();
                        if (iVar14 != 0) {
                          uVar19 = recovered_180069ac0(
                                                  _cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                                  ,&UNK_1819d8c88);
                          __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                                    (uVar19,&DAT_180069ca0);
                        }
                      }
                      LOCK();
                      bVar27 = _DAT_181b2f2d8 == 0;
                      if (bVar27) {
                        _DAT_181b2f2d8 = 1;
                      }
                      UNLOCK();
                      while (!bVar27) {
                        Sleep((char *)0x1f < pcVar25);
                        pcVar25 = pcVar25 + 1;
                        LOCK();
                        bVar27 = _DAT_181b2f2d8 == 0;
                        if (bVar27) {
                          _DAT_181b2f2d8 = 1;
                        }
                        UNLOCK();
                      }
                      if ((_DAT_181b2f2e0 != 0) &&
                         (iVar14 = recovered_1800953a0(0), puVar29 = _DAT_181b50ee0, iVar14 == 0)) {
                        _DAT_181b50ee0 = (undefined8 *)0x0;
                        while (puVar29 != (undefined8 *)0x0) {
                          puVar21 = (undefined8 *)*puVar29;
                          VirtualFree(puVar29,0,0x8000);
                          puVar29 = puVar21;
                        }
                        HeapFree(_DAT_181b2f2e0,0,_DAT_181b50ed0);
                        HeapDestroy(_DAT_181b2f2e0);
                        _DAT_181b2f2e0 = 0;
                        _DAT_181b50ed0 = 0;
                        _DAT_181b50ed8 = 0;
                      }
                      LOCK();
                      _DAT_181b2f2d8 = 0;
                      UNLOCK();
                      FreeConsole();
                      uVar19 = __acrt_iob_func(1);
                      fclose(uVar19);
                      DAT_181b2f2bf = 1;
                      if (_DAT_181b2f2e8 != 0) {
                        FreeLibraryAndExitThread(_DAT_181b2f2e8,0);
                      }
                      func_0x0001800b5a60(&lStack_228);
                      return;
                    }
                  }
                } while (auStack_170._8_4_ != 0x12);
                func_0x0001800b5a60(&lStack_228);
              }
              return;
            }
          }
          _auStack_238 = auVar11;
          __Throw_Cpp_error_std__YAXH_Z(1);
        }
        uStack_230._0_4_ = 0;
        __Throw_Cpp_error_std__YAXH_Z(6);
        auVar12 = _auStack_238;
      }
    }
    _auStack_238 = auVar12;
    __Throw_Cpp_error_std__YAXH_Z(1);
  }
  uStack_230._0_4_ = 0;
  __Throw_Cpp_error_std__YAXH_Z(6);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

