// 4.文件的复制。

#include <stdio.h>
#include <stdlib.h> // 文件的操作，是在这个头文件里面的
#include <string.h>

// 二进制文件来复制 rb rw
int main() {

    // https://en.cppreference.com/w/c/io

    char * fileNameStr = "D:\\Temp\\DerryFile.txt"; // 来源
    char * fileNameStrCopy = "D:\\Temp\\DerryFileCopy.txt"; // 目标

    // rb 读取二进制数据
    FILE * file = fopen(fileNameStr, "rb");

    // rw 写入二进制数据
    FILE * fileCopy = fopen(fileNameStrCopy, "wb");

    if (!file || !fileCopy) {
        printf("文件打开失败，请你个货检测：路径为%s路径的文件，看看有什么问题\n", fileNameStr);
        exit(0); // 退出程序
    }

    int buffer[514]; // 514 * 4 = 2048
    int len; // 每次读取的长度

    // fread：参数1：容器buffer， 参数2：每次偏移多少 int， 参数3：容器大小 写个2048，等下文件就报废了
    // sizeof(buffer) / sizeof(int) 等价与 514
    while ((len = fread(buffer, sizeof(int), 514 , file)) != 0) {
        fwrite(buffer, sizeof(int), len, fileCopy);
    }

    // 关闭文件
    fclose(file);
    fclose(fileCopy);

    return 0;
}
