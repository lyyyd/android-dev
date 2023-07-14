// 系统源码都是这样写的

#include <stdio.h>
#include <stdlib.h>

struct DAO {
    char name[10];
    int age;
    char sex;
};

// 匿名结构体的别名（这样写意义不大，因为没有名字）
typedef struct {
    char name[10];
    int age;
    char sex;
};

// 源码是这样写的
// 给结构体AV 取了一个别名等于AV
typedef struct {
    char name[10];
    int age;
    char sex;
} AV;

// 取一个别名
typedef struct DAO DAO;

void show(DAO dao) {} // 在不同工具上 又的要加，又的不用加 又差异化

int main() {
    // VS 不需要这样写，   Clion工具 要加入关键字  代码不统一
    // struct DAO * dao  = malloc( sizeof(struct DAO));

    // 加别名后  代码的统一了

    // VS
    DAO * dao  = malloc( sizeof(DAO));

    // CLion工具也这样写
    DAO * dao1  = malloc( sizeof(DAO));

    // xxx 工具也这样写
    DAO * dao2  = malloc( sizeof(DAO));

    // 加别名后  代码的统一了
    // C库的源码，系统源码...，为什么 typedef 还取一个和结构体一样的名字（兼容代码的写法，保持一致）
    AV av = {"VideoInfo", 54, 'M'}; // 结构体  VS  Clion  xxx工具  兼容写法

    AV * avp = malloc(sizeof(AV)); // 结构体指针

    return 0;
}
