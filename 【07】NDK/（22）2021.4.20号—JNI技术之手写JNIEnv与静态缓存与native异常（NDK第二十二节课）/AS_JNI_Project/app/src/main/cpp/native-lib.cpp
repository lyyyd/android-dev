#include <jni.h>
#include <string>

// 日志输出
#include <android/log.h>

#define TAG "JNISTUDY"
// __VA_ARGS__ 代表 ...的可变参数
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG,  __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG,  __VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG,  __VA_ARGS__);

extern "C" JNIEXPORT jstring JNICALL
Java_com_derry_as_1jni_1project_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

// 比较函数了
int compare(const jint * number1, const jint * number2) {
    return *number1 - *number2;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_derry_as_1jni_1project_MainActivity_sort(JNIEnv *env, jobject thiz, jintArray arr) {
    // 对 arr排序  内置的函数
    jint * intArray = env->GetIntArrayElements(arr, nullptr);

    int length = env->GetArrayLength(arr);

    // NDK 很大的工具链（Java JNI，C++，stdlib ....） 工具箱

    /**
     * 参数1：void * 数组的首地址
     * 参数2：数组的大小长度
     * 参数3：元素的大小
     * 参数4：对比的方法指针
     */
    qsort(intArray, length, sizeof(int),
          reinterpret_cast<int (*)(const void *, const void *)>(compare));

    env->ReleaseIntArrayElements(arr, intArray, 0); // 0 操纵杆 更新KT的数组
}



extern "C"
JNIEXPORT void JNICALL
Java_com_derry_as_1jni_1project_MainActivity2_localCache(JNIEnv *env, jclass clazz, jstring name) {

    // 非静态缓存

    jfieldID f_id = nullptr;

    if (f_id == nullptr) {
        f_id = env->GetStaticFieldID(clazz, "name1", "Ljava/lang/String;"); // 有点耗费性能
    } else  {
        LOGE("空的");
    }

    env->SetStaticObjectField(clazz, f_id, name); // 修改 AAA

    f_id = nullptr;
}




// 像OpenCV，WebRTC，等等 大量使用 静态缓存 ..

static jfieldID f_name1_id = nullptr;
static jfieldID f_name2_id = nullptr;
static jfieldID f_name3_id = nullptr;
static jfieldID f_name4_id = nullptr;
static jfieldID f_name5_id = nullptr;
static jfieldID f_name6_id = nullptr;

// 先缓存
extern "C"
JNIEXPORT void JNICALL
Java_com_derry_as_1jni_1project_MainActivity2_initStaticCache(JNIEnv *env, jclass clazz) {
    f_name1_id = env->GetStaticFieldID(clazz, "name1", "Ljava/lang/String;");
    f_name2_id = env->GetStaticFieldID(clazz, "name2", "Ljava/lang/String;");
    f_name3_id = env->GetStaticFieldID(clazz, "name3", "Ljava/lang/String;");
    f_name4_id = env->GetStaticFieldID(clazz, "name4", "Ljava/lang/String;");
    f_name5_id = env->GetStaticFieldID(clazz, "name5", "Ljava/lang/String;");
    f_name6_id = env->GetStaticFieldID(clazz, "name6", "Ljava/lang/String;");
}

// 使用
extern "C"
JNIEXPORT void JNICALL
Java_com_derry_as_1jni_1project_MainActivity2_staticCache(JNIEnv *env, jclass clazz, jstring name) {
    // 不会反复 GetStaticFieldID 提供性能
    env->SetStaticObjectField(clazz, f_name1_id, name);
    env->SetStaticObjectField(clazz, f_name2_id, name);
    env->SetStaticObjectField(clazz, f_name3_id, name);
    env->SetStaticObjectField(clazz, f_name4_id, name);
    env->SetStaticObjectField(clazz, f_name5_id, name);
    env->SetStaticObjectField(clazz, f_name6_id, name);
}

// 清除
extern "C"
JNIEXPORT void JNICALL
Java_com_derry_as_1jni_1project_MainActivity2_clearStaticCache(JNIEnv *env, jclass clazz) {
    f_name1_id = nullptr;
    f_name2_id = nullptr;
    f_name3_id = nullptr;
    f_name4_id = nullptr;
    f_name5_id = nullptr;
    f_name6_id = nullptr;
}



// 异常1  【native层主动干的异常】
extern "C"
JNIEXPORT void JNICALL
Java_com_derry_as_1jni_1project_MainActivity3_exception(JNIEnv *env, jclass clazz) {
    // 假设现在想操作 name999 ，没有name999就会在native层奔溃掉
    jfieldID f_id = env->GetStaticFieldID(clazz, "name999", "Ljava/lang/String;");

    // 奔溃后，有两种解决方案

    // 方式1 补救措施

    jthrowable thr =  env->ExceptionOccurred(); // 监测本次执行，到底有没有异常   JNI函数里面代码有问题

    if(thr) { // 非0 进去，监测到有异常
        LOGD("C++层有异常 监测到了");

        env->ExceptionClear(); // 此异常被清除

        // 开始 补救措施
        jfieldID f_id = env->GetStaticFieldID(clazz, "name1", "Ljava/lang/String;");
    }


}

// 异常2 【native层主动干的异常】
extern "C"
JNIEXPORT void JNICALL
Java_com_derry_as_1jni_1project_MainActivity3_exception2(JNIEnv *env, jclass clazz) {
    // 假设现在想操作 name999 ，没有name999就会在native层奔溃掉
    jfieldID f_id = env->GetStaticFieldID(clazz, "name8888", "Ljava/lang/String;");

    // 奔溃后，有两种解决方案

    // 方式2 往Java层抛

    jthrowable jthrowable = env->ExceptionOccurred(); // 监测本次执行，到底有没有异常   JNI函数里面代码有问题

    if(jthrowable) { // 非0 进去，监测到有异常
        LOGD("C++层有异常 监测到了");

        env->ExceptionClear(); // 此异常被清除

        // Throw抛一个 Java的对象     java/lang/String    java/xxxxx/xxx/NullExxx
        jclass clz = env->FindClass("java/lang/NoSuchFieldException");
        env->ThrowNew(clz, "NoSuchFieldException 是在是找不到 name8888啊，没有办法，抛给你了");
    }
}

// 异常3 【native层被动干的异常  被动 我是Java方法坑了】
extern "C"
JNIEXPORT void JNICALL
Java_com_derry_as_1jni_1project_MainActivity3_exception3(JNIEnv *env, jclass clazz) {
    jmethodID showID = env->GetStaticMethodID(clazz, "show", "()V");
    env->CallStaticVoidMethod(clazz, showID); // 是不是这句话奔溃的   1是   2不是   答：不是，只是他引起的而已

    // ExceptionCheck 《==》 慢慢的奔溃的，相当于给了你空余时间，既然不是马上奔溃，我就可以检测

    // JNI函数里面代码有问题 没有问题，给你空余时间，慢慢的奔溃的
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe(); // 输出描述 信息
        env->ExceptionClear(); // 此异常被清除    业务逻辑控制
    }

    // 注意实现：
    /*// 奔溃后，下面的语句，照样打印
    LOGI("C++层>>>>>>>>>>>>>>>>>>>>>>>>>>>>1");
    LOGI("C++层>>>>>>>>>>>>>>>>>>>>>>>>>>>>2");
    LOGI("C++层>>>>>>>>>>>>>>>>>>>>>>>>>>>>3");
    LOGI("C++层>>>>>>>>>>>>>>>>>>>>>>>>>>>>4");
    LOGI("C++层>>>>>>>>>>>>>>>>>>>>>>>>>>>>5");

    env->NewStringUTF("AAAA"); // 局部引用 奔溃给磨平*/
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_derry_as_1jni_1project_MainActivity3_derryAction(JNIEnv * env, jclass clazz) {

    // c++调用的  有对象 this == evn    env==一级指针
    // jstring jstring1 = env->NewStringUTF("AAAA"); // this 不需要传evn

    // c调用的 没有对象 ，没有this，所以需要传入evn   env==二级指针
    // jstring jstring1 = (*env).NewStringUTF(env, "AAAA");

    return  (env)->NewStringUTF("AAAA");
}

