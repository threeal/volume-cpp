#pragma once

#include <mmdeviceapi.h>

#include "device_collection.hpp"
#include "status.hpp"

namespace vol::utils {

struct DeviceEnumerator : public Status {
  IMMDeviceEnumerator* p;

  ~DeviceEnumerator() {
    if (is_ok()) p->Release();
  }

  DeviceCollection enumerate_input_devices() {
    DeviceCollection res;
    res.hr = p->EnumAudioEndpoints(eCapture, DEVICE_STATE_ACTIVE, &res.p);
    return res;
  }

  DeviceCollection enumerate_output_devices() {
    DeviceCollection res;
    res.hr = p->EnumAudioEndpoints(eRender, DEVICE_STATE_ACTIVE, &res.p);
    return res;
  }
};

}  // namespace vol::utils
