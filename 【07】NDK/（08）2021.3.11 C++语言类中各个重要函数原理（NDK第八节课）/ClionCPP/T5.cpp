// 指针常量 常量指针 常量指针常量

#include <iostream>
#include <string.h>
#include <string.h>

using namespace std;

int main() {

    // *strcpy (char *__restrict, const char *__restrict);
    // strcpy()


    int number = 9;
    int number2 = 8;

    // 大道至简 一分钟搞定

    // 常量指针
    const int * numberP1 = &number;
    // *numberP1 = 100; // 报错，不允许去修改【常量指针】存放地址所对应的值
    // numberP1 = &number2; // OK，允许重新指向【常量指针】存放的地址

    //  指针常量
    int* const numberP2 = &number;
    *numberP2 = 100; // OK，允许去修改【指针常量】存放地址所对应的值
    // numberP2 = &number2; // 报错，不允许重新指向【指针常量】存放的地址

    // 常量指针常量
    const int * const numberP3 = &number;
    // *numberP3 = 100; // 报错，不允许去修改【常量指针常量】存放地址所对应的值
    // numberP3 = &number2; // 报错，不允许重新指向【常量指针常量】存放的地址

    return 0;
}

