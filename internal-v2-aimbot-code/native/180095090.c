/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 recovered_180095090(longlong *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  uint auStack_38 [2];
  int iStack_30;
  int iStack_2c;
  ulonglong uVar7;
  
  uVar7 = 0;
  *param_1 = 0;
  param_1[1] = 0;
  bVar1 = false;
  lVar4 = CreateToolhelp32Snapshot(4,0);
  if (lVar4 != -1) {
    auStack_38[0] = 0x1c;
    iVar3 = Thread32First(lVar4,auStack_38);
    if (iVar3 != 0) {
      bVar1 = true;
      do {
        if (((0xf < auStack_38[0]) && (iVar3 = GetCurrentProcessId(), iStack_2c == iVar3)) &&
           (iVar3 = GetCurrentThreadId(), uVar2 = _DAT_181b2f2e0, iStack_30 != iVar3)) {
          lVar5 = *param_1;
          if (lVar5 == 0) {
            *(undefined4 *)(param_1 + 1) = 0x80;
            lVar5 = HeapAlloc(uVar2,0,0x200);
            *param_1 = lVar5;
            if (lVar5 == 0) goto LAB_1800951bc;
          }
          else if (*(uint *)(param_1 + 1) <= *(uint *)((longlong)param_1 + 0xc)) {
            uVar6 = *(uint *)(param_1 + 1) * 2;
            *(uint *)(param_1 + 1) = uVar6;
            lVar5 = HeapReAlloc(uVar2,0,lVar5,(ulonglong)uVar6 << 2);
            if (lVar5 == 0) goto LAB_1800951bc;
            *param_1 = lVar5;
          }
          uVar6 = *(uint *)((longlong)param_1 + 0xc);
          *(int *)(lVar5 + (ulonglong)uVar6 * 4) = iStack_30;
          *(uint *)((longlong)param_1 + 0xc) = uVar6 + 1;
        }
        auStack_38[0] = 0x1c;
        iVar3 = Thread32Next(lVar4,auStack_38);
      } while (iVar3 != 0);
      iVar3 = GetLastError();
      if (iVar3 != 0x12) {
LAB_1800951bc:
        bVar1 = false;
        if (*param_1 != 0) {
          HeapFree(_DAT_181b2f2e0,0);
          *param_1 = 0;
        }
      }
    }
    CloseHandle(lVar4);
    if (bVar1) {
      if (*param_1 == 0) {
        return 0;
      }
      if (*(int *)((longlong)param_1 + 0xc) == 0) {
        return 0;
      }
      do {
        lVar4 = OpenThread(0x5a,0,*(undefined4 *)(uVar7 * 4 + *param_1));
        if (lVar4 == 0) {
LAB_180095253:
          *(undefined4 *)(uVar7 * 4 + *param_1) = 0;
        }
        else {
          iVar3 = SuspendThread(lVar4);
          if (iVar3 == -1) {
            CloseHandle(lVar4);
            goto LAB_180095253;
          }
          func_0x000180094f00(lVar4,param_2,param_3);
          CloseHandle(lVar4);
        }
        uVar6 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar6;
        if (*(uint *)((longlong)param_1 + 0xc) <= uVar6) {
          return 0;
        }
      } while( true );
    }
  }
  return 9;
}

