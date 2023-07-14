// 1.构造函数详讲， 2.析构函数，  3.Java/KT的所谓的析构函数。
#include <iostream>
#include <string.h>
using namespace std;

class Student {

// 构造函数
public:
    // 空参数构造函数
    Student() {
        cout << "空参数构造函数" << endl;
    }

    // 一个参数的构造函数
    // :Student(name, 87) 等价 1.调用两个参数的构造函数， 2.再调用当前函数
    // 学生说的：先调用两个参数的，再调用一个的
    Student(char *name) :Student(name, 87) {
        cout << "一个参数的构造函数" << endl;
        this->name = name;
    }
    // 系统源码中是写的
    // :name(name) 等价 this->name = name;
    /*Student(char * name) :name(name) {
        cout << "一个参数的构造函数" << endl;
    }*/

    // 两个参数的构造函数
    Student(char *name, int age) {
        // this->name = name;

        // 堆区
        this->name = (char *) (malloc(sizeof(char *) * 10));
        strcpy(this->name, name);

        this->age = age;
        cout << "两个参数的构造函数" << endl;
    }

    // 析构函数 Student对象的，临终遗言，Student对象被回收了，你做一些释放工作
    // delete stu 的时候，我们的析构函数一定执行
    // free不会执行析构函数，也意味着，你没法在析构函数里面，做释放工作， malloc也不会调用构造函数
    ~Student() {
        cout << "析构函数" << endl;

        // 必须释放 堆区开辟的成员
        if (this->name) {
            free(this->name);
            this->name = NULL; // 执行NULL的地址，避免出现悬空指针
        }
    }

// 私有属性
private:
    char *name;
    int age;

// 公开的 set get 函数
public:
    int getAge() {
        return this->age;
    }

    char *getName() {
        return this->name;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setName(char *name) {
        this->name = name;
    }
};

int main() {
    // TODO  =========== 下面是栈区 开辟空间的

    /*Student stu; // 调用 空参数构造函数
    stu.setAge(34);
    stu.setName("李元霸");
    cout << "name:" << stu.getName() << ", age:" << stu.getAge() <<  endl;*/

    // Student stu("雄霸", 30);
    /*Student stu("李连杰");
    cout << "name:" << stu.getName() << ", age:" << stu.getAge() <<  endl;*/

    // TODO =========== 下面是堆区 开辟空间的  堆区必须手动释放，否则内存占用越来

    // 系统源码中，会看到，很多使用 new 关键字

    // *stu  ->：调用一级指针的成员
    // new/delete
    // C++中，必须使用 new/delete 一套
    Student *stu = new Student("杜子腾", 26);
    cout << "name:" << stu->getName() << ", age:" << stu->getAge() <<  endl;
    delete stu;

    // free(stu); 这样写是不规范的，不按人家规则来

    // 还有人这样写 (C工程师，搞了六年，改不了自己的习惯， malloc)
    // malloc 你的构造函数都没有调用，这个不行的
    /*Student *stu2 = (Student*) malloc(sizeof(Student));
    free(stu2);*/

    // 纠结：C++有析构函数（临终遗言 释放工作）    Java KT 临终遗言 是什么？

    return 0;
}
