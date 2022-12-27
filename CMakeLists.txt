cmake_minimum_required(VERSION 3.0)

project(volume)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wpedantic")

include(cmake/CPM.cmake)
cpmaddpackage("gh:TheLartians/Format.cmake@1.7.3")

add_library(volume src/example.cpp)
target_include_directories(volume PUBLIC include)

if(BUILD_TESTING)
  enable_testing()

  cpmaddpackage("gh:catchorg/Catch2@3.2.0")
  include("${Catch2_SOURCE_DIR}/extras/Catch.cmake")

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -fPIC -O0")

  add_executable(volume_test test/example_test.cpp)
  target_link_libraries(volume_test PRIVATE volume Catch2::Catch2WithMain)
  catch_discover_tests(volume_test)
endif()
