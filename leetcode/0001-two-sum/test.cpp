#include "solution.hpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace testing;

void Expect(const std::vector<int> &expected, const std::vector<int> &nums, const int target) {
    // 检查约束条件
    ASSERT_THAT(nums.size(), AllOf(Ge(2), Le(10000))); // 2 <= nums.length <= 10^4
    for (int n : nums) {
        ASSERT_THAT(n, AllOf(Ge(-1000000000), Le(1000000000))); // -10^9 <= nums[i] <= 10^9
    }
    ASSERT_THAT(target, AllOf(Ge(-1000000000), Le(1000000000))); // -10^9 <= target <= 10^9

    // 验证目标函数
    Solution solution;
    auto res{solution.twoSum(nums, target)};
    ASSERT_EQ(2, res.size());
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
