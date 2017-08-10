
if(USE_CONAN)
    set(LZ4_ROOT ${CONAN_LZ4_ROOT})
    message(STATUS "searching for LZ4 below: ${LZ4_ROOT}")
endif()
find_package(LZ4 REQUIRED)
message(STATUS "Found LZ4 libraries: ${LZ4_LIBRARY_DIRS}")
message(STATUS "${LZ4_LIBRARIES}")
message(STATUS "Found LZ4 headers: ${LZ4_INCLUDE_DIRS}")

add_subdirectory(src)
add_subdirectory(test)
