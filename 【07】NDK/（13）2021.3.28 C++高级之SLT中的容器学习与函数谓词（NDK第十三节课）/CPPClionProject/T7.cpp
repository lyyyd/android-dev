// 谓词 设计对象的排序

#include <iostream>
#include <set>

using namespace std;

// set（内部：红黑树结构），会对你存入的数据自动进行排序，但是绝对不允许元素相同

class Person {
public:
    string name;
    int id;
    Person(string name, int id) : name(name), id(id) {}
};

// C++ 都是一些常规的 谓词  不能满足功能， 模仿C++源码的谓词 自定义谓词 解决这个问题

// C++缔造者写的这个源码 没有对象比较的功能 【系统源码谓词 做不到对象比较功能】
// bool operator()(const _Tp& __x, const _Tp& __y) const { return __x < __y; }

// 我们就自定义这个功能  【自定义谓词 没有达到谓词的标准】
bool doCompareAction(const Person& person1, const Person& person2) {
    return person1.id < person2.id;
};

// 真正的谓词
struct doCompareAction2 {
public:
    bool operator() (const Person& __x, const Person& __y) {
        return __x.id < __y.id;
    }
};

struct doCompareAction3 {
public:
    bool operator() (const Person& __x, const Person& __y) {
        return __x.id > __y.id;
    }
};

int main() {
    // 默认是 less  return 对象1 < 对象2;

    set<Person, doCompareAction2> setVar;

    // set<Person, doCompareAction3> setVar;

    // 构建对象
    Person p1 ("Snake", 1);
    Person p2 ("kevin", 2);
    Person p3 ("Derry", 3);

    // 把构建的对象 插入到 set 容器里面去
    setVar.insert(p1);
    setVar.insert(p2);
    setVar.insert(p3);

    // name string  ---  c_str() ---->   char *
    for (set<Person>::iterator it = setVar.begin(); it != setVar.end() ; it ++) {
        cout << it->name.c_str() << " , " << it->id << endl;
    }

    return 0;
}

