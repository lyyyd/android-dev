#include <stdio.h>

// C语言的常量，其实是个 假常量（伪命题）
int main() {
    const int number = 100;

    // number = 200;

    int * numP = &number;

    *numP = 10000;

    printf("%d\n", number);

    return 0;
}