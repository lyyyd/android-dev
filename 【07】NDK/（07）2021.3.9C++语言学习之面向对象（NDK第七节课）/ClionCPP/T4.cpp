#include <iostream>

// C++语言的常量，其实是真常量
int main() {
    const int number = 100;

    // number = 200;

    // 我的编译器，编译不通过， 有的编译器，编译通过，但是运行报错（结论：就不能改）
    // int * numP = &number;

    // *numP = 10000;

    printf("%d\n", number);

    return 0;
}