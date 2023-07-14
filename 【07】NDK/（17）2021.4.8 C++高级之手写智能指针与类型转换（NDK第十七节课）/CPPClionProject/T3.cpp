// TODO 智能指针 解决循环依赖的问题  weak 智能指针 没有引用计数

// C++ 11后 推出智能指针，为什么要推出？  JVM非常厉害，完全不用管对象的回收的问题

#include <iostream>
#include <memory> // 智能指针的头文件引入
using namespace std;

class Person2; // 先声明 Person2 让我们的Person1 直接找到

class Person1 {
public:
    weak_ptr<Person2> person2; // Person2智能指针  没有引用计数 无法+1
    ~Person1() {
        cout << "Person1 析构函数" << endl;
    }
};

class Person2 {
public:
    weak_ptr<Person1> person1;  // Person1智能指针  没有引用计数 无法+1
    ~Person2() {
        cout << "Person2 析构函数" << endl;
    }
};


int main() {
    Person1 * person1 = new Person1(); // 堆区开辟
    Person2 * person2 = new Person2(); // 堆区开辟

    shared_ptr<Person1> sharedPtr1(person1); // +1 = 1
    shared_ptr<Person2> sharedPtr2(person2); // +1 = 1

    cout << "前 sharedPtr1的引用计数是:" << sharedPtr1.use_count() << endl;
    cout << "前 sharedPtr2的引用计数是:" << sharedPtr2.use_count() << endl;

    // 给Person2智能指针赋值
    person1->person2 = sharedPtr2;
    // 给Person1智能指针赋值
    person2->person1 = sharedPtr1;

    cout << "后 sharedPtr1的引用计数是:" << sharedPtr1.use_count() << endl;
    cout << "后 sharedPtr2的引用计数是:" << sharedPtr2.use_count() << endl;

    return 0;
} // 减1 = 0 释放对象

