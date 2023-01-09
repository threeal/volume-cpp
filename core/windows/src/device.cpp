#include <volume/core/windows/device.hpp>

namespace vol::win {

Device::~Device() {
  if (is_ok()) p->Release();
}

}  // namespace vol::win
