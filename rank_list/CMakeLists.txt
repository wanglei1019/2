cmake_minimum_required(VERSION 3.29.1)
project(xixi VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

#file(GLOB_RECURSE SOURCES "src/*.cpp")  # 自动从 src 目录读取所有 .cpp 文件
file(GLOB_RECURSE SOURCES "src/*.c")  # 自动从 src 目录读取所有 .c 文件
include_directories("lib")              # 设置头文件搜索路径为 lib 目录

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)


add_executable(xixi ${SOURCES})         # 将所有 .cpp 文件或者 .c 文件添加到可执行文件中

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
