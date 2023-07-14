// 谓词前戏

#include <iostream>
#include <set> // STL包
#include <algorithm> // 算法包

using namespace std;

// 谓词  == 仿函数

// TODO 第一版: 为什么叫仿函数 （空谓词 一元谓词 二元谓词 三元谓词）
class ComPareObject {
public:
    void operator()() { // 重装了括号运算符
        cout << "仿函数" << endl;
    }
};

// 普通函数
void fun2() {
    cout << "普通函数" << endl;
}

int main() {
    ComPareObject fun1;

    // 非常像函数的调用，很像函数 = （仿函数）
    fun1();

    fun2();

    return 0;
}

