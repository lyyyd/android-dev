#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Сд��

/// ������ջ ����һ��int arr[5];  ����һ�� int i;  (��̬�ķ���)

// malloc �ڶ������ٵ��ڴ�ռ� �� (��̬�ķ���)

// C�Ŀ��������У����ܳ��֣�Ұָ�룬����ָ��
void dynamicAction() {
    int * p; // Ұָ��  û�е�ַ�ģ��յ�

    // void * ��������ת��   int*  double *
    int * arr = malloc(1 * 1024 * 1024); // �������� 4M

    printf("dynamicAction������arr�Լ����ڴ��ַ:%p���������ٵ��ڴ��ַ:%p\n", &arr, arr);

    // C����ʦ���������ٵĿռ䣬�����ͷ�
    free(arr); // �ͷŵ�
    arr = NULL; // ����ָ��һ���ڴ��ַ00000

    printf("dynamicAction����2 �������ٵ��ڴ��ַ:%p\n", arr); // ����ָ��
}

int mainT1() {

    while (9) {
        // sleep(100);
        dynamicAction(); // ���ÿ���20
    }

    return 0;
}

