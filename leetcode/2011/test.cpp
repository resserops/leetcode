#include "test.hpp"
#include "solution.hpp"

using namespace testing;
namespace {
using SolutionList = std::tuple<approach1::Solution, approach2::Solution>;
struct TestCase {
    TestCase(const YAML::Node &node) {
        Decode(node["input"]["operations"], input.operations);
        Decode(node["expected"], expected);
    }
    struct {
        std::vector<std::string> operations;
    } input;
    int expected;
};

template <typename Solution>
void Expect(const std::vector<std::string> &operations, const int expected) {
    // 检查约束条件
    ASSERT_THAT(operations.size(), AllOf(Ge(1), Le(100))); // 1 <= operations.length <= 100
    for (const auto &op : operations) {                    // operations[i] will be either "++X", "X++", "--X", or "X--"
        ASSERT_THAT(op, AnyOf(Eq("++X"), Eq("X++"), Eq("--X"), Eq("X--")));
    }

    // 测试目标函数
    Solution solution;
    EXPECT_EQ(solution.finalValueAfterOperations(operations), expected);
}

template <typename Solution>
void Expect(const TestCase &tc) {
    Expect<Solution>(tc.input.operations, tc.expected);
}

TEST_Y(LeetCode2011, Example1);
TEST_Y(LeetCode2011, Example2);
TEST_Y(LeetCode2011, Example3);
} // namespace
