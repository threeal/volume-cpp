#pragma once

#include <mmdeviceapi.h>

#include "status.hpp"

namespace vol::utils {

struct DeviceCollection : public Status {
  IMMDeviceCollection* p;

  ~DeviceCollection() {
    if (is_ok()) p->Release();
  }
};

}  // namespace vol::utils
