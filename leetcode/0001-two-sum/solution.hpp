#include <vector>
#include <unordered_map>
#include <cstdlib>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hash;
        for (int i{0}; i < nums.size(); ++i) {
            auto it = hash.find(nums[i]);
            if (it != hash.end()) {
                return {it->second, i};
            }
            hash[target - nums[i]] = i;
        }
        std::abort();
    }
};
