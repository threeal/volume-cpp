#include <volume/core/windows/device_enumerator.hpp>

namespace vol::win {

DeviceEnumerator::~DeviceEnumerator() {
  if (is_ok()) p->Release();
}

DeviceCollection DeviceEnumerator::enumerate_input_devices() {
  DeviceCollection res;
  res.hr = p->EnumAudioEndpoints(eCapture, DEVICE_STATE_ACTIVE, &res.p);
  return res;
}

DeviceCollection DeviceEnumerator::enumerate_output_devices() {
  DeviceCollection res;
  res.hr = p->EnumAudioEndpoints(eRender, DEVICE_STATE_ACTIVE, &res.p);
  return res;
}

}  // namespace vol::win
