// 4.字符串转换，字符串的比较。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 快捷键：按两下 shift键  选择 file encoding

// 真正的C语言，在Linux上学，在VIM上才是专业的
int main() {
    // 字符串转换 =======================
    char * num = "1"; // 字符串
    num = "12.68";

    // 【int】
    int result =  atoi(num);
    if (result) { // 非0即ture  不是0进入if，  0就是转换失败了
        printf("恭喜你转换成功:%d\n", result);
    } else {
        printf("转换失败！\n");
    }

    // 【double】
    double resultD =  atof(num);
    printf("恭喜你转换成功:%lf\n", resultD);


    // 字符串的比较 ======================
    char * str1 = "Derry";
    char * str2 = "derry";

    // int resultC = strcmp(str1, str2); // strcmp = 区分大小写
    int resultC = strcmpi(str1, str2); // strcmpi = 不区分大小写

    if (!resultC) { // 0代表是相等的， 非0代表是不相等的
        printf("相等");
    } else {
        printf("不相等");
    }

    return 0;
}

