#include "yaml-cpp/yaml.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#define GET_TEST_CASE() ::GetTestCase<TestCase>(::GetTestSuitePath(__FILE__), ::GetTestCaseName())
#define TEST_Y(suite, name) \
    TEST(suite, name) { ::Expect(SolutionList{}, GET_TEST_CASE()); }

std::string GetTestSuitePath(const char *file);
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
const TestCase &GetTestCase(const std::string &testSuitePath, const std::string &key) {
    static const std::string &path{testSuitePath};
    static const auto testSuite{GetTestSuite<TestCase>(path)};
    assert(testSuitePath == path);
    return testSuite.at(key);
}

template <typename T>
void Decode(const YAML::Node &node, T &t) {
    t = node.as<std::decay_t<T>>();
}

template <template <typename...> typename Ts, typename... Solutions, typename... Args>
void Expect(Ts<Solutions...> &&, Args &&...args) {
    (Expect<Solutions>(std::forward<Args>(args)...), ...);
}
