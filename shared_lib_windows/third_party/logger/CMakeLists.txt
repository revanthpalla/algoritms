# create shared lib
cmake_minimum_required(VERSION 3.20.0)
project(logger VERSION 1.0) 

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(logger SHARED src/logger.cpp)
target_include_directories(logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_definitions(logger PRIVATE BUILDING_LOGGER)

# installation rules acts as a good practice
include(GNUInstallDirs)
if(TARGET logger)
    message(STATUS "Target: logger exists")
else()
    message(FATAL_ERROR "Target: logger is not found")
endif()
install(TARGETS logger
        EXPORT logger_target
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # .dll or .so
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # .lib (win)
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} # .a (linux)
        )
install(FILES include/logger.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/logger
        )

# build command 
# cmake -G "MinGW Makefiles" ..
# cmake --build . --config Release
# install command
# cmake --install . --config Release --prefix  "C:/code/shared_lib/third_party/logger/lib"
# run it 
# mingw32-make.exe
