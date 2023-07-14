#include "Pig.h"

// TODO  ======================  下面是 普普通通 常规操作 对象::

// 实现构造函数
Pig::Pig() {
    cout << "默认构造函数" << endl;
}

Pig::Pig(char * name) {
    cout << "1个参数构造函数" << endl;
}

Pig::Pig(char * name, int age) {
    cout << "2个参数构造函数" << endl;
}

// 实现析构函数
Pig::~Pig() {
    cout << "析构函数" << endl;
}

// 实现 拷贝构造函数
Pig::Pig(const Pig &pig) {
    cout << "拷贝构造函数" << endl;
}

int Pig::getAge() {
    return this->age;
}
char * Pig::getName() {
    return this->name;
}
void Pig::setAge(int age) {
    this->age = age;
}
void Pig::setName(char * name) {
    this->name = name;
}

void Pig::showPigInfo() const {

} // 常量指针常量 只读



// TODO ===============================  静态 和 友元 注意点 自己理解

// 实现 静态属性【不需要增加 static关键字】
int Pig::id = 878;

// 实现静态函数，【不需要增加 static关键字】
void Pig::changeTag(int age) {

}

// 友元的实现
// 友元特殊：不需要关键字，也不需要 对象:: ,只需要保证 函数名（参数）
void changeAge(Pig * pig, int age) {

}

