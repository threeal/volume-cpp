#include <catch2/catch_test_macros.hpp>
#include <volume/device.hpp>

TEST_CASE("list devices") {
  const auto res = vol::list_devices();
  if (res.is_err()) FAIL(res.unwrap_err());
}
