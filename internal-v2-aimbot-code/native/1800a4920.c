/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_1800a4920(undefined4 param_1)

{
  code *pcVar1;
  undefined auStack_38 [56];
  
  func_0x0001800a4870(auStack_38,param_1);
  func_0x0001801ca8c3(auStack_38,&UNK_181a249e0);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

