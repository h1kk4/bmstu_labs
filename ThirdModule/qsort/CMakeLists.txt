cmake_minimum_required(VERSION 3.7)
project(qsort)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp THeader.h)
add_executable(qsort ${SOURCE_FILES})