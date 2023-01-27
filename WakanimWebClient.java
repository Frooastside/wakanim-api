import java.io.BufferedOutputStream;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.net.URL;
import java.net.URLConnection;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.cert.Certificate;
import java.security.cert.X509Certificate;
import java.util.Arrays;
import java.util.List;

import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import javax.net.ssl.HttpsURLConnection;

import android.net.http.X509TrustManagerExtensions;
import android.util.Base64;

import com.wakanim.wakanimapp.test.WakanimAndroidApplication;
import com.wakanim.wakanimapp.test.wakanimWebclient.WakanimWebClient;
import com.wakanim.wakanimapp.test.WakanimActivity;

class WakanimWebClient {

  public static final byte[] VALID_HASH = {
      (byte) 0xDA,
      (byte) 0xA9,
      (byte) 0xF0,
      0x54,
      (byte) 0x96,
      (byte) 0xEB,
      (byte) 0xA7,
      0x29,
      (byte) 0xC1,
      (byte) 0xEB,
      0x5B,
      0x4A,
      (byte) 0xF9,
      (byte) 0x80,
      (byte) 0xE8,
      (byte) 0xF9,
      0x3B,
      (byte) 0xA3,
      0x52,
      0x0B,
      0x26,
      (byte) 0xB2,
      0x18,
      (byte) 0xB7,
      (byte) 0xC3,
      0x4E,
      (byte) 0x85,
      0x29,
      0x6F,
      0x5C,
      0x2D,
      0x4C
  };
  public static final byte[] DECRYPTION_KEY = { 0x01, 0x01, 0x0D, (byte) 0xF7, (byte) 0x86, 0x58, (byte) 0x86, 0x2A,
      0x08, 0x06, 0x0D, 0x36, 0x22, 0x05, (byte) 0x82, 0x30 };

  public static int process(String requestBody, URLConnection connection, X509TrustManagerExtensions trustManager) {
    URL url = connection.getURL();
    String host = url.getHost();
    if(!host.equals("account.wakanim.tv")) {
      return -1;
    }
    String connectionClassName = connection.getClass().getName();
    if(!connectionClassName.equals("com.android.okhttp.internal.http.HttpsURLConnectionImpl") && !connectionClassName.equals("com.android.okhttp.internal.huc.HttpsURLConnectionImpl"))) {
      return -1;
    }
    MessageDigest sha256Instance = MessageDigest.getInstance("SHA-256");
    HttpsURLConnection httpsServerConnection = (HttpsURLConnection) connection;
    Certificate[] serverCertificates = httpsServerConnection.getServerCertificates();
    int certificateListLength = serverCertificates.length;
    X509Certificate[] certificateArray = Arrays.copyOf(serverCertificates, certificateListLength, X509Certificate[].class);
    List<X509Certificate> orderedCertificateChain;
    try {
     orderedCertificateChain = trustManager.checkServerTrusted(certificateArray, "RSA", host);
    } catch (Exception ignored) {
      return -1;
    }
    int chainLength = orderedCertificateChain.size();
    if(chainLength <= 0) {
      return -1;
    }
    int index = 0;
					boolean certificatesAreValid = true;
    do {
      X509Certificate certificate = orderedCertificateChain.get(index);
      byte[] encodedPublicKey = certificate.getPublicKey().getEncoded();
      sha256Instance.update(encodedPublicKey, 0, encodedPublicKey.length);
      byte[] hash = sha256Instance.digest();
      if(hash.length != 32) {
        break;
      }
      int offset = 0;
      do {
          if ((VALID_HASH[offset * 4] != hash[offset * 4]) ||
            (VALID_HASH[offset * 4 + 1] != hash[offset * 4 + 1]) ||
            (VALID_HASH[offset * 4 + 2] != hash[offset * 4 + 2]) ||
            (VALID_HASH[offset * 4 + 3] != hash[offset * 4 + 3])) {
            certificatesAreValid = false;
          }
					offset++;
      } while (offset < 8);
      index++;
    } while (index < chainLength);
    if(!certificatesAreValid || requestBody.length() <= 0) {
      return -1;
    }
    byte[] encryptedClientSecret = Base64.decode(String.format("%s%s%s", WakanimAndroidApplication.FirebaseUID, WakanimWebClient.SecurityStoreUID, WakanimMetric.ActivityMetric), 0);
    Cipher aesInstance = Cipher.getInstance("AES");
    aesInstance.init(2, new SecretKeySpec(DECRYPTION_KEY, "AES"));
    String clientSecret = new String(aesInstance.doFinal(encryptedClientSecret), StandardCharsets.UTF_8);
    String clientSecretBody = String.format("%s%s", "client_secret=", clientSecret);
    String clientSecretBodyRegex = String.format("%s%s", "client_secret=", "[^&]+");
    String updatedRequestBody = requestBody.replaceFirst(clientSecretBodyRegex, clientSecretBody);
    BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(connection.getOutputStream(), "UTF-8"));
    bufferedWriter.write(updatedRequestBody);
    bufferedWriter.flush();
    bufferedWriter.close();
    return 0;
  }

}