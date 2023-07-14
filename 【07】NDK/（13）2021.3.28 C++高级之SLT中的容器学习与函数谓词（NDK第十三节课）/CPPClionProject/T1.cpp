// Java的集合框架 非常强大  相当于  C++  STL（标准模板库） #include <iostream>

// TODO STL 是“Standard Template Library”的缩写，中文译为“标准模板库”。STL 是 C++ 标准库的一部分，不用单独安装。

// STL 有很多很多的容器
// C++ STL 设计思路 和 Java不同

// C ++ vector 向量 容器 （内部：封装动态大小数组作为容器，能够存放任意的动态数组【数据结构】）

#include <iostream>

#include <vector> // 引入 vector 容器的支持

// NDK 开发 一定要用容器  应该 queue 队列

using namespace std;

int main() {
    std::cout << "标准模板库" << std::endl;

    vector<int> vector1;

    vector<int> vector2(10); // 指定10的空间大小

    vector<int> vector3(10, 0); // 有了10个值了 每个值都是0

    vector<int> vector4;

    // vector4.begin() 迭代器 插入到前面
    // vector4.end() 迭代器 插入到后面

    // 插入数据
    vector4.insert(vector4.begin(), 40);
    vector4.insert(vector4.begin(), 60);
    vector4.insert(vector4.begin(), 80);
    vector4.insert(vector4.begin(), 100);
    vector4.insert(vector4.begin(), 200);

    // 第一个
    cout << " 修改前：vector4.front():" << vector4.front() << endl;
    vector4.front() = 99; // 默认修改第一个
    cout << " 修改后：vector4.front():" << vector4.front() << endl;

    // 最后一个
    cout << " 修改前：vector4.back():" << vector4.back() << endl;
    vector4.back() = 777; // 默认修改最后
    cout << " 修改后：vector4.back():" << vector4.back() << endl;

    vector4.erase(vector4.begin()); // 移除第一个元素（内部：通过迭代器的位置 进行移除）  删除

    // 循环打印，默认 从大到小输出
    for (int i = 0; i < vector4.size(); ++i) {
        cout << "item:" << vector4[i] << endl;
    }

    // KT的类型推到  相当于 C++ auto
    /*var a = 10;
    var b = 30.4f;
    var c = "";*/

    // 迭代器 循环遍历
    // auto Kotlin自带类型推到
    // for (vector<int>::iterator iteratorVar = vector4.begin(); iteratorVar != vector4.end(); iteratorVar++) {
    for (auto iteratorVar = vector4.begin(); iteratorVar != vector4.end(); iteratorVar++) {
        // 迭代器 当中指针操作  iteratorVar++
        cout << "迭代器：" << *iteratorVar << endl;
    }

    cout << "" << endl;

    return 0;
}
