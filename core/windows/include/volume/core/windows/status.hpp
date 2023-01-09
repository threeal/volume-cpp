#pragma once

#include <Winerror.h>

namespace vol::win {

struct Status {
  HRESULT hr;
  inline bool is_ok() const { return hr == S_OK; }
};

template <typename T>
struct StatusOf : public Status {
  T val;
};

}  // namespace vol::win
