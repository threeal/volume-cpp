#pragma once

#include <mmdeviceapi.h>

#include "device.hpp"
#include "status.hpp"

namespace vol::win {

struct DeviceCollection : public Status {
  IMMDeviceCollection* p;

  ~DeviceCollection();

  StatusOf<UINT> count();
  Device get(UINT id);
};

}  // namespace vol::win
