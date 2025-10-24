#include <algorithm>
#include <ranges>
#include <vector>

// 方法1：枚举 + 二分查找 + 数学推导
struct Solution {
    static int maxFrequency(std::vector<int> nums, int k, int numOperations) {
        std::ranges::sort(nums);
        int fMax{0};
        // 枚举每个候选数cn
        for (std::size_t i{0}; i < nums.size(); ++i) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            // 只有nums中的数n及n±k，可能达到最大频率
            for (int cn : {nums[i] - k, nums[i], nums[i] + k}) {
                if (cn < nums.front() || cn > nums.back()) {
                    continue;
                }
                // 二分法计算可通过操作变为cn的数范围[l, r)
                auto l{std::ranges::lower_bound(nums, cn - k)};
                auto r{std::upper_bound(l, nums.end(), cn + k)};
                // 可通过操作变为cn的数，即cn的频率上界
                int f{static_cast<int>(r - l)};
                if (f <= 0) {
                    continue;
                }
                // 二分法计算重复cn的范围[repl, repr)，这些数不需要操作就等于cn
                auto repl{std::lower_bound(l, r, cn)};
                auto repr{std::upper_bound(repl, r, cn)};
                // 考虑操作次数约束
                f = std::min(f, static_cast<int>(repr - repl) + numOperations);
                fMax = std::max(fMax, f);
            }
        }
        return fMax;
    }
};
