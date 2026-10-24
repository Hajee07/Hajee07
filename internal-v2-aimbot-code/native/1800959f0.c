/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int recovered_1800959f0(longlong param_1,uint param_2)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  int *piVar6;
  ulonglong uVar7;
  bool bVar8;
  int *piStack_18;
  uint uStack_c;
  
  uVar7 = 0;
  LOCK();
  bVar8 = _DAT_181b2f2d8 == 0;
  if (bVar8) {
    _DAT_181b2f2d8 = 1;
  }
  UNLOCK();
  uVar5 = uVar7;
  while (!bVar8) {
    Sleep(0x1f < uVar5);
    uVar5 = uVar5 + 1;
    LOCK();
    bVar8 = _DAT_181b2f2d8 == 0;
    if (bVar8) {
      _DAT_181b2f2d8 = 1;
    }
    UNLOCK();
  }
  if (_DAT_181b2f2e0 == 0) {
    iVar1 = 2;
  }
  else if (param_1 == 0) {
    iVar1 = recovered_1800953a0(param_2);
  }
  else {
    plVar2 = _DAT_181b50ed0;
    if (_DAT_181b50edc != 0) {
      do {
        if (param_1 == *plVar2) {
          if ((int)uVar7 != -1) {
            if ((*(byte *)(_DAT_181b50ed0 + uVar7 * 7 + 4) >> 1 & 1) == param_2) {
              iVar1 = 6 - (uint)(param_2 != 0);
            }
            else {
              iVar1 = recovered_180095090(&piStack_18,uVar7,1);
              if ((iVar1 == 0) &&
                 (iVar1 = recovered_180095290(uVar7,param_2), piStack_18 != (int *)0x0)) {
                if (uStack_c != 0) {
                  uVar7 = (ulonglong)uStack_c;
                  piVar6 = piStack_18;
                  do {
                    if ((*piVar6 != 0) && (lVar3 = OpenThread(0x5a,0), lVar3 != 0)) {
                      ResumeThread(lVar3);
                      CloseHandle(lVar3);
                    }
                    piVar6 = piVar6 + 1;
                    uVar7 = uVar7 - 1;
                  } while (uVar7 != 0);
                }
                HeapFree(_DAT_181b2f2e0,0,piStack_18);
              }
            }
            goto LAB_180095b4d;
          }
          break;
        }
        uVar4 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar4;
        plVar2 = plVar2 + 7;
      } while (uVar4 < _DAT_181b50edc);
    }
    iVar1 = 4;
  }
LAB_180095b4d:
  LOCK();
  _DAT_181b2f2d8 = 0;
  UNLOCK();
  return iVar1;
}

