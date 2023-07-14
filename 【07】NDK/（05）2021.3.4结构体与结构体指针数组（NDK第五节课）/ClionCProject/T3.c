// 2.结构体定义与使用。  第一种写法

// Java/Kotlin是不是有类的概念，C语言  函数  结构体（相当于是Java的类）

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

struct Dog {
    // 成员
    char name[10]; // copy进去
    int age;
    char sex;

}; // 必须给写;

int main() {
    struct Dog dog; // 这样写完，成员是没有任何初始化的，成员默认值 是系统值(name:?@, age:3133440, sex:€)
    printf("name:%s, age:%d, sex:%c \n", dog.name, dog.age, dog.sex);

    // 赋值操作
    // dog.name = "旺财";
    strcpy(dog.name, "旺财");
    dog.age = 3;
    dog.sex = 'G';
    printf("name:%s, age:%d, sex:%c \n", dog.name, dog.age, dog.sex);



    return 0;
}