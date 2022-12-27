#include <volume/device.hpp>

namespace vol {

#ifndef _WIN32

res::ResultOr<Devices> list_devices() {
  return res::Err("unimplemented");  //
}

#endif

}  // namespace vol
