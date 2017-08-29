set(SOURCES H5Zlz4.c)

set(INCLUDE_DIRS ${HDF5_INCLUDE_DIRS} ${LZ4_INCLUDE_DIRS})
set(LINK_LIBS ${LZ4_LIBRARIES})

if(CMAKE_SYSTEM_NAME MATCHES Windows)
    #
    # we need to link with the winsock2 library
    #
    list(APPEND LINK_LIBS ws2_32.lib)
endif()


add_library(lz4_plugin MODULE ${SOURCES})
target_include_directories(lz4_plugin PRIVATE ${INCLUDE_DIRS})
target_link_libraries(lz4_plugin PRIVATE ${LINK_LIBS})
set_target_properties(lz4_plugin PROPERTIES OUTPUT_NAME h5lz4
                      LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HDF5_PLUGIN_PATH}
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HDF5_PLUGIN_PATH})

install(TARGETS lz4_plugin
        DESTINATION ${CMAKE_INSTALL_PLUGINDIR})


