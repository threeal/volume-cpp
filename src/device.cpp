#include <volume/device.hpp>

namespace vol {

#ifndef _WIN32

res::ResultOr<Devices> list_input_devices() {
  return res::Err("unimplemented");  //
}

res::ResultOr<Devices> list_output_devices() {
  return res::Err("unimplemented");  //
}

#endif

}  // namespace vol
