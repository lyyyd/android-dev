// TODO for_each 算法包里面的遍历

// 算法包
#include <iostream>
#include <vector> // stl包
#include <algorithm> // 算法包
using namespace std;

class __F {
public:
    void operator() (int __first) {
        cout << "自定义一元谓词:" << __first << endl;
    }
};

int main() {
    vector<int> vectorVar;
    vectorVar.insert(vectorVar.begin(), 10000);
    vectorVar.insert(vectorVar.begin(), 20000);
    vectorVar.insert(vectorVar.begin(), 30000);
    vectorVar.insert(vectorVar.begin(), 40000);
    vectorVar.insert(vectorVar.begin(), 50000);
    vectorVar.insert(vectorVar.begin(), 60000);

    for_each(vectorVar.begin(), vectorVar.end(), __F());

    return 0;
}

