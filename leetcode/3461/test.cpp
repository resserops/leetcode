#include "test.hpp"
#include "solution.hpp"

using namespace testing;
namespace {
using SolutionList = TypeList<Solution>;
struct TestCase {
    TestCase(const YAML::Node &node) {
        Decode(node["input"]["s"], input.s);
        Decode(node["expected"], expected);
    }
    struct {
        std::string s;
    } input;
    bool expected;
};

template <typename Solution>
void RunTest(const std::string &s, const bool expected) {
    // 检查约束条件
    ASSERT_THAT(s.size(), AllOf(Ge(3), Le(100))); // 3 <= s.length <= 100
    ASSERT_THAT(s, Each(Truly(IsDigit)));         // s consists of only digits

    // 测试目标函数
    Solution solution;
    EXPECT_EQ(solution.hasSameDigits(s), expected);
}

template <typename Solution>
void RunTest(const TestCase &tc) {
    RunTest<Solution>(tc.input.s, tc.expected);
}

TEST_Y(LeetCode3461, Example1);
TEST_Y(LeetCode3461, Example2);
TEST_Y(LeetCode3461, Regression1);
TEST_Y(LeetCode3461, Regression2);
TEST_Y(LeetCode3461, Regression3);
} // namespace
