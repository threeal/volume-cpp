#include <volume/core/windows/com.hpp>
#include <volume/core/windows/device_collection.hpp>
#include <volume/device.hpp>

namespace vol {

namespace {

res::ResultOr<Devices> to_devices(win::DeviceCollection& device_collection) {
  auto count = device_collection.count();
  if (!count.is_ok()) {
    return res::Err("failed to count devices");
  }
  Devices devices;
  for (UINT i = 0; i < count.val; ++i) {
    auto device = device_collection.get(i);
    if (!device.is_ok()) continue;
    devices.push_back(Device());
  }
  return devices;
}

}  // namespace

res::ResultOr<Devices> list_input_devices() {
  auto com = win::com_init();
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
  return to_devices(devices);
}

res::ResultOr<Devices> list_output_devices() {
  auto com = win::com_init();
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
  return to_devices(devices);
}

}  // namespace vol
