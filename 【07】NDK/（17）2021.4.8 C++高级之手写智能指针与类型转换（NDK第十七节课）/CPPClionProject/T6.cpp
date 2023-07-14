// TODO C++ 期末考试  -- 手写智能指针 2

#include "CustomPtr.h"

class Student {
public:
    ~Student() {
        cout << "析构函数 释放Student" << endl;
    }
};

// TODO 智能指针内置的
void action() {
    Student *student1 = new Student();
    Student *student2 = new Student();

    // TODO 第一种情况
    /*shared_ptr<Student> sharedPtr1(student1);
    shared_ptr<Student> sharedPtr2(student2);*/

    // TODO 第二种情况
    /*shared_ptr<Student> sharedPtr1 (student1);
    shared_ptr<Student> sharedPtr2 = sharedPtr1;*/

    // TODO 通用的打印
    /*cout << "智能指针内置的 sharedPtr1:" << sharedPtr1.use_count() << endl;
    cout << "智能指针内置的 sharedPtr2:" << sharedPtr2.use_count() << endl;*/
}

// TODO  手写的智能指针
void action2() {
    Student *student1 = new Student();
    Student *student2 = new Student();

    // TODO 第一种情况
    /*Ptr<Student> sharedPtr1(student1);
    Ptr<Student> sharedPtr2(student2);*/

    // TODO 第二种情况
    /*Ptr<Student> sharedPtr1 (student1);
    Ptr<Student> sharedPtr2 = sharedPtr1;*/

    // TODO 第二种情况
    // TODO 情况一
    /*Ptr<Student> sharedPtr1 (student1); // sharedPtr1构建对象
    Ptr<Student> sharedPtr2; // sharedPtr2也会构建对象， 此对象指向了object 与 count，必须释放

    // 在你写下面这个之前，我必须是发 sharedPtr2 的所有 object count 全部释放
    // sharedPtr2完全释放干净后，我才放心然你赋值 sharedPtr2 = sharedPtr1
    sharedPtr2 = sharedPtr1;*/


    // TODO 情况二
    Ptr<Student> sharedPtr1 (student1); // sharedPtr1构建对象
    // student2 成为野对象（每一被智能指针管理的对象 称为 野对象）
    Ptr<Student> sharedPtr2 (student2);

    // 在你写下面这个之前，我必须是发 sharedPtr2 的 的 student2 全部释放成功
    // sharedPtr2完全释放干净后,才放心然你赋值 sharedPtr2 = sharedPtr1

    sharedPtr2 = sharedPtr1;

    // delete student2; // 如果--哪些逻辑不写，就必须手动是否 student2

    // TODO 通用的打印
    cout << "手写的智能指针 sharedPtr1:" << sharedPtr1.use_count() << endl;
    cout << "手写的智能指针 sharedPtr2:" << sharedPtr2.use_count() << endl;
}


int main() {
    cout << "下面是 C++内置智能指针 ===========" << endl;
    // action();
    cout << endl;

    cout << "下面是 自定义的智能指针 ===========" << endl;
    action2();
}



