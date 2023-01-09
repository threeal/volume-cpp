#pragma once

#include <mmdeviceapi.h>

#include "device_collection.hpp"
#include "status.hpp"

namespace vol::win {

struct DeviceEnumerator : public Status {
  IMMDeviceEnumerator* p;

  ~DeviceEnumerator();

  DeviceCollection enumerate_input_devices();
  DeviceCollection enumerate_output_devices();
};

}  // namespace vol::win
