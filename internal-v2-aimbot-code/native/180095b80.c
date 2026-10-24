/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined8 recovered_180095b80(longlong *param_1)

{
  char cVar1;
  byte bVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined *puVar12;
  char *pcVar13;
  undefined8 *puVar14;
  byte bStackX_8;
  byte bStackX_10;
  undefined2 uStack_a8;
  undefined4 uStack_a6;
  undefined2 uStack_a2;
  undefined4 uStack_a0;
  undefined2 uStack_9c;
  undefined8 uStack_98;
  undefined8 *puStack_90;
  undefined2 uStack_88;
  undefined4 uStack_86;
  undefined2 uStack_82;
  undefined8 uStack_80;
  undefined8 auStack_78 [2];
  byte abStack_68 [11];
  byte bStack_5d;
  byte bStack_5c;
  byte bStack_5b;
  char cStack_59;
  int iStack_53;
  undefined4 uStack_4b;
  uint uStack_47;
  
  puVar14 = (undefined8 *)0x0;
  uStack_88 = 0x15ff;
  uStack_86 = 2;
  uStack_82 = 0x8eb;
  bStackX_8 = 0;
  uStack_80 = (undefined *)0x0;
  uStack_a8 = 0x25ff;
  uStack_a6 = 0;
  uStack_a2 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  uStack_98 = 0x25ff0e70;
  puStack_90 = (undefined8 *)0x0;
  bStackX_10 = 0;
  param_1[4] = 0;
  puVar9 = puVar14;
  do {
    puVar10 = (undefined8 *)((ulonglong)bStackX_10 + *param_1);
    lVar7 = param_1[2];
    uVar3 = func_0x000180094750(puVar10,abStack_68);
    uVar5 = uStack_47;
    uVar3 = uVar3 & 0xffffffff;
    if ((uStack_47 >> 0xc & 1) != 0) {
      return 0;
    }
    puVar8 = puVar9;
    if (bStackX_10 < 5) {
      if ((bStack_5b & 199) == 5) {
        uVar4 = (ulonglong)abStack_68[0];
        puVar9 = puVar10;
        puVar11 = auStack_78;
        for (uVar6 = uVar3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined *)puVar11 = *(undefined *)puVar9;
          puVar9 = (undefined8 *)((longlong)puVar9 + 1);
          puVar11 = (undefined8 *)((longlong)puVar11 + 1);
        }
        *(uint *)((longlong)auStack_78 + (uVar4 - (uVar5 >> 2 & 0xf)) + -4) =
             ((int)puVar10 - ((uint)bStackX_8 + (int)lVar7)) + uStack_4b;
        puVar11 = auStack_78;
        if ((bStack_5d == 0xff) && (cStack_59 == '\x04')) {
          puVar14 = (undefined8 *)0x1;
        }
      }
      else if (bStack_5d == 0xe8) {
        puVar11 = (undefined8 *)&uStack_88;
        uStack_80 = (undefined *)
                    ((longlong)puVar10 + (ulonglong)abStack_68[0] + (longlong)iStack_53);
LAB_180095db8:
        uVar3 = 0x10;
        puVar8 = puVar9;
      }
      else {
        puVar11 = puVar10;
        if ((bStack_5d & 0xfd) == 0xe9) {
          lVar7 = (longlong)(char)iStack_53;
          if (bStack_5d != 0xeb) {
            lVar7 = (longlong)iStack_53;
          }
          puVar8 = (undefined8 *)((longlong)puVar10 + lVar7 + (ulonglong)abStack_68[0]);
          if ((puVar8 < (undefined8 *)*param_1) ||
             ((undefined8 *)((longlong)(undefined8 *)*param_1 + 5U) <= puVar8)) {
            uStack_a2 = SUB82(puVar8,0);
            uStack_a0 = (undefined4)((ulonglong)puVar8 >> 0x10);
            uStack_9c = (undefined2)((ulonglong)puVar8 >> 0x30);
            puVar14 = (undefined8 *)(ulonglong)(puVar9 <= puVar10);
            uVar3 = 0xe;
            puVar11 = (undefined8 *)&uStack_a8;
            puVar8 = puVar9;
          }
          else if (puVar8 <= puVar9) {
            puVar8 = puVar9;
          }
        }
        else if ((((bStack_5d & 0xf0) == 0x70) || ((bStack_5d & 0xfc) == 0xe0)) ||
                ((bStack_5c & 0xf0) == 0x80)) {
          if (((bStack_5d & 0xf0) == 0x70) ||
             (lVar7 = (longlong)iStack_53, (bStack_5d & 0xfc) == 0xe0)) {
            lVar7 = (longlong)(char)iStack_53;
          }
          puVar8 = (undefined8 *)((longlong)puVar10 + lVar7 + (ulonglong)abStack_68[0]);
          if ((puVar8 < (undefined8 *)*param_1) ||
             ((undefined8 *)((longlong)(undefined8 *)*param_1 + 5U) <= puVar8)) {
            if ((bStack_5d & 0xfc) == 0xe0) {
              return 0;
            }
            bVar2 = bStack_5d;
            if (bStack_5d == 0xf) {
              bVar2 = bStack_5c;
            }
            puStack_90 = puVar8;
            puVar11 = &uStack_98;
            uStack_98 = CONCAT71(uStack_98._1_7_,bVar2) & 0xffffffffffffff0f ^ 0x71;
            goto LAB_180095db8;
          }
          if (puVar8 <= puVar9) {
            puVar8 = puVar9;
          }
        }
        else if ((bStack_5d & 0xfe) == 0xc2) {
          puVar14 = (undefined8 *)(ulonglong)(puVar9 <= puVar10);
        }
      }
    }
    else {
      uStack_a2 = SUB82(puVar10,0);
      uStack_a0 = (undefined4)((ulonglong)puVar10 >> 0x10);
      uStack_9c = (undefined2)((ulonglong)puVar10 >> 0x30);
      uVar3 = 0xe;
      puVar14 = (undefined8 *)0x1;
      puVar11 = (undefined8 *)&uStack_a8;
    }
    if ((puVar10 < puVar8) && ((uint)uVar3 != (uint)abStack_68[0])) {
      return 0;
    }
    uVar6 = (ulonglong)bStackX_8;
    if (0x32 < (uint)uVar3 + (uint)bStackX_8) {
      return 0;
    }
    if (7 < *(uint *)((longlong)param_1 + 0x24)) {
      return 0;
    }
    *(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0x24) + 0x28 + (longlong)param_1) =
         bStackX_10;
    *(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0x24) + 0x30 + (longlong)param_1) = bStackX_8
    ;
    bStackX_8 = bStackX_8 + (char)uVar3;
    *(int *)((longlong)param_1 + 0x24) = *(int *)((longlong)param_1 + 0x24) + 1;
    puVar12 = (undefined *)(uVar6 + param_1[2]);
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar12 = *(undefined *)puVar11;
      puVar11 = (undefined8 *)((longlong)puVar11 + 1);
      puVar12 = puVar12 + 1;
    }
    bStackX_10 = bStackX_10 + abStack_68[0];
    puVar9 = puVar8;
  } while ((int)puVar14 == 0);
  if (bStackX_10 < 5) {
    pcVar13 = (char *)((ulonglong)bStackX_10 + *param_1);
    cVar1 = *pcVar13;
    if (((cVar1 != '\0') && (cVar1 != -0x70)) && (cVar1 != -0x34)) {
LAB_180095e62:
      if (bStackX_10 < 2) {
        if (((cVar1 != '\0') && (cVar1 != -0x70)) && (cVar1 != -0x34)) {
          return 0;
        }
        uVar3 = 1;
        if (1 < 2 - bStackX_10) {
          do {
            if (pcVar13[uVar3] != cVar1) {
              return 0;
            }
            uVar5 = (int)uVar3 + 1;
            uVar3 = (ulonglong)uVar5;
          } while (uVar5 < 2 - bStackX_10);
        }
      }
      VirtualQuery(*param_1 + -5,abStack_68,0x30);
      if ((CONCAT31((undefined3)uStack_47,uStack_4b._3_1_) == 0x1000) &&
         ((uStack_47 & 0xf0000000) != 0)) {
        cVar1 = *(char *)(*param_1 + -5);
        if ((cVar1 == '\0') || ((cVar1 == -0x70 || (cVar1 == -0x34)))) {
          uVar5 = 1;
          pcVar13 = (char *)(*param_1 + -4);
          do {
            if (*pcVar13 != cVar1) {
              return 0;
            }
            uVar5 = uVar5 + 1;
            pcVar13 = pcVar13 + 1;
          } while (uVar5 < 5);
          *(undefined4 *)(param_1 + 4) = 1;
          goto LAB_180095f06;
        }
      }
      return 0;
    }
    uVar3 = 1;
    if (1 < 5 - bStackX_10) {
      do {
        if (pcVar13[uVar3] != cVar1) goto LAB_180095e62;
        uVar5 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar5;
      } while (uVar5 < 5 - bStackX_10);
    }
  }
LAB_180095f06:
  lVar7 = param_1[1];
  uStack_a2 = (undefined2)lVar7;
  uStack_a0 = (undefined4)((ulonglong)lVar7 >> 0x10);
  uStack_9c = (undefined2)((ulonglong)lVar7 >> 0x30);
  puVar9 = (undefined8 *)((ulonglong)bStackX_8 + param_1[2]);
  param_1[3] = (longlong)puVar9;
  *puVar9 = CONCAT26(uStack_a2,CONCAT42(uStack_a6,uStack_a8));
  *(undefined4 *)(puVar9 + 1) = uStack_a0;
  *(undefined2 *)((longlong)puVar9 + 0xc) = uStack_9c;
  return 1;
}

