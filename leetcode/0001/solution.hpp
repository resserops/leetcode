#include <cstdlib>
#include <unordered_map>
#include <vector>

// 方法1：哈希表
struct Solution {
    static std::vector<int> twoSum(const std::vector<int> &nums, int target) {
        std::unordered_map<int, int> hash;
        for (std::size_t i{0}; i < nums.size(); ++i) {
            auto it{hash.find(nums[i])};
            if (it != hash.end()) {
                return {it->second, static_cast<int>(i)};
            }
            hash[target - nums[i]] = i;
        }
        std::abort();
    }
};
