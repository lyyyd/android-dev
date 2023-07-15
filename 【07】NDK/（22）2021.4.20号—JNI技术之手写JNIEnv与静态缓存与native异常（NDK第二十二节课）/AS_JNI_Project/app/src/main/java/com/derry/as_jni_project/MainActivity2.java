package com.derry.as_jni_project;

import android.os.Bundle;
import android.view.View;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

// TODO 02. 静态缓存
public class MainActivity2 extends AppCompatActivity {

    /*MainActivity2() {
        // 初始化静态缓存
        initStaticCache(); // 如果是在类里面， Person Student ，必须在类的构造函数初始化
    }*/

    static {
        System.loadLibrary("native-lib");
    }

    // 假设这里定义了一堆变量
    static String name1  ="T1";
    static String name2  ="T2";
    static String name3  ="T3";
    static String name4  ="T4";
    static String name5  ="T5";
    static String name6  ="T6";
    // ... 省略很多变量
    // ...

    public static native void localCache(String name); // 普通的局部缓存，弊端演示

    // 下面 静态缓存
    public static native void initStaticCache(); // 初始化静态缓存
    public static native void staticCache(String name);
    public static native void clearStaticCache(); // 清除化静态缓存

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    // 事件
    public void staticCacheAction(View view) {
        localCache("AAAA");
        localCache("AAAA");
        localCache("AAAA");
        localCache("AAAA");
        localCache("AAAA");
        localCache("AAAA");
        localCache("AAAA");
        // ...

        // =========================== 下面是静态缓存相关
        // 初始化静态缓存
        initStaticCache(); // 如果是在类里面， Person Student ，必须在类的构造函数初始化

        staticCache("BBB");
        staticCache("BBB");
        staticCache("BBB");
        staticCache("BBB");
        staticCache("BBB");
        staticCache("BBB");
        staticCache("BBB");
        // ....

    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        clearStaticCache(); // 清除化静态缓存
    }
}
