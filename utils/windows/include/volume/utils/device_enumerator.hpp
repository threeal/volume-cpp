#pragma once

#include <mmdeviceapi.h>
#include "status.hpp"

namespace vol::utils {

struct DeviceEnumerator : public Status {
  IMMDeviceEnumerator* p;
  ~DeviceEnumerator() { if (is_ok()) p->Release(); }
};

DeviceEnumerator create_device_enumerator() {
  DeviceEnumerator res;
  res.hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&res.p);
  return res;
}

}  // namespace vol::utils
