#include <volume/device.hpp>

namespace vol {

#ifndef _WIN32

res::ResultOf<Devices> list_input_devices() {
  return res::Err("unimplemented");  //
}

res::ResultOf<Devices> list_output_devices() {
  return res::Err("unimplemented");  //
}

#endif

}  // namespace vol
