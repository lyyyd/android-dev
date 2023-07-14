#include <stdio.h>

// 4.循环时给数组赋值。
int mainT5() {

    // 定义数组
    // int [] arr = {1,2,3,4}; 错误的写法
    int arr[4];

    int * arrP = arr;

    // sizeof arr == sizeof(arr)

    // 循环赋值操作
    int j = 0;
    for (j = 0; j < 4; ++j) {
        // 1.拿到 元素一 元素二 元素三 元素四 的内存地址   (arrP + j)
        // 2.取出 元素一 元素二 元素三 元素四 的内存地址 所对应的值 * (arrP + j)
        * (arrP + j) = (j + 10001);
    }

    // sizeof arr = 16(sizeof arr)  /  4(sizeof(int))
    // 变量 刚刚赋值的数组
    for (int i = 0; i <  sizeof arr / sizeof(int); ++i) {
        printf("位置%d的值是:%d\n", i, * (arrP + i));
    }

    return 0;
}