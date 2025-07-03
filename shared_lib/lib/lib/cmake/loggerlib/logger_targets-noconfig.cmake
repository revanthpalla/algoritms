#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "LOGGER::logger" for configuration ""
set_property(TARGET LOGGER::logger APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(LOGGER::logger PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/liblogger.dylib"
  IMPORTED_SONAME_NOCONFIG "@rpath/liblogger.dylib"
  )

list(APPEND _cmake_import_check_targets LOGGER::logger )
list(APPEND _cmake_import_check_files_for_LOGGER::logger "${_IMPORT_PREFIX}/lib/liblogger.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
