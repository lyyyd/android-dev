#include <iostream>
#include <stdarg.h> // 可变参数的支持
using namespace std;

// Java的可变参数: int ...
// C++的可变参数写法：...
// count的第一个用处：内部需要一个 存储地址用的参考值，如果没有第二个参数，内部他无法处理存放参数信息
void sum(int count, ...) {
    va_list vp; // 可变参数的动作

    // 参数一：可变参数开始的动作vp
    // 参数二：内部需要一个 存储地址用的参考值，如果没有第二个参数，内部他无法处理存放参数信息
    va_start(vp, count);

    // 到这里后：vp就已经有丰富的信息

    // 取出可变参数的一个值
    int number  = va_arg(vp, int);
    cout << number << endl;

    // 取出可变参数的一个值
    number  = va_arg(vp, int);
    cout << number << endl;

    // 取出可变参数的一个值
    number  = va_arg(vp, int);
    cout << number << endl;

    // 越界 系统值 乱码
    // 取出可变参数的一个值 【娶不到后，会取系统值 乱码】
    number  = va_arg(vp, int);
    cout << number << endl;

    // 关闭阶段
    va_end(vp);
}

// 1.可变参数
int main() {
    std::cout << "同学们大家好，我是Derry" << std::endl;

    sum(546, 6,7,8);

    return 0;
}
