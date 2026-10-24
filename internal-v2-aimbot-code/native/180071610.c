/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined8 recovered_180071610(longlong param_1,int param_2)

{
  undefined8 *puVar1;
  float fStack_24;
  undefined auStack_18 [24];
  
  if (((((*(int *)(param_1 + 0x84) != 0) && (*(int *)(param_1 + 0x84) != param_2)) &&
       (*(char *)(param_1 + 1) != '\0')) &&
      ((*(char *)(param_1 + 2) == '\0' && (*(int *)(param_1 + 0x18) != 0)))) &&
     ((DAT_181b2b406 == '\0' || (*(char *)(param_1 + 3) == '\0')))) {
    puVar1 = (undefined8 *)recovered_180071430(auStack_18,param_1);
    if ((((float)*puVar1 != 0.0) ||
        (fStack_24 = (float)((ulonglong)*puVar1 >> 0x20), fStack_24 != 0.0)) ||
       (*(float *)(puVar1 + 1) != 0.0)) {
      return 1;
    }
  }
  return 0;
}

