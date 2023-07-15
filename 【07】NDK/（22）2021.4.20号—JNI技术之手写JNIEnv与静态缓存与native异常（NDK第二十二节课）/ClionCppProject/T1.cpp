// 简单说下 C++异常

#include <iostream>
#include <string>
using namespace std;

void exceptionMethod01() {
    throw "我报废了"; // const char *
}

class Student {
public:
    char * getInfo() {
        return "自定义";
    }
};

void exceptionMethod02() {
    Student student;
    throw student;
}

int main() {
    try {
        exceptionMethod01();
    } catch ( const char * & msg) {
        cout << "捕获到异常1：" << msg << endl;
    }

    try {
        exceptionMethod02();
    } catch (Student & msg) {
        cout << "捕获到异常2：" << msg.getInfo() << endl;
    }
    return 0;
}
