cmake_minimum_required(VERSION 3.7)
project(FileStream)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp TFileStream.h)
add_executable(FileStream ${SOURCE_FILES})