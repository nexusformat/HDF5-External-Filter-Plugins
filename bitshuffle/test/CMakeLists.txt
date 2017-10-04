set(datafiles bslz4_3x4x5_testdata.h5)

foreach(datafile ${datafiles})
    configure_file(${datafile} ${datafile} COPYONLY)
endforeach()



#=============================================================================
# new test program performing read-back tests. The data is generated with 
# PyTables which has support for BZIP2 compression included!
#=============================================================================
add_executable(bitshuffle_ui8_test read_ui8_test.c)
target_include_directories(bitshuffle_ui8_test PRIVATE ${HDF5_INCLUDE_DIRS})
target_link_libraries(bitshuffle_ui8_test PRIVATE ${HDF5_LIBRARIES})

add_test(NAME "HDF5:external_filters:bitshuffle_read_ui8"
         COMMAND bitshuffle_ui8_test
         WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/bitshuffle/test)
set_tests_properties("HDF5:external_filters:bitshuffle_read_ui8"
                     PROPERTIES
                     ENVIRONMENT
                     "HDF5_PLUGIN_PATH=$<TARGET_FILE_DIR:bitshuffle_plugin>")
                     
add_executable(bitshuffle_ui16_test read_ui16_test.c)
target_include_directories(bitshuffle_ui16_test PRIVATE ${HDF5_INCLUDE_DIRS})
target_link_libraries(bitshuffle_ui16_test PRIVATE ${HDF5_LIBRARIES})

add_test(NAME "HDF5:external_filters:bitshuffle_read_ui16"
         COMMAND bitshuffle_ui16_test
         WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/bitshuffle/test)
set_tests_properties("HDF5:external_filters:bitshuffle_read_ui16"
                     PROPERTIES
                     ENVIRONMENT
                     "HDF5_PLUGIN_PATH=$<TARGET_FILE_DIR:bitshuffle_plugin>")

add_executable(bitshuffle_ui32_test read_ui32_test.c)
target_include_directories(bitshuffle_ui32_test PRIVATE ${HDF5_INCLUDE_DIRS})
target_link_libraries(bitshuffle_ui32_test PRIVATE ${HDF5_LIBRARIES})

add_test(NAME "HDF5:external_filters:bitshuffle_read_ui32"
         COMMAND bitshuffle_ui32_test
         WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/bitshuffle/test)
set_tests_properties("HDF5:external_filters:bitshuffle_read_ui32"
                     PROPERTIES
                     ENVIRONMENT
                     "HDF5_PLUGIN_PATH=$<TARGET_FILE_DIR:bitshuffle_plugin>")

add_executable(bshuf_exists_test bshuf_exists.c)
target_include_directories(bshuf_exists_test PRIVATE ${HDF5_INCLUDE_DIRS})
target_link_libraries(bshuf_exists_test ${HDF5_LIBRARIES})
add_test(NAME "HDF5:external_filters:bitshuffle_load"
         COMMAND bshuf_exists_test
         WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/bitshuffle/test)
set_tests_properties("HDF5:external_filters:bitshuffle_load"
                     PROPERTIES
                     ENVIRONMENT
                     "HDF5_PLUGIN_PATH=$<TARGET_FILE_DIR:bitshuffle_plugin>")

