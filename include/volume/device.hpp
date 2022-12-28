#pragma once

#include <result/result_or.hpp>
#include <string>
#include <vector>

namespace vol {

struct Device {};

using Devices = std::vector<Device>;

res::ResultOr<Devices> list_input_devices();
res::ResultOr<Devices> list_output_devices();

}  // namespace vol
