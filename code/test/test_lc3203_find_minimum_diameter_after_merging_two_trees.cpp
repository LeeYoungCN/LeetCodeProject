/*
 * Time : 2025-05-29 14:32:49
 * URL  : https://leetcode.cn/problems/find-minimum-diameter-after-merging-two-trees/
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc3203_find_minimum_diameter_after_merging_two_trees.h"

using namespace std;

class TEST_LC3203 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3203_FindMinimumDiameterAfterMergingTwoTrees*> m_testList;
    void RunTest(vector<vector<int32_t>>& edges1, vector<vector<int32_t>>& edges2, int32_t expect);
};

void TEST_LC3203::SetUp()
{
    m_testList.push_back(new LC3203_FindMinimumDiameterAfterMergingTwoTrees());
}

void TEST_LC3203::TearDown()
{
    for (LC3203_FindMinimumDiameterAfterMergingTwoTrees* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3203::RunTest(vector<vector<int32_t>>& edges1, vector<vector<int32_t>>& edges2, int32_t expect)
{
    for (LC3203_FindMinimumDiameterAfterMergingTwoTrees* inst : m_testList) {
        EXPECT_EQ(expect, inst->minimumDiameterAfterMerge(edges1, edges2));
    }
}

TEST_F(TEST_LC3203, case1)
{
    vector<vector<int32_t>> edges1 = {{0, 1}, {0, 2}, {0, 3}};
    vector<vector<int32_t>> edges2 = {{0, 1}};
    int32_t expect = 3;
    RunTest(edges1, edges2, expect);
}

TEST_F(TEST_LC3203, case2)
{
    vector<vector<int32_t>> edges1 = {{0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}};
    vector<vector<int32_t>> edges2 = {{0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}};
    int32_t expect = 5;
    RunTest(edges1, edges2, expect);
}

TEST_F(TEST_LC3203, case3)
{
    vector<vector<int32_t>> edges1 = {{0, 1}};
    vector<vector<int32_t>> edges2 = {{0, 1}};
    int32_t expect = 3;
    RunTest(edges1, edges2, expect);
}

TEST_F(TEST_LC3203, case4)
{
    vector<vector<int32_t>> edges1 = {{0, 1}, {2, 0}, {3, 2}, {3, 6}, {8, 7}, {4, 8}, {5, 4}, {3, 5}, {3, 9}};
    vector<vector<int32_t>> edges2 = {{0, 1}, {0, 2}, {0, 3}};
    int32_t expect = 7;
    RunTest(edges1, edges2, expect);
}
