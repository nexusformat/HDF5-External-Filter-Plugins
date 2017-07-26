add_library(bz2_plugin MODULE H5Zbzip2.c)
target_include_directories(bz2_plugin PRIVATE
    ${BZIP2_INCLUDE_DIR} ${HDF5_INCLUDE_DIRS})
target_link_libraries(bz2_plugin PRIVATE
    ${BZIP2_LIBRARIES})
set_target_properties(bz2_plugin PROPERTIES 
    OUTPUT_NAME ${PLUGIN_NAME})

install(TARGETS bz2_plugin
        DESTINATION ${CMAKE_INSTALL_PLUGINDIR})
