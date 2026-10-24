/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * recovered_180071220(undefined8 *param_1,ulonglong param_2,longlong param_3)

{
  char cVar1;
  int iVar2;
  int aiStackX_10 [2];
  undefined4 uStackX_18;
  undefined4 uStackX_1c;
  undefined8 uStackX_20;
  undefined8 uStack_28;
  float fStack_20;
  
  aiStackX_10[0] = 0;
  cVar1 = recovered_180067cc0((param_2 & 0xffffffff) + param_3,&uStackX_18);
  if (((cVar1 != '\0') &&
      (iVar2 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,uStackX_18),aiStackX_10,4),
      iVar2 == 0)) && (aiStackX_10[0] != 0)) {
    uStack_28 = 0;
    fStack_20 = 0.0;
    cVar1 = recovered_180067cc0(aiStackX_10[0] + 8,&uStackX_20);
    if ((((cVar1 != '\0') &&
         (iVar2 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_20,&uStackX_18,4), iVar2 == 0)) &&
        (cVar1 = recovered_18006bd40(uStackX_18,&uStack_28), cVar1 != '\0')) &&
       ((((float)uStack_28 != 0.0 || (uStack_28._4_4_ != 0.0)) || (fStack_20 != 0.0)))) {
      *param_1 = uStack_28;
      *(float *)(param_1 + 1) = fStack_20;
      return param_1;
    }
  }
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  return param_1;
}

