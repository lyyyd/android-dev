#include <stdio.h>

// ����C���Բ�֧�ֺ������أ����������ĺ���������Ҫд����

void changeAction();

int main() {
    int a = 100;
    int b = 200;

    changeAction(&a, &b);

    printf("������ɺ��Ч����%d,%d\n", a, b);

}

// ֻ����ָ��(�ڴ��ַ)    �ڴ��ַ == ָ��
void changeAction(int * a, int * b) {

    int temp = *a;

    *a = *b;

    *b = temp;
}

