// 5.list的学习。 Java：ArrayList采用Object[]数组，   C++的list 内部：采用链表

#include <iostream>
#include <list> // list容器的支持
using namespace std;

// NDK 基本上用不到 list

int main() {
    list<int> listVar;

    // 插入操作
    listVar.push_front(50); // 插入到前面   明确
    listVar.push_back(60); // 插入到后面
    listVar.insert(listVar.begin(), 70); // 插入到前面  灵活
    listVar.insert(listVar.end(), 80); // 插入到后面

    // 修改操作
    listVar.back() = 88;
    listVar.front() = 55;

    // 删除
    listVar.erase(listVar.begin()); // 删除最前面的 55
    listVar.erase(listVar.end()); // 删除最后面的 88

    // list 迭代器
    // 不用通过角标去访问，也不能修改   遍历
    for (list<int>::iterator it = listVar.begin(); it != listVar.end() ; it ++) {
        cout << *it << endl;
    }

    return 0;
}

