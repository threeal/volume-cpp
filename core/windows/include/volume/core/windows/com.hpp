#pragma once

#include <Objbase.h>
#include <mmdeviceapi.h>

#include "device_enumerator.hpp"
#include "status.hpp"

namespace vol::win {

struct Com : public Status {
  ~Com() {
    if (is_ok()) CoUninitialize();
  }

  DeviceEnumerator create_device_enumerator() {
    DeviceEnumerator res;
    res.hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL,
                              __uuidof(IMMDeviceEnumerator), (void**)&res.p);
    return res;
  }
};

Com com_init() {
  Com res;
  res.hr = CoInitialize(NULL);
  return res;
}

}  // namespace vol::win
