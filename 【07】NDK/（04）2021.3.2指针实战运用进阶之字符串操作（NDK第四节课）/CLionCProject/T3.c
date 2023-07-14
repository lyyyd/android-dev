// 3.指针挪动获取字符串信息(手写API)。

#include <stdio.h>

// 获取长度
/*
int getLen(char * string) {
    int count = 0;
    while (*string) { // *string != '\0' 我就一直循环
        string ++;
        count++;
    }
    return count;
}

int mainT3() {
    char string[] = {'A', 'B', 'C', 'D', '0', '\0'}; // printf方法能够停下来，不要打印系统值

    int r =  getLen(string);
    printf("长度是:%d\n",r);

    return 0;
}
*/



#include <stdio.h>

// C/C++编译器 数组作为参数传递，会把数组优化成指针（为了高效率）
void getLen(int * resultLen, int intarr[]) { // 模仿了 strLen函数

    // 数组作为参数传递 就不能这样写了

    // sizeof(intarr)28 / sizeof(int)4 = 7
    /*int len = sizeof(intarr) / sizeof(int);
    printf("getLen len长度是:%d\n", len);*/

    // 手动计算长度
    int count = 0;
    while (*intarr != '\0') {
        intarr++;
        count++;
    }
    *resultLen = count;
}

void doEngine(int len) {

}

int mainT3() {
    // int 4   char 1

    // char string[] = {'A', 'B', 'C', 'D', '0', '\0'}; // printf方法能够停下来，不要打印系统值

    int intarr[] = {1,2,3, 0,5,6,7}; // 0   \0  其他函数 for 其他调用判断的时候，这个有冲突 【int类型数组】

    // int类型使用这种方式【第一种方式】
    // sizeof(intarr)28 / sizeof(int)4 = 7
    int len = sizeof(intarr) / sizeof(int);
    printf("len长度是:%d\n", len);

    int result; // &取出result遍历的地址给函数
    getLen(&result, intarr);
    printf("getLen len长度是:%d\n", result);

    // strLen API 的用法太简单 【第二种方式】 尝试

    // 真实函数直接调用，可以这样，传递长度
    doEngine(len);

    return 0;
}