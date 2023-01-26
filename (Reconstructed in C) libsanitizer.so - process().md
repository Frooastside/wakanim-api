```c

long WakanimWebClient_process
          (long *environment,
          long wakanimWebClientClass,long requestBody,long connection,long trustManager)

{
  local_38 = *(long *)(in_FS_OFFSET + 0x28);
  if (trustManager == 0) {
    long uVar7 = 1;
  }
  else {
    long uVar6 = (**(code **)(*environment + 0x30))(environment,"java/net/URLConnection");
    long uVar7 = (**(code **)(*environment + 0x108))(environment,uVar6,"getURL","()Ljava/net/URL;");
    long uVar7 = (**(code **)(*environment + 0x110))(environment,connection,uVar7);
    long uVar8 = (**(code **)(*environment + 0xf8))(environment,uVar7);
    long uVar8 = (**(code **)(*environment + 0x108))(environment,uVar8,"getHost","()Ljava/lang/String;");
    long uVar7 = (**(code **)(*environment + 0x110))(environment,uVar7,uVar8);
    char *__s1 = (char *)(**(code **)(*environment + 0x548))(environment,uVar7,0);
    local_58 = ZEXT816(0);
    local_68 = ZEXT816(0);
    local_78 = ZEXT816(0);
    local_88 = ZEXT816(0);
    local_98 = ZEXT816(0);
    local_a8 = ZEXT816(0);
    local_48 = 0;
    Abstract_d(local_a8,(byte *)"YWNjb3VudC53YWthbmltLnR2");
    int iVar3 = strcmp(__s1,local_a8);
    if (int iVar3 == 0) {
      long uVar8 = (**(code **)(*environment + 0xf8))(environment,connection);
      long uVar9 = (**(code **)(*environment + 0xf8))(environment,uVar8);
      long uVar9 = (**(code **)(*environment + 0x108))(environment,uVar9,"getName","()Ljava/lang/String;");
      bool bVar19 = false;
      long uVar9 = (**(code **)(*environment + 0x110))(environment,uVar8,uVar9);
      char *__s1_00 = (char *)(**(code **)(*environment + 0x548))(environment,uVar9,0);
      int iVar3 = strcmp(__s1_00,"com.android.okhttp.internal.http.HttpsURLConnectionImpl");
      if (iVar3 != 0) {
        int iVar3 = strcmp(__s1_00,"com.android.okhttp.internal.huc.HttpsURLConnectionImpl");
        bool bVar19 = iVar3 != 0;
      }
      (**(code **)(*environment + 0x550))(environment,uVar9,__s1_00);
      long uVar9 = (**(code **)(*environment + 0x30))(environment,"java/security/MessageDigest");
      long uVar10 = (**(code **)(*environment + 0x388))
                         (environment,uVar9,"getInstance",
                          "(Ljava/lang/String;)Ljava/security/MessageDigest;");
      long uVar11 = (**(code **)(*environment + 0x108))(environment,uVar9,"update","([BII)V");
      long uVar12 = (**(code **)(*environment + 0x108))(environment,uVar9,"digest",&DAT_00100e8d);
      long uVar13 = (**(code **)(*environment + 0x538))(environment,"SHA-256");
      long uVar9 = (**(code **)(*environment + 0x390))(environment,uVar9,uVar10,uVar13);
      long uVar8 = (**(code **)(*environment + 0x108))
                        (environment,uVar8,"getServerCertificates","()[Ljava/security/cert/Certificate;"
                        );
      long uVar8 = (**(code **)(*environment + 0x110))(environment,connection,uVar8);
      long uVar10 = (**(code **)(*environment + 0x30))(environment,"java/util/Arrays");
      int uVar4 = (**(code **)(*environment + 0x558))(environment,uVar8);
      long uVar13 = (**(code **)(*environment + 0x30))(environment,"java/security/cert/X509Certificate");
      long uVar13 = (**(code **)(*environment + 0x560))(environment,0,uVar13,0);
      long uVar13 = (**(code **)(*environment + 0xf8))(environment,uVar13);
      long uVar14 = (**(code **)(*environment + 0x388))
                         (environment,uVar10,"copyOf",
                          "([Ljava/lang/Object;ILjava/lang/Class;)[Ljava/lang/Object;");
      long uVar8 = (**(code **)(*environment + 0x390))(environment,uVar10,uVar14,uVar8,uVar4,uVar13);
      long uVar10 = (**(code **)(*environment + 0xf8))(environment,trustManager);
      long uVar10 = (**(code **)(*environment + 0x108))
                         (environment,uVar10,"checkServerTrusted",
                          "([Ljava/security/cert/X509Certificate;Ljava/lang/String;Ljava/lang/String ;)Ljava/util/List;"
                         );
      long uVar13 = (**(code **)(*environment + 0x538))(environment,&DAT_00101046);
      long uVar8 = (**(code **)(*environment + 0x110))(environment,trustManager,uVar10,uVar8,uVar13,uVar7);
      (**(code **)(*environment + 0x550))(environment,uVar7,__s1);
      char cVar2 = (**(code **)(*environment + 0x720))(environment);
      long uVar7 = 3;
      if (char cVar2 == '\0') {
        long uVar7 = (**(code **)(*environment + 0xf8))(environment,uVar8);
        long uVar10 = (**(code **)(*environment + 0x108))(environment,uVar7,&DAT_00101014,&DAT_001012ce);
        long uVar13 = (**(code **)(*environment + 0x108))
                           (environment,uVar7,&DAT_00100db9,"(I)Ljava/lang/Object;");
        long uVar7 = (**(code **)(*environment + 0x30))(environment,"java/security/cert/Certificate");
        long uVar14 = (**(code **)(*environment + 0x108))
                           (environment,uVar7,"getPublicKey","()Ljava/security/PublicKey;");
        long uVar7 = (**(code **)(*environment + 0x30))(environment,"java/security/PublicKey");
        long uVar15 = (**(code **)(*environment + 0x108))(environment,uVar7,"getEncoded",&DAT_00100e8d);
        int iVar3 = (**(code **)(*environment + 0x188))(environment,uVar8,uVar10);
        long uVar7 = 5;
        if (0 < iVar3) {
          bool bVar1 = false;
          int iVar18 = 0;
          do {
            long uVar7 = (**(code **)(*environment + 0x110))(environment,uVar8,uVar13,iVar18);
            long uVar7 = (**(code **)(*environment + 0x110))(environment,uVar7,uVar14);
            long uVar7 = (**(code **)(*environment + 0x110))(environment,uVar7,uVar15);
            int uVar4 = (**(code **)(*environment + 0x558))(environment,uVar7);
            (**(code **)(*environment + 0x1e8))(environment,uVar9,uVar11,uVar7,0,uVar4);
            long uVar7 = (**(code **)(*environment + 0x110))(environment,uVar9,uVar12);
            int iVar5 = (**(code **)(*environment + 0x558))(environment,uVar7);
            if (iVar5 != 0x20) break;
            long lVar16 = (**(code **)(*environment + 0x5c0))(environment,uVar7,0);
            long lVar17 = 3;
            do {
              if (((((&UNK_0010134d)[lVar17] != *(char *)(lVar16 + -3 + lVar17)) ||
                   ((&UNK_0010134e)[lVar17] != *(char *)(lVar16 + -2 + lVar17))) ||
                  ((&UNK_0010134f)[lVar17] != *(char *)(lVar16 + -1 + lVar17))) ||
                 ((&DAT_00101350)[lVar17] != *(char *)(lVar16 + lVar17))) goto LAB_00103510;
              long lVar17 = lVar17 + 4;
            } while (lVar17 != 0x23);
            bool bVar1 = true;
LAB_00103510:
            (**(code **)(*environment + 0x600))(environment,uVar7,lVar16,0);
            int iVar18 = iVar18 + 1;
          } while (iVar18 < iVar3);
          long uVar7 = 5;
          if ((bVar1) && (long uVar7 = 0, !(bool)(requestBody == 0 | bVar19))) {
            long uVar7 = (**(code **)(*environment + 0x30))
                              (environment,"com/wakanim/wakanimapp/test/WakanimAndroidApplication");
            long lVar16 = (**(code **)(*environment + 0x480))
                               (environment,uVar7,"FirebaseUID","Ljava/lang/String;");
            if (long lVar16 == 0) {
              long uVar7 = 6;
            }
            else {
              long uVar7 = (**(code **)(*environment + 0x488))(environment,uVar7,lVar16);
              long uVar8 = (**(code **)(*environment + 0x30))
                                (environment,
                                 "com/wakanim/wakanimapp/test/wakanimWebclient/WakanimWebClient");
              long lVar16 = (**(code **)(*environment + 0x480))
                                 (environment,uVar8,"SecurityStoreUID","Ljava/lang/String;");
              if (long lVar16 == 0) {
                long uVar7 = 7;
              }
              else {
                long uVar8 = (**(code **)(*environment + 0x488))(environment,uVar8,lVar16);
                long uVar9 = (**(code **)(*environment + 0x30))
                                  (environment,"com/wakanim/wakanimapp/test/WakanimActivity");
                long lVar16 = (**(code **)(*environment + 0x480))
                                   (environment,uVar9,"ActivityMetric","Ljava/lang/String;");
                if (long lVar16 == 0) {
                  long uVar7 = 8;
                }
                else {
                  long uVar10 = (**(code **)(*environment + 0x488))(environment,uVar9,lVar16);
                  long uVar11 = (**(code **)(*environment + 0x548))(environment,uVar7,0);
                  long uVar12 = (**(code **)(*environment + 0x548))(environment,uVar8,0);
                  long uVar13 = (**(code **)(*environment + 0x548))(environment,uVar10,0);
                  local_c8 = ZEXT816(0);
                  local_d8 = ZEXT816(0);
                  local_e8 = ZEXT816(0);
                  local_f8 = ZEXT816(0);
                  local_108 = ZEXT816(0);
                  local_118 = ZEXT816(0);
                  local_b8 = 0;
                  long uVar9 = uVar13;
                  FUN_00103e00(0,param_2,param_3,param_4,param_5,param_6,param_7,param_8,local_118,
                               100,"%s%s%s",uVar11,uVar12,uVar13,in_stack_fffffffffffffd18);
                  (**(code **)(*environment + 0x550))(environment,uVar7,uVar11);
                  (**(code **)(*environment + 0x550))(environment,uVar8,uVar12);
                  (**(code **)(*environment + 0x550))(environment,uVar10,uVar13);
                  local_128 = 0x22058230;
                  uStack_124 = 0x8060d36;
                  uStack_120 = 0x8658862a;
                  uStack_11c = 0x1010df7;
                  long uVar7 = (**(code **)(*environment + 0x580))(environment,0x10);
                  (**(code **)(*environment + 0x680))(environment,uVar7,0,0x10,&local_128);
                  long uVar8 = (**(code **)(*environment + 0x30))(environment,"javax/crypto/spec/SecretKeySpec");
                  long uVar10 = (**(code **)(*environment + 0x108))
                                     (environment,uVar8,"<init>","([BLjava/lang/String;)V");
                  long uVar11 = (**(code **)(*environment + 0x538))(environment,&DAT_00100ff9);
                  long uVar7 = (**(code **)(*environment + 0xe0))(environment,uVar8,uVar10,uVar7,uVar11);
                  long uVar8 = (**(code **)(*environment + 0x30))(environment,"javax/crypto/Cipher");
                  long uVar10 = (**(code **)(*environment + 0x388))
                                     (environment,uVar8,"getInstance",
                                      "(Ljava/lang/String;)Ljavax/crypto/Cipher;");
                  long uVar10 = (**(code **)(*environment + 0x390))(environment,uVar8,uVar10,uVar11);
                  long uVar11 = (**(code **)(*environment + 0x108))
                                     (environment,uVar8,&DAT_00101156,"(ILjava/security/Key;)V");
                  (**(code **)(*environment + 0x1e8))(environment,uVar10,uVar11,2,uVar7);
                  long uVar7 = (**(code **)(*environment + 0x538))(environment,local_118);
                  long uVar11 = (**(code **)(*environment + 0x30))(environment,"android/util/Base64");
                  long uVar12 = (**(code **)(*environment + 0x388))
                                     (environment,uVar11,"decode","(Ljava/lang/String;I)[B");
                  long uVar7 = (**(code **)(*environment + 0x390))(environment,uVar11,uVar12,uVar7,0);
                  long uVar8 = (**(code **)(*environment + 0x108))(environment,uVar8,"doFinal","([B)[B");
                  long uVar7 = (**(code **)(*environment + 0x110))(environment,uVar10,uVar8,uVar7);
                  long uVar8 = (**(code **)(*environment + 0xf8))(environment,requestBody);
                  long uVar10 = (**(code **)(*environment + 0x108))(environment,uVar8,"<init>","([B)V");
                  long uVar7 = (**(code **)(*environment + 0xe0))(environment,uVar8,uVar10,uVar7);
                  local_148 = ZEXT816(0);
                  local_158 = ZEXT816(0);
                  local_168 = ZEXT816(0);
                  local_178 = ZEXT816(0);
                  local_188 = ZEXT816(0);
                  local_198 = ZEXT816(0);
                  local_138 = 0;
                  Abstract_d(local_198,(byte *)"Y2xpZW50X3NlY3JldD0=");
                  long uVar10 = (**(code **)(*environment + 0x548))(environment,uVar7,0);
                  local_1b8 = ZEXT816(0);
                  local_1c8 = ZEXT816(0);
                  local_1d8 = ZEXT816(0);
                  local_1e8 = ZEXT816(0);
                  local_1f8 = ZEXT816(0);
                  local_208 = ZEXT816(0);
                  local_1a8 = 0;
                  FUN_00103e00(0,param_2,param_3,param_4,param_5,param_6,param_7,param_8,local_208,
                               100,&DAT_0010129a,local_198,uVar10,uVar9,in_stack_fffffffffffffd18);
                  long uVar11 = (**(code **)(*environment + 0x538))(environment,local_208);
                  (**(code **)(*environment + 0x550))(environment,uVar7,uVar10);
                  local_228 = ZEXT816(0);
                  local_238 = ZEXT816(0);
                  local_248 = ZEXT816(0);
                  local_258 = ZEXT816(0);
                  local_268 = ZEXT816(0);
                  local_278 = ZEXT816(0);
                  local_218 = 0;
                  FUN_00103e00(0,param_2,param_3,param_4,param_5,param_6,param_7,param_8,local_278,
                               100,&DAT_0010129a,local_198,"[^&]+",uVar9,in_stack_fffffffffffffd18);
                  long uVar7 = (**(code **)(*environment + 0x538))(environment,local_278);
                  long uVar8 = (**(code **)(*environment + 0x108))
                                    (environment,uVar8,"replaceFirst",
                                     "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
                  long uVar7 = (**(code **)(*environment + 0x110))(environment,requestBody,uVar8,uVar7,uVar11);
                  long uVar6 = (**(code **)(*environment + 0x108))
                                    (environment,uVar6,"getOutputStream","()Ljava/io/OutputStream;");
                  long uVar6 = (**(code **)(*environment + 0x110))(environment,connection,uVar6);
                  long uVar8 = (**(code **)(*environment + 0x30))(environment,"java/io/OutputStreamWriter");
                  long uVar9 = (**(code **)(*environment + 0x108))
                                    (environment,uVar8,"<init>",
                                     "(Ljava/io/OutputStream;Ljava/lang/String;)V");
                  (**(code **)(*environment + 0x108))(environment,uVar8,"close",&DAT_00100ffd);
                  long uVar10 = (**(code **)(*environment + 0x538))(environment,"UTF-8");
                  long uVar6 = (**(code **)(*environment + 0xe0))(environment,uVar8,uVar9,uVar6,uVar10);
                  long uVar8 = (**(code **)(*environment + 0x30))(environment,"java/io/BufferedWriter");
                  long uVar9 = (**(code **)(*environment + 0x108))
                                    (environment,uVar8,"<init>","(Ljava/io/Writer;)V");
                  long uVar6 = (**(code **)(*environment + 0xe0))(environment,uVar8,uVar9,uVar6);
                  long uVar9 = (**(code **)(*environment + 0x108))
                                    (environment,uVar8,"write","(Ljava/lang/String;)V");
                  long uVar10 = (**(code **)(*environment + 0x108))(environment,uVar8,"flush",&DAT_00100ffd);
                  long uVar8 = (**(code **)(*environment + 0x108))(environment,uVar8,"close",&DAT_00100ffd);
                  (**(code **)(*environment + 0x1e8))(environment,uVar6,uVar9,uVar7);
                  (**(code **)(*environment + 0x1e8))(environment,uVar6,uVar10);
                  (**(code **)(*environment + 0x1e8))(environment,uVar6,uVar8);
                  long uVar7 = 0;
                }
              }
            }
          }
        }
      }
    }
    else {
      (**(code **)(*environment + 0x550))(environment,uVar7,__s1);
      long uVar7 = 2;
    }
  }
  if (*(long *)(in_FS_OFFSET + 0x28) == local_38) {
    return uVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
```