#include <string>

struct Solution {
    bool hasSameDigits(std::string s) {
        while (s.size() > 2) {
            for (std::size_t i{0}; i < s.size() - 1; ++i) {
                s[i] = ((s[i] - '0') + (s[i + 1] - '0')) % 10 + '0';
            }
            s.pop_back();
        }
        return s[0] == s[1];
    }
};
