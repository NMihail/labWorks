cmake_minimum_required(VERSION 3.23)
project(Vectors C)

set(CMAKE_C_STANDARD 23)

add_executable(Vectors main.c)

add_subdirectory(libs)
target_link_libraries(Vectors dataStructures)