#include <string>

// 方法1：双指针
struct Solution {
    static bool isSubsequence(const std::string &s, const std::string &t) {
        std::size_t ss{s.size()}, ts{t.size()};
        if (ss > ts) {
            return false;
        }
        std::size_t si{0}, ti{0};
        while (si < ss && ti < ts) {
            if (s[si] == t[ti]) {
                ++si;
            }
            ++ti;
        }
        return si == ss;
    }
};
