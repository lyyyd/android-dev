#include <stdio.h>

// 指针难度高一点
int mainT5() {

    int number_int = 100;
    double number_double = 200;
    printf("number_int的值是:%d\n", number_int);
    printf("number_double的值是:%lf\n", number_double);

    // * == 取出number_int地址所对应的值 == 100
    // 指针取出值
    // 既然任何变量都是地址，可以使用都在获取值（灵感）
    printf("number_int的值是:%d\n", *(&number_int));
    printf("number_double的值是:%lf\n", *(&number_double));


    //   ================   难度

    int * intP = &number_int;
    double * doubleP = &number_double;

    // 输出 100  和 200
    printf("number_int的值是:%d\n", *intP);
    printf("number_double的值是:%lf\n", *doubleP);

    // 概念
    /**
       同学们：如果你去上网查询，指针的文章，就会发现，一些专业术语，导致大学老师一直说不清楚，成功劝退很多学生放弃：
       内存地址变量，内存地址别名，指针，指针变量，指针别名，.... 一大段的专业术语 ...


       理解：  大道至简 （化繁为简）

       内存地址 == 指针
       指针 == 内存地址
        int *，  double *      (int类型的指针)

        指针别名，指针变量 == 就是一个变量而已，只不过 是指针的 变量 而已
        intP，  doubleP
     */

    return NULL;
}
