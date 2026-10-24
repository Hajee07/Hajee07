/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined4 * recovered_180089b40(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = func_0x000180089860(param_2);
  if (((((iVar1 == 0x135) || (iVar1 == 0x4b5)) || (iVar1 == 0x15e1)) ||
      ((iVar1 - 0x46U < 0x3a &&
       ((0x200000000001c01U >> ((ulonglong)(iVar1 - 0x46U) & 0x3f) & 1) != 0)))) || (iVar1 == 0xb4))
  {
    *param_1 = 0x3f800000;
    param_1[1] = 0x3f59999a;
    param_1[2] = 0x3e4ccccd;
    param_1[3] = 0x3f800000;
    return param_1;
  }
  if (((iVar1 != 0x12f) && (iVar1 != 0x132)) &&
     ((iVar1 != 0x193 &&
      (((0x28 < iVar1 - 0x1f7U ||
        ((0x10000100401U >> ((ulonglong)(iVar1 - 0x1f7U) & 0x3f) & 1) == 0)) && (iVar1 != 0x2bf)))))
     ) {
    if (((iVar1 != 0x12e) && (iVar1 != 0x131)) &&
       (((iVar1 != 0x192 &&
         ((0x28 < iVar1 - 0x1f6U ||
          ((0x10000100401U >> ((ulonglong)(iVar1 - 0x1f6U) & 0x3f) & 1) == 0)))) && (iVar1 != 0x2be)
        ))) {
      if ((((iVar1 != 0x12d) && (iVar1 != 0x130)) && (iVar1 != 0x191)) &&
         (((0x28 < iVar1 - 0x1f5U ||
           ((0x10000100401U >> ((ulonglong)(iVar1 - 0x1f5U) & 0x3f) & 1) == 0)) &&
          ((iVar1 != 0x2bd && (iVar1 != 0x66)))))) {
        if ((iVar1 - 0xc9U < 7) && ((0x5dU >> (iVar1 - 0xc9U & 0x1f) & 1) != 0)) {
          *param_1 = 0x3f4ccccd;
          param_1[1] = 0x3f4ccccd;
          param_1[2] = 0x3f4ccccd;
          param_1[3] = 0x3f800000;
          return param_1;
        }
        *param_1 = 0x3f733333;
        param_1[1] = 0x3f733333;
        param_1[2] = 0x3f733333;
        param_1[3] = 0x3f800000;
        return param_1;
      }
      *param_1 = 0x3eb851ec;
      param_1[1] = 0x3f666666;
      param_1[2] = 0x3eeb851f;
      param_1[3] = 0x3f800000;
      return param_1;
    }
    *param_1 = 0x3e3851ec;
    param_1[1] = 0x3f266666;
    param_1[2] = 0x3f70a3d7;
    param_1[3] = 0x3f800000;
    return param_1;
  }
  *param_1 = 0x3f4f5c29;
  param_1[1] = 0x3ec28f5c;
  param_1[2] = 0x3f70a3d7;
  param_1[3] = 0x3f800000;
  return param_1;
}

