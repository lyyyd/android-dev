#include <stdio.h>

// 后续给大家画图(下次画图)
int mainT1() {

    // 数组
    int arrInt[] = {6,4,8,3,1,2,9,7,0,5};

    // *(arrInt+4))  数组的0元素 + 4   1的地址 *的值==1   TODO OK
    // arrInt + 前面  ：  数组的0元素 + 1

    int result = arrInt[*(arrInt+*(arrInt+4))];

    printf("result的值是多少呀:%d\n", result);

    return 0;

}

