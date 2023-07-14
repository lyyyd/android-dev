// 4.优先级队列学习 (queue 的 子集)。

#include <iostream>
#include <queue>
using namespace std;

// priority_queue 内部对我们前面的vector 有一定的封装

// Deque 跟 queue  有什么区别啊   双端队列

int main() {
    // 优先级队列，默认做了 从大大小 60 50 40 ...
    // priority_queue<int> priorityQueue;

    // 隐式代码： vector<int>, less<int>  你看不到
    // priority_queue<int, vector<int>, less<int>> priorityQueue;

    // less  // less<int> return __x < __y;  上一个元素和当前元素 比较，返回ture false  从大到小

    // less return __x < __y;  // 从大到小
    // greater return __x > __y; // 从小到大

    // 第二个参数：他内部需要vector，你就给他

    priority_queue<int ,vector<int>, less<int>> priorityQueue;
    // priority_queue<int ,vector<int>, greater<int>> priorityQueue;

    priorityQueue.push(10);
    priorityQueue.push(20);
    priorityQueue.push(30);
    priorityQueue.push(40);
    priorityQueue.push(50);
    priorityQueue.push(60);

    cout << priorityQueue.top() << endl; // 60

    // 循环代码
    while (!priorityQueue.empty()) {
        cout << "while1:" << priorityQueue.top() << endl; // 一直是60
        priorityQueue.pop(); // 最前面的元素消费掉
    }
    return 0;
}

