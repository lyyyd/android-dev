// TODO pthreads 我们必须掌握的内容 重头戏

// TODO pthreads 最简单的案例

#include <iostream>
#include <pthread.h> // Derry Cygwin 有 pthreads支持
using namespace std;

// void *(*)(void *)
void * customPthreadTask(void * pVoid) { // 异步线程  相当于Java的Thread.run函数一样
    // C++转换static_cast  转换指针操作的
    int * number = static_cast<int *>(pVoid); // pVoid==number int的地址，所以我用int*接收，很合理
    cout << "异步线程执行了:" << *number << endl;

    return 0; // 坑 坑 坑，必须返回，否则有错误，不好查询
}

int main() {
    int number = 9527;

    /**
      int pthread_create (pthread_t *,  // 参数一：线程ID
                        const pthread_attr_t *, // 参数二：线程属性
		                void *(*)(void *), // 参数三：函数指针的规则
		                void *); // 参数四：给函数指针传递的内容，void * 可以传递任何内容
     */
    pthread_t pthreadID; // 线程ID，每个线程都需要有的线程ID

    pthread_create(&pthreadID, 0, customPthreadTask, &number);

    return 0;
}

