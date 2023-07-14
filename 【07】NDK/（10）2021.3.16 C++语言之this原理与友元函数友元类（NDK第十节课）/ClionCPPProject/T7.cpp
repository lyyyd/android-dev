// 友元函数

// 老外：你是它的好朋友，那就可以拿私有成员给好朋友

#include <iostream>

using namespace std;

class Person {
private: // 私有的age，外界不能访问
    int age = 0;

public:
    Person(int age) {
        this->age = age;
    }

    int getAge() {
        return this->age;
    }

    // 定义友元函数 (声明，没有实现)
    friend void updateAge(Person * person, int age);
};

// 友元函数的实现，可以访问所以私有成员
void updateAge(Person* person, int age) {
    // 默认情况下：不能修改 私有的age
    // 谁有这个权限：友元（拿到所有私有成员）
    person->age = age;
}

int main() {
    Person person = Person(9);
    updateAge(&person, 88);

    cout << person.getAge() << endl;
    return 0;
}
