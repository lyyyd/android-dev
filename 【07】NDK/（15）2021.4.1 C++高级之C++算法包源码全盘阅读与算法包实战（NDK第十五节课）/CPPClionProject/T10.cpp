// TODO copy 算法包里面的 copy容器1的元素 到 容器2  （常用）

#include <iostream>
#include <vector> // stl包
#include <algorithm> // 算法包

using namespace std;

int main() {
    vector<int> vectorVar; // vector默认是没有排序功能的，默认输出： 65 53 84
    vectorVar.push_back(100);
    vectorVar.push_back(200);
    vectorVar.push_back(300);
    vectorVar.push_back(400);
    vectorVar.push_back(500);
    vectorVar.push_back(600);
    vectorVar.push_back(700);

    vector<int> vectorResult;
    vectorResult.resize(vectorVar.size());

    copy(vectorVar.begin(), vectorVar.end(), vectorResult.begin());
    // 100	200	300	400	500	600	700

    // 直接打印 vectorVar容器  此时 是不是就已经排序了
    for (auto itVar = vectorResult.begin(); itVar != vectorResult.end() ; itVar++) {
        cout << *itVar << "\t";
    }

    // 源码变了   VS里面

    return 0;
}

