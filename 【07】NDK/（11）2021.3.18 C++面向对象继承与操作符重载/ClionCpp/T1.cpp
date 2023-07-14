// 1.类外运算符重载。

#include <iostream>
using namespace std;

class Derry {
private:
    int x,y;

public:
    // 系统C++源码，大量使用此方式 :x(x), y(y)
    Derry(int x, int y) :x(x), y(y) {}

    // set get 函数
    void setX(int x) {
        this->x = x;
    }
    void setY(int y) {
        this->y = y;
    }
    int getX() {
        return this->x;
    }
    int getY() {
        return this->y;
    }
};

// 在真实开发过程中，基本上都是写在类的里面的，为什么？ 娓娓道来  答：外部是不能获取内部的私有成员的
// 把+重载 运算符重载
Derry operator + (Derry derry1, Derry derry2) {
    int x = derry1.getX() + derry2.getX();
    int y = derry1.getY() + derry2.getY();

    Derry res(x, y);
    return res;
}

int main() {
    std::cout << "NDK的第十一节课，同学们大家好" << std::endl;

    // 对象1 + 对象2   C++默认不支持的， Java也不支持，Kotlin也不支持

    // C++/Kotlin 运算符重载 + 把+重载掉

    Derry derry1(1000, 2000);
    Derry derry2(3000, 4000);

    Derry derry = derry1 + derry2; // C++/Java/Kotlin

    cout << derry.getX() << " , " << derry.getY() << endl;

    return 0;
}
