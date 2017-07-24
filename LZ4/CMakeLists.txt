message(STATUS "Building with LZ4 plugin")

#==============================================================================
# look for required packages
#==============================================================================
find_package(LZ4 REQUIRED)
message(STATUS "Found LZ4 libraries: ${LZ4_LIBRARY_DIRS}")
message(STATUS "${LZ4_LIBRARIES}")
message(STATUS "Found LZ4 headers: ${LZ4_INCLUDE_DIRS}")

#==============================================================================
# set the plugin name
#==============================================================================
set(PLUGIN_NAME hdf5lz4)

#==============================================================================
# add source directories
#==============================================================================
add_subdirectory(src)
add_subdirectory(test)

