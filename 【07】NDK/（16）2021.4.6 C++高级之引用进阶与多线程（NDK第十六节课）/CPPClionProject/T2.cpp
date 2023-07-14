// TODO C++ 11 后出现的 自带 Thread

#include <iostream>
#include <thread> // C++ 11 后出现的 自带 Thread  不是我们的重头戏，只是过一下
#include <unistd.h>

using namespace std;

// 异步线程 子线程
void runAction(int number) { // 相当于 Java的 run函数一样
    for (int i = 0; i < 10; ++i) {
        cout << "runAction：" << number << endl;
        sleep(1);
    }
}

// main函数的线程
int main() {
    // TODO 方式一  main只等3秒钟，各种玩各种的，老死不相往来
    /*thread thread1(runAction, 100);

    // sleep(3); // 我只等你三秒钟
    cout << "main弹栈了" << endl;*/

    // TODO 方式二  我等你执行完成后，我再执行
    thread thread2(runAction, 100);
    thread2.join(); // 我等runAction执行完成后，我再继续执行下面代码..
    cout << "main弹栈了" << endl;
    /*
    runAction：100
    runAction：100
    runAction：100
    runAction：100
    runAction：100
    runAction：100
    runAction：100
    runAction：100
    runAction：100
    runAction：100
    main弹栈了
     */

    return 0;
}

