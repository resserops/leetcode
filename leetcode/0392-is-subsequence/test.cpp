#include "solution.hpp"
#include "gtest/gtest.h"

TEST(LeetCode_0392, Case1) {
    EXPECT_TRUE(Solution{}.isSubsequence("abc", "ahbgdc"));
    EXPECT_FALSE(Solution{}.isSubsequence("axc", "ahbgdc"));
}
