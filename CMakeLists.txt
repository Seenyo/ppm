cmake_minimum_required(VERSION 3.22)
project(PPMreader)

set(CMAKE_CXX_STANDARD 14)

add_executable(PPMreader main.cpp)
target_link_libraries(PPMreader libopengl32.a libglu32.a libfreeglut.a)
