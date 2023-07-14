// C语言的函数重载 是不支持的

#include <stdio.h>

void add(int number1, int number2) {

}

// error: conflicting types for 'add'  == 已有函数主体
// C语言里面，搞了函数重载，这是不允许的，C++才支持函数重载
/*void add(int number1, int number2, int number3) {

}*/

int main() {

    return 0;
}

