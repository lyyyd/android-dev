#include <iostream>

using namespace std; // std 是系统的，必须这样叫，  下节课讲 自定义命名空间

int main() {

    // bool  isOK = 1; // !0 就true
    // bool  isOK = -8891; // !0 就true
    // bool  isOK = 4359; // !0 就true
    bool  isOK = 0; // 0 就false

    // 只有两个类型： !0   0
    // 和前面的C一模一样

    if (isOK) {
        cout << "真" << endl;
    } else {
        cout << "假" << endl;
    }

    // ==========================
    bool isRun = true;
    isRun = false;
    cout << isRun << endl; // true==1,   false=0

    return 0;
}

