// 2.虚继承，二义性。  在开发过程中，不准出现，如果出现，要知道怎么回事

#include <iostream>
using namespace std; // 已经声明了

// 租父类
class Object {
public: string info;
};

// 父类1/父类2
class Base1 : virtual public Object {};
class Base2 : virtual public Object {};

// 子类
class Main1 : public Base1, public Base2 {};

int main() {
    Object object; // 在栈区开辟，就会有一个this指针，假设指针是1000H，会有指向的能力
    Base1 base1; // 在栈区开辟，就会有一个this指针，假设指针是2000H，会有指向的能力
    Base2 base2; // 在栈区开辟，就会有一个this指针，假设指针是300H，会有指向的能力
    Main1 main1; // 在栈区开辟，就会有一个this指针，假设指针是4000H，会有指向的能力

    object.info = "A";
    base1.info = "B";
    base2.info = "C";
    main1.info = "D";

    cout << object.info << endl;
    cout << base1.info << endl;
    cout << base2.info << endl;
    cout << main1.info << endl;


    exit(0);
}