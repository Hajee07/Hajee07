/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool recovered_18008bca0(uint param_1,uint *param_2)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  uint auStackX_8 [2];
  uint auStackX_10 [2];
  uint auStackX_18 [2];
  int aiStackX_20 [2];
  int aiStack_68 [2];
  undefined8 uStack_60;
  undefined8 auStack_58 [3];
  
  uVar9 = (ulonglong)param_1;
  *param_2 = 0;
  auStackX_18[0] = 0;
  cVar2 = recovered_180067cc0(uVar9 + 0xdc,&uStack_60);
  if ((((cVar2 != '\0') &&
       (iVar3 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_60,auStackX_18,4), iVar3 == 0)) &&
      (auStackX_18[0] != 0)) ||
     (((cVar2 = recovered_180067cc0(uVar9 + 0xc4,&uStack_60), cVar2 != '\0' &&
       (iVar3 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_60,auStackX_18,4), iVar3 == 0)) &&
      (auStackX_18[0] != 0)))) {
    aiStackX_20[0] = 0;
    aiStack_68[0] = 0;
    cVar2 = recovered_180067cc0(auStackX_18[0] + 8,&uStack_60);
    if (((cVar2 != '\0') &&
        (iVar3 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_60,aiStackX_20,4), iVar3 == 0)) &&
       ((aiStackX_20[0] != 0 &&
        (((cVar2 = recovered_180067cc0(auStackX_18[0] + 0xc,&uStack_60), cVar2 != '\0' &&
          (iVar3 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_60,aiStack_68,4), iVar3 == 0)) &&
         (0 < aiStack_68[0])))))) {
      aiStackX_20[0] = aiStackX_20[0] + 0x10;
      auStackX_10[0] = 0;
      cVar2 = recovered_180067cc0(aiStackX_20[0],&uStack_60);
      if (((cVar2 != '\0') &&
          (iVar3 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_60,auStackX_10,4), iVar3 == 0)) &&
         (uVar7 = (ulonglong)auStackX_10[0], auStackX_10[0] != 0)) {
        plVar8 = (longlong *)&UNK_1819d89a0;
        do {
          lVar1 = *plVar8;
          if ((int)uVar7 == 0) {
LAB_18008beb0:
            *param_2 = 0;
          }
          else {
            auStackX_8[0] = auStackX_8[0] & 0xffff0000;
            cVar2 = recovered_180067cc0(uVar7 + lVar1,&uStack_60);
            if ((cVar2 == '\0') ||
               (iVar3 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_60,auStackX_8,2), iVar3 != 0)) {
LAB_18008bead:
              uVar7 = (ulonglong)auStackX_10[0];
              goto LAB_18008beb0;
            }
            if ((short)auStackX_8[0] == 0) goto LAB_18008bead;
            iVar3 = (short)auStackX_8[0] + 25000;
            if (-1 < (short)auStackX_8[0]) {
              iVar3 = (int)(short)auStackX_8[0];
            }
            uVar4 = func_0x000180089860(iVar3);
            *param_2 = uVar4;
            if (uVar4 != 0) goto LAB_18008c0b5;
            uVar7 = (ulonglong)auStackX_10[0];
          }
          if ((int)uVar7 == 0) {
LAB_18008bf97:
            *param_2 = 0;
          }
          else {
            auStackX_8[0] = 0;
            cVar2 = recovered_180067cc0(uVar7 + lVar1,auStack_58);
            if (((cVar2 == '\0') ||
                (iVar3 = (*_DAT_181b4ef88)(_DAT_181b4ef90,auStack_58[0],auStackX_8,4), iVar3 != 0))
               || (auStackX_8[0] == 0)) {
              uVar7 = (ulonglong)auStackX_10[0];
              goto LAB_18008bf97;
            }
            uVar4 = auStackX_8[0] + 25000;
            if (-1 < (int)auStackX_8[0]) {
              uVar4 = auStackX_8[0];
            }
            if ((int)uVar4 < 0x10000) {
              if ((int)uVar4 < 20000) goto LAB_18008bf83;
              if ((int)uVar4 < 21000) {
                uVar6 = uVar4 - 20000;
joined_r0x00018008bf81:
                if ((int)uVar6 < 1) goto LAB_18008bf83;
              }
              else {
                if (21999 < (int)uVar4) goto LAB_18008bf83;
                uVar6 = uVar4 - 21000;
                if (uVar6 == 1) {
                  uVar6 = 0x5209;
                }
                else if (uVar6 == 2) {
                  uVar6 = 0x520a;
                }
                else if (uVar6 == 6) {
                  uVar6 = 0x520e;
                }
                else {
                  if (uVar6 != 0x14) goto joined_r0x00018008bf81;
                  uVar6 = 1;
                }
              }
            }
            else {
              uVar6 = uVar4 & 0xffff;
              if (uVar6 - 1 < 499) goto LAB_18008bf85;
LAB_18008bf83:
              uVar6 = uVar4;
            }
LAB_18008bf85:
            *param_2 = uVar6;
            if (uVar6 != 0) goto LAB_18008c0b5;
            uVar7 = (ulonglong)auStackX_10[0];
          }
          plVar8 = plVar8 + 1;
        } while (plVar8 != (longlong *)&UNK_1819d89e0);
        plVar8 = (longlong *)&UNK_1819d8948;
        do {
          lVar1 = *plVar8;
          if (param_1 == 0) {
LAB_18008c025:
            *param_2 = 0;
          }
          else {
            auStackX_8[0] = auStackX_8[0] & 0xffff0000;
            cVar2 = recovered_180067cc0(uVar9 + lVar1,auStack_58);
            if ((cVar2 == '\0') ||
               (iVar3 = (*_DAT_181b4ef88)(_DAT_181b4ef90,auStack_58[0],auStackX_8,2), iVar3 != 0))
            goto LAB_18008c025;
            if ((short)auStackX_8[0] == 0) goto LAB_18008c025;
            iVar3 = (short)auStackX_8[0] + 25000;
            if (-1 < (short)auStackX_8[0]) {
              iVar3 = (int)(short)auStackX_8[0];
            }
            uVar4 = func_0x000180089860(iVar3);
            *param_2 = uVar4;
            if (uVar4 != 0) goto LAB_18008c0b5;
          }
          uVar4 = func_0x00018008bb30(uVar9,lVar1,0);
          *param_2 = uVar4;
          if (uVar4 != 0) goto LAB_18008c0b5;
          plVar8 = plVar8 + 1;
        } while (plVar8 != (longlong *)&UNK_1819d8978);
        uVar4 = recovered_180069360((ulonglong)auStackX_10[0] + 0x434);
        if (uVar4 != 0) {
          uVar5 = recovered_180069360((ulonglong)uVar4 + 0x494);
          uVar6 = func_0x000180089860(uVar5);
          *param_2 = uVar6;
          if ((uVar6 == 0) && (uVar4 = recovered_180069360((ulonglong)uVar4 + 0x58), uVar4 != 0)) {
            plVar8 = (longlong *)&UNK_1819d8978;
            do {
              uVar5 = recovered_180069360(*plVar8 + (ulonglong)uVar4);
              uVar6 = func_0x000180089860(uVar5);
              *param_2 = uVar6;
              if (uVar6 != 0) break;
              plVar8 = plVar8 + 1;
            } while (plVar8 != (longlong *)&UNK_1819d8998);
          }
        }
LAB_18008c0b5:
        return *param_2 != 0;
      }
    }
  }
  return false;
}

