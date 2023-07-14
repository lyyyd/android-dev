

#include <iostream>
#include "T2.h"
using namespace std;

int main() {

    // if 条件判断
    // ifdef xxx 是否定义了xxx这个宏

#ifdef DEBUG // 是否定义了DEBUG这个宏
    cout << "在测试环境下，迭代功能" << endl;
    // 省略 500行 ...

#else RELEASE
    cout << "在正式环境下，功能上下中" << endl;
    // 省略 500行 ...

#endif // 结束IF

}

