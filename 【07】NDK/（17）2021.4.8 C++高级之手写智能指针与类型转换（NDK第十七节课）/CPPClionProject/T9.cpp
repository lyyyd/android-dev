// 3.四种类型转换。 dynamic 字符类多态 运行期 转换

#include <iostream>
using namespace std;

class FuClass {
public:
    // 动态转换必须让父类成为虚函数
    virtual void show() {
        cout << "fu show" << endl;
    }
};

class ZiClass  : public FuClass {
public:
    void show() {
        cout << "zi show" << endl;
    }
};

int main() {
    // 动态类型转换的时候，在运行期 由于fuClass 是new 父类的，已成定局，就不能转换子类
    // FuClass * fuClass = new FuClass(); // 失败

    FuClass * fuClass = new ZiClass; // 已成定局 是子类
    ZiClass * ziClass = dynamic_cast<ZiClass *>(fuClass);

    // TODO 子类转父类不行的，同学们自己去试一试

    // 动态转换是有返回值， null 转换失败
    if (ziClass) { // ziClass != null
        cout << "恭喜，转换成功 " ;
        ziClass->show();
    } else {
        cout << "不恭喜 转换失败" << endl ;
    }



    return 0;
}

