#include <stdio.h>

// 3.采用指针遍历数组。

int mainT4() {

    // 定义数组
    // int [] arr = {1,2,3,4}; 错误的写法
    int arr[]  = {1,2,3,4};

    // 数组是连续的内存空间（没有断层，有规律） 数组  每次挪动 4个字节 == int数组

    int * arr_p = arr;

    int i = 0;
    for (i = 0; i < 4; ++i) {
        printf("位置%d的值是:%d\n", i, * (arr_p + i));

        // 04    08   12    16
        printf("位置%d的内存地址是:%p\n", i, (arr_p + i));
    }

    return 0;
}