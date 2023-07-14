// 3.C++对象中，为什么需要 this。

#include <iostream> // iostream.h 早期C++的方式

using namespace std;

class Student {
private:
    char *name;
    int age;

public:
    static int id; // 先声明

public:
    void setName(char *name) {
        this->name = name;
    }
    void setAge(int age) {
        this->age = age;
    }
    char *getName() {
        return this->name;
    }
    int getAge() {
        return this->age;
    }

public:
    // 默认的构造函数 栈区开辟空间 暴露 地址 == this指针 (和Java一致的思路)
};

// 再实现
int Student::id = 9527;

int main() {
    // ======= 常规使用下而已
    Student student;
    student.setAge(99);
    student.setName("Derry");
    cout << student.getName() << " , " << student.getAge()<< endl;

    // ==========  this 纠结
    Student student1;
    student1.setAge(88); // 设置值的时候，它怎么知道是给student1的age设置值的？
    student1.id = 880;

    Student student2;
    student2.setAge(99); // 设置值的时候，它怎么知道是给student2的age设置值的？
    student2.id = 990;

    Student::id = 666;

    // 它怎么知道是获取student1的age
    cout << " student1.getAge:" << student1.getAge() << endl;

    // 它怎么知道是获取student2的age
    cout << " student2.getAge:" << student2.getAge() << endl;

    cout << "student1.id:" << student1.id << endl;
    cout << "student2.id:" << student2.id << endl;
    cout << "Student:::" << Student::id << endl;


    return 0;
} // main函数弹栈会 隐士代码：（栈区：delete student ...， 堆区需要自己手动delete）

