#include <iostream>

using namespace std;

// Student.h 头文件  只写声明，不写实现

class Student {

private: // 下面的代码（成员和函数），都是私有
    char * name;
    int age;

public: // 下面的代码（成员和函数），都是公开
    // set get
    void setAge(int age); // 声明函数
    void setName(char * age); // 声明函数
    int getAge(); // 声明函数
    char * getName(); // 声明函数
};
