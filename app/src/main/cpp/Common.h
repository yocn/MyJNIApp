//
// Created by 赵英坤 on 2019/4/8.
//

#ifndef MYJNIAPP_COMMON_H
#define MYJNIAPP_COMMON_H

#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,"yoyo_JNI_utils",__VA_ARGS__)

#define JNI_METHOD_NAME(name) Java_com_yocn_mycapplication_nativelib_NativeJni_##name


#endif //MYJNIAPP_COMMON_H
