#include <volume/device.hpp>
#include <volume/utils/com.hpp>

namespace vol {

res::ResultOr<Devices> list_input_devices() {
  auto com = utils::com_init();
  if (!com.is_ok()) return res::Err("failed to initialize COM");
  auto enumerator = com.create_device_enumerator();
  if (!enumerator.is_ok())
    return res::Err("failed to create a device enumerator");
  return Devices{};
}

res::ResultOr<Devices> list_output_devices() {
  auto com = utils::com_init();
  if (!com.is_ok()) return res::Err("failed to initialize COM");
  auto enumerator = com.create_device_enumerator();
  if (!enumerator.is_ok())
    return res::Err("failed to create a device enumerator");
  return Devices{};
}

}  // namespace vol
