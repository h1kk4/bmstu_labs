cmake_minimum_required(VERSION 3.6)
project(Module2Sort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Module2Sort ${SOURCE_FILES})