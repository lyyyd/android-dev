// 2.类里运算符重载。

#include <iostream>
using namespace std;

class Derry {
private:
    int x,y;

public:
    Derry() {

    }

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
        // this->x  -9; 系统怕你在函数里面 修改了
        return this->x;
    }
    int getY() {
        return this->y;
    }

    // +号，运算符重载
    /*Derry operator + (Derry derry1) {
        // this指针 指向当前对象，所以只需要一个
        int x = this->x + derry1.getX();
        int y = this->y + derry1.getY();
        return Derry(x, y);
    }*/

    // 系统是这样写的  常量引用：不允许修改，只读模式
    // const 关键字的解释
    // & 性能的提高，如果没有&  运行+ 构建新的副本，会浪费性能
    // 如果增加了& 引用是给这块内存空间取一个别名而已
    Derry operator + (const Derry& derry1) {
        // this指针 指向当前对象，所以只需要一个
        int x = this->x + derry1.x; // 我在类的里面，是可以拿私有成员的
        int y = this->y + derry1.y; // 我在类的里面，是可以拿私有成员的
        return Derry(x, y);
    }

    // 运算符- 重载
    Derry operator - (const Derry & derry1) {
        int x = this->x - derry1.x;
        int y = this->y - derry1.y;
        return Derry(x, y);
    }

    // 对象++ 运算符 重载
    void operator ++() { //  ++对象
        this->x = this->x + 1;
        this->y = this->y + 1;
    }
    void operator ++ (int) { // 对象++
        this->x = this->x + 1;
        this->y = this->y + 1;
    }

    // istream 输入 系统的
    // ostream 输出 系统的
    // 输出 运算符重载 复杂 涉及到规则  重载<<
    friend void operator << (ostream & _START, Derry derry1) {
        // 输出换行：<< endl;
        _START << " 单 哥开始输出了 " << derry1.x << " ! " << derry1.y << " 哥结束了 " << endl;
    }

    // 多个的  ostream 输出 系统的
    // 输出 运算符重载 复杂 涉及到规则  重载 >>
    /*friend ostream & operator >> (ostream & _START, const Derry & derry1) {
        _START << " 多 哥开始输出了 " << derry1.x << " ! " << derry1.y << " 哥结束了 " << endl;
        return _START;

        // RxJava 链式调用  .操作符.操作符.操作符 你每次都是放回this  一个思路
    }*/

    // istream 输入 系统的
    friend istream & operator >> (istream & _START, Derry & derry) {
        // 接收用户的输入，把输入的信息，给x

        // _START >> derry.x;
        // _START >> derry.y;

        // 可读性不好，简化了
        _START >> derry.x >> derry.y;

        return _START;
    }
};

int main() {
    Derry derry1(1000, 2000);
    Derry derry2(3000, 4000);

    // Derry result = derry1 + derry2;

    // Derry result = derry2 - derry1;

    Derry result(1, 2);
    result++;
    ++result;

    cout << result.getX() << " , " << result.getY() << endl;

    cout << endl; // 系统的换行

    // 自定义的，系统没有考虑 你要输出 derry1对象，怎么办？ 我们需要自定义 <<
    cout << derry1; // 单个的

    // cout >> derry1 >> derry1 >> derry1 >> derry1; // 多个的

    cout << endl; // 系统的换行

    // cout 输出的 C++
    // cin 输入的 C++

    Derry res;
    cin >> res; // >> 是我们自己重载的哦
    cout << "你输入的是：" << res.getX() << endl;
    cout << "你输入的是：" << res.getY() << endl;

    return 0;
}

