#include "test.hpp"
#include "solution.hpp"

using namespace testing;
namespace {
using SolutionList = std::tuple<Solution>;
struct TestCase {
    TestCase(const YAML::Node &node) {
        Decode(node["input"]["s"], input.s);
        Decode(node["input"]["t"], input.t);
        Decode(node["expected"], expected);
    }
    struct {
        std::string s;
        std::string t;
    } input;
    bool expected;
};

template <typename Solution>
void Expect(const std::string &s, const std::string &t, const bool expected) {
    // 检查约束条件
    ASSERT_THAT(s.size(), AllOf(Ge(0), Le(100)));   // 0 <= s.length <= 100
    ASSERT_THAT(t.size(), AllOf(Ge(0), Le(10000))); // 0 <= t.length <= 10^4
    for (auto ch : s) {                             // s and t consist only of lowercase English letters
        ASSERT_TRUE(std::islower(ch));
    }
    for (auto ch : t) {
        ASSERT_TRUE(std::islower(ch));
    }

    // 测试目标函数
    Solution solution;
    EXPECT_EQ(solution.isSubsequence(s, t), expected);
}

template <typename Solution>
void Expect(const TestCase &tc) {
    Expect<Solution>(tc.input.s, tc.input.t, tc.expected);
}

TEST_Y(LeetCode392, Example1);
TEST_Y(LeetCode392, Example2);
TEST_Y(LeetCode392, Regression1);
} // namespace
