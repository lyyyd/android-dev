// TODO random_shuffle 算法包里面的 随机打乱元素的顺序

#include <iostream>
#include <vector> // stl包
#include <algorithm> // 算法包

using namespace std;

int main() {
    vector<int> vectorVar; // vector默认是没有排序功能的，默认输出： 65 53 84
    vectorVar.push_back(65);
    vectorVar.push_back(53);
    vectorVar.push_back(84);
    vectorVar.push_back(11);
    vectorVar.push_back(22);
    vectorVar.push_back(33);
    vectorVar.push_back(44);


    sort(vectorVar.begin(), vectorVar.end(), less<int>()); // 排序后 53 65 82

    random_shuffle(vectorVar.begin(), vectorVar.end());

    // 直接打印 vectorVar容器  此时 是不是就已经排序了
    for (auto itVar = vectorVar.begin(); itVar != vectorVar.end() ; itVar++) {
        cout << *itVar << "\t";
        // 84	65	53
    }
    return 0;
}