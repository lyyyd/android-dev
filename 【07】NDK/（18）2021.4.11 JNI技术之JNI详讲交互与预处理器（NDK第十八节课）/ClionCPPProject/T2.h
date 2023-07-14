#ifndef CLIONCPPPROJECT_T2_H // 如果没有定义这个宏  解决循环拷贝的问题
#define CLIONCPPPROJECT_T2_H // 我就定义这个宏

// 100 行代码
// 第一次能够进来
// 第二次  第n此进不来    直接 解决循环拷贝的问题了

// ---------------
#ifndef isRelease // 如果没有isRelease这个宏
#define isRelease 1 // 是否是正式环境下 【我就定义isRelease这个宏】

#if isRelease == true
#define RELEASE // 正式环境下 定义RELEASE宏

#elif isRelease == false
#define DEBUG // 测试环境下  定义DEBUG宏

#endif // 结束里面的if
#endif // 结束里面的if

#endif //CLIONCPPPROJECT_T2_H // 结束外面的if
