// 2.stack栈学习。 先进后出，后进先出，手枪子弹上膛的一个思路。

#include <iostream>
#include <stack>
using namespace std;

// NDK开发者 几乎用不到

int main() {
    stack<int> stackVar;

    // 压栈（注意：stack无法指定那个位置去压栈）
    stackVar.push(30);
    stackVar.push(60);
    stackVar.push(90);

    // 请问那个元素，在最上面（看图）

    // [] 角标是不行的，内部没有重载此运算符
    /*for (int i = 0; i < stackVar.size(); ++i) {
        // cout << stackVar[i] << endl;
        // cout << stackVar.at() << endl;
    }*/

    // 他根本就没有迭代器
    // 开发者 自己组装 迭代器 遍历
    /*for (stack<int>::iterator; i < ; ++i) {

    }*/

    // 慎用，为什么？ 元素被弹完了
    // 这种方式是可以的，手枪把子弹全部打完【会把元素清空】
    while (!stackVar.empty()) {
        int top = stackVar.top(); // top == 获取栈顶的元素
        cout << "获取栈顶的元素：" << top << endl; // 永远拿 90

        stackVar.pop(); // 把栈顶的元素 弹出去  【删除】
    }

    /*int top = stackVar.top();
    cout << top << endl;*/

    return 0;
}


