cmake_minimum_required(VERSION 3.6)
project(Module2Laba3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp TInt.h)
add_executable(Module2Laba3 ${SOURCE_FILES})