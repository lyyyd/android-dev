// 3.四种类型转换。 const_cast     const修饰的 都可以去转换

#include <iostream>

using namespace std;

class Person {
public:
    string name = "default";
};

int main() {
    const Person * p1 = new Person();
    // p1->name = "Derry"; // 报错：常量指针，不写修改值

    Person * p2 = const_cast<Person *>(p1); // 转成 非常量指针
    p2->name = "Derry";

    cout << p1->name << endl;

    return 0;
}

