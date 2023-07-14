// 3.结构体指针 与 动态内存开辟。

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Cat2 {
    char name[10];
    int age;
};

int main() { // 堆

    // VS的写法：Cat2 * cat = (Cat2 *) malloc(sizeof(Cat2));
    struct Cat2 *cat = malloc(sizeof(struct Cat2));

    strcpy(cat->name, "金色猫");
    cat->age = 5;

    printf("name:%s, age:%d \n", cat->name, cat->age);

    // 堆区的必须释放
    free(cat);
    cat = NULL;

    return 0;
}