cmake_minimum_required(VERSION 3.15.0)
project(logger VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(logger SHARED src/logger.cpp)

# enable macro for windows
if(WIN32)
    target_compile_definitions(logger PRIVATE BUILD_LOGGER)
endif()

# installing binaries under particular so that project becomes modular and clean
include(GNUInstallDirs)
target_include_directories(logger PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/logger/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# New installation Rules acts as a good practice
install(TARGETS logger
        EXPORT logger_targets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # for .so , .dylib
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} # for .lib (static part of dll)
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # for .dll (windows)
        )
# Install public header destination
install(DIRECTORY logger/include DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

#    Generate and install the CMake configuration files.
#    This is what allows `find_package(loggerlib)` to work.
include(CMakePackageConfigHelpers)

# Generate loggerlibConfigVersion.cmake (handles version checking)
# PROJECT_NAME comes from the top-level CMakeLists.txt
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/loggerConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# Generate loggerlibConfig.cmake
# This file will include our exported targets file.
configure_package_config_file(
    "cmake/loggerConfig.cmake.in" # This is a template file we will create
    "${CMAKE_CURRENT_BINARY_DIR}/loggerConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/loggerlib
    PATH_VARS CMAKE_INSTALL_INCLUDEDIR CMAKE_INSTALL_LIBDIR
)

# Install the generated config files and the exported targets file.
install(EXPORT logger_targets
    FILE logger_targets.cmake
    NAMESPACE LOGGER::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/loggerlib
)

# Second, install the two config files we generated
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/loggerConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/loggerConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/loggerlib
)

# command to build
# cmake .. -DCMAKE_INSTALL_PREFIX=../install
# cmake --build .
# install project
# cmake --install .
# command to run
# make