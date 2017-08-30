cmake_minimum_required(VERSION 3.0.0)
project(hdf5_filter_plugins
        LANGUAGES C CXX
        VERSION 0.0.1)
include(CTest)
include(CPackComponent)


#=============================================================================
# cached variables deciding which filter plugin to build
#=============================================================================

set(ENABLE_LZ4_PLUGIN OFF CACHE BOOL "Build LZ4 filter plugin")
set(ENABLE_BZIP2_PLUGIN OFF CACHE BOOL "Build BZIP2 filter plugin")
set(ENABLE_BITSHUFFLE_PLUGIN OFF CACHE BOOL "Build with BitShuffle plugin")

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
#         As a matter of fact, as we do not install the modules in a directory
#         available to the system linker we can also copy all the dependencies
#         directly to the directory where the plugins will be installed. 
#=============================================================================
set(ENABLE_CONAN OFF CACHE BOOL "Enable dependency build with conan")

if(ENABLE_CONAN)
	include(cmake/ConanSetup.cmake)
	
    conan_cmake_run(CONANFILE conanfile.txt
    	            BASIC_SETUP
    	            BUILD missing)
endif()

if(ENABLE_LZ4_PLUGIN OR ENABLE_BITSHUFFLE_PLUGIN)
	include(cmake/ConfigureLZ4.cmake)
endif()

#=============================================================================
# some global configuration - check for things we need to build all the 
# filter plugins.
#=============================================================================

#
# For building the plugin modules we only need the header files. 
# However, for the tests we also need the library!
#
find_package(HDF5 REQUIRED COMPONENTS C) 

if(CMAKE_SYSTEM_NAME MATCHES Windows)
    add_definitions(-DH5_BUILT_AS_DYNAMIC_LIB)
    link_directories(${HDF5_LIBRARY_DIRS})
endif()


#-----------------------------------------------------------------------------
# set the installation paths
#-----------------------------------------------------------------------------
if(CMAKE_SYSTEM_NAME MATCHES Windows)
    set(CMAKE_INSTALL_LIBDIR lib)
    set(CMAKE_INSTALL_PLUGINDIR ${CMAKE_INSTALL_LIBDIR}/plugins)
    set(CMAKE_INSTALL_SYSTEM_RUNTIME_DESTINATION ${CMAKE_INSTALL_PLUGINDIR})
   
    #ensure that runtime libraries are installed along with the plugins 
    include(InstallRequiredSystemLibraries)    
else()
    include(GNUInstallDirs)

    #
    # TODO: need to setup the installation directories for Linux and Unix
    #       systems
    #
    set(CMAKE_INSTALL_PLUGINDIR ${CMAKE_INSTALL_LIBDIR}/plugins)

endif()

#-----------------------------------------------------------------------------
# set the output path for build artifacts - should make testing simpler 
# (in particular when we want to test plugins simultaneously)
#-----------------------------------------------------------------------------
set(CMAKE_HDF5_PLUGIN_PATH ${PROJECT_BINARY_DIR}/plugins)

#=============================================================================
#add the subdirectories for the plugins to build
#=============================================================================
if(ENABLE_LZ4_PLUGIN)
    add_subdirectory(LZ4)
endif()

if(ENABLE_BZIP2_PLUGIN)
    add_subdirectory(BZIP2)
endif()

if(ENABLE_BITSHUFFLE_PLUGIN)
    add_subdirectory(bitshuffle)
endif()


#=============================================================================
# setting up the MSI build for Windows
#=============================================================================
if(CMAKE_SYSTEM_NAME MATCHES Windows)
    set(RESOURCE_DIR ${PROJECT_SOURCE_DIR}/resources)
    set(CPACK_GENERATOR WIX)
    set(CPACK_PACKAGE_VENDOR "HDFGroup")
    set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
    set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
    set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

    set(CPACK_RESOURCE_FILE_LICENSE "${RESOURCE_DIR}/LICENSE.txt")
    set(CPACK_WIX_PATCH_FILE "${PROJECT_SOURCE_DIR}/hdf5_plugin_path_patch.xml")

    include(CPack)
    include(CPackWIX)
endif()

