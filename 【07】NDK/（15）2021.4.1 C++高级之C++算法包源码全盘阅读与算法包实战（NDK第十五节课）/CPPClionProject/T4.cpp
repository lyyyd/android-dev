// TODO transform 算法包里面的 变化操作

#include <iostream>
#include <vector> // stl包
#include <algorithm> // 算法包
using namespace std;

class __unary_op {
public:
    int operator() (const int __first) {
        return __first + 9; // 修改每个元素 +9
    }
};

int main() {
    vector<int> vectorVar;
    vectorVar.insert(vectorVar.begin(), 10000);
    vectorVar.insert(vectorVar.begin(), 20000);
    vectorVar.insert(vectorVar.begin(), 30000);
    vectorVar.insert(vectorVar.begin(), 40000);

    // TODO 第一种方式  类似于 RxJava map 变化操作符  【不看API，直接看算法包源码 印象非常深刻的】
    // 迭代器 result == 参数三
    transform(vectorVar.begin(), vectorVar.end(), vectorVar.begin(), __unary_op());

    for (auto it = vectorVar.begin(); it != vectorVar.end() ; it++) {
        cout << "第一种方式:" << *it << endl;
    }
    cout << endl;

    // 第三个参数接收返回值有啥用？没感受出来
    // ==================================================================================

    // TODO 第二种方式
    vector<int> vectorVarResult; // vectorVarResult 大小空间
    vectorVarResult.resize(vectorVar.size());
    transform(vectorVar.begin(), vectorVar.end(), vectorVarResult.begin(), __unary_op());

    for (auto it = vectorVarResult.begin(); it != vectorVarResult.end() ; it++) {
        cout << "第二种方式:" << *it << endl;
    }

    return 0;
}
