// 友元类 的 小故事 （ImageView 私有成员  可以通过Class来访问，但是Class操作的native C++代码）
// 下载 JDK native代码 研究 【同学们自己去研究】

// ImageView 私有成员  你能访问它的私有成员吗 Class
#include <iostream>

using namespace std;

class ImageView {
private:
    int viewSize;
    friend class Class; // 友元类
};

// Java每个类，都会有一个Class，此Class可以操作 ImageView私有成员（感觉很神奇）
class Class {
public:
    ImageView imageView;

    void changeViewSize(int size) {
        imageView.viewSize = size;
    }

    int getViewSize() {
        return imageView.viewSize;
    }
};

int main() {
    Class mImageViewClass;

    mImageViewClass.changeViewSize(600);

    cout << mImageViewClass.getViewSize() << endl;

    return 0;
}

