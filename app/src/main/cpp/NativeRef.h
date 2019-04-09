//
// Created by 赵英坤 on 2019/4/9.
//

#ifndef MYJNIAPP_NATIVEREF_H
#define MYJNIAPP_NATIVEREF_H


#include <jni.h>
#include <string>

class NativeRef {
public:
    NativeRef(JNIEnv *env, jobject thiz, jobject reference, std::string classpath);

    ~NativeRef();

private:
    jclass mClass;
    jobject mReference;
};


#endif //MYJNIAPP_NATIVEREF_H
