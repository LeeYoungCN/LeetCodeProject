/*
 * Time : 2025-05-24 17:13:11
 * URL  : https://leetcode.cn/problems/maximum-score-after-applying-operations-on-a-tree/description/
 */
#include <cstdint>
#include <vector>

#include "gtest/gtest.h"
#include "lc2925_maximum_score_after_applying_operations_on_a_tree.h"

using namespace std;

class TEST_LC2925 : public testing::Test {
    protected:
        static void SetUpTestSuite() {};
        static void TearDownTestSuite() {};
        void SetUp() override;
        void TearDown() override;

        vector<LC2925_MaximumScoreAfterApplyingOperationsOnATree*> m_testList;
        void RunTest(std::vector<std::vector<int>>& edges, std::vector<int>& values, int64_t expect);
};

void TEST_LC2925::SetUp()
{
    m_testList.push_back(new LC2925_MaximumScoreAfterApplyingOperationsOnATree());
}

void TEST_LC2925::TearDown()
{
    for (LC2925_MaximumScoreAfterApplyingOperationsOnATree* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2925::RunTest(std::vector<std::vector<int>>& edges, std::vector<int>& values, int64_t expect)
{
    for (LC2925_MaximumScoreAfterApplyingOperationsOnATree* inst : m_testList) {
        EXPECT_EQ(expect, inst->maximumScoreAfterOperations(edges, values));
    }
}

TEST_F(TEST_LC2925, case1)
{
    std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {0, 4}};
    std::vector<int> values = {10, 1, 1, 1, 1};
    RunTest(edges, values, 10);
}

TEST_F(TEST_LC2925, case2)
{
    std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {0, 4}};
    std::vector<int> values = {1, 1, 10, 1, 1};
    RunTest(edges, values, 13);
}

TEST_F(TEST_LC2925, case3)
{
    std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {2, 4}, {4, 5}};
    std::vector<int> values = {5, 2, 5, 2, 1, 1};
    RunTest(edges, values, 11);
}

TEST_F(TEST_LC2925, case4)
{
    std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
    std::vector<int> values = {20, 10, 9, 7, 4, 3, 5};
    RunTest(edges, values, 40);
}

TEST_F(TEST_LC2925, case5)
{
    std::vector<std::vector<int>> edges = {{0, 1}};
    std::vector<int> values = {1, 2};
    RunTest(edges, values, 2);
}

TEST_F(TEST_LC2925, case6)
{
    std::vector<std::vector<int>> edges = {{7, 0}, {3, 1}, {6, 2}, {4, 3}, {4, 5}, {4, 6}, {4, 7}};
    std::vector<int> values = {2, 16, 23, 17, 22, 21, 8, 6};
    RunTest(edges, values, 113);
}
