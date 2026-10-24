/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined4 recovered_1800a8cf0(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 auStack_458 [2];
  undefined4 uStack_450;
  uint uStack_43c;
  undefined auStack_42c [532];
  undefined auStack_218 [528];
  
  if (param_1 == 0) {
    return 0;
  }
  MultiByteToWideChar(0xfde9,0,param_1,0xffffffff,auStack_218,0x104);
  uVar4 = 0;
  uVar3 = 0;
  uVar2 = CreateToolhelp32Snapshot(2,0);
  auStack_458[0] = 0x238;
  Process32FirstW(uVar2,auStack_458);
  do {
    iVar1 = _wcsicmp(auStack_42c,auStack_218);
    if ((iVar1 == 0) && (uVar3 < uStack_43c)) {
      uVar3 = uStack_43c;
      uVar4 = uStack_450;
    }
    iVar1 = Process32NextW(uVar2,auStack_458);
  } while (iVar1 != 0);
  return uVar4;
}

