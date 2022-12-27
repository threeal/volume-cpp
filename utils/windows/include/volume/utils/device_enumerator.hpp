#pragma once

#include <mmdeviceapi.h>
#include "status.hpp"

namespace vol::utils {

struct DeviceEnumerator : public Status {
  IMMDeviceEnumerator* p;
  ~DeviceEnumerator() { if (is_ok()) p->Release(); }
};

}  // namespace vol::utils
