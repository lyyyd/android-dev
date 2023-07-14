// TODO merge 算法包里面的 对我们两个容器 合并成一个

#include <iostream>
#include <vector> // stl包
#include <algorithm> // 算法包

using namespace std;

int main() {
    vector<int> vectorVar1;
    vectorVar1.push_back(10);
    vectorVar1.push_back(20);
    vectorVar1.push_back(30);
    vectorVar1.push_back(40);

    vector<int> vectorVar2;
    vectorVar2.push_back(50);
    vectorVar2.push_back(60);
    vectorVar2.push_back(70);
    vectorVar2.push_back(80);

    // 合并成一个容器 result
    vector<int> vectorResult;
    vectorResult.resize(vectorVar1.size() + vectorVar2.size());

    merge(vectorVar1.begin(), vectorVar1.end(), vectorVar2.begin(), vectorVar2.end(), vectorResult.begin());
    for (auto itVar = vectorResult.begin(); itVar != vectorResult.end() ; itVar++) {
        cout << *itVar <<endl;
    }

    return 0;

    /**

    ...
    merge(_InputIterator1 __first1, _InputIterator1 __last1,  第一个容器 位置
	  _InputIterator2 __first2, _InputIterator2 __last2,  第二个容器 位置
	  _OutputIterator __result) 最终合并后的结果
    {
      .... 监测工作而已
      return _GLIBCXX_STD_A::__merge(__first1, __last1,
				     __first2, __last2, __result,
				     __gnu_cxx::__ops::__iter_less_iter());
    }

    template<typename _InputIterator1, typename _InputIterator2,
	   typename _OutputIterator, typename _Compare>
    _GLIBCXX20_CONSTEXPR
    _OutputIterator
    __merge(_InputIterator1 __first1, _InputIterator1 __last1, 第一个容器 位置
	    _InputIterator2 __first2, _InputIterator2 __last2, 第二个容器 位置
	    _OutputIterator __result, 最终合并后的结果
       _Compare __comp)
    {
      while (__first1 != __last1 && __first2 != __last2)
	{

      做 合并 算法处理工作
	  if (__comp(__first2, __first1))
	    {
	      *__result = *__first2;
	      ++__first2;
	    }
	  else
	    {
	      *__result = *__first1;
	      ++__first1;
	    }
	  ++__result;
	}

      这个可以放弃 【不追逐了】
      return std::copy(__first2, __last2,
		       std::copy(__first1, __last1, __result));
    }

     */
}

