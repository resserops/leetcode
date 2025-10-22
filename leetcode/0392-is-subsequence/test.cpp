#include "solution.hpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace ::testing;

template <typename Solution>
void Expect(const bool expected, const std::string &s, const std::string &t) {
    // 检查约束条件
    ASSERT_THAT(s.size(), AllOf(Ge(0), Le(100)));   // 0 <= s.length <= 100
    ASSERT_THAT(t.size(), AllOf(Ge(0), Le(10000))); // 0 <= t.length <= 10^4

    // 测试目标函数
    Solution solution;
    EXPECT_EQ(expected, solution.isSubsequence(s, t));
}

TEST(LeetCode392, Example1) { Expect<Solution>(true, "abc", "ahbgdc"); }

TEST(LeetCode392, Example2) { Expect<Solution>(false, "axc", "ahbgdc"); }
