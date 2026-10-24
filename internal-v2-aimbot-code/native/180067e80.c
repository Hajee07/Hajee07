/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * recovered_180067e80(float *param_1,float *param_2,float *param_3,int param_4,int param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  *param_1 = -1.0;
  param_1[1] = -1.0;
  if ((0 < param_4) && (0 < param_5)) {
    fVar1 = *param_3;
    fVar2 = param_3[1];
    fVar3 = param_3[2];
    fVar9 = fVar2 * param_2[7] + fVar1 * param_2[3] + fVar3 * param_2[0xb] + param_2[0xf];
    if (_DAT_181a03124 <= fVar9) {
      fVar4 = param_2[1];
      fVar5 = param_2[5];
      fVar6 = param_2[9];
      fVar8 = (float)param_5 * _DAT_181a031bc;
      fVar7 = param_2[0xd];
      *param_1 = ((fVar2 * param_2[4] + fVar1 * *param_2 + fVar3 * param_2[8] + param_2[0xc]) *
                 (float)param_4 * _DAT_181a031bc) / fVar9 + (float)param_4 * _DAT_181a031bc;
      param_1[1] = fVar8 - ((fVar1 * fVar4 + fVar2 * fVar5 + fVar3 * fVar6 + fVar7) * fVar8) / fVar9
      ;
    }
    return param_1;
  }
  return param_1;
}

