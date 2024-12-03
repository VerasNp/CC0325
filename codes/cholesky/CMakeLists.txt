cmake_minimum_required(VERSION 3.10)
project(Cholesky VERSION 1.0 LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}/build")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${BUILD_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${BUILD_DIR}/lib")

include_directories("lib")

option(ENABLE_TESTS "Enable tests" OFF)

if(ENABLE_TESTS)
  enable_testing()
  add_library(Doctest INTERFACE)
  target_include_directories(Doctest INTERFACE "${CMAKE_SOURCE_DIR}/lib/doctest")
endif()

add_subdirectory("cholesky")

if(ENABLE_MAIN)
  add_executable(CholeskyExecutable "${CMAKE_SOURCE_DIR}/exe/main.cpp")
  include_directories(CholeskyExecutable PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/cholesky/include")
  target_link_libraries(CholeskyExecutable PUBLIC Cholesky)
endif()
