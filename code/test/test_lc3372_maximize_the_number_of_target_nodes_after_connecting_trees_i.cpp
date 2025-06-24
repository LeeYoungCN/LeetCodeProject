/*
 * Time : 2025-05-28 14:14:32
 * URL  :
 * https://leetcode.cn/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description/?envType=daily-questionURL_STRenvId=2025-05-28
 */
#include <cstdint>
#include <vector>

#include "gtest/gtest.h"
#include "lc3372_maximize_the_number_of_target_nodes_after_connecting_trees_i.h"

using namespace std;

class TEST_LC3372 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3372_MaximizeTheNumberOfTargetNodesAfterConnectingTreesI*> m_testList;
    void RunTest(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k, vector<int> expect);
};

void TEST_LC3372::SetUp()
{
    m_testList.push_back(new LC3372_MaximizeTheNumberOfTargetNodesAfterConnectingTreesI());
}

void TEST_LC3372::TearDown()
{
    for (LC3372_MaximizeTheNumberOfTargetNodesAfterConnectingTreesI* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3372::RunTest(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k, vector<int> expect)
{
    for (LC3372_MaximizeTheNumberOfTargetNodesAfterConnectingTreesI* inst : m_testList) {
        ASSERT_NE(inst, nullptr);

        vector<int32_t> result = inst->maxTargetNodes(edges1, edges2, k);
        ASSERT_EQ(expect.size(), result.size());

        for (size_t i = 0; i < expect.size(); i++) {
            EXPECT_EQ(expect.at(i), result.at(i)) << "i = " << i;
        }
    }
}

TEST_F(TEST_LC3372, case1)
{
    vector<vector<int32_t>> edges1 = {{0, 1}, {0, 2}, {2, 3}, {2, 4}};
    vector<vector<int32_t>> edges2 = {{0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}};
    int32_t k = 2;
    vector<int32_t> expect = {9, 7, 9, 8, 8};
    RunTest(edges1, edges2, k, expect);
}

TEST_F(TEST_LC3372, case2)
{
    vector<vector<int32_t>> edges1 = {{0, 1}, {0, 2}, {0, 3}, {0, 4}};
    vector<vector<int32_t>> edges2 = {{0, 1}, {1, 2}, {2, 3}};
    int32_t k = 1;
    vector<int32_t> expect = {6, 3, 3, 3, 3};
    RunTest(edges1, edges2, k, expect);
}
