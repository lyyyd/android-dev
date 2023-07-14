// 3.引用的原理与

#include <iostream>

using namespace std;

// 互换两个数

// 指针取地址 互换  C语言第一节课的内容
// 接收number1/number2的地址，取改地址的值，来完成的互换
void numberChange(int * number1, int * number2) {
    int temp = 0;
    temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}

// C++提倡的引用
void numberChange2(int & number1, int & number2) {

    // 如果不采用引用，main numberChange2 内存地址是不一样的
    // 如果采用引用，main numberChange2 内存地址是一样的，为什么呢？
    cout << "numberChange2 " << "n1地址：" << &number1 << " , n2地址：" << &number2 <<endl;

    int temp = 0;
    temp = number1;
    number1 = number2;
    number2 = temp;
}

int main() {

    int number1 = 10;
    int number2 = 20;

    cout << "main " << "n1地址：" << &number1 << " , n2地址：" << &number2 <<endl;

    // numberChange(&number1, &number2);
    numberChange2(number1, number2);

    cout << "n1:" << number1 << " , n2:" <<  number2 << endl;

    cout << endl;

    // 引用做实验，来学原理：

    // 第一部分，不采用 &
    /*int n1 = 999;
    int n2 = n1;
    cout << &n1 << "---" << &n2 << endl;*/ // 0xffffcbb4---0xffffcbb0

    // 第二部分，采用&
    int n1 = 999;
    int & n2 = n1;
    int & n9 = n1;
    n2 = 777;
    n9 = 9527;
    cout << "地址：" << &n1 << "---" << &n2 << endl;
    cout << "值：" << n1 << "---" << n2 << endl;

    return 0;
}

