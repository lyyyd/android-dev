// 谓词中戏

#include <iostream>
#include <set> // STL包
#include <algorithm> // 算法包

using namespace std;

// 我如何阅读C++源码，来写我们的仿函数
// 明明白白的仿函数（一元谓词==一元函数对象）
class showActionObj {
public:
    void operator()(int content) {
        cout << "自定义仿函数" << content << endl;
    }
};

// 回调函数 如果叫 仿函数 有点合理
// 简洁方式（回调函数、一元谓词      但是不能称为 仿函数）
void showAction(int content) {
    cout << "自定义 一元谓词" << content << endl;
}

using namespace std;

int main() {
    set<int> setVar;

    setVar.insert(10);
    setVar.insert(20);
    setVar.insert(30);
    setVar.insert(40);
    setVar.insert(50);
    setVar.insert(60);

    // for_each(setVar.begin(), setVar.end(), showActionObj());

    for_each(setVar.begin(), setVar.end(), showAction);

    return 0;
}
