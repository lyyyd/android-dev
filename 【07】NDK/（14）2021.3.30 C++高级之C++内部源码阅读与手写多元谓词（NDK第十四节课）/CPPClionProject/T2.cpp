// 2.multimap容器学习。

#include <iostream>
#include <map>

using namespace std;

int main() {
    // 1.key可以重复， 2.key重复的数据可以分组,  3.key会排序，  4.value不会排序
    multimap<int, string> multimapVar;

    multimapVar.insert(make_pair(10, "十个1"));
    multimapVar.insert(make_pair(10, "十个2"));
    multimapVar.insert(make_pair(10, "十个3"));

    multimapVar.insert(make_pair(30, "三十1"));
    multimapVar.insert(make_pair(30, "三十3"));
    multimapVar.insert(make_pair(30, "三十2"));


    multimapVar.insert(make_pair(20, "二十1"));
    multimapVar.insert(make_pair(20, "二十2"));
    multimapVar.insert(make_pair(20, "二十3"));

    for (auto iteratorVar = multimapVar.begin(); iteratorVar != multimapVar.end() ; iteratorVar ++) {
        cout << iteratorVar->first << "," << iteratorVar->second << endl;
    }
    cout << endl;

    // TODO 核心功能是分组
    int result;
    cout << "请输入你要查询的key，为int类型:" << endl;
    cin >> result;

    multimap<int, string>::iterator iteratorVar = multimapVar.find(result);
    while (iteratorVar != multimapVar.end()) {
        cout << iteratorVar->first << "," << iteratorVar->second << endl;

        // 需要自己做逻辑控制，不然有问题
        iteratorVar++;

        if (iteratorVar->first != result) {
            break;; // 循环结束
        }

        // 严谨性
        if (iteratorVar == multimapVar.end()) {
            break;; // 循环结束
        }
    }

    return 0;
}

