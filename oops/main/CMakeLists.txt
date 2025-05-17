cmake_minimum_required(VERSION 3.10.0)
project(HDF_Example)

# add hdf_root path for prebuilt binaries
set(HDF5_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../HDF5/1.14.6")
set(CMAKE_PREFIX_PATH "${HDF5_ROOT}")
# Find HDF5 package
find_package(HDF5 REQUIRED COMPONENTS C CXX)

add_executable(HDF_Example main.cpp)

target_include_directories(HDF_Example PRIVATE ${HDF5_INCLUDE_DIRS})
target_link_libraries(HDF_Example PRIVATE ${HDF5_LIBRARIES})
# cmake command to build
# cmake ..
# cmake command to run
# make