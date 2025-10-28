#include "test.hpp"
#include "solution.hpp"

using namespace testing;
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
    // 检查约束条件
    ASSERT_THAT(nums.size(), AllOf(Ge(1), Le(100000))); // 1 <= nums.length <= 10^5
    for (int n : nums) {                                // 1 <= nums[i] <= 10^5
        ASSERT_THAT(n, AllOf(Ge(1), Le(100000)));
    }
    ASSERT_THAT(k, AllOf(Ge(0), Le(100000)));                  // 0 <= k <= 10^5
    ASSERT_THAT(numOperations, AllOf(Ge(0), Le(nums.size()))); // 0 <= numOperations <= nums.length

    // 测试目标函数
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
