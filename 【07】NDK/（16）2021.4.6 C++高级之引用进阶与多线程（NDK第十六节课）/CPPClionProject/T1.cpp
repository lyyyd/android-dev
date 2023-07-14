// TODO 1.引用进阶。

#include <iostream>
#include <vector>
using namespace std;

// TODO  =========================== [引用的本质就是指针]
/*// TODO 指针 互相换两个数
int changeNumber(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

// TODO 引用 互相换两个数  [引用的本质就是指针]
int changeNumber2(int & n1, int & n2) { // 隐式：int * n1, int * n2
    int temp = n1; // int temp = *n1;
    n1 = n2; //  *n1 = *n2;
    n2 = temp; // *n2 = temp;
}

int main() {
    int number1 = 100;
    int number2 = 200;
    // changeNumber(&number1, &number2);

    // 我下面不需要去地址给他，为什么也可以，C、C++编译器 已经帮我们做了，所以无需写 &num 直接num
    changeNumber2(number1, number2);

    cout << number1 << " , " << number2 << endl;

    return 0;
}*/

// TODO ============================ [左值 右值 引用]
class Student {
private:
    string  info = "AAA"; // 旧变量

    // TODO 第一种情况【getInfo函数的info 与 main函数的result 是旧与新的两个变量而已，他们是值传递，所以右值修改时，影响不了里面的旧变量】
public:
    string getInfo() {
        return this->info;
    }

    // TODO 第二种情况【getInfo函数的info 与 main函数的result 是引用关系，一块内存空间 有多个别名而已，所以右值修改时，直接影响旧变量】
public:
    string & getInfo_front() {
        return this->info;
    }
};

int main() {
    /*vector<int> v;
    int r = v.front(); // 左值 获取
    v.front() = 88; // 右值 修改*/

    Student student;

    // TODO 第一种情况
    student.getInfo() = "九阳神功";
    string result = student.getInfo();
    cout << "第一种情况:" << result << endl;

    // TODO 第二种情况
    student.getInfo_front() = "三分归元气"; // 右值 修改内容
    result = student.getInfo_front(); // 左值 获取内容
    cout << "第二种情况:" << result << endl;
}