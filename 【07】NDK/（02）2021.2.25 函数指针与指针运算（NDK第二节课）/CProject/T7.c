#include <stdio.h>

// 6.指针类型有何用？。
int mainT7() {

    int num = 12;

    int * num_p = &num;

    // 优化处理，报错：检测无法通过的
    double * num_p_d = num_p;

    printf("%d\n", sizeof num_p);
    printf("%d\n", sizeof num_p_d);

    // 指针占用的内存大小是？  int double xxx 的指针 永远都是   4个字节（32）    4*2（64）

    // 6.指针类型有何用？。  既然都是 4个字节，为什么还要分 指针类型
    // 答：取值的时候，怎么取，这就是类型规定的好处

    // int * p; // 类型是为了计算偏移量

    char c = 'a';
    // char * p = &c;
    // char * p = "AAAA";

    return 0;
}

