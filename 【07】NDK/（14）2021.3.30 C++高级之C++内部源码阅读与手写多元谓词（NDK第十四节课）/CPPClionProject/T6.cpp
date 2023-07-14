// 类型传递 的 仿函数 怎么看源码得知 写法  同学们看懂了吗

#include <iostream>
#include <set>
using namespace std;

// C++源码：typename _Compare = std::less   less内置的仿函数，根据内置仿函数去写 自定义
//  bool operator()(const _Tp& __x, const _Tp& __y) const 二元谓词
class CompareObjectClass {
public:
    bool operator() (const string & __x, const string & __y) const { // const 指针 const  常量指针常量 = 只读
        return __x > __y;
    }
};

int main() {
    set<string, CompareObjectClass> setVar; // 第一版

    setVar.insert(setVar.begin(), "AAAAAAA");
    setVar.insert(setVar.begin(), "BBBBBBB");
    setVar.insert(setVar.begin(), "CCCCCCC");
    setVar.insert(setVar.begin(), "DDDDDDD");
    setVar.insert(setVar.begin(), "EEEEEEE");
    setVar.insert(setVar.begin(), "FFFFFFF");

    // 迭代器 循环
    for (set<string>::iterator iteratorVar = setVar.begin(); iteratorVar != setVar.end(); iteratorVar++) {
        cout << "循环item:" << *iteratorVar  << "\t";
        // 循环item:AAAAAAA	循环item:BBBBBBB	循环item:CCCCCCC	循环item:DDDDDDD	循环item:EEEEEEE	循环item:FFFFFFF

        // 循环item:FFFFFFF	循环item:EEEEEEE	循环item:DDDDDDD	循环item:CCCCCCC	循环item:BBBBBBB	循环item:AAAAAAA
    }


    return 0;
}

