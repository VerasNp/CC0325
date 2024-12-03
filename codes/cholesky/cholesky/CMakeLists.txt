add_library(Cholesky
    "${CMAKE_CURRENT_SOURCE_DIR}/src/cholesky.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/cholesky.hpp"
)

include_directories(Cholesky PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/include")

if(ENABLE_TESTS)
    add_subdirectory("tests")
endif()