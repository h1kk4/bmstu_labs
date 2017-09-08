cmake_minimum_required(VERSION 3.6)
project(Module2Laba4_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES main.cpp TVector.h)
add_executable(Module2Laba4_1 ${SOURCE_FILES})