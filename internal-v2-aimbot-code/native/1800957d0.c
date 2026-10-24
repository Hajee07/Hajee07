/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong recovered_1800957d0(void)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  longlong lVar7;
  longlong *plVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  int *piVar13;
  bool bVar14;
  int *piStack_28;
  uint uStack_1c;
  
  lVar7 = _DAT_181b4ef88;
  uVar11 = 0;
  LOCK();
  bVar14 = _DAT_181b2f2d8 == 0;
  if (bVar14) {
    _DAT_181b2f2d8 = 1;
  }
  UNLOCK();
  uVar10 = uVar11;
  while (!bVar14) {
    Sleep(0x1f < uVar10);
    uVar10 = uVar10 + 1;
    LOCK();
    bVar14 = _DAT_181b2f2d8 == 0;
    if (bVar14) {
      _DAT_181b2f2d8 = 1;
    }
    UNLOCK();
  }
  if (_DAT_181b2f2e0 == 0) {
    uVar11 = 2;
  }
  else {
    plVar8 = _DAT_181b50ed0;
    uVar10 = uVar11;
    if (_DAT_181b50edc != 0) {
      do {
        uVar9 = (uint)uVar10;
        if (lVar7 == *plVar8) {
          if (uVar9 != 0xffffffff) {
            if ((*(byte *)(_DAT_181b50ed0 + uVar10 * 7 + 4) & 2) == 0) goto LAB_18009591c;
            uVar6 = recovered_180095090(&piStack_28,uVar10,0);
            uVar11 = (ulonglong)uVar6;
            if (uVar6 == 0) {
              uVar6 = recovered_180095290(uVar10,0);
              uVar11 = (ulonglong)uVar6;
              if (piStack_28 != (int *)0x0) {
                if (uStack_1c != 0) {
                  uVar12 = (ulonglong)uStack_1c;
                  piVar13 = piStack_28;
                  do {
                    if ((*piVar13 != 0) && (lVar7 = OpenThread(0x5a,0), lVar7 != 0)) {
                      ResumeThread(lVar7);
                      CloseHandle(lVar7);
                    }
                    piVar13 = piVar13 + 1;
                    uVar12 = uVar12 - 1;
                  } while (uVar12 != 0);
                }
                HeapFree(_DAT_181b2f2e0,0,piStack_28);
              }
              if (uVar6 != 0) goto LAB_1800959bd;
LAB_18009591c:
              func_0x0001800946d0(_DAT_181b50ed0[uVar10 * 7 + 2]);
              plVar8 = _DAT_181b50ed0;
              _DAT_181b50edc = _DAT_181b50edc - 1;
              if (uVar9 < _DAT_181b50edc) {
                uVar12 = (ulonglong)_DAT_181b50edc;
                plVar1 = _DAT_181b50ed0 + uVar12 * 7;
                uVar3 = *(undefined4 *)((longlong)plVar1 + 4);
                uVar4 = *(undefined4 *)(plVar1 + 1);
                uVar5 = *(undefined4 *)((longlong)plVar1 + 0xc);
                plVar2 = _DAT_181b50ed0 + uVar10 * 7;
                *(undefined4 *)plVar2 = *(undefined4 *)plVar1;
                *(undefined4 *)((longlong)plVar2 + 4) = uVar3;
                *(undefined4 *)(plVar2 + 1) = uVar4;
                *(undefined4 *)((longlong)plVar2 + 0xc) = uVar5;
                plVar1 = plVar8 + uVar12 * 7 + 2;
                uVar3 = *(undefined4 *)((longlong)plVar1 + 4);
                uVar4 = *(undefined4 *)(plVar1 + 1);
                uVar5 = *(undefined4 *)((longlong)plVar1 + 0xc);
                plVar2 = plVar8 + uVar10 * 7 + 2;
                *(undefined4 *)plVar2 = *(undefined4 *)plVar1;
                *(undefined4 *)((longlong)plVar2 + 4) = uVar3;
                *(undefined4 *)(plVar2 + 1) = uVar4;
                *(undefined4 *)((longlong)plVar2 + 0xc) = uVar5;
                plVar1 = plVar8 + uVar12 * 7 + 4;
                uVar3 = *(undefined4 *)((longlong)plVar1 + 4);
                uVar4 = *(undefined4 *)(plVar1 + 1);
                uVar5 = *(undefined4 *)((longlong)plVar1 + 0xc);
                plVar2 = plVar8 + uVar10 * 7 + 4;
                *(undefined4 *)plVar2 = *(undefined4 *)plVar1;
                *(undefined4 *)((longlong)plVar2 + 4) = uVar3;
                *(undefined4 *)(plVar2 + 1) = uVar4;
                *(undefined4 *)((longlong)plVar2 + 0xc) = uVar5;
                plVar8[uVar10 * 7 + 6] = plVar8[uVar12 * 7 + 6];
              }
              if (((0x1f < _DAT_181b50ed8 >> 1) && (_DAT_181b50edc <= _DAT_181b50ed8 >> 1)) &&
                 (plVar8 = (longlong *)
                           HeapReAlloc(_DAT_181b2f2e0,0,_DAT_181b50ed0,
                                       (ulonglong)(_DAT_181b50ed8 >> 1) * 0x38),
                 plVar8 != (longlong *)0x0)) {
                _DAT_181b50ed8 = _DAT_181b50ed8 >> 1;
                _DAT_181b50ed0 = plVar8;
              }
            }
            goto LAB_1800959bd;
          }
          break;
        }
        plVar8 = plVar8 + 7;
        uVar10 = (ulonglong)(uVar9 + 1);
      } while (uVar9 + 1 < _DAT_181b50edc);
    }
    uVar11 = 4;
  }
LAB_1800959bd:
  LOCK();
  _DAT_181b2f2d8 = 0;
  UNLOCK();
  return uVar11;
}

