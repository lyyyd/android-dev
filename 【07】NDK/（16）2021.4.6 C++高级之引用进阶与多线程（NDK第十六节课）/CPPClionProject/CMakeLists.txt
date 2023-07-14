cmake_minimum_required(VERSION 3.17)
project(CPPClionProject) # 目标库 CPPClionProject

set(CMAKE_CXX_STANDARD 14)

# TODO 第一步：引入头文件
include_directories("D:/jingtong_yunyon_chuangzhao_VIPALL_NDK/XiangXueNDKAllVIP/ndk16/data/pthreads-w32-2-9-1-release/Pre-built.2/include")

# TODO 第二步：引入库文件
link_directories("D:/jingtong_yunyon_chuangzhao_VIPALL_NDK/XiangXueNDKAllVIP/ndk16/data/pthreads-w32-2-9-1-release/Pre-built.2/lib/x86")

add_executable(CPPClionProject  T8.cpp)

# TODO 第三步：链接到目标库  必须增加：pthreadVC2
target_link_libraries(CPPClionProject pthreadVC2)

# TODO 第五步： struct timespec 有问题   手动修改 pthread的源码 定义 HAVE_STRUCT_TIMESPEC
# 不到万不得已，不能修改系统源码

# TODO 第五步 第二种方式 增加HAVE_STRUCT_TIMESPEC,  -D 代表是define的意思  在你原有的基础上 再增加一个宏HAVE_STRUCT_TIMESPEC
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DHAVE_STRUCT_TIMESPEC") # 定义预编译宏

