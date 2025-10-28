#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        if (s.size() > t.size()) {
            return false;
        }
        std::size_t pos{0};
        for (char ch : s) {
            pos = t.find(ch, pos);
            if (pos == t.npos) {
                return false;
            }
            ++pos;
        }
        return true;
    }
};
