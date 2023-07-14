// 4.const修饰函数的this意义何在。

#include <iostream>

using namespace std;

// 如果是面试C++岗位，会被回到，不然问不到

class Worker {
public:
    char * name;
    int age = NULL; // C++中不像Java，Java有默认值， 如果你不给默认值，那么就是系统值 -64664

    // int * const  指针常量 指针常量【地址对应的值能改，地址不可以修改】
    // const int *  常量指针 常量指针【地址可以修改，地址对应的值不能改】

    // 纠结：原理：为什么可以修改age
    // 默认持有隐士的this【类型 * const this】
    // 类型 * const 指针常量：代表指针地址不能被修改，但是指针地址的值是可以修改的
    void change1() {
        // 代表指针地址不能被修改
        // this = 0x6546;  // 编译不通过，地址不能被修改，因为是指针常量
        // 地址不可以修改
        // this = 0x43563;

        // 隐士的this
        // 但是指针地址的值是可以修改的
        // 地址对应的值能改
        this->age = 100;
        this->name = "JJJ";
    }

    // 默认现在：this 等价于 const Student * const  常量指针常量（地址不能改，地址对应的值不能改）
    void changeAction() const {
        // 地址不能改
        // this = 0x43563;

        // 地址对应的值不能改
        // this->age = 100;
    }

    // 原理：修改隐士代码  const 类型 * const 常量指针常量
    void showInfo() const {
        // this->name = "";
        // this->age = 88;

        // 只读的
        cout << "age:" << age << endl;
    }
};

int main() {
    return 0;
}
