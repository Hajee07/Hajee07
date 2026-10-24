/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * recovered_180071430(undefined8 *param_1,longlong param_2)

{
  int iVar1;
  undefined8 uStack_18;
  float fStack_10;
  
  iVar1 = *(int *)(param_2 + 0x84);
  if (iVar1 != 0) {
    if (_DAT_181b2b620 == 1) {
      recovered_180071220(&uStack_18,iVar1,_DAT_181a2b128);
      if ((((float)uStack_18 == 0.0) && (uStack_18._4_4_ == 0.0)) && (fStack_10 == 0.0)) {
        if ((((float)*(undefined8 *)(param_2 + 0x100) == 0.0) &&
            (uStack_18._4_4_ = (float)((ulonglong)*(undefined8 *)(param_2 + 0x100) >> 0x20),
            uStack_18._4_4_ == 0.0)) && (*(float *)(param_2 + 0x108) == 0.0)) {
          uStack_18 = 0;
          fStack_10 = 0.0;
        }
        else {
          fStack_10 = *(float *)(param_2 + 0x108);
          uStack_18 = *(undefined8 *)(param_2 + 0x100);
        }
      }
    }
    else {
      recovered_180071220(&uStack_18,iVar1,_DAT_181a2b110);
      if ((((float)uStack_18 == 0.0) && (uStack_18._4_4_ == 0.0)) && (fStack_10 == 0.0)) {
        if ((((float)*(undefined8 *)(param_2 + 0x88) == 0.0) &&
            (uStack_18._4_4_ = (float)((ulonglong)*(undefined8 *)(param_2 + 0x88) >> 0x20),
            uStack_18._4_4_ == 0.0)) && (*(float *)(param_2 + 0x90) == 0.0)) {
          uStack_18 = 0;
          fStack_10 = 0.0;
        }
        else {
          fStack_10 = *(float *)(param_2 + 0x90);
          uStack_18 = *(undefined8 *)(param_2 + 0x88);
        }
      }
    }
    *param_1 = uStack_18;
    *(float *)(param_1 + 1) = fStack_10;
    return param_1;
  }
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  return param_1;
}

