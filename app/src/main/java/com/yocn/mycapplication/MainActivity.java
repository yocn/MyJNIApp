package com.yocn.mycapplication;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.TextView;

import com.yocn.mycapplication.nativelib.NativeJni;
import com.yocn.mycapplication.util.LogUtils;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_LAYOUT_NO_LIMITS);
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(NativeJni.stringFromJNI());
        Button mStartBtn = findViewById(R.id.btn_start);
        mStartBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                NativeJni.init(10);
                long addr = NativeJni.getVectorAddr(1);
                LogUtils.d(addr);
                NativeJni.getVector(addr);
            }
        });
    }
}
