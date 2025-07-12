/*
 * Time : 2025-05-29 17:35:45
 * URL  : https://leetcode.cn/problems/minimum-height-trees/
 */
#include <algorithm>
#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc03xx/lc031x/lc0310_minimum_height_trees.h"

using namespace std;

class TEST_LC0310 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0310_MinimumHeightTrees *> m_testList;
    void RunTest(int32_t n, vector<vector<int32_t>> &edges, vector<int32_t> expect);
};

void TEST_LC0310::SetUp()
{
    m_testList.push_back(new LC0310_MinimumHeightTrees_DFS());
    m_testList.push_back(new LC0310_MinimumHeightTrees_BFS());
    m_testList.push_back(new LC0310_MinimumHeightTrees_TopologicalSort());
}

void TEST_LC0310::TearDown()
{
    for (LC0310_MinimumHeightTrees *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0310::RunTest(int32_t n, vector<vector<int32_t>> &edges, vector<int32_t> expect)
{
    for (LC0310_MinimumHeightTrees *inst : m_testList) {
        vector<int32_t> result = inst->findMinHeightTrees(n, edges);
        ASSERT_EQ(expect.size(), result.size());
        sort(expect.begin(), expect.end());
        sort(result.begin(), result.end());
        for (uint32_t i = 0; i < (uint32_t)expect.size(); i++) {
            EXPECT_EQ(expect.at(i), result.at(i)) << "i = " << i;
        }
    }
}

TEST_F(TEST_LC0310, case1)
{
    int32_t n = 4;
    vector<vector<int32_t>> edges = {{1, 0}, {1, 2}, {1, 3}};
    vector<int32_t> expect = {1};
    RunTest(n, edges, expect);
}

TEST_F(TEST_LC0310, case2)
{
    int32_t n = 6;
    vector<vector<int32_t>> edges = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    vector<int32_t> expect = {3, 4};
    RunTest(n, edges, expect);
}

TEST_F(TEST_LC0310, case3)
{
    int32_t n = 18;
    vector<vector<int32_t>> edges = {{0, 1},
                                     {1, 2},
                                     {2, 3},
                                     {3, 4},
                                     {3, 5},
                                     {5, 6},
                                     {2, 7},
                                     {0, 8},
                                     {2, 9},
                                     {4, 10},
                                     {2, 11},
                                     {4, 12},
                                     {8, 13},
                                     {12, 14},
                                     {4, 15},
                                     {13, 16},
                                     {16, 17}};
    vector<int32_t> expect = {1};
    RunTest(n, edges, expect);
}

TEST_F(TEST_LC0310, case4)
{
    int32_t n = 1;
    vector<vector<int32_t>> edges = {};
    vector<int32_t> expect = {0};
    RunTest(n, edges, expect);
}
