#include "solution.hpp"
#include "gtest/gtest.h"

template <typename Solution>
void Expect(int expected, const std::vector<std::string> &operations) {
    Solution solution;
    EXPECT_EQ(expected, solution.finalValueAfterOperations(operations));
}

TEST(LeetCode2011, Example1) {
    const std::vector<std::string> operations{"--X", "X++", "X++"};
    Expect<approach1::Solution>(1, operations);
    Expect<approach2::Solution>(1, operations);
}

TEST(LeetCode2011, Example2) {
    const std::vector<std::string> operations{"++X", "++X", "X++"};
    Expect<approach1::Solution>(3, operations);
    Expect<approach2::Solution>(3, operations);
}

TEST(LeetCode2011, Example3) {
    const std::vector<std::string> operations{"X++", "++X", "--X", "X--"};
    Expect<approach1::Solution>(0, operations);
    Expect<approach2::Solution>(0, operations);
}
