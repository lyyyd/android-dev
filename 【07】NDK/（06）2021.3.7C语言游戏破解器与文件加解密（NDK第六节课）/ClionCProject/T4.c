// 3.文件的写。

#include <stdio.h>
#include <stdlib.h> // 文件的操作，是在这个头文件里面的
#include <string.h>

int main() {

    // fopen打开文件的意思（参数1：文件路径 文件源，  参数2：模式 r(读) w(写)  rb(作为二进制文件读) rw(作为二进制文件写)  返回值 FILE 结构体）
    // FILE * fopen (const char *, const char *);

    char * fileNameStr = "D:\\Temp\\DerryFileW.txt";

    // 既然是使用了w，他会自动生成文件 0kb
    FILE * file = fopen(fileNameStr, "w");

    if (!file) {
        printf("文件打开失败，请你个货检测：路径为%s路径的文件，看看有什么问题\n", fileNameStr);
        exit(0); // 退出程序
    }

    fputs("Derry Success run...", file);

    // 关闭文件
    fclose(file);

    return 0;
}

