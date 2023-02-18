undefined8
Java_com_wakanim_wakanimapp_test_wakanimWebclient_WakanimWebClient_process
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,long *param_9,
          undefined8 param_10,long param_11,undefined8 param_12,long param_13)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  char *__s1;
  undefined8 uVar9;
  char *__s1_00;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  long lVar16;
  long lVar17;
  int iVar18;
  long in_FS_OFFSET;
  bool bVar19;
  undefined in_stack_fffffffffffffd18;
  undefined local_278 [16];
  undefined local_268 [16];
  undefined local_258 [16];
  undefined local_248 [16];
  undefined local_238 [16];
  undefined local_228 [16];
  undefined4 local_218;
  undefined local_208 [16];
  undefined local_1f8 [16];
  undefined local_1e8 [16];
  undefined local_1d8 [16];
  undefined local_1c8 [16];
  undefined local_1b8 [16];
  undefined4 local_1a8;
  undefined local_198 [16];
  undefined local_188 [16];
  undefined local_178 [16];
  undefined local_168 [16];
  undefined local_158 [16];
  undefined local_148 [16];
  undefined4 local_138;
  undefined4 local_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined local_118 [16];
  undefined local_108 [16];
  undefined local_f8 [16];
  undefined local_e8 [16];
  undefined local_d8 [16];
  undefined local_c8 [16];
  undefined4 local_b8;
  undefined local_a8 [16];
  undefined local_98 [16];
  undefined local_88 [16];
  undefined local_78 [16];
  undefined local_68 [16];
  undefined local_58 [16];
  undefined4 local_48;
  long local_38;
  
  local_38 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_13 == 0) {
    uVar7 = 1;
  }
  else {
    uVar6 = (**(code **)(*param_9 + 0x30))(param_9,"java/net/URLConnection");
    uVar7 = (**(code **)(*param_9 + 0x108))(param_9,uVar6,"getURL","()Ljava/net/URL;");
    uVar7 = (**(code **)(*param_9 + 0x110))(param_9,param_12,uVar7);
    uVar8 = (**(code **)(*param_9 + 0xf8))(param_9,uVar7);
    uVar8 = (**(code **)(*param_9 + 0x108))(param_9,uVar8,"getHost","()Ljava/lang/String;");
    uVar7 = (**(code **)(*param_9 + 0x110))(param_9,uVar7,uVar8);
    __s1 = (char *)(**(code **)(*param_9 + 0x548))(param_9,uVar7,0);
    local_58 = ZEXT816(0);
    local_68 = ZEXT816(0);
    local_78 = ZEXT816(0);
    local_88 = ZEXT816(0);
    local_98 = ZEXT816(0);
    local_a8 = ZEXT816(0);
    local_48 = 0;
    Abstract_d(local_a8,(byte *)"YWNjb3VudC53YWthbmltLnR2");
    iVar3 = strcmp(__s1,local_a8);
    if (iVar3 == 0) {
      uVar8 = (**(code **)(*param_9 + 0xf8))(param_9,param_12);
      uVar9 = (**(code **)(*param_9 + 0xf8))(param_9,uVar8);
      uVar9 = (**(code **)(*param_9 + 0x108))(param_9,uVar9,"getName","()Ljava/lang/String;");
      bVar19 = false;
      uVar9 = (**(code **)(*param_9 + 0x110))(param_9,uVar8,uVar9);
      __s1_00 = (char *)(**(code **)(*param_9 + 0x548))(param_9,uVar9,0);
      iVar3 = strcmp(__s1_00,"com.android.okhttp.internal.http.HttpsURLConnectionImpl");
      if (iVar3 != 0) {
        iVar3 = strcmp(__s1_00,"com.android.okhttp.internal.huc.HttpsURLConnectionImpl");
        bVar19 = iVar3 != 0;
      }
      (**(code **)(*param_9 + 0x550))(param_9,uVar9,__s1_00);
      uVar9 = (**(code **)(*param_9 + 0x30))(param_9,"java/security/MessageDigest");
      uVar10 = (**(code **)(*param_9 + 0x388))
                         (param_9,uVar9,"getInstance",
                          "(Ljava/lang/String;)Ljava/security/MessageDigest;");
      uVar11 = (**(code **)(*param_9 + 0x108))(param_9,uVar9,"update","([BII)V");
      uVar12 = (**(code **)(*param_9 + 0x108))(param_9,uVar9,"digest",&DAT_00100e8d);
      uVar13 = (**(code **)(*param_9 + 0x538))(param_9,"SHA-256");
      uVar9 = (**(code **)(*param_9 + 0x390))(param_9,uVar9,uVar10,uVar13);
      uVar8 = (**(code **)(*param_9 + 0x108))
                        (param_9,uVar8,"getServerCertificates","()[Ljava/security/cert/Certificate;"
                        );
      uVar8 = (**(code **)(*param_9 + 0x110))(param_9,param_12,uVar8);
      uVar10 = (**(code **)(*param_9 + 0x30))(param_9,"java/util/Arrays");
      uVar4 = (**(code **)(*param_9 + 0x558))(param_9,uVar8);
      uVar13 = (**(code **)(*param_9 + 0x30))(param_9,"java/security/cert/X509Certificate");
      uVar13 = (**(code **)(*param_9 + 0x560))(param_9,0,uVar13,0);
      uVar13 = (**(code **)(*param_9 + 0xf8))(param_9,uVar13);
      uVar14 = (**(code **)(*param_9 + 0x388))
                         (param_9,uVar10,"copyOf",
                          "([Ljava/lang/Object;ILjava/lang/Class;)[Ljava/lang/Object;");
      uVar8 = (**(code **)(*param_9 + 0x390))(param_9,uVar10,uVar14,uVar8,uVar4,uVar13);
      uVar10 = (**(code **)(*param_9 + 0xf8))(param_9,param_13);
      uVar10 = (**(code **)(*param_9 + 0x108))
                         (param_9,uVar10,"checkServerTrusted",
                          "([Ljava/security/cert/X509Certificate;Ljava/lang/String;Ljava/lang/String ;)Ljava/util/List;"
                         );
      uVar13 = (**(code **)(*param_9 + 0x538))(param_9,&DAT_00101046);
      uVar8 = (**(code **)(*param_9 + 0x110))(param_9,param_13,uVar10,uVar8,uVar13,uVar7);
      (**(code **)(*param_9 + 0x550))(param_9,uVar7,__s1);
      cVar2 = (**(code **)(*param_9 + 0x720))(param_9);
      uVar7 = 3;
      if (cVar2 == '\0') {
        uVar7 = (**(code **)(*param_9 + 0xf8))(param_9,uVar8);
        uVar10 = (**(code **)(*param_9 + 0x108))(param_9,uVar7,&DAT_00101014,&DAT_001012ce);
        uVar13 = (**(code **)(*param_9 + 0x108))
                           (param_9,uVar7,&DAT_00100db9,"(I)Ljava/lang/Object;");
        uVar7 = (**(code **)(*param_9 + 0x30))(param_9,"java/security/cert/Certificate");
        uVar14 = (**(code **)(*param_9 + 0x108))
                           (param_9,uVar7,"getPublicKey","()Ljava/security/PublicKey;");
        uVar7 = (**(code **)(*param_9 + 0x30))(param_9,"java/security/PublicKey");
        uVar15 = (**(code **)(*param_9 + 0x108))(param_9,uVar7,"getEncoded",&DAT_00100e8d);
        iVar3 = (**(code **)(*param_9 + 0x188))(param_9,uVar8,uVar10);
        uVar7 = 5;
        if (0 < iVar3) {
          bVar1 = false;
          iVar18 = 0;
          do {
            uVar7 = (**(code **)(*param_9 + 0x110))(param_9,uVar8,uVar13,iVar18);
            uVar7 = (**(code **)(*param_9 + 0x110))(param_9,uVar7,uVar14);
            uVar7 = (**(code **)(*param_9 + 0x110))(param_9,uVar7,uVar15);
            uVar4 = (**(code **)(*param_9 + 0x558))(param_9,uVar7);
            (**(code **)(*param_9 + 0x1e8))(param_9,uVar9,uVar11,uVar7,0,uVar4);
            uVar7 = (**(code **)(*param_9 + 0x110))(param_9,uVar9,uVar12);
            iVar5 = (**(code **)(*param_9 + 0x558))(param_9,uVar7);
            if (iVar5 != 0x20) break;
            lVar16 = (**(code **)(*param_9 + 0x5c0))(param_9,uVar7,0);
            lVar17 = 3;
            do {
              if (((((&UNK_0010134d)[lVar17] != *(char *)(lVar16 + -3 + lVar17)) ||
                   ((&UNK_0010134e)[lVar17] != *(char *)(lVar16 + -2 + lVar17))) ||
                  ((&UNK_0010134f)[lVar17] != *(char *)(lVar16 + -1 + lVar17))) ||
                 ((&DAT_00101350)[lVar17] != *(char *)(lVar16 + lVar17))) goto LAB_00103510;
              lVar17 = lVar17 + 4;
            } while (lVar17 != 0x23);
            bVar1 = true;
LAB_00103510:
            (**(code **)(*param_9 + 0x600))(param_9,uVar7,lVar16,0);
            iVar18 = iVar18 + 1;
          } while (iVar18 < iVar3);
          uVar7 = 5;
          if ((bVar1) && (uVar7 = 0, !(bool)(param_11 == 0 | bVar19))) {
            uVar7 = (**(code **)(*param_9 + 0x30))
                              (param_9,"com/wakanim/wakanimapp/test/WakanimAndroidApplication");
            lVar16 = (**(code **)(*param_9 + 0x480))
                               (param_9,uVar7,"FirebaseUID","Ljava/lang/String;");
            if (lVar16 == 0) {
              uVar7 = 6;
            }
            else {
              uVar7 = (**(code **)(*param_9 + 0x488))(param_9,uVar7,lVar16);
              uVar8 = (**(code **)(*param_9 + 0x30))
                                (param_9,
                                 "com/wakanim/wakanimapp/test/wakanimWebclient/WakanimWebClient");
              lVar16 = (**(code **)(*param_9 + 0x480))
                                 (param_9,uVar8,"SecurityStoreUID","Ljava/lang/String;");
              if (lVar16 == 0) {
                uVar7 = 7;
              }
              else {
                uVar8 = (**(code **)(*param_9 + 0x488))(param_9,uVar8,lVar16);
                uVar9 = (**(code **)(*param_9 + 0x30))
                                  (param_9,"com/wakanim/wakanimapp/test/WakanimActivity");
                lVar16 = (**(code **)(*param_9 + 0x480))
                                   (param_9,uVar9,"ActivityMetric","Ljava/lang/String;");
                if (lVar16 == 0) {
                  uVar7 = 8;
                }
                else {
                  uVar10 = (**(code **)(*param_9 + 0x488))(param_9,uVar9,lVar16);
                  uVar11 = (**(code **)(*param_9 + 0x548))(param_9,uVar7,0);
                  uVar12 = (**(code **)(*param_9 + 0x548))(param_9,uVar8,0);
                  uVar13 = (**(code **)(*param_9 + 0x548))(param_9,uVar10,0);
                  local_c8 = ZEXT816(0);
                  local_d8 = ZEXT816(0);
                  local_e8 = ZEXT816(0);
                  local_f8 = ZEXT816(0);
                  local_108 = ZEXT816(0);
                  local_118 = ZEXT816(0);
                  local_b8 = 0;
                  uVar9 = uVar13;
                  FUN_00103e00(0,param_2,param_3,param_4,param_5,param_6,param_7,param_8,local_118,
                               100,"%s%s%s",uVar11,uVar12,uVar13,in_stack_fffffffffffffd18);
                  (**(code **)(*param_9 + 0x550))(param_9,uVar7,uVar11);
                  (**(code **)(*param_9 + 0x550))(param_9,uVar8,uVar12);
                  (**(code **)(*param_9 + 0x550))(param_9,uVar10,uVar13);
                  local_128 = 0x22058230;
                  uStack_124 = 0x8060d36;
                  uStack_120 = 0x8658862a;
                  uStack_11c = 0x1010df7;
                  uVar7 = (**(code **)(*param_9 + 0x580))(param_9,0x10);
                  (**(code **)(*param_9 + 0x680))(param_9,uVar7,0,0x10,&local_128);
                  uVar8 = (**(code **)(*param_9 + 0x30))(param_9,"javax/crypto/spec/SecretKeySpec");
                  uVar10 = (**(code **)(*param_9 + 0x108))
                                     (param_9,uVar8,"<init>","([BLjava/lang/String;)V");
                  uVar11 = (**(code **)(*param_9 + 0x538))(param_9,&DAT_00100ff9);
                  uVar7 = (**(code **)(*param_9 + 0xe0))(param_9,uVar8,uVar10,uVar7,uVar11);
                  uVar8 = (**(code **)(*param_9 + 0x30))(param_9,"javax/crypto/Cipher");
                  uVar10 = (**(code **)(*param_9 + 0x388))
                                     (param_9,uVar8,"getInstance",
                                      "(Ljava/lang/String;)Ljavax/crypto/Cipher;");
                  uVar10 = (**(code **)(*param_9 + 0x390))(param_9,uVar8,uVar10,uVar11);
                  uVar11 = (**(code **)(*param_9 + 0x108))
                                     (param_9,uVar8,&DAT_00101156,"(ILjava/security/Key;)V");
                  (**(code **)(*param_9 + 0x1e8))(param_9,uVar10,uVar11,2,uVar7);
                  uVar7 = (**(code **)(*param_9 + 0x538))(param_9,local_118);
                  uVar11 = (**(code **)(*param_9 + 0x30))(param_9,"android/util/Base64");
                  uVar12 = (**(code **)(*param_9 + 0x388))
                                     (param_9,uVar11,"decode","(Ljava/lang/String;I)[B");
                  uVar7 = (**(code **)(*param_9 + 0x390))(param_9,uVar11,uVar12,uVar7,0);
                  uVar8 = (**(code **)(*param_9 + 0x108))(param_9,uVar8,"doFinal","([B)[B");
                  uVar7 = (**(code **)(*param_9 + 0x110))(param_9,uVar10,uVar8,uVar7);
                  uVar8 = (**(code **)(*param_9 + 0xf8))(param_9,param_11);
                  uVar10 = (**(code **)(*param_9 + 0x108))(param_9,uVar8,"<init>","([B)V");
                  uVar7 = (**(code **)(*param_9 + 0xe0))(param_9,uVar8,uVar10,uVar7);
                  local_148 = ZEXT816(0);
                  local_158 = ZEXT816(0);
                  local_168 = ZEXT816(0);
                  local_178 = ZEXT816(0);
                  local_188 = ZEXT816(0);
                  local_198 = ZEXT816(0);
                  local_138 = 0;
                  Abstract_d(local_198,(byte *)"Y2xpZW50X3NlY3JldD0=");
                  uVar10 = (**(code **)(*param_9 + 0x548))(param_9,uVar7,0);
                  local_1b8 = ZEXT816(0);
                  local_1c8 = ZEXT816(0);
                  local_1d8 = ZEXT816(0);
                  local_1e8 = ZEXT816(0);
                  local_1f8 = ZEXT816(0);
                  local_208 = ZEXT816(0);
                  local_1a8 = 0;
                  FUN_00103e00(0,param_2,param_3,param_4,param_5,param_6,param_7,param_8,local_208,
                               100,&DAT_0010129a,local_198,uVar10,uVar9,in_stack_fffffffffffffd18);
                  uVar11 = (**(code **)(*param_9 + 0x538))(param_9,local_208);
                  (**(code **)(*param_9 + 0x550))(param_9,uVar7,uVar10);
                  local_228 = ZEXT816(0);
                  local_238 = ZEXT816(0);
                  local_248 = ZEXT816(0);
                  local_258 = ZEXT816(0);
                  local_268 = ZEXT816(0);
                  local_278 = ZEXT816(0);
                  local_218 = 0;
                  FUN_00103e00(0,param_2,param_3,param_4,param_5,param_6,param_7,param_8,local_278,
                               100,&DAT_0010129a,local_198,"[^&]+",uVar9,in_stack_fffffffffffffd18);
                  uVar7 = (**(code **)(*param_9 + 0x538))(param_9,local_278);
                  uVar8 = (**(code **)(*param_9 + 0x108))
                                    (param_9,uVar8,"replaceFirst",
                                     "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
                  uVar7 = (**(code **)(*param_9 + 0x110))(param_9,param_11,uVar8,uVar7,uVar11);
                  uVar6 = (**(code **)(*param_9 + 0x108))
                                    (param_9,uVar6,"getOutputStream","()Ljava/io/OutputStream;");
                  uVar6 = (**(code **)(*param_9 + 0x110))(param_9,param_12,uVar6);
                  uVar8 = (**(code **)(*param_9 + 0x30))(param_9,"java/io/OutputStreamWriter");
                  uVar9 = (**(code **)(*param_9 + 0x108))
                                    (param_9,uVar8,"<init>",
                                     "(Ljava/io/OutputStream;Ljava/lang/String;)V");
                  (**(code **)(*param_9 + 0x108))(param_9,uVar8,"close",&DAT_00100ffd);
                  uVar10 = (**(code **)(*param_9 + 0x538))(param_9,"UTF-8");
                  uVar6 = (**(code **)(*param_9 + 0xe0))(param_9,uVar8,uVar9,uVar6,uVar10);
                  uVar8 = (**(code **)(*param_9 + 0x30))(param_9,"java/io/BufferedWriter");
                  uVar9 = (**(code **)(*param_9 + 0x108))
                                    (param_9,uVar8,"<init>","(Ljava/io/Writer;)V");
                  uVar6 = (**(code **)(*param_9 + 0xe0))(param_9,uVar8,uVar9,uVar6);
                  uVar9 = (**(code **)(*param_9 + 0x108))
                                    (param_9,uVar8,"write","(Ljava/lang/String;)V");
                  uVar10 = (**(code **)(*param_9 + 0x108))(param_9,uVar8,"flush",&DAT_00100ffd);
                  uVar8 = (**(code **)(*param_9 + 0x108))(param_9,uVar8,"close",&DAT_00100ffd);
                  (**(code **)(*param_9 + 0x1e8))(param_9,uVar6,uVar9,uVar7);
                  (**(code **)(*param_9 + 0x1e8))(param_9,uVar6,uVar10);
                  (**(code **)(*param_9 + 0x1e8))(param_9,uVar6,uVar8);
                  uVar7 = 0;
                }
              }
            }
          }
        }
      }
    }
    else {
      (**(code **)(*param_9 + 0x550))(param_9,uVar7,__s1);
      uVar7 = 2;
    }
  }
  if (*(long *)(in_FS_OFFSET + 0x28) == local_38) {
    return uVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
