// 宏函数 真实开发中：宏函数都是大写
#include <iostream>
using namespace std;

#define SHOW(V) cout << V << endl; // 参数列表 无需类型  返回值 看不到
#define ADD(n1, n2) n1 + n2
#define CHE(n1, n2) n1 * n2 // 故意制作问题 ，宏函数的注意事项

// 复杂的宏函数
#define LOGIN(V) if(V==1) {                         \
    cout << "满足 你个货输入的是:" << V << endl;        \
} else {                                             \
    cout << "不满足 你个货输入的是:" << V << endl;       \
} // 这个是结尾，不需要加 \

void show() {}

int main() {
    SHOW(8);
    SHOW(8.8f);
    SHOW(8.99);

    int r = ADD(1, 2);
    cout << r << endl;

    r = ADD(1+1, 2+2);
    cout << r << endl;

    // r = CHE(1+1, 2+2);
    r = 1+1 * 2+2; // 文本替换：1+1 * 2+2  先算乘法  最终等于 5
    cout << r << endl; // 我们认为的是8，   但是打印5

    LOGIN(0);
    LOGIN(0);
    LOGIN(0);
    LOGIN(0);
    LOGIN(0);
    LOGIN(0);
    // 会导致代码体积增大

    show();
    show();
    show();
    show();
    show();
    // 普通函数，每次都会进栈 弹栈 ，不会导致代码体积增大

    return 0;
}

// 宏函数
/*
 * 优点：
 *   1.文本替换，不会造成函数的调用开销(开辟栈空间，形参压栈，函数弹栈释放 ..)
 *
 * 缺点：
 *   1.会导致代码体积增大
 *
 */

