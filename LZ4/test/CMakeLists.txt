add_executable(lz4_test_prg1 h5ex_d_lz4.c)
target_include_directories(lz4_test_prg1 PRIVATE
    ${HDF5_INCLUDE_DIRS})
target_link_libraries(lz4_test_prg1 PRIVATE
    ${HDF5_LIBRARIES})

add_test(NAME "HDF5:external_filters:LZ4"
         COMMAND lz4_test_prg1
         WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/LZ4/test)
set_tests_properties("HDF5:external_filters:LZ4"
                     PROPERTIES
                     ENVIRONMENT
                     "HDF5_PLUGIN_PATH=$<TARGET_FILE_DIR:lz4_plugin>")
         
