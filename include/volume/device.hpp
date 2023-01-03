#pragma once

#include <result/result_of.hpp>
#include <string>
#include <vector>

namespace vol {

struct Device {};

using Devices = std::vector<Device>;

res::ResultOf<Devices> list_input_devices();
res::ResultOf<Devices> list_output_devices();

}  // namespace vol
