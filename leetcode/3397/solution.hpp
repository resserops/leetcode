#pragma once
#include <algorithm>
#include <ranges>
#include <vector>

// 方法1：贪心
struct Solution {
    static int maxDistinctElements(std::vector<int> nums, int k) {
        std::ranges::sort(nums);
        int res{1}, prev{nums[0] - k};
        for (std::size_t i{1}; i < nums.size(); ++i) {
            if (nums[i] + k > prev) {
                // 每个数都取可能的最小值
                prev = std::max(prev + 1, nums[i] - k);
                ++res;
            }
        }
        return res;
    }
};
