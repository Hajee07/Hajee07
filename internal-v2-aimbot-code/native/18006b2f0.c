/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


int recovered_18006b2f0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong *puVar2;
  undefined8 uStackX_20;
  
  uStackX_20 = param_4;
  puVar2 = (ulonglong *)func_0x000180002450();
  iVar1 = __stdio_common_vsprintf(*puVar2 | 2,param_1,param_2,param_3,0,&uStackX_20);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}

