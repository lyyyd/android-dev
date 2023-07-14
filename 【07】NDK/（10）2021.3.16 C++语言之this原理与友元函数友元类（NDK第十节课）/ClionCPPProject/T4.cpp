// 2.C++static关键字。 正确的写法

/**
 * 静态的总结：
 * 1.可以直接通过类名::静态成员（字段/函数）
 * 2.静态的属性必须要初始化，然后再实现（规则）
 * 3.静态的函数只能取操作静态的属性和方法（Java）
 */

#include <iostream>

using namespace std;

class Dog {
public:
    char * info;
    int age;

    // 先声明
    static int id;

    static void update() {
        id += 100;

        // 报错:静态函数不能调用非静态函数（Java）
        // update2();
    }

    void update2() {
        id = 13;
    }
};

// 再实现
int Dog::id = 9;

int main() {
    Dog dog;
    dog.update2(); // 普通函数
    Dog::update(); // 静态函数
    dog.update(); // 对象名.静态函数（一般都是使用::调用静态成员，这种方式可以 知道就行）

    cout << Dog::id << endl;
    return 0;
}
