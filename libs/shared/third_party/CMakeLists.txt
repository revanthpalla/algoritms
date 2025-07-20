cmake_minimum_required(VERSION 3.10.0)
project(Complex VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Complex SHARED src/complex.cpp src/wrapper.cpp)
target_include_directories(Complex PRIVATE inc)

# build cmake ..
# run make