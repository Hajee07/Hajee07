/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 recovered_1800954f0(undefined4 *param_1)

{
  undefined8 uVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  bool bVar9;
  undefined4 *puStack_48;
  undefined *puStack_40;
  undefined8 *puStack_38;
  undefined8 uStack_30;
  int iStack_28;
  uint uStack_24;
  undefined8 uStack_20;
  undefined8 uStack_18;
  
  uVar8 = 0;
  uVar7 = 0;
  LOCK();
  bVar9 = _DAT_181b2f2d8 == 0;
  if (bVar9) {
    _DAT_181b2f2d8 = 1;
  }
  UNLOCK();
  while (!bVar9) {
    Sleep(0x1f < uVar7);
    uVar7 = uVar7 + 1;
    LOCK();
    bVar9 = _DAT_181b2f2d8 == 0;
    if (bVar9) {
      _DAT_181b2f2d8 = 1;
    }
    UNLOCK();
  }
  if (_DAT_181b2f2e0 == 0) {
    uVar8 = 2;
    goto LAB_1800957a3;
  }
  VirtualQuery(param_1,&puStack_48,0x30);
  if ((((iStack_28 != 0x1000) || ((uStack_24 & 0xf0) == 0)) ||
      (VirtualQuery(&UNK_180095f90,&puStack_48,0x30), iStack_28 != 0x1000)) ||
     ((uStack_24 & 0xf0) == 0)) {
    uVar8 = 7;
    goto LAB_1800957a3;
  }
  uVar2 = 0;
  puVar6 = _DAT_181b50ed0;
  if (_DAT_181b50edc != 0) {
    do {
      if (param_1 == (undefined4 *)*puVar6) {
        if (uVar2 != 0xffffffff) {
          uVar8 = 3;
          goto LAB_1800957a3;
        }
        break;
      }
      uVar2 = uVar2 + 1;
      puVar6 = puVar6 + 7;
    } while (uVar2 < _DAT_181b50edc);
  }
  lVar4 = recovered_180094470(param_1);
  if (lVar4 != 0) {
    puVar6 = *(undefined8 **)(lVar4 + 8);
    uVar1 = *puVar6;
    *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 1;
    *(undefined8 *)(lVar4 + 8) = uVar1;
    if (puVar6 != (undefined8 *)0x0) {
      puStack_40 = &UNK_180095f90;
      puStack_48 = param_1;
      puStack_38 = puVar6;
      iVar3 = recovered_180095b80(&puStack_48);
      if (iVar3 == 0) {
        uVar8 = 8;
        func_0x0001800946d0(puVar6);
        goto LAB_1800957a3;
      }
      if (_DAT_181b50ed0 == (undefined8 *)0x0) {
        _DAT_181b50ed8 = 0x20;
        _DAT_181b50ed0 = (undefined8 *)HeapAlloc(_DAT_181b2f2e0,0,0x700);
        if (_DAT_181b50ed0 != (undefined8 *)0x0) goto LAB_1800956d8;
      }
      else {
        if (_DAT_181b50ed8 <= _DAT_181b50edc) {
          puVar5 = (undefined8 *)
                   HeapReAlloc(_DAT_181b2f2e0,0,_DAT_181b50ed0,
                               (ulonglong)(_DAT_181b50ed8 * 2) * 0x38);
          if (puVar5 == (undefined8 *)0x0) goto LAB_180095664;
          _DAT_181b50ed8 = _DAT_181b50ed8 * 2;
          _DAT_181b50ed0 = puVar5;
        }
LAB_1800956d8:
        uVar7 = (ulonglong)_DAT_181b50edc;
        _DAT_181b50edc = _DAT_181b50edc + 1;
        puVar5 = _DAT_181b50ed0 + uVar7 * 7;
        if (puVar5 != (undefined8 *)0x0) {
          *(uint *)((longlong)puVar5 + 0x24) = *(uint *)((longlong)puVar5 + 0x24) & 0xfffffff0;
          *puVar5 = puStack_48;
          puVar5[1] = uStack_30;
          puVar5[2] = puStack_38;
          *(byte *)(puVar5 + 4) = (byte)iStack_28 & 1 | *(byte *)(puVar5 + 4) & 0xf8;
          *(uint *)((longlong)puVar5 + 0x24) = *(uint *)((longlong)puVar5 + 0x24) | uStack_24 & 0xf;
          puVar5[5] = uStack_20;
          puVar5[6] = uStack_18;
          if (iStack_28 == 0) {
            *(undefined4 *)(puVar5 + 3) = *param_1;
            *(undefined *)((longlong)puVar5 + 0x1c) = *(undefined *)(param_1 + 1);
            _DAT_181b4ef88 = puStack_38;
          }
          else {
            *(undefined4 *)(puVar5 + 3) = *(undefined4 *)((longlong)param_1 + -5);
            *(undefined2 *)((longlong)puVar5 + 0x1c) = *(undefined2 *)((longlong)param_1 + -1);
            *(undefined *)((longlong)puVar5 + 0x1e) = *(undefined *)((longlong)param_1 + 1);
            _DAT_181b4ef88 = puStack_38;
          }
          goto LAB_1800957a3;
        }
      }
LAB_180095664:
      uVar8 = 9;
      func_0x0001800946d0(puVar6);
      goto LAB_1800957a3;
    }
  }
  uVar8 = 9;
LAB_1800957a3:
  LOCK();
  _DAT_181b2f2d8 = 0;
  UNLOCK();
  return uVar8;
}

