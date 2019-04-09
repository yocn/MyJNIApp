#include <jni.h>
#include <string>
#include <vector>
#include <map>
#include<android/log.h>

#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,"yoyo_JNI_utils",__VA_ARGS__)

#define JNI_METHOD_NAME(name) Java_com_yocn_mycapplication_nativelib_NativeJni_##name

extern "C" {
JNIEXPORT jstring JNICALL JNI_METHOD_NAME(stringFromJNI)(JNIEnv *env, jclass type);
JNIEXPORT void JNICALL JNI_METHOD_NAME(init)(JNIEnv *env, jclass type, jint size);
JNIEXPORT jlong JNICALL JNI_METHOD_NAME(getVectorAddr)(JNIEnv *env, jclass type, jint index);
JNIEXPORT void JNICALL JNI_METHOD_NAME(getVector)(JNIEnv *env, jclass type, jlong addr);
}

std::map<int, std::vector<int> > map;

JNIEXPORT void JNICALL JNI_METHOD_NAME(init)(JNIEnv *env, jclass type, jint size) {
    for (int i = 0; i < size; i++) {
        std::vector<int> vector;
        for (int j = i * 10; j < 10; ++j) {
            vector.push_back(j);
        }
        map[i] = vector;
    }
    int mapSize = map.size();
    LOGE("%d", mapSize);
}

JNIEXPORT jlong JNICALL JNI_METHOD_NAME(getVectorAddr)(JNIEnv *env, jclass type, jint index) {
//    long long1 = &map[index];
    return (jlong) &map[index];
}

JNIEXPORT void JNICALL JNI_METHOD_NAME(getVector)(JNIEnv *env, jclass type, jlong addr) {
    LOGE("%ld", addr);
}

JNIEXPORT jstring JNICALL JNI_METHOD_NAME(stringFromJNI)(JNIEnv *env, jclass type) {
    std::string hello = "Hello from Native C++";
    return env->NewStringUTF(hello.c_str());
}


