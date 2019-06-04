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

std::map<int, std::vector<int> > *map = new std::map<int, std::vector<int> >();

JNIEXPORT void JNICALL JNI_METHOD_NAME(init)(JNIEnv *env, jclass type, jint size) {
    for (int i = 0; i < size; i++) {
        std::vector<int> *vector = new std::vector<int>();
        for (int j = 0; j < 10; ++j) {
            vector->push_back(j * 10);
        }
        map->insert(std::pair<int, std::vector<int> >(i, *vector));
    }
    u_long mapSize = map->size();
    LOGE("mapSize---->%ld", mapSize);
    for (int i = 0; i < map->size(); ++i) {
        std::vector<int> child = (*map)[i];
        LOGE("child %d->%ld", i, child.size());
    }
}

JNIEXPORT jlong JNICALL JNI_METHOD_NAME(getVectorAddr)(JNIEnv *env, jclass type, jint index) {
    return (long) map;
}

JNIEXPORT void JNICALL JNI_METHOD_NAME(getVector)(JNIEnv *env, jclass type, jlong addr) {
    std::map<int, std::vector<int> > *newMap = (std::map<int, std::vector<int> > *) addr;
    u_long mapSize = newMap->size();
    LOGE("new mapSize---->%ld", mapSize);
    LOGE("%ld", addr);
    for (int i = 0; i < newMap->size(); ++i) {
        std::vector<int> child = (*newMap)[i];
        LOGE("a  child %d->%ld", i, child.size());
    }
}

JNIEXPORT jstring JNICALL JNI_METHOD_NAME(stringFromJNI)(JNIEnv *env, jclass type) {
    std::string hello = "Hello from Native C++";
    return env->NewStringUTF(hello.c_str());
}


