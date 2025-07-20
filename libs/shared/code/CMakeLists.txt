cmake_minimum_required(VERSION 3.10.0)
project(APP)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(external::complex SHARED IMPORTED)
set_target_properties(external::complex PROPERTIES 
                                        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/build/libComplex.dylib"
                                        )
add_executable(APP main.cpp)
target_link_libraries(APP PRIVATE external::complex)