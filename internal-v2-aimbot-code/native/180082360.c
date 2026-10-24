/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180082360(void)

{
  double dVar1;
  code *pcVar2;
  undefined auVar3 [16];
  undefined auVar4 [16];
  undefined auVar5 [16];
  float fVar6;
  longlong lVar7;
  ulonglong uVar8;
  char cVar9;
  char cVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  longlong lVar17;
  undefined (*pauVar18) [16];
  longlong lVar19;
  undefined *puVar20;
  longlong *plVar21;
  longlong **pplVar22;
  longlong **pplVar23;
  undefined8 ****ppppuVar24;
  undefined *puVar25;
  undefined8 ****ppppuVar26;
  longlong *****ppppplVar27;
  longlong **pplVar28;
  ulonglong uVar29;
  undefined8 *puVar30;
  undefined8 *puVar31;
  longlong **pplVar32;
  undefined8 ****ppppuVar33;
  ulonglong uVar34;
  char *pcVar35;
  float fVar37;
  longlong *plVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  undefined8 uVar42;
  undefined8 extraout_XMM0_Qb;
  float fVar43;
  float fVar44;
  float fVar45;
  undefined auVar46 [16];
  undefined auVar47 [16];
  undefined auVar48 [16];
  float fVar49;
  float fStackX_8;
  float fStackX_c;
  float fStackX_10;
  float fStackX_14;
  undefined8 uStackX_18;
  float afStackX_20 [2];
  longlong *****in_stack_fffffffffffffa48;
  undefined4 uVar50;
  longlong *****in_stack_fffffffffffffa50;
  undefined8 *in_stack_fffffffffffffa58;
  undefined7 uVar51;
  float fStack_588;
  float fStack_584;
  longlong lStack_580;
  int iStack_578;
  int iStack_574;
  longlong **pplStack_570;
  longlong *aplStack_568 [2];
  longlong *aplStack_558 [2];
  float fStack_548;
  float fStack_544;
  undefined auStack_538 [16];
  longlong *plStack_528;
  undefined *puStack_520;
  undefined4 uStack_518;
  undefined4 uStack_514;
  undefined4 uStack_510;
  undefined4 uStack_50c;
  float fStack_508;
  undefined auStack_4f8 [16];
  undefined8 uStack_4e8;
  ulonglong uStack_4e0;
  undefined4 uStack_4d8;
  undefined4 uStack_4d4;
  undefined4 uStack_4d0;
  undefined4 uStack_4cc;
  undefined auStack_4c8 [16];
  undefined auStack_4b8 [16];
  undefined auStack_4a8 [16];
  undefined4 uStack_498;
  undefined4 uStack_494;
  undefined4 uStack_490;
  undefined4 uStack_48c;
  undefined auStack_488 [16];
  float fStack_478;
  float fStack_474;
  float fStack_470;
  float fStack_46c;
  float fStack_468;
  float fStack_464;
  float fStack_460;
  float fStack_45c;
  undefined4 uStack_458;
  undefined4 uStack_454;
  float afStack_450 [2];
  float fStack_448;
  float fStack_444;
  float fStack_440;
  float fStack_43c;
  float fStack_438;
  float fStack_434;
  undefined auStack_430 [8];
  undefined4 uStack_428;
  undefined4 uStack_424;
  undefined auStack_420 [16];
  undefined auStack_410 [16];
  undefined auStack_400 [16];
  undefined auStack_3f0 [16];
  undefined auStack_3e0 [16];
  undefined auStack_3d0 [16];
  ulonglong uStack_3c0;
  ulonglong uStack_3b8;
  undefined auStack_3a8 [16];
  char acStack_394 [12];
  float fStack_388;
  float fStack_384;
  float fStack_380;
  float fStack_37c;
  float fStack_378;
  float fStack_374;
  float fStack_370;
  float fStack_36c;
  undefined4 uStack_368;
  undefined4 uStack_364;
  undefined8 uStack_360;
  float fStack_358;
  float fStack_354;
  float fStack_350;
  float fStack_34c;
  float fStack_348;
  float fStack_344;
  undefined4 uStack_340;
  undefined4 uStack_33c;
  undefined8 auStack_338 [2];
  undefined auStack_328 [16];
  float fStack_318;
  float fStack_314;
  float fStack_310;
  float fStack_30c;
  undefined4 uStack_308;
  undefined4 uStack_304;
  undefined8 uStack_300;
  float fStack_2f8;
  float fStack_2f4;
  float fStack_2f0;
  float fStack_2ec;
  float fStack_2e8;
  float fStack_2e4;
  float fStack_2e0;
  float fStack_2dc;
  undefined auStack_2d8 [12];
  undefined2 uStack_2cc;
  undefined2 uStack_2ca;
  undefined4 uStack_2c8;
  undefined4 uStack_2c4;
  undefined4 uStack_2c0;
  undefined4 uStack_2bc;
  undefined8 uStack_2b8;
  float fStack_2a8;
  float fStack_2a4;
  float fStack_2a0;
  undefined4 uStack_29c;
  undefined8 ****appppuStack_298 [2];
  longlong lStack_288;
  ulonglong uStack_280;
  longlong *****appppplStack_278 [2];
  longlong lStack_268;
  ulonglong uStack_260;
  undefined auStack_258 [8];
  undefined auStack_250 [8];
  undefined auStack_248 [8];
  undefined auStack_240 [8];
  undefined auStack_238 [8];
  undefined8 uStack_230;
  undefined auStack_228 [4];
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined auStack_218 [16];
  undefined8 ****appppuStack_208 [2];
  ulonglong uStack_1f8;
  ulonglong uStack_1f0;
  float *pfStack_1e8;
  undefined4 *puStack_1e0;
  float *pfStack_1d8;
  undefined4 *puStack_1d0;
  float *pfStack_1c8;
  undefined4 *puStack_1c0;
  undefined4 *puStack_1b8;
  float *pfStack_1b0;
  undefined4 *puStack_1a8;
  undefined8 *puStack_1a0;
  undefined4 *puStack_198;
  undefined8 ****appppuStack_188 [2];
  ulonglong uStack_178;
  ulonglong uStack_170;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined auStack_118 [16];
  undefined auStack_108 [96];
  char *pcVar36;
  
  lVar19 = _DAT_181b2f2c0;
  fVar37 = 0.0;
  fStackX_10 = 0.0;
  fStackX_8 = 0.0;
  if (DAT_181b2b46c != '\0') {
    DAT_181b2f6da = '\0';
    if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
      _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
    }
    lStack_580 = func_0x00018000a880(**(undefined8 **)(lVar19 + 0x4908),0,&UNK_18020ed28);
    if (lStack_580 != 0) {
      recovered_18007b0b0();
      fVar6 = _DAT_181a03230;
      iStack_574 = _DAT_181b2bec8;
      iStack_578 = _DAT_181b2becc;
      pplStack_570 = _DAT_181b2be38;
      pplVar28 = (longlong **)*_DAT_181b2be38;
      pplVar22 = _DAT_181b2be38;
      fVar45 = _DAT_181a031bc;
      if (pplVar28 != _DAT_181b2be38) {
        do {
          uVar42 = 0;
          if (((*(char *)((longlong)pplVar28 + 0x19) != '\0') &&
              (*(char *)((longlong)pplVar28 + 0x1a) == '\0')) &&
             ((DAT_181b2bedc != '\0' || (*(char *)((longlong)pplVar28 + 0x1c) != '\0')))) {
            auVar48._4_4_ = _DAT_181b2b56c;
            auVar48._0_4_ = _DAT_181b2b568;
            auVar48._8_4_ = _DAT_181b2b570;
            auVar48._12_4_ = _DAT_181b2b574;
            cVar10 = *(char *)((longlong)pplVar28 + 0x1b);
            fVar39 = fVar6;
            fVar40 = fVar6;
            fVar41 = fVar6;
            if ((DAT_181b2bc70 == '\0') && (DAT_181b2b564 != '\0')) {
              dVar1 = *(double *)(_DAT_181b2f2c0 + 0x3e60);
              fVar39 = (float)func_0x0001801cb519((float)dVar1 + _DAT_181a032a8);
              fVar40 = (float)func_0x0001801cb519((float)dVar1 + _DAT_181a03270);
              fVar41 = (float)func_0x0001801cb519();
              fVar39 = fVar39 * fVar45 + fVar45;
              fVar40 = fVar40 * fVar45 + fVar45;
              fVar41 = fVar41 * fVar45 + fVar45;
            }
            fStack_2a8 = fVar41;
            fStack_2a4 = fVar40;
            uStack_29c = 0x3f800000;
            fStack_2a0 = fVar39;
            if ((DAT_181b2b565 == '\0') ||
               (cVar9 = recovered_180080860(pplVar28 + 3), pplVar22 = pplStack_570, cVar9 == '\0'))
            {
              aplStack_558[0] = pplVar28[0x14];
              fVar39 = _DAT_181b2beb0 - SUB84(aplStack_558[0],0);
              fVar40 = _DAT_181b2beb4 - (float)((ulonglong)aplStack_558[0] >> 0x20);
              fVar39 = fVar40 * fVar40 + fVar39 * fVar39 +
                       (_DAT_181b2beb8 - *(float *)(pplVar28 + 0x15)) *
                       (_DAT_181b2beb8 - *(float *)(pplVar28 + 0x15));
              if (fVar39 < 0.0) {
                fStack_508 = (float)func_0x0001801cb525();
              }
              else {
                fStack_508 = SQRT(fVar39);
              }
              pplVar22 = pplStack_570;
              if (fStack_508 <= (float)_DAT_181b2b57c) {
                uVar29 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffa48 >> 0x20),_DAT_181b2becc
                                 );
                recovered_180067e80(&fStack_448,&DAT_181b2be70,pplVar28 + 0x14,_DAT_181b2bec8,uVar29
                                   );
                in_stack_fffffffffffffa48 = (longlong *****)(uVar29 & 0xffffffff00000000);
                recovered_180067e80(&fStack_350,&DAT_181b2be70,pplVar28 + 0x2c);
                fVar40 = fStack_444;
                fVar39 = fStack_448;
                uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                pplVar22 = pplStack_570;
                if (((((fVar6 <= fStack_448) && (fVar6 <= fStack_444)) && (fVar6 <= fStack_350)) &&
                    ((fVar45 = _DAT_181a031bc, fVar6 <= fStack_34c &&
                     (fStack_448 <= (float)iStack_574)))) && (fStack_444 <= (float)iStack_578)) {
                  plVar21 = pplVar28[0x14];
                  uStack_2b8 = plVar21;
                  plVar21 = uStack_2b8;
                  fVar45 = _DAT_181a0317c;
                  if (cVar10 != '\0') {
                    fVar45 = _DAT_181a03160;
                  }
                  uStack_2b8._4_4_ = (float)((ulonglong)plVar21 >> 0x20);
                  fVar45 = fVar45 + uStack_2b8._4_4_;
                  if ((iStack_574 < 1) || (iStack_578 < 1)) {
LAB_180082811:
                    uStackX_18 = CONCAT44(fStack_444,fStack_448);
                    fVar44 = fStack_444;
                  }
                  else {
                    uStack_2b8._0_4_ = SUB84(plVar21,0);
                    fVar41 = *(float *)(pplVar28 + 0x15);
                    fVar43 = (float)uStack_2b8 * _DAT_181b2be7c + fVar45 * _DAT_181b2be8c +
                             fVar41 * _DAT_181b2be9c + _DAT_181b2beac;
                    if ((fVar43 < _DAT_181a03124) ||
                       ((fVar49 = (float)iStack_574 * _DAT_181a031bc,
                        fVar44 = (float)iStack_578 * _DAT_181a031bc,
                        fVar44 = fVar44 - (fVar44 * ((float)uStack_2b8 * _DAT_181b2be74 +
                                                     fVar45 * _DAT_181b2be84 +
                                                     fVar41 * _DAT_181b2be94 + _DAT_181b2bea4)) /
                                          fVar43,
                        (fVar49 * ((float)uStack_2b8 * _DAT_181b2be70 + fVar45 * _DAT_181b2be80 +
                                   fVar41 * _DAT_181b2be90 + _DAT_181b2bea0)) / fVar43 + fVar49 <
                        fVar6 || (fVar44 < fVar6)))) goto LAB_180082811;
                  }
                  fVar41 = (float)((uint)(fStack_34c - fVar44) & _DAT_181a039d0);
                  if (fVar41 < _DAT_181a032e0) {
                    fVar41 = _DAT_181a032e0;
                  }
                  uStackX_18 = CONCAT44(uStackX_18._4_4_,fVar41);
                  fStack_584 = _DAT_181a031c8;
                  if (cVar10 != '\0') {
                    fStack_584 = _DAT_181a031fc;
                  }
                  fStack_584 = fVar41 * fStack_584;
                  afStack_450[0] = (fStack_350 + fStack_448) * _DAT_181a031bc;
                  afStackX_20[0] = afStack_450[0] - fStack_584 * _DAT_181a031bc;
                  fStack_588 = fStack_34c;
                  if (fVar44 <= fStack_34c) {
                    fStack_588 = fVar44;
                  }
                  if (cVar10 == '\0') {
                    auStack_538._4_4_ = fStack_2a4;
                    auStack_538._0_4_ = fStack_2a8;
                    auStack_538._8_4_ = fStack_2a0;
                    auStack_538._12_4_ = uStack_29c;
                    auStack_400 = auStack_538;
                    if ((DAT_181b2bc70 == '\0') && (DAT_181b2b564 != '\0')) {
                      auStack_4f8 = auStack_538;
                    }
                    else {
                      auStack_4f8 = _DAT_181b2b478;
                    }
                    if ((((DAT_181b2bc70 == '\0') && (auVar48 = auStack_538, DAT_181b2b564 != '\0'))
                        || (auVar48 = _DAT_181b2b4a0, DAT_181b2bc70 == '\0')) &&
                       (DAT_181b2b564 != '\0')) {
                      _auStack_430 = auStack_538;
LAB_180082975:
                      if (DAT_181b2b564 == '\0') goto LAB_180082989;
                      auStack_4b8 = auStack_538;
LAB_18008299f:
                      if (DAT_181b2b564 == '\0') goto LAB_1800829b1;
                      auStack_328 = auStack_538;
LAB_1800829c8:
                      if (DAT_181b2b564 == '\0') goto LAB_1800829da;
                      auStack_3a8 = auStack_538;
LAB_1800829f2:
                      if (DAT_181b2b564 == '\0') goto LAB_180082a01;
LAB_180082a15:
                      if (DAT_181b2b564 != '\0') goto LAB_180082a2d;
                    }
                    else {
                      _auStack_430 = _DAT_181b2b53c;
                      if (DAT_181b2bc70 == '\0') goto LAB_180082975;
LAB_180082989:
                      auStack_4b8 = _DAT_181b2b4c8;
                      if (DAT_181b2bc70 == '\0') goto LAB_18008299f;
LAB_1800829b1:
                      auStack_328 = _DAT_181b2b4dc;
                      if (DAT_181b2bc70 == '\0') goto LAB_1800829c8;
LAB_1800829da:
                      auStack_3a8 = _DAT_181b2b4f0;
                      if (DAT_181b2bc70 == '\0') goto LAB_1800829f2;
LAB_180082a01:
                      auStack_538 = _DAT_181b2b508;
                      if (DAT_181b2bc70 == '\0') goto LAB_180082a15;
                    }
                    auStack_400 = _DAT_181b2b550;
                  }
                  else {
                    auStack_4f8 = auVar48;
                    _auStack_430 = auVar48;
                    auStack_4b8 = auVar48;
                    auStack_328 = auVar48;
                    auStack_3a8 = auVar48;
                    auStack_400 = auVar48;
                    auStack_538 = auVar48;
                  }
LAB_180082a2d:
                  auVar46 = auStack_4b8;
                  uVar15 = _DAT_181a03240;
                  uStack_2b8 = plVar21;
                  if (DAT_181b2b46d != '\0') {
                    if (_DAT_181b2f2c0 == 0) {
                      _wassert(&UNK_18020e450,&UNK_18020daf0,0x10b1);
                    }
                    fVar45 = _DAT_181b2b578;
                    if (_DAT_181b2b578 <= _DAT_181a03314) {
                      fVar45 = _DAT_181a03314;
                    }
                    fVar44 = fVar45 * _DAT_181a031bc;
                    fVar43 = *(float *)(_DAT_181b2f2c0 + 0x10) * _DAT_181a031bc - fVar44;
                    fVar41 = _DAT_181a032fc;
                    if (_DAT_181b2b470 != 0) {
                      if (_DAT_181b2b470 == 1) {
                        fVar41 = *(float *)(_DAT_181b2f2c0 + 0x14) * _DAT_181a031bc - fVar44;
                      }
                      else {
                        fVar41 = (*(float *)(_DAT_181b2f2c0 + 0x14) - fVar45) - _DAT_181a032fc;
                      }
                    }
                    aplStack_568[0] = (longlong *)CONCAT44(fVar41,fVar43);
                    aplStack_558[0] = (longlong *)CONCAT44(fVar44 + fVar41,fVar44 + fVar43);
                    fStack_348 = fVar39;
                    fStack_344 = fVar40;
                    uVar11 = func_0x000180004f90(auStack_4f8);
                    uVar15 = _DAT_181a03240;
                    in_stack_fffffffffffffa48 = (longlong *****)CONCAT44(uVar50,_DAT_181a03240);
                    func_0x000180027b00(lStack_580,&fStack_348,aplStack_558,uVar11,
                                        in_stack_fffffffffffffa48);
                    uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa50 >> 0x20);
                    if (((_DAT_181b2b474 == 0) || (DAT_181b2f6da != '\0')) || (_DAT_181b2f3d0 == 0))
                    {
                      fVar41 = (float)uStackX_18;
                    }
                    else {
                      if (DAT_181b2bc70 == '\0') {
                        uStack_340 = 0x3f800000;
                        uStack_33c = 0x3f800000;
                        auStack_338[0] = 0;
                        fStack_318 = fVar45 + fVar43 + _DAT_181a03270;
                        fStack_314 = fVar45 + fVar41 + _DAT_181a03270;
                        fStack_310 = fVar43 - _DAT_181a03270;
                        fStack_30c = fVar41 - _DAT_181a03270;
                        in_stack_fffffffffffffa58 =
                             (undefined8 *)
                             CONCAT44((int)((ulonglong)in_stack_fffffffffffffa58 >> 0x20),0x5affffff
                                     );
                        puVar16 = &uStack_340;
                        func_0x000180028a10(lStack_580,_DAT_181b2f3d0,&fStack_310,&fStack_318,
                                            auStack_338,puVar16,in_stack_fffffffffffffa58);
                        uVar50 = (undefined4)((ulonglong)puVar16 >> 0x20);
                      }
                      lVar7 = lStack_580;
                      lVar17 = _DAT_181b2f3d0;
                      uStack_308 = 0x3f800000;
                      uStack_304 = 0x3f800000;
                      uStack_300 = 0;
                      fStack_2f8 = fVar45 + fVar43;
                      fStack_2f4 = fVar45 + fVar41;
                      lVar19 = *(longlong *)(lStack_580 + 0x98);
                      if (_DAT_181b2f3d0 != lVar19) {
                        func_0x0001800255e0(lStack_580,_DAT_181b2f3d0);
                      }
                      func_0x000180025660(lVar7,6,4);
                      in_stack_fffffffffffffa50 = (longlong *****)CONCAT44(uVar50,0xffffffff);
                      in_stack_fffffffffffffa48 = (longlong *****)&uStack_308;
                      func_0x0001800257a0(lVar7,aplStack_568,&fStack_2f8,&uStack_300,
                                          in_stack_fffffffffffffa48,in_stack_fffffffffffffa50);
                      if (lVar17 != lVar19) {
                        if (*(int *)(lVar7 + 0x68) < 1) {
                          _wassert(&UNK_180213518,&UNK_18020d8d0,0x758);
                        }
                        iVar14 = *(int *)(lVar7 + 0x68);
                        iVar12 = iVar14 + -1;
                        *(int *)(lVar7 + 0x68) = iVar12;
                        if (iVar12 != 0) {
                          uVar42 = *(undefined8 *)
                                    (*(longlong *)(lVar7 + 0x70) + -0x10 + (longlong)iVar14 * 8);
                        }
                        *(undefined8 *)(lVar7 + 0x98) = uVar42;
                        func_0x000180025310(lVar7);
                      }
                      DAT_181b2f6da = '\x01';
                      fVar41 = (float)uStackX_18;
                      fVar37 = fStackX_10;
                    }
                  }
                  fVar40 = fStack_584;
                  fVar39 = fStack_588;
                  fVar45 = afStackX_20[0];
                  lVar19 = _DAT_181b2f2c0;
                  if (DAT_181b2b498 != '\0') {
                    if (_DAT_181b2b49c == 0) {
                      auStack_4f8 = auVar48;
                      if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
                        _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
                      }
                      lVar19 = func_0x00018000a880(**(undefined8 **)(lVar19 + 0x4908),0,
                                                   &UNK_18020ed28);
                      uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa58 >> 0x20);
                      if (lVar19 != 0) {
                        if ((DAT_181b2b4b0 != '\0') && (DAT_181b2bc70 == '\0')) {
                          if (cVar10 == '\0') {
                            uVar11 = func_0x000180004f90(0x181b2b4b4);
                          }
                          else {
                            uVar11 = 0x2d0000ff;
                          }
                          fStack_2f0 = fVar40 + fVar45;
                          fStack_2ec = fVar39 + fVar41;
                          in_stack_fffffffffffffa50 =
                               (longlong *****)
                               ((ulonglong)in_stack_fffffffffffffa50 & 0xffffffff00000000);
                          in_stack_fffffffffffffa48 =
                               (longlong *****)
                               ((ulonglong)in_stack_fffffffffffffa48 & 0xffffffff00000000);
                          fStack_2e8 = fVar45;
                          fStack_2e4 = fVar39;
                          func_0x000180027d60(lVar19,&fStack_2e8,&fStack_2f0,uVar11,
                                              in_stack_fffffffffffffa48,in_stack_fffffffffffffa50);
                        }
                        fStack_2e0 = fVar40 + fVar45;
                        fStack_2dc = fVar39 + fVar41;
                        fStack_388 = fVar45;
                        fStack_384 = fVar39;
                        uVar11 = func_0x000180004f90(auStack_4f8);
                        in_stack_fffffffffffffa58 = (undefined8 *)CONCAT44(uVar50,uVar15);
                        in_stack_fffffffffffffa50 =
                             (longlong *****)
                             ((ulonglong)in_stack_fffffffffffffa50 & 0xffffffff00000000);
                        in_stack_fffffffffffffa48 =
                             (longlong *****)
                             ((ulonglong)in_stack_fffffffffffffa48 & 0xffffffff00000000);
                        func_0x000180027c60(lVar19,&fStack_388,&fStack_2e0,uVar11,
                                            in_stack_fffffffffffffa48,in_stack_fffffffffffffa50,
                                            in_stack_fffffffffffffa58);
                      }
                    }
                    else {
                      if (_DAT_181b2b49c != 1) goto LAB_180082f28;
                      in_stack_fffffffffffffa58 =
                           (undefined8 *)
                           CONCAT44((int)((ulonglong)in_stack_fffffffffffffa58 >> 0x20),
                                    _DAT_181a032fc);
                      in_stack_fffffffffffffa50 =
                           (longlong *****)
                           CONCAT44((int)((ulonglong)in_stack_fffffffffffffa50 >> 0x20),uVar15);
                      in_stack_fffffffffffffa48 = (longlong *****)auStack_4f8;
                      auStack_4f8 = auVar48;
                      recovered_180080a40();
                    }
                    fVar41 = (float)uStackX_18;
                  }
LAB_180082f28:
                  fVar45 = fStack_588;
                  if (DAT_181b2b51c != '\0') {
                    if ((_DAT_181b2b524 == 0) || (_DAT_181b2b524 == 1)) {
                      in_stack_fffffffffffffa48 =
                           (longlong *****)
                           CONCAT71((int7)((ulonglong)in_stack_fffffffffffffa48 >> 8),cVar10);
                      recovered_180081370(*(undefined2 *)(pplVar28 + 5));
                    }
                    else {
                      uVar51 = (undefined7)((ulonglong)in_stack_fffffffffffffa58 >> 8);
                      uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                      if (_DAT_181b2b524 == 2) {
                        in_stack_fffffffffffffa58 = (undefined8 *)CONCAT71(uVar51,cVar10);
                        in_stack_fffffffffffffa50 =
                             (longlong *****)
                             CONCAT44((int)((ulonglong)in_stack_fffffffffffffa50 >> 0x20),fVar41);
                        in_stack_fffffffffffffa48 = (longlong *****)CONCAT44(uVar50,fStack_584);
                        recovered_180081850(*(undefined2 *)(pplVar28 + 5));
                      }
                      else if (_DAT_181b2b524 == 3) {
                        in_stack_fffffffffffffa58 = (undefined8 *)CONCAT71(uVar51,cVar10);
                        in_stack_fffffffffffffa48 = (longlong *****)CONCAT44(uVar50,fStack_584);
                        recovered_180081e00(*(undefined2 *)(pplVar28 + 5));
                      }
                    }
                  }
                  uStack_510 = 0x40800000;
                  uStack_50c = 0x40800000;
                  uStack_518 = 0x40800000;
                  uStack_458 = 0;
                  uStack_514 = 0x40800000;
                  uStack_454 = 0;
                  if (DAT_181b2b51c != '\0') {
                    if (_DAT_181b2b524 == 0) {
                      uStack_518 = 0x41200000;
                    }
                    else if (_DAT_181b2b524 == 1) {
                      uStack_514 = 0x41200000;
                    }
                    else if (_DAT_181b2b524 == 2) {
                      uStack_50c = 0x41300000;
                    }
                    else if (_DAT_181b2b524 == 3) {
                      uStack_510 = 0x41300000;
                    }
                  }
                  pfStack_1e8 = afStackX_20;
                  puStack_1e0 = &uStack_518;
                  pfStack_1d8 = &fStack_588;
                  puStack_1d0 = &uStack_458;
                  pfStack_1c8 = &fStack_584;
                  puStack_1c0 = &uStack_514;
                  puStack_1b8 = &uStack_454;
                  pfStack_1b0 = afStack_450;
                  puStack_1a8 = &uStack_510;
                  puStack_1a0 = &uStackX_18;
                  puStack_198 = &uStack_50c;
                  aplStack_568[0] = &lStack_580;
                  if (DAT_181b2b4c4 != '\0') {
                    plVar21 = pplVar28[9];
                    if (plVar21 == (longlong *)0x0) {
                      uStack_2c8 = _DAT_181a035f0;
                      uStack_2c4 = _UNK_181a035f4;
                      uStack_2c0 = _UNK_181a035f8;
                      uStack_2bc = _UNK_181a035fc;
                      auStack_2d8._8_4_ = _DAT_1819d8288;
                      auStack_2d8._0_8_ = _DAT_1819d8280;
                      uStack_2cc = _DAT_1819d828c;
                      uStack_2ca = 0;
                      puVar16 = (undefined4 *)auStack_2d8;
                      fVar37 = (float)((uint)fVar37 | 1);
                    }
                    else {
                      pauVar18 = (undefined (*) [16])(pplVar28 + 7);
                      if ((longlong *)0xf < pplVar28[10]) {
                        pauVar18 = *(undefined (**) [16])*pauVar18;
                      }
                      auStack_4f8 = ZEXT816(0);
                      if ((longlong *)0x7fffffffffffffff < plVar21) goto LAB_180084f07;
                      if (plVar21 < (longlong *)0x10) {
                        uStack_4e8 = plVar21;
                        uStack_4e0 = 0xf;
                        auStack_4f8 = *pauVar18;
                      }
                      else {
                        uVar29 = (ulonglong)plVar21 | 0xf;
                        if (uVar29 < 0x8000000000000000) {
                          if (uVar29 < 0x16) {
                            uVar29 = 0x16;
                          }
                        }
                        else {
                          uVar29 = 0x7fffffffffffffff;
                        }
                        uVar42 = func_0x000180024110(uVar29 + 1);
                        auStack_4f8._0_8_ = uVar42;
                        uStack_4e8 = plVar21;
                        uStack_4e0 = uVar29;
                        func_0x0001801ca88d(uVar42,pauVar18,(longlong)plVar21 + 1);
                      }
                      puVar16 = (undefined4 *)auStack_4f8;
                      fVar37 = (float)((uint)fStackX_10 | 2);
                    }
                    uStack_498 = *puVar16;
                    uStack_494 = puVar16[1];
                    uStack_490 = puVar16[2];
                    uStack_48c = puVar16[3];
                    auStack_488 = *(undefined (*) [16])(puVar16 + 4);
                    *(undefined8 *)(puVar16 + 4) = 0;
                    *(undefined8 *)(puVar16 + 6) = 0xf;
                    *(undefined *)puVar16 = 0;
                    fStackX_8 = fVar37;
                    fStackX_10 = fVar37;
                    ppppplVar27 = in_stack_fffffffffffffa50;
                    if (((uint)fVar37 & 2) != 0) {
                      fVar37 = (float)((uint)fVar37 & 0xfffffffd);
                      fStackX_8 = fVar37;
                      fStackX_10 = fVar37;
                      recovered_180066e40(auStack_4f8);
                      ppppplVar27 = in_stack_fffffffffffffa50;
                    }
                    if (((uint)fVar37 & 1) == 0) {
LAB_180083286:
                      lVar19 = _DAT_181b2f2c0;
                      plVar21 = _DAT_181b4f000;
                      if ((((_DAT_181b4f000 != (longlong *)0x0) ||
                           (plVar21 = _DAT_181b4f020, _DAT_181b4f020 != (longlong *)0x0)) ||
                          (plVar21 = _DAT_181b4f008, _DAT_181b4f008 != (longlong *)0x0)) ||
                         (((plVar21 = _DAT_181b4eff0, _DAT_181b4eff0 != (longlong *)0x0 ||
                           (plVar21 = _DAT_181b4f018, _DAT_181b4f018 != (longlong *)0x0)) ||
                          ((plVar21 = _DAT_181b4eff8, _DAT_181b4eff8 != (longlong *)0x0 ||
                           (plVar21 = *(longlong **)(_DAT_181b2f2c0 + 0x3c30),
                           plVar21 != (longlong *)0x0)))))) {
                        aplStack_558[0] = plVar21;
                        func_0x0001800149b0(plVar21);
                        func_0x000180022d70(lVar19 + 0x4888,aplStack_558);
                        func_0x0001800255e0(*(undefined8 *)(*(longlong *)(lVar19 + 0x3f10) + 0x298),
                                            *(undefined8 *)(plVar21[8] + 8));
                      }
                      fVar39 = _DAT_181a0348c;
                      in_stack_fffffffffffffa50 = (longlong *****)&uStack_498;
                      if (0xf < (ulonglong)auStack_488._8_8_) {
                        in_stack_fffffffffffffa50 = (longlong *****)CONCAT44(uStack_494,uStack_498);
                      }
                      if (in_stack_fffffffffffffa50 == (longlong *****)0x0) {
                        fVar41 = *(float *)(_DAT_181b2f2c0 + 0x3c38);
                        in_stack_fffffffffffffa50 = ppppplVar27;
                        fVar40 = 0.0;
                      }
                      else {
                        in_stack_fffffffffffffa58 = (undefined8 *)0x0;
                        in_stack_fffffffffffffa48 =
                             (longlong *****)
                             CONCAT44((int)((ulonglong)in_stack_fffffffffffffa48 >> 0x20),
                                      _DAT_181a0348c);
                        func_0x000180030a70(*(undefined8 *)(_DAT_181b2f2c0 + 0x3c30),&fStack_440,
                                            *(float *)(_DAT_181b2f2c0 + 0x3c38),_DAT_181a03460,
                                            in_stack_fffffffffffffa48,in_stack_fffffffffffffa50,0);
                        fStack_440 = (float)(int)(fStack_440 + _DAT_181a03228);
                        fVar41 = fStack_43c;
                        fVar40 = fStack_440;
                      }
                      if (plVar21 != (longlong *)0x0) {
                        func_0x000180014ae0();
                      }
                      recovered_180084f20(&pfStack_1e8,&fStack_548,_DAT_181b2b528,
                                          CONCAT44(fVar41,fVar40));
                      if (plVar21 == (longlong *)0x0) {
                        fVar40 = *(float *)(_DAT_181b2f2c0 + 0x3c38);
                      }
                      else {
                        fVar40 = *(float *)((longlong)plVar21 + 0x14);
                      }
                      if (DAT_181b2bc70 == '\0') {
                        puVar31 = (undefined8 *)CONCAT44(uStack_494,uStack_498);
                        uVar29 = auStack_488._8_8_;
                        lVar19 = lStack_580;
                        fVar45 = fStack_544;
                        fVar37 = fVar39;
                        fVar43 = fStack_548;
                        fVar44 = fVar39;
                        do {
                          uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                          if ((fVar44 != 0.0) || (fVar37 != 0.0)) {
                            puVar30 = (undefined8 *)&uStack_498;
                            if (0xf < uVar29) {
                              puVar30 = puVar31;
                            }
                            fStack_380 = fVar43 + fVar44;
                            fStack_37c = fVar45 + fVar37;
                            lVar17 = -1;
                            do {
                              lVar17 = lVar17 + 1;
                            } while (*(char *)((longlong)puVar30 + lVar17) != '\0');
                            fVar41 = fVar40;
                            if (puVar30 != (undefined8 *)((longlong)puVar30 + lVar17)) {
                              plVar38 = plVar21;
                              if (plVar21 == (longlong *)0x0) {
                                plVar38 = *(longlong **)(*(longlong *)(lVar19 + 0x38) + 8);
                              }
                              if (fVar40 == 0.0) {
                                fVar41 = *(float *)(*(longlong *)(lVar19 + 0x38) + 0x10);
                              }
                              if (*(longlong *)(plVar38[8] + 8) != *(longlong *)(lVar19 + 0x98)) {
                                _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
                              }
                              uStack_128 = *(undefined4 *)(lVar19 + 0x88);
                              uStack_124 = *(undefined4 *)(lVar19 + 0x8c);
                              uStack_120 = *(undefined4 *)(lVar19 + 0x90);
                              uStack_11c = *(undefined4 *)(lVar19 + 0x94);
                              in_stack_fffffffffffffa50 = (longlong *****)&uStack_128;
                              in_stack_fffffffffffffa48 =
                                   (longlong *****)CONCAT44(uVar50,0xc8000000);
                              func_0x000180030c90(plVar38,lVar19,fVar41,&fStack_380,
                                                  in_stack_fffffffffffffa48,
                                                  in_stack_fffffffffffffa50,puVar30,
                                                  (undefined8 *)((longlong)puVar30 + lVar17),0,0);
                              puVar31 = (undefined8 *)CONCAT44(uStack_494,uStack_498);
                              uVar29 = auStack_488._8_8_;
                              lVar19 = lStack_580;
                              fVar45 = fStack_544;
                              in_stack_fffffffffffffa58 = puVar30;
                              fVar43 = fStack_548;
                            }
                          }
                          fVar37 = fVar37 + fVar6;
                        } while ((fVar37 <= fVar6) ||
                                (fVar44 = fVar44 + fVar6, fVar37 = fVar39, fVar44 <= fVar6));
                        puVar30 = (undefined8 *)&uStack_498;
                        if (0xf < uVar29) {
                          puVar30 = puVar31;
                        }
                        uVar13 = func_0x000180004f90(auStack_4b8);
                        uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                        fStack_378 = fVar43 + _DAT_181a031d8;
                        fStack_374 = fVar45;
                        if ((uVar13 & 0xff000000) != 0) {
                          lVar17 = -1;
                          do {
                            lVar17 = lVar17 + 1;
                          } while (*(char *)((longlong)puVar30 + lVar17) != '\0');
                          if (puVar30 != (undefined8 *)((longlong)puVar30 + lVar17)) {
                            plVar38 = plVar21;
                            if (plVar21 == (longlong *)0x0) {
                              plVar38 = *(longlong **)(*(longlong *)(lVar19 + 0x38) + 8);
                            }
                            fVar37 = fVar40;
                            if (fVar40 == 0.0) {
                              fVar37 = *(float *)(*(longlong *)(lVar19 + 0x38) + 0x10);
                            }
                            if (*(longlong *)(plVar38[8] + 8) != *(longlong *)(lVar19 + 0x98)) {
                              _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
                            }
                            uStack_168 = *(undefined4 *)(lVar19 + 0x88);
                            uStack_164 = *(undefined4 *)(lVar19 + 0x8c);
                            uStack_160 = *(undefined4 *)(lVar19 + 0x90);
                            uStack_15c = *(undefined4 *)(lVar19 + 0x94);
                            in_stack_fffffffffffffa50 = (longlong *****)&uStack_168;
                            in_stack_fffffffffffffa48 = (longlong *****)CONCAT44(uVar50,uVar13);
                            func_0x000180030c90(plVar38,lVar19,fVar37,&fStack_378,
                                                in_stack_fffffffffffffa48,in_stack_fffffffffffffa50,
                                                puVar30,(undefined8 *)((longlong)puVar30 + lVar17),0
                                                ,0);
                            puVar31 = (undefined8 *)CONCAT44(uStack_494,uStack_498);
                            uVar29 = auStack_488._8_8_;
                            lVar19 = lStack_580;
                            in_stack_fffffffffffffa58 = puVar30;
                          }
                        }
                        puVar30 = (undefined8 *)&uStack_498;
                        if (0xf < uVar29) {
                          puVar30 = puVar31;
                        }
                        uVar13 = func_0x000180004f90(auStack_4b8);
                        uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                        fVar37 = fStackX_10;
                        if ((uVar13 & 0xff000000) != 0) {
                          lVar17 = -1;
                          do {
                            lVar17 = lVar17 + 1;
                          } while (*(char *)((longlong)puVar30 + lVar17) != '\0');
                          if (puVar30 != (undefined8 *)((longlong)puVar30 + lVar17)) {
                            if (plVar21 == (longlong *)0x0) {
                              plVar21 = *(longlong **)(*(longlong *)(lVar19 + 0x38) + 8);
                            }
                            if (fVar40 == 0.0) {
                              fVar40 = *(float *)(*(longlong *)(lVar19 + 0x38) + 0x10);
                            }
                            if (*(longlong *)(plVar21[8] + 8) != *(longlong *)(lVar19 + 0x98)) {
                              _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
                            }
                            uStack_158 = *(undefined4 *)(lVar19 + 0x88);
                            uStack_154 = *(undefined4 *)(lVar19 + 0x8c);
                            uStack_150 = *(undefined4 *)(lVar19 + 0x90);
                            uStack_14c = *(undefined4 *)(lVar19 + 0x94);
                            in_stack_fffffffffffffa50 = (longlong *****)&uStack_158;
                            in_stack_fffffffffffffa48 = (longlong *****)CONCAT44(uVar50,uVar13);
                            func_0x000180030c90(plVar21,lVar19,fVar40,&fStack_548,
                                                in_stack_fffffffffffffa48,in_stack_fffffffffffffa50,
                                                puVar30,(undefined8 *)((longlong)puVar30 + lVar17),0
                                                ,0);
                            fVar37 = fStackX_10;
                            in_stack_fffffffffffffa58 = puVar30;
                          }
                        }
                      }
                      else {
                        puVar31 = (undefined8 *)&uStack_498;
                        if (0xf < (ulonglong)auStack_488._8_8_) {
                          puVar31 = (undefined8 *)CONCAT44(uStack_494,uStack_498);
                        }
                        auStack_4f8 = auVar46;
                        if ((puVar31 != (undefined8 *)0x0) && (*(char *)puVar31 != '\0')) {
                          lVar19 = lStack_580;
                          fVar37 = fVar39;
                          fVar40 = fVar39;
                          if (plVar21 == (longlong *)0x0) {
                            fVar45 = *(float *)(_DAT_181b2f2c0 + 0x3c38);
                          }
                          else {
                            fVar45 = *(float *)((longlong)plVar21 + 0x14);
                          }
                          do {
                            uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                            if ((fVar40 != 0.0) || (fVar37 != 0.0)) {
                              fStack_370 = fStack_548 + fVar40;
                              fStack_36c = fStack_544 + fVar37;
                              lVar17 = -1;
                              do {
                                lVar17 = lVar17 + 1;
                              } while (*(char *)((longlong)puVar31 + lVar17) != '\0');
                              fVar41 = fVar45;
                              if (puVar31 != (undefined8 *)((longlong)puVar31 + lVar17)) {
                                plVar38 = plVar21;
                                if (plVar21 == (longlong *)0x0) {
                                  plVar38 = *(longlong **)(*(longlong *)(lVar19 + 0x38) + 8);
                                }
                                if (fVar45 == 0.0) {
                                  fVar41 = *(float *)(*(longlong *)(lVar19 + 0x38) + 0x10);
                                }
                                if (*(longlong *)(plVar38[8] + 8) != *(longlong *)(lVar19 + 0x98)) {
                                  _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
                                }
                                uStack_148 = *(undefined4 *)(lVar19 + 0x88);
                                uStack_144 = *(undefined4 *)(lVar19 + 0x8c);
                                uStack_140 = *(undefined4 *)(lVar19 + 0x90);
                                uStack_13c = *(undefined4 *)(lVar19 + 0x94);
                                in_stack_fffffffffffffa50 = (longlong *****)&uStack_148;
                                in_stack_fffffffffffffa48 =
                                     (longlong *****)CONCAT44(uVar50,0xc8000000);
                                in_stack_fffffffffffffa58 = puVar31;
                                func_0x000180030c90(plVar38,lVar19,fVar41,&fStack_370,
                                                    in_stack_fffffffffffffa48,
                                                    in_stack_fffffffffffffa50,puVar31,
                                                    (undefined8 *)((longlong)puVar31 + lVar17),0,0);
                                lVar19 = lStack_580;
                              }
                            }
                            fVar37 = fVar37 + fVar6;
                          } while ((fVar37 <= fVar6) ||
                                  (fVar40 = fVar40 + fVar6, fVar37 = fVar39, fVar40 <= fVar6));
                          uVar13 = func_0x000180004f90(auStack_4f8);
                          uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                          fVar37 = fStackX_10;
                          if ((uVar13 & 0xff000000) != 0) {
                            lVar17 = -1;
                            do {
                              lVar17 = lVar17 + 1;
                            } while (*(char *)((longlong)puVar31 + lVar17) != '\0');
                            if (puVar31 != (undefined8 *)((longlong)puVar31 + lVar17)) {
                              if (plVar21 == (longlong *)0x0) {
                                plVar21 = *(longlong **)(*(longlong *)(lVar19 + 0x38) + 8);
                              }
                              if (fVar45 == 0.0) {
                                fVar45 = *(float *)(*(longlong *)(lVar19 + 0x38) + 0x10);
                              }
                              if (*(longlong *)(plVar21[8] + 8) != *(longlong *)(lVar19 + 0x98)) {
                                _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
                              }
                              uStack_138 = *(undefined4 *)(lVar19 + 0x88);
                              uStack_134 = *(undefined4 *)(lVar19 + 0x8c);
                              uStack_130 = *(undefined4 *)(lVar19 + 0x90);
                              uStack_12c = *(undefined4 *)(lVar19 + 0x94);
                              in_stack_fffffffffffffa50 = (longlong *****)&uStack_138;
                              in_stack_fffffffffffffa48 = (longlong *****)CONCAT44(uVar50,uVar13);
                              func_0x000180030c90(plVar21,lVar19,fVar45,&fStack_548,
                                                  in_stack_fffffffffffffa48,
                                                  in_stack_fffffffffffffa50,puVar31,
                                                  (undefined8 *)((longlong)puVar31 + lVar17),0,0);
                              fVar37 = fStackX_10;
                              in_stack_fffffffffffffa58 = puVar31;
                            }
                          }
                        }
                      }
                      recovered_180066e40(&uStack_498);
                      goto LAB_180083751;
                    }
                    fVar37 = (float)((uint)fVar37 & 0xfffffffe);
                    fStackX_8 = fVar37;
                    fStackX_10 = fVar37;
                    if (CONCAT44(uStack_2bc,uStack_2c0) < 0x10) goto LAB_180083286;
                    if ((CONCAT44(uStack_2bc,uStack_2c0) + 1 < 0x1000) ||
                       ((auStack_2d8._0_8_ - *(longlong *)(auStack_2d8._0_8_ + -8)) - 8U < 0x20)) {
                      func_0x000180127e40();
                      goto LAB_180083286;
                    }
                    _invoke_watson(0,0,0,0,0);
LAB_180084cc3:
                    _invoke_watson(0,0,0,0,0);
LAB_180084cd9:
                    _invoke_watson(0,0,0,0,0);
                    goto LAB_180084cef;
                  }
LAB_180083751:
                  uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                  pplVar22 = (longlong **)0x0;
                  if (DAT_181b2b4d8 != '\0') {
                    fVar39 = (float)func_0x0001801cb513();
                    uVar13 = (uint)fVar39;
                    pcVar35 = (char *)((longlong)&uStack_4e8 + 5);
                    if ((int)uVar13 < 0) {
                      uVar13 = -uVar13;
                      do {
                        pcVar36 = pcVar35;
                        pcVar35 = pcVar36 + -1;
                        *pcVar35 = (char)uVar13 + (char)((ulonglong)uVar13 / 10) * -10 + '0';
                        uVar13 = (uint)((ulonglong)uVar13 / 10);
                      } while (uVar13 != 0);
                      pcVar35 = pcVar36 + -2;
                      *pcVar35 = '-';
                    }
                    else {
                      do {
                        pcVar35 = pcVar35 + -1;
                        *pcVar35 = (char)uVar13 + (char)((ulonglong)uVar13 / 10) * -10 + '0';
                        uVar13 = (uint)((ulonglong)uVar13 / 10);
                      } while (uVar13 != 0);
                    }
                    recovered_180078780(auStack_2d8,pcVar35,(longlong)&uStack_4e8 + 5,&fStackX_8);
                    pauVar18 = (undefined (*) [16])recovered_180066ec0(auStack_2d8,&UNK_1819d8290,1)
                    ;
                    auStack_4b8 = *pauVar18;
                    auStack_4a8 = pauVar18[1];
                    *(undefined8 *)pauVar18[1] = 0;
                    *(undefined8 *)(pauVar18[1] + 8) = 0xf;
                    (*pauVar18)[0] = 0;
                    fStackX_8 = (float)((uint)fVar37 | 0x1c);
                    fStackX_10 = fStackX_8;
                    recovered_180066e40(auStack_2d8);
                    lVar19 = _DAT_181b2f2c0;
                    plVar21 = _DAT_181b4eff8;
                    if ((_DAT_181b4eff8 != (longlong *)0x0) ||
                       (plVar21 = *(longlong **)(_DAT_181b2f2c0 + 0x3c30),
                       ppppplVar27 = in_stack_fffffffffffffa50, plVar21 != (longlong *)0x0)) {
                      aplStack_558[0] = plVar21;
                      func_0x0001800149b0(plVar21);
                      func_0x000180022d70(lVar19 + 0x4888,aplStack_558);
                      func_0x0001800255e0(*(undefined8 *)(*(longlong *)(lVar19 + 0x3f10) + 0x298),
                                          *(undefined8 *)(plVar21[8] + 8));
                      ppppplVar27 = in_stack_fffffffffffffa50;
                    }
                    in_stack_fffffffffffffa50 = (longlong *****)auStack_4b8;
                    if (0xf < (ulonglong)auStack_4a8._8_8_) {
                      in_stack_fffffffffffffa50 = (longlong *****)auStack_4b8._0_8_;
                    }
                    if (in_stack_fffffffffffffa50 == (longlong *****)0x0) {
                      fVar41 = *(float *)(_DAT_181b2f2c0 + 0x3c38);
                      in_stack_fffffffffffffa50 = ppppplVar27;
                      fVar37 = 0.0;
                    }
                    else {
                      in_stack_fffffffffffffa58 = (undefined8 *)0x0;
                      func_0x000180030a70(*(undefined8 *)(_DAT_181b2f2c0 + 0x3c30),&fStack_438,
                                          *(float *)(_DAT_181b2f2c0 + 0x3c38),_DAT_181a03460,
                                          CONCAT44(uVar50,_DAT_181a0348c),in_stack_fffffffffffffa50,
                                          0);
                      fStack_438 = (float)(int)(fStack_438 + _DAT_181a03228);
                      fVar41 = fStack_434;
                      fVar37 = fStack_438;
                    }
                    if (plVar21 != (longlong *)0x0) {
                      func_0x000180014ae0();
                    }
                    recovered_180084f20(&pfStack_1e8,auStack_250,_DAT_181b2b52c,
                                        CONCAT44(fVar41,fVar37));
                    in_stack_fffffffffffffa48 = (longlong *****)auStack_4b8;
                    if (0xf < (ulonglong)auStack_4a8._8_8_) {
                      in_stack_fffffffffffffa48 = (longlong *****)auStack_4b8._0_8_;
                    }
                    recovered_180085090(aplStack_568,plVar21,auStack_250,auStack_328,
                                        in_stack_fffffffffffffa48);
                    if (0xf < (ulonglong)auStack_4a8._8_8_) {
                      if ((0xfff < auStack_4a8._8_8_ + 1) &&
                         (0x1f < (ulonglong)
                                 (auStack_4b8._0_8_ +
                                 (-8 - (longlong)*(longlong ****)(auStack_4b8._0_8_ + -8)))))
                      goto LAB_180084cc3;
                      func_0x000180127e40();
                    }
                    auStack_4a8 = _DAT_181a03530;
                    auVar46[15] = 0;
                    auVar46._0_15_ = auStack_4b8._1_15_;
                    auStack_4b8 = auVar46 << 8;
                  }
                  auVar48 = _DAT_181a03530;
                  if ((DAT_181b2b4ec != '\0') &&
                     ((pplVar28[0x11] != (longlong *)0x0 || (pplVar28[0xd] != (longlong *)0x0)))) {
                    lVar19 = recovered_180085590();
                    if (*(longlong *)(lVar19 + 0x10) == 0) {
                      recovered_180085a10(_DAT_181b2f350);
                    }
                    pauVar18 = (undefined (*) [16])(pplVar28 + 0xf);
                    auStack_3f0 = ZEXT816(0);
                    auStack_3e0 = ZEXT816(0);
                    pplVar32 = (longlong **)pplVar28[0x11];
                    if ((longlong *)0xf < pplVar28[0x12]) {
                      pauVar18 = *(undefined (**) [16])*pauVar18;
                    }
                    if ((longlong **)0x7fffffffffffffff < pplVar32) {
                      func_0x000180052a50();
                      pcVar2 = (code *)swi(3);
                      (*pcVar2)();
                      return;
                    }
                    if (pplVar32 < (longlong **)0x10) {
                      uVar29 = 0xf;
                      auStack_3e0._8_8_ = 0xf;
                      auStack_3e0._0_8_ = pplVar32;
                      puVar20 = *(undefined **)*pauVar18;
                      auStack_3f0 = *pauVar18;
                    }
                    else {
                      uVar29 = (ulonglong)pplVar32 | 0xf;
                      if (uVar29 < 0x8000000000000000) {
                        if (uVar29 < 0x16) {
                          uVar29 = 0x16;
                        }
                      }
                      else {
                        uVar29 = 0x7fffffffffffffff;
                      }
                      puVar20 = (undefined *)func_0x000180024110(uVar29 + 1);
                      auStack_3f0._0_8_ = puVar20;
                      auStack_3e0._8_8_ = uVar29;
                      auStack_3e0._0_8_ = pplVar32;
                      func_0x0001801ca88d(puVar20,pauVar18,(undefined *)((longlong)pplVar32 + 1));
                    }
                    if (pplVar32 == (longlong **)0x0) {
                      pauVar18 = (undefined (*) [16])recovered_180080590(auStack_108,pplVar28 + 0xb)
                      ;
                      if (&auStack_3f0 != pauVar18) {
                        if (0xf < uVar29) {
                          puVar25 = puVar20;
                          if ((0xfff < uVar29 + 1) &&
                             (puVar25 = *(undefined **)(puVar20 + -8),
                             (undefined *)0x1f < puVar20 + (-8 - (longlong)puVar25)))
                          goto LAB_180084cd9;
                          func_0x000180127e40(puVar25);
                        }
                        puVar20 = *(undefined **)*pauVar18;
                        auStack_3f0 = *pauVar18;
                        auStack_3e0 = pauVar18[1];
                        pplVar32 = auStack_3e0._0_8_;
                        *(undefined8 *)pauVar18[1] = 0;
                        *(undefined8 *)(pauVar18[1] + 8) = 0xf;
                        (*pauVar18)[0] = 0;
                        uVar29 = auStack_3e0._8_8_;
                      }
                      recovered_180066e40(auStack_108);
                      if (pplVar32 != (longlong **)0x0) goto LAB_180083df3;
LAB_180083fc7:
                      lVar19 = _DAT_181b2f2c0;
                      uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                      if (pplVar28[0xd] != (longlong *)0x0) {
                        plVar21 = _DAT_181b4eff8;
                        if ((_DAT_181b4eff8 != (longlong *)0x0) ||
                           (plVar21 = *(longlong **)(_DAT_181b2f2c0 + 0x3c30),
                           ppppplVar27 = in_stack_fffffffffffffa50, plVar21 != (longlong *)0x0)) {
                          aplStack_558[0] = plVar21;
                          func_0x0001800149b0(plVar21);
                          func_0x000180022d70(lVar19 + 0x4888,aplStack_558);
                          func_0x0001800255e0(*(undefined8 *)
                                               (*(longlong *)(lVar19 + 0x3f10) + 0x298),
                                              *(undefined8 *)(plVar21[8] + 8));
                          ppppplVar27 = in_stack_fffffffffffffa50;
                        }
                        in_stack_fffffffffffffa48 = (longlong *****)(pplVar28 + 0xb);
                        in_stack_fffffffffffffa50 = in_stack_fffffffffffffa48;
                        if ((longlong *)0xf < pplVar28[0xe]) {
                          in_stack_fffffffffffffa50 = (longlong *****)*in_stack_fffffffffffffa48;
                        }
                        if (in_stack_fffffffffffffa50 == (longlong *****)0x0) {
                          fVar41 = *(float *)(_DAT_181b2f2c0 + 0x3c38);
                          in_stack_fffffffffffffa50 = ppppplVar27;
                          fVar37 = 0.0;
                        }
                        else {
                          in_stack_fffffffffffffa58 = (undefined8 *)0x0;
                          func_0x000180030a70(*(undefined8 *)(_DAT_181b2f2c0 + 0x3c30),&fStack_470,
                                              *(float *)(_DAT_181b2f2c0 + 0x3c38),_DAT_181a03460,
                                              CONCAT44(uVar50,_DAT_181a0348c),
                                              in_stack_fffffffffffffa50,0);
                          fStack_470 = (float)(int)(fStack_470 + _DAT_181a03228);
                          fVar41 = fStack_46c;
                          fVar37 = fStack_470;
                        }
                        if (plVar21 != (longlong *)0x0) {
                          func_0x000180014ae0();
                        }
                        recovered_180084f20(&pfStack_1e8,auStack_248,_DAT_181b2b500,
                                            CONCAT44(fVar41,fVar37));
                        if ((longlong *)0xf < pplVar28[0xe]) {
                          in_stack_fffffffffffffa48 = (longlong *****)*in_stack_fffffffffffffa48;
                        }
                        recovered_180085090(aplStack_568,plVar21,auStack_248,auStack_3a8,
                                            in_stack_fffffffffffffa48);
                      }
                    }
                    else {
LAB_180083df3:
                      lVar19 = recovered_180085590();
                      if (*(longlong *)(lVar19 + 0x10) == 0) {
                        recovered_180085a10(_DAT_181b2f350);
                      }
                      plVar21 = (longlong *)recovered_180085590();
                      puVar25 = auStack_3f0;
                      if (0xf < uVar29) {
                        puVar25 = puVar20;
                      }
                      uVar34 = 0xcbf29ce484222325;
                      pplVar23 = pplVar22;
                      if (pplVar32 != (longlong **)0x0) {
                        do {
                          uVar34 = (uVar34 ^ (byte)puVar25[(longlong)pplVar23]) * 0x100000001b3;
                          pplVar23 = (longlong **)((longlong)pplVar23 + 1);
                        } while (pplVar23 < pplVar32);
                      }
                      aplStack_558[0] = plVar21;
                      lVar19 = recovered_180085cb0(plVar21,auStack_118,auStack_3f0,uVar34);
                      uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa50 >> 0x20);
                      lVar19 = *(longlong *)(lVar19 + 8);
                      if (((lVar19 == 0) || (lVar19 == plVar21[1])) ||
                         (lVar19 = *(longlong *)(lVar19 + 0x30), lVar19 == 0)) goto LAB_180083fc7;
                      fVar37 = _DAT_181a03334;
                      recovered_180084f20(&pfStack_1e8,&fStack_478,_DAT_181b2b500,
                                          CONCAT44(_DAT_181a03334,_DAT_181a03334));
                      lVar7 = lStack_580;
                      uStack_368 = 0x3f800000;
                      uStack_364 = 0x3f800000;
                      uStack_360 = 0;
                      fStack_358 = fStack_478 + fVar37;
                      fStack_354 = fStack_474 + fVar37;
                      lVar17 = *(longlong *)(lStack_580 + 0x98);
                      if (lVar19 != lVar17) {
                        func_0x0001800255e0(lStack_580,lVar19);
                      }
                      func_0x000180025660(lVar7,6,4);
                      in_stack_fffffffffffffa50 = (longlong *****)CONCAT44(uVar50,0xffffffff);
                      in_stack_fffffffffffffa48 = (longlong *****)&uStack_368;
                      func_0x0001800257a0(lVar7,&fStack_478,&fStack_358,&uStack_360,
                                          in_stack_fffffffffffffa48,in_stack_fffffffffffffa50);
                      if (lVar19 != lVar17) {
                        if (*(int *)(lVar7 + 0x68) < 1) {
                          _wassert(&UNK_180213518,&UNK_18020d8d0,0x758);
                        }
                        iVar14 = *(int *)(lVar7 + 0x68);
                        iVar12 = iVar14 + -1;
                        *(int *)(lVar7 + 0x68) = iVar12;
                        if (iVar12 == 0) {
                          *(undefined8 *)(lVar7 + 0x98) = 0;
                          func_0x000180025310(lVar7);
                        }
                        else {
                          *(undefined8 *)(lVar7 + 0x98) =
                               *(undefined8 *)
                                (*(longlong *)(lVar7 + 0x70) + -0x10 + (longlong)iVar14 * 8);
                          func_0x000180025310(lVar7);
                        }
                      }
                    }
                    if (0xf < uVar29) {
                      puVar25 = puVar20;
                      if ((0xfff < uVar29 + 1) &&
                         (puVar25 = *(undefined **)(puVar20 + -8),
                         (undefined *)0x1f < puVar20 + (-8 - (longlong)puVar25))) {
LAB_180084cef:
                        _invoke_watson(0,0,0,0,0);
                        pcVar2 = (code *)swi(3);
                        (*pcVar2)();
                        return;
                      }
                      func_0x000180127e40(puVar25);
                    }
                  }
                  uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                  pplVar32 = pplVar28 + 3;
                  if ((DAT_181b2b504 != '\0') &&
                     (uVar13 = *(uint *)(pplVar28 + 0x13), 0 < (int)uVar13)) {
                    pcVar35 = acStack_394 + 1;
                    do {
                      pcVar35 = pcVar35 + -1;
                      *pcVar35 = (char)uVar13 + (char)((ulonglong)uVar13 / 10) * -10 + '0';
                      uVar13 = (uint)((ulonglong)uVar13 / 10);
                    } while (uVar13 != 0);
                    recovered_180078780(appppuStack_298,pcVar35,acStack_394 + 1,&fStackX_8);
                    fVar37 = fStackX_10;
                    if (uStack_280 - lStack_288 < 3) {
                      in_stack_fffffffffffffa50 = (longlong *****)0x0;
                      uVar50 = 1;
                      pauVar18 = (undefined (*) [16])
                                 recovered_1800678e0(appppuStack_298,3,lStack_288,0,&UNK_1819d8294,3
                                                    );
                    }
                    else {
                      ppppuVar33 = appppuStack_298;
                      if (0xf < uStack_280) {
                        ppppuVar33 = appppuStack_298[0];
                      }
                      if ((&UNK_1819d8296 < ppppuVar33) ||
                         ((undefined *)(lStack_288 + (longlong)ppppuVar33) < &UNK_1819d8294)) {
                        pplVar23 = (longlong **)0x3;
                      }
                      else {
                        pplVar23 = pplVar22;
                        if (&UNK_1819d8294 < ppppuVar33) {
                          pplVar23 = (longlong **)((longlong)ppppuVar33 + -0x1819d8294);
                        }
                      }
                      lVar19 = lStack_288 + 1;
                      lStack_288 = lStack_288 + 3;
                      func_0x0001801ca893((undefined *)((longlong)ppppuVar33 + 3),ppppuVar33,lVar19)
                      ;
                      func_0x0001801ca88d(ppppuVar33,&UNK_1819d8294,pplVar23);
                      func_0x0001801ca88d((undefined *)((longlong)ppppuVar33 + (longlong)pplVar23),
                                          &UNK_1819d8297 + (longlong)pplVar23,3 - (longlong)pplVar23
                                         );
                      pauVar18 = (undefined (*) [16])appppuStack_298;
                    }
                    auStack_420 = ZEXT816(0);
                    auStack_410 = ZEXT816(0);
                    auStack_420 = *pauVar18;
                    auStack_410 = pauVar18[1];
                    *(undefined8 *)pauVar18[1] = 0;
                    *(undefined8 *)(pauVar18[1] + 8) = 0xf;
                    (*pauVar18)[0] = 0;
                    fStackX_8 = (float)((uint)fVar37 | 0xe0);
                    fStackX_10 = fStackX_8;
                    recovered_180066e40(appppuStack_298);
                    lVar19 = _DAT_181b2f2c0;
                    plVar21 = _DAT_181b4eff8;
                    if ((_DAT_181b4eff8 != (longlong *)0x0) ||
                       (plVar21 = *(longlong **)(_DAT_181b2f2c0 + 0x3c30),
                       ppppplVar27 = in_stack_fffffffffffffa50, plVar21 != (longlong *)0x0)) {
                      aplStack_558[0] = plVar21;
                      func_0x0001800149b0(plVar21);
                      func_0x000180022d70(lVar19 + 0x4888,aplStack_558);
                      func_0x0001800255e0(*(undefined8 *)(*(longlong *)(lVar19 + 0x3f10) + 0x298),
                                          *(undefined8 *)(plVar21[8] + 8));
                      ppppplVar27 = in_stack_fffffffffffffa50;
                    }
                    in_stack_fffffffffffffa50 = (longlong *****)auStack_420;
                    if (0xf < (ulonglong)auStack_410._8_8_) {
                      in_stack_fffffffffffffa50 = (longlong *****)auStack_420._0_8_;
                    }
                    if (in_stack_fffffffffffffa50 == (longlong *****)0x0) {
                      fVar41 = *(float *)(_DAT_181b2f2c0 + 0x3c38);
                      in_stack_fffffffffffffa50 = ppppplVar27;
                      fVar37 = 0.0;
                    }
                    else {
                      in_stack_fffffffffffffa58 = (undefined8 *)0x0;
                      func_0x000180030a70(*(undefined8 *)(_DAT_181b2f2c0 + 0x3c30),&fStack_468,
                                          *(float *)(_DAT_181b2f2c0 + 0x3c38),_DAT_181a03460,
                                          CONCAT44(uVar50,_DAT_181a0348c),in_stack_fffffffffffffa50,
                                          0);
                      fStack_468 = (float)(int)(fStack_468 + _DAT_181a03228);
                      fVar41 = fStack_464;
                      fVar37 = fStack_468;
                    }
                    if (plVar21 != (longlong *)0x0) {
                      func_0x000180014ae0();
                    }
                    recovered_180084f20(&pfStack_1e8,auStack_240,_DAT_181b2b518,
                                        CONCAT44(fVar41,fVar37));
                    in_stack_fffffffffffffa48 = (longlong *****)auStack_420;
                    if (0xf < (ulonglong)auStack_410._8_8_) {
                      in_stack_fffffffffffffa48 = (longlong *****)auStack_420._0_8_;
                    }
                    recovered_180085090(aplStack_568,plVar21,auStack_240,auStack_538,
                                        in_stack_fffffffffffffa48);
                    if ((ulonglong)auStack_410._8_8_ < 0x10) {
LAB_18008448b:
                      auStack_410 = auVar48;
                      auVar3[15] = 0;
                      auVar3._0_15_ = auStack_420._1_15_;
                      auStack_420 = auVar3 << 8;
                      goto LAB_18008449b;
                    }
                    if ((auStack_410._8_8_ + 1 < 0x1000) ||
                       ((ulonglong)
                        (auStack_420._0_8_ +
                        (-8 - (longlong)*(longlong ****)(auStack_420._0_8_ + -8))) < 0x20)) {
                      func_0x000180127e40();
                      goto LAB_18008448b;
                    }
                    _invoke_watson(0,0,0,0,0);
LAB_180084d1b:
                    _invoke_watson(0,0,0,0,0);
LAB_180084d31:
                    in_stack_fffffffffffffa48 = (longlong *****)0x0;
                    _invoke_watson(0,0,0,0,0);
                    goto LAB_180084d47;
                  }
LAB_18008449b:
                  auVar46 = auStack_400;
                  if (DAT_181b2b54c != '\0') {
                    uVar29 = (ulonglong)*(ushort *)((longlong)pplVar28 + 0x2a);
                    cVar10 = recovered_18007ea60(uVar29);
                    auVar46 = auStack_400;
                    if (cVar10 != '\0') {
                      recovered_18007eac0(appppplStack_278,uVar29 & 0xffff);
                      lVar19 = _DAT_181b2f2c0;
                      uVar50 = (undefined4)((ulonglong)in_stack_fffffffffffffa48 >> 0x20);
                      auVar46 = auStack_400;
                      if (lStack_268 != 0) {
                        plVar21 = _DAT_181b4eff8;
                        if ((_DAT_181b4eff8 != (longlong *)0x0) ||
                           (plVar21 = *(longlong **)(_DAT_181b2f2c0 + 0x3c30),
                           ppppplVar27 = in_stack_fffffffffffffa50, plVar21 != (longlong *)0x0)) {
                          aplStack_558[0] = plVar21;
                          func_0x0001800149b0(plVar21);
                          func_0x000180022d70(lVar19 + 0x4888,aplStack_558);
                          func_0x0001800255e0(*(undefined8 *)
                                               (*(longlong *)(lVar19 + 0x3f10) + 0x298),
                                              *(undefined8 *)(plVar21[8] + 8));
                          ppppplVar27 = in_stack_fffffffffffffa50;
                        }
                        in_stack_fffffffffffffa50 = (longlong *****)appppplStack_278;
                        if (0xf < uStack_260) {
                          in_stack_fffffffffffffa50 = appppplStack_278[0];
                        }
                        if (in_stack_fffffffffffffa50 == (longlong *****)0x0) {
                          fVar41 = *(float *)(_DAT_181b2f2c0 + 0x3c38);
                          in_stack_fffffffffffffa50 = ppppplVar27;
                          fVar37 = 0.0;
                        }
                        else {
                          in_stack_fffffffffffffa58 = (undefined8 *)0x0;
                          func_0x000180030a70(*(undefined8 *)(_DAT_181b2f2c0 + 0x3c30),&fStack_460,
                                              *(float *)(_DAT_181b2f2c0 + 0x3c38),_DAT_181a03460,
                                              CONCAT44(uVar50,_DAT_181a0348c),
                                              in_stack_fffffffffffffa50,0);
                          fStack_460 = (float)(int)(fStack_460 + _DAT_181a03228);
                          fVar41 = fStack_45c;
                          fVar37 = fStack_460;
                        }
                        if (plVar21 != (longlong *)0x0) {
                          func_0x000180014ae0();
                        }
                        recovered_180084f20(&pfStack_1e8,auStack_238,_DAT_181b2b534,
                                            CONCAT44(fVar41,fVar37));
                        auVar46 = auStack_400;
                        in_stack_fffffffffffffa48 = (longlong *****)appppplStack_278;
                        if (0xf < uStack_260) {
                          in_stack_fffffffffffffa48 = appppplStack_278[0];
                        }
                        auStack_538 = auStack_400;
                        recovered_180085090(aplStack_568,plVar21,auStack_238,auStack_538,
                                            in_stack_fffffffffffffa48);
                      }
                      recovered_180066e40(appppplStack_278);
                    }
                  }
                  if (DAT_181b2b54d != '\0') {
                    uVar29 = (ulonglong)*(ushort *)((longlong)pplVar28 + 0x2a);
                    cVar10 = recovered_18007ea60(uVar29);
                    if ((((cVar10 != '\0') &&
                         (iVar14 = func_0x00018007e9d0(uVar29 & 0xffff), -1 < iVar14)) &&
                        (uVar34 = (ulonglong)iVar14,
                        uVar34 < (ulonglong)((_DAT_181b2f550 - _DAT_181b2f548) / 0x48))) &&
                       ((*(char *)(_DAT_181b2f548 + 0x42 + uVar34 * 0x48) == '\0' &&
                        (*(longlong *)(_DAT_181b2f548 + 0x30 + uVar34 * 0x48) != 0)))) {
                      recovered_18007eb60(&uStack_4d8,uVar29 & 0xffff);
                      recovered_18007eac0(appppuStack_208,*(undefined2 *)((longlong)pplVar28 + 0x2a)
                                         );
                      recovered_18007fe70(appppuStack_188,appppuStack_208);
                      uVar8 = uStack_178;
                      uVar34 = uStack_1f0;
                      uVar29 = uStack_1f8;
                      ppppuVar33 = appppuStack_208[0];
                      ppppuVar26 = appppuStack_208;
                      if (0xf < uStack_1f0) {
                        ppppuVar26 = appppuStack_208[0];
                      }
                      ppppuVar24 = appppuStack_188;
                      if (0xf < uStack_170) {
                        ppppuVar24 = appppuStack_188[0];
                      }
                      if ((uStack_178 != uStack_1f8) ||
                         ((uStack_178 != 0 &&
                          (iVar14 = func_0x0001801ca8a5(ppppuVar24,ppppuVar26,uStack_178),
                          iVar14 != 0)))) {
                        auStack_3d0 = ZEXT816(0);
                        uStack_3c0 = 0;
                        uStack_3b8 = 0;
                        if (uVar29 < uVar8) {
                          recovered_180067b60();
LAB_180084f07:
                          func_0x000180052a50();
                          pcVar2 = (code *)swi(3);
                          (*pcVar2)();
                          return;
                        }
                        lVar17 = uVar29 - uVar8;
                        lVar19 = -1;
                        if (lVar17 != -1) {
                          lVar19 = lVar17;
                        }
                        ppppuVar26 = appppuStack_208;
                        if (0xf < uVar34) {
                          ppppuVar26 = ppppuVar33;
                        }
                        recovered_180066cc0(auStack_3d0,(longlong)ppppuVar26 + uVar8,lVar19);
                        fVar37 = fStackX_10;
                        fStackX_8 = (float)((uint)fStackX_10 | 0x100);
                        ppppplVar27 = (longlong *****)&uStack_4d8;
                        if (0xf < (ulonglong)auStack_4c8._8_8_) {
                          ppppplVar27 = (longlong *****)CONCAT44(uStack_4d4,uStack_4d8);
                        }
                        fStackX_10 = fStackX_8;
                        if ((uStack_3c0 <= (ulonglong)auStack_4c8._0_8_) &&
                           ((pplVar23 = pplVar22, uStack_3c0 == 0 ||
                            ((lVar17 = auStack_4c8._0_8_ + (longlong)ppppplVar27,
                             lVar19 = func_0x0001801278a0(ppppplVar27,lVar17), lVar19 != lVar17 &&
                             (pplVar23 = (longlong **)(lVar19 - (longlong)ppppplVar27),
                             (longlong **)(lVar19 - (longlong)ppppplVar27) !=
                             (longlong **)0xffffffffffffffff)))))) {
                          _auStack_228 = ZEXT816(0);
                          auStack_218 = ZEXT816(0);
                          if ((ulonglong)auStack_4c8._0_8_ < pplVar23) {
                            pplVar23 = (longlong **)auStack_4c8._0_8_;
                          }
                          ppppplVar27 = (longlong *****)&uStack_4d8;
                          if (0xf < (ulonglong)auStack_4c8._8_8_) {
                            ppppplVar27 = (longlong *****)CONCAT44(uStack_4d4,uStack_4d8);
                          }
                          recovered_180066cc0(auStack_228,ppppplVar27,pplVar23);
                          fStackX_8 = (float)((uint)fVar37 | 0x300);
                          fStackX_10 = fStackX_8;
                          if (0xf < (ulonglong)auStack_4c8._8_8_) {
                            if ((0xfff < auStack_4c8._8_8_ + 1) &&
                               (0x1f < (CONCAT44(uStack_4d4,uStack_4d8) -
                                       *(longlong *)(CONCAT44(uStack_4d4,uStack_4d8) + -8)) - 8U))
                            goto LAB_180084d1b;
                            func_0x000180127e40();
                          }
                          uStack_4d8 = auStack_228;
                          uStack_4d4 = uStack_224;
                          uStack_4d0 = uStack_220;
                          uStack_4cc = uStack_21c;
                          auStack_4c8 = auStack_218;
                          auStack_218 = auVar48;
                          auVar4[15] = 0;
                          auVar4._0_15_ = stack0xfffffffffffffdd9;
                          _auStack_228 = auVar4 << 8;
                          recovered_180066e40(auStack_228);
                        }
                        if (0xf < uStack_3b8) {
                          if ((0xfff < uStack_3b8 + 1) &&
                             (0x1f < (auStack_3d0._0_8_ - *(longlong *)(auStack_3d0._0_8_ + -8)) -
                                     8U)) goto LAB_180084d31;
                          func_0x000180127e40();
                        }
                        uStack_3c0 = 0;
                        uStack_3b8 = 0xf;
                        auVar5[15] = 0;
                        auVar5._0_15_ = auStack_3d0._1_15_;
                        auStack_3d0 = auVar5 << 8;
                      }
                      lVar19 = _DAT_181b4f010;
                      if (((_DAT_181b4f010 != 0) ||
                          (lVar19 = *(longlong *)(_DAT_181b2f2c0 + 0x3c30), lVar19 != 0)) &&
                         (auStack_4c8._0_8_ != 0)) {
                        in_stack_fffffffffffffa50 = (longlong *****)&uStack_4d8;
                        if (0xf < (ulonglong)auStack_4c8._8_8_) {
                          in_stack_fffffffffffffa50 =
                               (longlong *****)CONCAT44(uStack_4d4,uStack_4d8);
                        }
                        in_stack_fffffffffffffa58 = (undefined8 *)0x0;
                        func_0x000180030a70(lVar19,&uStack_230,*(undefined4 *)(lVar19 + 0x14),
                                            _DAT_181a03460,
                                            (ulonglong)in_stack_fffffffffffffa48 &
                                            0xffffffff00000000,in_stack_fffffffffffffa50,0);
                        recovered_180084f20(&pfStack_1e8,auStack_258,_DAT_181b2b530,uStack_230);
                        in_stack_fffffffffffffa48 = (longlong *****)&uStack_4d8;
                        if (0xf < (ulonglong)auStack_4c8._8_8_) {
                          in_stack_fffffffffffffa48 =
                               (longlong *****)CONCAT44(uStack_4d4,uStack_4d8);
                        }
                        auStack_538 = auVar46;
                        recovered_180085090(aplStack_568,lVar19,auStack_258,auStack_538,
                                            in_stack_fffffffffffffa48);
                      }
                      recovered_180066e40(appppuStack_188);
                      recovered_180066e40(appppuStack_208);
                      recovered_180066e40(&uStack_4d8);
                    }
                  }
                  pplVar22 = pplStack_570;
                  fVar45 = _DAT_181a031bc;
                  fVar37 = fStackX_10;
                  if (DAT_181b2b538 != '\0') {
                    auStack_538._8_8_ = &iStack_578;
                    auStack_538._0_8_ = &iStack_574;
                    plStack_528 = &lStack_580;
                    puStack_520 = auStack_430;
                    recovered_180085390(auStack_538,pplVar28 + 0x14,(longlong)pplVar28 + 0xac);
                    recovered_180085390(auStack_538,(longlong)pplVar28 + 0xac,pplVar28 + 0x23);
                    recovered_180085390(auStack_538,(longlong)pplVar28 + 0xac,
                                        (longlong)pplVar28 + 0xc4);
                    recovered_180085390(auStack_538,(longlong)pplVar28 + 0xc4,
                                        (longlong)pplVar28 + 0xdc);
                    recovered_180085390(auStack_538,(longlong)pplVar28 + 0xdc,
                                        (longlong)pplVar28 + 0xf4);
                    recovered_180085390(auStack_538,(longlong)pplVar28 + 0xac,pplVar28 + 0x17);
                    recovered_180085390(auStack_538,pplVar28 + 0x17,pplVar28 + 0x1a);
                    recovered_180085390(auStack_538,pplVar28 + 0x1a,pplVar28 + 0x1d);
                    recovered_180085390(auStack_538,pplVar28 + 0x23,(longlong)pplVar28 + 0x124);
                    recovered_180085390(auStack_538,(longlong)pplVar28 + 0x124,
                                        (longlong)pplVar28 + 0x13c);
                    recovered_180085390(auStack_538,(longlong)pplVar28 + 0x124,pplVar28 + 0x26);
                    recovered_180085390(auStack_538,(longlong)pplVar28 + 0x13c,pplVar28 + 0x29);
                    recovered_180085390(auStack_538,pplVar28 + 0x26,(longlong)pplVar28 + 0x154);
                    pplVar22 = pplStack_570;
                    fVar45 = _DAT_181a031bc;
                    fVar37 = fStackX_10;
                  }
                }
              }
            }
          }
          pplVar28 = (longlong **)*pplVar28;
        } while (pplVar28 != pplVar22);
      }
      auVar48 = ZEXT416(_DAT_181a03460);
      pplVar22 = (longlong **)0x0;
      if ((DAT_181b2b46e != '\0') &&
         (pplVar28 = (longlong **)*_DAT_181b2be38, pplVar32 = _DAT_181b2be38,
         fVar41 = _DAT_181a0331c, pplVar28 != _DAT_181b2be38)) {
        do {
          if (((((*(char *)((longlong)pplVar28 + 0x19) != '\0') &&
                (*(char *)((longlong)pplVar28 + 0x1a) == '\0')) &&
               ((DAT_181b2bedc != '\0' || (*(char *)((longlong)pplVar28 + 0x1c) != '\0')))) &&
              ((DAT_181b2b565 == '\0' ||
               (cVar10 = recovered_180080860(pplVar28 + 3), cVar10 == '\0')))) &&
             ((DAT_181b2b406 == '\0' || (*(char *)((longlong)pplVar28 + 0x1b) == '\0')))) {
            fVar37 = _DAT_181b2beb0 - SUB84(pplVar28[0x14],0);
            fVar39 = _DAT_181b2beb4 - (float)((ulonglong)pplVar28[0x14] >> 0x20);
            fVar37 = fVar39 * fVar39 + fVar37 * fVar37 +
                     (_DAT_181b2beb8 - *(float *)(pplVar28 + 0x15)) *
                     (_DAT_181b2beb8 - *(float *)(pplVar28 + 0x15));
            if (fVar37 < 0.0) {
LAB_180084d47:
              uVar42 = func_0x0001801cb525();
              auVar47._8_4_ = (int)extraout_XMM0_Qb;
              auVar47._0_8_ = uVar42;
              auVar47._12_4_ = (int)((ulonglong)extraout_XMM0_Qb >> 0x20);
            }
            else {
              auVar47 = ZEXT416((uint)SQRT(fVar37));
            }
            if ((auVar47._0_4_ < auVar48._0_4_) && (auVar47._0_4_ < fVar41)) {
              in_stack_fffffffffffffa48 =
                   (longlong *****)
                   CONCAT44((int)((ulonglong)in_stack_fffffffffffffa48 >> 0x20),iStack_578);
              recovered_180067e80(&fStackX_8,&DAT_181b2be70,pplVar28 + 0x14,iStack_574,
                                  in_stack_fffffffffffffa48);
              if ((fVar6 <= fStackX_8) && (fVar6 <= fStackX_c)) {
                pplVar22 = pplVar28 + 3;
                auVar48 = auVar47;
              }
            }
          }
          pplVar28 = (longlong **)*pplVar28;
        } while (pplVar28 != pplVar32);
        if (pplVar22 != (longlong **)0x0) {
          uVar42 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffa48 >> 0x20),iStack_578);
          iVar14 = iStack_574;
          iVar12 = iStack_578;
          recovered_180067e80(&fStackX_8,&DAT_181b2be70,pplVar22 + 0x11,iStack_574,uVar42);
          uVar50 = (undefined4)((ulonglong)uVar42 >> 0x20);
          if ((fVar6 <= fStackX_8) && (fVar6 <= fStackX_c)) {
            fStackX_10 = (float)iVar14 * fVar45;
            fStackX_14 = (float)iVar12 * fVar45;
            auStack_430._0_4_ = _DAT_181b2b488;
            auStack_430._4_4_ = uRam0000000181b2b48c;
            uStack_428 = uRam0000000181b2b490;
            uStack_424 = uRam0000000181b2b494;
            if (*(char *)((longlong)pplVar22 + 3) != '\0') {
              auStack_430._0_4_ = _DAT_181b2b568;
              auStack_430._4_4_ = _DAT_181b2b56c;
              uStack_428 = _DAT_181b2b570;
              uStack_424 = _DAT_181b2b574;
            }
            uVar15 = func_0x000180004f90(auStack_430);
            func_0x000180027b00(lStack_580,&fStackX_10,&fStackX_8,uVar15,CONCAT44(uVar50,fVar6));
          }
        }
      }
      if ((DAT_181b2b581 != '\0') && (DAT_181b2bc70 == '\0')) {
        recovered_18006fb50();
      }
    }
  }
  return;
}

