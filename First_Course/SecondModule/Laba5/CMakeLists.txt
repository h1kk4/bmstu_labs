cmake_minimum_required(VERSION 3.6)
project(Module2Laba5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp TNotCopyable.h)
add_executable(Module2Laba5 ${SOURCE_FILES})