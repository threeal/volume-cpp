#include <catch2/catch_test_macros.hpp>
#include <volume/device.hpp>

TEST_CASE("list input devices") {
  const auto res = vol::list_input_devices();
  if (res.is_err()) FAIL(res.unwrap_err());
  REQUIRE(res.unwrap().size() == TESTING_INPUTS_COUNT);
}

TEST_CASE("list output devices") {
  const auto res = vol::list_output_devices();
  if (res.is_err()) FAIL(res.unwrap_err());
  REQUIRE(res.unwrap().size() == TESTING_OUTPUTS_COUNT);
}
