// 5.纯虚函数（Java版抽象类）
// C++纯虚函数(C++没有抽象类)  相当于 Java的抽象类  为了更好理解

#include <iostream>
using namespace std;

// 抽象类/纯虚函数： 分为：1.普通函数， 2.抽象函数/纯虚函数
class BaseActivity {
private:
    void setContentView(string layoutResID) {
        cout << "XmlResourceParser解析布局文件信息... 反射" << endl;
    }

public:
    // 1.普通函数
    void onCreate() {
        setContentView(getLayoutID());

        initView();
        initData();
        initListener();
    }

    // 纯虚函数是必须继承的（如果子类没有重写纯虚函数，子类就是抽象类）， 虚函数是不是不必须的

    // 2.抽象函数/纯虚函数
    // virtual string getLayoutID(); // 虚函数
    virtual string getLayoutID() = 0; // 纯虚函数
    virtual void initView() = 0;
    virtual void initData() = 0;
    virtual void initListener() = 0;
};

// 子类 MainActivity
class MainActivity : public BaseActivity { // MainActivity如果没有重新父类的纯虚函数，自己就相当于 抽象类了

    string getLayoutID() {
        return "R.layout.activity_main";
    }

    void initView()  {
        // Button btLogin = findViewById(R.id.bt_login);
        // Button btRegister = findViewById(R.id.bt_register);
        // TextView tvInfo = findViewById(R.id.tv_info);
        // ... 省略
    }

    void initData() {
        // tvInfo.setText("info...");
        // ... 省略
    }

    void initListener() {
        /*btLogin.setOnClickListener(new View.OnClickListener() {
                   @Override
                   public void onClick(View v) {
                       // 点击做事情
                   }
               });*/
        // ... 省略
    }
};

// 子类 HomeActivity
class HomeActivity : public BaseActivity { // MainActivity如果没有重新父类的纯虚函数，自己就相当于 抽象类了

    string getLayoutID() {
        return "R.layout.activity_home";
    }

    void initView()  {
        // Button btLogin = findViewById(R.id.bt_login);
        // Button btRegister = findViewById(R.id.bt_register);
        // TextView tvInfo = findViewById(R.id.tv_info);
        // ... 省略
    }

    void initData() {
        // tvInfo.setText("info...");
        // ... 省略
    }

    void initListener() {
        /*btLogin.setOnClickListener(new View.OnClickListener() {
                   @Override
                   public void onClick(View v) {
                       // 点击做事情
                   }
               });*/
        // ... 省略
    }
};

// 子类 LoginActivity
class LoginActivity : public BaseActivity { // MainActivity如果没有重新父类的纯虚函数，自己就相当于 抽象类了

    string getLayoutID() {
        return "R.layout.activity_login";
    }

    void initView()  {
        // Button btLogin = findViewById(R.id.bt_login);
        // Button btRegister = findViewById(R.id.bt_register);
        // TextView tvInfo = findViewById(R.id.tv_info);
        // ... 省略
    }

    void initData() {
        // tvInfo.setText("info...");
        // ... 省略
    }

    void initListener() {
        /*btLogin.setOnClickListener(new View.OnClickListener() {
                   @Override
                   public void onClick(View v) {
                       // 点击做事情
                   }
               });*/
        // ... 省略
    }
};

int main() {

    // 错误：抽象类型 MainActivity 绝对不能实例化
    // MainActivity mainActivity;

    // 重新了父类所有的纯虚函数
    MainActivity mainActivity;

    return 0;
}
