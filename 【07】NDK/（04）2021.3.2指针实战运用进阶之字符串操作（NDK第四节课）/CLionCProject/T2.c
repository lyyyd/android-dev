#include <stdio.h>

// 字符串
int mainT2() {
    char str[] = {'D', 'e', 'r', 'r', 'y', '\0'};
    str[2] = 'z'; // 这里能修改？
    printf("第一种方式：%s\n", str); // printf 必须遇到 \0 才结束

    char * str2 = "Derry"; // 隐士  Derry+\0
    str2[2] = 'z'; // 会奔溃，为什么，不允许访问，为什么 画图  原理图
    printf("第二种方式：%s\n", str);

    return 0;
}