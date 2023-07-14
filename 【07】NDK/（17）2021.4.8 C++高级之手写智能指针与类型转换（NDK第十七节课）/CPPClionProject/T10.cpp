// 3.四种类型转换。 reinterpret_cast 强制转换 比 static_cast要强大， static_cast能够做的事情，
// reinterpret_cast强制转换都可以，同时并且附加 新功能

#pragma once
#include <iostream>
#include <iostream>
#include <iostream>
#include <iostream>
#include <iostream>
#include <iostream>

using namespace std;

class DerryPlayer {
public:
    void show() {
        cout << "DerryPlayer" << endl;
    }
};

int main() {
    DerryPlayer * derryPlayer = new DerryPlayer();
    long playerValue = reinterpret_cast<long>(derryPlayer); // 把对象变成数值

    // 通过数值 变成对象
    DerryPlayer * derryPlayer2 = reinterpret_cast<DerryPlayer *>(playerValue);
    derryPlayer2->show();

    printf("derryPlayer:%p\n", derryPlayer);
    printf("derryPlayer2:%p\n", derryPlayer2);

    // 前面的只是：为什么不一样：因为指针存放地址，同时指针有自己的地址，而你打印了自己的的地址，能一样？
    printf("derryPlayer:%p\n", &derryPlayer);
    printf("derryPlayer2:%p\n", &derryPlayer2);

}