// 生产者 消费者 工具类   播放器 有用

#ifndef CPPCLIONPROJECT_SAFE_QUEUE_TOO_H
#define CPPCLIONPROJECT_SAFE_QUEUE_TOO_H

#endif //CPPCLIONPROJECT_SAFE_QUEUE_TOO_H

#pragma once // 防止重复写 include 的控制

#include <iostream>
#include <string>
#include <pthread.h>
#include <string>
#include <queue>

using namespace std;

// 定义模版函数 int double float == Java的泛型
template<typename T>

class SafeQueueClass {
private:
    queue<T> queue; // 定义队列
    pthread_mutex_t  mutex; // 定义互斥锁（不允许有野指针）
    pthread_cond_t cond; // 条件变量，为了实现 等待 读取 等功能 （不允许有野指针）

public:
    SafeQueueClass() {
        // 初始化 互斥锁
        pthread_mutex_init(&mutex, 0);

        // 初始化 条件变量
        pthread_cond_init(&cond, 0);
    }
    ~SafeQueueClass() {
        // 回收 互斥锁
        pthread_mutex_destroy(&mutex);

        // 回收 条件变量
        pthread_cond_destroy(&cond);
    }

    // TODO 加入到队列中（进行生成）
    void add(T t) {
        // 为了安全 加锁
        pthread_mutex_lock(&mutex);

        queue.push(t); // 把数据加入到队列中

        // 告诉消费者，我已经生产好了
        // pthread_cond_signal(&cond) // Java notify 单个的
        pthread_cond_broadcast(&cond); // Java notifyAll 所有的的

        cout << "add queue.push 我已经notifyAll所有等待线程了" << endl;

        // 解锁
        pthread_mutex_unlock(&mutex);
    }

    // TODO 从队列中获取（进行消费） 外面的人消费 你可以直接返回，你也可以采用引用
    void get(T & t) {
        // 为了安全 加锁
        pthread_mutex_lock(&mutex);

        while (queue.empty()) {
            cout << "get empty 我已经乖乖等待中.." << endl;
            pthread_cond_wait(&cond, &mutex); // 相当于 Java的 wait 等待了[有可能被系统唤醒]
        }

        // 证明被唤醒了
        t = queue.front(); // 得到 队列中的元素数据 仅此而已
        queue.pop(); // 删除元素

        // 解锁
        pthread_mutex_unlock(&mutex);
    }
};
