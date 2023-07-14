// TODO count count_if 算法包里面的 统计元素的个数

#include <iostream>
#include <vector> // stl包
#include <algorithm> // 算法包

using namespace std;

// count 没有自定义仿函数
int main() {
    vector<int> vectorVar;
    vectorVar.push_back(1);
    vectorVar.push_back(2);
    vectorVar.push_back(3);
    vectorVar.push_back(2);
    vectorVar.push_back(4);
    vectorVar.push_back(6);
    vectorVar.push_back(8);
    vectorVar.push_back(1);

    int number = count(vectorVar.begin(), vectorVar.end(), 2);
    cout << "等于2的个数是:" << number << endl;

    // C++ 源码 函数适配器
    number = count_if(vectorVar.begin(), vectorVar.end(), bind2nd(less<int>(), 2)); // 函数适配器 配合 less   <
    cout << "等于2的个数是:" << number << endl;

    number = count_if(vectorVar.begin(), vectorVar.end(), bind2nd(greater<int>(), 2)); // 函数适配器 配合 less >
    cout << "等于2的个数是:" << number << endl;

    number = count_if(vectorVar.begin(), vectorVar.end(), bind2nd(equal_to<int>(), 2)); // 函数适配器 配合 less =
    cout << "等于2的个数是:" << number << endl;

    return 0;

    // count_if 源码分析...
    /**
    ....
    count_if(_InputIterator __first,   迭代器 开始位置
      _InputIterator __last,  迭代器 结束位置
      _Predicate __pred) 自定义仿函数  __pred在源码里面可以知道 我们去写自定义仿函数的规则
    {
       .... 省略  监测工作而已
      return std::__count_if(__first, __last,
			     __gnu_cxx::__ops::__pred_iter(__pred));
    }

    ....
    __count_if(_InputIterator __first,
     _InputIterator __last,
     _Predicate __pred)
    {
      typename iterator_traits<_InputIterator>::difference_type __n = 0;  int __n
      for (; __first != __last; ++__first)  思路：迭代器 ++ 挪动位置
	    if (__pred(__first))  自定义仿函数  返回bool类型   ？？？ 迭代器类型
	    ++__n;
        return __n; // 最终 count_if 是返回int类型   __n  ++后的  统计元素的个数
        }
     */
}
