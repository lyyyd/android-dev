// 静态多态 （编译期已经决定，调用哪个函数了，这个就属于静态多态的范畴）  重载（静态多态）

#include <iostream>

using namespace std;

void add(int number1, int number2) {
    cout << number1 + number2 << endl;
}

void add(float number1, float number2) {
    cout << number1 + number2 << endl;
}

void add(double number1, double number2) {
    cout << number1 + number2 << endl;
}

int main() {
    add(10000, 10000);
    add(1.9f, 2.8f);
    add(545.4, 654.54);

    return 0;
}
