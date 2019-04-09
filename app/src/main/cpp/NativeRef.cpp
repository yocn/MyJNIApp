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
}