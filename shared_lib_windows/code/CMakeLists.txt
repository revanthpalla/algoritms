cmake_minimum_required(VERSION 3.20.0)
project(app VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find path of external lib
set(logger_lookup_dir ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
find_path(logger_include_dir NAMES logger.h 
                             PATHS ${logger_lookup_dir}/include/logger
                             )
find_library(logger_implib_library NAMES logger 
                            PATHS ${logger_lookup_dir}/lib
                            )
find_file(logger_dll NAMES logger.dll 
                     PATHS ${logger_lookup_dir}/bin
                     )

message(STATUS "logger_include_dir: ${logger_include_dir}")
message(STATUS "logger_implib_library: ${logger_library}/lib")
message(STATUS "logger_dll_library: ${logger_library}/bin")

# if search is successful then 
if(logger_include_dir AND logger_implib_library)
    message(STATUS "External logger lib: ${logger} is found in path: ${logger_lookup_dir}/bin")
else()
    message(FATAL_ERROR "External logger lib doesn't exist in path: ${logger_lookup_dir}/bin")
endif()

# create imported target as a library
add_library(External::logger SHARED IMPORTED)
set_target_properties(External::logger PROPERTIES 
                                       IMPORTED_LOCATION "${logger_dll}"
                                       IMPORTED_IMPLIB "${logger_implib_library}"
                                       INTERFACE_INCLUDE_DIRECTORIES "${logger_include_dir}")

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE External::logger)

# cmake -G "MinGW Makefiles" .. 
# mingw32-make.exe

