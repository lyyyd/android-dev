// 常量引用。

#include <iostream>
#include <string.h>

using namespace std;

// 代码的统一性
typedef struct {
    char name[20];
    int age;
}Student;

// 常量引用：Student不准你改 == const Student &
// 插入数据库，Student的信息给插入数据库
void insertStudent(const Student & student) {
    // 内鬼 卧底
    // strcpy(student.name, "李元霸"); 不能这样修改

    Student student2 = {"刘奋", 43};
    // student = student2; 不能这样修改

    // 只读的了，可以安心插入数据库了
    cout << student.name << "," << student.age << endl;
}

int main() {

    // 用户提交的Student数据
    Student student = {"张无忌", 30};
    insertStudent(student);

    return 0;
}

