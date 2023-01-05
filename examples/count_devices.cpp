#include <iostream>
#include <volume/device.hpp>

int main() {
  const auto inputs = vol::list_input_devices();
  if (inputs.is_err()) {
    std::cerr << "failed to list input devices! " << inputs.unwrap_err() << std::endl;
    return 1;
  }
  const auto outputs = vol::list_output_devices();
  if (outputs.is_err()) {
    std::cerr << "failed to list output devices! " << outputs.unwrap_err() << std::endl;
    return 1;
  }
  std::cout << "input devices: " << inputs.unwrap().size() << std::endl;
  std::cout << "output devices: " << outputs.unwrap().size() << std::endl;
  return 0;
}
