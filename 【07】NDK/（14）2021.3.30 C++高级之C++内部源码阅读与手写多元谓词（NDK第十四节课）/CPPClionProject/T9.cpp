// 手写预定义函数
#include <iostream>
#include <set> // STL包
#include <algorithm> // 算法包
using namespace std;

template<typename Arg1, typename Arg2, typename Result>
struct binary_function
{
    /// 第一个参数类型 是底一个参数的类型
    typedef Arg1 	first_argument_type;

    //econd_argument_type是第二个参数的类型
    typedef Arg2 	second_argument_type;

    /// @c result_type是返回类型
    typedef Result 	result_type;
};

// TODO 对象 + 对象
// 1.运算符重载
// 2.对象+对象 自己去写仿函数

template<typename T>
struct plus_d /*: public binary_function<T, T, T>*/
{
    T operator() (const T & x, const T & y) {
        return x + y;
    }
};

int main() {

    plus_d<int> add_func;
    int r = add_func(1, 1);
    cout << r << endl;

    plus_d<string> add_func2;
    string r2 = add_func2("AAAA", "BBB");
    cout << r2 << endl;

    plus_d<float> add_func3;
    float r3 = add_func3(4354.45f, 34.3f);
    cout << r3 << endl;

    return 0;
}

