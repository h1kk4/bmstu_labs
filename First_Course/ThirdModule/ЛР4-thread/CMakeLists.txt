cmake_minimum_required(VERSION 3.7)
project(thread)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp InfInt.cpp InfInt.h)
add_executable(thread ${SOURCE_FILES})