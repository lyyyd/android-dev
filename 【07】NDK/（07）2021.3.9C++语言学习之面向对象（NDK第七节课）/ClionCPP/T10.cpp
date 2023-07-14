// 5.C++面向对象。

#include "Student.h"

int main() {
    // 规范写法：要有 头文件.h .hpp   --   实现文件 .c  cpp

    std::cout << 1 << std::endl;


    // TODO  =======      下面是栈空间

    Student student1; // 栈区开辟空间的

    // 赋值
    student1.setAge(99);
    student1.setName("李连杰");

    cout << "name:" << student1.getName() << " ,age:" << student1.getAge() << endl;


    // TODO  =======      下面是堆空间

    Student * student2 = new Student(); // new/delete

    // 赋值
    student2->setAge(88);
    student2->setName("李元霸");

    cout << "name:" << student2->getName() << " ,age:" << student2->getAge() << endl;

    if (student2)
        delete student2; // 必须手动释放堆空间的对象student2
        student2 = NULL; // 指向NULL的地址区域
        // free(student2); // 不能这样写，不规范，会被鄙视的

    return 0;


    // 以后我们学习C++的时候，Derry可能没有写头文件，是不规范的，我只是为了讲课
    // 真实开发过程中，必须规范来：
    // 正规的流程：【xxx.so（C/Cpp的实现代码） 用户拿到xxx.so】， 头文件


} // main函数弹栈后，会释放栈成员 student1

