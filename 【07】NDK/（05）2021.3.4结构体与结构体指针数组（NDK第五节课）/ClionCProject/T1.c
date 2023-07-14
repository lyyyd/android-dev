// 上课通用模板

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// TODO 第一版   通用
void substrAction1(char * result, char * str, int start, int end) {
    char * temp = str; // 定义临时指针，不破坏str指针
    int count = 0; // 记录当前的位置
    while (*temp) {
        // 2 到 5 的位置  在截取的范围内
        if (count >= start && count < end) {
            *result = *temp; // *temp 取出 D e r r y ...
            result++; // （接收值也要挪动）挪动指针来接收   =   *temp给我的值
        }
        temp++; // 取值也要挪动
        count++; // 当前的位置要同步
    }
}

// TODO 第二版    有意让同学，深刻理解  栈区 堆区 开辟（1）
void substrAction2(char ** result, char * str, int start, int end) {
    char * temp = str; // 定义临时指针，不破坏str指针

    // 合理分配，截取多少用多少，节约
    char resultArr[end - start]; // 我只需要你截取的大小空间：例如：rry

    // 尽量不要使用第二种方式，会被C工程师鄙视的，为什么？ 你开辟的，就应该你回收
    // char * resultArr = malloc(end - start); // 堆区开辟，第二种解决方案

    int count = 0;
    for (int i = start; i < end; ++i) {
        resultArr[count] = *(temp + i); // *(temp + i);取出D e r r y 给  数组容器
        count++;
    }

    // * 取出二级指针的一级指针 ==  main函数的result一级指针

    // *result = resultArr; // 不能让我们的一级指针 指向容器，因为容器会被回收掉

    strcpy(*result, resultArr); // 第一种解决方案

    printf("%s\n", resultArr);

    // 1   2  不能回收堆空间，否则main函数 打印了空
    // free(resultArr);

} // 函数弹栈后，会回收所有的栈成员，包括：resultArr

// TODO 第三版    三行代码搞定
void substrAction3(char * result, char * str, int start, int end) { // 没有涉及栈区 堆区的概念
    // 合理分配，截取多少用多少，节约 思路
    for (int i = start; i < end; ++i) { // 刚好结束 循环三次
        *(result++) = *(str+i); // i = 2
    }
}

// TODO 第四版   一行代码搞定
void substrAction4(char * result, char * str, int start, int end) {
    // 参数1：我最终是copy到result容器里面
    // 参数2：直接从r开始，因为我一级做了，指针挪动了
    // 参数3：你从r开始，挪动多少
    strncpy(result, str+start, end - start);
}

// 【截取】字符串的截取操作
int main() {

    char *str = "Derry is";
    // 正好她是一级指针
    char *result; // char * 不需要结尾符\0

    // 截取第二个位置到第五个位置 2，5

    // substrAction1(result, str, 2, 5);
    // substrAction2(&result,str, 2, 5);
    // substrAction3(result,str, 2, 5);
    substrAction4(result, str, 2, 5);

    printf("main 截取的内容是：%s", result); // 最终截取：rry

    if (result) {
        free(result);
        result = NULL;
    }

    return 0;
}
