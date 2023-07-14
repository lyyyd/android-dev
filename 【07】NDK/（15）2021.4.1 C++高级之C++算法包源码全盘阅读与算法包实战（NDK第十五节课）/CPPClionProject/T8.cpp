// TODO sort 算法包里面的 对容器进行排序

#include <iostream>
#include <vector> // stl包
#include <algorithm> // 算法包

using namespace std;

int main() {
    vector<int> vectorVar;
    vectorVar.push_back(10);
    vectorVar.push_back(30);
    vectorVar.push_back(20);

    // if (__comp(__i, __first)) 自定义仿函数规则  返回值 bool     第一个参数int    第二个参数 是int 吗

    // 内置 的 仿函数 less<int>()
    // less<int>() 里面泛型==函数模版  没法确定好 第二个参数的类型【到底是什么类型？】

    // sort(vectorVar.begin(), vectorVar.end(), less<int>());
    sort(vectorVar.begin(), vectorVar.end(), greater<int>());

    // 直接打印 vectorVar容器  此时 是不是就已经排序了
    for (auto itVar = vectorVar.begin(); itVar != vectorVar.end() ; itVar++) {
        cout << *itVar <<endl;
    }
}
