# **CMake Summary**
### CMake is an extensible, open-source system that manages the build process in an operating system and in a compiler-independent manner.
## Basic flow of Cmake
![](https://cgold.readthedocs.io/en/latest/_images/generate-native-files.png)
## The source and Binary Folders
![](https://preshing.com/images/cmake-concepts.png)
## The Configure and Generate Steps
![](https://preshing.com/images/cmake-simple-flowchart.png)
# CMake is a family of tools that can help you during all stages of sources for developers -> quality control -> installers for users stack.
![](https://cgold.readthedocs.io/en/latest/_images/cmake-environment.png)

## Example of CMakeLists.txt for **Building a Library with Target**
> cmake_minimum_required(VERSION 3.9.1)     
project(CMakeHello)     
set(CMAKE_CXX_STANDARD 14)       
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")     
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)      
add_executable(cmake_hello main.cpp lib/math/operations.cpp lib/math/operations.hpp)     

