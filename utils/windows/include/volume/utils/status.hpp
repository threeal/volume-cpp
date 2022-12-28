#pragma once

#include <mmdeviceapi.h>

namespace vol::utils {

struct Status {
  HRESULT hr;
  bool is_ok() const { return SUCCEEDED(hr); }
};

template <typename T>
struct StatusOf : public Status {
  T val;
};

}  // namespace vol::utils
