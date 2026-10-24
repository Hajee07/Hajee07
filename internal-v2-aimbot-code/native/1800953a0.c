/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong recovered_1800953a0(uint param_1)

{
  uint uVar1;
  byte *pbVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  int *piVar6;
  ulonglong uVar7;
  uint uVar8;
  int *piStack_18;
  uint uStack_c;
  
  uVar5 = 0;
  if (_DAT_181b50edc != 0) {
    pbVar2 = (byte *)(_DAT_181b50ed0 + 0x20);
    do {
      if ((*pbVar2 >> 1 & 1) != param_1) {
        if (uVar5 == 0xffffffff) {
          return 0;
        }
        uVar3 = recovered_180095090(&piStack_18,0xffffffff,param_1 != 0);
        uVar7 = uVar3 & 0xffffffff;
        if ((int)uVar3 != 0) {
          return uVar3;
        }
        uVar8 = _DAT_181b50edc;
        if (_DAT_181b50edc <= uVar5) goto LAB_18009546c;
        goto LAB_180095430;
      }
      uVar5 = uVar5 + 1;
      pbVar2 = pbVar2 + 0x38;
    } while (uVar5 < _DAT_181b50edc);
  }
  return 0;
LAB_180095430:
  do {
    if ((*(byte *)((ulonglong)uVar5 * 0x38 + 0x20 + _DAT_181b50ed0) >> 1 & 1) != param_1) {
      uVar1 = recovered_180095290(uVar5,param_1);
      uVar7 = (ulonglong)uVar1;
      uVar8 = _DAT_181b50edc;
      if (uVar1 != 0) break;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < uVar8);
LAB_18009546c:
  if (piStack_18 != (int *)0x0) {
    if (uStack_c != 0) {
      uVar3 = (ulonglong)uStack_c;
      piVar6 = piStack_18;
      do {
        if ((*piVar6 != 0) && (lVar4 = OpenThread(0x5a,0), lVar4 != 0)) {
          ResumeThread(lVar4);
          CloseHandle(lVar4);
        }
        piVar6 = piVar6 + 1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    HeapFree(_DAT_181b2f2e0,0,piStack_18);
  }
  return uVar7;
}

