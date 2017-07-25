message(STATUS "Building with LZ4 plugin")

#==============================================================================
# look for required packages
#
# On windows we are currently using the code provided by the repository rather
# than a third party library. The developers should definitely switch to a 
# newer version of LZ4.
#==============================================================================
if(NOT (CMAKE_SYSTEM_NAME MATCHES Windows))
    if(USE_CONAN)
        set(LZ4_ROOT ${CONAN_LZ4_ROOT})
        message(STATUS "searching for LZ4 below: ${LZ4_ROOT}")
    endif()
    find_package(LZ4 REQUIRED)
    message(STATUS "Found LZ4 libraries: ${LZ4_LIBRARY_DIRS}")
    message(STATUS "${LZ4_LIBRARIES}")
    message(STATUS "Found LZ4 headers: ${LZ4_INCLUDE_DIRS}")
else()
    message(STATUS "On Windows the repository version of LZ4 is used!")
endif()


#==============================================================================
# set the plugin name
#==============================================================================
set(PLUGIN_NAME hdf5lz4)

#==============================================================================
# add source directories
#==============================================================================
add_subdirectory(src)
add_subdirectory(test)

