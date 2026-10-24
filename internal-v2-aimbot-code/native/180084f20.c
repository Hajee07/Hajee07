/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * recovered_180084f20(float **param_1,float *param_2,int param_3,undefined8 param_4)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float *pfVar4;
  float fVar5;
  float fStack_18;
  float fStack_14;
  
  param_2[1] = 0.0;
  fStack_18 = (float)param_4;
  fStack_14 = (float)((ulonglong)param_4 >> 0x20);
  if (param_3 == 0) {
    pfVar4 = param_1[3];
    fVar5 = (**param_1 - fStack_18) - *param_1[1];
  }
  else {
    if (param_3 != 1) {
      pfVar4 = param_1[7];
      if (param_3 == 2) {
        pfVar3 = param_1[8];
        fVar5 = *param_1[2];
        *param_2 = *pfVar4 - fStack_18 * _DAT_181a031bc;
        fVar1 = *pfVar3;
        *pfVar3 = fStack_14 + _DAT_181a03270 + *pfVar3;
        param_2[1] = (fVar5 - fStack_14) - fVar1;
        return param_2;
      }
      if (param_3 != 3) {
        pfVar3 = param_1[2];
        *param_2 = *pfVar4;
        param_2[1] = *pfVar3;
        return param_2;
      }
      fVar5 = *param_1[9];
      *param_2 = *pfVar4 - fStack_18 * _DAT_181a031bc;
      pfVar4 = param_1[10];
      fVar1 = *param_1[2];
      fVar2 = *pfVar4;
      *pfVar4 = fStack_14 + _DAT_181a03270 + *pfVar4;
      param_2[1] = fVar5 + fVar1 + fVar2;
      return param_2;
    }
    pfVar4 = param_1[6];
    fVar5 = *param_1[4] + **param_1 + *param_1[5];
  }
  fVar1 = *pfVar4;
  pfVar3 = param_1[2];
  *param_2 = fVar5;
  fVar5 = *pfVar3;
  *pfVar4 = fStack_14 + _DAT_181a03270 + fVar1;
  param_2[1] = fVar1 + fVar5;
  return param_2;
}

