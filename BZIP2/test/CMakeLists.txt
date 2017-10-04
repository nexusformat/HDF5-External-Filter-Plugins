set(datafiles ui8_data.h5)

foreach(datafile ${datafiles})
    configure_file(${datafile} ${datafile} COPYONLY)
endforeach()

#=============================================================================
# original test program provided by the HDF group
#=============================================================================
add_executable(bz2_plugin_prg1 h5ex_d_bzip2.c)
target_include_directories(bz2_plugin_prg1 PRIVATE ${HDF5_INCLUDE_DIRS})
target_link_libraries(bz2_plugin_prg1 PRIVATE ${HDF5_LIBRARIES})

add_test(NAME "HDF5:external_filters:bzip2"
         COMMAND bz2_plugin_prg1
         WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/BZIP2/test)
set_tests_properties("HDF5:external_filters:bzip2"
                     PROPERTIES
                     ENVIRONMENT
                     "HDF5_PLUGIN_PATH=$<TARGET_FILE_DIR:bz2_plugin>")


#=============================================================================
# new test program performing read-back tests. The data is generated with 
# PyTables which has support for BZIP2 compression included!
#=============================================================================
add_executable(read_ui8_test read_ui8_test.c)
target_include_directories(read_ui8_test PRIVATE ${HDF5_INCLUDE_DIRS})
target_link_libraries(read_ui8_test PRIVATE ${HDF5_LIBRARIES})

add_test(NAME "HDF5:external_filters:bipz2_read_ui8"
         COMMAND read_ui8_test
         WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/BZIP2/test)
set_tests_properties("HDF5:external_filters:bipz2_read_ui8"
                     PROPERTIES
                     ENVIRONMENT
                     "HDF5_PLUGIN_PATH=$<TARGET_FILE_DIR:bz2_plugin>")
                     
