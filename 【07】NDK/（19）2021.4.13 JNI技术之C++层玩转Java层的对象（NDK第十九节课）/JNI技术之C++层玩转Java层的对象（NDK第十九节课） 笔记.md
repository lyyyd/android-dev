#### JNI技术之C++层玩转Java层的对象（NDK第十九节课） 笔记

### 01-MainActivity统一代码：

```java
package com.kevin.ndk08_code_as;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private final static String TAG = MainActivity.class.getSimpleName();

    static {
        // System.load(); 这种是可以绝对路径的加载动态链接库文件
        System.loadLibrary("native-lib"); // 这种是从库目录遍历层级目录，去自动的寻找
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Log.d(TAG, "onCreate stringFromJNI:" + stringFromJNI());
    }

    /**
     * 下面是 native 区域
     */

    public native String stringFromJNI();

    public native void testArrayAction(int count, String textInfo, int[] ints, String[] strs); // String引用类型，玩数组

    public native void putObject(Student student, String str); // 传递引用类型，传递对象

    public native void insertObject(); // 凭空创建Java对象

    public native void testQuote(); // 测试引用
    public native void delQuote(); // 释放全局引用


    /**
     * 下面是 点击事件区域
     */

    // 点击事件：操作testArrayAction函数
    public void test01(View view) {
        int[] ints = new int[]{1,2,3,4,5,6};
        String[] strs = new String[]{"李小龙","李连杰","李元霸"};
        testArrayAction(99, "你好", ints, strs);

        for (int anInt : ints) {
            Log.d(TAG, "test01: anInt:" + anInt);
        }
    }

    // 点击事件：操作putObject函数 
    public void test02(View view) {
        Student student = new Student();
        student.name = "史泰龙";
        student.age = 88;
        putObject(student, "九阳神功");
    }

    // 点击事件：操作insertObject函数
    public void test03(View view) {
        insertObject();
    }

    // 点击事件：两个函数是一起的，操作引用 与 释放引用
    public void test04(View view) {
        testQuote();
    }
    public void test05(View view) {
        delQuote();
    }
}
```



#### MainActivity 对应的 布局文件：

```xml
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity"
    android:orientation="vertical">

    <TextView
        android:id="@+id/sample_text"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="-"
        />

    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:onClick="test01"
        android:text="test01"
        />

    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:onClick="test02"
        android:text="test02"
        />

    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:onClick="test03"
        android:text="test03"
        />

    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:onClick="test04"
        android:text="test04"
        />

    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:onClick="test05"
        android:text="test05"
        />

</LinearLayout>
```

### 02-Student/Person/Dog 三个实体Bean，统一代码：

**Student**

```java
package com.kevin.ndk08_code_as;

import android.util.Log;

public class Student {

    private final static String TAG = Student.class.getSimpleName();

    public String name;
    public int age;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        Log.d(TAG, "Java setName name:" + name);
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        Log.d(TAG, "Java setAge age:" + age);
        this.age = age;
    }

    public static void showInfo(String info) {
        Log.d(TAG, "showInfo info:" + info);
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }
}
```

**Person:**

```java
package com.kevin.ndk08_code_as;

import android.util.Log;

public class Person {

    private static final String TAG = Person.class.getSimpleName();

    public Student student;

    public void setStudent(Student student) {
        Log.d(TAG, "call setStudent student:" + student.toString());
        this.student = student;
    }

    public static void putStudent(Student student) {
        Log.d(TAG, "call static putStudent student:" + student.toString());
    }
}
```

**Dog:**

```java
package com.kevin.ndk08_code_as;

import android.util.Log;

public class Dog {

    public Dog() {
        Log.d("Dog", "Dog init...");
    }

}
```

### 03-native层的统一代码（native-lib.cpp）：

```cpp
#include <jni.h>
#include <string>
#include <iostream>

// 日志输出
#include <android/log.h>

#define TAG "JNISTUDY"
// __VA_ARGS__ 代表 ...的可变参数
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG,  __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG,  __VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG,  __VA_ARGS__);

using namespace std;

/**
 * JNIEXPORT : Linux 和 Windows jni.h内部的宏定义 是不一样的，此宏代表是 对外暴露的标准形式，
 *             例如：在Windows中 对外暴露的标准已经被规定好了，所以在jni.h中的宏是以Windows对外暴露的标准规则来写的
 *
 * JNICALL ： Linux 和 Windows jni.h内部的宏定义 是不一样的，此宏代表是 此函数形参压栈的规则制定，
 *            例如：在Windows平台中里面的宏定义，代表函数压栈从右到左方式操作的 等等
 */
```



##### 数组操作：

```cpp
// jint == int
// jstring == String
// jintArray == int[]
// jobjectArray == 引用类型对象，例如 String[]   Test[]   Student[]  Person[]
extern "C"
JNIEXPORT void JNICALL
Java_com_derry_as_1jni_1project_MainActivity_testArrayAction(JNIEnv *env, jobject thiz,
                                                             jint count,
                                                             jstring text_info,
                                                             jintArray ints,
                                                             jobjectArray strs) {
    // ① 基本数据类型  jint count， jstring text_info， 最简单的
    int countInt = count; // jint本质是int，所以可以用int接收
    LOGI("参数一 countInt:%d\n", countInt);

    // const char* GetStringUTFChars(jstring string, jboolean* isCopy)
    const char * textInfo = env->GetStringUTFChars(text_info, NULL);
    LOGI("参数二 textInfo:%s\n", textInfo);

    // ② 把int[] 转成 int*
    // jint* GetIntArrayElements(jintArray array, jboolean* isCopy)
    int* jintArray = env->GetIntArrayElements(ints, NULL);

    // Java层数组的长度
    // jsize GetArrayLength(jarray array) // jintArray ints 可以放入到 jarray的参数中去
    jsize size = env->GetArrayLength(ints);

    for (int i = 0; i < size; ++i) {
        *(jintArray+i) += 100; // C++的修改，影响不了Java层
        LOGI("参数三 int[]:%d\n", *jintArray+i);
    }
    // 目前无法控制Java的数组 变化 +100
    // 操作杆 ----> JMV
    // env->

    /**
     * 0:           刷新Java数组，并 释放C++层数组
     * JNI_COMMIT:  只提交 只刷新Java数组，不释放C++层数组
     * JNI_ABORT:   只释放C++层数组
     */
    env->ReleaseIntArrayElements(ints, jintArray, 0);

    // ③：jobjectArray 代表是Java的引用类型数组，不一样
    jsize  strssize = env->GetArrayLength(strs);
    for (int i = 0; i < strssize; ++i) {

        jstring jobj = static_cast<jstring>(env->GetObjectArrayElement(strs, i));

        // 模糊：isCopy内部启动的机制
        // const char* GetStringUTFChars(jstring string, jboolean* isCopy)
        const char * jobjCharp = env->GetStringUTFChars(jobj, NULL);

        LOGI("参数四 引用类型String 具体的：%s\n", jobjCharp);

        // 释放jstring
        env->ReleaseStringUTFChars(jobj, jobjCharp);
    }
}
```



##### Student 对象操作：

```
// jobject student == Student
// jstring str  == String
extern "C"
JNIEXPORT void JNICALL
Java_com_derry_as_1jni_1project_MainActivity_putObject(JNIEnv *env,
                                                       jobject thiz,
                                                       jobject student,
                                                       jstring str) {
    const char * strChar = env->GetStringUTFChars(str, NULL);
    LOGI("strChar：%s\n", strChar);
    env->ReleaseStringUTFChars(str, strChar);

    // --------------
    // 1.寻找类 Student
    // jclass studentClass = env->FindClass("com/derry/as_jni_project/Student"); // 第一种
    jclass studentClass =  env->GetObjectClass(student); // 第二种

    // 2.Student类里面的函数规则  签名
    jmethodID setName = env->GetMethodID(studentClass, "setName", "(Ljava/lang/String;)V");
    jmethodID getName = env->GetMethodID(studentClass, "getName", "()Ljava/lang/String;");
    jmethodID showInfo = env->GetStaticMethodID(studentClass, "showInfo", "(Ljava/lang/String;)V");

    // 3.调用 setName
    jstring value = env->NewStringUTF("AAAA");
    env->CallVoidMethod(student, setName, value);

    // 4.调用 getName
    jstring getNameResult = static_cast<jstring>(env->CallObjectMethod(student, getName));
    const char * getNameValue = env->GetStringUTFChars(getNameResult, NULL);
    LOGE("调用到getName方法，值是:%s\n", getNameValue);

    // 5.调用静态showInfo
    jstring  jstringValue = env->NewStringUTF("静态方法你好，我是C++");
    env->CallStaticVoidMethod(studentClass, showInfo, jstringValue);
}
```



##### 对象进阶

```cpp
extern "C"
JNIEXPORT void JNICALL
Java_com_derry_as_1jni_1project_MainActivity_insertObject(JNIEnv *env, jobject thiz) {
    // 1.通过包名+类名的方式 拿到 Student class  凭空拿class
    const char *studentstr = "com/derry/as_jni_project/Student";
    jclass studentClass = env->FindClass(studentstr);

    // 2.通过student的class  实例化此Student对象   C++ new Student
    jobject studentObj = env->AllocObject(studentClass); // AllocObject 只实例化对象，不会调用对象的构造函数

    // 方法签名的规则
    jmethodID setName = env->GetMethodID(studentClass, "setName", "(Ljava/lang/String;)V");
    jmethodID setAge = env->GetMethodID(studentClass, "setAge", "(I)V");

    // 调用方法
    jstring strValue = env->NewStringUTF("Derry");
    env->CallVoidMethod(studentObj, setName, strValue);
    env->CallVoidMethod(studentObj, setAge, 99);


    // env->NewObject() // NewObject 实例化对象，会调用对象的构造函数


    // ====================  下面是 Person对象  调用person对象的  setStudent 函数等

    // 4.通过包名+类名的方式 拿到 Student class  凭空拿class
    const char *personstr = "com/derry/as_jni_project/Person";
    jclass personClass = env->FindClass(personstr);

    jobject personObj = env->AllocObject(personClass); // AllocObject 只实例化对象，不会调用对象的构造函数

    // setStudent 此函数的 签名 规则
    jmethodID setStudent = env->GetMethodID(personClass, "setStudent",
            "(Lcom/derry/as_jni_project/Student;)V");

    env->CallVoidMethod(personObj, setStudent, studentObj);
}
```



##### 全局引用 局部引用理解：

```cpp
jclass dogClass; // 你以为这个是全局引用，实际上他还是局部引用

extern "C"
JNIEXPORT void JNICALL
Java_com_derry_as_1jni_1project_MainActivity_testQuote(JNIEnv *env, jobject thiz) {
    if (NULL == dogClass) {
        /*const char * dogStr = "com/derry/as_jni_project/Dog";
        dogClass = env->FindClass(dogStr);*/

        // 升级全局引用： JNI函数结束也不释放，反正就是不释放，必须手动释放   ----- 相当于： C++ 对象 new、手动delete
        const char * dogStr = "com/derry/as_jni_project/Dog";
        jclass temp = env->FindClass(dogStr);
        dogClass = static_cast<jclass>(env->NewGlobalRef(temp)); // 提升全局引用
        // 记住：用完了，如果不用了，马上释放，C C++ 工程师的赞美
        env->DeleteLocalRef(temp);
    }

    // <init> V  是不会变的

    // 构造函数一
    jmethodID init = env->GetMethodID(dogClass, "<init>", "()V");
    jobject dog = env->NewObject(dogClass, init);

    // 构造函数2
    init = env->GetMethodID(dogClass, "<init>", "(I)V");
    dog = env->NewObject(dogClass, init, 100);


    // 构造函数3
    init = env->GetMethodID(dogClass, "<init>", "(II)V");
    dog = env->NewObject(dogClass, init, 200, 300);

    // 构造函数4
    init = env->GetMethodID(dogClass, "<init>", "(III)V");
    dog = env->NewObject(dogClass, init, 400, 500, 600);

    env->DeleteLocalRef(dog); // 释放
}

// JNI函数结束，会释放局部引用   dogClass虽然被释放，但是还不等于NULL，只是一个悬空指针而已，所以第二次进不来IF，会奔溃

// 非常方便，可以使用了
extern int age; // 声明age
extern void show(); // 声明show函数

// 手动释放全局引用
extern "C"
JNIEXPORT void JNICALL
Java_com_derry_as_1jni_1project_MainActivity_delQuote(JNIEnv *env, jobject thiz) {
   if (dogClass != NULL) {
       LOGE("全局引用释放完毕，上面的按钮已经失去全局引用，再次点击会报错");
       env->DeleteGlobalRef(dogClass);
       dogClass = NULL; // 最好给一个NULL，指向NULL的地址，不要去成为悬空指针
   }

   // 测试下
   show();
}
```



##### 补充：

```cpp
#include <iostream>

// 日志输出
#include <android/log.h>

#define TAG "JNISTUDY"
// __VA_ARGS__ 代表 ...的可变参数
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG,  __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG,  __VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG,  __VA_ARGS__);

int age = 99; // 实现

void show() { // 实现
    // 5000行代码
    // ...

    LOGI("show run age:%d\n", age);
}



```

