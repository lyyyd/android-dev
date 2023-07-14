#include <stdio.h>

void add(int num1, int num2); // 先声明

void mins(int num1, int num2) {
    printf("num1 - num2 = %d\n", (num1 - num2));
}

// 操作 回调到  add  mins
// void(*method)(int,int)  声明好 函数指针
// void 返回值
// (*method) 函数名
// (int,int) 两个参数
void opreate(void(*method)(int,int), int num1, int num2) {
    method(num1, num2);

    printf("opreate函数的 method指针是多少：%p\n", method);
}

// 7.函数指针。（回调)  Java接口的回调
int mainT8() {  // 【第一种写法】

    opreate(add,  10, 10);
    opreate(mins,  100, 10);

    // 原理是什么？

    printf("main函数的 add指针是多少：%p\n", add);
    printf("main函数的 mins指针是多少：%p\n", mins);

    // &add和add是一样的值吗
    printf("%p, %p\n", add, &add); //  004018CE, 004018CE  一样的

    return 0;
}

// 再实现 使用
void add(int num1, int num2) {
    printf("num1 + num2 = %d\n", (num1 + num2));
}