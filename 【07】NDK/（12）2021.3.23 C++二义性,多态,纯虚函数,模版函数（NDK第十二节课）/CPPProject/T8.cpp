// 8.模版函数（Java版泛型）。  C++没有泛型 C++的模板函数 非常类似于 Java的泛型

#include <iostream>

using namespace std;

// 加分合集  int double float ... 你都要考虑，你是不是要定义很多的 函数
/*void addAction(int n1, int n2) {
    cout << "addAction(int n1, int n2):" << n1 + n1 << endl;
}

void addAction(float n1, float n2) {
    cout << "addAction(int n1, int n2):" << n1 + n1 << endl;
}

void addAction(double n1, double n2) {
    cout << "addAction(int n1, int n2):" << n1 + n1 << endl;
}*/

// 模板函数  == Java的泛型解决此问题
template <typename TT>
void addAction(TT n1, TT n2) {
    cout << "模板函数：" << n1 + n2 << endl;
}

int main() {
    addAction(1, 2);
    addAction(10.2f, 20.3f);
    addAction(545.34, 324.3);
    addAction<string>("AAA", "BBB");

    /*addAction(2, 324.3);
    addAction(54, 324.3f);*/
    return 0;
}
