// 2.结构体定义与使用。  第2种写法

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

struct Person {
    // 成员
    char * name; // 字符指针 = "赋值"
    int age;
    char sex;
} ppp = {"Derry", 33, 'M'},
ppp2,
ppp3,
pppp4,
pppp5
// ...
;

int main() {

    // Person == ppp == struct Person ppp;
    printf("name:%s, age:%d, sex:%c \n", ppp.name, ppp.age, ppp.sex);

    // 赋值
    // strcpy(pppp5.name, "Derry5"); // Copy不进去
    pppp5.name = "DerryO";
    pppp5.age = 4;
    pppp5.sex = 'M';

    printf("name:%s, age:%d, sex:%c \n", pppp5.name, pppp5.age, pppp5.sex);


    return 0;
}