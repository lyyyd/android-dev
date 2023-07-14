#include <iostream>
#include <stdarg.h> // 可变参数的支持
using namespace std;

// Java的可变参数: int ...
// C++的可变参数写法：...

// count变量的第二个用处，用于循环遍历长度
void sum(int count, ...) {
    va_list vp; // 可变参数的动作

    // 参数一：可变参数开始的动作vp
    // 参数二：内部需要一个 存储地址用的参考值，如果没有第二个参数，内部他无法处理存放参数信息
    va_start(vp, count);

    // 到这里后：vp就已经有丰富的信息

    for (int i = 0; i < count; ++i) {
        int r = va_arg(vp, int);
        cout << r << endl;
    }

    // 关闭阶段（规范：例如：file文件一样 要关闭）
    va_end(vp);
}

// 1.可变参数
int main() {

    sum(3, 6,7,8); // 真实开发过程的写法

    return 0;
}