#ifndef CPPCLIONPROJECT_CUSTOMPTR_H
#define CPPCLIONPROJECT_CUSTOMPTR_H

#pragma once
#include <iostream>
#include <memory> // 智能指针的
using namespace std;

template<typename T>
class Ptr {
private:
    T * object; // 用于智能指针指向管理的对象  Person Student
    int * count; // 引用计数

public:
    Ptr() {
        count = new int (1); // new 的对象 必须 *指针   【new只是为了后面操作方便】
        object = 0; // 因为你没有给他对象呀，人家也没有对象呀，没办法
    }

    // t = Person Student
    Ptr(T * t) :object(t) {
        // 只有你存入对象，那么引用计数为1，这个是很合理的
        count = new int (1);
    }

    // 析构函数
    ~Ptr() {
        // 引用计数减1，为0标识可以释放object了
        if (--(*count) ==0) {
            if (object) {
                delete object;
            }
            // 归零
            delete count;
            object = 0;
            count = 0;
        }
    }

    // 拷贝构造函数
    Ptr(const Ptr<T> & p) {
        cout << "拷贝构造函数" << endl;

        // sharedPtr1 == p 的引用计数 +1  = 2
        ++(*p.count);

        object = p.object;
        count = p.count; // 最终是不是 p.count==2 给 count==2
    }

    // 自定义 =号运算符重载
    Ptr<T> & operator = (const Ptr<T> & p) {
        cout << "=号运算符重载" << endl;

        ++(*p.count);

        // 这个点非常绕  跳过  看不懂没有关系，后面专门解释 (配合代码)
        if (--(*count) == 0) {
            if (object) {
                delete object;
            }
            delete count;
        }

        object = p.object;
        count = p.count;
        return *this; // 运算符重载的返回
    }

    // 返回引用计数的数值
    int use_count() {
        return *this->count;
    }
};


#endif //CPPCLIONPROJECT_CUSTOMPTR_H
