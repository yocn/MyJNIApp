//
// Created by 赵英坤 on 2019/4/8.
//
#include <jni.h>
#include <android/log.h>
#include "Common.h"
#include "NativeRef.h"

extern "C" {
JNIEXPORT void JNICALL JNI_METHOD_NAME(setup)(JNIEnv *env, jobject thiz, jobject reference);
}


JNIEXPORT void JNICALL JNI_METHOD_NAME(setup)(JNIEnv *env, jobject thiz, jobject reference) {

    LOGE("sss");
    NativeRef *native = new NativeRef(env, thiz, reference, std::string("a"));
}