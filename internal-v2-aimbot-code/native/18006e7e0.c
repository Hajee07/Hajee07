/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


ulonglong recovered_18006e7e0(uint param_1)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  
  uVar5 = (ulonglong)param_1;
  if (param_1 == 0) {
    return 0;
  }
  uVar2 = func_0x00018006e5f0(uVar5);
  uVar4 = recovered_180069360(uVar5 + 0x434);
  uVar3 = func_0x00018006e440(uVar4);
  if (uVar2 == 0) {
    uVar4 = recovered_180069360(uVar5 + 0x3f8);
    uVar2 = func_0x00018006e440(uVar4);
    uVar5 = (ulonglong)uVar2;
    if (uVar3 == 0) {
      return uVar5;
    }
  }
  else {
    if (((uVar3 == 0) || (cVar1 = func_0x00018006e8c0(uVar2), cVar1 != '\0')) ||
       (cVar1 = func_0x00018006e8c0(uVar3), cVar1 == '\0')) {
      uVar3 = uVar2;
    }
    uVar4 = recovered_180069360(uVar5 + 0x3f8);
    uVar2 = func_0x00018006e440(uVar4);
    uVar5 = (ulonglong)uVar2;
  }
  if ((short)uVar5 != 0) {
    cVar1 = func_0x00018006e8c0(uVar3);
    uVar2 = (ushort)uVar5;
    if ((cVar1 == '\0') && (cVar1 = func_0x00018006e8c0(uVar5 & 0xffff), cVar1 != '\0')) {
      uVar3 = uVar2;
    }
  }
  return (ulonglong)uVar3;
}

