// TODO find find_if 算法包里面的 查找元素

#include <iostream>
#include <vector> // stl包
#include <algorithm> // 算法包
using namespace std;

// find 没有自定义仿函数
//int main() {
//    vector<int> vectorVar;
//    vectorVar.insert(vectorVar.begin(), 10000);
//    vectorVar.insert(vectorVar.begin(), 20000);
//    vectorVar.insert(vectorVar.begin(), 30000);
//    vectorVar.insert(vectorVar.begin(), 40000);
//
//    // find 没有自定义仿函数
//    auto iteratorVar = find(vectorVar.begin(), vectorVar.end(), 40000);
//    if (iteratorVar != vectorVar.end()) {
//        cout << "查找到了" << endl;
//    } else {
//        cout << "没有找到" << endl;
//    }
//    return 0;
//
//    /*
//    ...
//    find(_InputIterator __first,  开始位置 迭代器
//     _InputIterator __last, 结束位置 迭代器
//         const _Tp& __val) 需要查找的元素 40000
//    {
//        ....
//        结论：对__find_if的封装而已
//        return std::__find_if(__first, __last,
//                              __gnu_cxx::__ops::__iter_equals_val(__val));
//    }*/
//}


// find_if 有自定义仿函数
class __pred {
public:
    int number;
    __pred(int number) : number(number) {}
    bool operator() (const int value) {
        return number == value;
    }
};

int main() {
    vector<int> vectorVar;
    vectorVar.insert(vectorVar.begin(), 10000);
    vectorVar.insert(vectorVar.begin(), 20000);
    vectorVar.insert(vectorVar.begin(), 30000);
    vectorVar.insert(vectorVar.begin(), 40000);

    auto it = find_if(vectorVar.begin(), vectorVar.end(), __pred(30000));

    if (it != vectorVar.end()) {
        cout << "查找到了" << endl;
    } else {
        cout << "没有找到" << endl;
    }
    return 0;

    /*  知道怎么阅读算法包源码 1
    ...
    find_if(_InputIterator __first,  开始位置 迭代器
      _InputIterator __last, 结束位置 迭代器
	    _Predicate __pred)  自定义仿函数
    {
     ... 监测工作而已
      return std::__find_if(__first, __last,
			    __gnu_cxx::__ops::__pred_iter(__pred));
    }

    ...
    __find_if(_InputIterator __first, 开始位置 迭代器
           _InputIterator __last, 结束位置 迭代器
	      _Predicate __pred,   TODO 自定义仿函数
	      ....)
    {
      while (__first != __last && !__pred(__first)) //  __pred(__first)  自定义仿函数 怎么写  返回值bool 传入int类型
	++__first;  // 迭代器从开始位置挪动     算法思路： 指针++
      return __first;
    }
     */

}


