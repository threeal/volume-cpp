#pragma once

#include "device_enumerator.hpp"
#include "status.hpp"

namespace vol::win {

struct Com : public Status {
  ~Com();
  DeviceEnumerator create_device_enumerator();
};

Com com_init();

}  // namespace vol::win
