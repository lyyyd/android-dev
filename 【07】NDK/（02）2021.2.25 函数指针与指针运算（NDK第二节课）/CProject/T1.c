#include <stdio.h>

void update(int * i) { // 1000H�ڴ��ַ
    // printf("update������i���ڴ��ַ��:%p\n", &i); // 2000H

    printf("update������i���ڴ��ַ��:%p\n", i); // 1000H

    * i = 999;
}

// �Ͻڿ�ͬѧ������һ�����⣨Ϊʲô main���� �� update ���� i ���ڴ治��ַһ������
int mainT1() {
    int i = 100; // 1000H���ڴ��ַ
    update(&i);

    printf("main������i���ڴ��ַ��:%p\n", &i);

    return 0;
}
