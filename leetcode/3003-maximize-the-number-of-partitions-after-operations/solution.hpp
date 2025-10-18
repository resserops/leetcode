#include <algorithm>
#include <bit>
#include <string>
#include <unordered_map>

class Solution {
public:
    int maxPartitionsAfterOperations(std::string s, int k) {
        std::unordered_map<uint64_t, int> memory;

        auto dfs = [&](this auto &&dfs, int i, unsigned int hash, bool changed) {
            if (i == s.size()) {
                return 1;
            }

            uint64_t status = static_cast<uint64_t>(i) << 32 | hash << 1 | changed;
            auto it{memory.find(status)};
            if (it != memory.end()) {
                return it->second;
            }

            int ofs{s[i] - 'a'};
            int bit{1 << ofs};
            int res;
            if (((hash & bit) == 0) && std::popcount(hash | bit) > k) {
                res = dfs(i + 1, bit, changed) + 1;
            } else {
                res = dfs(i + 1, hash | bit, changed);
            }
            if (changed) {
                return memory[status] = res;
            }

            for (int ofs_i{0}; ofs_i < 26; ++ofs_i) {
                if (ofs_i == ofs) {
                    continue;
                }
                int bit{1 << ofs_i};
                if (((hash & bit) == 0) && std::popcount(hash | bit) > k) {
                    res = std::max(res, dfs(i + 1, bit, true) + 1);
                } else {
                    res = std::max(res, dfs(i + 1, hash | bit, true));
                }
            }
            return memory[status] = res;
        };
        return dfs(0, 0, false);
    }
};
