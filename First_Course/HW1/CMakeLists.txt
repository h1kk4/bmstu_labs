cmake_minimum_required(VERSION 3.7)
project(forward_list)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp TList.h)
add_executable(forward_list ${SOURCE_FILES})