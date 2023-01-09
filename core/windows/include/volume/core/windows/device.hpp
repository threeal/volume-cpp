#pragma once

#include <mmdeviceapi.h>

#include "status.hpp"

namespace vol::win {

struct Device : public Status {
  IMMDevice* p;
  ~Device();
};

}  // namespace vol::win
