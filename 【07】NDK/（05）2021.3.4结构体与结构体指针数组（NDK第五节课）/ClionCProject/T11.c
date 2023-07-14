#include <stdio.h>

// 枚举 int 类型的
enum CommentType {
    TEXT = 10,
    TEXT_IMAGE,
    IMAGE
};

// 作业：处理好 差异化代码
int main() {
    // Clion工具的写法如下：
    enum CommentType commentType = TEXT;
    enum CommentType commentType1 = TEXT_IMAGE;
    enum CommentType commentType2 = IMAGE;

    // VS工具的写法如下：
    // CommentType commentType = TEXT;

    printf("%d, %d, %d \n", commentType, commentType1, commentType2);

    return 0;
}

