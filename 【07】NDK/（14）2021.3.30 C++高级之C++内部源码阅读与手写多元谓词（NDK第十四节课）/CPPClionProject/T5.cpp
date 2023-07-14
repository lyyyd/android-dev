// 回调函数 和 仿函数  各个的用途  同学们知道了 1
// 谓词尾戏

#include <iostream>
#include <set> // STL包
#include <algorithm> // 算法包

using namespace std;

// 回调函数 (功能够简单)
void showAction(int __first) {
    cout << "一元谓词" << __first << endl;
}

// 仿函数(扩展性强) C++内置源码使用仿函数频率高，扩展性强
class showActionObj {
public:
    int count = 0;
    void _count() { cout << "本次输出次数是:" << this->count << endl; }

    void operator() (int __first) {
        cout << "仿函数" << __first << endl;
        count++;
    }
};

int main() {
    // 理解：类型传递
    // set<int, showActionObj> setVar; 这样写的语法是OK的，不能加括号
    set<int> setVar;

    setVar.insert(10);
    setVar.insert(20);
    setVar.insert(30);
    setVar.insert(40);
    setVar.insert(50);
    setVar.insert(60);

    // TODO 第一种方式
    for_each(setVar.begin(), setVar.end(), showAction);
    // 请你统计打印次数？ 答：做不到

    // TODO 第二种方式
    showActionObj s; // 理解：值传递
    s = for_each(setVar.begin(), setVar.end(), s); // 传入进去的s是新的副本，我们外面的s是旧地址
    // 请你统计打印次数？ 答：OK
    s._count();

    return 0;
}
