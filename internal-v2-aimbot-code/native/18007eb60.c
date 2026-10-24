/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined (*) [16] recovered_18007eb60(undefined (*param_1) [16],undefined2 param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  code *pcVar3;
  int iVar4;
  longlong lVar5;
  undefined *puVar6;
  undefined (*pauVar7) [16];
  longlong lVar8;
  longlong lVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined uStackX_18;
  undefined auStack_58 [16];
  undefined auStack_48 [16];
  undefined auStack_38 [16];
  ulonglong uStack_28;
  
  iVar4 = func_0x00018007e9d0(param_2);
  if ((-1 < iVar4) &&
     ((ulonglong)(longlong)iVar4 < (ulonglong)((_DAT_181b2f550 - _DAT_181b2f548) / 0x48))) {
    lVar8 = (longlong)iVar4 * 0x48;
    if (*(char *)(lVar8 + 0x42 + _DAT_181b2f548) != '\0') {
      *param_1 = ZEXT816(0);
      *(undefined8 *)param_1[1] = 0;
      *(undefined8 *)(param_1[1] + 8) = 0xf;
      (*param_1)[0] = 0;
      return param_1;
    }
    puVar10 = (undefined8 *)(_DAT_181b2f548 + lVar8);
    if (*(longlong *)(lVar8 + 0x30 + _DAT_181b2f548) != 0) {
      if (*(char *)(lVar8 + 0x41 + _DAT_181b2f548) == '\0') {
        recovered_180080190(param_1,puVar10 + 4);
        return param_1;
      }
      recovered_18007fe70(auStack_38,puVar10);
      puVar10 = (undefined8 *)(_DAT_181b2f548 + lVar8);
      auStack_58 = ZEXT816(0);
      auStack_48 = ZEXT816(0);
      if ((ulonglong)puVar10[2] < uStack_28) {
        recovered_180067b60();
      }
      else {
        lVar5 = puVar10[2] - uStack_28;
        lVar9 = -1;
        if (lVar5 != -1) {
          lVar9 = lVar5;
        }
        if (0xf < (ulonglong)puVar10[3]) {
          puVar10 = (undefined8 *)*puVar10;
        }
        recovered_180066cc0(auStack_58,uStack_28 + (longlong)puVar10,lVar9);
        puVar10 = (undefined8 *)(_DAT_181b2f548 + 0x20 + lVar8);
        if ((ulonglong)auStack_48._0_8_ <= 0x7fffffffffffffff - puVar10[2]) {
          puVar11 = puVar10;
          if (0xf < (ulonglong)puVar10[3]) {
            puVar11 = (undefined8 *)*puVar10;
          }
          puVar6 = auStack_58;
          if (0xf < (ulonglong)auStack_48._8_8_) {
            puVar6 = (undefined *)auStack_58._0_8_;
          }
          recovered_180067040(param_1,uStackX_18,puVar10,puVar11,puVar10[2],puVar6,auStack_48._0_8_)
          ;
          if (0xf < (ulonglong)auStack_48._8_8_) {
            if ((0xfff < auStack_48._8_8_ + 1) &&
               (0x1f < (auStack_58._0_8_ - *(longlong *)(auStack_58._0_8_ + -8)) - 8U)) {
              _invoke_watson(0,0,0,0,0);
              pcVar3 = (code *)swi(3);
              pauVar7 = (undefined (*) [16])(*pcVar3)();
              return pauVar7;
            }
            func_0x000180127e40();
          }
          recovered_180066e40(auStack_38);
          return param_1;
        }
      }
      func_0x000180052a50();
      pcVar3 = (code *)swi(3);
      pauVar7 = (undefined (*) [16])(*pcVar3)();
      return pauVar7;
    }
    uVar2 = puVar10[2];
    if (uVar2 != 0) {
      puVar11 = puVar10;
      if (0xf < (ulonglong)puVar10[3]) {
        puVar11 = (undefined8 *)*puVar10;
      }
      if (((uVar2 < 3) ||
          (lVar8 = func_0x0001801278a0(puVar11,(longlong)puVar11 + uVar2,&UNK_1819d7d28,3),
          lVar8 == (longlong)puVar11 + uVar2)) || (lVar8 - (longlong)puVar11 == -1)) {
        puVar11 = puVar10;
        if (0xf < (ulonglong)puVar10[3]) {
          puVar11 = (undefined8 *)*puVar10;
        }
        if ((((ulonglong)puVar10[2] < 5) ||
            (lVar8 = puVar10[2] + (longlong)puVar11,
            lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d8140,5), lVar9 == lVar8)) ||
           (lVar9 - (longlong)puVar11 == -1)) {
          puVar11 = puVar10;
          if (0xf < (ulonglong)puVar10[3]) {
            puVar11 = (undefined8 *)*puVar10;
          }
          if ((((ulonglong)puVar10[2] < 3) ||
              (lVar8 = puVar10[2] + (longlong)puVar11,
              lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d8148,3), lVar9 == lVar8)) ||
             (lVar9 - (longlong)puVar11 == -1)) {
            puVar11 = puVar10;
            if (0xf < (ulonglong)puVar10[3]) {
              puVar11 = (undefined8 *)*puVar10;
            }
            if ((((ulonglong)puVar10[2] < 3) ||
                (lVar8 = puVar10[2] + (longlong)puVar11,
                lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d7d80,3), lVar9 == lVar8)) ||
               (lVar9 - (longlong)puVar11 == -1)) {
              puVar11 = puVar10;
              if (0xf < (ulonglong)puVar10[3]) {
                puVar11 = (undefined8 *)*puVar10;
              }
              if ((((ulonglong)puVar10[2] < 6) ||
                  (lVar8 = puVar10[2] + (longlong)puVar11,
                  lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d814c,6), lVar9 == lVar8)) ||
                 (lVar9 - (longlong)puVar11 == -1)) {
                puVar11 = puVar10;
                if (0xf < (ulonglong)puVar10[3]) {
                  puVar11 = (undefined8 *)*puVar10;
                }
                if ((((ulonglong)puVar10[2] < 3) ||
                    (lVar8 = puVar10[2] + (longlong)puVar11,
                    lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d7b48,3), lVar9 == lVar8)) ||
                   (lVar9 - (longlong)puVar11 == -1)) {
                  puVar11 = puVar10;
                  if (0xf < (ulonglong)puVar10[3]) {
                    puVar11 = (undefined8 *)*puVar10;
                  }
                  if ((((ulonglong)puVar10[2] < 3) ||
                      (lVar8 = puVar10[2] + (longlong)puVar11,
                      lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d8154,3), lVar9 == lVar8))
                     || (lVar9 - (longlong)puVar11 == -1)) {
                    puVar11 = puVar10;
                    if (0xf < (ulonglong)puVar10[3]) {
                      puVar11 = (undefined8 *)*puVar10;
                    }
                    if ((((ulonglong)puVar10[2] < 10) ||
                        (lVar8 = puVar10[2] + (longlong)puVar11,
                        lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d7ef8,10), lVar9 == lVar8
                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                      puVar11 = puVar10;
                      if (0xf < (ulonglong)puVar10[3]) {
                        puVar11 = (undefined8 *)*puVar10;
                      }
                      if ((((ulonglong)puVar10[2] < 5) ||
                          (lVar8 = puVar10[2] + (longlong)puVar11,
                          lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d7c8c,5),
                          lVar9 == lVar8)) || (lVar9 - (longlong)puVar11 == -1)) {
                        puVar11 = puVar10;
                        if (0xf < (ulonglong)puVar10[3]) {
                          puVar11 = (undefined8 *)*puVar10;
                        }
                        if ((((ulonglong)puVar10[2] < 4) ||
                            (lVar8 = puVar10[2] + (longlong)puVar11,
                            lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d8158,4),
                            lVar9 == lVar8)) || (lVar9 - (longlong)puVar11 == -1)) {
                          puVar11 = puVar10;
                          if (0xf < (ulonglong)puVar10[3]) {
                            puVar11 = (undefined8 *)*puVar10;
                          }
                          if ((((ulonglong)puVar10[2] < 5) ||
                              (lVar8 = puVar10[2] + (longlong)puVar11,
                              lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d7cc8,5),
                              lVar9 == lVar8)) || (lVar9 - (longlong)puVar11 == -1)) {
                            puVar11 = puVar10;
                            if (0xf < (ulonglong)puVar10[3]) {
                              puVar11 = (undefined8 *)*puVar10;
                            }
                            if ((((ulonglong)puVar10[2] < 3) ||
                                (lVar8 = puVar10[2] + (longlong)puVar11,
                                lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d8160,3),
                                lVar9 == lVar8)) || (lVar9 - (longlong)puVar11 == -1)) {
                              puVar11 = puVar10;
                              if (0xf < (ulonglong)puVar10[3]) {
                                puVar11 = (undefined8 *)*puVar10;
                              }
                              if ((((ulonglong)puVar10[2] < 7) ||
                                  (lVar8 = puVar10[2] + (longlong)puVar11,
                                  lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d8168,7),
                                  lVar9 == lVar8)) || (lVar9 - (longlong)puVar11 == -1)) {
                                puVar11 = puVar10;
                                if (0xf < (ulonglong)puVar10[3]) {
                                  puVar11 = (undefined8 *)*puVar10;
                                }
                                if ((((ulonglong)puVar10[2] < 6) ||
                                    (lVar8 = puVar10[2] + (longlong)puVar11,
                                    lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d8170,6),
                                    lVar9 == lVar8)) || (lVar9 - (longlong)puVar11 == -1)) {
                                  puVar11 = puVar10;
                                  if (0xf < (ulonglong)puVar10[3]) {
                                    puVar11 = (undefined8 *)*puVar10;
                                  }
                                  if ((((ulonglong)puVar10[2] < 0xd) ||
                                      (lVar8 = puVar10[2] + (longlong)puVar11,
                                      lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d7cf0,0xd),
                                      lVar9 == lVar8)) || (lVar9 - (longlong)puVar11 == -1)) {
                                    puVar11 = puVar10;
                                    if (0xf < (ulonglong)puVar10[3]) {
                                      puVar11 = (undefined8 *)*puVar10;
                                    }
                                    if ((((ulonglong)puVar10[2] < 4) ||
                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d79f0,4),
                                        lVar9 == lVar8)) || (lVar9 - (longlong)puVar11 == -1)) {
                                      puVar11 = puVar10;
                                      if (0xf < (ulonglong)puVar10[3]) {
                                        puVar11 = (undefined8 *)*puVar10;
                                      }
                                      if ((((ulonglong)puVar10[2] < 3) ||
                                          (lVar8 = puVar10[2] + (longlong)puVar11,
                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d7bc0,3
                                                                     ), lVar9 == lVar8)) ||
                                         (lVar9 - (longlong)puVar11 == -1)) {
                                        puVar11 = puVar10;
                                        if (0xf < (ulonglong)puVar10[3]) {
                                          puVar11 = (undefined8 *)*puVar10;
                                        }
                                        if ((((ulonglong)puVar10[2] < 3) ||
                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                            lVar9 = func_0x0001801278a0(puVar11,lVar8,&UNK_1819d7bc8
                                                                        ,3), lVar9 == lVar8)) ||
                                           (lVar9 - (longlong)puVar11 == -1)) {
                                          puVar11 = puVar10;
                                          if (0xf < (ulonglong)puVar10[3]) {
                                            puVar11 = (undefined8 *)*puVar10;
                                          }
                                          if ((((ulonglong)puVar10[2] < 4) ||
                                              (lVar8 = puVar10[2] + (longlong)puVar11,
                                              lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                          &UNK_1819d7c08,4),
                                              lVar9 == lVar8)) || (lVar9 - (longlong)puVar11 == -1))
                                          {
                                            puVar11 = puVar10;
                                            if (0xf < (ulonglong)puVar10[3]) {
                                              puVar11 = (undefined8 *)*puVar10;
                                            }
                                            if ((((ulonglong)puVar10[2] < 8) ||
                                                (lVar8 = puVar10[2] + (longlong)puVar11,
                                                lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                            &UNK_1819d7c28,8),
                                                lVar9 == lVar8)) ||
                                               (lVar9 - (longlong)puVar11 == -1)) {
                                              puVar11 = puVar10;
                                              if (0xf < (ulonglong)puVar10[3]) {
                                                puVar11 = (undefined8 *)*puVar10;
                                              }
                                              if ((((ulonglong)puVar10[2] < 3) ||
                                                  (lVar8 = puVar10[2] + (longlong)puVar11,
                                                  lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                              &UNK_1819d7c14,3),
                                                  lVar9 == lVar8)) ||
                                                 (lVar9 - (longlong)puVar11 == -1)) {
                                                puVar11 = puVar10;
                                                if (0xf < (ulonglong)puVar10[3]) {
                                                  puVar11 = (undefined8 *)*puVar10;
                                                }
                                                if ((((ulonglong)puVar10[2] < 6) ||
                                                    (lVar8 = puVar10[2] + (longlong)puVar11,
                                                    lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                &UNK_1819d7c38,6),
                                                    lVar9 == lVar8)) ||
                                                   (lVar9 - (longlong)puVar11 == -1)) {
                                                  puVar11 = puVar10;
                                                  if (0xf < (ulonglong)puVar10[3]) {
                                                    puVar11 = (undefined8 *)*puVar10;
                                                  }
                                                  if ((((ulonglong)puVar10[2] < 5) ||
                                                      (lVar8 = puVar10[2] + (longlong)puVar11,
                                                      lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                  &UNK_1819d7c5c,5),
                                                      lVar9 == lVar8)) ||
                                                     (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 3) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d7be8,3
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 4) ||
                                                          (lVar8 = (longlong)puVar11 + puVar10[2],
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d7b80
                                                                                      ,4),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 3) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d7b94,3), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 4) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d7bb8,4
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 7) ||
                                                          (lVar8 = puVar10[2] + (longlong)puVar11,
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d7ec0
                                                                                      ,7),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 7) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d7e48,7), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 4) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d8178,4
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 3) ||
                                                          (lVar8 = (longlong)puVar11 + puVar10[2],
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d7e90
                                                                                      ,3),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 3) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d8180,3), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 3) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d8184,3
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 3) ||
                                                          (lVar8 = puVar10[2] + (longlong)puVar11,
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d8188
                                                                                      ,3),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 8) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d8190,8), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 7) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d81a0,7
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 3) ||
                                                          (lVar8 = puVar10[2] + (longlong)puVar11,
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d7e08
                                                                                      ,3),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 6) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d7e10,6), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 7) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d81a8,7
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 6) ||
                                                          (lVar8 = puVar10[2] + (longlong)puVar11,
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d7e24
                                                                                      ,6),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 6) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d7e2c,6), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 3) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d7e1c,3
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 4) ||
                                                          (lVar8 = puVar10[2] + (longlong)puVar11,
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d81b0
                                                                                      ,4),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 9) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d81b8,9), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 5) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d81c4,5
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 3) ||
                                                          (lVar8 = puVar10[2] + (longlong)puVar11,
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d80b4
                                                                                      ,3),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 5) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d81cc,5), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 5) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d81d4,5
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 5) ||
                                                          (lVar8 = puVar10[2] + (longlong)puVar11,
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d81dc
                                                                                      ,5),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 7) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d7f58,7), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 8) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d7f38,8
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar11 = puVar10;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar11 = (undefined8 *)*puVar10;
                                                      }
                                                      if ((((ulonglong)puVar10[2] < 3) ||
                                                          (lVar8 = puVar10[2] + (longlong)puVar11,
                                                          lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                      &UNK_1819d80b8
                                                                                      ,3),
                                                          lVar9 == lVar8)) ||
                                                         (lVar9 - (longlong)puVar11 == -1)) {
                                                        puVar11 = puVar10;
                                                        if (0xf < (ulonglong)puVar10[3]) {
                                                          puVar11 = (undefined8 *)*puVar10;
                                                        }
                                                        if ((((ulonglong)puVar10[2] < 3) ||
                                                            (lVar8 = puVar10[2] + (longlong)puVar11,
                                                            lVar9 = func_0x0001801278a0(puVar11,
                                                  lVar8,&UNK_1819d7b40,3), lVar9 == lVar8)) ||
                                                  (lVar9 - (longlong)puVar11 == -1)) {
                                                    puVar11 = puVar10;
                                                    if (0xf < (ulonglong)puVar10[3]) {
                                                      puVar11 = (undefined8 *)*puVar10;
                                                    }
                                                    if ((((ulonglong)puVar10[2] < 7) ||
                                                        (lVar8 = puVar10[2] + (longlong)puVar11,
                                                        lVar9 = func_0x0001801278a0(puVar11,lVar8,
                                                                                    &UNK_1819d7b68,7
                                                                                   ), lVar9 == lVar8
                                                        )) || (lVar9 - (longlong)puVar11 == -1)) {
                                                      puVar1 = puVar10 + 2;
                                                      if (0xf < (ulonglong)puVar10[3]) {
                                                        puVar10 = (undefined8 *)*puVar10;
                                                      }
                                                      if (((5 < *puVar1) &&
                                                          (lVar8 = *puVar1 + (longlong)puVar10,
                                                          lVar9 = func_0x0001801278a0(puVar10,lVar8,
                                                                                      &UNK_1819d81e4
                                                                                      ,6),
                                                          lVar9 != lVar8)) &&
                                                         (lVar9 - (longlong)puVar10 != -1)) {
                                                        *param_1 = ZEXT816(0);
                                                        *(undefined8 *)param_1[1] = 3;
                                                        *(undefined8 *)(param_1[1] + 8) = 0xf;
                                                        *(short *)*param_1 = (short)_DAT_1819d79bc;
                                                        (*param_1)[2] =
                                                             (char)((uint)_DAT_1819d79bc >> 0x10);
                                                        (*param_1)[3] = 0;
                                                        return param_1;
                                                      }
                                                      *param_1 = ZEXT816(0);
                                                      *(undefined8 *)param_1[1] = 3;
                                                      *(undefined8 *)(param_1[1] + 8) = 0xf;
                                                      *(short *)*param_1 = (short)_DAT_1819d7a10;
                                                      (*param_1)[2] =
                                                           (char)((uint)_DAT_1819d7a10 >> 0x10);
                                                      (*param_1)[3] = 0;
                                                      return param_1;
                                                    }
                                                  }
                                                  }
                                                  }
                                                  *param_1 = ZEXT816(0);
                                                  *(undefined8 *)param_1[1] = 3;
                                                  *(undefined8 *)(param_1[1] + 8) = 0xf;
                                                  *(short *)*param_1 = (short)_DAT_1819d7b44;
                                                  (*param_1)[2] =
                                                       (char)((uint)_DAT_1819d7b44 >> 0x10);
                                                  (*param_1)[3] = 0;
                                                  return param_1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  *param_1 = ZEXT816(0);
                                                  *(undefined8 *)param_1[1] = 3;
                                                  *(undefined8 *)(param_1[1] + 8) = 0xf;
                                                  *(short *)*param_1 = (short)_DAT_1819d7f88;
                                                  (*param_1)[2] =
                                                       (char)((uint)_DAT_1819d7f88 >> 0x10);
                                                  (*param_1)[3] = 0;
                                                  return param_1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  *param_1 = ZEXT816(0);
                                                  *(undefined8 *)param_1[1] = 3;
                                                  *(undefined8 *)(param_1[1] + 8) = 0xf;
                                                  *(short *)*param_1 = (short)_DAT_1819d79bc;
                                                  (*param_1)[2] =
                                                       (char)((uint)_DAT_1819d79bc >> 0x10);
                                                  (*param_1)[3] = 0;
                                                  return param_1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  *param_1 = ZEXT816(0);
                                                  *(undefined8 *)param_1[1] = 3;
                                                  *(undefined8 *)(param_1[1] + 8) = 0xf;
                                                  *(short *)*param_1 = (short)_DAT_1819d7e0c;
                                                  (*param_1)[2] =
                                                       (char)((uint)_DAT_1819d7e0c >> 0x10);
                                                  (*param_1)[3] = 0;
                                                  return param_1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  *param_1 = ZEXT816(0);
                                                  *(undefined8 *)param_1[1] = 3;
                                                  *(undefined8 *)(param_1[1] + 8) = 0xf;
                                                  *(short *)*param_1 = (short)_DAT_1819d7990;
                                                  (*param_1)[2] =
                                                       (char)((uint)_DAT_1819d7990 >> 0x10);
                                                  (*param_1)[3] = 0;
                                                  return param_1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  *param_1 = ZEXT816(0);
                                                  *(undefined8 *)param_1[1] = 3;
                                                  *(undefined8 *)(param_1[1] + 8) = 0xf;
                                                  *(short *)*param_1 = (short)_DAT_1819d7b88;
                                                  (*param_1)[2] =
                                                       (char)((uint)_DAT_1819d7b88 >> 0x10);
                                                  (*param_1)[3] = 0;
                                                  return param_1;
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                      *param_1 = ZEXT816(0);
                                      *(undefined8 *)param_1[1] = 3;
                                      *(undefined8 *)(param_1[1] + 8) = 0xf;
                                      *(short *)*param_1 = (short)_DAT_1819d7bc4;
                                      (*param_1)[2] = (char)((uint)_DAT_1819d7bc4 >> 0x10);
                                      (*param_1)[3] = 0;
                                      return param_1;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                      *param_1 = ZEXT816(0);
                      *(undefined8 *)param_1[1] = 3;
                      *(undefined8 *)(param_1[1] + 8) = 0xf;
                      *(short *)*param_1 = (short)_DAT_1819d7c94;
                      (*param_1)[2] = (char)((uint)_DAT_1819d7c94 >> 0x10);
                      (*param_1)[3] = 0;
                      return param_1;
                    }
                  }
                }
              }
            }
          }
        }
      }
      *param_1 = ZEXT816(0);
      *(undefined8 *)param_1[1] = 3;
      *(undefined8 *)(param_1[1] + 8) = 0xf;
      *(short *)*param_1 = (short)_DAT_1819d7d2c;
      (*param_1)[2] = (char)((uint)_DAT_1819d7d2c >> 0x10);
      (*param_1)[3] = 0;
      return param_1;
    }
  }
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0xf;
  (*param_1)[0] = 0;
  return param_1;
}

