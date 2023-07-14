// TODO 预处理器不是编译器，预处理器主要完成文本替换的操作（文本替换，以后专门在Linux中去讲），预处理器都是用 #xxx 的写法，并不是注释哦

/*
                                #include  导入头文件
                                #if       if判断操作  【if的范畴 必须endif】
                                #elif     else if
                                #else     else
                                #endif    结束if
          #define   定义一个宏
          #ifdef    如果定义了这个宏 【if的范畴 必须endif】
          #ifndef   如果没有定义这个宏 【if的范畴 必须endif】
          #undef    取消宏定义
          #pragma   设定编译器的状态
 */

#include <iostream>
using namespace std;

int main() {
    // std::cout << "宏" << std::endl;

#if 1 // if
    cout <<  "真" << endl;

#elif 0 // else if
    cout <<  "假" << endl;

#else
    cout << "都不满足" << endl;

#endif // 结束if
    cout << "结束if" << endl;

    return 0;
}
