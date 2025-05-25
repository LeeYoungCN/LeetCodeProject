/*
 * Time : 2025-05-23 01:03:47
 * URL  : https://leetcode.cn/problems/find-the-maximum-sum-of-node-values/description/?envType=daily-questionURL_STRenvId=2025-05-23
 */
#include <vector>
#include "gtest/gtest.h"
#include "lc3068_find_the_maximum_sum_of_node_values.h"

using namespace std;

class TEST_LC3068 : public testing::Test {
    protected:
        static void SetUpTestSuite() {}
        static void TearDownTestSuite() {}
        void SetUp() override;
        void TearDown() override;

        vector<LC3068_FindTheMaximumSumOfNodeValues *> m_testList;
        void RunTest(vector<int>& nums, int k, vector<vector<int>>& edges,
                     long long expectResult);
};

void TEST_LC3068::SetUp()
{
    m_testList.push_back(new LC3068_FindTheMaximumSumOfNodeValues_Greedy());
}

void TEST_LC3068::TearDown()
{
    for (LC3068_FindTheMaximumSumOfNodeValues *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3068::RunTest(vector<int>& nums, int k, vector<vector<int>>& edges,
                          long long expectResult)
{
    for (LC3068_FindTheMaximumSumOfNodeValues *inst : m_testList) {
        EXPECT_EQ(expectResult, inst->maximumValueSum(nums, k, edges));
    }
}

TEST_F(TEST_LC3068, case1)
{
    vector<int> nums = {1, 2, 1};
    int k = 3;
    vector<vector<int>> edges = {{0, 1}, {0, 2}};
    RunTest(nums, k, edges, 6);
}

TEST_F(TEST_LC3068, case2)
{
    vector<int> nums = {2, 3};
    int k = 7;
    vector<vector<int>> edges = {{0, 1}};
    RunTest(nums, k, edges, 9);
}

TEST_F(TEST_LC3068, case3)
{
    vector<int> nums = {7, 7, 7, 7, 7, 7};
    int k = 3;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}};
    RunTest(nums, k, edges, 42);
}
