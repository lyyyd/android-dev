// 5.结构体与结构体指针 取别名。

#include <stdio.h>
#include <stdlib.h>

struct Workder_ {
    char name[10];
    int age;
    char sex;
};

// VS的写法：typedef Workder_
typedef struct Workder_ Workder_; // 给结构体取别名

typedef Workder_ * Workder; // 给结构体指针取别名

// C库的源码，系统源码...，为什么 typedef 还取一个和结构体一样的名字（兼容代码的写法，保持一致）

int main() {
    // 以前 Clion工具 必须加上 struct   VS又不用加  代码差异化大
    // struct Workder_ workder1 = malloc(sizeof(struct Workder_));

    // 现在 （兼容代码的写法，保持一致）
    Workder_ workder1 = malloc(sizeof(Workder_));

    // VS  CLion  他们都是一样的写法
    Workder workder = malloc(sizeof(Workder_));

    return 0;
}

