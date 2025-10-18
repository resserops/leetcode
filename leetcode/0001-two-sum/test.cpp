#include "solution.hpp"
#include "gtest/gtest.h"

void Expect(const std::vector<int> &expected, const std::vector<int> &nums, int target) {
    Solution solution;
    auto res{solution.twoSum(nums, target)};
    ASSERT_EQ(res.size(), 2);
    if (res[0] > res[1]) {
        std::swap(res[0], res[1]);
    }
    EXPECT_EQ(expected, res);
}

TEST(LeetCode1, Example1) {
    const std::vector<int> expected{0, 1};
    const std::vector<int> nums{2, 7, 11, 15};
    Expect(expected, nums, 9);
}

TEST(LeetCode1, Example2) {
    const std::vector<int> expected{1, 2};
    const std::vector<int> nums{3, 2, 4};
    Expect(expected, nums, 6);
}

TEST(LeetCode1, Example3) {
    const std::vector<int> expected{0, 1};
    const std::vector<int> nums{3, 3};
    Expect(expected, nums, 6);
}
