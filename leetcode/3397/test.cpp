#include "solution.hpp"
#include "test_utility.hpp"

using namespace testing;
namespace {
using SolutionList = TypeList<Solution>;
struct TestCase {
    TestCase(const YAML::Node &node) {
        Decode(node["input"]["nums"], input.nums);
        Decode(node["input"]["k"], input.k);
        Decode(node["expected"], expected);
    }
    struct {
        std::vector<int> nums;
        int k;
    } input;
    int expected;
};

template <typename Solution>
void RunTest(const std::vector<int> &nums, const int k, const int expected) {
    // 检查约束条件
    ASSERT_THAT(nums.size(), AllOf(Ge(1), Le(E<5>))); // 1 <= nums.length <= 10^5
    ASSERT_THAT(nums, Each(AllOf(Ge(1), Le(E<9>))));  // 1 <= nums[i] <= 10^9
    ASSERT_THAT(k, AllOf(Ge(1), Le(E<9>)));           // 0 <= k <= 10^9

    // 测试目标函数
    Solution solution;
    EXPECT_EQ(solution.maxDistinctElements(nums, k), expected);
}

template <typename Solution>
void RunTest(const TestCase &tc) {
    RunTest<Solution>(tc.input.nums, tc.input.k, tc.expected);
}

TEST_Y(LeetCode3397, Example1);
TEST_Y(LeetCode3397, Example2);
} // namespace
