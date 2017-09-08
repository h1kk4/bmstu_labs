cmake_minimum_required(VERSION 3.6)
project(MyZoo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp TAnimal.cpp TAnimal.h TZoo.cpp TZoo.h TArtiodactyla.cpp TArtiodactyla.h TGiraffa.cpp TGiraffa.h All.h TCarnivora.cpp TCarnivora.h TElephas.cpp TElephas.h THippopotamus.cpp THippopotamus.h TLoxodonta.cpp TLoxodonta.h TProboscidea.cpp TProboscidea.h TLeo.cpp TLeo.h TTigris.cpp TTigris.h TYU.cpp)
add_executable(MyZoo ${SOURCE_FILES})