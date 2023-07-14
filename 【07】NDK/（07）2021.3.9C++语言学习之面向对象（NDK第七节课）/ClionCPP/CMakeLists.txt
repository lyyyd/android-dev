cmake_minimum_required(VERSION 3.17)
project(ClionCPP)

set(CMAKE_CXX_STANDARD 14) # https://zhuanlan.zhihu.com/p/27551890 同学们自己去查询下

# 敲黑板 重要事情说三遍 重要事情说三遍 重要事情说三遍
# 编译一个.exe执行程序，你没有把实现文件给导入进去  Student.cpp
# 所有的头文件都依赖的好好的，检查代码一周，没有任何问题，运行就奔溃（没有导入实现：xxx.so ==  Student.cpp）
add_executable(ClionCPP Student.h Student.cpp T10.cpp)

# NDK自学为什么学不会？   NDK就是踩坑记（以后所有的坑 敲黑板 重要事情说三遍）

# NDK 你不要去 抢C中间件人家的饭碗，我们的业余 攻击 人家的专业

# .a静态库    .so库     Android对Linux系统内部的包装  Linux的动态库 就是 .so库


# 基础：NDK  C语言，C++语言，JNI操作，mk, Camke, Linux系统学习，Linux Shell
# 小应用实战：身份证识别，QQ语言变声，Gif实战，..... 省略
# 大项目实战：FFmpeg音视频播放器，OpenCv图像领域，Openx， WbeRTC ... 省略
# 有大部分同学，陷入误区，我只要把C++精通，我NDK就牛逼
# NDK本身的东西 很大的工具集  NDK（C/C++）      SDK(Java)

# Derry NDK顺利，不会放弃，因为都听的懂