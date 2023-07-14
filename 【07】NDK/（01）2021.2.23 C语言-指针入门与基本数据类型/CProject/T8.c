#include <stdio.h>

// 由于C语言不支持函数重载，所以声明的函数，不需要写参数

void changeAction();

int main() {
    int a = 100;
    int b = 200;

    changeAction(&a, &b);

    printf("交换完成后的效果：%d,%d\n", a, b);

}

// 只接收指针(内存地址)    内存地址 == 指针
void changeAction(int * a, int * b) {

    int temp = *a;

    *a = *b;

    *b = temp;
}

