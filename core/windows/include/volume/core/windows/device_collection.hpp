#pragma once

#include <mmdeviceapi.h>

#include "device.hpp"
#include "status.hpp"

namespace vol::win {

struct DeviceCollection : public Status {
  IMMDeviceCollection* p;

  ~DeviceCollection() {
    if (is_ok()) p->Release();
  }

  StatusOf<UINT> count() {
    StatusOf<UINT> res;
    res.hr = p->GetCount(&res.val);
    return res;
  }

  Device get(UINT id) {
    Device res;
    res.hr = p->Item(id, &res.p);
    return res;
  }
};

}  // namespace vol::win
