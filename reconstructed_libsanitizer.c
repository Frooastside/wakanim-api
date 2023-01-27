long WakanimWebClient_process(long* environment, long wakanimWebClientClass, long requestBody, long connection, long trustManager) {
	if (trustManager == 0) {
		return -1;
	}
	else {
		long urlConnectionClass = environment.FindClass(environment, "java/net/URLConnection");
		long getURLMethod = environment.GetMethodID(environment, urlConnectionClass, "getURL", "()Ljava/net/URL;");
		long url = environment.CallObjectMethod(environment, connection, getURLMethod);
		long urlClass = environment.GetObjectClass(environment, url);
		long getHostMethod = environment.GetMethodID(environment, urlClass, "getHost", "()Ljava/lang/String;");
		long host = environment.CallObjectMethod(environment, urlClass, getHostMethod);
		char* hostString = (char*)environment.GetStringUTFChars(environment, host, 0);
		char expectedHost[100] = {};
		Abstract_d(expectedHost, "YWNjb3VudC53YWthbmltLnR2"); //account.wakanim.com
		int validHost = compareStrings(hostString, expectedHost);
		if (int validHost == 0) {
			long connectionClass = environment.GetObjectClass(environment, connection);				//URLConnection
			long genericConnectionClass = environment.GetObjectClass(environment, connectionClass);	//Class<? extends URLConnection>
			long getClassNameMethod = environment.GetMethodID(environment, genericConnectionClass, "getName", "()Ljava/lang/String;");
			long connectionClassName = environment.CallObjectMethod(environment, genericConnectionClass, getClassNameMethod);
			char* connectionClassNameString = (char*)environment.GetStringUTFChars(environment, connectionClassName, 0);
			bool instanceofHttpsURLConnectionImpl = compareStrings(connectionClassNameString, "com.android.okhttp.internal.http.HttpsURLConnectionImpl")
				|| compareStrings(connectionClassNameString, "com.android.okhttp.internal.huc.HttpsURLConnectionImpl");
			environment.ReleaseStringUTFChars(environment, connectionClassName, connectionClassNameString);
			long messageDigestClass = environment.FindClass(environment, "java/security/MessageDigest");
			long messageDigestInstanceMethod = environment.GetStaticMethodID(environment, messageDigestClass, "getInstance", "(Ljava/lang/String;)Ljava/security/MessageDigest;");
			long updateMethod = environment.GetMethodID(environment, messageDigestClass, "update", "([BII)V");
			long digestMethod = environment.GetMethodID(environment, messageDigestClass, "digest", "()[B");
			long hashAlgorithm = environment.NewStringUTF(environment, "SHA-256");
			long sha256Instance = environment.CallStaticObjectMethod(environment, messageDigestClass, messageDigestInstanceMethod, hashAlgorithm);
			long getServerCertificatesMethod = environment.GetMethodID(environment, connectionClass, "getServerCertificates", "()[Ljava/security/cert/Certificate;");
			long serverCertificates = environment.CallObjectMethod(environment, connection, getServerCertificatesMethod);
			long arraysClass = environment.FindClass(environment, "java/util/Arrays");
			int certificateListLength = environment.GetArrayLength(environment, serverCertificates);
			long x509CertificateClass = environment.FindClass(environment, "java/security/cert/X509Certificate");
			long certificateArray = environment.NewObjectArray(environment, 0, x509CertificateClass, 0);
			long certificateArrayClass = environment.GetObjectClass(environment, certificateArray);
			long copyOfMethod = environment.GetStaticMethodID(environment, arraysClass, "copyOf", "([Ljava/lang/Object;ILjava/lang/Class;)[Ljava/lang/Object;");
			long castedCertificateList = environment.CallStaticObjectMethod(environment, arraysClass, copyOfMethod, serverCertificates, certificateListLength, certificateArrayClass);
			long trustManagerClass = environment.GetObjectClass(environment, trustManager);
			long checkServerTrustedMethod = environment.GetMethodID(environment, trustManagerClass, "checkServerTrusted", "([Ljava/security/cert/X509Certificate;Ljava/lang/String;Ljava/lang/String;)Ljava/util/List;");
			long rsaString = environment.NewStringUTF(environment, "RSA");
			long orderedCertificateChain = environment.CallObjectMethod(environment, trustManager, checkServerTrustedMethod, castedCertificateList, hostString, rsaString);
			environment.ReleaseStringUTFChars(environment, host, hostString);
			char exception = environment.ExceptionCheck(environment);
			if (exception == '\0') {
				long certificateListClass = environment.GetObjectClass(environment, orderedCertificateChain);
				long sizeMethod = environment.GetMethodID(environment, certificateListClass, "size", "()I");
				long getMethod = environment.GetMethodID(environment, certificateListClass, "get", "(I)Ljava/lang/Object;");
				long certificateClass = environment.FindClass(environment, "java/security/cert/Certificate");
				long getPublicKeyMethod = environment.GetMethodID(environment, certificateClass, "getPublicKey", "()Ljava/security/PublicKey;");
				long publicKeyClass = environment.FindClass(environment, "java/security/PublicKey");
				long getEncodedMethod = environment.GetMethodID(environment, publicKeyClass, "getEncoded", "()[B");
				int chainLength = environment.CallIntMethod(environment, orderedCertificateChain, sizeMethod);
				if (0 < chainLength) {
					int index = 0;
					bool certificatesAreValid = true;
					do {
						long certificate = environment.CallObjectMethod(environment, certificateListClass, getMethod, index);
						long publicKey = environment.CallObjectMethod(environment, certificate, getPublicKeyMethod);
						long encodedPublicKey = environment.CallObjectMethod(environment, publicKey, getEncodedMethod);
						int publicKeyLength = environment.GetArrayLength(environment, encodedPublicKey);
						environment.CallVoidMethod(environment, sha256Instance, updateMethod, encodedPublicKey, 0, publicKeyLength);
						long hash = environment.CallObjectMethod(environment, sha256Instance, digestMethod);
						int hashLength = environment.GetArrayLength(environment, hash);
						if (hashLength != 32) {
							break
						};
						long hashBytes = environment.GetByteArrayElements(environment, hash, 0);
						byte validHash[] = { 0xDA, 0xA9, 0xF0, 0x54, 0x96, 0xEB, 0xA7, 0x29, 0xC1, 0xEB, 0x5B, 0x4A, 0xF9, 0x80, 0xE8, 0xF9, 0x3B, 0xA3, 0x52, 0x0B, 0x26, 0xB2, 0x18, 0xB7, 0xC3, 0x4E, 0x85, 0x29, 0x6F, 0x5C, 0x2D, 0x4C };
						long offset = 0;
						do {
							if ((validHash[offset * 4] != *(char*)hashBytes[offset * 4]) ||
								(validHash[offset * 4 + 1] != *(char*)hashBytes[offset * 4 + 1]) ||
								(validHash[offset * 4 + 2] != *(char*)hashBytes[offset * 4 + 2]) ||
								(validHash[offset * 4 + 3] != *(char*)hashBytes[offset * 4 + 3])) {
								certificatesAreValid = false;
							}
							offset++;
						} while (offset != 32);
						environment.ReleaseByteArrayElements(environment, hash, hashBytes, 0);
						index++;
					} while (index < chainLength);
					if (certificatesAreValid && !(requestBody == 0 || instanceofHttpsURLConnectionImpl)) {
						long wakanimAndroidApplicationClass = environment.FindClass(environment, "com/wakanim/wakanimapp/test/WakanimAndroidApplication");
						long firebaseUIDField = environment.GetStaticFieldID(environment, wakanimAndroidApplicationClass, "FirebaseUID", "Ljava/lang/String;");
						long firebaseUID = environment.GetStaticObjectField(environment, wakanimAndroidApplicationClass, firebaseUIDField);
						long wakanimWebClientClass = environment.FindClass(environment, "com/wakanim/wakanimapp/test/wakanimWebclient/WakanimWebClient");
						long securityStoreUIDField = environment.GetStaticFieldID(environment, wakanimWebClientClass, "SecurityStoreUID", "Ljava/lang/String;");
						long securityStoreUID = environment.GetStaticObjectField(environment, wakanimWebClientClass, securityStoreUIDField);
						long wakanimActivityClass = environment.FindClass(environment, "com/wakanim/wakanimapp/test/WakanimActivity");
						long activityMetricField = environment.GetStaticFieldID(environment, wakanimActivityClass, "ActivityMetric", "Ljava/lang/String;");
						long activityMetric = environment.GetStaticObjectField(environment, wakanimActivityClass, activityMetricField);
						long firebaseUIDString = environment.GetStringUTFChars(environment, firebaseUID, 0);
						long securityStoreUIDString = environment.GetStringUTFChars(environment, securityStoreUID, 0);
						long activityMetricString = environment.GetStringUTFChars(environment, activityMetric, 0);
						char clientSecretB64[100] = { 0 };
						__vsprintf_chk(&clientSecretB64, 0, 100, "%s%s%s", [firebaseUIDString, securityStoreUIDString, activityMetricString]);
						environment.ReleaseStringUTFChars(environment, firebaseUID, firebaseUIDString);
						environment.ReleaseStringUTFChars(environment, securityStoreUID, securityStoreUIDString);
						environment.ReleaseStringUTFChars(environment, activityMetric, activityMetricString);
						byte rawKey[] = { 0x01, 0x01, 0x0D, 0xF7, 0x86, 0x58, 0x86, 0x2A, 0x08, 0x06, 0x0D, 0x36, 0x22, 0x05, 0x82, 0x30 }
						long rawKeyArray = environment.NewByteArray(environment, 16);
						environment.SetByteArrayRegion(environment, rawKeyArray, 0, 16, rawKey);
						long secretKeyClass = environment.FindClass(environment, "javax/crypto/spec/SecretKeySpec");
						long secretKeyConstructor = environment.GetMethodID(environment, secretKeyClass, "<init>", "([BLjava/lang/String;)V");
						long aesString = environment.NewStringUTF(environment, "AES");
						long secretKey = environment.NewObject(environment, secretKeyClass, secretKeyConstructor, rawKeyArray, aesString);
						long cipherClass = environment.FindClass(environment, "javax/crypto/Cipher");
						long cipherInstanceClass = environment.GetStaticMethodID(environment, cipherClass, "getInstance", "(Ljava/lang/String;)Ljavax/crypto/Cipher;");
						long aesInstance = environment.CallStaticObjectMethod(environment, cipherClass, cipherInstanceClass, aesString);
						long initMethod = environment.GetMethodID(environment, cipherClass, "init", "(ILjava/security/Key;)V");
						environment.CallVoidMethod(environment, aesInstance, initMethod, 2, secretKey);
						long clientSecretB64String = environment.NewStringUTF(environment, clientSecretB64);
						long base64Class = environment.FindClass(environment, "android/util/Base64");
						long base64DecodeMethod = environment.GetStaticMethodID(environment, base64Class, "decode", "(Ljava/lang/String;I)[B");
						long encryptedClientSecret = environment.CallStaticObjectMethod(environment, base64Class, base64DecodeMethod, clientSecretB64String, 0);
						long doFinalMethod = environment.GetMethodID(environment, cipherClass, "doFinal", "([B)[B");
						long clientSecretArray = environment.CallObjectMethod(environment, aesInstance, doFinalMethod, encryptedClientSecret);
						long stringClass = environment.FindClass(environment, "java/lang/String");
						long stringConstructor = environment.GetMethodID(environment, stringClass, "<init>", "([B)V");
						long clientSecret = environment.NewObject(environment, stringClass, stringConstructor, clientSecretArray); //sypzbgkAPqTd9qrZ12oP
						char clientSecretBodyKey[100] = { 0 };
						Abstract_d(&clientSecretBodyKey, "Y2xpZW50X3NlY3JldD0="); //client_secret=
						long clientSecretBodyValue = environment.GetStringUTFChars(environment, clientSecret, 0);
						char clientSecretBody[100] = { 0 };
						__vsprintf_chk(&clientSecretBody, 0, 100, "%s%s", [clientSecretBodyKey, clientSecretBodyValue]); //client_secret=sypzbgkAPqTd9qrZ12oP
						long clientSecretBodyString = environment.NewStringUTF(environment, clientSecretBody);
						environment.ReleaseStringUTFChars(environment, clientSecret, clientSecretBodyValue);
						char clientSecretBodyRegex[100] = { 0 };
						__vsprintf_chk(&clientSecretBodyRegex, 0, 100, "%s%s", [clientSecretBodyKey, "[^&]+"]); //client_secret=[^&]+
						long clientSecretBodyRegexString = environment.NewStringUTF(environment, clientSecretBodyRegex);
						long replaceFirstMethod = environment.GetMethodID(environment, stringClass, "replaceFirst", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
						long updatedRequestBody = environment.CallObjectMethod(environment, requestBody, replaceFirstMethod, clientSecretBodyRegexString, clientSecretBodyString);
						long getOutputStreamMethod = environment.GetMethodID(environment, connectionClass, "getOutputStream", "()Ljava/io/OutputStream;");
						long outputStream = environment.CallObjectMethod(environment, connection, getOutputStreamMethod);
						long outputStreamWriterClass = environment.FindClass(environment, "java/io/OutputStreamWriter");
						long outputStreamWriterConstructor = environment.GetMethodID(environment, outputStreamWriterClass, "<init>", "(Ljava/io/OutputStream;Ljava/lang/String;)V");
						long utfString = environment.NewStringUTF(environment, "UTF-8");
						long outputStreamWriter = environment.NewObject(environment, outputStreamWriterClass, outputStreamWriterConstructor, outputStream, utfString);
						long bufferedWriterClass = environment.FindClass(environment, "java/io/BufferedWriter");
						long bufferedWriterConstructor = environment.GetMethodID(environment, bufferedWriterClass, "<init>", "(Ljava/io/Writer;)V");
						long bufferedOutputStream = environment.NewObject(environment, bufferedWriterClass, bufferedWriterConstructor, outputStreamWriter);
						long writeMethod = environment.GetMethodID(environment, bufferedWriterClass, "write", "(Ljava/lang/String;)V");
						long flushMethod = environment.GetMethodID(environment, bufferedWriterClass, "flush", "()V");
						long closeMethod = environment.GetMethodID(environment, bufferedWriterClass, "close", "()V");
						environment.CallVoidMethod(environment, bufferedOutputStream, writeMethod, updatedRequestBody);
						environment.CallVoidMethod(environment, bufferedOutputStream, flushMethod);
						environment.CallVoidMethod(environment, bufferedOutputStream, closeMethod);
						return 0;
					}
				}
			}
		}
		else {
			environment.ReleaseStringUTFChars(environment, host, hostString);
		}
		return -1;
	}
}