cmake_minimum_required(VERSION 3.23)
project(LAB01)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 20)

add_executable(LAB01 main.cpp)

include_directories("${PROJECT_SOURCE_DIR}/src")


