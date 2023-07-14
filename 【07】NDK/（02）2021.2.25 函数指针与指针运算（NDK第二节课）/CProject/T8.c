#include <stdio.h>

void add(int num1, int num2); // ������

void mins(int num1, int num2) {
    printf("num1 - num2 = %d\n", (num1 - num2));
}

// ���� �ص���  add  mins
// void(*method)(int,int)  ������ ����ָ��
// void ����ֵ
// (*method) ������
// (int,int) ��������
void opreate(void(*method)(int,int), int num1, int num2) {
    method(num1, num2);

    printf("opreate������ methodָ���Ƕ��٣�%p\n", method);
}

// 7.����ָ�롣���ص�)  Java�ӿڵĻص�
int mainT8() {  // ����һ��д����

    opreate(add,  10, 10);
    opreate(mins,  100, 10);

    // ԭ����ʲô��

    printf("main������ addָ���Ƕ��٣�%p\n", add);
    printf("main������ minsָ���Ƕ��٣�%p\n", mins);

    // &add��add��һ����ֵ��
    printf("%p, %p\n", add, &add); //  004018CE, 004018CE  һ����

    return 0;
}

// ��ʵ�� ʹ��
void add(int num1, int num2) {
    printf("num1 + num2 = %d\n", (num1 + num2));
}