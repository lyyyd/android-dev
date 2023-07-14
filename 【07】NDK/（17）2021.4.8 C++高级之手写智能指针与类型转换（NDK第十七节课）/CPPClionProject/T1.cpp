// TODO 智能指针初探 内部机制原理

// 在真实开发过程中，才能体系智能指针的用途，否则写demo无法体现，为什么？
// 因为真实开发过程中，很很多的代码，可能会导致你忘记写 delete 对象；
// new 对象  我就马上 加入到 智能指针  我就不会忘记了

#include <iostream>
#include <memory> // 智能指针的头文件引入
using namespace std;

class Person {
public:
    ~Person() {
        cout << "Person 析构函数" << endl;
    }
};

int main() {
    std::cout << "C++最后一节课" << std::endl;

    Person * person1 = new Person(); // 堆区开辟
    Person * person2 = new Person(); // 堆区开辟

    // 以前：
    // delete person1; 忘记写了，怎么办，非常严重的问题，没法释放

    // 现在：
    // shared_ptr<Person> sharedPtr1(person1); // 智能指针帮你释放堆区开辟的 --> Person 析构函数

    /*
     *
     *
     *
     *
     *
     *
     *
     *
     *
     *
     *   10000行代码
     *
     *
     *
     *
     *
     *
     *
     *
     *
     *
     *
     */
    // 最后，就忘记给人家 delete person1
    // 如果 加入到 智能指针，我就不用管了

    shared_ptr<Person> sharedPtr1(person1); // 栈区开辟sharedPtr1， 加1 等于1 引用计数
    shared_ptr<Person> sharedPtr2(person2); // 栈区开辟sharedPtr2  加1 等于1 引用计数

    return 0;
}
// main函数弹栈，会释放 所有的栈成员 sharedPtr1 调用 sharedPtr1析构函数 减1 等于0  直接释放person1
// main函数弹栈，会释放 所有的栈成员 sharedPtr2 调用 sharedPtr2析构函数 减1 等于0  直接释放person2
