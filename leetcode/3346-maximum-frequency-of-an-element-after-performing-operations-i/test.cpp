#include "solution.hpp"
#include "gtest/gtest.h"

template <typename Solution>
void Expect(const int expected, const std::vector<int> &nums, const int k, const int numOperations) {
    Solution solution;
    EXPECT_EQ(expected, solution.maxFrequency(nums, k, numOperations));
}

TEST(LeetCode3346, Example1) {
    const std::vector<int> nums{1, 4, 5};
    Expect<Solution>(2, nums, 1, 2);
}

TEST(LeetCode3346, Example2) {
    const std::vector<int> nums{5, 11, 20, 20};
    Expect<Solution>(2, nums, 5, 1);
}

TEST(LeetCode3346, Regression1) {
    const std::vector<int> nums{88, 53};
    Expect<Solution>(2, nums, 27, 2);
}

TEST(LeetCode3346, Regression2) {
    const std::vector<int> nums{1, 2, 4, 5};
    Expect<Solution>(4, nums, 2, 4);
}

TEST(LeetCode3346, Regression3) {
    // 用例存在yaml中
}

TEST(LeetCode3346, Regression4) {
    const std::vector<int> nums{2};
    Expect<Solution>(1, nums, 7, 0);
}

TEST(LeetCode3346, Regression5) {
    const std::vector<int> nums{1, 90};
    Expect<Solution>(1, nums, 76, 1);
}

TEST(LeetCode3346, Regression6) {
    const std::vector<int> nums{111, 21, 21, 13, 11};
    Expect<Solution>(2, nums, 3, 0);
}

TEST(LeetCode3346, Regression7) {
    const std::vector<int> nums{28, 79, 98, 98, 61, 41};
    Expect<Solution>(2, nums, 4, 0);
}
