/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180085390(int **param_1,float *param_2,float *param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  float fVar6;
  float fStackX_10;
  float fStackX_14;
  float fStackX_20;
  float fStackX_24;
  
  if ((((*param_2 != 0.0) || (param_2[1] != 0.0)) || (param_2[2] != 0.0)) &&
     (((*param_3 != 0.0 || (param_3[1] != 0.0)) || (param_3[2] != 0.0)))) {
    iVar1 = *param_1[1];
    iVar5 = **param_1;
    recovered_180067e80(&fStackX_10,&DAT_181b2be70,param_2,iVar5,iVar1);
    recovered_180067e80(&fStackX_20,&DAT_181b2be70,param_3);
    fVar3 = fStackX_14;
    fVar2 = fStackX_10;
    if (((_DAT_181a03230 <= fStackX_10) && (_DAT_181a03230 <= fStackX_14)) &&
       ((_DAT_181a03230 <= fStackX_20 &&
        ((((_DAT_181a03230 <= fStackX_24 && (fStackX_10 <= (float)iVar5)) &&
          (fVar6 = (float)iVar1, fStackX_14 <= fVar6)) &&
         ((fStackX_20 <= (float)iVar5 && (fStackX_24 <= fVar6)))))))) {
      uVar4 = func_0x000180004f90(param_1[3]);
      fStackX_10 = fStackX_20;
      fStackX_14 = fStackX_24;
      fStackX_20 = fVar2;
      fStackX_24 = fVar3;
      func_0x000180027b00(*(undefined8 *)param_1[2],&fStackX_20,&fStackX_10,uVar4,_DAT_181a03240);
    }
  }
  return;
}

