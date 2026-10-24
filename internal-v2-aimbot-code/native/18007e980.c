/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong recovered_18007e980(longlong param_1,longlong param_2)

{
  recovered_1800785e0();
  recovered_1800785e0(param_1 + 0x20,param_2 + 0x20);
  *(undefined *)(param_1 + 0x40) = *(undefined *)(param_2 + 0x40);
  *(undefined *)(param_1 + 0x41) = *(undefined *)(param_2 + 0x41);
  *(undefined *)(param_1 + 0x42) = *(undefined *)(param_2 + 0x42);
  return param_1;
}

