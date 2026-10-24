/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * recovered_180094470(undefined8 *param_1)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined auStack_78 [8];
  undefined8 *puStack_70;
  undefined8 *puStack_68;
  uint uStack_50;
  longlong lStack_48;
  ulonglong uStack_40;
  longlong lStack_30;
  int iStack_28;
  
  GetSystemInfo(auStack_78);
  puVar8 = puStack_70;
  if (((undefined8 *)0x40000000 < param_1) && (puStack_70 < param_1 + -0x8000000)) {
    puVar8 = param_1 + -0x8000000;
  }
  puVar9 = param_1 + 0x8000000;
  if (puStack_68 <= param_1 + 0x8000000) {
    puVar9 = puStack_68;
  }
  puVar9 = (undefined8 *)((longlong)puVar9 - 0xfff);
  for (puVar4 = _DAT_181b50ee0; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)*puVar4) {
    if (((puVar8 <= puVar4) && (puVar4 < puVar9)) && (puVar4[1] != 0)) {
      return puVar4;
    }
  }
  uVar7 = 0x40;
  puVar3 = (undefined8 *)0x0;
  puVar4 = param_1;
  if (puVar8 <= param_1) {
    do {
      uVar5 = (ulonglong)uStack_50;
      puVar4 = (undefined8 *)((longlong)puVar4 + (-uVar5 - (ulonglong)puVar4 % uVar5));
      while( true ) {
        if ((puVar4 < puVar8) || (lVar2 = VirtualQuery(puVar4,&lStack_48,0x30), lVar2 == 0))
        goto LAB_180094579;
        if (iStack_28 == 0x10000) break;
        if (uStack_40 < uVar5) goto LAB_180094579;
        puVar4 = (undefined8 *)(uStack_40 - uVar5);
      }
      if (puVar4 == (undefined8 *)0x0) {
LAB_180094579:
        if (puVar3 != (undefined8 *)0x0) goto LAB_180094660;
        break;
      }
      puVar3 = (undefined8 *)VirtualAlloc(puVar4,0x1000,0x3000,0x40);
      if (puVar3 != (undefined8 *)0x0) goto LAB_18009465b;
    } while (puVar8 <= puVar4);
  }
  if (param_1 <= puVar9) {
    do {
      uVar1 = uStack_50;
      uVar5 = (ulonglong)uStack_50;
      param_1 = (undefined8 *)
                (((ulonglong)uStack_50 - (ulonglong)param_1 % uVar5) + (longlong)param_1);
      while( true ) {
        if ((puVar9 < param_1) || (lVar2 = VirtualQuery(param_1,&lStack_48,0x30), lVar2 == 0))
        goto LAB_18009465b;
        if (iStack_28 == 0x10000) break;
        uVar6 = (ulonglong)(uVar1 - 1) + lStack_30 + lStack_48;
        param_1 = (undefined8 *)(uVar6 - uVar6 % uVar5);
      }
    } while (((param_1 != (undefined8 *)0x0) &&
             (puVar3 = (undefined8 *)VirtualAlloc(param_1,0x1000,0x3000,0x40),
             puVar3 == (undefined8 *)0x0)) && (param_1 <= puVar9));
LAB_18009465b:
    if (puVar3 != (undefined8 *)0x0) {
LAB_180094660:
      *(undefined4 *)(puVar3 + 2) = 0;
      puVar9 = (undefined8 *)0x0;
      puVar8 = puVar3;
      do {
        puVar8 = puVar8 + 8;
        *puVar8 = puVar9;
        puVar3[1] = puVar8;
        uVar7 = uVar7 + 0x40;
        puVar9 = puVar8;
      } while (uVar7 < 0xfc1);
      *puVar3 = _DAT_181b50ee0;
      _DAT_181b50ee0 = puVar3;
    }
  }
  return puVar3;
}

