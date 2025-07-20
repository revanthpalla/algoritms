cmake_minimum_required(VERSION 3.10.0)
project(APP)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Complex::Complex STATIC IMPORTED)
set_target_properties(Complex::Complex PROPERTIES
                                       IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/../third_party_libs/libComplex.a"
                                       INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/../third_party_libs/inc"
                                       )

add_executable(APP main.cpp)
target_link_libraries(APP PRIVATE Complex::Complex)
