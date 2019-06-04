//
// Created by 赵英坤 on 2019/4/9.
//

#include <string>
#include "NativeRef.h"

//双引号表示NativeRef的构造方法
NativeRef::NativeRef(JNIEnv *env, jobject thiz, jobject reference, std::string classpath) {
    mClass = (*env).GetObjectClass(thiz);
    mReference = env->NewGlobalRef(reference);
}


NativeRef::~NativeRef() {
    int status;
    JNIEnv* _jniEnv = NULL;
    status = (jvm)->GetEnv((void **)&_jniEnv, JNI_VERSION_1_6);

    if(status < 0)
    {
        status = (jvm)->AttachCurrentThread(&_jniEnv, NULL);
        if(status < 0)
        {
            _jniEnv = NULL;
        }
    }
}