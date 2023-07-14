// TODO  C++ 互斥锁 == Java版本（synchronize） 多线程操作的安全  持有内置锁
#include <iostream>
#include <pthread.h>
#include <queue>
#include <unistd.h> // sleep（秒）

using namespace std;

queue<int> queueData; // 定义一个全局的队列，用于 存储/获取

pthread_mutex_t mutex; // 定义一个互斥锁，注意：（Cygwin平台 此互斥锁，不能有野指针，坑）

// void *(*)(void *)
void * task(void * pVoid) {

    /*synchronize(锁) {
        // code
    }*/

    pthread_mutex_lock(&mutex); // 锁住

    cout << "异步线程-当前线程的标记是:" << *static_cast<int *>(pVoid) << "异步线程" << endl;

    if (!queueData.empty()) { // 有元素
        printf("异步线程-获取队列的数据:%d\n", queueData.front());
        queueData.pop(); // 把数据弹出去，删除的意思
    } else { // 没有元素
        printf("异步线程-队列中没有数据了\n");
    }

    // sleep(0.2);

    pthread_mutex_unlock(&mutex); // 解锁

    return 0;
}

int main()
{
    // 初始化 互斥锁
    pthread_mutex_init(&mutex, NULL);

    // 给队列 初始化数据 手动增加数据进去
    for (int i = 10001; i < 10011; ++i) {
        queueData.push(i);
    }

    // 一次性定义10个线程
    pthread_t pthreadIDArray[10];
    for (int i = 0; i < 10; ++i) {
        pthread_create(&pthreadIDArray[i], 0, task, &i);

        // 不能使用 join，如果使用（就变成顺序的方式，就没有多线程的意义了，所以不能写join）
        // pthread_join(pthreadIDArray[i], 0);
    }

    // main函数等 异步线程
    sleep(12);

    // 销毁 互斥锁
    pthread_mutex_destroy(&mutex);
    cout << "main函数即将弹栈..." << endl;

    // 每次运行 效果都不同：1，8，9，10，3，2，5，8
    // 每次运行 效果都是错乱

    return 0;
}