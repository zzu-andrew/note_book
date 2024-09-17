# Use at least CMake 3.3
cmake_minimum_required (VERSION 3.3.0)
cmake_policy(VERSION 3.2.2)
cmake_policy(SET CMP0054 NEW)

# Set up the project
project (node_books)

# 设置指定的C++编译器版本是必须的，如果不设置，或者为OFF，则指定版本不可用时，会使用上一版>本。
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 指定为C++11 版本
set(CMAKE_CXX_STANDARD 11)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

#option(ADVANCED_OPTION "An advanced option that should be hidden" OFF)
# 标记之后将不会在配置界面显示
#mark_as_advanced(ADVANCED_OPTION)
# 设置Google Test源码路径
set(GTEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest)
set(GTEST_SRC_DIR ${GTEST_DIR}/googletest)
set(GTEST_INCLUDE_DIR ${GTEST_SRC_DIR})

# 添加Google Test作为子目录
add_subdirectory(${GTEST_DIR})


#add_definitions("-pg -o0 -g")
add_definitions("-g")

include_directories(inc/include)


add_subdirectory(src)
#
#set(list1 A B)
#
#foreach(loopVar IN LISTS list1)
#    message(STATUS "Iteration for: ${loopVar}")
#endforeach()










