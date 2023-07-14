// 1.C++的函数适配器。  第二版本

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

    // bind2nd()  第二个参数 适配过去 （需要知道的）
    // bind1st()  第一个参数 适配过去（NDK 很少用）

    // 死活不想用 函数适配器 【Derry 没法做到，门都找不到】
    find_if(setVar.begin(), setVar.end(),  equal_to<string>());

    return 0;
}

