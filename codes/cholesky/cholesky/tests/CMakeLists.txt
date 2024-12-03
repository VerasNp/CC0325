set(TestsToRun
    "${CMAKE_CURRENT_SOURCE_DIR}/cholesky/cholesky.test.cpp"
)

foreach(test ${TestsToRun})
    get_filename_component(TName ${test} NAME_WE)
    add_executable(${TName} ${test} "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
    target_compile_features(${TName} PRIVATE cxx_std_17)
    target_link_libraries(${TName} PRIVATE Doctest Cholesky)
    add_test(NAME ${TName} COMMAND ${TName})
endforeach()