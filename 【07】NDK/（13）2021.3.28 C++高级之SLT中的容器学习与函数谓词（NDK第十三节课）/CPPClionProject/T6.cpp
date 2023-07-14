// 6.set容器  来引出函数谓词。

// set（内部：红黑树结构），会对你存入的数据进行排序，但是绝对不允许元素相同

#include <iostream>
#include <set>

using namespace std;


int main() {
    set<int, less<int>> setVar; //  __x < __y 从小到大，默认情况下 就是 less

    // 添加参数，不需要用迭代器，也不需要指定位置
    setVar.insert(1);
    setVar.insert(3);
    setVar.insert(2);
    setVar.insert(4);

    // 重复插入，并不会报错  std::pair<iterator, bool>
    pair<set<int, less<int>>::iterator, bool> res = setVar.insert(8);

    // res.first 获取第一个元素 迭代器   当前迭代器   最后一个位置
    // res.second 获取第二个元素 bool
    bool insert_success = res.second;
    if (insert_success) {
        cout << "恭喜你，插入成功" << endl;

        // 插入成功后，我用第一个元素遍历
        for (; res.first != setVar.end(); res.first ++) {
            cout << *res.first << endl;
        }

    } else {
        cout << "哎，插入失败.." << endl;
    }

    // 全部遍历  auto 自动推到
    for (auto it = setVar.begin(); it != setVar.end() ; it ++) {
        cout << *it << endl;
    }

    return 0;
}

