#define _CRT_SECURE_NO_WARNINGS // strcpy运行会报错，支持

#include<iostream>
#include<string.h>
using namespace std;

class Student
{
public:

	int age;
	char * name;

	Student() { cout << "空参数构造函数" << endl; }

	Student(char * name) :Student(name, 99) {
		cout << "一个参数构造函数 this:" << (int)this << endl;
	}

	Student(char * name, int age) {
		cout << "二个参数构造函数 this:" << (int)this << endl;

		this->name = (char *)malloc(sizeof(char *)* 10);
		strcpy(this->name, name);

		this->age = age;
	}

	~Student() {
		cout << "析构函数执行 &this->name:" << (int)this->name << endl;

		free(this->name);
		this->name = NULL;
	}

	// 默认有一个拷贝构造函数 隐士的 我们看不见
	// 一旦复写了拷贝构造函数，默认的还在吗？ Java的构造函数一个思路
	// 自定义拷贝构造函数 如果有堆成员，必须采用深拷贝
	Student(const Student & stu) {
		// stu 旧地址

		// this 新地址

		// s2 = 新地址

		cout << "拷贝构造函数 &stu:" << (int)&stu << " this:" << (int)this << endl;

		// 【浅拷贝】：新地址name  旧地址name 指向同一个空间，会造成，重复free的问题，引发奔溃
		// 新地址name = 旧地址 （浅拷贝）
		// this->name = stu.name;

		// 【深拷贝】
		this->name = (char *)malloc(sizeof(char *)* 10);
		strcpy(this->name, name);

		this->age = stu.age;

		cout << "拷贝构造函数2 this->name:" << ((int) this->name) << "  stu.name:" << (int)stu.name << endl;

		// 深拷贝 后面见  原理全部打通的时候讲
	} // 此拷贝构造函数执行完 旧会出现一个 this==新地址  给 main函数的 stu


	// 默认的拷贝构造函数 是浅拷贝
};

void showStudent(Student stu) {
	cout << "showStudent函数：" << (int)&stu << "  " << stu.name << "," << stu.age<< endl;
}

void main() {
	Student stu("刘奋", 31);

	showStudent(stu); // 弹栈后 新地址name释放一遍
	// showStudent(stu); // 弹栈后 新地址name释放一遍
	// 两次释放新地址name 会奔溃

	// 释放一次新地址name  再释放一次旧name也报错

	showStudent(stu);


	showStudent(stu);


	showStudent(stu);


	showStudent(stu);

	getchar();
} // main函数弹栈 stu 旧地址


// 专业技能：1.研究过C++语言深拷贝原理