cmake_minimum_required(VERSION 3.21)
project(volume)

option(VOLUME_ENABLE_TESTS "Enable test targets.")

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /permissive- /W4 /w14640 /EHsc")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wpedantic")
endif()

option(BUILD_EXAMPLE "build the examples" OFF)
set(TESTING_INPUTS_COUNT -1 CACHE STRING "count of input devices that is available for testing")
set(TESTING_OUTPUTS_COUNT -1 CACHE STRING "count of output devices that is available for testing")

include(cmake/CPM.cmake)
cpmaddpackage("gh:threeal/result@0.1.0")

if(PROJECT_IS_TOP_LEVEL)
  cpmaddpackage(gh:TheLartians/Format.cmake@1.8.1)

  if(VOLUME_ENABLE_TESTS)
    enable_testing()
    cpmaddpackage(gh:catchorg/Catch2@3.9.0)
    include("${Catch2_SOURCE_DIR}/extras/Catch.cmake")
  endif()
endif()

if(WIN32)
  set(EXTRA_SRCS src/device_windows.cpp)
endif()

add_library(volume src/device.cpp ${EXTRA_SRCS})
target_include_directories(volume PUBLIC include)
target_link_libraries(volume PUBLIC result)

if(WIN32)
  add_subdirectory(core/windows)
  target_link_libraries(volume PUBLIC volume_core_windows)
endif()

if(PROJECT_IS_TOP_LEVEL)
  if(VOLUME_ENABLE_TESTS)
    add_executable(volume_test test/device_test.cpp)
    target_link_libraries(volume_test PRIVATE volume Catch2::Catch2WithMain)
    target_compile_definitions(
      volume_test PRIVATE TESTING_INPUTS_COUNT=${TESTING_INPUTS_COUNT} TESTING_OUTPUTS_COUNT=${TESTING_OUTPUTS_COUNT}
    )
    catch_discover_tests(volume_test)
  endif()

  if(BUILD_EXAMPLE)
    add_subdirectory(examples)
  endif()
endif()
