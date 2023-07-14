#include <stdio.h>

// 5.数组指针操作的几种方式。
int mainT6() {

    int arr[]  = {1,9,0,9999};

    int * arrP = arr;

    for (int i = 0; i < 4; ++i) {
        // printf("%d\n", arrP[i]);
        // printf("%d\n", *(arrP + i)); // + i 挪动元素3内存地址 再取元素3内存地址所对应的值
        // printf("%d\n", *arrP + i);  放后面解释
    }

    return 0;
}

