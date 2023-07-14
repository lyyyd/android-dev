#include <stdio.h>

void callBackMethod(char * fileName, int current, int total) {
    printf("%s图片压缩的进度是：%d/%d\n", fileName, current, total);
}

// 压缩的方法
// 定义函数指针: 返回值(*名称)(int,double)
void compress(char * fileName, void(*callBackP)(char *,int,int)) {
    callBackP(fileName, 5, 100); // 回调给外交 压缩的进度情况
}

// 函数指针2
int main() {

    // 1 如果有问题
    // VS  Clion 通过了，  Linux 可能不通过（因为这样不合规范）
    // void (* call) (char *, int ,int) = callBackMethod;

    // 有种temp的思路一样的感觉
    //  2 再换成这种方式 【第二种写法】
    // Linux  先定义， 再赋值
    void (* call) (char *, int ,int);
    call = &callBackMethod;

    void (* call2) (char *, int ,int);
    void (* call3) (char *, int ,int);
    void (* call4) (char *, int ,int);
    void (* call5) (char *, int ,int);
    call5 = &callBackMethod; // &callBackMethod 1000H  == callBackMethod 1000H

    compress("derry.png", call5);

    // 常量指针  指针常量   【函数指针】

    // 字符串  操作符重载 + C函数
    // char * c = "Derry" + "A";
}
