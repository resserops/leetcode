#include <vector>

class Solution {
public:
    int findSmallestInteger(std::vector<int>& nums, int value) {
        std::vector<int> count(value);
        for (int n : nums) {
            int rem{n % value};
            if (rem < 0) {
                rem += value;
            }
            ++count[rem];
        }
        int min_pos = 0;
        for (int i{1}; i < count.size(); ++i) {
            if (count[i] < count[min_pos]) {
                min_pos = i;
            }
        }
        return count[min_pos] * value + min_pos;
    }
};
