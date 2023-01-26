```c

long WakanimWebClient_process(long *environment, long wakanimWebClientClass, long requestBody, long connection, long trustManager) {
  local_38 = *(long *)(in_FS_OFFSET + 0x28);
  if (trustManager == 0) {
    long uVar7 = 1;
  }
  else {
    long uVar6 = environment.FindClass(environment,"java/net/URLConnection");
    long uVar7 = environment.GetMethodID(environment,uVar6,"getURL","()Ljava/net/URL;");
    long uVar7 = environment.CallObjectMethod(environment,connection,uVar7);
    long uVar8 = environment.GetObjectClass(environment,uVar7);
    long uVar8 = environment.GetMethodID(environment,uVar8,"getHost","()Ljava/lang/String;");
    long uVar7 = environment.CallObjectMethod(environment,uVar7,uVar8);
    char *__s1 = (char *)environment.GetStringUTFChars(environment,uVar7,0);
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
      long uVar8 = environment.GetObjectClass(environment,connection);
      long uVar9 = environment.GetObjectClass(environment,uVar8);
      long uVar9 = environment.GetMethodID(environment,uVar9,"getName","()Ljava/lang/String;");
      bool bVar19 = false;
      long uVar9 = environment.CallObjectMethod(environment,uVar8,uVar9);
      char *__s1_00 = (char *)environment.GetStringUTFChars(environment,uVar9,0);
      int iVar3 = strcmp(__s1_00,"com.android.okhttp.internal.http.HttpsURLConnectionImpl");
      if (iVar3 != 0) {
        int iVar3 = strcmp(__s1_00,"com.android.okhttp.internal.huc.HttpsURLConnectionImpl");
        bool bVar19 = iVar3 != 0;
      }
      environment.ReleaseStringUTFChars(environment,uVar9,__s1_00);
      long uVar9 = environment.FindClass(environment,"java/security/MessageDigest");
      long uVar10 = environment.GetStaticMethodID))
                         (environment,uVar9,"getInstance",
                          "(Ljava/lang/String;)Ljava/security/MessageDigest;");
      long uVar11 = environment.GetMethodID(environment,uVar9,"update","([BII)V");
      long uVar12 = environment.GetMethodID(environment,uVar9,"digest","()[B");
      long uVar13 = environment.NewStringUTF(environment,"SHA-256");
      long uVar9 = environment.CallStaticObjectMethod(environment,uVar9,uVar10,uVar13);
      long uVar8 = environment.GetMethodID))
                        (environment,uVar8,"getServerCertificates","()[Ljava/security/cert/Certificate;"
                        );
      long uVar8 = environment.CallObjectMethod(environment,connection,uVar8);
      long uVar10 = environment.FindClass(environment,"java/util/Arrays");
      int uVar4 = environment.GetArrayLength(environment,uVar8);
      long uVar13 = environment.FindClass(environment,"java/security/cert/X509Certificate");
      long uVar13 = environment.NewObjectArray(environment,0,uVar13,0);
      long uVar13 = environment.GetObjectClass(environment,uVar13);
      long uVar14 = environment.GetStaticMethodID))
                         (environment,uVar10,"copyOf",
                          "([Ljava/lang/Object;ILjava/lang/Class;)[Ljava/lang/Object;");
      long uVar8 = environment.CallStaticObjectMethod(environment,uVar10,uVar14,uVar8,uVar4,uVar13);
      long uVar10 = environment.GetObjectClass(environment,trustManager);
      long uVar10 = environment.GetMethodID))
                         (environment,uVar10,"checkServerTrusted",
                          "([Ljava/security/cert/X509Certificate;Ljava/lang/String;Ljava/lang/String ;)Ljava/util/List;"
                         );
      long uVar13 = environment.NewStringUTF(environment,"RSA");
      long uVar8 = environment.CallObjectMethod(environment,trustManager,uVar10,uVar8,uVar13,uVar7);
      environment.ReleaseStringUTFChars(environment,uVar7,__s1);
      char cVar2 = environment.ExceptionCheck(environment);
      long uVar7 = 3;
      if (char cVar2 == '\0') {
        long uVar7 = environment.GetObjectClass(environment,uVar8);
        long uVar10 = environment.GetMethodID(environment,uVar7,"size","()I");
        long uVar13 = environment.GetMethodID))
                           (environment,uVar7,"get","(I)Ljava/lang/Object;");
        long uVar7 = environment.FindClass(environment,"java/security/cert/Certificate");
        long uVar14 = environment.GetMethodID))
                           (environment,uVar7,"getPublicKey","()Ljava/security/PublicKey;");
        long uVar7 = environment.FindClass(environment,"java/security/PublicKey");
        long uVar15 = environment.GetMethodID(environment,uVar7,"getEncoded","()[B");
        int iVar3 = environment.CallIntMethod(environment,uVar8,uVar10);
        long uVar7 = 5;
        if (0 < iVar3) {
          bool bVar1 = false;
          int iVar18 = 0;
          do {
            long uVar7 = environment.CallObjectMethod(environment,uVar8,uVar13,iVar18);
            long uVar7 = environment.CallObjectMethod(environment,uVar7,uVar14);
            long uVar7 = environment.CallObjectMethod(environment,uVar7,uVar15);
            int uVar4 = environment.GetArrayLength(environment,uVar7);
            environment.CallVoidMethod(environment,uVar9,uVar11,uVar7,0,uVar4);
            long uVar7 = environment.CallObjectMethod(environment,uVar9,uVar12);
            int iVar5 = environment.GetArrayLength(environment,uVar7);
            if (iVar5 != 0x20) break;
            long lVar16 = environment.GetByteArrayElements(environment,uVar7,0);
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
            environment.ReleaseByteArrayElements(environment,uVar7,lVar16,0);
            int iVar18 = iVar18 + 1;
          } while (iVar18 < iVar3);
          long uVar7 = 5;
          if ((bVar1) && (long uVar7 = 0, !(bool)(requestBody == 0 | bVar19))) {
            long uVar7 = environment.FindClass))
                              (environment,"com/wakanim/wakanimapp/test/WakanimAndroidApplication");
            long lVar16 = environment.GetStaticFieldID))
                               (environment,uVar7,"FirebaseUID","Ljava/lang/String;");
            if (long lVar16 == 0) {
              long uVar7 = 6;
            }
            else {
              long uVar7 = environment.GetStaticObjectField(environment,uVar7,lVar16);
              long uVar8 = environment.FindClass))
                                (environment,
                                 "com/wakanim/wakanimapp/test/wakanimWebclient/WakanimWebClient");
              long lVar16 = environment.GetStaticFieldID))
                                 (environment,uVar8,"SecurityStoreUID","Ljava/lang/String;");
              if (long lVar16 == 0) {
                long uVar7 = 7;
              }
              else {
                long uVar8 = environment.GetStaticObjectField(environment,uVar8,lVar16);
                long uVar9 = environment.FindClass))
                                  (environment,"com/wakanim/wakanimapp/test/WakanimActivity");
                long lVar16 = environment.GetStaticFieldID))
                                   (environment,uVar9,"ActivityMetric","Ljava/lang/String;");
                if (long lVar16 == 0) {
                  long uVar7 = 8;
                }
                else {
                  long uVar10 = environment.GetStaticObjectField(environment,uVar9,lVar16);
                  long uVar11 = environment.GetStringUTFChars(environment,uVar7,0);
                  long uVar12 = environment.GetStringUTFChars(environment,uVar8,0);
                  long uVar13 = environment.GetStringUTFChars(environment,uVar10,0);
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
                  environment.ReleaseStringUTFChars(environment,uVar7,uVar11);
                  environment.ReleaseStringUTFChars(environment,uVar8,uVar12);
                  environment.ReleaseStringUTFChars(environment,uVar10,uVar13);
                  local_128 = 0x22058230;
                  uStack_124 = 0x8060d36;
                  uStack_120 = 0x8658862a;
                  uStack_11c = 0x1010df7;
                  long uVar7 = environment.NewByteArray(environment,0x10);
                  environment.SetByteArrayRegion(environment,uVar7,0,0x10,&local_128);
                  long uVar8 = environment.FindClass(environment,"javax/crypto/spec/SecretKeySpec");
                  long uVar10 = environment.GetMethodID))
                                     (environment,uVar8,"<init>","([BLjava/lang/String;)V");
                  long uVar11 = environment.NewStringUTF(environment,"AES");
                  long uVar7 = environment.NewObject(environment,uVar8,uVar10,uVar7,uVar11);
                  long uVar8 = environment.FindClass(environment,"javax/crypto/Cipher");
                  long uVar10 = environment.GetStaticMethodID))
                                     (environment,uVar8,"getInstance",
                                      "(Ljava/lang/String;)Ljavax/crypto/Cipher;");
                  long uVar10 = environment.CallStaticObjectMethod(environment,uVar8,uVar10,uVar11);
                  long uVar11 = environment.GetMethodID))
                                     (environment,uVar8,"init","(ILjava/security/Key;)V");
                  environment.CallVoidMethod(environment,uVar10,uVar11,2,uVar7);
                  long uVar7 = environment.NewStringUTF(environment,local_118);
                  long uVar11 = environment.FindClass(environment,"android/util/Base64");
                  long uVar12 = environment.GetStaticMethodID))
                                     (environment,uVar11,"decode","(Ljava/lang/String;I)[B");
                  long uVar7 = environment.CallStaticObjectMethod(environment,uVar11,uVar12,uVar7,0);
                  long uVar8 = environment.GetMethodID(environment,uVar8,"doFinal","([B)[B");
                  long uVar7 = environment.CallObjectMethod(environment,uVar10,uVar8,uVar7);
                  long uVar8 = environment.GetObjectClass(environment,requestBody);
                  long uVar10 = environment.GetMethodID(environment,uVar8,"<init>","([B)V");
                  long uVar7 = environment.NewObject(environment,uVar8,uVar10,uVar7);
                  local_148 = ZEXT816(0);
                  local_158 = ZEXT816(0);
                  local_168 = ZEXT816(0);
                  local_178 = ZEXT816(0);
                  local_188 = ZEXT816(0);
                  local_198 = ZEXT816(0);
                  local_138 = 0;
                  Abstract_d(local_198,(byte *)"Y2xpZW50X3NlY3JldD0=");
                  long uVar10 = environment.GetStringUTFChars(environment,uVar7,0);
                  local_1b8 = ZEXT816(0);
                  local_1c8 = ZEXT816(0);
                  local_1d8 = ZEXT816(0);
                  local_1e8 = ZEXT816(0);
                  local_1f8 = ZEXT816(0);
                  local_208 = ZEXT816(0);
                  local_1a8 = 0;
                  FUN_00103e00(0,param_2,param_3,param_4,param_5,param_6,param_7,param_8,local_208,
                               100,"%s%s",local_198,uVar10,uVar9,in_stack_fffffffffffffd18);
                  long uVar11 = environment.NewStringUTF(environment,local_208);
                  environment.ReleaseStringUTFChars(environment,uVar7,uVar10);
                  local_228 = ZEXT816(0);
                  local_238 = ZEXT816(0);
                  local_248 = ZEXT816(0);
                  local_258 = ZEXT816(0);
                  local_268 = ZEXT816(0);
                  local_278 = ZEXT816(0);
                  local_218 = 0;
                  FUN_00103e00(0,param_2,param_3,param_4,param_5,param_6,param_7,param_8,local_278,
                               100,"%s%s",local_198,"[^&]+",uVar9,in_stack_fffffffffffffd18);
                  long uVar7 = environment.NewStringUTF(environment,local_278);
                  long uVar8 = environment.GetMethodID))
                                    (environment,uVar8,"replaceFirst",
                                     "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
                  long uVar7 = environment.CallObjectMethod(environment,requestBody,uVar8,uVar7,uVar11);
                  long uVar6 = environment.GetMethodID))
                                    (environment,uVar6,"getOutputStream","()Ljava/io/OutputStream;");
                  long uVar6 = environment.CallObjectMethod(environment,connection,uVar6);
                  long uVar8 = environment.FindClass(environment,"java/io/OutputStreamWriter");
                  long uVar9 = environment.GetMethodID))
                                    (environment,uVar8,"<init>",
                                     "(Ljava/io/OutputStream;Ljava/lang/String;)V");
                  environment.GetMethodID(environment,uVar8,"close","()V");
                  long uVar10 = environment.NewStringUTF(environment,"UTF-8");
                  long uVar6 = environment.NewObject(environment,uVar8,uVar9,uVar6,uVar10);
                  long uVar8 = environment.FindClass(environment,"java/io/BufferedWriter");
                  long uVar9 = environment.GetMethodID))
                                    (environment,uVar8,"<init>","(Ljava/io/Writer;)V");
                  long uVar6 = environment.NewObject(environment,uVar8,uVar9,uVar6);
                  long uVar9 = environment.GetMethodID))
                                    (environment,uVar8,"write","(Ljava/lang/String;)V");
                  long uVar10 = environment.GetMethodID(environment,uVar8,"flush","()V");
                  long uVar8 = environment.GetMethodID(environment,uVar8,"close","()V");
                  environment.CallVoidMethod(environment,uVar6,uVar9,uVar7);
                  environment.CallVoidMethod(environment,uVar6,uVar10);
                  environment.CallVoidMethod(environment,uVar6,uVar8);
                  long uVar7 = 0;
                }
              }
            }
          }
        }
      }
    }
    else {
      environment.ReleaseStringUTFChars(environment,uVar7,__s1);
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