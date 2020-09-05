cmake_minimum_required(VERSION 3.16)
project(demo)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/)

add_executable(demo demo.c)

target_link_libraries(demo Network_framework)