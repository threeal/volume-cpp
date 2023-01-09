add_library(volume_core_windows STATIC src/com.cpp src/device_collection.cpp src/device_enumerator.cpp src/device.cpp
                                       src/status.cpp)
target_include_directories(volume_core_windows PUBLIC include)
