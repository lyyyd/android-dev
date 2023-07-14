#include <stdio.h> // C99 标准库

// 地址概念
// Java 万物皆对象
// C C++(对象) 万物皆指针
// Linux 万物皆文件
int mainT4() {

    // 指针 == 地址

    // %p == 地址输出的占位
    // & == 取出地址

    int number1 = 100000;
    printf("此number1变量的地址是:%p\n", &number1); // 地址 == 00B3FE90

    return NULL;
}
