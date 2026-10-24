/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined8 * recovered_18009b020(undefined8 *param_1,undefined8 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined4 auStack_248 [2];
  undefined4 auStack_240 [9];
  short asStack_21c [266];
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  lVar3 = CreateToolhelp32Snapshot(2,0);
  if (lVar3 != -1) {
    auStack_248[0] = 0x238;
    iVar2 = Process32FirstW(lVar3,auStack_248);
    while (iVar2 != 0) {
      lVar4 = -1;
      do {
        lVar4 = lVar4 + 1;
      } while (asStack_21c[lVar4] != 0);
      puVar5 = param_2;
      if (7 < (ulonglong)param_2[3]) {
        puVar5 = (undefined8 *)*param_2;
      }
      if ((param_2[2] == lVar4) &&
         ((param_2[2] == 0 || (iVar2 = func_0x00018009ae70(puVar5,asStack_21c), iVar2 == 0)))) {
        puVar1 = (undefined4 *)param_1[1];
        if (puVar1 == (undefined4 *)param_1[2]) {
          recovered_18007a050(param_1,puVar1,auStack_240);
        }
        else {
          *puVar1 = auStack_240[0];
          param_1[1] = param_1[1] + 4;
        }
      }
      iVar2 = Process32NextW(lVar3,auStack_248);
    }
    CloseHandle(lVar3);
  }
  return param_1;
}

