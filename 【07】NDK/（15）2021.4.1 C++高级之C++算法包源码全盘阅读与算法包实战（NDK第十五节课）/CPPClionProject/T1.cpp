// 1.C++的函数适配器。  第一版本

#include <iostream>
#include <set> // stl包
#include <algorithm> // 算法包
using namespace std;

int main() {
    // std::cout << "算法包" << std::endl;

    set<string, less<string>> setVar;
    setVar.insert("AAAA");
    setVar.insert("BBBB");
    setVar.insert("CCCC");

    for (set<string>::iterator iteratorVar = setVar.begin(); iteratorVar != setVar.end() ; iteratorVar++) {
        cout << *iteratorVar << endl;
    }

    // find_if
    // equal_to 比较用的
    set<string, less<string>>::iterator iteratorResult =

            // 解决尴尬的问题  equal_to 需要比较的 内容没有 使用 函数适配器 解决
            // 现在的问题是： 没有办法把 CCCC 传递给 const _Tp& __y，就没法去比较
            // find_if(setVar.begin(), setVar.end(), equal_to<string>("CCCC"), "CCCC");

            // 使用函数适配器后，就能够 CCCC 传递给了  const _Tp& __y，
            // setVar.begin(), setVar.end() 会把这些元素取出来 const _Tp& __x
            // x == y 的比较
            find_if(setVar.begin(), setVar.end(), bind2nd(equal_to<string>(), "CCCC"));

    if (iteratorResult != setVar.end()) {
        cout << "查找到了" << endl;
    } else {
        cout << "没有查找到" << endl;
    }

    return 0;
}
