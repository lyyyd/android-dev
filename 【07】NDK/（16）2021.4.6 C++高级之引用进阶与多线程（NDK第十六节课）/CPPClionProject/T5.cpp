// TODO 分离线程  非分离线程  理论知识

// C++ 服务器开发，线程是非常要去高
// C++ 分离线程 和 非分离线程 区别，应用场景？
/**
 * 答：分离线程： 各个线程都是自己运行自己的，老死不相往来，例如：main函数结束，全部结束，不会等待异步线程 【多线程情况下场景】
 *   非分离线程： 线程有协作的能力，例如：main函数线程会等待 异步线程执行完成后，我再执行 后面main函数的代码【协作，顺序执行 场景】
 */

#include <iostream>
#include <pthread.h> // Derry Cygwin 有 pthreads支持
#include <unistd.h>

using namespace std;

// void *(*)(void *)
void * runTask(void * pVoid) { // 异步线程  子线程
    int number = *static_cast<int *>(pVoid);
    cout << "异步线程执行了:" << number << endl;

    for (int i = 0; i < 10; ++i) {
        cout << "run:" << i << endl;
        sleep(1);
    }
    return 0;
}

int main() {
    int number = 999;

    pthread_t  pthreadID; // Cygwin允许有野指针
    pthread_create(&pthreadID, 0, runTask, &number);

    pthread_join(pthreadID, 0);

    cout << "main函数即将弹栈..." << endl;
    return 0;
}

