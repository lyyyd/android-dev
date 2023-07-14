// TODO C++ 期末考试  -- 手写智能指针

#include <iostream>
#include <memory> // 智能指针的头文件引入

using namespace std;

class Person {};

int main() {
    Person * person1 = new Person();
    // Person * person2 = new Person();

    // shared_ptr<Person> sharedPtr0;

    shared_ptr<Person> sharedPtr1(person1); // +1 引用计数

    // 第一种情况 会调用拷贝构造函数
    // shard_ptr智能指针的特性
    // shared_ptr<Person> sharedPtr2 = sharedPtr1;  // +1 再引用计数  不会调用构造函数，只能执行拷贝构造函数

    // 第二种情况 不会调用拷贝构造函数
    shared_ptr<Person> sharedPtr2;  // +1 再引用计数   先构造函数 开辟sharedPtr2对象

    // 给sharedPtr2对象 从新赋值
    sharedPtr2 = sharedPtr1; // 自定义 =号运算符重载


    return 0;
}
// main函数弹栈 sharedPtr1栈成员  ---> 析构函数 --等于0 就释放对象



