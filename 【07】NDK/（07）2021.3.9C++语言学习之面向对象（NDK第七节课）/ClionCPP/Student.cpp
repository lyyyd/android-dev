#include "Student.h"

// 根据 Student.h 头文件 ，写实现

// 和实现头文件那个函数，没有任何关系，相当于另外一个函数
/*void setAge(int age) {

}*/

void Student::setAge(int age) { // 实现函数
    // C++对象指向的是一个指针
    // -> 调用一级指针的成员
    this->age = age;
}

void  Student::setName(char * name) { // 实现函数
    this->name = name;
}
int Student::getAge() { // 实现函数
    return this->age;
}
char * Student:: getName() { // 实现函数
    return this->name;
}
