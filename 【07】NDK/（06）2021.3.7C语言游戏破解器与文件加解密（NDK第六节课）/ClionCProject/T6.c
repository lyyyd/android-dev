// 文件大小的获取

#include <stdio.h>
#include <stdlib.h> // 文件的操作，是在这个头文件里面的
#include <string.h>

int main() {

    // 没有专门的 文件大小获取 API，
    // （思路：）读取头指针 头指针挪动位置，挪动到最后，就可以求得文件大小

    char * fileNameStr = "D:\\Temp\\DerryFile.txt"; // 来源

    // 既然是使用了w，他会自动生成文件 0kb
    FILE * file = fopen(fileNameStr, "rb"); // file == 指针

    if (!file) {
        printf("文件打开失败，请你个货检测：路径为%s路径的文件，看看有什么问题\n", fileNameStr);
        exit(0); // 退出程序
    }

    // 都是操作指针来玩的

    // SEEK_SET（开头）  SEEK_CUR（当前）  SEEK_END（结尾）
    fseek(file, 0, SEEK_END);
    // 走到这里之后：file有了更丰富的值，给你的file指针赋值，挪动的记录信息

    // 读取   刚刚给file赋值的记录信息
    // 其实此函数目的是：计算偏移的位置,ftell 从 0 开始统计到当前（SEEK_END）
    long file_size = ftell(file);
    printf("%s文件的字节大小是:%ld\n", fileNameStr, file_size);
    // 8 字节 (8 字节)

    // 关闭文件
    fclose(file);

    return 0;
}

