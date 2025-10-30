#include "test.hpp"
#include "solution.hpp"

using namespace testing;
namespace {
using SolutionList = TypeList<Solution>;
struct TestCase {
    TestCase(const YAML::Node &node) {
        Decode(node["input"]["nums"], input.nums);
        Decode(node["input"]["target"], input.target);
        Decode(node["expected"], expected);
    }
    struct {
        std::vector<int> nums;
        int target;
    } input;
    std::vector<int> expected;
};

template <typename Solution>
void RunTest(const std::vector<int> &nums, const int target, const std::vector<int> &expected) {
    // 检查约束条件
    ASSERT_THAT(nums.size(), AllOf(Ge(2), Le(E<4>)));    // 2 <= nums.length <= 10^4
    ASSERT_THAT(nums, Each(AllOf(Ge(-E<9>), Le(E<9>)))); // -10^9 <= nums[i] <= 10^9
    ASSERT_THAT(target, AllOf(Ge(-E<9>), Le(E<9>)));     // -10^9 <= target <= 10^9
    // Only one valid answer exists
    // TODO(resserops): 补充检查

    // 验证目标函数
    Solution solution;
    auto res{solution.twoSum(nums, target)};
    ASSERT_EQ(2, res.size());
    if (res[0] > res[1]) {
        std::swap(res[0], res[1]);
    }
    EXPECT_EQ(res, expected);
}

template <typename Solution>
void RunTest(const TestCase &tc) {
    RunTest<Solution>(tc.input.nums, tc.input.target, tc.expected);
}

TEST_Y(LeetCode1, Example1);
TEST_Y(LeetCode1, Example2);
TEST_Y(LeetCode1, Example3);
} // namespace
