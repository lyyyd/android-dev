// 宏变量  真实开发中：宏都是大写

#include <iostream>
using namespace std;

#define VALUE_I 9527
#define VALUE_S "AAA"
#define VALUE_F 545.3f

int main() {
    int i = VALUE_I; // 预处理阶段 宏会直接完成文本替换工作，替换后的样子：int i = 9527;
    string s = VALUE_S; // 预处理阶段 宏会直接完成文本替换工作，替换后的样子：string s = "AAA";
    float f = VALUE_F; // 预处理阶段 宏会直接完成文本替换工作，替换后的样子：float f = 545.3f;

    return 0;
}

