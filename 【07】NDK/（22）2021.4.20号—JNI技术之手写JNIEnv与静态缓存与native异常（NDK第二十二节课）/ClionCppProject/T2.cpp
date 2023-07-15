// JNI 怎么学习？
//    1.JNIEnv 300个函数  常用的函数就行了
//    2.手写JNIEnv

#include <iostream>
#include <string>
using namespace std;

// 模拟 jstring
typedef char * jstring;

// 模拟 jobject
typedef char * jobject;

// 如果是C语言  C++也是会调用C的 JNINativeInterface
typedef const struct JNINativeInterface * JNIEnv; // 定义了一个结构体指针的别名   一级指针

struct JNINativeInterface {
    // 300多个 函数指针 声明 -------  指针函数对应的实现 我们现在看不到 在库
    // ...
    jstring (*NewStringUTF) (JNIEnv *, char *); // 函数指针 声明
};

// 指针函数对应的实现 我们现在看不到 在库
jstring NewStringUTF(JNIEnv * env, char * str) {
    // 注意：在真正的源码中，这里需要很多复杂的代码来转换 （毕竟涉及到跨越语言操作了）， 我们就简写了
    // char * str <---> jstring str
    return str;
}

jstring Java_com_derry_as_1jni_1project_MainActivity3_derryAction(JNIEnv *env, jobject job) {
    // env 已经是二级指针了
    return (*env)->NewStringUTF(env, "9527"); // 函数指针 不起作用
}

// 模拟 紫色区域  内部处理的逻辑 我们看不到
int main() {
    // 构建 JNIEnv *
    struct JNINativeInterface nativeInterface;

    // 把结构体函数指针 进行赋值  （函数指针---实现）
    nativeInterface.NewStringUTF = NewStringUTF;

    // 处理生成好的 JNIEnv * 后，传递给 JNI函数
    JNIEnv env = &nativeInterface;  // 本来就是 一级指针
    JNIEnv * jniEnv = &env; // 二级指针

    jstring result = Java_com_derry_as_1jni_1project_MainActivity3_derryAction(jniEnv, "com/derry/jni/MainActivity");

    // 把jstring 转换 给 Java String 简化了
    // jstring ----->  String
    printf("Java层拿到 C++给我们的 String result:%s", result);
}



