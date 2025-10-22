#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

// 方法1：枚举 + 二分查找
struct Solution {
    static int maxFrequency(std::vector<int> nums, int k, int numOperations) {
        std::ranges::sort(nums);
        int fMax{0};
        int i{nums.front()};
        for (size_t a{0}, b{0}; a < nums.size() + 1; ++a) {
            if (a < nums.size() && nums[a] == nums[b]) {
                continue;
            }
            int count = int(a - b);
            int limit = (a < nums.size()) ? nums[a] : nums.back() + 1;
            while (i < std::min(nums[b] + k + 1, limit)) {
                auto l{std::lower_bound(nums.begin(), nums.end(), i - k)};
                auto r{std::upper_bound(nums.begin(), nums.end(), i + k)};
                int f = std::min<int>(r - l, count + numOperations);
                fMax = std::max<int>(fMax, f);
                // std::cout << "i: " << i << " " <<r - l << " " << count + numOperations << " " << f << "\n";
                ++i;
                count = 0;
            }
            b = a;
        }
        return fMax;
    }
};
