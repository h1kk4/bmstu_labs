cmake_minimum_required(VERSION 3.7)
include(cmake/HunterGate.cmake)

HunterGate(
        URL "https://github.com/h1kk4/hunter/archive/v0.19.137.1.tar.gz"
        SHA1 "8667deec901df1cade767c847ffacdbf26f2efd1"
)

project(lab13)

hunter_add_package(pugixml)
find_package(pugixml CONFIG REQUIRED)
set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES pack.cpp unpack.cpp)

add_executable(lab13 ${SOURCE_FILES})




target_link_libraries(lab13 pugixml)


