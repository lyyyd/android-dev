// 宏的取消 #undef 宏

#include <iostream>
using namespace std;

int main() {
    int i = 1

#ifndef DERRY // 如果没有定义这个宏
#define DERRY // 我就定义宏
#ifdef DERRY // 是否定义了这个宏
    for (int i = 0; i < 6; ++i) {
        cout << "Derry 1" << endl;
    }
    // 省略 500行 ...

#ifdef DERRY // 是否定义了这个宏
    for (int i = 0; i < 6; ++i) {
        cout << "Derry 2" << endl;
    }
    // 省略 500行 ...

#undef DERRY // 取消宏的定义，下面的代码，就没法用这个宏了，相当于：没有定义过DERRY宏

#ifdef DERRY
    cout << "你定义了Derry宏" << endl;
#else
    cout << "你没有定义了Derry宏" << endl;

#endif
#endif
#endif
#endif

    return 0;
}

