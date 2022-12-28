#pragma once

#include <mmdeviceapi.h>

#include "status.hpp"

namespace vol::utils {

struct Device : public Status {
  IMMDevice* p;

  ~Device() {
    if (is_ok()) p->Release();
  }
};

}  // namespace vol::utils
