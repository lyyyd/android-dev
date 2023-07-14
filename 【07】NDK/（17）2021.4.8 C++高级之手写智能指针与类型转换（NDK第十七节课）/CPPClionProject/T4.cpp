// TODO unique 智能指针  设计的够简单，每一那么多功能  [独占式智能指针]

#include <iostream>
#include <memory> // 智能指针的头文件引入

class Person {};

int main() {
    Person * person1 = new Person();
    Person * person2 = new Person();

    std::unique_ptr<Person> uniquePtr1(person1);

    // 严格禁止
    // std::unique_ptr<Person> uniquePtr2 = uniquePtr1;  unique不允许，因为是独占的

    // shared_ptr 是可以的，会造成隐患问题

    return 0;
}


