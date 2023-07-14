// C++是有多继承的
// Java语言不允许多继承，多继承有歧义，如果Java语言多继承 就会导致代码不健壮，（二义性）
// Java多实现：做的非常棒，严格避免出现 二义性问题（歧义）

#include <iostream>

using namespace std;

class BaseActivity1 {
public:
    void onCreate() {
        cout << "BaseActivity1 onCreate" << endl;
    }

    void onStart() {
        cout << "BaseActivity1 onStart" << endl;
    }

    void show() {
        cout << "BaseActivity1 show" << endl;
    }
};

class BaseActivity2 {
public:
    void onCreate() {
        cout << "BaseActivity2 onCreate" << endl;
    }

    void onStart() {
        cout << "BaseActivity2 onStart" << endl;
    }

    void show() {
        cout << "BaseActivity2 show" << endl;
    }
};

class BaseActivity3 {
public:
    void onCreate() {
        cout << "BaseActivity3 onCreate" << endl;
    }

    void onStart() {
        cout << "BaseActivity3 onStart" << endl;
    }

    void show() {
        cout << "BaseActivity3 show" << endl;
    }
};

// 子类 继承 三个父类
class MainActivity1 : public BaseActivity1, public BaseActivity2, public BaseActivity3 {
public:
    void onCreate() {
        cout << "MainActivity1 onCreate" << endl;
    }

    void onStart() {
        cout << "MainActivity1 onStart" << endl;
    }

    void showSonInfo() {
        cout << "MainActivity1 showSonInfo" << endl;
    }

    // 解决方案二： 子类上 重写父类的show函数
    void show() {
        cout << "MainActivity1 show" << endl;
    }

};

int main() {
    // 这个是优先寻找子类的函数，因为特别明确，没有问题，还没有产生歧义（二义性）
    MainActivity1 mainActivity1; // 子类
    mainActivity1.onCreate();
    mainActivity1.onStart();
    mainActivity1.showSonInfo();

    // error: request for member 'show' is ambiguous
    // 不明确，二义性，歧义
    // mainActivity1.show();

    // 解决方案一： 明确指定父类 ::
    mainActivity1.BaseActivity3::show();
    mainActivity1.BaseActivity2::show();
    mainActivity1.BaseActivity1::show();

    // 解决方案二： 子类上 重写父类的show函数
    mainActivity1.show();

    return 0;
}

