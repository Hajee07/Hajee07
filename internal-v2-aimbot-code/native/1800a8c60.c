/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined * recovered_1800a8c60(void)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = recovered_1800a8cf0(&UNK_1819d9040);
  if (iVar1 != 0) {
    return &UNK_1819d9040;
  }
  iVar1 = recovered_1800a8cf0(&UNK_1819dbec8);
  if (iVar1 != 0) {
    return &UNK_1819dbec8;
  }
  iVar1 = recovered_1800a8cf0(&UNK_1819dbf78);
  if (iVar1 != 0) {
    return &UNK_1819dbf78;
  }
  iVar1 = recovered_1800a8cf0(&UNK_1819dbfc8);
  if (iVar1 != 0) {
    return &UNK_1819dbfc8;
  }
  puVar2 = (undefined *)recovered_1800a8cf0(&UNK_1819dbe90);
  if ((int)puVar2 != 0) {
    puVar2 = &UNK_1819dbe90;
  }
  return puVar2;
}

