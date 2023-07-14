// 3.括号运算符。   数组 系统源码把此括号[i]给重载，  系统重载后的样子 *(arr+i)

#include <iostream>
using namespace std;

// 写一个小容器，模拟容器
class ArrayClass {

private:
    // C++ 默认都是系统值  size 系统值 -13275
    int size = 0; // 大小  开发过程中，给size赋默认值，不然会出现，后患无穷的问题
    int * arrayValue; // 数组存放 int 类型的很多值

public:
    void set(int index, int value) {
        arrayValue[index] = value; // []目前不是我的
        size+=1;
    }
    int getSize() { // size成员的目标：是为了循环可以遍历
        return this->size;
    }
    // 运算符重载 [index]
    int operator[](int index) {
        return this->arrayValue[index]; // 系统的
    }
};

// 输出容器的内容
void printfArryClass(ArrayClass arrayClass) {
    cout << arrayClass.getSize() << endl;
    for (int i = 0; i < arrayClass.getSize(); ++i) {
        cout << arrayClass[i] << endl; // []是我们自己的 重载符号
    }
}

int main() {
    // 能在栈区的，尽量在栈区
    // 1.代码量少
    // 2.避免麻烦
    // 3.怕有问题
    // 4.栈区的回收，不是你负责的，责任推卸

    ArrayClass arrayClass;  // 栈区    实例出来的对象，是在堆区了

    arrayClass.set(0, 1000);
    arrayClass.set(1, 2000);
    arrayClass.set(2, 3000);
    arrayClass.set(3, 4000);
    arrayClass.set(4, 5000);

    printfArryClass(arrayClass);

    return 0;
}

