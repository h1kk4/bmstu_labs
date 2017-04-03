cmake_minimum_required(VERSION 3.6)
project(Module2Laba10)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp TArray.h)
add_executable(Module2Laba10 ${SOURCE_FILES})