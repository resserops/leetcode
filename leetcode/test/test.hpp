#include "yaml-cpp/yaml.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#define TEST_Y(suite, name) \
    TEST(suite, name) { ::Expect(SolutionList{}, ::GetTestCase<TestCase>()); }

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
    return testSuite.at(::GetTestCaseName());
}

template <typename T>
void Decode(const YAML::Node &node, T &t) {
    t = node.as<std::decay_t<T>>();
}

template <template <typename...> typename Ts, typename... Solutions, typename... Args>
void Expect(Ts<Solutions...> &&, Args &&...args) {
    (Expect<Solutions>(std::forward<Args>(args)...), ...);
}
