#include <Objbase.h>
#include <mmdeviceapi.h>

#include <volume/core/windows/com.hpp>

namespace vol::win {

Com::~Com() {
  if (is_ok()) CoUninitialize();
}

DeviceEnumerator Com::create_device_enumerator() {
  DeviceEnumerator res;
  res.hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL,
                            __uuidof(IMMDeviceEnumerator), (void**)&res.p);
  return res;
}

Com com_init() {
  Com res;
  res.hr = CoInitialize(NULL);
  return res;
}

}  // namespace vol::win
