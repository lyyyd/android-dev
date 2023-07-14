#include <stdio.h>

void add(int i,int j) {
    printf("i+j=%d\n", i+j);
}

void add2(int i,int j) {
    printf("2 i+j=%d\n", i+j);
}

// 函数 函数指针声明来接收函数
void test(void(*p)(int, int)) {
    p(9, 9); // 上节课 省略*

    (*p)(9, 9);
    (p)(9, 9); // 省略*

    // (&p)(9, 9); 在源码没有看到这种写法

    // 思考：p 为什么也可以不用写 *   函数的上面已经声明就是 函数指针，所以可以省略*

}

// 上节课 点  函数指针
int mainT1() {
    test(add);
    test(add2);
    return 0;
}
