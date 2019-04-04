package com.yocn.mycapplication.nativelib;

/**
 * @Author yocn
 * @Date 2019/4/4 1:38 PM
 * @ClassName NativeJni
 */
public class NativeJni {
    static {
        System.loadLibrary("native-lib");
    }

    public static native String stringFromJNI();

    public static native void init(int size);

    public static native long getVectorAddr(int index);

    public static native void getVector(long addr);


}
