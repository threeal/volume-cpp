#include <catch2/catch_test_macros.hpp>
#include <volume/core/windows/status.hpp>

TEST_CASE("check Windows core's status") {
  vol::win::Status status;
  SECTION("ok status") {
    status.hr = S_OK;
    CHECK(status.is_ok());
  }
  SECTION("error status") {
    status.hr = E_UNEXPECTED;
    CHECK_FALSE(status.is_ok());
  }
}

TEST_CASE("check Windows core's status message") {
  vol::win::Status status;
  SECTION("ok status") {
    status.hr = S_OK;
    CHECK(status.message() == std::string("The operation completed successfully."));
  }
  SECTION("error status") {
    status.hr = E_FAIL;
    CHECK(status.message() == std::string("Unspecified error"));
  }
}
