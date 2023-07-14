// TODO replace 算法包里面的 替换元素内容

#include <iostream>
#include <vector> // stl包
#include <algorithm> // 算法包

using namespace std;

int age;

void set(int age) {
    ::age = age;
}

int main() {
    vector<int> vectorVar; // vector默认是没有排序功能的，默认输出： 65 53 84
    vectorVar.push_back(100);
    vectorVar.push_back(200);
    vectorVar.push_back(300);
    vectorVar.push_back(400);
    vectorVar.push_back(500);
    vectorVar.push_back(600);

    // 100 ~ 200 范围
    // replace(vectorVar.begin(), vectorVar.begin() + 2, 200, 222);

    // 所有范围
    replace(vectorVar.begin(), vectorVar.end(), 300, 333);

    // 直接打印 vectorVar容器  此时 是不是就已经排序了
    // Java有这个能力吗，想都不要想  指针
    for (auto itVar = vectorVar.begin(); itVar != vectorVar.end() ; itVar++) {
        cout << *itVar << "\t";
    }

    return 0;
}