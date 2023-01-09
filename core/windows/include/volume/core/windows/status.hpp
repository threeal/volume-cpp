#pragma once

#include <Winerror.h>

#include <string>

namespace vol::win {

struct Status {
  HRESULT hr;
  inline bool is_ok() const { return hr == S_OK; }
  std::string message() const;
};

template <typename T>
struct StatusOf : public Status {
  T val;
};

}  // namespace vol::win
