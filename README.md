# Wakanim API

My write-up to the successful attempt to reverse engineer the Wakanim API used in the android app.

### Why the Android App?

Wakanim does not use a real API on the web version and instead, all the content is rendered server side. They also use Incapsula to protect their site, and it makes it pretty annoying (not impossible) to use a web scraper there. I made a web scraper for it in the past and bypassed Incapsula using [puppeteer](https://pptr.dev/), remote captcha solving using [Holz](https://github.com/Frooastside/Holz) and [Holz-Desktop](https://github.com/Frooastside/Holz-Desktop) (with a public instance hosted at [holz.wolkeneis.dev](https://holz.wolkeneis.dev)), and some puppeteer-extra plugins. Using the Android App API ensures valid results even if they change their web player and makes it easier to use.

## Reversing the API

### Requirements

- Windows (not strictly required, but some tools I used are only available on Windows.)
- [Android Studio](https://developer.android.com/studio) with Emulator installed
> **Warning**
> Make sure you use a Google APIs Image instead of Google Play Store image because getting root on one of these requires additional steps.
- Wakanim App installed on the Emulator
> **Note**
> Without the Google Play Store, you can get the App from your regular Android phone or online from something like [APK Mirror](https://www.apkmirror.com/apk/wakanim-production/wakanim/)
- Android debug bridge (ADB) binaries
> **Note**
> These binaries get shipped with Android Studio and on Windows you usually can find them in `%localappdata%/Android/Sdk/platform-tools` 
- Network Traffic analyzer like [Fiddler](https://www.telerik.com/download/fiddler) or [HttpToolkit](https://httptoolkit.com/) (I used Fiddler and the Tutorial expects you to use it if you want to follow.)
- [Byte Code Viewer](https://github.com/Konloch/bytecode-viewer/releases)
- [Ghidra](https://github.com/NationalSecurityAgency/ghidra/releases)

### Setting up the Analyzer

I at first attempted to just look at all the API requests using a program like Fiddler Classic or HttpToolkit while having the app open on the android emulator. I decided to use Fiddler, but to use it with external devices or in this case the Android emulator, I had to enable it in the Fiddler Settings: `Tools > Options... > Connections > Allow remote computers to connect`. After that, I just set up the emulator to use the proxy with the local IP address "10.0.2.2", and the default fiddler proxy port "8888".

> **Note**
> The IP address "10.0.2.2" is used in the Android Emulator to always represent the host computer, where in my case, Fiddler is running.

> **Note**
> If you have problems settings up the Proxy with your android emulator, or it simply does not work, check out [Setup a proxy with your emulator](#manually-setting-the-proxy-of-the-android-emulator)

Only doing that just allowed me to analyze unsecured HTTP traffic, but the App uses HTTPS. Fiddler has the capability to decrypt HTTPS traffic, but it is not enabled by default. I enabled it in here: `Tools > Options... > HTTPS > Decrypt HTTPS traffic`. Fiddler then generates a certificate that is used to sign the messages that the Android emulator receives. But because everybody could generate such a certificate, the emulator does not trust it yet. Fixing that, was as simple as, exporting the certificate via `Tools > Options... > HTTPS > Actions > Export Root Certificate to Desktop`, then copying it via

```bash
adb push %userprofile%/Desktop/FiddlerRoot.cer /sdcard/FiddlerRoot.cer
```

And on the emulator, installing it in the file explorer by clicking on it. I then checked if it is installed in the settings app under `Security & location > Advanced > Encryption & credentials > Trusted credentials > User`. However, I was still not finished yet, because starting with Android 5, user installed certificates are not trusted by default and to work with all apps, is has to be in the "System" Tab instead. Since Android 11, this gets even more enforced[^android-11-certificates]. The method shown below only works for emulators with API level < 29 (only up to Android 9) after that, it is harder to mount the system partition any you have to follow extra steps additional to `-writable-system`[^github-comment]

[^android-11-certificates]: https://httptoolkit.com/blog/android-11-trust-ca-certificates/
[^github-comment]: https://gist.github.com/pwlin/8a0d01e6428b7a96e2eb?permalink_comment_id=3927718#gistcomment-3927718

> **Note**
> Make sure you select "Apps and VPN" in the installation step or it will not be in the required directory.

### Moving the certificate into the system certificate store

#### Prepare emulator

User installed certificates are located under `/data/misc/user/0/cacerts-added/<hash>.o`, but it has to be in `/system/etc/security/cacerts/`. As the destination path is in the system partition, I had to start the emulator with the `-writable-system` flag like this:

```bash
%localappdata%/Android/Sdk/emulator/emulator.exe -writable-system -avd <AVD Name>
```

> **Note**
> You can get a list of available AVDs (Android Virtual Device) with:
>```bash
> %localappdata%/Android/Sdk/emulator/emulator.exe -list-avds
>```

Get yourself root permissions on the emulator:

```bash
adb root
```

#### Android API level > 28

If you are on a device with API level > 28 (Starting from Android 10) you now have to make the system partition writable. 

Then you have to disable secure boot verification:

```bash
adb shell avbctl disable-verification
```

reboot the device afterwards:

```bash
adb reboot
```

and remount the system partition before going to the next step:

```bash
adb remount
```

#### Copying the certificate

Then in the last step, I copied the only file in `/data/misc/user/0/cacerts-added/` into the `/system/etc/security/cacerts/` folder using:
```
adb shell cp /data/misc/user/0/cacerts-added/<hash>.o /system/etc/security/cacerts/
```

> **Note**
> You can get the name of the certificate found in `/data/misc/user/0/cacerts/` by using
>```bash
> adb shell ls /data/misc/user/0/cacerts-added/
>```

And after opening a website that uses HTTPS in chrome on the emulator, I immediately saw the traffic in Fiddler.

### SSL Pinning

I thought it would be as easy as that, but after trying to log into an account, I saw that the App does say, that there is a problem with the network connection, even if there is not. That comes from the app using SSL certificate pinning[^certificate-pinning-explained]. That just means that it does check if the certificate that was used to sign the messages, is actually the one expected to do it and not, like in our case, something like the Fiddler Root certificate. Using [Frida](https://frida.re) to defeat the SSL pinning[^defeat-ssl-pinning] is probably one of the easiest solutions. I began by downloading the Frida server archive from [their GitHub repository](https://github.com/frida/frida/releases/), choosing the latest android server archive with my emulator architecture, in this case, ["frida-server-16.0.8-android-x86_64.xz"](https://github.com/frida/frida/releases/download/16.0.8/frida-server-16.0.8-android-x86_64.xz), unpacking it and using the following command to copy the binary to the emulator file system:

```bash
adb push ./frida-server-16.0.8-android-x86_64 /data/local/tmp/frida-server
```

and then I ran the server in the background using the following command:

```bash
adb shell /data/local/tmp/frida-server &
```

[^certificate-pinning-explained]: https://owasp.org/www-community/controls/Certificate_and_Public_Key_Pinning
[^defeat-ssl-pinning]: https://httptoolkit.com/blog/frida-certificate-pinning/

The server is running and ready to receive a frida script. I was lazy and just used [this one](https://github.com/httptoolkit/frida-android-unpinning) and ran it using:

```bash
frida -U -l ./frida-script.js -f wakanimapp.wakanimapp
```

I finally could see some API requests, their content and what the server responded. The only thing still not working, was logging into the account, and it still said, that there is a problem with the network connection. If I logged in while the proxy was disabled and re-enabled it later, I could still see all other network requests. But the other routes are completely useless without the access token from the login request. The weird thing was, that it seemed that SSL pinning was disabled, and it was, but only for the Java code running. The Frida script gave a hint about this problem:

```log
Unpinning Android app...
[+] SSLPeerUnverifiedException auto-patcher
[+] HttpsURLConnection (setDefaultHostnameVerifier)
[+] HttpsURLConnection (setSSLSocketFactory)
[+] HttpsURLConnection (setHostnameVerifier)
[+] SSLContext
[+] TrustManagerImpl
...
[+] Android WebViewClient (SslErrorHandler)
...
Unpinning setup completed
---
  --> Bypassing TrustManagerImpl checkTrusted
  --> Unexpected SSL verification failure, adding dynamic patch...
      Thrown by com.wakanim.wakanimapp.test.wakanimWebclient.WakanimWebClient->p1
      Attempting to patch automatically...
      [+] com.wakanim.wakanimapp.test.wakanimWebclient.WakanimWebClient->p1 (automatic exception patch)
```

The script I used has two methods.
1. It automatically patches common methods of SSL Pinning by some libraries.
1. It waits for a `SSLPeerUnverifiedException` exception to be thrown and just bypasses the whole method where it originated.

The first method actually disabled the default SSL pinning in the Wakanim App, used for almost all API requests, except for the login request. While logging in, the exception gets thrown by their custom check, and just bypassing it makes the request fail. I was confused by why the request failed and checked it out in fiddler. And there was the next hint on what was going wrong:

```
POST https://account.wakanim.tv/core/connect/token HTTP/1.1
Content-Type: application/x-www-form-urlencoded
charset: utf-8
Accept-Language: en
X-DeviceType: Google
X-AppVersion: 7.1.0
X-DeviceVersion: Android SDK built for x86_64
X-SoftwareVersion: 9 P
User-Agent: Dalvik/2.1.0 (Linux; U; Android 9; Android SDK built for x86_64 Build/PSR1.180720.122)
Host: account.wakanim.tv
Connection: Keep-Alive
Accept-Encoding: gzip
Content-Length: 0

(Body would be here if there was any)
```

And yes, that is the whole request. It specified `Content-Type: application/x-www-form-urlencoded` but the Body is empty (`Content-Length: 0`).

### Decompiling and Reverse Engineering

So it was time to actually look into the code of it. I started by downloading [Byte Code Viewer](https://github.com/Konloch/bytecode-viewer/releases) and I collected the URL of the token endpoint (`https://account.wakanim.tv/core/connect/token`) and the exception that was thrown by the app (`com.wakanim.wakanimapp.test.wakanimWebclient.WakanimWebClient->p1`).

#### (Reconstructed) `WakanimWebClient.class` 
```java
  ...
  
  private void p1(X509TrustManagerExtensions trustManager, HttpsURLConnection connection, String... arguments) {
    String body = arguments.length > 0 ? arguments[0] : null;
    int returnCode = process(body, connection, trustManager);
    if (returnCode != 0) {
      StringBuilder errorMessage = new StringBuilder();
      errorMessage.append("Failed to sanitize request. \n");
      errorMessage.append(returnCode);
      throw new SSLPeerUnverifiedException(errorMessage.toString());
    }
  }
  
  public static native int process(String body, URLConnection connection, X509TrustManagerExtensions trustManager);

  ...
```

Looking into the method and refactoring it a little bit reveals, that as I guessed, the signature verification does not happen in Java but in a native library. To be able to find out what which variables are, I again used Frida with the following script:

```javascript
setTimeout(() =>  {
  Java.perform(() => {
    const wakanimWebClient = Java.use(
      "com.wakanim.wakanimapp.test.wakanimWebclient.WakanimWebClient"
    );
    wakanimWebClient.p1.implementation = (trustManager, connection, arguments) => {
      const returns = this.p1(trustManager, connection, arguments);
      console.log("WakanimWebClient -> p1", arguments);
      return returns;
    };
  });
}, 0);
```

> **Note**
> You pretty much can do this with every function you find with the decompiler, and that with only some slight modifications. I will continue using this with modifications without providing the exact source of it.

The main reason I hooked the function was that I wasn't sure what the third argument was. After executing it and trying to log in, we see something that looks like we would expect the missing body of the token endpoint would look like (Modified for readability):

```text
client_id=wakanim.android.test2
&grant_type=password
&response_type=code+id_token+token
&client_secret=FA2P0X10
&username=<EMAIL>
&password=<PASSWORD>
&scope=email+openid+profile+offline_access+read
&redirect_uri=wakanimandroidapp://callback
&nonce=<SOME RANDOM UUID>
&state=<SOME RANDOM UUID>
```

But it would be too simple just using that and getting an access token. If we do that, we get the same `{"error":"invalid_client"}` response as without a body. So before digging into the native library, I thought I would search where p1 actually gets called from. It was as easy as searching for the token URL path (`/core/connect/token`) that is found also in `WakanimWebClient` and stored as a static variable. After searching for usages of it, I traced it back to `WakanimWebClient$i1.class`.

#### (Decompiled) `WakanimWebClient$i1.class` 
```java
public j a(String... var1) {
  ...
  
  connection.setConnectTimeout(60000);  
  connection.connect();  
  WakanimWebClient var43 = this.c;  
  WakanimWebClient.c(var43, WakanimWebClient.x(var43), connection, new String[]{var1[0]});
  responseCode = connection.getResponseCode();

  ...
}
```

> **Note**
> When working with this decompiled code it is good to know that,
> 1. the standard java HTTP implementation lets you write the request body between connection.connect() and calling any response related method, like in this case the getResponseCode() method
> 1. the java compiler is simplifying a lot of stuff if more information is not required and in this case, it is also obfuscated which makes working with it more unpleasant

At the first look it looks pretty complicated but after analyzing it a bit it just simplifies to following pseudocode:

#### (Reconstructed) `WakanimWebClient$i1.class`
```java
public Response makeRequest(String requestBody) {
  ...
  
  connection.setConnectTimeout(60000);
  connection.connect();
  webClient.p1(webClient.getTrustManager(), connection, requestBody);
  int responseCode = connection.getResponseCode();

  ...
}
```

So that is the last proof that we actually need to tackle the native lib. But what lib? Finding that out was pretty easy, because in the constructor of the `WakanimWebClient` class, there is this expression `System.loadLibrary("sanitizer");` and inside the APK there are multiple versions (for the different architectures) of the file `libsanitizer.so` I used Ghidra for the analysis of the library, but you can also use other Tools like IDA. The library exports a lot of functions, but the one that we're interested in is obviously `Java_com_wakanim_wakanimapp_test_wakanimWebclient_WakanimWebClient_process`. Ghidra can reconstruct C code from the assembly, and I started by looking at the function declaration in the [decompiled C code](./decompiled_libsanitizer.process.c):

#### (Reconstructed) libsanitizer.so → process
```c

undefined8 Java_com_wakanim_wakanimapp_test_wakanimWebclient_WakanimWebClient_process
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,long *param_9,
          undefined8 param_10,long param_11,undefined8 param_12,long param_13) {
...

...
}

```

Ok first let's replace `undefined8` with the appropriate data type, an unsigned integer with 64 bits. Also by looking at the assembly code, that resulted in this c code, we can say that the first 8 parameters are actually just the 128 bit XMM registers of the CPU:

```
 uint64            RAX:8          <RETURN>
 uint64            XMM0_Qa:8      param_1
 undefined4        XMM1_Da:4      param_2
 undefined4        XMM2_Da:4      param_3
 undefined4        XMM3_Da:4      param_4
 undefined4        XMM4_Da:4      param_5
 undefined4        XMM5_Da:4      param_6
 undefined4        XMM6_Da:4      param_7
 undefined4        XMM7_Da:4      param_8
 long *            RDI:8          param_9
 uint64            RSI:8          param_10
 long              RDX:8          param_11
 uint64            RCX:8          param_12
 long              R8:8           param_13
```

But that still leaves us with 5 instead of the 3 parameters we would expect, right? Actually no, because the used JNI (Java Native Interface) specification states:

> The JNI interface pointer is the first argument to native methods. The JNI interface pointer is of type _JNIEnv_. The second argument differs depending on whether the native method is static or nonstatic. The second argument to a nonstatic native method is a reference to the object. The second argument to a static native method is a reference to its Java class.[^jni-specification-design]

[^jni-specification-design]: https://docs.oracle.com/javase/7/docs/technotes/guides/jni/spec/design.html

So `param_9` equals the JNI environment, `param_10` the `WakanimWebClient` class, `param_11` the request body, `param_12` the connection and `param_13` equals the trust manager. We can also see that we get the arguments as pointers to the actual values. The next part is just of variable declarations, and we can almost completely ignore them, except if we want to know what type a variable actually is.

```c
bool bVar1;
char cVar2;
...

...
undefined4 local_48;
long local_38;
```

The actual content of the function is pretty much just java code executed with the JNI. Let's have a look at it.

```c
uint64 Java_com_wakanim_wakanimapp_test_wakanimWebclient_WakanimWebClient_process
	(long *jniEnvironment, uint64 webClient, long requestBody, uint64 connection, long trustManager) {
	...

	...
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
	    ...
	
		...
}
```

That looks very complicated, but if you understand what it actually does, you can easily understand pretty much all you need to be able to send a token request yourself. Let's look at the first line: 
```c
uVar6 = (**(code **)(*param_9 + 0x30))(param_9,"java/net/URLConnection");
```

`uVar6` Got initialized in the first section of the function and is of the type `uint64`. `(**(code **)(*param_9 + 0x30))` also looks complicated but is actually just a fancy way to say: "give me the function at an offset of 0x30 of `param_9` (the JNI environment as we found out earlier)". You might ask: "what function is at an offset of 0x30?". That's a good question, and the answer can again be found in the JNI specifications:

> Each function is accessible at a fixed offset through the _JNIEnv_ argument. The _JNIEnv_ type is a pointer to a structure storing all JNI function pointers.
> 
> The VM initializes the function table, as shown by [Code Example 4-1](https://docs.oracle.com/javase/7/docs/technotes/guides/jni/spec/functions.html#wp2556).

That means you can just take the offset, as an example we take the 0x30 from above, convert it to decimal (48), device it by 8 (6), and just take the 7th (don't forget counting from 0) function from the [JNI specification](./jni_spec.c), in this case `FindClass`.

So in the end, we can simplify the code from above into:

```c
uint64 urlConnectionClass = environment.FindClass(environment, "java/net/URLConnection");
```

That actually makes it a lot more understandable. If we also do the for the following lines, we get something like this:

```c
uint64 getURLMethod = environment.GetMethodID(environment, urlConnectionClass, "getURL", "()Ljava/net/URL;");
uint64 url = environment.CallObjectMethod(environment, connection, getURLMethod);
uint64 urlClass = environment.GetObjectClass(environment, url);
uint64 getHostMethod = environment.GetMethodID(environment, urlClass, "getHost", "()Ljava/lang/String;");
uint64 host = environment.CallObjectMethod(environment, url, getHostMethod);
char* hostString = (char *) environment.NewStringUTF(environment, host, 0);
```

While that is still not the easiest way to write Java code, in the end it is still just Java (I mean it's not, but it works the same way because it interacts with the JVM). The next line also seems weird (for convenience, I added the type definition to the line):

```c
byte local_58[16] = ZEXT816(0);
```

But the built-in method of Ghidra `ZEXT816` just takes the supplied 8 byte value and converts it to a 16 byte value by "**Z**ero **EXT**ending" it (putting zeros in front of it), and stores it in the byte array `local_58` with the length of 16. Why are we doing this? Probably because they actually will store a string, and use it to allocate the necessary space beforehand. Except for `local_a8`, the values get never used and are just placeholders. `local_a8` is used in the next line:

```c
Abstract_d(local_a8,(byte *)"YWNjb3VudC53YWthbmltLnR2");
```

To be honest, I did not actually look through the implementation because I think it is unnecessary. Looking at `YWNjb3VudC53YWthbmltLnR2` gives me the feeling we are working with a base64 value here. And if we decode it ("account.wakanim.tv") and look into the next few lines (I changed it for understandability):

```java
String expectedHost = base64Decode("YWNjb3VudC53YWthbmltLnR2"); // "account.wakanim.tv"
boolean hostIsCorrect = hostString.equals(expectedHost); //(hostString is from above)
if (hostIsCorrect) {
  ...
  //go on
  ...
} else {
  ...
  //return non null exit code
  ...
}
```

We can already see that this is probably true. The rest of the function is just stuff we have already covered, except for the function `FUN_00103e00`. When we look at the first use of it we can already make some assumptions about it:

```c
FUN_00103e00(0,param_2,param_3,param_4,param_5,param_6,param_7,param_8,local_118,100,"%s%s%s",uVar11,uVar12,uVar13,in_stack_fffffffffffffd18);
```

The first 8 arguments are just the XMM registers. The next one there is `local_118` which got also allocated like `local_a8` above:

```c
byte local_c8[16] = ZEXT816(0);
byte local_d8[16] = ZEXT816(0);
byte local_e8[16] = ZEXT816(0);
byte local_f8[16] = ZEXT816(0);
byte local_108[16] = ZEXT816(0);
byte local_118[16] = ZEXT816(0);
```

So `local_118` will probably be a string and the output of `FUN_00103e00`, because right now it is just empty, and before it gets used, there is nothing else accessing it, so it has to be filled by this function. The next argument is just the number 100, and we don't know yet for what it stands. But the next string `%s%s%s` looks interesting, this syntax is also used in Java by the `String.format` function and in C by `printf`. Also, there are exactly 3 arguments next, that got created in the process function before. So my guess, it just combines these 3 values into one string and stores it in `local_118`.  When we look at the code, it actually can get reduced down to this line:

```c
__vsprintf_chk(local_118, 0, 100, "%s%s%s", [uVar11, uVar12, uVar13]);
```

And guess what that functions does:

> The interface __vsprintf_chk() shall function in the same way as the interface vsprintf(), except that __vsprintf_chk() shall check for stack overflow before computing a result.[^__vsprintf_chk]

[^__vsprintf_chk]: https://refspecs.linuxbase.org/LSB_4.0.0/LSB-Core-generic/LSB-Core-generic/libc---vsprintf-chk-1.html

and

> vsprintf - Format a string and place it in a buffer[^vsprintf]

[^vsprintf]: https://github.com/torvalds/linux/blob/master/lib/vsprintf.c

So exactly what we expected. With that information, we can actually reconstruct the whole process function and after that, we're left with something like [this](./reconstructed_libsanitizer.process.c). And because it is almost exclusively calls Java code via the JNI, writing it in Java as well wasn't that hard, if you want to look at it, you can find it [here](./WakanimWebClient.java). If we boil it down to what we actually need and don't have, we end up with this:

```java
  public static final byte[] DECRYPTION_KEY = { (byte) 0x01, (byte) 0x01, (byte) 0x0D, (byte) (byte) 0xF7, (byte) 0x86, (byte) 0x58, (byte) 0x86, (byte) 0x2A,
      (byte) 0x08, (byte) 0x06, (byte) 0x0D, (byte) 0x36, (byte) 0x22, (byte) 0x05, (byte) 0x82, (byte) 0x30 };
  public static final String FirebaseUID = "DboH6X1KLQ08RT6";
  public static final String SecurityStoreUID = "pyumur0D+ejcXhI";
  public static final String ActivityMetric = "/kpz++Ak9Q+ss=";


  public static void main(String[] args) throws Exception {
    byte[] encryptedClientSecret = Base64.decode(String.format("%s%s%s", FirebaseUID, SecurityStoreUID, ActivityMetric), 0);
    Cipher aesInstance = Cipher.getInstance("AES");
    aesInstance.init(2, new SecretKeySpec(DECRYPTION_KEY, "AES"));
    String clientSecret = new String(aesInstance.doFinal(encryptedClientSecret), StandardCharsets.UTF_8);
    System.out.println(clientSecret);
  }
```

when run we're left with this, the actual `client_secret` value that gets used instead of `FA2P0X10`: `sypzbgkAPqTd9qrZ12oP`.

So after retriving the full request body, I tried the to find out what rules we have to follow to actually get a response. And it turns out you only need the bare minimum HTTP Headers and any User-Agent also we should not forget the Content-Type `application/x-www-form-urlencoded`, no custom Headers are required. The body is bit more tricky. I thought the specification requires URL encoded keys and values. And also the MDN web docs state that: 

>`application/x-www-form-urlencoded`: the keys and values are encoded in key-value tuples separated by '&', with a '=' between the key and the value. Non-alphanumeric characters in both keys and values are URL encoded: this is the reason why this type is not suitable to use with binary data (use multipart/form-data instead)[^form_urlencoded]

[^form_urlencoded]: https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods/POST

**But with this endpoint you actually don't url encode any keys and for the keys only the `email`, `password` and `redirect_uri` field**. In the end it should look something like this:

```http
POST https://account.wakanim.tv/core/connect/token HTTP/1.1
Host: account.wakanim.tv
Content-Type: application/x-www-form-urlencoded
Content-Length: 300
Connection: keep-alive
Accept: */*
Accept-Encoding: gzip, deflate, br
User-Agent: PostmanRuntime/7.32.3

client_id=wakanim.android.test2&grant_type=password&response_type=code+id_token+token&client_secret=sypzbgkAPqTd9qrZ12oP&username=<URL ENCODED EMAIL>&password=<URL ENCODED PASSWORD>&scope=email+openid+profile+offline_access+read&redirect_uri=wakanimandroidapp%3A%2F%2Fcallback&nonce=<RANDOM UUID>&state=<RANDOM UUID>
```

The response should be a json object that looks somthing like this:

```json
{
    "access_token": "<JWT Authorization Token>",
    "expires_in": 21600,
    "token_type": "Bearer",
    "refresh_token": "<32 digit refresh token>"
}
```

The refresh token allows you to request more tokens after the token expired after 21600 seconds like the request above with some small changes:

```http
POST https://account.wakanim.tv/core/connect/token HTTP/1.1
Host: account.wakanim.tv
Content-Type: application/x-www-form-urlencoded
Content-Length: 300
Connection: keep-alive
Accept: */*
Accept-Encoding: gzip, deflate, br
User-Agent: PostmanRuntime/7.32.3

client_id=wakanim.android.test2&grant_type=refresh_token&refresh_token=<32 digit refresh token>&response_type=code+id_token+token&client_secret=sypzbgkAPqTd9qrZ12oP&scope=email+openid+profile+offline_access+read&redirect_uri=wakanimandroidapp%3A%2F%2Fcallback&nonce=<RANDOM UUID>&state=<RANDOM UUID>
```

The access token now allows you to make all the requests you like with the Bearer HTTP Header with the included access token. Some Endpoints are documented in this repository, including the [Core Endpoint](./reference/wakanim_core.yaml) and the [API Endpoint](./reference/wakanim_api.yaml). The API Endpoint is responsible for all the Content Stuff, while the Core Endpoint is what we already used to get our access token.

### Troubleshooting

#### Manually setting the Proxy of the Android Emulator

In my case, getting the Emulator to use a Proxy was harder than expected because it just did not want to use the proxy in the settings app. But there is an easy workaround using ADB. If you type in the following command, it sets the address you provide to the global proxy of the android system.

Enable:
```bash
adb shell settings put global http_proxy "10.0.2.2:8888"
```

Disable:
```bash
adb shell settings put global http_proxy ":0"
```
