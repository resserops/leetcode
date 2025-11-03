#pragma once
#include <algorithm>
#include <string>
#include <vector>

// 方法1：模拟
namespace approach1 {
struct Solution {
    static int finalValueAfterOperations(const std::vector<std::string> &operations) {
        int res{0};
        for (const auto &op : operations) {
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

// 方法2：计数 + 数学推导
namespace approach2 {
struct Solution {
    static int finalValueAfterOperations(const std::vector<std::string> &operations) {
        auto isInc{[](const std::string &op) { return op[1] == '+'; }};
        return 2 * std::ranges::count_if(operations, isInc) - operations.size();
    }
};
} // namespace approach2
