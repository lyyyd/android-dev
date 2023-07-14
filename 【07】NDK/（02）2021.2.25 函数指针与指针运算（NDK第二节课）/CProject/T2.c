#include <stdio.h>

// 多级指针的意义是什么啊 (C的框架，再去说，比较时候)
void test1(int ** n) {}

// 1.多级指针。
int mainT2() {

    int num = 999;

    // 一级指针 *
    // 在真实开发过程中，最多三级指针  int ***
    int * num_p = &num; // 取出num的内存地址给 num_p（一级指针）

    int ** num_p_p = &num_p; // 取出num_p的内存地址给  num_p_p（二级指针）

    int *** num_ppp = &num_p_p;

    printf("num_p的值是：%p， num_p_p的值是：%p\n", num_p, num_p_p);
    // num_p的值是：0061FF18， num_p_p的值是：0061FF14

    // 我先输出 999
    printf("获取最终的值：%d\n", **num_p_p);
    printf("获取最终的值：%d\n", *** num_ppp);

    // 多级指针的意义是什么啊
    // test1(num_p_p)

    // printf("num_p的自己的内存地址是：%p， num_p_p自己的额内存地址是：%p\n", &num_p, &num_p_p);

    // *num_ppp  取的是什么？

    return 0;
}
