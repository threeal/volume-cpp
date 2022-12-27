#pragma once

#include <result/result_or.hpp>
#include <string>
#include <vector>

namespace vol {

struct Device {};

using Devices = std::vector<Device>;

res::ResultOr<Devices> list_devices();

}  // namespace vol
