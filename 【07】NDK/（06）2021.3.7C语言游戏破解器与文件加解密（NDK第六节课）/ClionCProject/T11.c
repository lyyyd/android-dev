#include <stdio.h>

void substrAction3(char * result, char * str, int start, int end) {
    for (int i = start; i < end; ++i) {
        *(result++) = *(str + i);
    }
}

int main() {
    char * str = "Derry is";

    // char * result = "ABCDEFG"; (会报错，因为不准修改常量值)

    // char * result = NULL;  (会报错，因为不准修改NULL值)
    // VS不允许野指针（严格）

    // char * result; // 这就是不通过的 才对的  VS 不通过对的

    // 在你的栈区开辟空间[推荐方式]
    char result[100] = "ABC";

    substrAction3(result, str, 3, 5);
    printf("%s\n", result);


    // 这两个地方搞晕了，
   // char arry1[]={'1','2'}; // 不会自动增加\0
   // 一级指针，字符指针，数组
   char * arry = "21"; // 会自动增加\0
    // char arry[10] = "12";
    char arry3[10] = "12";

    return 0;
}

