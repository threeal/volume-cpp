#include <volume/device.hpp>
#include <volume/utils/com.hpp>

namespace vol {

res::ResultOr<Devices> list_input_devices() {
  auto com = utils::com_init();
  if (!com.is_ok()) {
    return res::Err("failed to initialize COM");
  }
  auto enumerator = com.create_device_enumerator();
  if (!enumerator.is_ok()) {
    return res::Err("failed to create a device enumerator");
  }
  auto devices = enumerator.enumerate_input_devices();
  if (!devices.is_ok()) {
    return res::Err("failed to enumerate input devices");
  }
  auto count = devices.count();
  if (!count.is_ok()) {
    return res::Err("failed to count devices");
  }
  return Devices{};
}

res::ResultOr<Devices> list_output_devices() {
  auto com = utils::com_init();
  if (!com.is_ok()) {
    return res::Err("failed to initialize COM");
  }
  auto enumerator = com.create_device_enumerator();
  if (!enumerator.is_ok()) {
    return res::Err("failed to create a device enumerator");
  }
  auto devices = enumerator.enumerate_output_devices();
  if (!devices.is_ok()) {
    return res::Err("failed to enumerate output devices");
  }
  auto count = devices.count();
  if (!count.is_ok()) {
    return res::Err("failed to count devices");
  }
  return Devices{};
}

}  // namespace vol
