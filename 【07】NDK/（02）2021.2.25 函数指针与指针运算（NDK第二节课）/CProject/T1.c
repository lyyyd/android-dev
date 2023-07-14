#include <stdio.h>

void update(int * i) { // 1000H内存地址
    // printf("update函数，i的内存地址是:%p\n", &i); // 2000H

    printf("update函数，i的内存地址是:%p\n", i); // 1000H

    * i = 999;
}

// 上节课同学问了我一个问题（为什么 main函数 和 update 函数 i 的内存不地址一样？）
int mainT1() {
    int i = 100; // 1000H的内存地址
    update(&i);

    printf("main函数，i的内存地址是:%p\n", &i);

    return 0;
}
