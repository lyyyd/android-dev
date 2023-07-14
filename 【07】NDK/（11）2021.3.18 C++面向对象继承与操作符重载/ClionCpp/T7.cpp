// 第三种解决方案： 【虚基类】 属于 虚继承的范畴
// 真实C++开始，是很少出现，二义性（歧义） 如果出现， 系统源码（系统用 第三种解决方案）

#include <iostream>

using namespace std;

// 祖父类
class Object{
public:
    int number;
    void show() {
        cout << "Object show run..." << endl;
    }
};

// 等下讲 virtual 的原理是什么 ...

// 父类1
class BaseActivity1 : virtual public Object {
// public:int number; // 人为制作二义性  error: request for member 'number' is ambiguous
};

// 父类2
class BaseActivity2 : virtual public Object {
// public:int number;
};

// 子类
class Son : public BaseActivity1, public BaseActivity2 {

};

int main() {
    Object object;
    BaseActivity1 baseActivity1;
    BaseActivity2 baseActivity2;
    Son son;

    object.number = 100;
    baseActivity1.number = 200;
    baseActivity2.number = 300;
    son.number = 400;

    object.show();
    baseActivity1.show();
    baseActivity2.show();
    son.show();

    cout << object.number << endl;
    cout << baseActivity1.number << endl;
    cout << baseActivity2.number << endl;
    cout << son.number << endl;

    return 0;
}

