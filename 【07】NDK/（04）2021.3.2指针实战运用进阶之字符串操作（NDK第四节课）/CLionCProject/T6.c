// 大小写转换(手写API)

#include <stdio.h>
#include <ctype.h>

// 指针的理解
void lower(char * dest, char * name) {
    char * temp = name; // 临时指针，你只能操作，临时指针，不能破坏name指针
    while (*temp) {
        *dest = tolower(*temp);
        temp ++; // 挪动指针位置 ++
        dest ++; // 挪动指针位置 ++  目的是为了 挪动一个存储一个 挪动一个存储一个 ...
    }
    // printf '\0'
    *dest = '\0'; // 避免printf打印系统值

    printf("不能破坏 name:%s\n", name); // temp的好处就是，不会破坏name
}

// 全部变成小写 derry
int mainT6() {
    char * name = "DerrY";

    // 先定义结果
    char dest[20];
    lower(dest, name);
    printf("小写转换后的结构是:%s\n", dest);

    // 作业：
    /*char * str = "Derry is";
    char * result;
    函数(&result, str, 2, 5);
    printf("%s\n", result); // 最终输出：rry*/

    // 这样-不成功
    /*char * a = "ABCDEFG";
    char * b = "AB";
    int r = b - a;
    printf("r:%d\n", r);*/

    return 0;
}

