#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // 小写的

/// 函数进栈 定义一个int arr[5];  定义一个 int i;  (静态的范畴)

// malloc 在堆区开辟的内存空间 ， (动态的范畴)

// C的开发过程中，不能出现，野指针，悬空指针
void dynamicAction() {
    int * p; // 野指针  没有地址的，空的

    // void * 可以任意转变   int*  double *
    int * arr = malloc(1 * 1024 * 1024); // 堆区开辟 4M

    printf("dynamicAction函数，arr自己的内存地址:%p，堆区开辟的内存地址:%p\n", &arr, arr);

    // C工程师，堆区开辟的空间，必须释放
    free(arr); // 释放掉
    arr = NULL; // 重新指向一块内存地址00000

    printf("dynamicAction函数2 堆区开辟的内存地址:%p\n", arr); // 悬空指针
}

int mainT1() {

    while (9) {
        // sleep(100);
        dynamicAction(); // 调用开辟20
    }

    return 0;
}

