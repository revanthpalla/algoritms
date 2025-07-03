cmake_minimum_required(VERSION 3.15.0)
project(app)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find our installed library.
# REQUIRED means CMake will error out if it can't be found.
# The VERSION check is optional but good practice.
find_package(logger 1.0 REQUIRED)

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE LOGGER::logger)

# cmake .. -DCMAKE_PREFIX_PATH=../lib
# cmake --build .

# for linux run
# LD_LIBRARY_PATH=../../lib/lib ./app

# for macOs run
# DYLD_LIBRARY_PATH=./../lib/lib ./app