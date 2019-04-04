package com.yocn.mycapplication.util;

import android.util.Log;

/**
 * @Author yocn
 * @Date 2019/4/4 2:09 PM
 * @ClassName LogUtils
 */
public class LogUtils {
    public static <T> void d(T msg) {
        Log.d("yocn", msg.toString());
    }
}
