// 中午输出的问题，一次解决：ctrl+alt+shift+/

// 1.map容器学习。

#include <iostream>
#include <map>

using namespace std;

int main() {
    cout << "1.map容器学习。" << endl;

    // 注意：map会对key进行排序，默认 key不能重复
    map<int, string> mapVar;

    // TODO 添加数据
    // 第一种方式
    mapVar.insert(pair<int, string>(1, "一"));

    // 第二种方式
    mapVar.insert(make_pair(2, "二"));

    // 第三种方式
    mapVar.insert(map<int, string>::value_type (3, "三"));

    // 上面三种方式 key不能重复
    // 思考：既然会对key进行排序，那么key是不能重复的（会插入失败）
    mapVar.insert(pair<int, string>(3, "三3"));

    // 第四种方式    mapVar[key]=Value
    mapVar[4] = "四";
    mapVar[4] = "肆"; // 第四种方式覆盖/替换（常用）

    /**
     *  typedef typename _Rep_type::iterator		 iterator;  之前常规的迭代器
        typedef typename _Rep_type::const_iterator	 const_iterator;  只读的，只能读，不能修改 的迭代器
        typedef typename _Rep_type::reverse_iterator	 reverse_iterator;  倒序打印的迭代器
     */

    // 循环打印，迭代器
    for (map<int, string>::iterator it = mapVar.begin() ; it != mapVar.end() ; it ++) {
        cout << it->first << "," << it->second.c_str() << "\t";
    }
    cout << endl;

    // Derry想知道，怎么判断插入成功、失败
    std::pair<map<int, string>::iterator, bool> result = mapVar.insert(map<int, string>::value_type (6, "66三san"));
    if (result.second) {
        cout << "插入成功" << endl;
    } else {
        cout << "插入失败" << endl;
    }
    // 我想知道插入后的 数据
    for (result.first == mapVar.begin(); result.first != mapVar.end() ; result.first++) {
        cout << result.first->first << " , " << result.first->second <<  endl;
    }

    // 查找，操作
    map<int, string> ::iterator findResult = mapVar.find(3); // 查找
    if (findResult != mapVar.end()) {
        cout << "恭喜，找到了" << findResult->first << "," << findResult->second.c_str() << endl;
    } else {
        cout << "不恭喜，没找到了" << endl;
    }

    return 0;
}

