package com.derry.as_jni_project

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.TextView

// TODO 01. 数组排序
class MainActivity : AppCompatActivity() {

    // public native String stringFromJNI();
    external fun stringFromJNI(): String

    // public native void sort(int[] arr);
    external fun sort(arr: IntArray)

    // static { System.loadLibrary("native-lib"); }
    companion object {
        init {
            System.loadLibrary("native-lib")
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }

    // 点击事件
    fun sortAction(view: View) {
        val arr = intArrayOf(11, 22, -3, 2, 4, 6, -15)

        sort(arr)

        for (element in arr) {
            Log.e("Derry", "sortAction: " + element.toString() + "\t")
        }
    }


}