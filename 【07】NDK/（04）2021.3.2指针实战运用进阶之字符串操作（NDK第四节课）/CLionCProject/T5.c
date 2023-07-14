// 字符串查找，包含，拼接。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mainT5() {

    char * text = "name is Derry";
    char * subtext = "D";

    char * pop = strstr(text, subtext);

    // 怎么去 字符串查找
    if (pop) { // 非NULL，就进入if，就查找到了
        printf("查找到了,pop的值是:%s\n", pop);
    } else {
        printf("没有查找到,subtext的值是:%s\n", subtext);
    }

    // 包含了D吗
    if (pop) {
        printf("包含了\n");
    } else {
        printf("没有包含\n");
    }

    // printf("pop地址%p， text地址:%p,\n", pop, text);

    // 求取位置？  数组是一块连续的内存空间，没有断层，所以可以-
    int index = pop - text; // pop="Derry" - text"name is Derry"
    printf("%s第一次出现的位置是:%d\n", subtext, index); // 我的D在第8个位置

    // 指针是可以：++ --  +=  -=

    // 拼接 ========================
    char destination[25]; // 容器 25的大小 已经写死了
    char * blank = "--到--", *CPP="C++", *Java= "Java";

    strcpy(destination, CPP); // 先Copy到数组里面去
    strcat(destination, blank); // 然后再拼接
    strcat(destination, Java); // 然后再拼接
    printf("拼接后的结果:%s\n", destination); // C++--到--Java

    return 0;
}

