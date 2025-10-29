#include <string>

// 方法1：双指针
struct Solution {
    static bool isSubsequence(const std::string &s, const std::string &t) {
        std::size_t ss{s.size()}, ts{t.size()};
        if (s.size() > t.size()) {
            return false;
        }
        std::size_t si{0};
        for (std::size_t ti{0}; si < ss && ti < ts; ++ti) {
            if (s[si] == t[ti]) {
                ++si;
            }
        }
        return si == ss;
    }
};
