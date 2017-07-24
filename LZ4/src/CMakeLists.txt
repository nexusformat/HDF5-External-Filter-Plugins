message(STATUS ${LZ4_INCLUDE_DIRS})
add_library(lz4_plugin MODULE H5Zlz4.c)
target_include_directories(lz4_plugin PRIVATE
    ${LZ4_INCLUDE_DIRS}
    ${HDF5_INCLUDE_DIRS})
target_link_libraries(lz4_plugin PRIVATE
    ${LZ4_LIBRARIES})
set_target_properties(lz4_plugin PROPERTIES OUTPUT_NAME h5lz4)
