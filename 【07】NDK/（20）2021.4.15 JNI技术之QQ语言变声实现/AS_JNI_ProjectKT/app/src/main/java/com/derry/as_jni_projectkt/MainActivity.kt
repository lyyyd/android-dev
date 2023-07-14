package com.derry.as_jni_projectkt

import android.os.Bundle
import android.view.View
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import org.fmod.FMOD

class MainActivity : AppCompatActivity() {

    private val MODE_NORMAL = 0 // 正常
    private val MODE_LUOLI = 1 // 萝莉
    private val MODE_DASHU = 2 // 大叔
    private val MODE_JINGSONG = 3 // 惊悚
    private val MODE_GAOGUAI = 4 // 搞怪
    private val MODE_KONGLING = 5 // 空灵

    companion object {
        init {
            System.loadLibrary("native-lib")
        }
    }

    // 播放的路径
    private val PATH = "file:///android_asset/derry.mp3"

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        FMOD.init(this)
    }

    // 六个 点击事件
    fun onFix(view: View) {
        when (view.id) {
            R.id.btn_normal -> voiceChangeNative(MODE_NORMAL, PATH)
            R.id.btn_luoli -> voiceChangeNative(MODE_LUOLI, PATH)
            R.id.btn_dashu -> voiceChangeNative(MODE_DASHU, PATH)
            R.id.btn_jingsong -> voiceChangeNative(MODE_JINGSONG, PATH)
            R.id.btn_gaoguai -> voiceChangeNative(MODE_GAOGUAI, PATH)
            R.id.btn_kongling -> voiceChangeNative(MODE_KONGLING, PATH)
        }
    }

    /**
     * 下面：native区域
     */
    // private native String stringFromJNI();
    private external fun stringFromJNI(): String
    // private native void voiceChangeNative(int mode, String path);
    private external fun voiceChangeNative(mode: Int, path: String)

    // 给native调用的   方法签名： (Ljava/lang/String;)V
    fun playerEnd(nativeMessageContent: String) {
        Toast.makeText(this, "" + nativeMessageContent, Toast.LENGTH_SHORT).show()
    }

    override fun onDestroy() {
        super.onDestroy()
        FMOD.close(); // 做实验 来验证
    }
}