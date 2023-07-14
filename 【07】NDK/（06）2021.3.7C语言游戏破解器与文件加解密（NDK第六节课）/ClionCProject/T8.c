// TODO 【文件的解密】

#include <stdio.h>
#include <stdlib.h> // 文件的操作，是在这个头文件里面的
#include <string.h>

int main() {

    char *fileNameStr = "D:\\Temp\\IMG_encode.jpg"; // 来源
    char *fileNameStrDecode = "D:\\Temp\\IMG_decode.jpg"; // 解密后的目标文件

    FILE * file = fopen(fileNameStr, "rb"); // r 必须字节提前准备好文件
    FILE * fileEncode = fopen(fileNameStrDecode, "wb"); // w 创建一个0kb的文件

    if (!file || !fileEncode) {
        printf("文件打开失败，请你个货检测：路径为%s路径的文件，看看有什么问题\n", fileNameStr);
        exit(0); // 退出程序
    }

    int c;
    while ((c = fgetc(file)) != EOF) {
        // 解密操作 1111 ^ 5 = 10；（还原）
        fputc(c ^ 5, fileEncode);
    }

    fclose(file);
    fclose(fileEncode);

    return 0;
}