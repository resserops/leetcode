#include <algorithm>
#include <string>
#include <vector>

// 方法1：模拟
namespace approach1 {
class Solution {
public:
    static int finalValueAfterOperations(const std::vector<std::string> &operations) {
        int res{0};
        for (const std::string &op : operations) {
            if (op[1] == '+') {
                ++res;
            } else {
                --res;
            }
        }
        return res;
    }
};
} // namespace approach1

// 方法2：加法计数
namespace approach2 {
class Solution {
public:
    static int finalValueAfterOperations(const std::vector<std::string> &operations) {
        auto is_inc{[](const std::string &op) { return op[1] == '+'; }};
        auto incs{std::count_if(operations.begin(), operations.end(), is_inc)};
        return 2 * incs - operations.size();
    }
};
} // namespace approach2
