#include <volume/core/windows/com.hpp>
#include <volume/core/windows/device_collection.hpp>
#include <volume/device.hpp>

namespace vol {

namespace {

res::ResultOf<Devices> to_devices(win::DeviceCollection& win_devices) {
  auto count = win_devices.count();
  if (!count.is_ok()) {
    return res::ErrStream() << "failed to count devices: " << count.message();
  }
  Devices devices;
  for (UINT i = 0; i < count.val; ++i) {
    auto win_device = win_devices.get(i);
    if (!win_device.is_ok()) continue;
    devices.push_back(Device());
  }
  return devices;
}

}  // namespace

res::ResultOf<Devices> list_input_devices() {
  auto win_com = win::com_init();
  if (!win_com.is_ok()) {
    return res::ErrStream() << "failed to initialize COM: " << win_com.message();
  }
  auto win_enumerator = win_com.create_device_enumerator();
  if (!win_enumerator.is_ok()) {
    return res::ErrStream() << "failed to create a device enumerator: "
                            << win_enumerator.message();
  }
  auto win_devices = win_enumerator.enumerate_input_devices();
  if (!win_devices.is_ok()) {
    return res::ErrStream() << "failed to enumerate input devices: "
                            << win_devices.message();
  }
  return to_devices(win_devices);
}

res::ResultOf<Devices> list_output_devices() {
  auto win_com = win::com_init();
  if (!win_com.is_ok()) {
    return res::ErrStream() << "failed to initialize COM: " << win_com.message();
  }
  auto win_enumerator = win_com.create_device_enumerator();
  if (!win_enumerator.is_ok()) {
    return res::ErrStream() << "failed to create a device enumerator: "
                            << win_enumerator.message();
  }
  auto win_devices = win_enumerator.enumerate_output_devices();
  if (!win_devices.is_ok()) {
    return res::ErrStream() << "failed to enumerate output devices: "
                            << win_devices.message();
  }
  return to_devices(win_devices);
}

}  // namespace vol
