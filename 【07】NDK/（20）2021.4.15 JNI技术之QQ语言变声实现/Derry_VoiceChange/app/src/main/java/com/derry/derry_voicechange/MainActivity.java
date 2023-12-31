package com.derry.derry_voicechange;

import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import org.fmod.FMOD;

// TODO 终点：本节课目标：Android NDK 导入 C库，开发流程，一劳永逸，任何C库 都是一样的 非常慢
public class MainActivity extends AppCompatActivity {

    private static final int MODE_NORMAL = 0; // 正常
    private static final int MODE_LUOLI = 1; //
    private static final int MODE_DASHU = 2; //
    private static final int MODE_JINGSONG = 3; //
    private static final int MODE_GAOGUAI = 4; //
    private static final int MODE_KONGLING = 5; //

    static {
        System.loadLibrary("native-lib");
    }

    private String path;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        path =  "file:///android_asset/derry.mp3";

        FMOD.init(this);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        FMOD.close();
    }

    // 六个 点击事件
    public void onFix(View view) {
        switch (view.getId()) {
            case R.id.btn_normal:
                voiceChangeNative(MODE_NORMAL, path); // 真实开发中，必须子线程  JNI线程（很多坑）
                break;
            case R.id.btn_luoli:
                voiceChangeNative(MODE_LUOLI, path);
                break;
            case R.id.btn_dashu:
                voiceChangeNative(MODE_DASHU, path);
                break;
            case R.id.btn_jingsong:
                voiceChangeNative(MODE_JINGSONG, path);
                break;
            case R.id.btn_gaoguai:
                voiceChangeNative(MODE_GAOGUAI, path);
                break;
            case R.id.btn_kongling:
                voiceChangeNative(MODE_KONGLING, path);
                break;
        }
    }

    // 给C++调用的函数
    // JNI 调用 Java函数的时候，忽略掉 私有、公开 等
    private void playerEnd(String msg) {
        Toast.makeText(this, "" +msg, Toast.LENGTH_SHORT).show();
    }

    private native void voiceChangeNative(int modeNormal, String path);
}
