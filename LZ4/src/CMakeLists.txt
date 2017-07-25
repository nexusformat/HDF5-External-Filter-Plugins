set(SOURCES H5Zlz4.c)

set(INCLUDE_DIRS ${HDF5_INCLUDE_DIRS})
set(LINK_LIBS)

if(CMAKE_SYSTEM_NAME MATCHES Windows)
    #
    # on Windows we do not link with an external library but rather use the 
    # LZ4 code shipped with the repository.
    #
    list(APPEND SOURCES lz4.c lz4hc.c)

    #
    # we need to link with the winsock2 library
    #
    list(APPEND LINK_LIBS ws2_32.lib)
else()
    list(APPEND INCLUDE_DIRS ${LZ4_INCLUDE_DIRS})
    list(APPEND LINK_LIBS ${LZ4_LIBRARIES})
endif()


add_library(lz4_plugin MODULE ${SOURCES})
target_include_directories(lz4_plugin PRIVATE ${INCLUDE_DIRS})
target_link_libraries(lz4_plugin PRIVATE ${LINK_LIBS})
set_target_properties(lz4_plugin PROPERTIES OUTPUT_NAME h5lz4)
