cmake_minimum_required(VERSION 3.15.0)
project(static_lib_example VERSION 1.0) # vanilla version

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(EXTERNAL::Logger STATIC IMPORTED)
if(WIN32)
    # on windows look for logger.lib
    set_target_properties(EXTERNAL::Logger PROPERTIES 
        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/libs/external_libs/logger.lib"
        )
else()
    # on linux or mac
    set_target_properties(EXTERNAL::Logger PROPERTIES 
        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/libs/external_libs/liblogger.a"
        )
endif()

set_target_properties(EXTERNAL::Logger PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/libs/include"
)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE EXTERNAL::Logger)