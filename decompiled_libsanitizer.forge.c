
long
Java_com_wakanim_wakanimapp_test_wakanimWebclient_WakanimWebClient_forge
          (long *environment,long param_2,long userId,long forgeKey,long kid,
          long clientId)

{
  long userIdChars;
  long *forgeKeyChars;
  long kidChars;
  long clientIdChars;
  char *__ptr;
  ulong uVar8;
  long *value;
  long local_580 [2];
  byte abStack_570 [176];
  long local_4c0;
  long uStack_4b8;
  long local_4b0;
  long uStack_4a8;
  long local_4a0;
  long uStack_498;
  byte d0c_output [1024];
  long local_78;
  
  local_580[1] = tpidr_el0;
  local_78 = *(long *)(local_580[1] + 0x28);
  userIdChars = environment.GetStringUTFChars(environment,userId,0);
  local_580[0] = forgeKey;
  forgeKeyChars = (long*) environment.GetStringUTFChars(environment,forgeKey,0);
  kidChars = environment.GetStringUTFChars(environment,kid,0);
  clientIdChars = environment.GetStringUTFChars(environment,clientId,0);
  memset(d0c_output,0,0x400);
  byte d0c_format[] = { 0x40, 0x25, 0x73, 0x40, 0x44, 0x65, 0x77, 0x23, 0x40, 0x57, 0x41, 0x4B, 0x40, 0x25, 0x73, 0x40, 0x4E, 0x31, 0x4D, 0x40, 0x25, 0x73 };
  __vsprintf_chk(d0c_output, 0, 0x400, d0c_format, clientIdChars, kidChars, userIdChars);
  environment.ReleaseStringUTFChars(environment,userId,userIdChars);
  environment.ReleaseStringUTFChars(environment,kid,kidChars);
  environment.ReleaseStringUTFChars(environment,clientId,clientIdChars);
  uStack_498 = 0x5934dc1b6219aa20;
  local_4a0 = 0x1834dd4720038404;
  uint d0c_length = __strlen_chk(d0c_output,0x400);
  int requiredPadding = 0;
  if ((int)d0c_length % 0x10 != 0) {
    requiredPadding = 0x10 - (int)d0c_length % 0x10;
  }
  uint paddedLength = requiredPadding + d0c_length;
  value = (long *)((long)local_580 - ((ulong) paddedLength + 0xf & 0x1fffffff0));
  memset(value,0,(long)(int)paddedLength);
  if (0 < (int)d0c_length) {
    memcpy(value,d0c_output,(ulong)d0c_length);
  }
  uStack_4a8 = forgeKeyChars[1];
  local_4b0 = *forgeKeyChars;
  environment.ReleaseStringUTFChars(environment,forgeKey,forgeKeyChars);
  uVar8 = (ulong)(int)d0c_length;
  d0c_length = 0x10 - (d0c_length & 0b1111);
  if (uVar8 + d0c_length <= (ulong) paddedLength) {
    memset((void *)((long)value + uVar8),d0c_length,(ulong)d0c_length);
  }
  FUN_00101c14(abStack_570,(undefined *)&local_4a0);
  uStack_4b8 = uStack_4a8;
  local_4c0 = local_4b0;
  AES_CBC_encrypt_buffer(abStack_570,value,uVar8);
  __ptr = (char *)malloc((long)(int)(((int)(paddedLength + 2) / 3) * 4 | 1));
  Abstract_e(__ptr,(long)value,paddedLength);
  userIdChars = (**(code **)(*environment + 0x538))(environment,__ptr);
  free(__ptr);
  if (*(long *)(local_580[1] + 0x28) == local_78) {
    return userIdChars;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

