// TODO pthread 的 三种情况分析 的
//  第一种情况，main函数只要结束，不等异步线程，全部技术
//  第二种情况，我们开发者，千万不要让 main函数睡眠的方式，去等待异步线程
//  第三种情况，main函数一直等待 异步线程，只有异步线程执行完成后，我在执行 join后面的代码
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

    pthread_t  pthreadID;
    pthread_create(&pthreadID, 0, runTask, &number);

    // 为了演示第二种情况
    // sleep(3); // main函数只 异步线程三秒钟

    // 异步线程在执行的过程中，我们的main函数 相当于 阻塞在这里不动了，只有异步线程执行完成后，我才开始执行join后面的代码
    pthread_join(pthreadID, 0);

    cout << "main函数即将弹栈..." << endl;
    return 0;
}
