#include "test_utility.hpp"

#include <cctype>
#include <filesystem>
#include <ranges>

namespace detail {
std::string GetTestSuitePath() {
    std::filesystem::path path{PROBLEM_PATH};
    std::string_view suite{testing::UnitTest::GetInstance()->current_test_info()->test_suite_name()};
    std::string_view num{
        suite.substr(std::distance(suite.begin(), std::find_if(suite.begin(), suite.end(), ::isdigit)))};
    return path / (std::string(4 - num.size(), '0') + std::string(num)) / "test_suite.yaml";
}

std::string GetTestCaseName() {
    std::string name{testing::UnitTest::GetInstance()->current_test_info()->name()};
    name[0] = std::tolower(name[0]);
    return name;
}
} // namespace detail
