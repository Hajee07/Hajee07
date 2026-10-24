/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800b1990(longlong param_1)

{
  double dVar1;
  code *pcVar2;
  bool bVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  undefined8 *puVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  undefined8 uVar17;
  undefined8 *puVar18;
  undefined8 uVar19;
  longlong lVar20;
  longlong lVar21;
  longlong *plVar22;
  float *pfVar23;
  float *pfVar24;
  longlong lVar25;
  longlong lVar26;
  undefined *puVar27;
  ulonglong uVar28;
  undefined8 *puVar29;
  ulonglong uVar30;
  ulonglong uVar31;
  longlong unaff_GS_OFFSET;
  float fVar32;
  float fVar33;
  float fVar34;
  undefined8 uVar35;
  undefined8 extraout_XMM0_Qa;
  undefined8 extraout_XMM0_Qb;
  undefined auVar36 [16];
  undefined auVar37 [16];
  float fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  float fVar42;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined8 uStackX_18;
  undefined8 uStackX_20;
  undefined8 in_stack_fffffffffffffde8;
  undefined8 uVar43;
  undefined8 *in_stack_fffffffffffffdf0;
  ulonglong uVar44;
  undefined8 **ppuVar45;
  undefined8 in_stack_fffffffffffffdf8;
  undefined8 in_stack_fffffffffffffe00;
  undefined *puVar46;
  undefined8 uStack_1e8;
  undefined8 *apuStack_1e0 [3];
  undefined auStack_1c8 [16];
  undefined8 *puStack_1b8;
  undefined8 **ppuStack_1a8;
  float fStack_1a0;
  float fStack_19c;
  undefined8 *puStack_198;
  undefined4 uStack_190;
  float fStack_18c;
  undefined8 uStack_188;
  int iStack_180;
  float fStack_17c;
  undefined4 uStack_178;
  undefined8 *apuStack_168 [7];
  undefined8 **ppuStack_130;
  undefined8 uStack_128;
  float fStack_120;
  float fStack_11c;
  undefined8 uStack_118;
  int iStack_110;
  float fStack_10c;
  undefined8 uStack_108;
  float afStack_100 [2];
  longlong lStack_f8;
  
  uVar11 = (undefined4)((ulonglong)in_stack_fffffffffffffdf8 >> 0x20);
  uVar12 = (undefined4)((ulonglong)in_stack_fffffffffffffe00 >> 0x20);
  uVar7 = (undefined4)((ulonglong)in_stack_fffffffffffffde8 >> 0x20);
  DAT_181b2bc71 = *(undefined *)(param_1 + 0x18);
  if (*(char *)(param_1 + 0x18) == '\0') {
    func_0x00018009bde0();
    return;
  }
  if (_DAT_181b2f2c0 == 0) {
    _wassert(&UNK_18020e450,&UNK_18020daf0,0xbe8);
  }
  lVar26 = _DAT_181b2f2c0;
  fVar40 = _DAT_181a03230;
  lStack_f8 = _DAT_181b2f2c0;
  if ((DAT_181b2bc6e != '\0') && (DAT_181b2bc70 == '\0')) {
    func_0x0001801cb4f5((float)*(double *)(_DAT_181b2f2c0 + 0x3e60) * _DAT_181a0315c);
    in_stack_fffffffffffffdf0 = &uStackX_8;
    uVar7 = (undefined4)((ulonglong)&uStackX_10 >> 0x20);
    func_0x0001800050f0();
    puVar13 = (undefined4 *)func_0x000180002310(&uStack_188);
    _DAT_181a2aff0 = *puVar13;
    _DAT_181a2aff4 = puVar13[1];
    _DAT_181a2aff8 = puVar13[2];
    _DAT_181a2affc = (float)puVar13[3];
  }
  uVar30 = (ulonglong)__tls_index;
  lVar25 = *(longlong *)(*(longlong *)(unaff_GS_OFFSET + 0x58) + uVar30 * 8);
  uVar28 = 0;
  if ((*(int *)(lVar25 + 4) < _DAT_181b50e68) &&
     (func_0x000180127a18(&DAT_181b50e68), _DAT_181b50e68 == -1)) {
    _DAT_181b509b8 = ZEXT816(0);
    _DAT_181b509c8 = (undefined8 *)0x0;
    func_0x000180127e28(&UNK_1801d1260);
    func_0x0001801279ac(&DAT_181b50e68);
  }
  if (DAT_181b4f07a == '\0') {
    uStackX_8 = &UNK_1819dcee0;
    puVar14 = (undefined8 *)func_0x000180024110(8);
    puVar18 = puVar14 + 1;
    *puVar14 = uStackX_8;
    uStackX_10 = &UNK_1819dcf0c;
    auStack_1c8 = ZEXT816(0);
    puStack_1b8 = (undefined8 *)0x0;
    apuStack_1e0[0] = puVar14;
    apuStack_1e0[1] = puVar18;
    apuStack_1e0[2] = puVar18;
    puVar15 = (undefined8 *)func_0x000180024110(8);
    puVar16 = puVar15 + 1;
    *puVar15 = uStackX_10;
    auStack_1c8._8_8_ = puVar16;
    auStack_1c8._0_8_ = puVar15;
    puVar29 = _DAT_181b509c0;
    if (_DAT_181b509c0 == _DAT_181b509c8) {
      puStack_1b8 = puVar16;
      func_0x0001800ba260(uStackX_10,_DAT_181b509c0,apuStack_1e0);
    }
    else {
      apuStack_1e0[2] = (undefined8 *)0x0;
      apuStack_1e0[1] = (undefined8 *)0x0;
      apuStack_1e0[0] = (undefined8 *)0x0;
      *_DAT_181b509c0 = puVar14;
      puVar29[1] = puVar18;
      puVar29[2] = puVar18;
      puStack_1b8 = (undefined8 *)0x0;
      auStack_1c8 = ZEXT816(0);
      puVar29[3] = puVar15;
      puVar29[4] = puVar16;
      puVar29[5] = puVar16;
      _DAT_181b509c0 = (undefined8 *)((longlong)_DAT_181b509c0 + 0x30);
    }
    func_0x000180066b10(auStack_1c8);
    func_0x000180066b10(apuStack_1e0);
    uStackX_8 = &UNK_1819dcf08;
    puVar14 = (undefined8 *)func_0x000180024110(8);
    puVar18 = puVar14 + 1;
    *puVar14 = uStackX_8;
    uStackX_10 = &UNK_1819dcf14;
    auStack_1c8 = ZEXT816(0);
    puStack_1b8 = (undefined8 *)0x0;
    apuStack_1e0[0] = puVar14;
    apuStack_1e0[1] = puVar18;
    apuStack_1e0[2] = puVar18;
    puVar15 = (undefined8 *)func_0x000180024110(8);
    puVar16 = puVar15 + 1;
    *puVar15 = uStackX_10;
    auStack_1c8._8_8_ = puVar16;
    auStack_1c8._0_8_ = puVar15;
    puVar29 = _DAT_181b509c0;
    if (_DAT_181b509c0 == _DAT_181b509c8) {
      puStack_1b8 = puVar16;
      func_0x0001800ba260(uStackX_10,_DAT_181b509c0,apuStack_1e0);
    }
    else {
      apuStack_1e0[2] = (undefined8 *)0x0;
      apuStack_1e0[1] = (undefined8 *)0x0;
      apuStack_1e0[0] = (undefined8 *)0x0;
      *_DAT_181b509c0 = puVar14;
      puVar29[1] = puVar18;
      puVar29[2] = puVar18;
      puStack_1b8 = (undefined8 *)0x0;
      auStack_1c8 = ZEXT816(0);
      puVar29[3] = puVar15;
      puVar29[4] = puVar16;
      puVar29[5] = puVar16;
      _DAT_181b509c0 = (undefined8 *)((longlong)_DAT_181b509c0 + 0x30);
    }
    func_0x000180066b10(auStack_1c8);
    func_0x000180066b10(apuStack_1e0);
    uStackX_8 = &UNK_1819dcf10;
    puVar14 = (undefined8 *)func_0x000180024110(8);
    puVar18 = puVar14 + 1;
    *puVar14 = &UNK_1819dcf10;
    uStackX_10 = &UNK_1819dcf20;
    auStack_1c8 = ZEXT816(0);
    puStack_1b8 = (undefined8 *)0x0;
    apuStack_1e0[0] = puVar14;
    apuStack_1e0[1] = puVar18;
    apuStack_1e0[2] = puVar18;
    puVar15 = (undefined8 *)func_0x000180024110(8);
    puVar16 = puVar15 + 1;
    *puVar15 = &UNK_1819dcf20;
    auStack_1c8._8_8_ = puVar16;
    auStack_1c8._0_8_ = puVar15;
    puVar29 = _DAT_181b509c0;
    if (_DAT_181b509c0 == _DAT_181b509c8) {
      puStack_1b8 = puVar16;
      func_0x0001800ba260(puVar16,_DAT_181b509c0,apuStack_1e0);
    }
    else {
      apuStack_1e0[2] = (undefined8 *)0x0;
      apuStack_1e0[1] = (undefined8 *)0x0;
      apuStack_1e0[0] = (undefined8 *)0x0;
      *_DAT_181b509c0 = puVar14;
      puVar29[1] = puVar18;
      puVar29[2] = puVar18;
      puStack_1b8 = (undefined8 *)0x0;
      auStack_1c8 = ZEXT816(0);
      puVar29[3] = puVar15;
      puVar29[4] = puVar16;
      puVar29[5] = puVar16;
      _DAT_181b509c0 = (undefined8 *)((longlong)_DAT_181b509c0 + 0x30);
    }
    func_0x0001800b59f0(apuStack_1e0);
    uStackX_8 = &UNK_1819dcf1c;
    apuStack_168[0] = &uStackX_8;
    apuStack_168[1] = &uStackX_10;
    func_0x0001800b7070(apuStack_1e0,apuStack_168);
    uStackX_10 = &UNK_1819dcf30;
    apuStack_168[0] = &uStackX_10;
    apuStack_168[1] = &uStackX_18;
    uVar35 = func_0x0001800b7070(auStack_1c8,apuStack_168);
    func_0x0001800b6ee0(uVar35,apuStack_1e0);
    func_0x0001800b59f0(apuStack_1e0);
    uStackX_8 = &UNK_1819dcf28;
    apuStack_168[0] = &uStackX_8;
    apuStack_168[1] = &uStackX_10;
    func_0x0001800b7070(apuStack_1e0,apuStack_168);
    uStackX_10 = &UNK_180213280;
    apuStack_168[0] = &uStackX_10;
    apuStack_168[1] = &uStackX_18;
    uVar35 = func_0x0001800b7070(auStack_1c8,apuStack_168);
    func_0x0001800b6ee0(uVar35,apuStack_1e0);
    func_0x0001800b59f0(apuStack_1e0);
    DAT_181b4f07a = '\x01';
    lVar26 = lStack_f8;
  }
  if ((*(int *)(lVar25 + 4) < _DAT_181b50a1c) &&
     (func_0x000180127a18(&DAT_181b50a1c), _DAT_181b50a1c == -1)) {
    uVar35 = func_0x0001800b6f60(apuStack_1e0);
    func_0x0001800a0b40(extraout_XMM0_Qa,uVar35);
    func_0x000180127e28(&UNK_1801d1250);
    func_0x0001801279ac(&DAT_181b50a1c);
  }
  if ((*(int *)(lVar25 + 4) < _DAT_181b509b0) &&
     (func_0x000180127a18(&DAT_181b509b0), _DAT_181b509b0 == -1)) {
    func_0x0001800a0fd0();
    func_0x000180127e28(&UNK_1801d1240);
    func_0x0001801279ac(&DAT_181b509b0);
  }
  _DAT_181b32b68 = _DAT_181b2f370;
  _DAT_181b32b58 = _DAT_181b2f388;
  if ((((_DAT_181b2f370 != 0) && (_DAT_181b2f388 != 0)) && (_DAT_181b32b70 != 0)) &&
     (_DAT_181b35b10 != 0)) {
    DAT_181a2b040 = DAT_181b2bc70 == '\0';
    func_0x00018009c7f0();
    func_0x00018009c6b0();
    if (DAT_181b2bc70 == '\0') {
      apuStack_168[0] = (undefined8 *)CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
      apuStack_168[1] = (undefined8 *)CONCAT44(_DAT_181a2affc,_DAT_181a2aff8);
      func_0x0001800a1ad0();
      apuStack_168[0] = (undefined8 *)CONCAT44(_DAT_181a2aff4,_DAT_181a2aff0);
      apuStack_168[1] = (undefined8 *)CONCAT44(_DAT_181a2affc,_DAT_181a2aff8);
      func_0x0001800a2d10();
    }
  }
  if (DAT_181b4f090 == '\0') {
    func_0x0001800a1030();
    recovered_180085a10(_DAT_181b2f350);
    DAT_181b4f090 = '\x01';
  }
  if (_DAT_181b2f2c0 == 0) {
    _wassert(&UNK_18020e450,&UNK_18020daf0,0x10b1);
  }
  lVar20 = _DAT_181b2f2c0;
  fVar38 = *(float *)(_DAT_181b2f2c0 + 0x1c) * _DAT_181a03314;
  if (DAT_181b2f8ca == '\0') {
    _DAT_181b32b44 = (0.0 - _DAT_181b32b44) * fVar38 + _DAT_181b32b44;
  }
  else {
    _DAT_181b32b44 = _DAT_181b32b44 + (_DAT_181a03420 - _DAT_181b32b44) * fVar38;
    if ((float)((uint)(_DAT_181b32b44 - _DAT_181a03420) & _DAT_181a039d0) < _DAT_181a0333c) {
      DAT_181b2f8ca = '\0';
    }
  }
  *(uint *)(_DAT_181b2f2c0 + 0x47f8) = *(uint *)(_DAT_181b2f2c0 + 0x47f8) | 2;
  *(ulonglong *)(lVar20 + 0x4818) = CONCAT44(_DAT_181b2b284,_DAT_181b2b280);
  *(undefined4 *)(lVar20 + 0x4800) = 1;
  func_0x000180011340(&UNK_1819d8b00,0,0x20c3);
  if (_DAT_181b2f2c0 == 0) {
    _wassert(&UNK_18020e450,&UNK_18020daf0,0x10b1);
  }
  lVar21 = _DAT_181b2f2c0;
  _DAT_181b4eed0 = *(float *)(_DAT_181b2f2c0 + 0x1c) * _DAT_181a032fc;
  lVar20 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
  fVar38 = *(float *)(undefined8 *)(lVar20 + 0x20);
  uStackX_8 = (undefined *)CONCAT44(uStackX_8._4_4_,fVar38);
  fVar41 = *(float *)(lVar20 + 0x24);
  uStackX_18 = *(undefined8 *)(lVar20 + 0x20);
  uStackX_10 = (undefined *)CONCAT44(uStackX_10._4_4_,fVar41);
  _DAT_181ade2e0 = (fVar40 - _DAT_181ade2e0) * _DAT_181b4eed0 + _DAT_181ade2e0;
  *(undefined *)(lVar20 + 0xb8) = 1;
  lVar20 = *(longlong *)(lVar21 + 0x3f10);
  _DAT_181b4eec4 = *(float *)(lVar20 + 0x24);
  _DAT_181b4eecc = _DAT_181b4eec4 + *(float *)(lVar20 + 0x2c);
  _DAT_181b4eec0 = *(float *)(lVar20 + 0x20);
  _DAT_181b4eec8 = _DAT_181b4eec0 + *(float *)(lVar20 + 0x28);
  uStack_108 = uStackX_18;
  func_0x000180016100(0,0,0);
  *(float *)(lVar26 + 0x37d0) = _DAT_181ade2e0;
  lVar20 = _DAT_181b2f2c0;
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  uVar35 = func_0x00018000a880(**(undefined8 **)(lVar20 + 0x4908),0,&UNK_18020ed28);
  puStack_198 = (undefined8 *)CONCAT44(_DAT_181a2b0a4,_DAT_181a2b0a0);
  uStack_190 = _DAT_181a2b0a8;
  fStack_18c = _DAT_181a2b0ac * *(float *)(lVar26 + 0x37d0);
  uStackX_20 = CONCAT44(fVar41 + _DAT_181b2b284,fVar38 + _DAT_181b2b280);
  uVar5 = func_0x000180004f90(&puStack_198);
  uVar31 = (ulonglong)in_stack_fffffffffffffdf0 & 0xffffffff00000000;
  uVar19 = CONCAT44(uVar7,_DAT_181a032ec);
  func_0x000180027d60(uVar35,&uStack_108,&uStackX_20,uVar5,uVar19,uVar31);
  lVar20 = _DAT_181b2f2c0;
  uVar7 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar5 = (undefined4)(uVar31 >> 0x20);
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  uVar35 = func_0x00018000a880(**(undefined8 **)(lVar20 + 0x4908),0,&UNK_18020ed28);
  fVar34 = _DAT_181a03298;
  puStack_198 = (undefined8 *)CONCAT44(_DAT_181a2b0a4,_DAT_181a2b0a0);
  uStack_190 = _DAT_181a2b0a8;
  fStack_18c = (_DAT_181a2b0ac * *(float *)(lVar26 + 0x37d0)) / _DAT_181a03298;
  fVar39 = fVar41 + _DAT_181a0338c;
  uStackX_20 = CONCAT44(fVar39,fVar38 + _DAT_181b2b280);
  uVar6 = func_0x000180004f90(&puStack_198);
  puVar18 = (undefined8 *)CONCAT44(uVar5,0x30);
  uVar19 = CONCAT44(uVar7,_DAT_181a032ec);
  func_0x000180027d60(uVar35,&uStack_108,&uStackX_20,uVar6,uVar19,puVar18);
  uVar7 = (undefined4)((ulonglong)uVar19 >> 0x20);
  if (_DAT_181b2f2c0 == 0) {
    _wassert(&UNK_18020e450,&UNK_18020daf0,0x10b1);
  }
  lVar21 = _DAT_181b2f2c0;
  fVar32 = fVar38 + _DAT_181b2b280;
  *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
  lVar20 = *(longlong *)(lVar21 + 0x3f10);
  fVar33 = (float)uStackX_18;
  *(float *)(lVar20 + 0x100) = (float)uStackX_18;
  fVar42 = uStackX_18._4_4_;
  *(float *)(lVar20 + 0x104) = uStackX_18._4_4_;
  *(undefined *)(lVar20 + 0x141) = 1;
  uStackX_18 = CONCAT44(fVar39 - fVar41,fVar32 - fVar38);
  func_0x000180038c00(&UNK_1819dcf48,&uStackX_18);
  cVar4 = func_0x00018000a3e0(0);
  if ((cVar4 != '\0') && (cVar4 = func_0x000180016380(0), cVar4 != '\0')) {
    uStackX_18 = *(undefined8 *)(lVar21 + 0xfc);
    lVar20 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
    uStackX_20 = *(undefined8 *)(lVar20 + 0x20);
    uVar35 = func_0x00018009b6a0(&puStack_198,&uStackX_20,&uStackX_18);
    func_0x000180015010(lVar20,uVar35,0);
  }
  lVar21 = _DAT_181b2f2c0;
  *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
  lVar20 = *(longlong *)(lVar21 + 0x3f10);
  *(float *)(lVar20 + 0x100) = fVar33;
  *(float *)(lVar20 + 0x104) = fVar42;
  *(undefined *)(lVar20 + 0x141) = 1;
  if (DAT_181b2bc70 == '\0') {
    lVar20 = *(longlong *)(lVar21 + 0x3f10);
    uStackX_18 = *(undefined8 *)(lVar20 + 0x28);
    uStackX_20 = *(undefined8 *)(lVar20 + 0x20);
    puVar16 = (undefined8 *)func_0x00018009b6a0(afStack_100,&uStackX_20,&uStackX_18);
    uVar35 = *puVar16;
    uVar19 = *(undefined8 *)(lVar20 + 0x20);
    uVar17 = func_0x00018000a9e0();
    uVar43 = CONCAT44(uVar7,_DAT_181a031fc);
    func_0x000180055330(uVar17,uVar19,uVar35,_DAT_181a032bc,uVar43);
    uVar7 = (undefined4)((ulonglong)uVar43 >> 0x20);
    if (DAT_181b2bc70 == '\0') {
      uVar35 = func_0x00018000a9e0();
      uStackX_18 = 0;
      uStackX_20 = *(undefined8 *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0x28);
      uStack_128 = *(undefined8 *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0x20);
      lVar20 = _DAT_181b2f2c0;
      func_0x00018009b6a0(&fStack_1a0,&uStack_128,&uStackX_20);
      uStackX_20 = *(undefined8 *)(*(longlong *)(lVar20 + 0x3f10) + 0x20);
      func_0x000180004f90(&DAT_181a2b0a0);
      puVar18 = &uStackX_18;
      func_0x00018002a070(uVar35,&uStackX_20);
    }
    fVar38 = (float)uStackX_8;
    fVar41 = (float)uStackX_10;
  }
  lVar20 = _DAT_181b2f2c0;
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  uVar35 = func_0x00018000a880(**(undefined8 **)(lVar20 + 0x4908),0,&UNK_18020ed28);
  puStack_198 = (undefined8 *)CONCAT44(_DAT_181a2b0a4,_DAT_181a2b0a0);
  uStack_190 = _DAT_181a2b0a8;
  fStack_18c = _DAT_181a2b0ac * *(float *)(lVar26 + 0x37d0);
  uStackX_18 = CONCAT44(fVar41 + _DAT_181b2b284,fVar38 + _DAT_181b2b280);
  fVar39 = fVar41 + _DAT_181a03384;
  uStackX_20 = CONCAT44(fVar39,fVar38 + 0.0);
  uVar5 = func_0x000180004f90(&puStack_198);
  uVar44 = (ulonglong)puVar18 & 0xffffffff00000000;
  uVar31 = CONCAT44(uVar7,_DAT_181a032ec);
  func_0x000180027d60(uVar35,&uStackX_20,&uStackX_18,uVar5,uVar31,uVar44);
  lVar20 = _DAT_181b2f2c0;
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  uVar35 = func_0x00018000a880(**(undefined8 **)(lVar20 + 0x4908),0,&UNK_18020ed28);
  puStack_198 = (undefined8 *)CONCAT44(_DAT_181b4f19c,_DAT_181b4f198);
  uStack_190 = _DAT_181b4f1a0;
  fStack_18c = _DAT_181b4f1a4 * *(float *)(_DAT_181b2f2c0 + 0x37d0);
  uStackX_18 = CONCAT44(fVar41 + _DAT_181a03388,fVar38 + _DAT_181b2b280);
  uStackX_20 = CONCAT44(fVar39,fVar38 + 0.0);
  uVar7 = func_0x000180004f90(&puStack_198);
  func_0x000180027d60(uVar35,&uStackX_20,&uStackX_18,uVar7,uVar31 & 0xffffffff00000000,
                      uVar44 & 0xffffffff00000000);
  lVar20 = _DAT_181b2f2c0;
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  uVar35 = func_0x00018000a880(**(undefined8 **)(lVar20 + 0x4908),0,&UNK_18020ed28);
  apuStack_168[0] = (undefined8 *)CONCAT44(_UNK_181a03814,_DAT_181a03810);
  apuStack_168[1] = (undefined8 *)CONCAT44(_UNK_181a0381c,_UNK_181a03818);
  uStackX_18 = 0x3f8000003f800000;
  uStackX_20 = 0;
  fStack_1a0 = fVar38 + _DAT_181b2b280;
  fStack_19c = fVar41 + _DAT_181b2b284;
  uVar7 = func_0x000180004f90(apuStack_168);
  puVar27 = (undefined *)CONCAT44(uVar12,_DAT_181a032ec);
  puVar18 = &uStackX_20;
  func_0x000180028b00(uVar35,_DAT_181b2f3a8,&uStack_108,&fStack_1a0,puVar18,&uStackX_18,
                      CONCAT44(uVar11,uVar7),puVar27);
  uVar7 = (undefined4)((ulonglong)puVar18 >> 0x20);
  if (DAT_181b2bc70 == '\0') {
    fVar38 = _DAT_181a2affc / _DAT_181a03248;
    lVar20 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
    uStackX_18 = *(undefined8 *)(lVar20 + 0x28);
    uStackX_20 = *(undefined8 *)(lVar20 + 0x20);
    puVar18 = (undefined8 *)func_0x00018009b6a0(&puStack_198,&uStackX_20,&uStackX_18);
    uVar35 = *puVar18;
    uStackX_18 = 0;
    uStackX_20 = *(undefined8 *)(lVar20 + 0x20);
    puVar18 = (undefined8 *)func_0x00018009b6a0(&uStack_128,&uStackX_20,&uStackX_18);
    uVar19 = *puVar18;
    uVar17 = func_0x00018000a9e0();
    uVar43 = CONCAT44(uVar7,fVar38);
    func_0x0001800a1f00(uVar17,uVar19,uVar35,_DAT_181a032ec,uVar43);
    uVar7 = (undefined4)((ulonglong)uVar43 >> 0x20);
    fVar38 = (float)uStackX_8;
    fVar34 = _DAT_181a03298;
  }
  if ((*(int *)(lVar25 + 4) < _DAT_181b509d4) &&
     (func_0x000180127a18(&DAT_181b509d4), _DAT_181b509d4 == -1)) {
    _DAT_181b50a00 = GetTickCount();
    func_0x0001801279ac(&DAT_181b509d4);
  }
  iVar8 = GetTickCount();
  if (0xf < (uint)(iVar8 - _DAT_181b50a00)) {
    if (DAT_181b4f092 == '\0') {
      if (_DAT_181b4f110 < 0x35) {
        _DAT_181b4f110 = _DAT_181b4f110 + 1;
      }
      else {
        DAT_181b4f092 = '\x01';
      }
    }
    else if (_DAT_181b4f110 < 1) {
      DAT_181b4f092 = '\0';
    }
    else {
      _DAT_181b4f110 = _DAT_181b4f110 + -1;
    }
    _DAT_181b50a00 = GetTickCount();
  }
  lVar20 = _DAT_181b2f2c0;
  uStackX_18 = _DAT_181b4f0c8;
  lVar25 = _DAT_181b4f0c8;
  if ((_DAT_181b4f0c8 == 0) && (lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x50), lVar25 == 0)) {
    lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x40);
    if (*(int *)(lVar25 + 0x58) < 1) {
      _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
    }
    lVar25 = **(longlong **)(lVar25 + 0x60);
  }
  uStackX_18 = lVar25;
  func_0x0001800149b0();
  func_0x000180022d70(lVar20 + 0x4888,&uStackX_18);
  func_0x0001800255e0(*(undefined8 *)(*(longlong *)(lVar20 + 0x3f10) + 0x298),
                      *(undefined8 *)(*(longlong *)(lVar25 + 0x40) + 8));
  uVar11 = _DAT_181a03460;
  apuStack_1e0[0] = (undefined8 *)&UNK_1819dcf64;
  apuStack_1e0[1] = (undefined8 *)&UNK_1819dcf58;
  apuStack_1e0[2] = (undefined8 *)&UNK_1819dcf7c;
  fVar32 = fVar38 + _DAT_181b2b280;
  uVar12 = 0;
  ppuVar45 = (undefined8 **)&UNK_1819dcf70;
  uVar35 = CONCAT44(uVar7,_DAT_181a0348c);
  func_0x000180030a70(*(undefined8 *)(_DAT_181b2f2c0 + 0x3c30),&uStackX_18,
                      *(undefined4 *)(_DAT_181b2f2c0 + 0x3c38),_DAT_181a03460,uVar35,&UNK_1819dcf70,
                      0);
  fVar41 = _DAT_181a031bc;
  uVar7 = (undefined4)((ulonglong)uVar35 >> 0x20);
  fStack_120 = ((fVar32 - fVar33) * _DAT_181a031bc + fVar33) -
               (float)(int)((float)uStackX_18 + _DAT_181a03228) * _DAT_181a031bc;
  fStack_11c = ((fVar39 - fVar42) * _DAT_181a031bc + fVar42) - uStackX_18._4_4_ * _DAT_181a031bc;
  if (DAT_181b2bc70 == '\0') {
    uVar19 = CONCAT44(uVar7,0x96);
    uVar35 = func_0x000180024180(&uStack_188,0,0,0,uVar19);
    uVar7 = (undefined4)((ulonglong)uVar19 >> 0x20);
    uVar9 = func_0x000180004f90(uVar35);
    uVar31 = (ulonglong)uVar9;
    uVar35 = func_0x0001800152b0();
    uStackX_18 = 0x3f8000003f800000;
    uVar19 = func_0x00018009b6a0(&uStackX_20,&fStack_120,&uStackX_18);
    func_0x000180028900(uVar35,uVar19,uVar31 & 0xffffffff,&UNK_1819dcf3c);
    lVar25 = _DAT_181b2f2c0;
    *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
    func_0x000180025190(*(undefined8 *)(*(longlong *)(lVar25 + 0x3f10) + 0x298),&DAT_1800a2a80,0);
    lVar25 = _DAT_181b2f2c0;
    *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
    uVar35 = *(undefined8 *)(*(longlong *)(lVar25 + 0x3f10) + 0x298);
    uVar17 = CONCAT44(uVar7,0xff);
    uVar19 = func_0x000180024180(&uStack_188,0xff,0xff,0xff,uVar17);
    uVar5 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar7 = func_0x000180004f90(uVar19);
    func_0x000180028900(uVar35,&fStack_120,uVar7,&UNK_1819dcf3c);
    uVar35 = func_0x0001800152b0();
    func_0x000180025190(uVar35,&DAT_1800a2cc0,0);
    uVar7 = _DAT_181a0348c;
    uVar19 = CONCAT44(uVar5,_DAT_181a0348c);
    func_0x00018000dc20(&uStackX_18,&UNK_1819dcf3c,0,0,uVar19);
    uStackX_20 = CONCAT44(uStackX_20._4_4_,fStack_11c + 0.0);
    fVar33 = fStack_120 + (float)uStackX_18;
    uStackX_18._0_4_ = fVar38 + _DAT_181b2b280;
    uStackX_18._4_4_ = fStack_11c + _DAT_181a0336c;
    fStack_19c = fStack_11c - _DAT_181a032ec;
    fStack_1a0 = fVar33;
    func_0x00018000c9e0(&fStack_1a0,&uStackX_18,1);
    lVar25 = _DAT_181b2f2c0;
    dVar1 = *(double *)(_DAT_181b2f2c0 + 0x3e60);
    uVar35 = func_0x0001801cb4f5();
    uVar5 = (undefined4)((ulonglong)uVar19 >> 0x20);
    fVar39 = (float)uVar35;
    uVar9 = (int)((float)dVar1 / fVar34) & 0x80000001;
    if ((int)uVar9 < 0) {
      uVar9 = (uVar9 - 1 | 0xfffffffe) + 1;
    }
    puStack_198 = apuStack_1e0[(int)uVar9];
    lVar20 = -1;
    do {
      lVar20 = lVar20 + 1;
    } while (*(char *)((longlong)puStack_198 + lVar20) != '\0');
    uStackX_18 = (ulonglong)(uint)uStackX_18._4_4_ << 0x20;
    uVar31 = uVar28;
    if (0 < (longlong)(int)lVar20) {
      do {
        uVar9 = _DAT_181a03a00;
        uStack_1e8._0_1_ = *(undefined *)((longlong)puStack_198 + uVar31);
        uStack_1e8._1_1_ = 0;
        uVar12 = 0;
        ppuVar45 = (undefined8 **)&uStack_1e8;
        uVar19 = CONCAT44((int)((ulonglong)uVar19 >> 0x20),uVar7);
        func_0x000180030a70(*(undefined8 *)(lVar25 + 0x3c30),afStack_100,
                            *(undefined4 *)(lVar25 + 0x3c38),uVar11,uVar19,ppuVar45,0);
        fVar42 = (float)(int)(afStack_100[0] + _DAT_181a03228);
        fVar38 = (float)(int)uVar28 * _DAT_181a0313c;
        fVar34 = fVar38 + _DAT_181a03280;
        afStack_100[0] = fVar42;
        if (fVar34 <= fVar39) {
          fVar38 = fVar40;
          if (fVar39 <= fVar34 + fVar41) {
            fVar38 = (fVar39 - fVar34) + (fVar39 - fVar34);
          }
          fVar34 = fVar40 - fVar38;
          fVar38 = (float)((uint)(fVar38 * fVar38 * (fVar38 * _DAT_181a03290 - _DAT_181a03254)) ^
                          uVar9);
        }
        else {
          if (fVar38 <= fVar39) {
            if (fVar39 <= fVar38 + fVar41) {
              fVar32 = (fVar39 - fVar38) + (fVar39 - fVar38);
              uVar11 = (int)((ulonglong)uVar35 >> 0x20);
              uVar5 = (int)extraout_XMM0_Qb;
              uVar6 = (int)((ulonglong)extraout_XMM0_Qb >> 0x20);
            }
            else {
              fVar32 = fVar40;
              uVar11 = 0;
              uVar5 = 0;
              uVar6 = 0;
            }
          }
          else {
            fVar32 = 0.0;
            uVar11 = 0;
            uVar5 = 0;
            uVar6 = 0;
          }
          auVar36._4_4_ = uVar11;
          auVar36._0_4_ = fVar32;
          auVar36._8_4_ = uVar5;
          auVar36._12_4_ = uVar6;
          auVar37._4_12_ = auVar36._4_12_;
          auVar37._0_4_ = ((fVar32 - _DAT_181a03150) * _DAT_181a032d0) / _DAT_181a0318c;
          fVar38 = (float)func_0x0001801cb519(auVar37._0_8_);
          fVar34 = (float)func_0x0001801cb50d();
          fVar38 = fVar38 * fVar34 + fVar40;
          if (fVar40 <= fVar32) {
            fVar38 = fVar40;
          }
          if (fVar32 <= 0.0) {
            fVar38 = 0.0;
          }
          fVar32 = fVar32 * _DAT_181a03248;
          if (0.0 <= fVar32) {
            fVar34 = fVar40;
            if (fVar32 <= fVar40) {
              fVar34 = fVar32;
            }
          }
          else {
            fVar34 = 0.0;
          }
          fVar38 = fVar40 - fVar38;
          uVar11 = _DAT_181a03460;
        }
        iVar8 = (int)uVar28;
        if (_DAT_181a03124 < fVar34) {
          fStack_1a0 = fVar33 + 0.0;
          fStack_19c = fVar38 * _DAT_181a03330 + (float)uStackX_20;
          uStack_118 = 0;
          iStack_110 = 0;
          fStack_10c = fVar34 * _DAT_181a031cc;
          uVar9 = func_0x000180004f90(&uStack_118);
          apuStack_168[0] = (undefined8 *)0x3f8000003f800000;
          apuStack_168[1] =
               (undefined8 *)
               CONCAT44((float)(int)(fVar34 * _DAT_181a033ec) * _DAT_181a03118,0x3f800000);
          uVar10 = func_0x000180004f90(apuStack_168);
          lVar26 = _DAT_181b2f2c0;
          uVar5 = (undefined4)((ulonglong)uVar19 >> 0x20);
          *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
          lVar26 = *(longlong *)(*(longlong *)(lVar26 + 0x3f10) + 0x298);
          uStack_128 = CONCAT44(fStack_19c + fVar40,fStack_1a0 + fVar40);
          if ((uVar9 & 0xff000000) != 0) {
            lVar25 = -1;
            do {
              lVar21 = lVar25;
              lVar25 = lVar21 + 1;
            } while (*(char *)((longlong)&uStack_1e8 + lVar21 + 1) != '\0');
            puVar46 = (undefined *)((longlong)&uStack_1e8 + lVar21 + 1);
            if (&uStack_1e8 != (undefined8 *)puVar46) {
              lVar25 = *(longlong *)(*(longlong *)(lVar26 + 0x38) + 8);
              uVar12 = *(undefined4 *)(*(longlong *)(lVar26 + 0x38) + 0x10);
              if (*(longlong *)(*(longlong *)(lVar25 + 0x40) + 8) != *(longlong *)(lVar26 + 0x98)) {
                _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
              }
              apuStack_1e0[0] = *(undefined8 **)(lVar26 + 0x88);
              apuStack_1e0[1] = *(undefined8 **)(lVar26 + 0x90);
              puVar27 = (undefined *)&uStack_1e8;
              ppuVar45 = apuStack_1e0;
              uVar19 = CONCAT44(uVar5,uVar9);
              func_0x000180030c90(lVar25,lVar26,uVar12,&uStack_128,uVar19,ppuVar45,puVar27,puVar46,0
                                  ,0);
              uVar12 = (undefined4)((ulonglong)puVar27 >> 0x20);
              puVar27 = puVar46;
            }
          }
          lVar26 = _DAT_181b2f2c0;
          *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
          func_0x000180025190(*(undefined8 *)(*(longlong *)(lVar26 + 0x3f10) + 0x298),&DAT_1800a2a80
                              ,0);
          lVar26 = _DAT_181b2f2c0;
          uVar5 = (undefined4)((ulonglong)uVar19 >> 0x20);
          *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
          lVar26 = *(longlong *)(*(longlong *)(lVar26 + 0x3f10) + 0x298);
          if ((uVar10 & 0xff000000) != 0) {
            lVar25 = -1;
            do {
              lVar21 = lVar25;
              lVar25 = lVar21 + 1;
            } while (*(char *)((longlong)&uStack_1e8 + lVar21 + 1) != '\0');
            puVar46 = (undefined *)((longlong)&uStack_1e8 + lVar21 + 1);
            if (&uStack_1e8 != (undefined8 *)puVar46) {
              lVar25 = *(longlong *)(*(longlong *)(lVar26 + 0x38) + 8);
              uVar12 = *(undefined4 *)(*(longlong *)(lVar26 + 0x38) + 0x10);
              if (*(longlong *)(*(longlong *)(lVar25 + 0x40) + 8) != *(longlong *)(lVar26 + 0x98)) {
                _wassert(&UNK_1819d1c30,&UNK_1819d1a00);
              }
              uStack_188._0_4_ = *(undefined4 *)(lVar26 + 0x88);
              uStack_188._4_4_ = *(undefined4 *)(lVar26 + 0x8c);
              iStack_180 = *(int *)(lVar26 + 0x90);
              fStack_17c = *(float *)(lVar26 + 0x94);
              puVar27 = (undefined *)&uStack_1e8;
              ppuVar45 = (undefined8 **)&uStack_188;
              uVar19 = CONCAT44(uVar5,uVar10);
              func_0x000180030c90(lVar25,lVar26,uVar12,&fStack_1a0,uVar19,ppuVar45,puVar27,puVar46,0
                                  ,0);
              uVar12 = (undefined4)((ulonglong)puVar27 >> 0x20);
              puVar27 = puVar46;
            }
          }
          lVar26 = _DAT_181b2f2c0;
          *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
          func_0x000180025190(*(undefined8 *)(*(longlong *)(lVar26 + 0x3f10) + 0x298),&DAT_1800a2cc0
                              ,0);
          iVar8 = (int)(float)uStackX_18;
        }
        uVar5 = (undefined4)((ulonglong)uVar19 >> 0x20);
        fVar33 = fVar33 + fVar42;
        uVar28 = (ulonglong)(iVar8 + 1U);
        uStackX_18 = CONCAT44(uStackX_18._4_4_,iVar8 + 1U);
        uVar31 = uVar31 + 1;
        lVar25 = _DAT_181b2f2c0;
      } while ((longlong)uVar31 < (longlong)(int)lVar20);
      uVar30 = (ulonglong)__tls_index;
      lVar26 = lStack_f8;
      fVar38 = (float)uStackX_8;
    }
    func_0x00018000ca90();
  }
  else {
    uVar35 = func_0x0001800152b0();
    uVar17 = CONCAT44(uVar7,0xff);
    uVar19 = func_0x000180024180(&uStack_188,0xff,0xff,0xff,uVar17);
    uVar5 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar7 = func_0x000180004f90(uVar19);
    func_0x000180028900(uVar35,&fStack_120,uVar7,&UNK_1819dcf70);
  }
  func_0x000180014ae0();
  lVar25 = _DAT_181b2f2c0;
  *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
  apuStack_168[0] = (undefined8 *)CONCAT44(_DAT_181b4f19c,_DAT_181b4f198);
  apuStack_168[1] =
       (undefined8 *)CONCAT44(_DAT_181b4f1a4 * *(float *)(lVar25 + 0x37d0),_DAT_181b4f1a0);
  uStackX_8 = (undefined *)CONCAT44((float)uStackX_10 + _DAT_181b2b284,fVar38 + _DAT_181b2b280);
  uVar7 = func_0x000180004f90(apuStack_168);
  puVar18 = (undefined8 *)((ulonglong)ppuVar45 & 0xffffffff00000000);
  puVar16 = (undefined8 *)CONCAT44(uVar5,_DAT_181a032ec);
  func_0x000180027c60(*(undefined8 *)(*(longlong *)(lVar25 + 0x3f10) + 0x298),&uStack_108,&uStackX_8
                      ,uVar7,puVar16,puVar18,CONCAT44(uVar12,fVar40));
  lVar25 = _DAT_181b2f2c0;
  uVar7 = (undefined4)((ulonglong)puVar18 >> 0x20);
  if (DAT_181b2f8c8 == '\0') {
    fVar38 = _DAT_181b32b44 + _DAT_181a0338c;
    *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
    fVar40 = _DAT_181a0331c;
    lVar25 = *(longlong *)(lVar25 + 0x3f10);
    *(float *)(lVar25 + 0x100) =
         (*(float *)(lVar25 + 0x20) - *(float *)(lVar25 + 0x84)) + _DAT_181a0331c;
    *(float *)(lVar25 + 0x104) = (*(float *)(lVar25 + 0x24) - *(float *)(lVar25 + 0x88)) + fVar38;
    *(undefined *)(lVar25 + 0x141) = 1;
    func_0x000180019310();
    lVar20 = _DAT_181b2f2c0;
    lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
    if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
       (pfVar23 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
      pfVar23 = (float *)(lVar25 + 0x220);
    }
    fVar38 = *pfVar23 - *(float *)(lVar25 + 0x100);
    fVar40 = (((pfVar23[1] - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810)) - fVar40) +
             _DAT_181b32b44;
    uStackX_10 = (undefined *)CONCAT44(fVar40,fVar38);
    *(undefined *)(lVar25 + 0xb8) = 1;
    uVar35 = *(undefined8 *)(lVar20 + 0x3f10);
    uStackX_8 = (undefined *)0x4150000041500000;
    func_0x000180006ac0(2,&uStackX_8);
    uStackX_8 = (undefined *)0x4150000041500000;
    func_0x000180006ac0(0xe,&uStackX_8);
    uVar11 = func_0x000180009d10(uVar35,&UNK_1819dcfa0);
    func_0x000180057580(&UNK_1819dcfa0,uVar11,&uStackX_10);
    lVar26 = _DAT_181b2f2c0;
    *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
    lVar26 = *(longlong *)(lVar26 + 0x3f10);
    fVar40 = fVar40 - _DAT_181a033f0;
    *(float *)(lVar26 + 0x100) =
         (*(float *)(lVar26 + 0x20) - *(float *)(lVar26 + 0x84)) +
         (fVar38 - _DAT_181a03410) * fVar41;
    *(float *)(lVar26 + 0x104) =
         (*(float *)(lVar26 + 0x24) - *(float *)(lVar26 + 0x88)) + fVar40 * fVar41;
    *(undefined *)(lVar26 + 0x141) = 1;
    func_0x000180019310();
    lVar25 = _DAT_181b2f2c0;
    uStackX_8 = (undefined *)_DAT_181b4f028;
    lVar26 = _DAT_181b4f028;
    if ((_DAT_181b4f028 == 0) && (lVar26 = *(longlong *)(_DAT_181b2f2c0 + 0x50), lVar26 == 0)) {
      lVar26 = *(longlong *)(_DAT_181b2f2c0 + 0x40);
      if (*(int *)(lVar26 + 0x58) < 1) {
        _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
      }
      lVar26 = **(longlong **)(lVar26 + 0x60);
    }
    uStackX_8 = (undefined *)lVar26;
    func_0x0001800149b0();
    func_0x000180022d70(lVar25 + 0x4888,&uStackX_8);
    func_0x0001800255e0(*(undefined8 *)(*(longlong *)(lVar25 + 0x3f10) + 0x298),
                        *(undefined8 *)(*(longlong *)(lVar26 + 0x40) + 8));
    func_0x000180037ef0(&UNK_1819dcf88);
    func_0x000180014ae0();
    lVar26 = _DAT_181b2f2c0;
    uStack_188._0_4_ = 0;
    uStack_188._4_4_ = *(undefined4 *)(_DAT_181b2f2c0 + 0x38bc);
    iStack_180 = *(int *)(_DAT_181b2f2c0 + 0x38c0);
    fStack_17c = *(float *)(_DAT_181b2f2c0 + 0x38c4);
    uStack_178 = *(undefined4 *)(_DAT_181b2f2c0 + 0x38c8);
    func_0x000180022be0(_DAT_181b2f2c0 + 0x4868,&uStack_188);
    *(undefined4 *)(lVar26 + 0x38bc) = 0x3f34b4b5;
    *(undefined4 *)(lVar26 + 0x38c0) = 0x3f34b4b5;
    *(undefined4 *)(lVar26 + 0x38c4) = 0x3f3ebebf;
    *(undefined4 *)(lVar26 + 0x38c8) = 0x3f800000;
    func_0x0001800380d0(&UNK_1819dcfe8);
    func_0x0001800069f0(1);
    lVar26 = _DAT_181b2f2c0;
    if (DAT_181b2f2dc != '\0') {
      *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
      if (*(char *)(*(longlong *)(lVar26 + 0x3f10) + 0xbb) == '\0') {
        uStackX_8 = (undefined *)0x0;
        func_0x000180018c50(&uStackX_8);
      }
      lVar26 = _DAT_181b2f2c0;
      uStack_188._0_4_ = 0;
      uStack_188._4_4_ = *(undefined4 *)(_DAT_181b2f2c0 + 0x38bc);
      iStack_180 = *(int *)(_DAT_181b2f2c0 + 0x38c0);
      fStack_17c = *(float *)(_DAT_181b2f2c0 + 0x38c4);
      uStack_178 = *(undefined4 *)(_DAT_181b2f2c0 + 0x38c8);
      func_0x000180022be0(_DAT_181b2f2c0 + 0x4868,&uStack_188);
      *(undefined4 *)(lVar26 + 0x38bc) = 0x3f800000;
      *(undefined4 *)(lVar26 + 0x38c0) = 0x3e99999a;
      *(undefined4 *)(lVar26 + 0x38c4) = 0x3e99999a;
      *(undefined4 *)(lVar26 + 0x38c8) = 0x3f800000;
      func_0x000180037ef0(&UNK_1819dcfb0);
      func_0x0001800069f0(1);
    }
    if ((*(int *)(*(longlong *)(*(longlong *)(unaff_GS_OFFSET + 0x58) + uVar30 * 8) + 4) <
         _DAT_181b509ac) && (func_0x000180127a18(&DAT_181b509ac), _DAT_181b509ac == -1)) {
      func_0x000180078760(&DAT_181b50d78);
      func_0x000180127e28(&DAT_1801d1230);
      func_0x0001801279ac(&DAT_181b509ac);
    }
    lVar26 = _DAT_181b2f2c0;
    if (_DAT_181b50d88 != 0) {
      *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
      if (*(char *)(*(longlong *)(lVar26 + 0x3f10) + 0xbb) == '\0') {
        uStackX_8 = (undefined *)0x0;
        func_0x000180018c50(&uStackX_8);
      }
      lVar26 = _DAT_181b2f2c0;
      uStack_188._0_4_ = 0;
      uStack_188._4_4_ = *(undefined4 *)(_DAT_181b2f2c0 + 0x38bc);
      iStack_180 = *(int *)(_DAT_181b2f2c0 + 0x38c0);
      fStack_17c = *(float *)(_DAT_181b2f2c0 + 0x38c4);
      uStack_178 = *(undefined4 *)(_DAT_181b2f2c0 + 0x38c8);
      func_0x000180022be0(_DAT_181b2f2c0 + 0x4868,&uStack_188);
      *(undefined4 *)(lVar26 + 0x38bc) = 0x3f800000;
      *(undefined4 *)(lVar26 + 0x38c0) = 0x3eb33333;
      *(undefined4 *)(lVar26 + 0x38c4) = 0x3eb33333;
      *(undefined4 *)(lVar26 + 0x38c8) = 0x3f800000;
      puVar27 = &DAT_181b50d78;
      if (0xf < _DAT_181b50d90) {
        puVar27 = _DAT_181b50d78;
      }
      func_0x0001800380d0(&UNK_18021328c,puVar27);
      func_0x0001800069f0(1);
    }
    lVar26 = _DAT_181b2f2c0;
    *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
    if (*(char *)(*(longlong *)(lVar26 + 0x3f10) + 0xbb) == '\0') {
      uStackX_8 = (undefined *)0x0;
      func_0x000180018c50(&uStackX_8);
    }
    lVar26 = _DAT_181b2f2c0;
    *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
    if (*(char *)(*(longlong *)(lVar26 + 0x3f10) + 0xbb) == '\0') {
      uStackX_8 = (undefined *)0x0;
      func_0x000180018c50(&uStackX_8);
    }
    lVar25 = _DAT_181b2f2c0;
    lVar26 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
    *(undefined *)(lVar26 + 0xb8) = 1;
    lVar25 = *(longlong *)(lVar25 + 0x3f10);
    *(float *)(lVar25 + 0x104) =
         (*(float *)(lVar25 + 0x24) - *(float *)(lVar25 + 0x88)) +
         (*(float *)(lVar26 + 0x104) - *(float *)(lVar26 + 0x24)) + *(float *)(lVar26 + 0x88) +
         _DAT_181a032a8;
    *(undefined *)(lVar25 + 0x141) = 1;
    uStackX_8 = (undefined *)0x4260000043dc0000;
    func_0x00018003f4e0(&UNK_1819dd020,&UNK_1819dd030,0x181b2bcf8,0x80,&uStackX_8,
                        CONCAT44(uVar7,0x100),&DAT_1800ae450,0);
    lVar25 = _DAT_181b2f2c0;
    lVar26 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
    *(undefined *)(lVar26 + 0xb8) = 1;
    lVar25 = *(longlong *)(lVar25 + 0x3f10);
    *(float *)(lVar25 + 0x104) =
         (*(float *)(lVar25 + 0x24) - *(float *)(lVar25 + 0x88)) +
         (*(float *)(lVar26 + 0x104) - *(float *)(lVar26 + 0x24)) + *(float *)(lVar26 + 0x88) +
         _DAT_181a03308;
    *(undefined *)(lVar25 + 0x141) = 1;
    if (DAT_181b4f078 == '\0') {
      uStackX_8 = (undefined *)0x4240000043dc0000;
      cVar4 = func_0x000180058040(&UNK_1819dd058,&uStackX_8);
      if (cVar4 != '\0') {
        DAT_181b4f078 = '\x01';
        func_0x0001800785c0(&DAT_181b50d78);
        uStack_188._0_4_ = _DAT_181a2aff0;
        uStack_188._4_4_ = _DAT_181a2aff4;
        iStack_180 = _DAT_181a2aff8;
        fStack_17c = _DAT_181a2affc;
        recovered_18009bbb0();
        recovered_180066c80(apuStack_168,0x181b2bcf8);
        recovered_180080190(apuStack_1e0,apuStack_168);
        uVar35 = func_0x0001800b5b30(&uStack_188,apuStack_1e0);
        func_0x000180067c80(uVar35);
        if (iStack_180 != 0) {
          terminate();
        }
        recovered_180066e40(apuStack_1e0);
        recovered_180066e40(apuStack_168);
      }
    }
    else {
      func_0x000180014d80();
      uStackX_8 = (undefined *)0x4240000043dc0000;
      func_0x000180058040(&UNK_1819dd078,&uStackX_8);
      func_0x000180014e10();
    }
    func_0x000180019460();
  }
  else {
    func_0x0001800a0be0();
    lVar25 = _DAT_181b2f2c0;
    fVar39 = _DAT_181a033a0;
    fVar34 = _DAT_181a0338c;
    fVar38 = _DAT_181a0331c;
    uVar7 = (undefined4)((ulonglong)puVar27 >> 0x20);
    if (_DAT_181b50d50 == 0) {
      fVar33 = _DAT_181b32b44 + _DAT_181a0338c;
      *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
      lVar25 = *(longlong *)(lVar25 + 0x3f10);
      *(float *)(lVar25 + 0x100) = (*(float *)(lVar25 + 0x20) - *(float *)(lVar25 + 0x84)) + fVar38;
      *(float *)(lVar25 + 0x104) = (*(float *)(lVar25 + 0x24) - *(float *)(lVar25 + 0x88)) + fVar33;
      *(undefined *)(lVar25 + 0x141) = 1;
      func_0x000180019310();
      lVar20 = _DAT_181b2f2c0;
      uVar7 = (undefined4)((ulonglong)puVar16 >> 0x20);
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar23 = (float *)(lVar25 + 0x254), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar23 = (float *)(lVar25 + 0x224);
      }
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar24 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar24 = (float *)(lVar25 + 0x220);
      }
      uStackX_10 = (undefined *)
                   CONCAT44((((*pfVar23 - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810))
                            - fVar39) + _DAT_181b32b44,
                            (*pfVar24 - *(float *)(lVar25 + 0x100)) * fVar41);
      *(undefined *)(lVar25 + 0xb8) = 1;
      uVar35 = *(undefined8 *)(lVar20 + 0x3f10);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(2,&uStackX_8);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(0xe,&uStackX_8);
      uVar11 = func_0x000180009d10(uVar35,&UNK_1819dcf0c);
      func_0x000180057580(&UNK_1819dcf0c,uVar11,&uStackX_10);
      cVar4 = func_0x000180059d50(&UNK_1819dd098,&UNK_1819dd060,&DAT_181b2f8c9);
      if (cVar4 != '\0') {
        DAT_181b2f8c9 = DAT_181b2f8c9 == '\0';
        recovered_1800acfd0();
      }
      if ((DAT_181b2f8c9 != '\0') &&
         (cVar4 = func_0x00018005d100(&UNK_1819dd0c0,&UNK_1819dd088,&DAT_181b30424,0x181ade2e8,
                                      CONCAT44(uVar7,1)), cVar4 != '\0')) {
        DAT_181b2f8c9 = '\0';
        recovered_1800acfd0();
      }
      func_0x000180059d50(&UNK_1819dd0e8,&UNK_1819dd0a0,&DAT_181b2b5b5);
      func_0x000180059d50(&UNK_1819dd108,&UNK_1819dd0d0,&DAT_181b2b400);
      func_0x000180059d50(&UNK_1819dd130,&UNK_1819dd0f8,&DAT_181b2b5c0);
      func_0x000180059d50(&UNK_1819dd158,&UNK_1819dd118,&DAT_181b2b407);
      func_0x000180059d50(&UNK_1819dd178,&UNK_1819dd140,&DAT_181b2b406);
      func_0x0001800579c0();
      func_0x000180019010();
      lVar20 = _DAT_181b2f2c0;
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar23 = (float *)(lVar25 + 0x254), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar23 = (float *)(lVar25 + 0x224);
      }
      uStackX_10._4_4_ =
           (((*pfVar23 - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810)) - fVar39) +
           _DAT_181b32b44;
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar23 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar23 = (float *)(lVar25 + 0x220);
      }
      uStackX_10._0_4_ = *pfVar23 - *(float *)(lVar25 + 0x100);
      *(undefined *)(lVar25 + 0xb8) = 1;
      uVar35 = *(undefined8 *)(lVar20 + 0x3f10);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(2,&uStackX_8);
      uStackX_8._0_4_ = 13.0;
      uStackX_8._4_4_ = 0x41500000;
      func_0x000180006ac0(0xe,&uStackX_8);
      uVar7 = func_0x000180009d10(uVar35,&UNK_1819dd168);
      func_0x000180057580(&UNK_1819dd168,uVar7,&uStackX_10);
      uStackX_8._0_4_ = 1200.0;
      uStackX_10._0_4_ = 0.0;
      uVar28 = (ulonglong)puVar27 & 0xffffffff00000000;
      func_0x0001800610a0(&UNK_1819dd188,&UNK_1819dd198,8,&DAT_181b2b410,&uStackX_10,&uStackX_8,
                          &UNK_180213290,uVar28);
      uStackX_8 = (undefined *)CONCAT44(uStackX_8._4_4_,200);
      uStackX_10 = (undefined *)((ulonglong)(uint)uStackX_10._4_4_ << 0x20);
      uVar28 = uVar28 & 0xffffffff00000000;
      puVar18 = &uStackX_8;
      puVar16 = &uStackX_10;
      func_0x0001800610a0(&UNK_1819dd1e0,&UNK_1819dd1b0,4,&DAT_181b2b40c,puVar16,puVar18,
                          &UNK_1819dd1c4,uVar28);
      uVar7 = (undefined4)(uVar28 >> 0x20);
      cVar4 = func_0x000180059d50(&UNK_1819dd208,&UNK_1819dd1c8,0x181b31b5b);
      if (cVar4 != '\0') {
        apuStack_168[0] = (undefined8 *)&UNK_1819de310;
        ppuStack_130 = apuStack_168;
        apuStack_1e0[0] = (undefined8 *)&UNK_1819de210;
        ppuStack_1a8 = apuStack_1e0;
        func_0x0001800ac810(0x172b,&UNK_1819dd208,apuStack_1e0,apuStack_168);
        func_0x0001800553f0(apuStack_1e0);
        func_0x0001800553f0(apuStack_168);
      }
      func_0x000180059d50(&UNK_1819dd230,&UNK_1819dd1f0,&DAT_181b2b5b6);
      if (DAT_181b2b5b6 != '\0') {
        puVar16 = (undefined8 *)CONCAT44((int)((ulonglong)puVar16 >> 0x20),2);
        func_0x00018005d100(&UNK_1819dd260,&UNK_1819dd218,&DAT_181b2b5b8,0x181ade2a8,puVar16);
      }
      cVar4 = func_0x000180059d50(&UNK_1819dcca8,&UNK_1819dd240,&DAT_181b30438);
      if (cVar4 != '\0') {
        apuStack_168[0] = (undefined8 *)&UNK_1819ddf50;
        ppuStack_130 = apuStack_168;
        apuStack_1e0[0] = (undefined8 *)&UNK_181a03018;
        ppuStack_1a8 = apuStack_1e0;
        func_0x0001800ac810(8,&UNK_1819dcca8,apuStack_1e0,apuStack_168);
        func_0x0001800553f0(apuStack_1e0);
        func_0x0001800553f0(apuStack_168);
      }
      func_0x0001800579c0();
      func_0x000180019460();
    }
    lVar25 = _DAT_181b2f2c0;
    uVar11 = (undefined4)((ulonglong)puVar18 >> 0x20);
    if (_DAT_181b50d50 == 1) {
      fVar33 = _DAT_181b32b44 + fVar34;
      *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
      lVar25 = *(longlong *)(lVar25 + 0x3f10);
      *(float *)(lVar25 + 0x100) = (*(float *)(lVar25 + 0x20) - *(float *)(lVar25 + 0x84)) + fVar38;
      *(float *)(lVar25 + 0x104) = (*(float *)(lVar25 + 0x24) - *(float *)(lVar25 + 0x88)) + fVar33;
      *(undefined *)(lVar25 + 0x141) = 1;
      func_0x000180019310();
      lVar20 = _DAT_181b2f2c0;
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar23 = (float *)(lVar25 + 0x254), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar23 = (float *)(lVar25 + 0x224);
      }
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar24 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar24 = (float *)(lVar25 + 0x220);
      }
      uStackX_10 = (undefined *)
                   CONCAT44((((*pfVar23 - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810))
                            - fVar39) + _DAT_181b32b44,
                            (*pfVar24 - *(float *)(lVar25 + 0x100)) * fVar41);
      *(undefined *)(lVar25 + 0xb8) = 1;
      uVar35 = *(undefined8 *)(lVar20 + 0x3f10);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(2,&uStackX_8);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(0xe,&uStackX_8);
      uVar12 = func_0x000180009d10(uVar35,&UNK_1819dd290);
      func_0x000180057580(&UNK_1819dd290,uVar12,&uStackX_10);
      func_0x000180059d50(&UNK_1819dd298,&UNK_1819dd278,&DAT_181b2b46c);
      apuStack_1e0[0] = (undefined8 *)&UNK_1819dd294;
      apuStack_1e0[1] = (undefined8 *)&UNK_1819dd2ac;
      apuStack_1e0[2] = (undefined8 *)&UNK_1819dd2a4;
      uVar19 = CONCAT44(uVar7,0x2000128);
      uVar35 = CONCAT44(uVar11,3);
      func_0x0001800640d0(&UNK_1819dd2b8,&UNK_1819dd2c8,&DAT_181b2b46d,&DAT_181b2b470,apuStack_1e0,
                          uVar35,&DAT_181b2b478,uVar19);
      uVar7 = (undefined4)((ulonglong)uVar35 >> 0x20);
      uVar11 = (undefined4)((ulonglong)uVar19 >> 0x20);
      if (2 < _DAT_181b2b470) {
        _DAT_181b2b470 = 0;
      }
      if (DAT_181b2b46d != '\0') {
        uStackX_8 = (undefined *)CONCAT71(uStackX_8._1_7_,_DAT_181b2b474 != 0);
        cVar4 = func_0x000180059d50(&UNK_1819dd2e8,&UNK_1819dd2f8,&uStackX_8);
        if (cVar4 != '\0') {
          _DAT_181b2b474 = (uint)((char)uStackX_8 != '\0');
        }
      }
      apuStack_168[0] = (undefined8 *)&UNK_1819dd320;
      apuStack_168[1] = (undefined8 *)&UNK_1819dd310;
      uVar28 = CONCAT44(uVar11,0x2000128);
      ppuVar45 = apuStack_168;
      func_0x0001800640d0(&UNK_1819dd328,&UNK_1819dd330,&DAT_181b2b498,&DAT_181b2b49c,ppuVar45,
                          CONCAT44(uVar7,2),&DAT_181b2b4a0,uVar28);
      if (1 < _DAT_181b2b49c) {
        _DAT_181b2b49c = 0;
      }
      uVar35 = CONCAT44((int)((ulonglong)ppuVar45 >> 0x20),0x2000128);
      func_0x000180062830(&UNK_1819dd348,&UNK_1819dd358,&DAT_181b2b538,&DAT_181b2b53c,uVar35);
      uVar35 = CONCAT44((int)((ulonglong)uVar35 >> 0x20),0x2000128);
      func_0x000180062830(&UNK_1819dd370,&UNK_1819dd380,&DAT_181b2b4c4,&DAT_181b2b4c8,uVar35);
      uVar35 = CONCAT44((int)((ulonglong)uVar35 >> 0x20),0x2000128);
      func_0x000180062830(&UNK_1819dd398,&UNK_1819dd3a8,&DAT_181b2b4d8,&DAT_181b2b4dc,uVar35);
      uVar35 = CONCAT44((int)((ulonglong)uVar35 >> 0x20),0x2000128);
      func_0x000180062830(&UNK_1819dd3c0,&UNK_1819dd3d0,&DAT_181b2b4ec,&DAT_181b2b4f0,uVar35);
      uVar35 = CONCAT44((int)((ulonglong)uVar35 >> 0x20),0x2000128);
      func_0x000180062830(&UNK_1819dd3e8,&UNK_1819dd3f8,&DAT_181b2b504,&DAT_181b2b508,uVar35);
      uVar7 = (undefined4)((ulonglong)uVar35 >> 0x20);
      func_0x000180059d50(&UNK_1819dd410,&UNK_1819dd420,&DAT_181b2b51c);
      func_0x000180059d50(&UNK_1819da980,&UNK_1819dd450,&DAT_181b2b54d);
      func_0x000180059d50(&UNK_1819da9a8,&UNK_1819dd438,&DAT_181b2b54c);
      func_0x000180059d50(&UNK_1819dd460,&UNK_1819dd470,&DAT_181b2b46e);
      func_0x000180059d50(&UNK_1819dd490,&UNK_1819dd4a0,&DAT_181b2bedc);
      func_0x000180059d50(&UNK_1819dd4b8,&UNK_1819dd4c8,&DAT_181b2bdd0);
      if (DAT_181b2bdd0 != '\0') {
        func_0x0001800627e0(&UNK_1819dd4e0,&UNK_1819dd4f0,&DAT_181b2bdd4,0x14,CONCAT44(uVar7,500));
        func_0x000180059d50(&UNK_1819dd508,&UNK_1819dd518,&DAT_181b2bdd1);
      }
      uStackX_8 = (undefined *)CONCAT44(uStackX_8._4_4_,200);
      uStackX_10 = (undefined *)((ulonglong)uStackX_10 & 0xffffffff00000000);
      puVar18 = &uStackX_8;
      puVar16 = &uStackX_10;
      func_0x0001800610a0(&UNK_1819dd530,&UNK_1819dd540,4,&DAT_181b2b57c,puVar16,puVar18,
                          &UNK_1819dd1c4,uVar28 & 0xffffffff00000000);
      func_0x000180059d50(&UNK_1819dd558,&UNK_1819dd568,&DAT_181b2b581);
      func_0x000180059d50(&UNK_1819dd580,&UNK_1819dd590,&DAT_181b2b564);
      func_0x000180059d50(&UNK_1819dd5a8,&UNK_1819dd5c0,&DAT_181b2b565);
      uStackX_8 = (undefined *)0x420c000043c80000;
      cVar4 = func_0x000180058040(&UNK_1819dd5e8,&uStackX_8);
      if (cVar4 != '\0') {
        recovered_180067b80(&uStackX_8);
        lVar25 = (longlong)uStackX_8;
        uStackX_8 = (undefined *)((longlong)uStackX_8 - _DAT_181b4f0b8);
        plVar22 = (longlong *)func_0x0001800694c0(&uStackX_10,&uStackX_8);
        if (0xf9 < *plVar22) {
          DAT_181b2bedd = 1;
          uStack_188._0_4_ = _DAT_181a2aff0;
          uStack_188._4_4_ = _DAT_181a2aff4;
          iStack_180 = _DAT_181a2aff8;
          fStack_17c = _DAT_181a2affc;
          _DAT_181b4f0b8 = lVar25;
          recovered_18009bbb0();
        }
      }
      func_0x0001800579c0();
      func_0x000180019010();
      lVar20 = _DAT_181b2f2c0;
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar23 = (float *)(lVar25 + 0x254), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar23 = (float *)(lVar25 + 0x224);
      }
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar24 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar24 = (float *)(lVar25 + 0x220);
      }
      uStackX_10 = (undefined *)
                   CONCAT44((((*pfVar23 - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810))
                            - fVar39) + _DAT_181b32b44,*pfVar24 - *(float *)(lVar25 + 0x100));
      *(undefined *)(lVar25 + 0xb8) = 1;
      uVar35 = *(undefined8 *)(lVar20 + 0x3f10);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(2,&uStackX_8);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(0xe,&uStackX_8);
      uVar7 = func_0x000180009d10(uVar35,&UNK_1819dd5d8);
      func_0x000180057580(&UNK_1819dd5d8,uVar7,&uStackX_10);
      func_0x00018009c940(&DAT_181b2fd70);
      func_0x00018009d460(&DAT_181b2fd70);
      func_0x0001800579c0();
      func_0x000180019460();
    }
    lVar25 = _DAT_181b2f2c0;
    uVar7 = _DAT_181a0330c;
    if (_DAT_181b50d50 == 2) {
      fVar33 = _DAT_181b32b44 + fVar34;
      *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
      lVar25 = *(longlong *)(lVar25 + 0x3f10);
      *(float *)(lVar25 + 0x100) = (*(float *)(lVar25 + 0x20) - *(float *)(lVar25 + 0x84)) + fVar38;
      *(float *)(lVar25 + 0x104) = (*(float *)(lVar25 + 0x24) - *(float *)(lVar25 + 0x88)) + fVar33;
      *(undefined *)(lVar25 + 0x141) = 1;
      func_0x000180019310();
      lVar20 = _DAT_181b2f2c0;
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar23 = (float *)(lVar25 + 0x254), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar23 = (float *)(lVar25 + 0x224);
      }
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar24 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar24 = (float *)(lVar25 + 0x220);
      }
      uStackX_10 = (undefined *)
                   CONCAT44((((*pfVar23 - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810))
                            - fVar39) + _DAT_181b32b44,
                            (*pfVar24 - *(float *)(lVar25 + 0x100)) * fVar41);
      *(undefined *)(lVar25 + 0xb8) = 1;
      uVar35 = *(undefined8 *)(lVar20 + 0x3f10);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(2,&uStackX_8);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(0xe,&uStackX_8);
      uVar11 = func_0x000180009d10(uVar35,&UNK_1819dcf20);
      func_0x000180057580(&UNK_1819dcf20,uVar11,&uStackX_10);
      func_0x000180059d50(&UNK_1819dd5f8,&UNK_1819dd608,&DAT_181b2b5fc);
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) == 0) && (*(longlong *)(_DAT_181b2f2c0 + 0x4be0) == 0)) {
        pfVar23 = (float *)(lVar25 + 0x250);
      }
      else {
        pfVar23 = (float *)(lVar25 + 0x220);
      }
      uStackX_8 = (undefined *)CONCAT44(0x42200000,*pfVar23 - *(float *)(lVar25 + 0x100));
      cVar4 = func_0x000180058040(&UNK_1819dd640,&uStackX_8);
      if (cVar4 != '\0') {
        apuStack_1e0[0] = (undefined8 *)&UNK_1819de418;
        ppuStack_1a8 = apuStack_1e0;
        func_0x0001800ac840(&UNK_1819dcc58,apuStack_1e0);
        func_0x0001800553f0(apuStack_1e0);
      }
      cVar4 = func_0x000180059d50(&UNK_1819dcc58,&UNK_1819dd620,&DAT_181b3044f);
      if (cVar4 != '\0') {
        apuStack_168[0] = (undefined8 *)&UNK_181a02fa0;
        ppuStack_130 = apuStack_168;
        apuStack_1e0[0] = (undefined8 *)&UNK_181a02ef8;
        ppuStack_1a8 = apuStack_1e0;
        func_0x0001800ac810(0x1f,&UNK_1819dcc58,apuStack_1e0,apuStack_168);
        func_0x0001800553f0(apuStack_1e0);
        func_0x0001800553f0(apuStack_168);
      }
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) == 0) && (*(longlong *)(_DAT_181b2f2c0 + 0x4be0) == 0)) {
        pfVar23 = (float *)(lVar25 + 0x250);
      }
      else {
        pfVar23 = (float *)(lVar25 + 0x220);
      }
      uStackX_8 = (undefined *)CONCAT44(0x42200000,*pfVar23 - *(float *)(lVar25 + 0x100));
      cVar4 = func_0x000180058040(&UNK_1819dd670,&uStackX_8);
      if (cVar4 != '\0') {
        apuStack_1e0[0] = (undefined8 *)&UNK_181a030a8;
        ppuStack_1a8 = apuStack_1e0;
        func_0x0001800ac840(&UNK_1819dcc78,apuStack_1e0);
        func_0x0001800553f0(apuStack_1e0);
      }
      cVar4 = func_0x000180059d50(&UNK_1819dcc78,&UNK_1819dd650,&DAT_181b3055d);
      if (cVar4 != '\0') {
        apuStack_168[0] = (undefined8 *)&UNK_1819dde90;
        ppuStack_130 = apuStack_168;
        apuStack_1e0[0] = (undefined8 *)&UNK_1819de060;
        ppuStack_1a8 = apuStack_1e0;
        func_0x0001800ac810(0x12d,&UNK_1819dcc78,apuStack_1e0,apuStack_168);
        func_0x0001800553f0(apuStack_1e0);
        func_0x0001800553f0(apuStack_168);
      }
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) == 0) && (*(longlong *)(_DAT_181b2f2c0 + 0x4be0) == 0)) {
        pfVar23 = (float *)(lVar25 + 0x250);
      }
      else {
        pfVar23 = (float *)(lVar25 + 0x220);
      }
      uStackX_8 = (undefined *)CONCAT44(0x42200000,*pfVar23 - *(float *)(lVar25 + 0x100));
      cVar4 = func_0x000180058040(&UNK_1819dd6a0,&uStackX_8);
      if (cVar4 != '\0') {
        apuStack_1e0[0] = (undefined8 *)&UNK_1819de028;
        ppuStack_1a8 = apuStack_1e0;
        func_0x0001800ac840(&UNK_1819dd688,apuStack_1e0);
        func_0x0001800553f0(apuStack_1e0);
      }
      cVar4 = func_0x000180059d50(&UNK_1819dd688,&UNK_1819dd6c8,&DAT_181b3049f);
      if (cVar4 != '\0') {
        apuStack_168[0] = (undefined8 *)&UNK_1819dde20;
        ppuStack_130 = apuStack_168;
        apuStack_1e0[0] = (undefined8 *)&UNK_1819de3a0;
        ppuStack_1a8 = apuStack_1e0;
        func_0x0001800ac810(0x6f,&UNK_1819dcc88,apuStack_1e0,apuStack_168);
        func_0x0001800553f0(apuStack_1e0);
        func_0x0001800553f0(apuStack_168);
      }
      func_0x0001800579c0();
      func_0x000180019010();
      lVar20 = _DAT_181b2f2c0;
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar23 = (float *)(lVar25 + 0x254), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar23 = (float *)(lVar25 + 0x224);
      }
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar24 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar24 = (float *)(lVar25 + 0x220);
      }
      uStackX_10 = (undefined *)
                   CONCAT44((((*pfVar23 - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810))
                            - fVar39) + _DAT_181b32b44,*pfVar24 - *(float *)(lVar25 + 0x100));
      *(undefined *)(lVar25 + 0xb8) = 1;
      uVar35 = *(undefined8 *)(lVar20 + 0x3f10);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(2,&uStackX_8);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(0xe,&uStackX_8);
      uVar11 = func_0x000180009d10(uVar35,&UNK_1819dd6b8);
      func_0x000180057580(&UNK_1819dd6b8,uVar11,&uStackX_10);
      func_0x000180059d50(&UNK_1819dd6e8,&UNK_1819dd6f8,&DAT_181b2b5e9);
      func_0x000180059d50(&UNK_1819dd710,&UNK_1819dd720,&DAT_181b2b60c);
      cVar4 = func_0x000180059d50(&UNK_1819dd738,&UNK_1819dd748,&DAT_181b2bc60);
      if (cVar4 != '\0') {
        if (DAT_181b2bc60 == '\0') {
          LOCK();
          DAT_181b2f6d9 = 0;
          UNLOCK();
          _DAT_181b3031c = 0;
          puVar16 = (undefined8 *)CONCAT44((int)((ulonglong)puVar16 >> 0x20),0xff);
          puVar13 = (undefined4 *)func_0x000180024180(apuStack_1e0,0xff,0x50,0x50,puVar16);
          uStack_188._0_4_ = *puVar13;
          uStack_188._4_4_ = puVar13[1];
          iStack_180 = puVar13[2];
          fStack_17c = (float)puVar13[3];
        }
        else {
          func_0x0001800776a0();
          uStack_188._0_4_ = _DAT_181a2aff0;
          uStack_188._4_4_ = _DAT_181a2aff4;
          iStack_180 = _DAT_181a2aff8;
          fStack_17c = _DAT_181a2affc;
        }
        recovered_18009bbb0();
      }
      if (DAT_181b2bc60 != '\0') {
        puVar18 = (undefined8 *)&UNK_1819dd7a8;
        puVar16 = (undefined8 *)CONCAT44((int)((ulonglong)puVar16 >> 0x20),uVar7);
        func_0x000180062790(&UNK_1819dd7d0,&UNK_1819dd790,&DAT_181b2bc64,fVar40,puVar16,
                            &UNK_1819dd7a8);
      }
      cVar4 = func_0x000180059d50(&UNK_1819dd7f0,&UNK_1819dd7b0,0x181b327f2);
      if (cVar4 != '\0') {
        apuStack_168[0] = (undefined8 *)&UNK_1819ddec8;
        ppuStack_130 = apuStack_168;
        apuStack_1e0[0] = (undefined8 *)&UNK_181a02f30;
        ppuStack_1a8 = apuStack_1e0;
        func_0x0001800ac810(0x23c2,&UNK_1819dd7f0,apuStack_1e0,apuStack_168);
        func_0x0001800553f0(apuStack_1e0);
        func_0x0001800553f0(apuStack_168);
      }
      func_0x0001800579c0();
      func_0x000180019460();
    }
    lVar25 = _DAT_181b2f2c0;
    if (_DAT_181b50d50 == 3) {
      fVar40 = _DAT_181b32b44 + fVar34;
      *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
      lVar25 = *(longlong *)(lVar25 + 0x3f10);
      *(float *)(lVar25 + 0x100) = (*(float *)(lVar25 + 0x20) - *(float *)(lVar25 + 0x84)) + fVar38;
      *(float *)(lVar25 + 0x104) = (*(float *)(lVar25 + 0x24) - *(float *)(lVar25 + 0x88)) + fVar40;
      *(undefined *)(lVar25 + 0x141) = 1;
      func_0x000180019310();
      lVar20 = _DAT_181b2f2c0;
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar23 = (float *)(lVar25 + 0x254), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar23 = (float *)(lVar25 + 0x224);
      }
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar24 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar24 = (float *)(lVar25 + 0x220);
      }
      uStackX_10 = (undefined *)
                   CONCAT44((((*pfVar23 - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810))
                            - fVar39) + _DAT_181b32b44,
                            (*pfVar24 - *(float *)(lVar25 + 0x100)) * fVar41);
      *(undefined *)(lVar25 + 0xb8) = 1;
      uVar35 = *(undefined8 *)(lVar20 + 0x3f10);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(2,&uStackX_8);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(0xe,&uStackX_8);
      uVar7 = func_0x000180009d10(uVar35,&UNK_1819dd7e0);
      func_0x000180057580(&UNK_1819dd7e0,uVar7,&uStackX_10);
      uVar28 = (ulonglong)puVar16 & 0xffffffffffffff00;
      func_0x000180056290(&UNK_1819dd800,&UNK_1819dd810,&DAT_181ade1f8,0x181b32d10,uVar28);
      uVar35 = CONCAT71((int7)(uVar28 >> 8),1);
      func_0x000180056290(&UNK_1819dd828,&UNK_1819dd838,&DAT_181b32b7c,0x181b32b80,uVar35);
      uVar35 = CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dd850,&UNK_1819dd868,&DAT_181b2f398,0x181b32bd8,uVar35);
      uVar35 = CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dd878,&UNK_1819dd890,&DAT_181b303b8,0x181b32ba0,uVar35);
      uVar35 = CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dd8a8,&UNK_1819dd8c0,&DAT_181b32b40,0x181b32bf0,uVar35);
      uVar35 = CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dd8e0,&UNK_1819dd8f8,&DAT_181b2f3c8,0x181b32bd4,uVar35);
      func_0x0001800579c0();
      func_0x000180019010();
      lVar20 = _DAT_181b2f2c0;
      lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar23 = (float *)(lVar25 + 0x254), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar23 = (float *)(lVar25 + 0x224);
      }
      if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
         (pfVar24 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
        pfVar24 = (float *)(lVar25 + 0x220);
      }
      uStackX_10 = (undefined *)
                   CONCAT44((((*pfVar23 - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810))
                            - fVar39) + _DAT_181b32b44,*pfVar24 - *(float *)(lVar25 + 0x100));
      *(undefined *)(lVar25 + 0xb8) = 1;
      uVar19 = *(undefined8 *)(lVar20 + 0x3f10);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(2,&uStackX_8);
      uStackX_8 = (undefined *)0x4150000041500000;
      func_0x000180006ac0(0xe,&uStackX_8);
      uVar7 = func_0x000180009d10(uVar19,&UNK_1819dd928);
      func_0x000180057580(&UNK_1819dd928,uVar7,&uStackX_10);
      uVar35 = CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dd950,&UNK_1819dd910,&DAT_181b32b50,0x181b32ba4,uVar35);
      uVar35 = CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dd978,&UNK_1819dd938,&DAT_181b32b4c,0x181b32bbc,uVar35);
      uVar35 = CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dd9a0,&UNK_1819dd960,&DAT_181b303bc,0x181b32bc0,uVar35);
      uVar35 = CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dd9c8,&UNK_1819dd988,&DAT_181b30428,0x181b32bc4,uVar35);
      uVar35 = CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dd9f0,&UNK_1819dd9b0,&DAT_181ade2b8,0x181b32ce0,uVar35);
      puVar16 = (undefined8 *)CONCAT71((int7)((ulonglong)uVar35 >> 8),1);
      func_0x000180056290(&UNK_1819dda18,&UNK_1819dd9d8,&DAT_181b3042c,0x181b32be8,puVar16);
      func_0x0001800579c0();
      func_0x000180019460();
    }
    lVar25 = _DAT_181b2f2c0;
    if (_DAT_181b50d50 != 4) goto LAB_1800b3b57;
    fVar34 = _DAT_181b32b44 + fVar34;
    *(undefined *)(*(longlong *)(_DAT_181b2f2c0 + 0x3f10) + 0xb8) = 1;
    lVar25 = *(longlong *)(lVar25 + 0x3f10);
    *(float *)(lVar25 + 0x100) = (*(float *)(lVar25 + 0x20) - *(float *)(lVar25 + 0x84)) + fVar38;
    *(float *)(lVar25 + 0x104) = (*(float *)(lVar25 + 0x24) - *(float *)(lVar25 + 0x88)) + fVar34;
    *(undefined *)(lVar25 + 0x141) = 1;
    func_0x000180019310();
    lVar20 = _DAT_181b2f2c0;
    lVar25 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
    if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
       (pfVar23 = (float *)(lVar25 + 0x254), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
      pfVar23 = (float *)(lVar25 + 0x224);
    }
    if ((*(longlong *)(lVar25 + 0x1a8) != 0) ||
       (pfVar24 = (float *)(lVar25 + 0x250), *(longlong *)(_DAT_181b2f2c0 + 0x4be0) != 0)) {
      pfVar24 = (float *)(lVar25 + 0x220);
    }
    uStackX_10 = (undefined *)
                 CONCAT44((((*pfVar23 - *(float *)(lVar25 + 0x104)) - *(float *)(lVar26 + 0x3810)) -
                          fVar39) + _DAT_181b32b44,(*pfVar24 - *(float *)(lVar25 + 0x100)) * fVar41)
    ;
    *(undefined *)(lVar25 + 0xb8) = 1;
    uVar35 = *(undefined8 *)(lVar20 + 0x3f10);
    uStackX_8 = (undefined *)0x4150000041500000;
    func_0x000180006ac0(2,&uStackX_8);
    uStackX_8 = (undefined *)0x4150000041500000;
    func_0x000180006ac0(0xe,&uStackX_8);
    uVar7 = func_0x000180009d10(uVar35,&UNK_1819dda00);
    func_0x000180057580(&UNK_1819dda00,uVar7,&uStackX_10);
    cVar4 = func_0x000180059d50(&UNK_1819dda28,&UNK_1819dda40,&DAT_181b30590);
    if ((cVar4 != '\0') && (DAT_181b30590 != '\0')) {
      func_0x0001800b5bd0(&uStack_118);
      func_0x000180067c80(&uStack_118);
      if (iStack_110 != 0) {
        terminate();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    cVar4 = func_0x000180059d50(&UNK_1819dda58,&UNK_1819dda70,&DAT_181b30592);
    if ((cVar4 != '\0') && (DAT_181b30592 != '\0')) {
      func_0x0001800b5c40(&uStack_118);
      func_0x000180067c80(&uStack_118);
      if (iStack_110 != 0) {
        terminate();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
    func_0x000180059d50(&UNK_1819dda90,&UNK_1819ddaa0,&DAT_181b2bc6d);
    func_0x000180059d50(&UNK_1819ddab8,&UNK_1819ddad0,&DAT_181b2bc70);
    lVar26 = _DAT_181b2f2c0;
    if (DAT_181b2f6dd == '\0') {
      _DAT_181b32b60 = 0;
      DAT_181ade204 = 1;
      DAT_181b2f6dd = '\x01';
    }
    apuStack_168[0] = (undefined8 *)&UNK_1819ddb38;
    apuStack_168[1] = (undefined8 *)&UNK_1819ddb20;
    if ((_DAT_181b32b60 < 0) || (1 < _DAT_181b32b60)) {
      _DAT_181b32b60 = 0;
    }
    puVar29 = (undefined8 *)&UNK_18020df8a;
    if (apuStack_168[_DAT_181b32b60] != (undefined8 *)0x0) {
      puVar29 = apuStack_168[_DAT_181b32b60];
    }
    cVar4 = func_0x00018005b350(&UNK_1819ddb50,&UNK_1819ddb60,puVar29,2,
                                (ulonglong)puVar16 & 0xffffffffffffff00,
                                (ulonglong)puVar18 & 0xffffffff00000000);
    if (cVar4 != '\0') {
      bVar3 = false;
      uStackX_8 = (undefined *)0x4170000041700000;
      func_0x000180006ac0(0xe,&uStackX_8);
      puVar18 = (undefined8 *)&UNK_1819d4fc8;
      if (apuStack_168[0] != (undefined8 *)0x0) {
        puVar18 = apuStack_168[0];
      }
      func_0x000180015530(0);
      iVar8 = _DAT_181b32b60;
      uStackX_8 = (undefined *)0x0;
      cVar4 = func_0x00018005d120(puVar18,_DAT_181b32b60 == 0,0,&uStackX_8);
      if ((cVar4 != '\0') && (_DAT_181b32b60 != 0)) {
        bVar3 = true;
        _DAT_181b32b60 = 0;
      }
      if (iVar8 == 0) {
        func_0x000180015390();
      }
      func_0x0001800155b0();
      puVar27 = &UNK_1819d4fc8;
      if (apuStack_168[1] != (undefined8 *)0x0) {
        puVar27 = (undefined *)apuStack_168[1];
      }
      func_0x000180015530(1);
      iVar8 = _DAT_181b32b60;
      uStackX_8 = (undefined *)0x0;
      cVar4 = func_0x00018005d120(puVar27,_DAT_181b32b60 == 1,0,&uStackX_8);
      if ((cVar4 != '\0') && (_DAT_181b32b60 != 1)) {
        bVar3 = true;
        _DAT_181b32b60 = 1;
      }
      if (iVar8 == 1) {
        func_0x000180015390();
      }
      func_0x0001800155b0();
      func_0x000180006ba0(1);
      func_0x000180013b80();
      if (bVar3) {
        func_0x00018000a300(*(undefined4 *)(lVar26 + 0x47b8));
        DAT_181ade204 = _DAT_181b32b60 == 0;
        uStack_188._0_4_ = _DAT_181a2aff0;
        uStack_188._4_4_ = _DAT_181a2aff4;
        iStack_180 = _DAT_181a2aff8;
        fStack_17c = _DAT_181a2affc;
        puVar27 = &UNK_1819ddb88;
        if (_DAT_181b32b60 == 0) {
          puVar27 = &UNK_1819ddba0;
        }
        recovered_18009bbb0(&UNK_1819ddba0,puVar27);
      }
    }
    func_0x000180059d50(&UNK_1819ddbb8,&UNK_1819ddbc8,&DAT_181b2bc6e);
    if (DAT_181b2bc6e == '\0') {
      func_0x00018005dc00(&UNK_1819ddbe8,&UNK_1819ddbf8,&DAT_181a2aff0,0x30120);
    }
    cVar4 = func_0x000180059d50(&UNK_1819ddc18,&UNK_1819ddc30,&DAT_181b305c0);
    if ((cVar4 != '\0') && (DAT_181b305c0 != '\0')) {
      func_0x0001800af680();
    }
    lVar26 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
    if ((*(longlong *)(lVar26 + 0x1a8) == 0) && (*(longlong *)(_DAT_181b2f2c0 + 0x4be0) == 0)) {
      pfVar23 = (float *)(lVar26 + 0x250);
    }
    else {
      pfVar23 = (float *)(lVar26 + 0x220);
    }
    uStackX_8 = (undefined *)CONCAT44(0x42200000,*pfVar23 - *(float *)(lVar26 + 0x100));
    cVar4 = func_0x000180058040(&UNK_1819ddc70,&uStackX_8);
    if (cVar4 != '\0') {
      func_0x0001800af9d0();
    }
    lVar26 = *(longlong *)(_DAT_181b2f2c0 + 0x3f10);
    if ((*(longlong *)(lVar26 + 0x1a8) == 0) && (*(longlong *)(_DAT_181b2f2c0 + 0x4be0) == 0)) {
      pfVar23 = (float *)(lVar26 + 0x250);
    }
    else {
      pfVar23 = (float *)(lVar26 + 0x220);
    }
    uStackX_8 = (undefined *)CONCAT44(0x42200000,*pfVar23 - *(float *)(lVar26 + 0x100));
    cVar4 = func_0x000180058040(&UNK_1819ddc60,&uStackX_8);
    if (cVar4 != '\0') {
      uVar35 = func_0x0001800b5cb0(&uStack_188);
      func_0x000180067c80(uVar35);
      if (iStack_180 != 0) {
        terminate();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
    }
  }
  func_0x0001800579c0();
  func_0x000180019460();
LAB_1800b3b57:
  func_0x00018009bde0();
  func_0x000180013b80();
  if (((_DAT_181b50d50 == 1) && (DAT_181b2bdd0 != '\0')) && (DAT_181b2bdd1 != '\0')) {
    func_0x000180091c60(1);
  }
  return;
}

