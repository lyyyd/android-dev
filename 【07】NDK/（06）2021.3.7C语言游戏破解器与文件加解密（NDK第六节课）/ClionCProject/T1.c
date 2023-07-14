// 上节课作业

#include <stdio.h>

// 枚举在创建的时候已经取别名了
typedef enum {
    AUDIO = 111,
    VIDEO,
    INFO
} AV;

int main() {
    printf("截拳道");

    // 以后写C代码的习惯，尽量加上别名，来保证代码的 统一
    AV av1 = AUDIO;
    AV av2 = VIDEO;
    AV av3 = INFO;
    printf("audio:%d, video:%d, info:%d,\n", av1, av2, av3);
    // 截拳道audio:111, video:112, info:113,

    return 0;
}

