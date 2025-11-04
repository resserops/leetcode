#include "solution.hpp"
#include "test_utility.hpp"

#include <ranges>

using namespace testing;
namespace {
using SolutionList = TypeList<Solution>;
struct TestCase {
    TestCase(const YAML::Node &node) {
        Decode(node["input"]["l1"], input.l1);
        Decode(node["input"]["l2"], input.l2);
        Decode(node["expected"], expected);
    }
    struct {
        std::vector<int> l1;
        std::vector<int> l2;
    } input;
    std::vector<int> expected;
};

template <typename Solution>
void RunTest(const std::vector<int> &l1, const std::vector<int> &l2, const std::vector<int> &expceted) {
    // 检查约束条件
    auto assertList = [](const std::vector<int> &l) {
        // The number of nodes in each linked list is in the range [1, 100]
        ASSERT_THAT(l.size(), AllOf(Ge(1), Le(100)));
        ASSERT_THAT(l, Each(AllOf(Ge(0), Le(9)))); // 0 <= Node.val <= 9
        // It is guaranteed that the list represents a number that does not have leading zeros
        if (l.size() > 1) {
            ASSERT_GT(l.back(), 0);
        }
    };
    assertList(l1);
    assertList(l2);

    // 验证目标函数
    Solution solution;
    EXPECT_EQ(FromList(solution.addTwoNumbers(ToList(l1), ToList(l2))), expceted);
    ListNode::Clear();
}

template <typename Solution>
void RunTest(const TestCase &tc) {
    RunTest<Solution>(tc.input.l1, tc.input.l2, tc.expected);
}

TEST_Y(LeetCode2, Example1);
TEST_Y(LeetCode2, Example2);
TEST_Y(LeetCode2, Example3);
} // namespace
