// 1.源码中属性初始化的方式。

#include <iostream>
using namespace std; // 已经声明了

// 人类
class Person {
protected:
    // 注意：string 是 std 命名空间里面的成员，C++源码是这种写法std::string
    // string内部其实就是对 char*的封装
    string name;
    int age;
public:
    Person(string name, int age) :name(name), age(age) {}
};

// 课程类
class Course {
private:
    string name;
public:
    Course(string name) :name(name) {}
};

class Student : public Person {
private:
    // 如果定义的是对象成员，必须这样初始化(构造函数的后面 : 对象成员(内容))  使用我们的第二种方式
    Course course; // 对象成员
public:
    Student(string name, int age, Course course1, string courseNameInfo)
    :Person(name, age) // 既然继承了父类就必须给父类的构造函数初始化

    // ,

    // course(course1) // 第二种方式，编译阶段认可的 对象=对象   对象直接的赋值而已

     ,

     course(courseNameInfo) // 第三种方式， 对象(string内容)  直接初始化Course对象 --- 构造函数

    {
        // this->course = course1; // 第一种方式（对象=对象） 编译阶段不认可，无法监测到你是否真的给course对象成员初始化了
    }
};

int main() {
    Course c("C++");
    Student student("Derry", 30, c, "NDK内容真多");

    return 0;
}
