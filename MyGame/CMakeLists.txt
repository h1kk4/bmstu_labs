cmake_minimum_required(VERSION 3.7)
project(Slayin)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp TPlayer.h TMap.h TGameObj.h TEnemy.h DarkLord.h TBoss.h TEvil.h)
add_executable(Slayin ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Slayin ${SFML_LIBRARIES})
endif()