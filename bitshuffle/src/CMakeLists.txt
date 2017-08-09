set(SOURCES bitshuffle.c
            bshuf_h5filter.c
            bshuf_h5plugin.c)


set(INCLUDE_DIRS ${HDF5_INCLUDE_DIRS})


add_library(bitshuffle_plugin MODULE ${SOURCES})
target_include_directories(bitshuffle_plugin PRIVATE ${INCLUDE_DIRS})
set_target_properties(bitshuffle_plugin PROPERTIES OUTPUT_NAME h5bitshuffle)

install(TARGETS bitshuffle_plugin
        DESTINATION ${CMAKE_INSTALL_PLUGINDIR})


