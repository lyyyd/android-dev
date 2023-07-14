// 2.结构体定义与使用。  第3种写法

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

struct Study {
    char * studyContent; // 学习的内容
};

struct Student {
    char name[10];
    int age;
    char sex;

    // Study study; // VS的写法
    struct Study study; // Clion工具的写法

    struct Wan {
        char * wanContent; // 玩的内容
    } wan;
};

int main() {

    struct Student student =
            {"李元霸", 88, 'm' ,
             {"学习C"},
             {"王者农药"}
             };

    printf("name:%s, age:%d, sex:%c，study:%s, wan:%s \n",
           student.name, student.age, student.sex, student.study.studyContent, student.wan.wanContent);


    return 0;
}