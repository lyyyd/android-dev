#define _CRT_SECURE_NO_WARNINGS // strcpy运行会报错，支持

#include<iostream>
#include<string.h>
using namespace std;

class Student2
{
public:

	int age;
	char * name;

	Student2() { cout << "空参数构造函数" << endl; }

	Student2(char * name) :Student2(name, 99) {
		cout << "一个参数构造函数 this:" << this << endl;
	}

	Student2(char * name, int age) {
		cout << "二个参数构造函数 this:" << this << endl;

		this->name = (char *)malloc(sizeof(char *)* 10);
		strcpy(this->name, name);

		this->age = age;
	}

	~Student2() {
		cout << "析构函数执行 &this->name:" << &this->name << endl;

		free(this->name);
		this->name = NULL;
	}

	// 默认有一个拷贝构造函数 隐士的 我们看不见
	// 一旦复写了拷贝构造函数，默认的还在吗？ Java的构造函数一个思路
	Student2(const Student2 & stu) {
		// stu 旧地址

		// this 新地址

		// s2 = 新地址

		cout << "拷贝构造函数 &stu:" << &stu << " this:" << this << endl;


		// 新地址name = 旧地址 （浅拷贝）
		this->name = stu.name;


		// 深拷贝 后面见  原理全部打通的时候讲
	} // 此拷贝构造函数执行完 旧会出现一个 this==新地址  给 main函数的 stu
};

Student2 getStudent(char * name) {
	Student2 stu(name); // 旧地址

	cout << "getStudent函数:" << &stu << endl; // 旧地址

	return stu; // stu 旧地址
} // 弹栈 释放 栈成员 stu

void mainT3() {
	// = 会执行拷贝构造函数
	// stu 新地址
	Student2 stu = getStudent("截拳道");

	cout << "main函数:" << &stu << endl;

	// 打印：
	// 两个参数构造函数
	// 一个参数构造函数
	// getStudent函数: 1000H地址
	// 拷贝构造函数 构建新地址 把新地址 给 main函数的 stu == 新地址
	// 析构函数
	// main函数: 

	// getchar(); // 不要一闪而过，让程序停留
} // main函数弹栈 stu 新地址 析构函数执行

// 伏笔一： main函数弹栈 stu 新地址 析构函数执行 会造成 重复释放空间的问题   深拷贝
// 伏笔二 xx