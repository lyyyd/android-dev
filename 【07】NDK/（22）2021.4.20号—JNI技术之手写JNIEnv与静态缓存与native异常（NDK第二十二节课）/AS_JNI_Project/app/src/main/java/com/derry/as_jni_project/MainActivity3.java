package com.derry.as_jni_project;

import android.os.Bundle;
import android.util.Log;
import android.view.View;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity3 extends AppCompatActivity {
    static {
        System.loadLibrary("native-lib");
    }

    static String name1 = "T1";

    // 下面是异常处理
    public static native void exception();
    public static native void exception2() throws NoSuchFieldException; // NoSuchFieldException接收C++层抛上来的异常
    public static native void exception3();

    public static native String derryAction();

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void exceptionAction(View view) {
        exception(); // C++层自己做了补救措施了

        // 捕获人家C++层抛上来的异常
        try {
            exception2();
        } catch (NoSuchFieldException exception) {
            exception.printStackTrace();
            Log.d("Derry", "exceptionAction: 异常被我捕获了");
        }

        exception3();

        String result = derryAction();
    }

    // 专门给 C++（native层） 层调用的 函数
    public static void show() throws Exception {
        Log.d("Derry", "show: 1111");
        Log.d("Derry", "show: 1111");
        Log.d("Derry", "show: 1111");
        Log.d("Derry", "show: 1111");
        Log.d("Derry", "show: 1111");
        Log.d("Derry", "show: 1111");

        throw new NullPointerException("我是Java中抛出的异常，我的show方法里面发送了Java逻辑错误");
    }

}
