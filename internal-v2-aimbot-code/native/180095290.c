/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 recovered_180095290(ulonglong param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  byte bVar4;
  undefined8 *puVar5;
  undefined4 *puVar6;
  undefined4 auStackX_8 [2];
  
  puVar5 = (undefined8 *)((param_1 & 0xffffffff) * 0x38 + _DAT_181b50ed0);
  puVar6 = (undefined4 *)((longlong)(undefined4 *)*puVar5 + -5);
  if ((*(byte *)(puVar5 + 4) & 1) == 0) {
    puVar6 = (undefined4 *)*puVar5;
  }
  cVar1 = (*(byte *)(puVar5 + 4) & 1) * '\x02' + '\x05';
  iVar2 = VirtualProtect(puVar6,cVar1,0x40,auStackX_8);
  if (iVar2 == 0) {
    uVar3 = 10;
  }
  else {
    if (param_2 == 0) {
      bVar4 = *(byte *)(puVar5 + 4);
      *puVar6 = *(undefined4 *)(puVar5 + 3);
      if ((bVar4 & 1) == 0) {
        *(undefined *)(puVar6 + 1) = *(undefined *)((longlong)puVar5 + 0x1c);
      }
      else {
        *(undefined2 *)(puVar6 + 1) = *(undefined2 *)((longlong)puVar5 + 0x1c);
        *(undefined *)((longlong)puVar6 + 6) = *(undefined *)((longlong)puVar5 + 0x1e);
      }
    }
    else {
      *(undefined *)puVar6 = 0xe9;
      *(int *)((longlong)puVar6 + 1) = (*(int *)(puVar5 + 1) - (int)puVar6) + -5;
      if ((*(byte *)(puVar5 + 4) & 1) != 0) {
        *(undefined2 *)*puVar5 = 0xf9eb;
      }
    }
    VirtualProtect(puVar6,cVar1,auStackX_8[0],auStackX_8);
    uVar3 = GetCurrentProcess();
    FlushInstructionCache(uVar3,puVar6,cVar1);
    bVar4 = ((char)param_2 * '\x02' ^ *(byte *)(puVar5 + 4)) & 2 ^ *(byte *)(puVar5 + 4);
    *(byte *)(puVar5 + 4) = ((char)param_2 << 2 ^ bVar4) & 4 ^ bVar4;
    uVar3 = 0;
  }
  return uVar3;
}

