/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180073f10(void)

{
  uint uVar1;
  longlong *plVar2;
  code *pcVar3;
  bool bVar4;
  float fVar5;
  undefined auVar6 [16];
  uint *puVar7;
  undefined8 *puVar8;
  char cVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined8 *puVar15;
  longlong *plVar16;
  longlong lVar17;
  undefined8 uVar18;
  uint *puVar19;
  undefined4 *puVar20;
  int *piVar21;
  undefined8 *puVar22;
  int iVar23;
  ulonglong uVar24;
  uint *puVar25;
  longlong lVar26;
  undefined8 *puVar27;
  ulonglong uVar28;
  undefined8 *puVar29;
  ulonglong unaff_R15;
  longlong unaff_GS_OFFSET;
  undefined8 extraout_XMM0_Qa;
  undefined8 extraout_XMM0_Qa_00;
  undefined8 extraout_XMM0_Qa_01;
  undefined8 extraout_XMM0_Qa_02;
  undefined8 extraout_XMM0_Qa_03;
  undefined4 uVar30;
  float fVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  undefined8 uStackX_8;
  undefined4 uStackX_10;
  undefined4 uStackX_14;
  uint uStackX_18;
  undefined4 uStackX_1c;
  undefined8 uStackX_20;
  undefined8 uStack_1c8;
  float fStack_1c0;
  undefined8 uStack_1b8;
  float fStack_1b0;
  int iStack_1a8;
  undefined4 uStack_1a4;
  undefined8 uStack_198;
  float fStack_190;
  float fStack_188;
  undefined4 uStack_184;
  undefined8 uStack_178;
  undefined4 uStack_170;
  undefined auStack_168 [8];
  undefined8 uStack_160;
  uint *puStack_158;
  uint *puStack_150;
  uint *puStack_148;
  uint uStack_140;
  int iStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined auStack_128 [8];
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined auStack_118 [8];
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined auStack_108 [8];
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined auStack_f8 [8];
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  float afStack_e0 [4];
  undefined auStack_d0 [152];
  
  puVar29 = (undefined8 *)0x0;
  DAT_181b2bec4 = 0;
  if ((DAT_181b2bede != '\0') &&
     (recovered_180067b80(&uStackX_8), uVar24 = uStackX_8,
     1999999999 < (longlong)(uStackX_8 - _DAT_181b2f4e0))) {
    recovered_18006e930();
    _DAT_181b2f4e0 = uVar24;
  }
  if (DAT_181b2bedd != '\0') {
    recovered_18006e930();
  }
  uVar1 = __tls_index;
  if (DAT_181b2bc70 != '\0') {
    if ((*(int *)(*(longlong *)(*(longlong *)(unaff_GS_OFFSET + 0x58) + (ulonglong)__tls_index * 8)
                 + 4) < _DAT_181b50884) &&
       (func_0x000180127a18(&DAT_181b50884), _DAT_181b50884 == -1)) {
      recovered_180067b80(&DAT_181b50920);
      func_0x0001801279ac(&DAT_181b50884);
    }
    recovered_180067b80(&uStackX_8);
    uVar24 = uStackX_8;
    if (29999999999 < (longlong)(uStackX_8 - _DAT_181b50920)) {
      if (0x400 < _DAT_181b2bf30) {
        recovered_180069a10(&DAT_181b2bf20);
      }
      _DAT_181b50920 = uVar24;
    }
  }
  if (_DAT_181b4efd8 == 0) {
    return;
  }
  iVar10 = recovered_180069360(_DAT_181b4efd8 + 0xa342efc);
  if (iVar10 == 0) {
    recovered_18006f2b0();
    return;
  }
  uVar11 = recovered_180069360(iVar10);
  if (uVar11 == 0) {
    recovered_18006f2b0();
    return;
  }
  iVar10 = recovered_180069360((ulonglong)uVar11 + 0x5c);
  if (iVar10 == 0) {
    recovered_18006f2b0();
    return;
  }
  uVar11 = recovered_180069360(iVar10);
  uVar24 = (ulonglong)uVar11;
  if (uVar11 == 0) {
    recovered_18006f2b0();
    return;
  }
  uVar11 = recovered_180069360(uVar24 + 0x50);
  iVar10 = 0;
  if (uVar11 != 0) {
    iVar10 = recovered_180069360((ulonglong)uVar11 + 0x8c);
  }
  if (DAT_181b2b581 == '\0') {
LAB_1800741b0:
    _DAT_181b302f8 = 0;
    _DAT_181b302fc = 0;
    DAT_181b302fa = '\0';
LAB_1800741c7:
    if (uVar11 == 0) {
      recovered_18006f2b0();
      return;
    }
    if (iVar10 == 0) {
      recovered_18006f2b0();
      return;
    }
    if (iVar10 != 1) {
      recovered_18006f2b0();
      return;
    }
  }
  else {
    if ((uVar11 == 0) || (iVar10 != 1)) {
      recovered_180067b80(&uStackX_8);
      if (DAT_181b302fa == '\0') {
        DAT_181b302fa = '\x01';
        _DAT_181b30308 = uStackX_8;
      }
      else if (1999999999 < (longlong)(uStackX_8 - _DAT_181b30308)) goto LAB_1800741b0;
      goto LAB_1800741c7;
    }
    DAT_181b302fa = '\0';
    if (uVar11 == _DAT_181b302fc) {
      if (((DAT_181b302f8 != '\0') && (DAT_181b302f9 == '\0')) &&
         (iVar10 = recovered_1800705d0(), iVar10 < 1)) {
        _DAT_181b302f8 = CONCAT11(1,DAT_181b302f8);
      }
    }
    else {
      _DAT_181b302fc = uVar11;
      puVar15 = (undefined8 *)recovered_180067b80(&uStackX_8);
      _DAT_181b30300 = *puVar15;
      _DAT_181b302f8 = 1;
      DAT_181b302fa = '\0';
    }
  }
  uVar12 = recovered_180069360((ulonglong)uVar11 + 0x94);
  uStackX_18 = uVar12;
  if (uVar12 == 0) {
LAB_18007421a:
    iVar10 = recovered_180069360(uVar11 + 0xb4);
    if (iVar10 != 0) goto LAB_180074229;
LAB_180074247:
    uStackX_20 = (uint *)CONCAT44(uStackX_20._4_4_,uVar12);
    uVar14 = uStackX_18;
    uVar11 = uVar12;
    if (uVar12 == 0) {
      return;
    }
  }
  else {
    iVar10 = recovered_180069360(uVar12 + 0xb4);
    if (iVar10 == 0) goto LAB_18007421a;
LAB_180074229:
    uVar11 = recovered_180069360(iVar10 + 0x28);
    uStackX_20 = (uint *)CONCAT44(uStackX_20._4_4_,uVar11);
    uVar14 = uVar11;
    if (uVar11 == 0) goto LAB_180074247;
  }
  uStackX_18 = uVar14;
  uVar28 = (ulonglong)uVar11;
  _DAT_181b2bebc = uVar11;
  if (DAT_181b2b5ef == '\0') {
    if (DAT_181b4efd3 != '\0') {
      LOCK();
      DAT_181b2f6d8 = 0;
      UNLOCK();
      DAT_181b2b5ef = '\0';
      DAT_181b4efd3 = '\0';
    }
  }
  else if (DAT_181b4efd3 == '\0') {
    recovered_18006f9b0();
    DAT_181b4efd3 = '\x01';
  }
  if (DAT_181b2b5fc == '\0') {
    if (_DAT_181b30314 != 0) {
      cVar9 = recovered_180067cc0((ulonglong)_DAT_181b30314 + 0x24,&uStackX_10);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_14,uStackX_10),&UNK_1819d7950,4);
      }
      _DAT_181b30314 = 0;
    }
  }
  else {
    uStackX_8 = uStackX_8 & 0xffffffff00000000;
    cVar9 = recovered_180067cc0(uVar24 + 0x10,&uStackX_10);
    if ((cVar9 != '\0') &&
       (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_14,uStackX_10),&uStackX_8,4),
       iVar10 == 0)) {
      if ((float)uStackX_8 != 0.0) {
        _DAT_181b30314 = (uint)(float)uStackX_8;
        cVar9 = recovered_180067cc0((uStackX_8 & 0xffffffff) + 0x24,&uStackX_10);
        if (cVar9 != '\0') {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_14,uStackX_10),&UNK_1819d7910,4);
        }
      }
    }
  }
  uStack_1c8 = uVar28;
  iVar10 = recovered_180069360(uVar28 + 0x28c);
  if (iVar10 == 0) {
    return;
  }
  uStack_178 = 0;
  uStack_170 = 0;
  recovered_18006bd40(iVar10,&uStack_178);
  _DAT_181b2beb0 = (undefined4)uStack_178;
  _DAT_181b2beb4 = uStack_178._4_4_;
  _DAT_181b2beb8 = uStack_170;
  uVar12 = recovered_180069360(uVar28 + 0x494);
  if (uVar12 == 0) {
    return;
  }
  iVar10 = recovered_180069360((ulonglong)uVar12 + 0x18);
  if (iVar10 == 0) {
    return;
  }
  uVar12 = recovered_180069360(iVar10 + 8);
  if (uVar12 == 0) {
    return;
  }
  _auStack_128 = ZEXT816(0);
  _auStack_118 = ZEXT816(0);
  _auStack_f8 = ZEXT816(0);
  _auStack_108 = _auStack_128;
  cVar9 = recovered_180067cc0((ulonglong)uVar12 + 0xe8,&uStackX_8);
  if (cVar9 == '\0') {
    if (_DAT_181b4ef90 == 0) {
      uVar18 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                   &UNK_1819d77a0);
      __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                (uVar18,&DAT_180069ca0);
    }
  }
  else {
    (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_8,auStack_128,0x40);
  }
  lVar17 = _DAT_181b2bde0;
  DAT_181b2bec4 = '\x01';
  _DAT_181b2be70 = auStack_128._0_4_;
  _DAT_181b2be74 = auStack_128._4_4_;
  _DAT_181b2be78 = uStack_120;
  _DAT_181b2be7c = uStack_11c;
  _DAT_181b2be80 = auStack_118._0_4_;
  _DAT_181b2be84 = auStack_118._4_4_;
  _DAT_181b2be88 = uStack_110;
  _DAT_181b2be8c = uStack_10c;
  _DAT_181b2be90 = auStack_108._0_4_;
  _DAT_181b2be94 = auStack_108._4_4_;
  _DAT_181b2be98 = uStack_100;
  _DAT_181b2be9c = uStack_fc;
  _DAT_181b2bea0 = auStack_f8._0_4_;
  _DAT_181b2bea4 = auStack_f8._4_4_;
  uRam0000000181b2bea8 = uStack_f0;
  _DAT_181b2beac = uStack_ec;
  if (DAT_181b2bdd0 == '\0') {
    lVar26 = _DAT_181b2bdd8;
    uVar11 = uStackX_18;
    if (_DAT_181b2bdd8 != _DAT_181b2bde0) {
      do {
        recovered_180066e40(lVar26 + 0x10);
        uVar11 = uStackX_18;
        lVar26 = lVar26 + 0x38;
      } while (lVar26 != lVar17);
      uVar33 = (uint)uStackX_20;
      _DAT_181b2bde0 = _DAT_181b2bdd8;
      uStackX_18 = uVar11;
      if (_DAT_181b2bdd8 != _DAT_181b2bde8) {
        recovered_180066d80(&DAT_181b2bdd8);
        uStackX_20 = (uint *)CONCAT44(uStackX_20._4_4_,uVar33);
        uStackX_18 = uVar11;
      }
    }
  }
  else {
    if ((*(int *)(*(longlong *)(*(longlong *)(unaff_GS_OFFSET + 0x58) + (ulonglong)uVar1 * 8) + 4) <
         _DAT_181b508d0) && (func_0x000180127a18(&DAT_181b508d0), _DAT_181b508d0 == -1)) {
      recovered_180067b80(&DAT_181b50830);
      func_0x0001801279ac(&DAT_181b508d0);
    }
    recovered_180067b80(&uStackX_8);
    uVar28 = uStackX_8;
    if (299999999 < (longlong)(uStackX_8 - _DAT_181b50830)) {
      recovered_18008c0f0(uVar24,&uStack_178);
      _DAT_181b50830 = uVar28;
    }
  }
  recovered_180067b80(&uStackX_8);
  if ((_DAT_181b4efc0 == 0) || (32999999 < (longlong)(uStackX_8 - _DAT_181b4efc0))) {
    uStackX_10 = CONCAT31(uStackX_10._1_3_,1);
    _DAT_181b4efc0 = uStackX_8;
  }
  else {
    uStackX_10 = (uint)uStackX_10._1_3_ << 8;
  }
  iVar10 = recovered_180069360(uVar24 + 0x68);
  if (iVar10 == 0) {
    recovered_18006f2b0();
    return;
  }
  iStack_13c = recovered_180069360(iVar10 + 0xc);
  if (iStack_13c == 0) {
    recovered_18006f2b0();
    return;
  }
  iStack_13c = iStack_13c + 0x1c;
  uVar13 = recovered_180069360(iVar10 + 0x10);
  uVar12 = _DAT_181b2bec0;
  uVar14 = _DAT_181b302f4;
  uStack_140 = uVar13;
  bVar4 = false;
  if (uVar13 != _DAT_181b2bec0) {
    iVar23 = uVar13 - _DAT_181b2bec0;
    iVar10 = -iVar23;
    if (0 < iVar23) {
      iVar10 = iVar23;
    }
    uVar12 = uVar13;
    uVar14 = uVar11;
    if ((5 < iVar10) || (bVar4 = false, _DAT_181b302f4 != uVar11)) {
      bVar4 = true;
      recovered_180078290(0x181b2be30);
      recovered_180069a10(&DAT_181b2bf20);
    }
  }
  _DAT_181b302f4 = uVar14;
  _DAT_181b2bec0 = uVar12;
  if (uVar13 == 0) {
    recovered_180073970();
    recovered_180073610();
    recovered_1800731b0();
    recovered_180070fd0();
    recovered_180072bf0();
    return;
  }
  if (DAT_181b2f2b9 == '\0') {
    LOCK();
    DAT_181b2f2b9 = '\x01';
    UNLOCK();
    uStackX_8 = func_0x000180127a94(1);
    auStack_168 = (undefined  [8])_beginthreadex(0,0,&DAT_18006a9f0,uStackX_8,0,&uStack_160);
    uVar33 = (undefined4)((ulonglong)uStack_160 >> 0x20);
    if (auStack_168 != (undefined  [8])0x0) {
      if (_DAT_181b2f458 != 0) {
        terminate();
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      uVar30 = SUB84(auStack_168,0);
      uVar32 = (undefined4)((ulonglong)auStack_168 >> 0x20);
      iVar10 = (int)uStack_160;
      _DAT_181b2f450 = _auStack_168;
      if (iVar10 == 0) {
        _auStack_168 = ZEXT816(0);
        __Throw_Cpp_error_std__YAXH_Z(1);
      }
      auStack_168._4_4_ = uVar32;
      auStack_168._0_4_ = uVar30;
      uStack_160._0_4_ = iVar10;
      uStack_160._4_4_ = uVar33;
      iVar10 = _Thrd_detach(auStack_168);
      if (iVar10 != 0) {
        __Throw_Cpp_error_std__YAXH_Z(1);
      }
      _DAT_181b2f450 = ZEXT816(0);
      goto LAB_1800747f8;
    }
    _auStack_168 = ZEXT812(0);
    uStack_160._4_4_ = uVar33;
    __Throw_Cpp_error_std__YAXH_Z(6);
LAB_1800748b4:
    if (_DAT_181b4ef90 == 0) {
      uVar18 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                   &UNK_1819d77a0);
      __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                (uVar18,&DAT_180069ca0);
    }
  }
  else {
LAB_1800747f8:
    puVar15 = _DAT_181b2f4e8;
    if (bVar4) {
      cVar9 = *(char *)((longlong)(longlong *)_DAT_181b2f4e8[1] + 0x19);
      plVar16 = (longlong *)_DAT_181b2f4e8[1];
      while (cVar9 == '\0') {
        func_0x000180023e30(&DAT_181b2f4e8,&DAT_181b2f4e8,plVar16[2]);
        plVar2 = (longlong *)*plVar16;
        func_0x000180127e40(plVar16,0x28);
        plVar16 = plVar2;
        cVar9 = *(char *)((longlong)plVar2 + 0x19);
      }
      puVar15[1] = puVar15;
      *puVar15 = puVar15;
      puVar15[2] = puVar15;
      _DAT_181b2f4f0 = 0;
    }
    unaff_R15 = uStack_1c8;
    if (DAT_181b2b400 == '\0') goto LAB_180074a27;
    uStackX_8 = 0;
    cVar9 = recovered_180067cc0(uStack_1c8 + 0x434,&uStack_1c8);
    if (cVar9 == '\0') goto LAB_1800748b4;
    (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,8);
  }
  uVar24 = uStackX_8;
  if (uStackX_8 != 0) {
    uStackX_8 = 0;
    cVar9 = recovered_180067cc0(uVar24 + 0x58,&uStack_1c8);
    if (cVar9 == '\0') {
      if (_DAT_181b4ef90 == 0) {
        uVar18 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                     &UNK_1819d77a0);
        __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                  (uVar18,&DAT_180069ca0);
      }
    }
    else {
      (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,8);
    }
    uVar24 = uStackX_8;
    if (uStackX_8 != 0) {
      uStackX_8 = uStackX_8 & 0xffffffff00000000;
      cVar9 = recovered_180067cc0(uVar24 + 0xc,&uStack_1c8);
      if (cVar9 == '\0') {
        if (_DAT_181b4ef90 == 0) {
          uVar18 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                       ,&UNK_1819d77a0);
          __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                    (uVar18,&DAT_180069ca0);
        }
      }
      else {
        (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,4);
      }
      if ((float)uStackX_8 != 0.0) {
        uStackX_8 = uStackX_8 & 0xffffffff00000000;
        cVar9 = recovered_180067cc0(uVar24 + 0xc,&uStack_1c8);
        if (cVar9 != '\0') {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,4);
        }
      }
    }
  }
LAB_180074a27:
  lVar17 = unaff_R15 + 0x500;
  if (DAT_181b2b5c0 == '\0') {
    uVar11 = recovered_180069360(lVar17);
    if (uVar11 != 0) {
      uStackX_8 = uStackX_8 & 0xffffffffffffff00;
      cVar9 = recovered_180067cc0((ulonglong)uVar11 + 0xc1,&uStack_1c8);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,1);
      }
    }
  }
  else {
    uVar11 = recovered_180069360(lVar17);
    if (uVar11 != 0) {
      uStackX_8 = CONCAT71(uStackX_8._1_7_,1);
      cVar9 = recovered_180067cc0((ulonglong)uVar11 + 0xc1,&uStack_1c8);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,1);
      }
    }
  }
  if (DAT_181b2bc68 == '\0') {
    uVar11 = recovered_180069360(lVar17);
    if (uVar11 != 0) {
      uStackX_8 = uStackX_8 & 0xffffffffffffff00;
      cVar9 = recovered_180067cc0((ulonglong)uVar11 + 0xe0,&uStack_1c8);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,1);
      }
    }
  }
  else {
    uVar11 = recovered_180069360(lVar17);
    if (uVar11 != 0) {
      uStackX_8 = CONCAT71(uStackX_8._1_7_,1);
      cVar9 = recovered_180067cc0((ulonglong)uVar11 + 0xe0,&uStack_1c8);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,1);
      }
    }
  }
  if (DAT_181b2b5e9 == '\0') {
    uVar11 = recovered_180069360(lVar17);
    fVar40 = _DAT_181a03230;
    if (uVar11 != 0) {
      uStackX_8 = CONCAT44(uStackX_8._4_4_,0x3f800000);
      cVar9 = recovered_180067cc0((ulonglong)uVar11 + _DAT_181b2bf68,&uStack_1c8);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,4);
      }
    }
  }
  else {
    uVar11 = recovered_180069360(lVar17);
    fVar40 = _DAT_181a03230;
    if (uVar11 != 0) {
      uStackX_8 = CONCAT44(uStackX_8._4_4_,0x3e99999a);
      cVar9 = recovered_180067cc0((ulonglong)uVar11 + _DAT_181b2bf68,&uStack_1c8);
      fVar40 = _DAT_181a03230;
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,4);
        fVar40 = _DAT_181a03230;
      }
    }
  }
  lVar26 = *(longlong *)(*(longlong *)(unaff_GS_OFFSET + 0x58) + (ulonglong)uVar1 * 8);
  if ((*(int *)(lVar26 + 4) < _DAT_181b50880) &&
     (func_0x000180127a18(&DAT_181b50880), _DAT_181b50880 == -1)) {
    recovered_180077f30(&DAT_181b50890);
    func_0x000180127e28(&DAT_1801d07a0);
    func_0x0001801279ac(&DAT_181b50880);
  }
  if ((*(int *)(lVar26 + 4) < _DAT_181b508d4) &&
     (func_0x000180127a18(&DAT_181b508d4), _DAT_181b508d4 == -1)) {
    recovered_180077f30(0x181b508e0);
    func_0x000180127e28(&DAT_1801d0780);
    func_0x0001801279ac(&DAT_181b508d4);
  }
  if ((*(int *)(lVar26 + 4) < _DAT_181b50838) &&
     (func_0x000180127a18(&DAT_181b50838), _DAT_181b50838 == -1)) {
    recovered_180077f30(0x181b50840);
    func_0x000180127e28(&DAT_1801d0760);
    func_0x0001801279ac(&DAT_181b50838);
  }
  if (DAT_181b2b5f4 == '\0') {
    if (_DAT_181b4efb8 != 0) {
      uStackX_8 = (ulonglong)uStackX_8._4_4_ << 0x20;
      cVar9 = recovered_180067cc0(lVar17,&uStack_1c8);
      if ((cVar9 != '\0') &&
         (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,4), iVar10 == 0)) {
        if ((float)uStackX_8 != 0.0) {
          fStack_188 = 1.0;
          cVar9 = recovered_180067cc0((uStackX_8 & 0xffffffff) + 0x1d8,&uStack_1c8);
          if (((cVar9 != '\0') &&
              (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&fStack_188,4), iVar10 == 0)) &&
             (_DAT_181a03114 < (float)((uint)(fStack_188 - fVar40) & _DAT_181a039d0))) {
            uVar24 = ((((uStackX_8 & 0xff ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                       uStackX_8 >> 8 & 0xff) * 0x100000001b3 ^ uStackX_8 >> 0x10 & 0xff) *
                      0x100000001b3 ^ uStackX_8 >> 0x18 & 0xff) * 0x100000001b3 & _DAT_181b508c0;
            puVar15 = *(undefined8 **)(_DAT_181b508a8 + 8 + uVar24 * 0x10);
            puVar22 = puVar29;
            if (puVar15 != _DAT_181b50898) {
              for (; (puVar22 = puVar15, (float)uStackX_8 != (float)*(int *)(puVar15 + 2) &&
                     (puVar22 = puVar29, puVar15 != *(undefined8 **)(_DAT_181b508a8 + uVar24 * 0x10)
                     )); puVar15 = (undefined8 *)puVar15[1]) {
              }
            }
            puVar15 = _DAT_181b50898;
            if (puVar22 != (undefined8 *)0x0) {
              puVar15 = puVar22;
            }
            lVar17 = (uStackX_8 & 0xffffffff) + 0x1d8;
            if (puVar15 == _DAT_181b50898) {
              uStack_1c8 = CONCAT44(uStack_1c8._4_4_,0x3f800000);
              cVar9 = recovered_180067cc0(lVar17,&iStack_1a8);
              if (cVar9 != '\0') {
                (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStack_1a4,iStack_1a8),&uStack_1c8,4);
              }
            }
            else {
              cVar9 = recovered_180067cc0(lVar17,&uStack_1c8);
              if (cVar9 != '\0') {
                (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_1c8,(longlong)puVar15 + 0x14,4);
              }
            }
          }
        }
      }
    }
    _DAT_181b4efb8 = 0;
    fVar31 = _DAT_181b4efb0;
  }
  else {
    if (DAT_181b2b5f5 == '\0') {
      DAT_181b2b5f5 = '\x01';
    }
    uStackX_8 = (ulonglong)uStackX_8._4_4_ << 0x20;
    cVar9 = recovered_180067cc0(lVar17,&uStack_1c8);
    fVar31 = _DAT_181b4efb0;
    if (((cVar9 != '\0') &&
        (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,4), fVar31 = _DAT_181b4efb0
        , iVar10 == 0)) && ((float)uStackX_8 != 0.0)) {
      if ((_DAT_181b4efb8 != 0) && ((float)_DAT_181b4efb8 != (float)uStackX_8)) {
        recovered_180077e30(&DAT_181b50890);
        recovered_180077e30(0x181b508e0);
        recovered_180077e30(0x181b50840);
        _DAT_181b4efb0 = 0.0;
      }
      fVar36 = _DAT_181a033a0;
      fVar35 = (_DAT_181b2b5f8 - fVar40) * _DAT_181a033a0;
      fStack_188 = 1.0;
      _DAT_181b4efb8 = (uint)(float)uStackX_8;
      cVar9 = recovered_180067cc0((ulonglong)(uint)(float)uStackX_8 + 0x1d8,&uStack_1c8);
      fVar31 = _DAT_181b4efb0;
      if ((cVar9 != '\0') &&
         (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&fStack_188,4), fVar5 = fStack_188,
         fVar31 = _DAT_181b4efb0, iVar10 == 0)) {
        uVar24 = ((((uStackX_8 & 0xff ^ 0xcbf29ce484222325) * 0x100000001b3 ^ uStackX_8 >> 8 & 0xff)
                   * 0x100000001b3 ^ uStackX_8 >> 0x10 & 0xff) * 0x100000001b3 ^
                 uStackX_8 >> 0x18 & 0xff) * 0x100000001b3 & _DAT_181b508c0;
        puVar15 = *(undefined8 **)(_DAT_181b508a8 + 8 + uVar24 * 0x10);
        puVar22 = puVar29;
        if (puVar15 != _DAT_181b50898) {
          for (; (puVar22 = puVar15, (float)uStackX_8 != (float)*(int *)(puVar15 + 2) &&
                 (puVar22 = puVar29, puVar15 != *(undefined8 **)(_DAT_181b508a8 + uVar24 * 0x10)));
              puVar15 = (undefined8 *)puVar15[1]) {
          }
        }
        puVar15 = _DAT_181b50898;
        if (puVar22 != (undefined8 *)0x0) {
          puVar15 = puVar22;
        }
        uVar18 = extraout_XMM0_Qa;
        if (puVar15 == _DAT_181b50898) {
          plVar16 = (longlong *)recovered_180078a40(puVar22,&uStack_138,&uStackX_8);
          *(float *)(*plVar16 + 0x14) = fVar5;
          uVar18 = extraout_XMM0_Qa_00;
        }
        plVar16 = (longlong *)recovered_180078a40(uVar18,&uStack_138,&uStackX_8);
        fVar31 = (fVar35 / fVar36) * _DAT_181a031ec + *(float *)(*plVar16 + 0x14);
        uStack_1c8 = CONCAT44(uStack_1c8._4_4_,fVar31);
        if (((_DAT_181a03114 < (float)((uint)(fStack_188 - fVar31) & _DAT_181a039d0)) ||
            (fVar31 = _DAT_181b4efb0,
            _DAT_181a03114 < (float)((uint)(_DAT_181b4efb0 - fVar35) & _DAT_181a039d0))) &&
           (cVar9 = recovered_180067cc0((uStackX_8 & 0xffffffff) + 0x1d8,&iStack_1a8),
           fVar31 = fVar35, cVar9 != '\0')) {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStack_1a4,iStack_1a8),&uStack_1c8,4);
        }
      }
    }
  }
  _DAT_181b4efb0 = fVar31;
  uVar1 = uStackX_18;
  recovered_180071ae0(uStackX_18);
  if (DAT_181b2b630 == '\0') {
    if (_DAT_181b2f470 != 0) {
      recovered_1800721a0();
    }
    plVar16 = (longlong *)recovered_180067b80(&uStackX_18);
    _DAT_181b302e0 = *plVar16;
  }
  else {
    iVar10 = 6;
    if (0 < _DAT_181b2b638) {
      iVar10 = _DAT_181b2b638;
    }
    recovered_180067b80(&uStackX_18);
    lVar17 = CONCAT44(uStackX_1c,uStackX_18);
    if ((((longlong)iVar10 * 1000000 <= lVar17 - _DAT_181b302e0) &&
        (_DAT_181b302e0 = lVar17, 0 < _DAT_181b2bec8)) &&
       ((0 < _DAT_181b2becc && ((DAT_181b2bec4 != '\0' && (uVar1 != 0)))))) {
      uStackX_8 = uStackX_8 & 0xffffffffffffff00;
      cVar9 = recovered_180067cc0(_DAT_181b50778 + unaff_R15,&uStackX_18);
      if ((cVar9 == '\0') ||
         ((iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,1),
          iVar10 != 0 || ((char)uStackX_8 == '\0')))) {
        recovered_1800721a0();
      }
      else {
        lVar17 = recovered_180072400(_DAT_181b2b634 == 1,_DAT_181b2b634 == 1);
        if (lVar17 == 0) {
          recovered_1800721a0();
        }
        else {
          recovered_1800727b0(lVar17);
        }
      }
    }
  }
  if (DAT_181b2b60d == '\0') {
    if (((DAT_181b4efc9 != '\0') && (DAT_181b4efe0 != '\0')) && (_DAT_181b2bebc != 0)) {
      uStackX_8 = uStackX_8 & 0xffffffff00000000;
      cVar9 = recovered_180067cc0((ulonglong)_DAT_181b2bebc + 0x494,&uStackX_18);
      if ((cVar9 != '\0') &&
         (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,4),
         iVar10 == 0)) {
        if (((float)uStackX_8 != 0.0) &&
           (cVar9 = recovered_180067cc0((uStackX_8 & 0xffffffff) + 100,&uStackX_18), cVar9 != '\0'))
        {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&DAT_181b4efd4,4);
        }
      }
    }
    DAT_181b4efc9 = '\0';
    DAT_181b4efe0 = '\0';
    fVar36 = _DAT_181a03364;
    fVar31 = _DAT_181a03124;
  }
  else {
    fVar36 = _DAT_181a03364;
    fVar31 = _DAT_181a03124;
    if (_DAT_181b2bebc != 0) {
      uStackX_18 = 0;
      cVar9 = recovered_180067cc0((ulonglong)_DAT_181b2bebc + 0x494,&uStackX_8);
      fVar36 = _DAT_181a03364;
      fVar31 = _DAT_181a03124;
      if (((cVar9 != '\0') &&
          (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_8,&uStackX_18,4),
          fVar36 = _DAT_181a03364, fVar31 = _DAT_181a03124, iVar10 == 0)) && (uStackX_18 != 0)) {
        if (DAT_181b4efe0 == '\0') {
          uStackX_8 = uStackX_8 & 0xffffffff00000000;
          cVar9 = recovered_180067cc0((ulonglong)uStackX_18 + 100,&iStack_1a8);
          if ((cVar9 != '\0') &&
             (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1a4,iStack_1a8),&uStackX_8,4
                                        ), iVar10 == 0)) {
            _DAT_181b4efd4 = (float)uStackX_8;
            if ((DAT_181b4efc9 != '\0') &&
               (_DAT_181a03124 < (float)((uint)_DAT_181b4efcc & _DAT_181a039d0))) {
              _DAT_181b4efd4 =
                   (float)uStackX_8 -
                   (_DAT_181b4efcc / _DAT_181a03364 + _DAT_181b4efcc / _DAT_181a03364);
            }
            DAT_181b4efe0 = '\x01';
            DAT_181b4efc9 = '\x01';
          }
        }
        fVar36 = _DAT_181a03364;
        fVar31 = _DAT_181a03124;
        uStack_1c8 = CONCAT44(uStack_1c8._4_4_,
                              _DAT_181b2b610 / _DAT_181a03364 + _DAT_181b2b610 / _DAT_181a03364 +
                              _DAT_181b4efd4);
        cVar9 = recovered_180067cc0((ulonglong)uStackX_18 + 100,&uStackX_8);
        if (cVar9 != '\0') {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,uStackX_8,&uStack_1c8,4);
        }
        _DAT_181b4efcc = _DAT_181b2b610;
      }
    }
  }
  if (DAT_181b2b614 == '\0') {
    if (((DAT_181b4efc8 != '\0') && (DAT_181b4efd0 != '\0')) && (_DAT_181b2bebc != 0)) {
      uStackX_8 = uStackX_8 & 0xffffffff00000000;
      cVar9 = recovered_180067cc0((ulonglong)_DAT_181b2bebc + 0x494,&uStackX_18);
      if ((cVar9 != '\0') &&
         (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,4),
         iVar10 == 0)) {
        if (((float)uStackX_8 != 0.0) &&
           (cVar9 = recovered_180067cc0((uStackX_8 & 0xffffffff) + 0x68,&uStackX_18), cVar9 != '\0')
           ) {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&DAT_181b4efe4,4);
        }
      }
    }
    DAT_181b4efc8 = '\0';
    DAT_181b4efd0 = '\0';
  }
  else if (_DAT_181b2bebc != 0) {
    uStackX_18 = 0;
    cVar9 = recovered_180067cc0((ulonglong)_DAT_181b2bebc + 0x494,&uStackX_8);
    if (((cVar9 != '\0') &&
        (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_8,&uStackX_18,4), iVar10 == 0)) &&
       (uStackX_18 != 0)) {
      if (DAT_181b4efd0 == '\0') {
        uStackX_8 = uStackX_8 & 0xffffffff00000000;
        cVar9 = recovered_180067cc0((ulonglong)uStackX_18 + 0x68,&iStack_1a8);
        if ((cVar9 != '\0') &&
           (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1a4,iStack_1a8),&uStackX_8,4),
           iVar10 == 0)) {
          _DAT_181b4efe4 = (float)uStackX_8;
          if ((DAT_181b4efc8 != '\0') && (fVar31 < (float)((uint)_DAT_181b4efb4 & _DAT_181a039d0)))
          {
            _DAT_181b4efe4 = (float)uStackX_8 - (_DAT_181b4efb4 / fVar36 + _DAT_181b4efb4 / fVar36);
          }
          DAT_181b4efd0 = '\x01';
          DAT_181b4efc8 = '\x01';
        }
      }
      uStack_1c8 = CONCAT44(uStack_1c8._4_4_,
                            _DAT_181b2b618 / fVar36 + _DAT_181b2b618 / fVar36 + _DAT_181b4efe4);
      cVar9 = recovered_180067cc0((ulonglong)uStackX_18 + 0x68,&uStackX_8);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,uStackX_8,&uStack_1c8,4);
      }
      _DAT_181b4efb4 = _DAT_181b2b618;
    }
  }
  uStackX_18 = 0x42960000;
  uStack_1c8 = uStack_1c8 & 0xffffffff00000000;
  uStackX_8 = uStackX_8 & 0xffffffff00000000;
  cVar9 = recovered_180067cc0(unaff_R15 + 0x494,&iStack_1a8);
  if ((cVar9 != '\0') &&
     (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1a4,iStack_1a8),&uStackX_8,4),
     iVar10 == 0)) {
    if ((float)uStackX_8 != 0.0) {
      if (DAT_181b2b60c == '\0') {
        if (DAT_181b4efca != '\0') {
          cVar9 = recovered_180067cc0((uStackX_8 & 0xffffffff) + 0x48,&iStack_1a8);
          if (cVar9 != '\0') {
            (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStack_1a4,iStack_1a8),&uStack_1c8,4);
          }
          DAT_181b4efca = '\0';
        }
      }
      else {
        cVar9 = recovered_180067cc0((uStackX_8 & 0xffffffff) + 0x48,&iStack_1a8);
        if (cVar9 != '\0') {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStack_1a4,iStack_1a8),&uStackX_18,4);
        }
        DAT_181b4efca = '\x01';
      }
    }
  }
  if (DAT_181b2b5f3 != '\0') {
    uStackX_8 = 0;
    cVar9 = recovered_180067cc0(unaff_R15 + 0x434,&uStackX_18);
    if (cVar9 == '\0') {
      if (_DAT_181b4ef90 == 0) {
        uVar18 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                     &UNK_1819d77a0);
        __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                  (uVar18,&DAT_180069ca0);
      }
    }
    else {
      (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,8);
    }
    uVar24 = uStackX_8;
    if (uStackX_8 != 0) {
      uStackX_8 = uStackX_8 & 0xffffffff00000000;
      cVar9 = recovered_180067cc0(uVar24 + 0x43c,&uStackX_18);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,4);
      }
      uStackX_8 = uStackX_8 & 0xffffffff00000000;
      cVar9 = recovered_180067cc0(uVar24 + 0x44,&uStackX_18);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,4);
      }
      uStackX_8 = uStackX_8 & 0xffffffff00000000;
      cVar9 = recovered_180067cc0(uVar24 + 0x444,&uStackX_18);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,4);
      }
      uStackX_8 = uStackX_8 & 0xffffffff00000000;
      cVar9 = recovered_180067cc0(uVar24 + 0x448,&uStackX_18);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,4);
      }
      uStackX_8 = 0;
      cVar9 = recovered_180067cc0(uVar24 + 0x58,&uStackX_18);
      if (cVar9 == '\0') {
        if (_DAT_181b4ef90 == 0) {
          uVar18 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                       ,&UNK_1819d77a0);
          __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                    (uVar18,&DAT_180069ca0);
        }
      }
      else {
        (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,8);
      }
      uVar28 = uStackX_8;
      if (uStackX_8 != 0) {
        uStackX_8 = CONCAT44(uStackX_8._4_4_,0x3a83126f);
        cVar9 = recovered_180067cc0(uVar28 + 0x120,&uStackX_18);
        if (cVar9 != '\0') {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,4);
        }
      }
      uStackX_8 = uStackX_8 & 0xffffffff00000000;
      cVar9 = recovered_180067cc0(uVar24 + 0x440,&uStackX_18);
      if (cVar9 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),&uStackX_8,4);
      }
    }
  }
  if (DAT_181b2b58d != '\0') {
    uStackX_18 = 0;
    cVar9 = recovered_180067cc0(_DAT_181a2b148 + unaff_R15,&uStackX_8);
    if (((cVar9 != '\0') &&
        (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_8,&uStackX_18,4), iVar10 == 0)) &&
       (uStackX_18 != 0)) {
      uStack_198 = (uint *)0x0;
      fStack_190 = 0.0;
      cVar9 = recovered_180067cc0(uStackX_18 + 8,&uStack_1c8);
      if (((cVar9 != '\0') &&
          (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,4), iVar10 == 0)) &&
         (cVar9 = recovered_18006bd40(uStackX_8 & 0xffffffff,&uStack_198), fVar36 = fStack_190,
         uVar18 = uStack_198, puVar15 = _DAT_181b2be38, fVar31 = _DAT_181a032ec, cVar9 != '\0')) {
        fVar35 = _DAT_181b2b590;
        if (_DAT_181b2b590 <= _DAT_181a0315c) {
          fVar35 = fVar40;
        }
        puVar27 = (undefined8 *)*_DAT_181b2be38;
        fVar5 = (float)uStack_198;
        puVar22 = puVar29;
        fVar37 = _DAT_181a03460;
        while( true ) {
          fVar34 = (float)((ulonglong)uVar18 >> 0x20);
          if (puVar27 == puVar15) break;
          uVar11 = *(uint *)((longlong)puVar27 + 0x9c);
          if (((((uVar11 != 0) && (uVar11 != uVar1)) &&
               (*(char *)((longlong)puVar27 + 0x19) != '\0')) &&
              ((*(char *)((longlong)puVar27 + 0x1a) == '\0' && (*(int *)(puVar27 + 6) != 0)))) &&
             ((DAT_181b2b406 == '\0' || (*(char *)((longlong)puVar27 + 0x1b) == '\0')))) {
            uStackX_8 = (ulonglong)uStackX_8._4_4_ << 0x20;
            cVar9 = recovered_180067cc0((ulonglong)uVar11 + _DAT_181a2b148,&iStack_1a8);
            if (((cVar9 != '\0') &&
                (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1a4,iStack_1a8),
                                            &uStackX_8,4), iVar10 == 0)) &&
               ((float)uStackX_8 != 0.0)) {
              uStack_1b8 = 0;
              fStack_1b0 = 0.0;
              cVar9 = recovered_180067cc0((int)(float)uStackX_8 + 8,&fStack_188);
              if (((cVar9 != '\0') &&
                  (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_184,fStack_188),
                                              &uStack_1c8,4), iVar10 == 0)) &&
                 (cVar9 = recovered_18006bd40(uStack_1c8 & 0xffffffff,&uStack_1b8), cVar9 != '\0'))
              {
                auStack_168 = (undefined  [8])uVar18;
                fVar34 = fVar34 - uStack_1b8._4_4_;
                fVar34 = fVar34 * fVar34 + (fVar5 - (float)uStack_1b8) * (fVar5 - (float)uStack_1b8)
                         + (fVar36 - fStack_1b0) * (fVar36 - fStack_1b0);
                if (fVar34 < 0.0) {
                  fVar34 = (float)func_0x0001801cb525();
                }
                else {
                  fVar34 = SQRT(fVar34);
                }
                if ((fVar34 <= fVar31) && (fVar34 < fVar37)) {
                  puVar22 = puVar27 + 3;
                  fVar37 = fVar34;
                }
              }
            }
          }
          puVar27 = (undefined8 *)*puVar27;
        }
        if ((puVar22 != (undefined8 *)0x0) && (*(uint *)((longlong)puVar22 + 0x84) != uVar1)) {
          uStackX_8 = (ulonglong)uStackX_8._4_4_ << 0x20;
          cVar9 = recovered_180067cc0((ulonglong)*(uint *)((longlong)puVar22 + 0x84) +
                                      _DAT_181a2b148,&uStack_1c8);
          if ((cVar9 != '\0') &&
             ((iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&uStackX_8,4), iVar10 == 0 &&
              ((float)uStackX_8 != 0.0)))) {
            uStack_1b8 = 0;
            fStack_1b0 = 0.0;
            cVar9 = recovered_180067cc0((int)(float)uStackX_8 + 8,&iStack_1a8);
            if ((cVar9 != '\0') &&
               ((iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1a4,iStack_1a8),
                                            &uStack_1c8,4), iVar10 == 0 &&
                (cVar9 = recovered_18006bd40(uStack_1c8 & 0xffffffff,&uStack_1b8), cVar9 != '\0'))))
            {
              fVar37 = (float)uStack_1b8 - fVar5;
              auStack_168 = (undefined  [8])uStack_1b8;
              fVar38 = (float)((ulonglong)uStack_1b8 >> 0x20) - uStack_198._4_4_;
              fVar39 = fStack_1b0 - fVar36;
              fVar31 = fVar38 * fVar38 + fVar37 * fVar37 + fVar39 * fVar39;
              if (fVar31 < 0.0) {
                fVar31 = (float)func_0x0001801cb525();
              }
              else {
                fVar31 = SQRT(fVar31);
              }
              if (fVar31 <= _DAT_181a0310c) {
                fVar37 = 0.0;
                fVar38 = 0.0;
              }
              else {
                fVar37 = fVar37 / fVar31;
                fVar38 = fVar38 / fVar31;
                fVar40 = fVar39 / fVar31;
              }
              fStack_1b0 = fVar36 + fVar35 * fVar40;
              uStack_1b8 = CONCAT44(fVar34 + fVar35 * fVar38,fVar37 * fVar35 + fVar5);
              fStack_188 = 0.0;
              cVar9 = recovered_180067cc0((int)(float)uStackX_8 + 8,&uStack_1c8);
              if (((cVar9 != '\0') &&
                  (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&fStack_188,4), iVar10 == 0)
                  ) && (fStack_188 != 0.0)) {
                iStack_1a8 = 0;
                cVar9 = recovered_180067cc0((int)fStack_188 + 8,&uStack_1c8);
                if (((cVar9 != '\0') &&
                    (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1c8,&iStack_1a8,4),
                    iVar10 == 0)) && (iStack_1a8 != 0)) {
                  uStack_1c8 = uStack_1c8 & 0xffffffff00000000;
                  cVar9 = recovered_180067cc0(iStack_1a8 + 0x20,&uStack_198);
                  if (((cVar9 != '\0') &&
                      (iVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_198,&uStack_1c8,4),
                      iVar10 == 0)) &&
                     (((float)uStack_1c8 != 0.0 &&
                      (cVar9 = recovered_180067cc0((int)(float)uStack_1c8 + 0x60,&uStack_198),
                      cVar9 != '\0')))) {
                    (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_198,&uStack_1b8,0xc);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  iVar10 = iStack_13c;
  uVar1 = uStack_140;
  if ((char)uStackX_10 == '\0') {
    if (_DAT_181b2be40 != 0) {
      recovered_18006eb70(&uStack_178);
    }
    recovered_180073970();
    recovered_180073610();
    recovered_1800731b0();
    recovered_180070fd0();
    recovered_180072bf0();
    return;
  }
  puStack_158 = (uint *)0x0;
  puStack_150 = (uint *)0x0;
  puStack_148 = (uint *)0x0;
  uVar11 = (uint)uStackX_20;
  puVar15 = puVar29;
LAB_180076170:
  do {
    uVar12 = (uint)puVar15;
    if (uVar1 <= uVar12) {
      puVar15 = (undefined8 *)*_DAT_181b2be38;
      puVar25 = puStack_150;
      puVar19 = puStack_158;
      puVar7 = puStack_150;
      fVar40 = _DAT_181a0337c;
      if (puVar15 != _DAT_181b2be38) {
        do {
          puVar22 = _DAT_181b2be38;
          if (puStack_158 != puVar25) {
            puVar19 = puStack_158;
            do {
              if (*(uint *)(puVar15 + 2) == *puVar19) {
                puVar22 = (undefined8 *)*puVar15;
                goto LAB_1800762ef;
              }
              puVar19 = puVar19 + 1;
            } while (puVar19 != puVar25);
          }
          uVar24 = (((((ulonglong)*(byte *)(puVar15 + 2) ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                     (ulonglong)*(byte *)((longlong)puVar15 + 0x11)) * 0x100000001b3 ^
                    (ulonglong)*(byte *)((longlong)puVar15 + 0x12)) * 0x100000001b3 ^
                   (ulonglong)*(byte *)((longlong)puVar15 + 0x13)) * 0x100000001b3 & _DAT_181b2be60;
          lVar17 = _DAT_181b2be48 + uVar24 * 0x10;
          puVar27 = *(undefined8 **)(_DAT_181b2be48 + uVar24 * 0x10);
          if (*(undefined8 **)(lVar17 + 8) == puVar15) {
            if (puVar27 == puVar15) {
              *(undefined8 **)(_DAT_181b2be48 + uVar24 * 0x10) = _DAT_181b2be38;
              *(undefined8 **)(lVar17 + 8) = puVar22;
            }
            else {
              *(undefined8 *)(lVar17 + 8) = puVar15[1];
            }
          }
          else if (puVar27 == puVar15) {
            *(undefined8 *)(_DAT_181b2be48 + uVar24 * 0x10) = *puVar15;
          }
          puVar22 = (undefined8 *)*puVar15;
          _DAT_181b2be40 = _DAT_181b2be40 + -1;
          *(undefined8 **)puVar15[1] = puVar22;
          puVar22[1] = puVar15[1];
          recovered_180066e40(puVar15 + 0xf);
          recovered_180066e40(puVar15 + 0xb);
          recovered_180066e40(puVar15 + 7);
          func_0x000180127e40(puVar15,400);
          puVar25 = puStack_150;
LAB_1800762ef:
          puVar15 = puVar22;
          puVar19 = puStack_158;
          puVar7 = puVar25;
          fVar40 = _DAT_181a0337c;
        } while (puVar22 != _DAT_181b2be38);
      }
      for (; uStack_198 = puVar7, uStackX_20 = puVar19, puVar19 != uStack_198; puVar19 = puVar19 + 1
          ) {
        uVar1 = *puVar19;
        uStackX_8 = CONCAT44(uStackX_8._4_4_,uVar1);
        uVar24 = ((((ulonglong)((int)uVar1 >> 8 & 0xff) ^
                   ((ulonglong)uVar1 & 0xff ^ 0xcbf29ce484222325) * 0x100000001b3) * 0x100000001b3 ^
                  (ulonglong)((int)uVar1 >> 0x10 & 0xff)) * 0x100000001b3 ^
                 (ulonglong)((int)uVar1 >> 0x18 & 0xff)) * 0x100000001b3 & _DAT_181b2be60;
        puVar15 = *(undefined8 **)(_DAT_181b2be48 + 8 + uVar24 * 0x10);
        puVar22 = puVar29;
        if (puVar15 != _DAT_181b2be38) {
          for (; (puVar22 = puVar15, uVar1 != *(uint *)(puVar15 + 2) &&
                 (puVar22 = puVar29, puVar15 != *(undefined8 **)(_DAT_181b2be48 + uVar24 * 0x10)));
              puVar15 = (undefined8 *)puVar15[1]) {
          }
        }
        puVar15 = _DAT_181b2be38;
        if (puVar22 != (undefined8 *)0x0) {
          puVar15 = puVar22;
        }
        uVar24 = (ulonglong)uVar1;
        if (puVar15 == _DAT_181b2be38) {
          uStackX_10 = uVar1;
          puVar15 = (undefined8 *)recovered_180078f90(0x181b2be30,auStack_d0,&uStackX_10);
          puVar15 = (undefined8 *)*puVar15;
          *(float *)((longlong)puVar15 + 0x9c) = (float)uStackX_8;
          puVar20 = (undefined4 *)recovered_180078170(extraout_XMM0_Qa_01,&uStackX_8);
          *puVar20 = 0;
          uVar24 = uStackX_8;
        }
        if (puVar15 + 3 == (undefined8 *)0x0) {
          uStack_1c8 = 0;
          fVar31 = 0.0;
        }
        else {
          uStack_1c8 = puVar15[0x14];
          fVar31 = *(float *)(puVar15 + 0x15);
        }
        fStack_1c0 = fVar31;
        cVar9 = recovered_1800767b0(uVar24 & 0xffffffff,puVar15 + 3,&uStack_178);
        if (cVar9 == '\0') {
          piVar21 = (int *)recovered_180078170(extraout_XMM0_Qa_02,&uStackX_8);
          if (*piVar21 < 5) {
            piVar21 = (int *)recovered_180078170(extraout_XMM0_Qa_03,&uStackX_8);
            *piVar21 = *piVar21 + 1;
          }
          else {
            uStackX_18 = (uint)(float)uStackX_8;
            recovered_180078370(0x181b2be30,&uStackX_18);
            cVar9 = *(char *)((longlong)(undefined8 *)_DAT_181b2f4e8[1] + 0x19);
            puVar15 = (undefined8 *)_DAT_181b2f4e8[1];
            uStack_160 = _DAT_181b2f4e8;
            auStack_168 = (undefined  [8])_DAT_181b2f4e8;
            while (puVar22 = puVar15, cVar9 == '\0') {
              if (*(uint *)((longlong)puVar22 + 0x1c) < (uint)(float)uStackX_8) {
                puVar15 = (undefined8 *)puVar22[2];
                puVar22 = (undefined8 *)auStack_168;
              }
              else {
                if ((*(char *)((longlong)uStack_160 + 0x19) != '\0') &&
                   ((uint)(float)uStackX_8 < *(uint *)((longlong)puVar22 + 0x1c))) {
                  uStack_160 = puVar22;
                }
                puVar15 = (undefined8 *)*puVar22;
              }
              cVar9 = *(char *)((longlong)puVar15 + 0x19);
              auStack_168 = (undefined  [8])puVar22;
            }
            puVar15 = _DAT_181b2f4e8 + 1;
            if (*(char *)((longlong)uStack_160 + 0x19) == '\0') {
              puVar15 = uStack_160;
            }
            cVar9 = *(char *)((longlong)(undefined8 *)*puVar15 + 0x19);
            puVar15 = (undefined8 *)*puVar15;
            while (cVar9 == '\0') {
              if ((uint)(float)uStackX_8 < *(uint *)((longlong)puVar15 + 0x1c)) {
                puVar22 = (undefined8 *)*puVar15;
                uStack_160 = puVar15;
              }
              else {
                puVar22 = (undefined8 *)puVar15[2];
              }
              puVar15 = puVar22;
              cVar9 = *(char *)((longlong)puVar22 + 0x19);
            }
            auVar6 = _auStack_168;
            auStack_168._4_4_ = (undefined4)((ulonglong)auStack_168 >> 0x20);
            uStack_160._4_4_ = (undefined4)((ulonglong)uStack_160 >> 0x20);
            uStack_138 = auStack_168._0_4_;
            uStack_134 = auStack_168._4_4_;
            uStack_130 = (undefined4)uStack_160;
            uStack_12c = uStack_160._4_4_;
            _auStack_168 = auVar6;
            recovered_180079580(puVar15,&uStack_138);
          }
        }
        else {
          puVar20 = (undefined4 *)recovered_180078170(extraout_XMM0_Qa_02,&uStackX_8);
          *puVar20 = 0;
          fVar36 = fStack_1c0;
          if ((((float)uStack_1c8 != 0.0) || (uStack_1c8._4_4_ != 0.0)) ||
             (fVar36 = fVar31, fVar31 != 0.0)) {
            uVar18 = puVar15[0x14];
            uStack_1b8._4_4_ = (float)((ulonglong)uVar18 >> 0x20);
            fVar31 = uStack_1b8._4_4_ - uStack_1c8._4_4_;
            uStack_1b8 = uVar18;
            if ((float *)((longlong)puVar15 + 0x184) != afStack_e0) {
              *(float *)((longlong)puVar15 + 0x184) = ((float)uVar18 - (float)uStack_1c8) * fVar40;
              *(float *)(puVar15 + 0x31) = fVar31 * fVar40;
              *(float *)((longlong)puVar15 + 0x18c) = (*(float *)(puVar15 + 0x15) - fVar36) * fVar40
              ;
            }
          }
          if (puVar15 + 0x2f != puVar15 + 0x14) {
            *(undefined4 *)(puVar15 + 0x2f) = *(undefined4 *)(puVar15 + 0x14);
            *(undefined4 *)((longlong)puVar15 + 0x17c) = *(undefined4 *)((longlong)puVar15 + 0xa4);
            *(undefined4 *)(puVar15 + 0x30) = *(undefined4 *)(puVar15 + 0x15);
          }
        }
        puVar25 = puStack_150;
        puVar7 = uStack_198;
      }
      puVar15 = (undefined8 *)*_DAT_181b2f4e8;
      puVar22 = _DAT_181b2f4e8;
      if (puVar15 != _DAT_181b2f4e8) {
        do {
          puVar19 = puStack_158;
          if (puStack_158 != puVar25) {
LAB_180076681:
            if (*(uint *)((longlong)puVar15 + 0x1c) != *puVar19) goto code_r0x00018007668a;
            puVar27 = (undefined8 *)puVar15[2];
            if (*(char *)((longlong)puVar27 + 0x19) == '\0') {
              cVar9 = *(char *)((longlong)(undefined8 *)*puVar27 + 0x19);
              puVar15 = puVar27;
              puVar27 = (undefined8 *)*puVar27;
              while (cVar9 == '\0') {
                cVar9 = *(char *)((longlong)(undefined8 *)*puVar27 + 0x19);
                puVar15 = puVar27;
                puVar27 = (undefined8 *)*puVar27;
              }
            }
            else {
              cVar9 = *(char *)((longlong)(undefined8 *)puVar15[1] + 0x19);
              puVar8 = (undefined8 *)puVar15[1];
              puVar27 = puVar15;
              while ((puVar15 = puVar8, cVar9 == '\0' && (puVar27 == (undefined8 *)puVar15[2]))) {
                cVar9 = *(char *)((longlong)(undefined8 *)puVar15[1] + 0x19);
                puVar8 = (undefined8 *)puVar15[1];
                puVar27 = puVar15;
              }
            }
            goto LAB_1800766aa;
          }
LAB_180076693:
          puVar15 = (undefined8 *)recovered_180079700(puVar19,puVar15);
          puVar25 = puStack_150;
          puVar22 = _DAT_181b2f4e8;
LAB_1800766aa:
        } while (puVar15 != puVar22);
      }
      _DAT_181b2bee0 = 0;
      for (puVar15 = (undefined8 *)*_DAT_181b2be38; puVar15 != _DAT_181b2be38;
          puVar15 = (undefined8 *)*puVar15) {
        if ((*(char *)((longlong)puVar15 + 0x19) != '\0') &&
           (*(char *)((longlong)puVar15 + 0x1a) == '\0')) {
          puVar29 = (undefined8 *)(ulonglong)((int)puVar29 + 1);
        }
        _DAT_181b2bee0 = SUB84(puVar29,0);
      }
      recovered_180073970();
      recovered_180073610();
      recovered_1800731b0();
      recovered_180070fd0();
      recovered_180072bf0();
      recovered_180079780(&puStack_158);
      return;
    }
    uVar14 = recovered_180069360(uVar12 * 0x10 + iVar10);
    uStackX_8 = CONCAT44(uStackX_8._4_4_,uVar14);
    if ((uVar14 == 0) || (uVar14 == uVar11)) {
LAB_1800761d2:
      puVar15 = (undefined8 *)(ulonglong)(uVar12 + 1);
      goto LAB_180076170;
    }
    if (puStack_150 == puStack_148) {
      recovered_18007a050(&puStack_158,puStack_150,&uStackX_8);
      goto LAB_1800761d2;
    }
    *puStack_150 = uVar14;
    puStack_150 = puStack_150 + 1;
    puVar15 = (undefined8 *)(ulonglong)(uVar12 + 1);
  } while( true );
code_r0x00018007668a:
  puVar19 = puVar19 + 1;
  if (puVar19 == puVar25) goto LAB_180076693;
  goto LAB_180076681;
}

