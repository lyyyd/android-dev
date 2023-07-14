#include <stdio.h>

// 基本数据类型
int mainT2() {

    int i = 100;
    double d = 200;
    float f = 200;
    long l = 100;
    short s = 100;
    char c = 'd';
    // 字符串
    char * str = "Derry";

    // 不是随便打印的，需要占位
    printf("i的值是：%d\n", i); // d == 整形
    printf("d的值是:%lf\n", d); // lf == long float
    printf("f的值是:%f\n", f); // f == float
    printf("l的值是:%d\n", l); // d == 整形
    printf("s的值是:%d\n", s); // s == short
    printf("c的值是:%c\n", c); // c == char
    printf("字符串:%s\n", str); // s == String

    printf("Derry");
    // getchar();
}

