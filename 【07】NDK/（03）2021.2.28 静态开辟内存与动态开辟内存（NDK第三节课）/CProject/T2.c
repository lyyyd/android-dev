#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1.如何自己学会阅读C语言API文档
/*
int main() {

    // 看文档的思路：
    // 1.看到文档，不要Copy，初学者
    // 2. 传入 &t  &p   可以直接传递 NULL 尝试

    // 时间单位 给他才行
    srand((unsigned) time(NULL));

    int i;
    for (i = 0;  i< 10 ; i++) {
        printf("随机数%d\n", rand() % 100);
    }

    return(0); // return 0;
}
*/

// 字符串的Copy工作
/*函数名: strcpy
        功  能: 串拷贝
        用  法: char *strcpy(char *str1, char *str2);
程序例:*/

#include <stdio.h>
#include <string.h>

/*
int mainT2(void)
{
    char string[10]; // 定义一个数组
    char *str1 = "abcdefghi"; // 字符串定义

    strcpy(string, str1); // 就是把 str1 复制到 数组
    printf("%s\n", string); // 打印数组
    return 0;
}*/

// C中的 布尔
int mainT2() {

    // Java Boolean

    // 非0即true， 0就是false

    if (0) {
        printf("真\n");
    } else {
        printf("假\n");
    }

    if (43665) {
        printf("真\n");    // 1  走
    } else {
        printf("假\n");    // 2
    }

    if (-545) {
        printf("真\n");    // 1
    } else {
        printf("假\n");    // 2
    }


    return 0;
}



