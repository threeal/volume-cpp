#include <comdef.h>

#include <volume/core/windows/status.hpp>

namespace vol::win {

std::string Status::message() const { return _com_error(hr).ErrorMessage(); }

}  // namespace vol::win
