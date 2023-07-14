// 4.结构体的数组。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cat3 {
    char name[10];
    int age;
};

int main() {

    // 栈区 静态范畴
    struct Cat3 cat [10] = {
            {"小黄", 1},
            {"小白", 2},
            {"小黑", 3},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
    };

    // VS的写法
    // cat[9] = {"小黑9", 9},

    // ClION的写法
    struct Cat3 cat9 =  {"小黑9", 9};
    // cat[9] = cat9;
    *(cat + 9) = cat9;
    printf("name:%s, age:%d \n", cat9.name, cat9.age);




    // 堆区 动态范畴 ==============================
    struct Cat3 * cat2 = malloc(sizeof(struct Cat3) * 10);

    // 【1元素地址的操作】给他赋值，请问是赋值，那个元素  （默认指向首元素地址）
    strcpy(cat2->name, "小花猫000");
    cat2->age = 9;
    printf("name:%s, age:%d \n", cat2->name, cat2->age);

    // 【8元素地址的操作】 给第八个元素赋值
    cat2 += 7;
    strcpy(cat2->name, "小花猫888");
    cat2->age = 88;
    printf("name:%s, age:%d \n", cat2->name, cat2->age);

    free(cat2);
    cat2 = NULL;


    return 0;
}
