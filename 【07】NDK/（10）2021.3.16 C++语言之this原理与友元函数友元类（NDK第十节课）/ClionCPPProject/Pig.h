#include <iostream>

using namespace std;

// JNI 为什么一定要用这个东西（后面专门）

#ifndef PIG_H // 你有没有这个宏（Java 宏==常量）
#define PIG_H // 定义这个宏

class Pig {
private:
    int age;
    char * name;

public:
    // 静态成员声明
    static int id;

    // 构造函数的声明系列
    Pig();
    Pig(char *);
    Pig(char *,int);

    // 析构函数
    ~Pig();

    // 拷贝构造函数
    Pig(const Pig & pig);

    // 普通函数 set get
    int getAge();
    char * getName();
    void setAge(int);
    void setName(char *);

    void showPigInfo() const; // 常量指针常量 只读

    // 静态函数的声明
    static void changeTag(int age);

    // 不要这样干
    // void changeTag(int age);

    // 友元函数的声明
    friend void changeAge(Pig * pig, int age);
};

#endif // 关闭/结尾
