// C++ 预定义函数（C++ 内置函数）

#include <iostream>
#include <set> // STL包
#include <algorithm> // 算法包
using namespace std;

int main() {
    // "Derry" + "AAAA" // 运算符重载

    // C++已经提供了 预定义函数  plus,minus,multiplies,divides,modulus ...
    plus<int> add_func;

    int r = add_func(1, 1);
    cout << r << endl;

    plus<string> add_func2;
    string r2 = add_func2("AAAA", "BBB");
    cout << r2 << endl;

    plus<float> add_func3;
    float r3 = add_func3(4354.45f, 34.3f);
    cout << r3 << endl;

    return 0;
}



