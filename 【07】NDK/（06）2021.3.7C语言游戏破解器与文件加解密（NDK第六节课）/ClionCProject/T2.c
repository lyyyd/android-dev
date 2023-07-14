// 游戏作弊器

// C语言：地址的重要性

#include <stdio.h>
#include <windows.h>

int main() {
    printf("游戏倒计时开始了....\n");

    // Linux就不规范
    int i;
    for (i = 100; i > 0; i--) {
        printf("还剩下多少秒:%d, 内存地址是:%p\n", i, &i);
        Sleep(20000);
    }

    printf("恭喜，你已经赢得了游戏最高等级，碉堡了!\n");

    getchar(); // 停留

    // 最难的是地址的寻找，只要你能找到地址，就操作一切

    return 0;
}

