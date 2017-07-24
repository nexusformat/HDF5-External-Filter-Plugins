cmake_minimum_required(VERSION 3.0.0)
project(hdf5_filter_plugins
        LANGUAGES C
        VERSION 0.0.1)


#=============================================================================
# cached variables deciding which filter plugin to build
#=============================================================================

set(ENABLE_LZ4_PLUGIN OFF CACHE BOOL "Build LZ4 filter plugin")
set(ENABLE_BZIP2_PLUGIN OFF CACHE BOOL "Build BZIP2 filter plugin")

#
# add the global cmake directory to the module search path. Thus we can keep
# CMake code used by all plugins at a single location and avoid code
# duplications for the build system.
#
if(NOT DEFINED CMAKE_MODULE_PATH)
    message(STATUS "define an empty cmake module path")
    set(CMAKE_MODULE_PATH)
endif()
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

#=============================================================================
# if there is a conan file in the build directory we use conan to satisfy
# the build dependencies. This is currently not implemented.
#
# Using conan is particularly useful on Windows and OSX systems but can also 
# be useful on Linux systems where the required libraries are not available 
# from the distributions native package repositories. 
#
# Remark: if we use conan we have to ensure that all required shared 
#         libraries are copied to the install directory for OSX and Windows. 
#         For Linux we need to use RPATH for linking and copy the libraries
#         to a reasonable location according to the FHS (the same is true 
#         for all other Unix systems). 
#=============================================================================
if(EXISTS ${PROJECT_BINARY_DIR}/conanbuildinfo.cmake)
    message(WARNING "Conan build is currently not implemented!")
endif()

#=============================================================================
# some global configuration - check for things we need to build all the 
# filter plugins.
#=============================================================================

#
# For building the plugin modules we only need the header files. 
# However, for the tests we also need the library!
#
find_package(HDF5 REQUIRED) 


#=============================================================================
#add the subdirectories for the plugins to build
#=============================================================================
if(ENABLE_LZ4_PLUGIN)
    add_subdirectory(LZ4)
endif()

if(ENABLE_BZIP2_PLUGIN)
    add_subdirectory(BZIP2)
endif()
