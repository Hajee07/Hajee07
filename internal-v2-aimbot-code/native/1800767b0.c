/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint recovered_1800767b0(uint param_1,char *param_2,undefined8 *param_3)

{
  char cVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined8 uVar7;
  char *pcVar8;
  undefined8 *******pppppppuVar9;
  int *piVar10;
  undefined8 *puVar11;
  ulonglong uVar12;
  float extraout_XMM0_Da;
  float fVar13;
  float fVar14;
  float fVar15;
  uint auStackX_20 [2];
  undefined4 uStack_1f8;
  undefined4 uStack_1f4;
  undefined8 uStack_1e8;
  undefined8 uStack_1b8;
  undefined8 *******apppppppuStack_1b0 [2];
  longlong lStack_1a0;
  ulonglong uStack_198;
  int aiStack_188 [2];
  char *pcStack_180;
  undefined4 uStack_178;
  char *pcStack_170;
  undefined4 uStack_168;
  char *pcStack_160;
  undefined4 uStack_158;
  char *pcStack_150;
  undefined4 uStack_148;
  char *pcStack_140;
  undefined4 uStack_138;
  char *pcStack_130;
  undefined4 uStack_128;
  char *pcStack_120;
  undefined4 uStack_118;
  char *pcStack_110;
  undefined4 uStack_108;
  char *pcStack_100;
  undefined4 uStack_f8;
  char *pcStack_f0;
  undefined4 uStack_e8;
  char *pcStack_e0;
  undefined4 uStack_d8;
  char *pcStack_d0;
  undefined4 uStack_c8;
  char *pcStack_c0;
  undefined4 uStack_b8;
  char *pcStack_b0;
  undefined4 uStack_a8;
  char *pcStack_a0;
  undefined4 uStack_98;
  char *pcStack_90;
  undefined4 uStack_88;
  char *pcStack_80;
  undefined4 uStack_78;
  char *pcStack_70;
  int aiStack_68 [2];
  undefined8 uStack_60;
  undefined8 uStack_54;
  undefined8 auStack_48 [4];
  
  uVar12 = (ulonglong)param_1;
  uVar3 = recovered_180069360(uVar12 + 0x504);
  if ((uVar3 != 0) && (uVar3 = recovered_180069360((ulonglong)uVar3 + 0xa8), uVar3 != 0)) {
    auStackX_20[0] = auStackX_20[0] & 0xffffff00;
    cVar1 = recovered_180067cc0((ulonglong)uVar3 + 0x95,&uStack_1f8);
    if (cVar1 == '\0') {
      if (_DAT_181b4ef90 == 0) {
        uVar7 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                    &UNK_1819d77a0);
        __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                  (uVar7,&DAT_180069ca0);
      }
    }
    else {
      (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1f4,uStack_1f8),auStackX_20,1);
    }
    param_2[4] = (char)auStackX_20[0];
    uVar3 = recovered_180069360((ulonglong)uVar3 + 0x14);
    if (uVar3 != 0) {
      auStackX_20[0] = auStackX_20[0] & 0xffffff00;
      cVar1 = recovered_180067cc0((ulonglong)uVar3 + 0x59,&uStack_1f8);
      if (cVar1 == '\0') {
        if (_DAT_181b4ef90 == 0) {
          uVar7 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                      ,&UNK_1819d77a0);
          __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                    (uVar7,&DAT_180069ca0);
        }
      }
      else {
        (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1f4,uStack_1f8),auStackX_20,1);
      }
      iVar6 = 0;
      *(uint *)(param_2 + 0x18) = (uint)((char)auStackX_20[0] == '\0');
      param_2[1] = (char)auStackX_20[0] == '\0';
      if ((char)auStackX_20[0] == '\0') {
        uVar3 = recovered_180069360(uVar12 + 0x1a60);
        if (uVar3 != 0) {
          auStackX_20[0] = 0;
          cVar1 = recovered_180067cc0((ulonglong)uVar3 + 0x78,&uStack_1f8);
          if (cVar1 == '\0') {
            if (_DAT_181b4ef90 == 0) {
              uVar7 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                          ,&UNK_1819d77a0);
              __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                        (uVar7,&DAT_180069ca0);
            }
          }
          else {
            (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1f4,uStack_1f8),auStackX_20,4);
          }
          param_2[3] = auStackX_20[0] == 8;
        }
        uVar2 = recovered_18006e7e0(uVar12);
        *(undefined2 *)(param_2 + 0x12) = uVar2;
        auStackX_20[0] = auStackX_20[0] & 0xffffff00;
        cVar1 = recovered_180067cc0(uVar12 + 0x50,&uStack_1f8);
        if (cVar1 == '\0') {
          if (_DAT_181b4ef90 == 0) {
            uVar7 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                        ,&UNK_1819d77a0);
            __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                      (uVar7,&DAT_180069ca0);
          }
        }
        else {
          (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1f4,uStack_1f8),auStackX_20,1);
        }
        param_2[2] = (char)auStackX_20[0];
        auStackX_20[0] = auStackX_20[0] & 0xffffff00;
        cVar1 = recovered_180067cc0(uVar12 + 0x324,&uStack_1f8);
        if (cVar1 == '\0') {
          if (_DAT_181b4ef90 == 0) {
            uVar7 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                        ,&UNK_1819d77a0);
            __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                      (uVar7,&DAT_180069ca0);
          }
        }
        else {
          (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1f4,uStack_1f8),auStackX_20,1);
        }
        *param_2 = (char)auStackX_20[0];
        *(uint *)(param_2 + 0x84) = param_1;
        iVar4 = recovered_180069360(uVar12 + 0x48);
        if (((iVar4 != 0) && (iVar4 = recovered_180069360(iVar4 + 8), iVar4 != 0)) &&
           (iVar4 = recovered_180069360(iVar4 + 0x10), iVar4 != 0)) {
          auStackX_20[0] = auStackX_20[0] & 0xffff0000;
          cVar1 = recovered_180067cc0(iVar4 + 0x10,&uStack_1f8);
          if (cVar1 == '\0') {
            if (_DAT_181b4ef90 == 0) {
              uVar7 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref
                                          ,&UNK_1819d77a0);
              __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
                        (uVar7,&DAT_180069ca0);
            }
          }
          else {
            (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStack_1f4,uStack_1f8),auStackX_20,2);
          }
          *(undefined2 *)(param_2 + 0x10) = (undefined2)auStackX_20[0];
        }
        aiStack_188[0] = _DAT_181a2b110;
        pcStack_180 = param_2 + 0x88;
        uStack_178 = _DAT_181a2b0f0;
        pcStack_170 = param_2 + 0x94;
        uStack_168 = _DAT_181a2b118;
        pcStack_160 = param_2 + 0xac;
        uStack_158 = _DAT_181a2b0f8;
        pcStack_150 = param_2 + 0xa0;
        uStack_148 = _DAT_181a2b100;
        pcStack_140 = param_2 + 0xc4;
        uStack_138 = _DAT_181a2b120;
        pcStack_130 = param_2 + 0xb8;
        uStack_128 = _DAT_181a2b108;
        pcStack_120 = param_2 + 0xdc;
        uStack_118 = _DAT_181a2b150;
        pcStack_110 = param_2 + 0xd0;
        uStack_108 = _DAT_181a2b178;
        pcStack_100 = param_2 + 0xe8;
        uStack_f8 = _DAT_181a2b160;
        pcStack_f0 = param_2 + 0xf4;
        uStack_e8 = _DAT_181a2b128;
        pcStack_e0 = param_2 + 0x100;
        uStack_d8 = _DAT_181a2b168;
        pcStack_d0 = param_2 + 0x10c;
        uStack_c8 = _DAT_181a2b148;
        pcStack_c0 = param_2 + 0x148;
        uStack_b8 = _DAT_181a2b140;
        pcStack_b0 = param_2 + 0x154;
        uStack_a8 = _DAT_181a2b170;
        pcStack_a0 = param_2 + 0x124;
        uStack_98 = _DAT_181a2b158;
        pcStack_90 = param_2 + 0x118;
        uStack_88 = _DAT_181a2b138;
        pcStack_80 = param_2 + 0x130;
        uStack_78 = _DAT_181a2b130;
        pcStack_70 = param_2 + 0x13c;
        piVar10 = aiStack_188;
        do {
          while( true ) {
            if (piVar10 == aiStack_68) {
              if ((((float)*(undefined8 *)(param_2 + 0x88) != 0.0) ||
                  (uStack_1e8._4_4_ = (float)((ulonglong)*(undefined8 *)(param_2 + 0x88) >> 0x20),
                  uStack_1e8._4_4_ != 0.0)) || (*(float *)(param_2 + 0x90) != 0.0)) {
                uStack_1e8 = *(undefined8 *)(param_2 + 0x88);
                fVar14 = (float)*param_3 - (float)uStack_1e8;
                fVar13 = (float)((ulonglong)*param_3 >> 0x20);
                fVar15 = fVar13 - (float)((ulonglong)uStack_1e8 >> 0x20);
                fVar14 = fVar15 * fVar15 + fVar14 * fVar14 +
                         (*(float *)(param_3 + 1) - *(float *)(param_2 + 0x90)) *
                         (*(float *)(param_3 + 1) - *(float *)(param_2 + 0x90));
                if (fVar14 < 0.0) {
                  func_0x0001801cb525(CONCAT44(fVar13,fVar14));
                  fVar14 = extraout_XMM0_Da;
                }
                else {
                  fVar14 = SQRT(fVar14);
                }
                *(float *)(param_2 + 0xc) = fVar14;
              }
              uVar7 = *(undefined8 *)(param_2 + 0x88);
              if ((((float)uVar7 == 0.0) &&
                  (uStack_1e8._4_4_ = (float)((ulonglong)uVar7 >> 0x20), uStack_1e8._4_4_ == 0.0))
                 && (*(float *)(param_2 + 0x90) == 0.0)) {
                return 0;
              }
              uStack_1e8 = uVar7;
              if (*(longlong *)(param_2 + 0x30) == 0) {
                recovered_18006b9b0(apppppppuStack_1b0,uVar12);
                if ((lStack_1a0 != 0) &&
                   ((undefined8 ********)(param_2 + 0x20) != apppppppuStack_1b0)) {
                  pppppppuVar9 = apppppppuStack_1b0;
                  if (0xf < uStack_198) {
                    pppppppuVar9 = apppppppuStack_1b0[0];
                  }
                  recovered_1800676d0(param_2 + 0x20,pppppppuVar9);
                }
                recovered_180066e40(apppppppuStack_1b0);
              }
              if (*(longlong *)(param_2 + 0x50) == 0) {
                puVar11 = (undefined8 *)(param_2 + 0x40);
                if (*param_2 == '\0') {
                  *(undefined8 *)(param_2 + 0x70) = 0;
                  pcVar8 = param_2 + 0x60;
                  if (0xf < *(ulonglong *)(param_2 + 0x78)) {
                    pcVar8 = *(char **)(param_2 + 0x60);
                  }
                  *pcVar8 = '\0';
                  if (param_1 == 0) {
                    *(undefined8 *)(param_2 + 0x50) = 0;
                    if (0xf < *(ulonglong *)(param_2 + 0x58)) {
                      puVar11 = (undefined8 *)*puVar11;
                    }
                    *(undefined *)puVar11 = 0;
                  }
                  else {
                    auStackX_20[0] = 0;
                    cVar1 = recovered_180067cc0(uVar12 + 0x18cc,&uStack_1e8);
                    if (((cVar1 == '\0') ||
                        (iVar4 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1e8,auStackX_20,4),
                        iVar4 != 0)) || (auStackX_20[0] == 0)) {
                      recovered_1800676d0(puVar11,&DAT_18020e770,7);
                    }
                    else {
                      uVar5 = recovered_180069360((ulonglong)auStackX_20[0] + 0x5c);
                      recovered_18006c300(uVar5,puVar11,param_2 + 0x60);
                    }
                    auStackX_20[0] = 0;
                    cVar1 = recovered_180067cc0(uVar12 + 0x18cc,&uStack_1e8);
                    if (((cVar1 != '\0') &&
                        (iVar4 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1e8,auStackX_20,4),
                        iVar4 == 0)) &&
                       ((iVar6 = 0, 0xffff < auStackX_20[0] &&
                        (iVar6 = recovered_180069360((ulonglong)auStackX_20[0] + 0x14),
                        199 < iVar6 - 1U)))) {
                      iVar4 = recovered_180069360((ulonglong)auStackX_20[0] + 0x14);
                      iVar6 = 0;
                      if (iVar4 - 1U < 200) {
                        iVar6 = iVar4;
                      }
                    }
                  }
                  *(int *)(param_2 + 0x80) = iVar6;
                }
                else {
                  recovered_1800676d0(puVar11,&UNK_1819d7890,3);
                }
              }
              return 1;
            }
            auStackX_20[0] = 0;
            cVar1 = recovered_180067cc0(*piVar10 + param_1,&uStack_1b8);
            if (((cVar1 != '\0') &&
                (iVar4 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1b8,auStackX_20,4), iVar4 == 0)) &&
               (auStackX_20[0] != 0)) break;
            puVar11 = *(undefined8 **)(piVar10 + 2);
            if (puVar11 != auStack_48) {
              *puVar11 = 0;
              *(undefined4 *)(puVar11 + 1) = 0;
            }
LAB_180076e3c:
            piVar10 = piVar10 + 4;
          }
          puVar11 = *(undefined8 **)(piVar10 + 2);
          cVar1 = recovered_180067cc0(auStackX_20[0] + 8,&uStack_1e8);
          if ((cVar1 == '\0') ||
             (iVar4 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1e8,&uStack_1f8,4), iVar4 != 0)) {
            if (puVar11 != &uStack_60) {
              *puVar11 = 0;
              *(undefined4 *)(puVar11 + 1) = 0;
            }
          }
          else {
            cVar1 = recovered_18006bd40(uStack_1f8,puVar11);
            if (cVar1 != '\0') goto LAB_180076e3c;
          }
          if (puVar11 == &uStack_54) goto LAB_180076e3c;
          *puVar11 = 0;
          *(undefined4 *)(puVar11 + 1) = 0;
          piVar10 = piVar10 + 4;
        } while( true );
      }
      uVar3 = 1;
    }
  }
  return uVar3;
}

