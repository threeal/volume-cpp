add_library(
  volume_core_windows STATIC
  src/com.cpp
  src/device_collection.cpp
  src/device_enumerator.cpp
  src/device.cpp
  src/status.cpp
)
target_include_directories(volume_core_windows PUBLIC include)

if(BUILD_TESTING)
  add_executable(volume_core_windows_test test/status_test.cpp)
  target_link_libraries(volume_core_windows_test PRIVATE volume Catch2::Catch2WithMain)
  catch_discover_tests(volume_core_windows_test)
endif()
