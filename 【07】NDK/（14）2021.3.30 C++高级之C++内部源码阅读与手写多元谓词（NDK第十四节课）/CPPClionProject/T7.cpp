// 专业的C++工程师开发有用 ，知识补充： 对象存入到容器后  对象的生命周期 状态

#include <iostream>
#include <set> // set 存入对象 奔溃（set会自动排序，对象没法排序，所以奔溃）  解决方案：自定义仿函数解决
#include <vector>  // 存入对象

using namespace std;

class Person {
private:
    string name;
public:
    Person(string name) : name(name) {}

    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return this->name;
    }

    Person(const Person &person) {
        this->name = person.name; // 浅拷贝

        cout << "Person拷贝构造函数执行了..." << endl;
    }

    ~Person() {
        cout << "Person析构函数执行了" << endl;
    }
};

int main() {
    // Java：把对象存入 添加到 集合
    // C++: 调用拷贝构造函数，存进去的是另一个新的对象

    vector<Person> vectorVar;

    // person 被main函数弹栈 析构一次
    Person person("Derry"); // 2  Derry

    // 里面的insert函数弹栈 析构一次
    vectorVar.insert(vectorVar.begin(), person); // 外面的person是旧地址，到insert函数里面的person就是新地址（拷贝构造函数 一次）

    person.setName("Kevin"); // 1

    // newPerson 被main函数弹栈 析构一次
    Person newPerson =
            vectorVar.front(); // front里面的person是旧地址， 外面的newPerson就是新地址（拷贝构造函数 一次）

    cout << "newPerson:" << newPerson.getName().c_str() << endl;

    // 3次析构函数   两次拷贝构造

    return 0;
} // main弹栈

