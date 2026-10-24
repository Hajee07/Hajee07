/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 recovered_180069360(undefined8 param_1)

{
  char cVar1;
  undefined8 uVar2;
  undefined4 auStackX_10 [2];
  undefined8 auStackX_18 [2];
  
  auStackX_10[0] = 0;
  cVar1 = recovered_180067cc0(param_1,auStackX_18);
  if (cVar1 != '\0') {
    (*_DAT_181b4ef88)(_DAT_181b4ef90,auStackX_18[0],auStackX_10,4);
    return auStackX_10[0];
  }
  if (_DAT_181b4ef90 == 0) {
    uVar2 = recovered_180069ac0(_cout_std__3V__basic_ostream_DU__char_traits_D_std___1_A_exref,
                                &UNK_1819d77a0);
    __6__basic_ostream_DU__char_traits_D_std___std__QEAAAEAV01_P6AAEAV01_AEAV01__Z_Z
              (uVar2,&DAT_180069ca0);
  }
  return auStackX_10[0];
}

