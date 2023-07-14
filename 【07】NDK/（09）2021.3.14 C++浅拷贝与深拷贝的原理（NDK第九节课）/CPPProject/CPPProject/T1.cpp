#define _CRT_SECURE_NO_WARNINGS // strcpy运行会报错，支持

#include<iostream>
#include<string.h>
using namespace std;

class Student1
{
public:

	int age;
	char * name;

	Student1() { cout << "空参数构造函数" << endl; }

	Student1(char * name) :Student1(name, 99) { cout << "一个参数构造函数" << endl; }

    Student1(char * name, int age) { 
		cout << "二个参数构造函数" << endl;

		this->name = (char *) malloc(sizeof(char * ) * 10);
		strcpy(this->name, name);

		this->age = age;
	}

	~Student1() {
		cout << "析构函数执行" << endl;

		free(this->name);
		this->name = NULL;
	}

	// 默认有一个拷贝构造函数 隐士的 我们看不见
	// Student(const Student & stu) {
		// stu 旧地址

		// this 新地址

		// s2 = 新地址
	// }
};

void mainT1() {
	// ① 情况分析 画图了
	// Student s1;
	// Student s2;
	// cout << &s1 << endl;
	// cout << &s2 << endl;
	// 两个地址 完全不同
	// 打印：
	// 空参数构造函数
	// 空参数构造函数
	// 1000H
	// 2000H


	// ② 情况分析 
	Student1 s1;
	Student1 s2 = s1; 

	// 两个地址 完全不同
	// 打印：
	// 空参数构造函数
	// 1000H
	// 2000H

	cout << &s1 << endl;
	cout << &s2 << endl;

	getchar(); // 不要一闪而过，让程序停留
}