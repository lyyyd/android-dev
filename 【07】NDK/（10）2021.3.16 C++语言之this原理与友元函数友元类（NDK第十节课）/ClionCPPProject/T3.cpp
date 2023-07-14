// 2.C++static关键字。 错误的写法

#include <iostream>

using namespace std;

class Dog {
public:
    char * info;
    int age;

    // 已经编译不成功，不允许这样初始化
    // static int id = 9;
    static int id;

    Dog() {
        // 运行报错
        // id = 9;
    }

    static void update() {
        // 运行报错
        // id = 9;
    }

    void update2() {
        // 运行报错
        // id = 9;
    }
};

int main() {
    Dog dog;
    Dog::update(); // 类名::可以调用静态函数
    return 0;
}