// 多继承 二义性2：
// 在真实开发过程中，严格避免出现 二义性

#include <iostream>

using namespace std;

// 祖父类
class Object {
public:
    int number;
};

// 父类1
class BaseActivity1 : public Object {

};

// 父类2
class BaseActivity2 : public Object {

};

// 子类
class Son : public BaseActivity1, public BaseActivity2 {

    // 第二种解决方案： 在类中定义同名成员，覆盖掉父类的相关成员
public:
    int number;

};


int main() {
    Son son;

    // error: request for member 'show' is ambiguous  二义性 歧义
    // son.number = 2000;

    // 第一种解决方案： :: 明确指定
    son.BaseActivity1::number  = 1000;
    son.BaseActivity2::number  = 1000;

    // 第二种解决方案： 在类中定义同名成员，覆盖掉父类的相关成员
    son.number = 3000;

    // 第三种解决方案： 【虚基类】 属于 虚继承的范畴

    return 0;
}

