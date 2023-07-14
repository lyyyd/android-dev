// 系统源码里面大量的写法 [特殊写法，意义何在]

#include <iostream>

using namespace std;

// 前期先抽象出现，我后面再升级
// 后面你可以扩展
void JNIMethod(double, double, int, int) {

}

// 上层日志
// 我前期的时候，没有考虑好，为了防止扩展功能，你必须传递一个int类型参数
// 0：服务器同步，   1：友萌服务器同步     2：服务器同步+友萌服务器同步
void uploadLogToEngine(char * logText, int mode) {
    // 普通上传日志

    // 半年过后，我再来补这个功能
    if (mode) {

    } else if (mode == 1) {

    }
}

int main(void) {
    // 前面一个月开发功能的时候
    uploadLogToEngine("xxxxx", 0); // 300出地方调用
    uploadLogToEngine("xxxxx", 2); // 600出地方调用
    uploadLogToEngine("xxxxx", 1); // 400出地方调用

    JNIMethod(9.0 ,9.9, 1, 2);

    return 0;

}
