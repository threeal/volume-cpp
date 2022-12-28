#pragma once

#include <mmdeviceapi.h>

#include "status.hpp"

namespace vol::utils {

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
};

}  // namespace vol::utils
