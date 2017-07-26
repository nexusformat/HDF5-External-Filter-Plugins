
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

