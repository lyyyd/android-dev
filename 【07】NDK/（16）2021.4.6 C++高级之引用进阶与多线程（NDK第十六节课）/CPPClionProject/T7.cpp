// TODO C++ 条件变量+互斥锁 == Java版本的（notify 与 wait 操作）

#pragma once

#include <iostream>

#include "safe_queue_too.h"
using namespace std;
SafeQueueClass<int> sq;

// TODO 模拟演示 消费者
void * getMethod(void *) {
    while (true) {
        printf("getMethod\n");

        int  value;
        sq.get(value);
        printf("消费者get 得到的数据:%d\n", value);

        // 你只要传入 -1 就结束当前循环
        if (-1 == value) {
            printf("消费者get 全部执行完毕\n");
            break;
        }
    }
    return 0;
}

// TODO 模拟演示 生产者
void * setMethod(void *) {
    while (true) {
        printf("setMethod\n");

        int value;
        printf("请输入你要生成的信息:\n");
        cin >> value;

        // 你只要传入 -1 就结束当前循环
        if (-1 == value) {
            sq.add(value); // 为了让消费者 可以结束循环
            printf("消费者get 全部执行完毕\n");
            break;
        }

        sq.add(value);
    }
    return 0;
}

int main() {
    pthread_t pthreadGet;
    pthread_create(&pthreadGet, 0, getMethod, 0);
    // pthread_join(pthreadGet, 0); 不能这样写，否则，下面的代码，可能无法有机会执行

    pthread_t pthreadSet;
    pthread_create(&pthreadSet, 0, setMethod, 0);


    pthread_join(pthreadGet, 0);

    pthread_join(pthreadSet, 0);


    return 0;
}
