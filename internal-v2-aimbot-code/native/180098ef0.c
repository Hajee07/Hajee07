/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_180098ef0(void)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  undefined4 auStack_908 [2];
  undefined4 uStack_900;
  short asStack_8dc [266];
  undefined4 auStack_6c8 [2];
  undefined4 uStack_6c0;
  short asStack_69c [266];
  undefined4 auStack_488 [2];
  uint uStack_480;
  short asStack_45c [266];
  undefined4 auStack_248 [2];
  undefined4 uStack_240;
  short asStack_21c [266];
  
  uVar6 = 0;
  uVar7 = 0;
  lVar2 = CreateToolhelp32Snapshot(2,0);
  if (lVar2 != -1) {
    auStack_908[0] = 0x238;
    iVar1 = Process32FirstW(lVar2,auStack_908);
    while (uVar4 = uVar6, uVar7 = 0, iVar1 != 0) {
      while (uVar3 = uVar4 + 1, asStack_8dc[uVar4] == *(short *)(&UNK_1819d8e6e + uVar3 * 2)) {
        uVar4 = uVar3;
        uVar7 = uStack_900;
        if (uVar3 == 8) goto LAB_180098f7c;
      }
      iVar1 = Process32NextW(lVar2,auStack_908);
    }
LAB_180098f7c:
    CloseHandle(lVar2);
  }
  lVar2 = OpenProcess(1,0,uVar7);
  if (lVar2 != 0) {
    TerminateProcess(lVar2,0);
    CloseHandle(lVar2);
  }
  lVar2 = CreateToolhelp32Snapshot(2,0);
  if (lVar2 != -1) {
    auStack_6c8[0] = 0x238;
    iVar1 = Process32FirstW(lVar2,auStack_6c8);
    while (uVar4 = uVar6, iVar1 != 0) {
      while (uVar3 = uVar4 + 1, asStack_69c[uVar4] == *(short *)(&UNK_1819d8e6e + uVar3 * 2)) {
        uVar4 = uVar3;
        if (uVar3 == 8) {
          CloseHandle(lVar2);
          func_0x000180099d20(uStack_6c0);
          goto LAB_180099066;
        }
      }
      iVar1 = Process32NextW(lVar2,auStack_6c8);
    }
    CloseHandle(lVar2);
  }
LAB_180099066:
  lVar2 = CreateToolhelp32Snapshot(2,0);
  if (lVar2 != -1) {
    auStack_488[0] = 0x238;
    iVar1 = Process32FirstW(lVar2,auStack_488);
    while (iVar1 != 0) {
      lVar5 = -1;
      do {
        if (asStack_45c[lVar5 + 1] != *(short *)(&UNK_1819d8e82 + lVar5 * 2)) break;
        lVar5 = lVar5 + 2;
        if (lVar5 == 0xb) {
          uVar6 = (ulonglong)uStack_480;
          goto LAB_1800990ff;
        }
      } while (asStack_45c[lVar5] == *(short *)(&UNK_1819d8e80 + lVar5 * 2));
      iVar1 = Process32NextW(lVar2,auStack_488);
    }
LAB_1800990ff:
    CloseHandle(lVar2);
  }
  lVar2 = OpenProcess(1,0,uVar6);
  if (lVar2 != 0) {
    TerminateProcess(lVar2,0);
    CloseHandle(lVar2);
  }
  lVar2 = CreateToolhelp32Snapshot(2,0);
  if (lVar2 != -1) {
    auStack_248[0] = 0x238;
    iVar1 = Process32FirstW(lVar2,auStack_248);
    while (iVar1 != 0) {
      lVar5 = -1;
      do {
        if (asStack_21c[lVar5 + 1] != *(short *)(&UNK_1819d8e82 + lVar5 * 2)) break;
        lVar5 = lVar5 + 2;
        if (lVar5 == 0xb) {
          CloseHandle(lVar2);
          func_0x000180099d20(uStack_240);
          return;
        }
      } while (asStack_21c[lVar5] == *(short *)(&UNK_1819d8e80 + lVar5 * 2));
      iVar1 = Process32NextW(lVar2,auStack_248);
    }
    CloseHandle(lVar2);
  }
  return;
}

