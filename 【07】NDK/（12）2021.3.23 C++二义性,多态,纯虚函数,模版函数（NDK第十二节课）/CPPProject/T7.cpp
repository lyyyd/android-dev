// 7.回调。  Java的登录 简单的 接口

#include <iostream>
using namespace std;

// 登录成功的Bean
class SuccessBean {
public:
    string username;
    string userpwd;

    SuccessBean(string username, string userpwd)
    :username(username), userpwd(userpwd) {}
};

// 登录响应的接口  成功，错误
class ILoginResponse {
public:
    // 登录成功
    virtual void loginSuccess(int code, string message, SuccessBean successBean) = 0;

    // 登录失败
    virtual void loginError(int code, string message) = 0;
};

// 登录的API动作
void loginAction(string name, string pwd, ILoginResponse & loginResponse) {
    if (name.empty() || pwd.empty()) {
        cout << "用户名或密码为空!" << endl;
        return;
    }

    if ("Derry" == name && "123" == pwd) {
        loginResponse.loginSuccess(200, "登录成功", SuccessBean(name, "恭喜你进入"));
    } else {
        loginResponse.loginError(404, "登录错误，用户名或密码错误...");
    }
}

// 写一个实现类，继承接口
// 接口实现类
class ILoginResponseImpl : public ILoginResponse {
public:
    // 登录成功
    void loginSuccess(int code, string message, SuccessBean successBean) {
        cout << "恭喜登录成功 " << "code:" << code << " message:" << message
        << "successBean:" << successBean.username << "," << successBean.userpwd << endl;
    }

    // 登录失败
    void loginError(int code, string message) {
        cout << " 登录失败 " << "code:" << code << " message:" << message << endl;
    }
};

int main() {

    // 做实验
    // Allocating an object of abstract class type 'ILoginResponse'
    // 正在分配抽象类型为ILoginResponse的对象  不能被实例化
    // 纠结：为什么不可以
    // 1.他不是Java的接口，C++也没有接口，他只是像接口而已。
    // 2.他也不是抽象类，C++也没有抽象类，他只是像抽象类而已。
    // 3.他是纯虚函数的类，此类决定不准你实例化  无论堆区 还是栈区
    /*new ILoginResponse() {
        // 登录成功
        void loginSuccess(int code, string message, SuccessBean successBean) {

        }

        // 登录失败
        void loginError(int code, string message) {

        }
    }*/

    string username;
    cout << "请输入用户名.." << endl;
    cin >> username;

    string userpwd;
    cout << "请输入密码.." << endl;
    cin >> userpwd;

    ILoginResponseImpl iLoginResponse;
    loginAction(username, userpwd, iLoginResponse);

    return 0;
}

