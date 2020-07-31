# Set the CMake minimum version
cmake_minimum_required(VERSION 3.5)

#  point your compiler to build with C++14
set(CMAKE_CXX_STANDARD 14)

project(problem3)
project(problem4)
project(problem2)

add_executable(problem3 problem3.c)
add_executable(problem2 problem2.cpp)
add_executable(problem4 problem4.c)

# the program can be build and compiled through build directory

