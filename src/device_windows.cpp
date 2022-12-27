#include <volume/device.hpp>
#include <volume/utils/device_enumerator.hpp>

namespace vol {

res::ResultOr<Devices> list_devices() {
  const auto enumerator = utils::create_device_enumerator();
  if (!enumerator.is_ok()) return res::Err("failed to create a device enumerator");
  return Devices{};
}

}  // namespace vol
