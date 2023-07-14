// 命名空间

#include <iostream>

// 声明std，我们的main函数就可以直接使用里面的成员，不需要使用 std::
using namespace std; // C++自己的命名空间 (C# .net 命名空间)

// 自定义命名空间
namespace derry1 {
    int age = 33;
    char * name = "Derry猛男1";

    void show() {
        cout << "name:" << name << ", age:" << age << endl;
    }

    void action() {
        cout << "derry1 action" << endl;
    }
}

// TODO ------ 命名空间里面重复的函数
// 自定义命名空间
namespace derry2 {
    void action() {
        cout << "derry2 action" << endl;
    }
}

// TODO ------ 小概率会遇到的情况，命名空间的嵌套
// 自定义命名空间
namespace derry3 {
    namespace derry3Inner {
        namespace derry3Inner1 {
            namespace derry3Inner2 {
                namespace derry3Inner3 {
                    void out() {
                        cout << "爱恨情仇人消瘦，悲欢起落人寂寞" << endl;
                    }
                }
            }
        }
    }
}

// 声明各个写的 命名空间
// using namespace derry1;

int main() {
    cout << "命名空间" << endl;

    // 声明各个写的 命名空间
    using namespace derry1;

    int ageValue = derry1::age; // 方式1 使用 刚刚声明的命名空间
    derry1::show(); // 使用 刚刚声明的命名空间

    ageValue = age; // 方式2 直接去引出来 ::
    show(); // 直接去引出来 ::


    // TODO ------ 命名空间里面重复的函数
    using namespace derry2;
    // action(); 很尴尬
    derry1::action();
    derry2::action();

    // TODO ------ 小概率会遇到的情况，命名空间的嵌套

    // 第一种方式 先声明命名空间  再使用
    using namespace derry3::derry3Inner::derry3Inner1::derry3Inner2::derry3Inner3;
    // 再使用
    out();

    // 第二种方式 直接使用
    derry3::derry3Inner::derry3Inner1::derry3Inner2::derry3Inner3::out();

    return 0;
}

