#include "test.hpp"
#include "solution.hpp"

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
