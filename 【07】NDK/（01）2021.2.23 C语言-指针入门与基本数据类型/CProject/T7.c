#include <stdio.h>

// C语言不允许函数重载，    Java可以，C++可以

// void change(int i); // 先声明

void change(int * i); // 先声明

// 函数 取修改一个数（指针操作）
int mainT7() {

    int i = 100;

    change(&i);

    printf("%d\n", i);

    // * i 和 *i 有什么区别呢  没区别 写法而已

    /*
        int * i;  定义指针

        *i = 888;  取出内存地址所对应的值修改成 888
    */

    return 0;
}

// 函数不能写在 main的下面，会报错
// void change(int i) {}

// 再实现
/*void change(int i) {

    printf("change内存地址：%p\n", &i);

    i = 200;
}*/

// 再实现
// 使用指针 来修改
void change(int * i) {

    *i = 666;
}

