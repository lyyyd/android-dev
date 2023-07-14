// C++语言的函数重载 是支持的

#include <iostream>

using namespace std;

// Java构造函数  50个字段，我真正使用的，只有6个
// 建造者设计模式 去解决此问题

// int add(int number1, int number2) = number1 + number2; // 这个是KT写法

int add(int number1) {
    return number1;
}

int add(int number1, int number2) {
    return number1 + number2;
}

// C++重载 == Java重载
int add(int number1, int number2, int number3) {
    return number1 + number2 + number3;
}

// 函数重载 二义性
// 自己做实验
// 默认行参赋值，   // KT也有默认行参赋值   优先寻找默认行参赋值的函数， 跟顺序无关
int add(double n1 = 100, int n2 = 200, int n3 = 300, int n4 = 400, bool isOK = 0) {
    return 0;
}

// 后面：函数顺序的问题？

int main() {
    add(999);

    add(999, 777);

    add(100, 200, 888);

    return 0;
}

