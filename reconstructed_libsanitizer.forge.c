
long
WakanimWebClient_forge
          (long* environment, undefined8 wakanimWebClientClass,undefined8 param_3,long param_4,undefined8 param_5,
          undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  char *__ptr;
  ulong uVar8;
  undefined8 *__s;
  long local_580 [2];
  byte abStack_570 [176];
  undefined8 local_4c0;
  undefined8 uStack_4b8;
  undefined8 local_4b0;
  undefined8 uStack_4a8;
  undefined8 local_4a0;
  undefined8 uStack_498;
  undefined local_490;
  undefined7 uStack_48f;
  undefined uStack_488;
  undefined6 uStack_487;
  undefined uStack_481;
  undefined uStack_480;
  undefined uStack_47f;
  undefined uStack_47e;
  undefined uStack_47d;
  undefined uStack_47c;
  undefined uStack_47b;
  undefined uStack_47a;
  undefined auStack_478 [1024];
  long local_78;
  
  local_580[1] = tpidr_el0;
  local_78 = *(long *)(local_580[1] + 0x28);
  uVar4 = (**(code **)(*environment + 0x548))(environment,param_3,0);
  local_580[0] = param_4;
  puVar5 = (undefined8 *)(**(code **)(*environment + 0x548))(environment,param_4,0);
  uVar6 = (**(code **)(*environment + 0x548))(environment,param_5,0);
  uVar7 = (**(code **)(*environment + 0x548))(environment,param_6,0);
  memset(auStack_478,0,0x400);
  local_490 = 0x40;
  uStack_48f = 0x23776544407325;
  uStack_488 = 0x40;
  uStack_487 = 0x7325404b4157;
  uStack_481 = 0x40;
  uStack_480 = 0x4e;
  uStack_47f = 0x31;
  uStack_47e = 0x4d;
  uStack_47d = 0x40;
  uStack_47c = 0x25;
  uStack_47b = 0x73;
  uStack_47a = 0;
  FUN_00103d0c(auStack_478,0x400,&local_490,uVar7,uVar6,uVar4,param_7,param_8);
  (**(code **)(*environment + 0x550))(environment,param_3,uVar4);
  (**(code **)(*environment + 0x550))(environment,param_5,uVar6);
  (**(code **)(*environment + 0x550))(environment,param_6,uVar7);
  uStack_498 = 0x5934dc1b6219aa20;
  local_4a0 = 0x1834dd4720038404;
  uVar3 = __strlen_chk(auStack_478,0x400);
  iVar2 = 0;
  if ((int)uVar3 % 0x10 != 0) {
    iVar2 = 0x10 - (int)uVar3 % 0x10;
  }
  uVar1 = iVar2 + uVar3;
  __s = (undefined8 *)((long)local_580 - ((ulong)uVar1 + 0xf & 0x1fffffff0));
  memset(__s,0,(long)(int)uVar1);
  if (0 < (int)uVar3) {
    memcpy(__s,auStack_478,(ulong)uVar3);
  }
  uStack_4a8 = puVar5[1];
  local_4b0 = *puVar5;
  (**(code **)(*environment + 0x550))(environment,local_580[0],puVar5);
  uVar8 = (ulong)(int)uVar3;
  uVar3 = 0x10 - (uVar3 & 0xf);
  if (uVar8 + uVar3 <= (ulong)uVar1) {
    memset((void *)((long)__s + uVar8),uVar3,(ulong)uVar3);
  }
  FUN_00101c14(abStack_570,(undefined *)&local_4a0);
  uStack_4b8 = uStack_4a8;
  local_4c0 = local_4b0;
  AES_CBC_encrypt_buffer(abStack_570,__s,uVar8);
  __ptr = (char *)malloc((long)(int)(((int)(uVar1 + 2) / 3) * 4 | 1));
  Abstract_e(__ptr,(long)__s,uVar1);
  uVar4 = (**(code **)(*environment + 0x538))(environment,__ptr);
  free(__ptr);
  if (*(long *)(local_580[1] + 0x28) == local_78) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

