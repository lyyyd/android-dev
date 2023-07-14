#include <iostream>
using namespace std;

void show(int * i) {
    cout << " show(int * i) " << endl;
}

void show(int  i) {
    cout << " show(int  i) " << endl;
}

int main() {
    show(9);

    show(nullptr); // C++11 后的特性： 原本本意代替NULL，除了代替NULL，还有此功能

    return 0;
}
