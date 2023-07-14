// 3.queue队列学习（必须会使用）。

#include <iostream>
#include <queue> // 队列支持（内部：基本上 链表 、 数组 ）

// 容器 + 数据结构

// 音视频： 压缩格式音频数据（push） 保存       pop消费最前面的 音频格式数据 获取

using namespace std;

int main() {
    queue<int> queueVar;

    queueVar.push(20);
    queueVar.push(40);
    queueVar.push(60);

    // 第一个元素是谁 20  FIFO 原则
    cout << " 修改前： queueVar.front():" << queueVar.front() << endl;
    queueVar.front() = 88;
    cout << " 修改后： queueVar.front():" << queueVar.front() << endl;

    // 最后一个
    cout << " 修改前： queueVar.back():" << queueVar.back() << endl;
    queueVar.back() = 88;
    cout << " 修改后： queueVar.back():" << queueVar.back() << endl;

    // 没有找到 角标
    /*for (int i = 0; i < 9; ++i) {
        queueVar[i];
    }*/

    // 他根本就没有迭代器
    /*for (queue<int>::iterator; i < ; ++i) {

    }*/

    // 慎用，为什么？ 前面的元素全部被消费完了
    while (!queueVar.empty()) {
        cout << "while1:" << queueVar.front() << endl;

        queueVar.pop(); // 把前面的元素 给消费掉  【删除】
    }

    while (!queueVar.empty()) {
        cout << "while2:" << queueVar.front() << endl;

        queueVar.pop(); // 把前面的元素 给消费掉  【删除】
    }

    return 0;
}
