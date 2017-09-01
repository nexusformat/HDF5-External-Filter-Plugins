
#=============================================================================
# do some plugin specific configuration
#=============================================================================
find_package(BZip2 REQUIRED)

if(CMAKE_SYSTEM_NAME MATCHES Windows)
    set(EXTERNAL_LIBRARIES ${PROJECT_BINARY_DIR}/bin/bz2.dll)
endif()

#=============================================================================
# setup the plugin name
#=============================================================================
set(PLUGIN_NAME h5bz2)

#=============================================================================
# adding required subdirectories
#=============================================================================
add_subdirectory(src)
add_subdirectory(test)



