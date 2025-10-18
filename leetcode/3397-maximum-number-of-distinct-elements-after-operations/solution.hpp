#include <algorithm>
#include <vector>

class Solution {
public:
    int maxDistinctElements(std::vector<int> &nums, int k) {
        std::sort(nums.begin(), nums.end());
        int count = 1;
        int min_v = nums[0] - k + 1;
        for (int i{1}; i < nums.size(); ++i) {
            if (nums[i] + k >= min_v) {
                min_v = std::max(min_v, nums[i] - k) + 1;
                count++;
            }
        }
        return count;
    }
};
