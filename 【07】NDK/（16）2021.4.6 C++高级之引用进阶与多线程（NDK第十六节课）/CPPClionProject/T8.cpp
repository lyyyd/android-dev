// TODO #### 08-pthreads 手动依赖进来

#include <iostream> // windows平台 支持Windows
using namespace std;
#include <pthread.h> // minGW 默认是没有pthread的   TODO 第四步 导入 pthread 的头文件

void * run(void * pVoid) {
    for (int i = 0; i < 10; ++i) {
        cout << "异步线程执行了一次:" << i << endl;
    }
    return 0;
}

int main() {

    // JNI 去讲课 宏 预处理阶段的  先暂时这样理解：把宏理解常量

    // TODO 注意：必须是第五步完全没有任何问题了，才能用下面的代码，引出第六步

    // TODO 第六步 千辛万苦 很多坑 被我们折服了

    pthread_t pid; // 注意：pid可以允许存在野指针的行为，但是线程属性是绝对不允许的，线程属性必须初始化
    pthread_create(&pid, 0, run, 0);
    pthread_join(pid, 0);

    cout << "main函数即将弹栈..." << endl;
    return 0;
}
