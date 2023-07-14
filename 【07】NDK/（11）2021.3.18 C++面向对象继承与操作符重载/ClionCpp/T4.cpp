// 4.C++对象继承。

#include <iostream>

using namespace std;

class Person {
public:
    char *name;
    int age;

public:
    Person(char *name, int age) : name(name) {
        this->age = age;
        cout << "Person 构造函数" << endl;
    }

    void print() {
        cout << this->name << " , " << this->age << endl;
    }
};

// 1.默认是 隐式代码： : private Person
// 2.私有继承：在子类里面是可以访问父类的成员，但是在类的外面不行
// 3.必须公开继承，才可以访问父类的成员
class Student : public Person {

// 类 默认是私有，注意下

private:
    char * course;

public:
    // :父类 , 给自己子类成员初始化
    Student(char * name, int age, char* course) : Person(name, age) , course(course) {
        cout << "Student 构造函数" << endl;
    }

    void test() {
        cout << name << endl;
        cout << age << endl;
        print();
    }
};

int main() {
    Student stu("李元霸", 99, "C++");

    // 公开继承，才可以拿父类的成员
    stu.name = "李四";

    return 0;
}

