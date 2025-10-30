#include "yaml-cpp/yaml.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#define TEST_Y(suite, name) \
    TEST(suite, name) { ::detail::RunTestImpl<SolutionList>::F(::detail::GetTestCase<TestCase>()); }

namespace detail {
std::string GetTestSuitePath();
std::string GetTestCaseName();

template <typename TestCase>
auto GetTestSuite(const std::string &testSuitePath) {
    std::unordered_map<std::string, TestCase> testSuite;
    auto testCaseFile{YAML::LoadFile(testSuitePath)};
    for (const auto &p : testCaseFile) {
        std::string key{p.first.template as<std::string>()};
        testSuite.emplace(key, p.second);
    }
    return testSuite;
}

template <typename TestCase>
const TestCase &GetTestCase() {
    static const auto path{GetTestSuitePath()};
    static const auto testSuite{GetTestSuite<TestCase>(path)};
    assert(path == GetTestSuitePath());
    return testSuite.at(GetTestCaseName());
}

template <typename>
struct RunTestImpl;
template <template <typename...> typename TypeList, typename... Solutions>
struct RunTestImpl<TypeList<Solutions...>> {
    template <typename... Args>
    static void F(const Args &...args) {
        (RunTest<Solutions>(args...), ...);
    }
};
} // namespace detail

template <typename T>
void Decode(const YAML::Node &node, T &t) {
    t = node.as<std::decay_t<T>>();
}

template <typename...>
struct TypeList;

// 用例约束检查
// 编译期计算10^N，简明定义数据范围
template <unsigned N>
constexpr std::intmax_t E{10 * E<N - 1>};
template <>
constexpr std::intmax_t E<0>{1};

constexpr bool IsLower(char c) noexcept { return 'a' <= c && c <= 'z'; }
constexpr bool IsDigit(char c) noexcept { return '0' <= c && c <= '9'; }
