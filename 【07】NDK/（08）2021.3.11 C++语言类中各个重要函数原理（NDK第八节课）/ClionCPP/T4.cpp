// 4.拷贝构造函数。

#include <iostream>
#include <string.h>

using namespace std;

class Student {

public:
    Student() { cout << "空参数构造函数" << endl; }

    // 两个参数的构造函数
    Student(char *name, int age) : name(name), age(age) {
        cout << "两个参数构造函数" << endl;
    }

    // 析构函数
    // ~Student(char * name) { } 这样写，就不是析构函数了，如果你这样写，C/C++编译器对你很无语
    ~Student() {
        cout << "析构函数" << endl;
    }

    // 以前是默认有一个拷贝构造函数，stu2 = stu1 默认赋值 【隐士 你看不到】

    // 拷贝构造函数，它默认有，我们看不到，一旦我们写拷贝构造函数，会覆盖她
    // 对象1 = 对象2
    // 覆盖拷贝构造函数
    Student(const Student & student) { // 常量引用：只读的，不让你修改
        cout << "拷贝构造函数" << endl;

        // 我们自己赋值
        // 为什么要自己赋值，自己来控制，就可以 例如：-10
        this->name = student.name;
        this->age = student.age - 10;

        cout << "自定义拷贝构造函数 内存地址 " << &student << endl;
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

struct Person {
    int age;
    char *name;
};

// TODO = 号的意义 隐士代码，引出 拷贝构造函数
/*
int main() {
    Person person1 = {100, "张三丰"};

    // = 你看起来，没有什么特殊，隐士的代码：你看不到  C/C++编译器 会把p1的成员值赋值给p2成员
    Person person2 = person1;

    cout << &person1 << endl;
    cout << &person2 << endl;

    cout << person2.name << ",  " << person2.age << endl;

    // 思考：对象 对象1=对象2  默认的 拷贝构造函数

    return 0;
}*/

// TODO  拷贝构造函数
/*
int main() {
    Student stu1("李鬼", 34);
    Student stu2 = stu1;

    cout << stu2.getName() << " , " <<  stu2.getAge() <<  endl;
    cout << "main " << &stu1 << endl; // 地址的打印是一样的，  注意：cnetos的环境 地址打印有差异，要注意



    // TODO  拷贝构造函数的注意点：
    // Student stu1("李鬼", 34);

    // Student stu2;
    // stu2 = stu1; // 这样赋值是不会调用 自定义拷贝构造函数，但是会调用默认赋值
    // Student stu2 = stu1;  // 这样赋值是会调用 自定义拷贝构造函数，我们自己赋值

    // cout << stu2.getName() << " , " <<  stu2.getAge() <<  endl;

    getchar(); // 程序等待在这一行

    return 0;
} // main函数弹，stu1栈成员会回收  stu2栈成员会回收
*/

// TODO 这种写法 拷贝构造函数  到底会不会调用
int main() {
    Student *student1 = new Student("杜子腾", 39);

    Student *student2 = student1;  // 压根就不会执行拷贝构造函数（指针指向问题，和我们刚刚那个  对象2=对象1 是两回事）

    // 原理，为什么不会？ 纠结

    student2->setAge(99);

    cout << student1->getName() << student1->getAge() << endl;

    // “->”调用一级指针的成员    和    “.”非指针的操作  有啥区别

    return 0;
}

// Clion和VS差异太大了，放到下一节课，包括 内存地址的分析，等等，到下节课讲
// 下节课讲： 拷贝构造函数的，深拷贝 和 浅拷贝
