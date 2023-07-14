// TODO 【文件的加密】
// 文件加密 与 文件解密  二进制的方式来操作  .txt  .png  ...

#include <stdio.h>
#include <stdlib.h> // 文件的操作，是在这个头文件里面的
#include <string.h>

int main() {
    char * fileNameStr = "D:\\Temp\\IMG.jpg"; // 来源
    char * fileNameStrEncode = "D:\\Temp\\IMG_encode.jpg"; // 加密后的目标文件

    FILE * file = fopen(fileNameStr, "rb"); // r 必须字节提前准备好文件
    FILE * fileEncode = fopen(fileNameStrEncode, "wb"); // w 创建一个0kb的文件

    if (!file || !fileEncode) {
        printf("文件打开失败，请你个货检测：路径为%s路径的文件，看看有什么问题\n", fileNameStr);
        exit(0); // 退出程序
    }

    // 【加密 和 解密 的 思路】
    // 加密 == 破坏文件
    // 解密 == 还原文件 还原之前的样子

    // ---
    // 加密的想法：（全部）把每一个字节都拿出来，对每一个字节都全部处理， （部分加密：把某一部分内容拿出来处理）
    // TODO 加密的想法
    // while 循环遍历的时候  取出来的  10
    // 10 ^异惑 5   就变成这个效果1111

    /// TODO 解密的想法
    // while 循环遍历的时候  取出来的  1111
    // 1111 ^异惑 5  就变成这个效果10（还原）

    int c; // 接收读取的值

    // fgetc(文件指针)  返回值 EOF = end fo file
    while ((c = fgetc(file)) != EOF) {
        // 加密操作
        fputc(c ^ 5, fileEncode ); // 写入到 fileEncode  D:\Temp\IMG_encode.jpg（加密后的图片）
    }

    // 关闭文件
    fclose(file);
    fclose(fileEncode);

    return 0;
}
