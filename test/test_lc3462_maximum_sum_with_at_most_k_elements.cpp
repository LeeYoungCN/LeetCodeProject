/*
 * Time : 2025-06-02 03:20:20
 * URL  : https://leetcode.cn/problems/maximum-sum-with-at-most-k-elements/description/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc3462_maximum_sum_with_at_most_k_elements.h"

using namespace std;

class TEST_LC3462 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3462_MaximumSumWithAtMostKElements*> m_testList;
    void RunTest(std::vector<std::vector<int>>& grid, std::vector<int>& limits, int k, long long expect);
};

void TEST_LC3462::SetUp()
{
    m_testList.push_back(new LC3462_MaximumSumWithAtMostKElements_Sort());
    m_testList.push_back(new LC3462_MaximumSumWithAtMostKElements_NthElement());
}

void TEST_LC3462::TearDown()
{
    for (LC3462_MaximumSumWithAtMostKElements* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3462::RunTest(std::vector<std::vector<int>>& grid, std::vector<int>& limits, int k, long long expect)
{
    for (LC3462_MaximumSumWithAtMostKElements* inst : m_testList) {
        EXPECT_EQ(expect, inst->maxSum(grid, limits, k));
    }
}

TEST_F(TEST_LC3462, case1)
{
    std::vector<std::vector<int>> grid = {{1, 2}, {3, 4}};
    std::vector<int> limits = {1, 2};
    int k = 2;

    long long expect = 7;
    RunTest(grid, limits, k, expect);
}

TEST_F(TEST_LC3462, case2)
{
    std::vector<std::vector<int>> grid = {{5, 3, 7}, {8, 2, 6}};
    std::vector<int> limits = {2, 2};
    int k = 3;

    long long expect = 21;
    RunTest(grid, limits, k, expect);
}
