// 上节课指针练习

#include <stdio.h>

int main() {
    int a[] = {6,4,8,3,1,2,9,7,0,5};

    // *(a+4) --- (a+4):a数组默认指向首元素地址 挪动到 第四个元素    *取出第四个元素内存地址的值 == 1
    // *a+1  a数组默认指向首元素地址 挪动到 第一个元素     *取出第一个元素内存地址的值 == 4
    // a[4] 挪动到第四个元素 内存地址的值 等于 1
    int result = a[*(a+*(a+4))];
    printf("result的值是:%d\n", result); // 输出1
    return 0;
}