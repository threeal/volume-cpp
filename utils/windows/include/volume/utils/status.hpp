#pragma once

#include <mmdeviceapi.h>

namespace vol::utils {

struct Status {
  HRESULT hr;
  bool is_ok() const { return SUCCEEDED(hr); }
};

}  // namespace vol::utils
