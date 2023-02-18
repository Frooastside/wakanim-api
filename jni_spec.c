const struct JNINativeInterface ... = {
    NULL,                            //0x0
    NULL,                            //0x8
    NULL,                            //0x10
    NULL,                            //0x18
    GetVersion,                      //0x20

    DefineClass,                     //0x28
    FindClass,                       //0x30

    FromReflectedMethod,             //0x38
    FromReflectedField,              //0x40
    ToReflectedMethod,               //0x48

    GetSuperclass,                   //0x50
    IsAssignableFrom,                //0x58

    ToReflectedField,                //0x60

    Throw,                           //0x68
    ThrowNew,                        //0x70
    ExceptionOccurred,               //0x78
    ExceptionDescribe,               //0x80
    ExceptionClear,                  //0x88
    FatalError,                      //0x90

    PushLocalFrame,                  //0x98
    PopLocalFrame,                   //0xa0

    NewGlobalRef,                    //0xa8
    DeleteGlobalRef,                 //0xb0
    DeleteLocalRef,                  //0xb8
    IsSameObject,                    //0xc0
    NewLocalRef,                     //0xc8
    EnsureLocalCapacity,             //0xd0

    AllocObject,                     //0xd8
    NewObject,                       //0xe0
    NewObjectV,                      //0xe8
    NewObjectA,                      //0xf0

    GetObjectClass,                  //0xf8
    IsInstanceOf,                    //0x100

    GetMethodID,                     //0x108

    CallObjectMethod,                //0x110
    CallObjectMethodV,               //0x118
    CallObjectMethodA,               //0x120
    CallBooleanMethod,               //0x128
    CallBooleanMethodV,              //0x130
    CallBooleanMethodA,              //0x138
    CallByteMethod,                  //0x140
    CallByteMethodV,                 //0x148
    CallByteMethodA,                 //0x150
    CallCharMethod,                  //0x158
    CallCharMethodV,                 //0x160
    CallCharMethodA,                 //0x168
    CallShortMethod,                 //0x170
    CallShortMethodV,                //0x178
    CallShortMethodA,                //0x180
    CallIntMethod,                   //0x188
    CallIntMethodV,                  //0x190
    CallIntMethodA,                  //0x198
    CallLongMethod,                  //0x1a0
    CallLongMethodV,                 //0x1a8
    CallLongMethodA,                 //0x1b0
    CallFloatMethod,                 //0x1b8
    CallFloatMethodV,                //0x1c0
    CallFloatMethodA,                //0x1c8
    CallDoubleMethod,                //0x1d0
    CallDoubleMethodV,               //0x1d8
    CallDoubleMethodA,               //0x1e0
    CallVoidMethod,                  //0x1e8
    CallVoidMethodV,                 //0x1f0
    CallVoidMethodA,                 //0x1f8

    CallNonvirtualObjectMethod,      //0x200
    CallNonvirtualObjectMethodV,     //0x208
    CallNonvirtualObjectMethodA,     //0x210
    CallNonvirtualBooleanMethod,     //0x218
    CallNonvirtualBooleanMethodV,    //0x220
    CallNonvirtualBooleanMethodA,    //0x228
    CallNonvirtualByteMethod,        //0x230
    CallNonvirtualByteMethodV,       //0x238
    CallNonvirtualByteMethodA,       //0x240
    CallNonvirtualCharMethod,        //0x248
    CallNonvirtualCharMethodV,       //0x250
    CallNonvirtualCharMethodA,       //0x258
    CallNonvirtualShortMethod,       //0x260
    CallNonvirtualShortMethodV,      //0x268
    CallNonvirtualShortMethodA,      //0x270
    CallNonvirtualIntMethod,         //0x278
    CallNonvirtualIntMethodV,        //0x280
    CallNonvirtualIntMethodA,        //0x288
    CallNonvirtualLongMethod,        //0x290
    CallNonvirtualLongMethodV,       //0x298
    CallNonvirtualLongMethodA,       //0x2a0
    CallNonvirtualFloatMethod,       //0x2a8
    CallNonvirtualFloatMethodV,      //0x2b0
    CallNonvirtualFloatMethodA,      //0x2b8
    CallNonvirtualDoubleMethod,      //0x2c0
    CallNonvirtualDoubleMethodV,     //0x2c8
    CallNonvirtualDoubleMethodA,     //0x2d0
    CallNonvirtualVoidMethod,        //0x2d8
    CallNonvirtualVoidMethodV,       //0x2e0
    CallNonvirtualVoidMethodA,       //0x2e8

    GetFieldID,                      //0x2f0

    GetObjectField,                  //0x2f8
    GetBooleanField,                 //0x300
    GetByteField,                    //0x308
    GetCharField,                    //0x310
    GetShortField,                   //0x318
    GetIntField,                     //0x320
    GetLongField,                    //0x328
    GetFloatField,                   //0x330
    GetDoubleField,                  //0x338
    SetObjectField,                  //0x340
    SetBooleanField,                 //0x348
    SetByteField,                    //0x350
    SetCharField,                    //0x358
    SetShortField,                   //0x360
    SetIntField,                     //0x368
    SetLongField,                    //0x370
    SetFloatField,                   //0x378
    SetDoubleField,                  //0x380

    GetStaticMethodID,               //0x388

    CallStaticObjectMethod,          //0x390
    CallStaticObjectMethodV,         //0x398
    CallStaticObjectMethodA,         //0x3a0
    CallStaticBooleanMethod,         //0x3a8
    CallStaticBooleanMethodV,        //0x3b0
    CallStaticBooleanMethodA,        //0x3b8
    CallStaticByteMethod,            //0x3c0
    CallStaticByteMethodV,           //0x3c8
    CallStaticByteMethodA,           //0x3d0
    CallStaticCharMethod,            //0x3d8
    CallStaticCharMethodV,           //0x3e0
    CallStaticCharMethodA,           //0x3e8
    CallStaticShortMethod,           //0x3f0
    CallStaticShortMethodV,          //0x3f8
    CallStaticShortMethodA,          //0x400
    CallStaticIntMethod,             //0x408
    CallStaticIntMethodV,            //0x410
    CallStaticIntMethodA,            //0x418
    CallStaticLongMethod,            //0x420
    CallStaticLongMethodV,           //0x428
    CallStaticLongMethodA,           //0x430
    CallStaticFloatMethod,           //0x438
    CallStaticFloatMethodV,          //0x440
    CallStaticFloatMethodA,          //0x448
    CallStaticDoubleMethod,          //0x450
    CallStaticDoubleMethodV,         //0x458
    CallStaticDoubleMethodA,         //0x460
    CallStaticVoidMethod,            //0x468
    CallStaticVoidMethodV,           //0x470
    CallStaticVoidMethodA,           //0x478

    GetStaticFieldID,                //0x480

    GetStaticObjectField,            //0x488
    GetStaticBooleanField,           //0x490
    GetStaticByteField,              //0x498
    GetStaticCharField,              //0x4a0
    GetStaticShortField,             //0x4a8
    GetStaticIntField,               //0x4b0
    GetStaticLongField,              //0x4b8
    GetStaticFloatField,             //0x4c0
    GetStaticDoubleField,            //0x4c8

    SetStaticObjectField,            //0x4d0
    SetStaticBooleanField,           //0x4d8
    SetStaticByteField,              //0x4e0
    SetStaticCharField,              //0x4e8
    SetStaticShortField,             //0x4f0
    SetStaticIntField,               //0x4f8
    SetStaticLongField,              //0x500
    SetStaticFloatField,             //0x508
    SetStaticDoubleField,            //0x510

    NewString,                       //0x518

    GetStringLength,                 //0x520
    GetStringChars,                  //0x528
    ReleaseStringChars,              //0x530

    NewStringUTF,                    //0x538
    GetStringUTFLength,              //0x540
    GetStringUTFChars,               //0x548
    ReleaseStringUTFChars,           //0x550

    GetArrayLength,                  //0x558

    NewObjectArray,                  //0x560
    GetObjectArrayElement,           //0x568
    SetObjectArrayElement,           //0x570

    NewBooleanArray,                 //0x578
    NewByteArray,                    //0x580
    NewCharArray,                    //0x588
    NewShortArray,                   //0x590
    NewIntArray,                     //0x598
    NewLongArray,                    //0x5a0
    NewFloatArray,                   //0x5a8
    NewDoubleArray,                  //0x5b0

    GetBooleanArrayElements,         //0x5b8
    GetByteArrayElements,            //0x5c0
    GetCharArrayElements,            //0x5c8
    GetShortArrayElements,           //0x5d0
    GetIntArrayElements,             //0x5d8
    GetLongArrayElements,            //0x5e0
    GetFloatArrayElements,           //0x5e8
    GetDoubleArrayElements,          //0x5f0

    ReleaseBooleanArrayElements,     //0x5f8
    ReleaseByteArrayElements,        //0x600
    ReleaseCharArrayElements,        //0x608
    ReleaseShortArrayElements,       //0x610
    ReleaseIntArrayElements,         //0x618
    ReleaseLongArrayElements,        //0x620
    ReleaseFloatArrayElements,       //0x628
    ReleaseDoubleArrayElements,      //0x630

    GetBooleanArrayRegion,           //0x638
    GetByteArrayRegion,              //0x640
    GetCharArrayRegion,              //0x648
    GetShortArrayRegion,             //0x650
    GetIntArrayRegion,               //0x658
    GetLongArrayRegion,              //0x660
    GetFloatArrayRegion,             //0x668
    GetDoubleArrayRegion,            //0x670
    SetBooleanArrayRegion,           //0x678
    SetByteArrayRegion,              //0x680
    SetCharArrayRegion,              //0x688
    SetShortArrayRegion,             //0x690
    SetIntArrayRegion,               //0x698
    SetLongArrayRegion,              //0x6a0
    SetFloatArrayRegion,             //0x6a8
    SetDoubleArrayRegion,            //0x6b0

    RegisterNatives,                 //0x6b8
    UnregisterNatives,               //0x6c0

    MonitorEnter,                    //0x6c8
    MonitorExit,                     //0x6d0

    GetJavaVM,                       //0x6d8

    GetStringRegion,                 //0x6e0
    GetStringUTFRegion,              //0x6e8

    GetPrimitiveArrayCritical,       //0x6f0
    ReleasePrimitiveArrayCritical,   //0x6f8

    GetStringCritical,               //0x700
    ReleaseStringCritical,           //0x708

    NewWeakGlobalRef,                //0x710
    DeleteWeakGlobalRef,             //0x718

    ExceptionCheck,                  //0x720

    NewDirectByteBuffer,             //0x728
    GetDirectBufferAddress,          //0x730
    GetDirectBufferCapacity,         //0x738

    GetObjectRefType                 //0x740
  };
