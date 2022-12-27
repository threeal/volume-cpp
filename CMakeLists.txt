cmake_minimum_required(VERSION 3.0)
project(volume)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /permissive- /W4 /w14640 /EHsc")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wpedantic")
endif()

include(cmake/CPM.cmake)

cpmaddpackage(
  NAME result
  GITHUB_REPOSITORY threeal/result
  GIT_TAG 7acc062
  OPTIONS "BUILD_TESTING OFF")

add_library(volume src/device.cpp)
target_include_directories(volume PUBLIC include)
target_link_libraries(volume PUBLIC result)

if(BUILD_TESTING)
  enable_testing()

  cpmaddpackage("gh:catchorg/Catch2@3.2.0")
  include("${Catch2_SOURCE_DIR}/extras/Catch.cmake")

  add_executable(volume_test test/device_test.cpp)
  target_link_libraries(volume_test PRIVATE volume Catch2::Catch2WithMain)
  catch_discover_tests(volume_test)
endif()
