#include "test.hpp"

#include <filesystem>
#include <ranges>

std::string GetTestSuitePath(const char *file) {
    std::filesystem::path path{file};
    return path.parent_path() / "test_suite.yaml";
}

std::string GetTestCaseName() {
    std::string name{testing::UnitTest::GetInstance()->current_test_info()->name()};
    std::ranges::transform(name, name.begin(), [](unsigned char c) { return std::tolower(c); });
    return name;
}
