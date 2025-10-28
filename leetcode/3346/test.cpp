#include "test.hpp"
#include "solution.hpp"

namespace {
using SolutionList = std::tuple<Solution>;
struct TestCase {
    TestCase(const YAML::Node &node) {
        Decode(node["input"]["nums"], input.nums);
        Decode(node["input"]["k"], input.k);
        Decode(node["input"]["numOperations"], input.numOperations);
        Decode(node["expected"], expected);
    }
    struct {
        std::vector<int> nums;
        int k;
        int numOperations;
    } input;
    int expected;
};

template <typename Solution>
void Expect(const std::vector<int> &nums, const int k, const int numOperations, const int expected) {
    Solution solution;
    EXPECT_EQ(solution.maxFrequency(nums, k, numOperations), expected);
}

template <typename Solution>
void Expect(const TestCase &tc) {
    Expect<Solution>(tc.input.nums, tc.input.k, tc.input.numOperations, tc.expected);
}

TEST_Y(LeetCode3346, Example1);
TEST_Y(LeetCode3346, Example2);
TEST_Y(LeetCode3346, Regression1);
TEST_Y(LeetCode3346, Regression2);
TEST_Y(LeetCode3346, Regression3);
TEST_Y(LeetCode3346, Regression4);
TEST_Y(LeetCode3346, Regression5);
TEST_Y(LeetCode3346, Regression6);
TEST_Y(LeetCode3346, Regression7);
} // namespace
