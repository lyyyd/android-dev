#include <stdio.h>
#include <stdlib.h>

// 动态开辟之realloc
int mainT0() {

    int num;
    printf("请输入个数");
    // 获取用户输入的值
    scanf("%d", &num);

    // 5个值
    int * arr = (int *) malloc(sizeof(int) * num);
    for (int i = 0; i < num; ++i) {
        arr[i] = (i + 10001); // arr[i]的内部隐士 == *(arr+i)
    }
    printf("开辟的内存指针: %p\n", arr);

    // 打印 内容
    for (int i = 0; i < num; ++i) {
        // Derry装B的打印
        // &取出内存地址 *然后去值
        // &取出内存地址 *然后去值
        // &取出内存地址 *然后去值
        // .....
        printf("元素的值:%d, 元素的地址:%p\n",
               *&*&*&*&*&*&*&*&
                       *&*&*&*&*&*&*&*&*&
                               *&*&*&*&*&*&*&*&
                                       *&*&*&*&*&*&*&*&
                                               *&*&*&*&*&*&*&*&
                                                       *&*&*&*&
                                                               *&*(arr + i)
                ,
               (arr + i)
        );
    }




    // =================================   在堆区开辟新的空间  加长空间大小

    // C的岗位
    // C工程师的面试题：  realloc 为什么一定要传入 arr指针，为什么要传总大小

    // 新增
    int new_num;
    printf("请输入新增加的个数");
    scanf("%d", &new_num);

    // 原来的大小4 + 新增加的大小4  =  总大小 8
    // void *realloc (void *前面开辟的指针, size_t总大小);
    int * new_arr = (int *) realloc(arr, sizeof(int) * (num + new_num));

    if (new_arr) { // new_arr != NULL 我才进if  【非0即true】
        int j = num; // 4开始
        for (; j < (num + new_num); j++) { // 5 6 7 8
            arr[j] = (j + 10001);
        }

        printf("新 开辟的内存指针: %p\n", new_arr);

        // 后 打印 内容
        for (int i = 0; i < (num + new_num); ++i) {

            printf("新 元素的值:%d, 元素的地址:%p\n",
                   *(arr + i),
                   (arr + i)
            );
        }
    }

    // 我已经释放
    /*free(new_arr);
    new_arr = NULL;*/

    // 1000行代码
    // 。。。

    //  重复释放/重复free VS会奔溃，   CLion会优化(发现不奔溃)   [错误的写法]
    /*free(new_arr);
    new_arr = NULL;*/

    // 必须释放【规则】
    /*if (arr) {
        free(arr);   // 如果不赋值给NULL，就是悬空指针了
        arr = NULL;
    }*/

    /*if (new_arr) {
        free(new_arr);   // 如果不赋值给NULL，就是悬空指针了
        new_arr = NULL;
    }*/


    // TODO ========================== 下面代码对我们上节课 遗留点 完成  末尾工作了
    if (new_arr) { // new_arr != NULL 进去if， 重新开辟的堆空间是成功的
        free(new_arr);
        new_arr = NULL;
        arr = NULL; // 他还在指向那块空间，为了不出现悬空指针，指向NULL的空间
    } else { // 重新开辟的堆空间是失败的
        free(arr);
        arr = NULL;
    }
    // 画图：内存的走向  1


    return 0;
}
