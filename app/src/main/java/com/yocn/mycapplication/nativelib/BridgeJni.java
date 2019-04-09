package com.yocn.mycapplication.nativelib;

/**
 * @Author yocn
 * @Date 2019/4/8 1:51 PM
 * @ClassName BridgeJni
 */
public class BridgeJni {

    private long mCHandle;

    static {
        System.loadLibrary("native-lib");
    }

    public BridgeJni() {
        setup(this);
    }

    public native void setup(Object obj);

}
