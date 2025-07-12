/*
 * Time : 2025-05-29 00:11:51
 * URL  :
 * https://leetcode.cn/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/description/?envType=daily-questionURL_STRenvId=2025-05-29
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc3xxx/lc33xx/lc337x/lc3373_maximize_the_number_of_target_nodes_after_connecting_trees_ii.h"

using namespace std;

class TEST_LC3373 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC3373_MaximizeTheNumberOfTargetNodesAfterConnectingTreesII*> m_testList;
    void RunTest(vector<vector<int32_t>>& edges1, vector<vector<int32_t>>& edges2, vector<int32_t> expect);
};

void TEST_LC3373::SetUp()
{
    m_testList.push_back(new LC3373_MaximizeTheNumberOfTargetNodesAfterConnectingTreesII());
}

void TEST_LC3373::TearDown()
{
    for (LC3373_MaximizeTheNumberOfTargetNodesAfterConnectingTreesII* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC3373::RunTest(vector<vector<int32_t>>& edges1, vector<vector<int32_t>>& edges2, vector<int32_t> expect)
{
    for (LC3373_MaximizeTheNumberOfTargetNodesAfterConnectingTreesII* inst : m_testList) {
        ASSERT_NE(inst, nullptr);

        vector<int32_t> result = inst->maxTargetNodes(edges1, edges2);
        ASSERT_EQ(expect.size(), result.size());

        for (size_t i = 0; i < expect.size(); i++) {
            EXPECT_EQ(expect.at(i), result.at(i)) << "i = " << i;
        }
    }
}

TEST_F(TEST_LC3373, case1)
{
    vector<vector<int32_t>> edges1 = {{0, 1}, {0, 2}, {2, 3}, {2, 4}};
    vector<vector<int32_t>> edges2 = {{0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}};

    vector<int32_t> expect = {8, 7, 7, 8, 8};
    RunTest(edges1, edges2, expect);
}

TEST_F(TEST_LC3373, case2)
{
    vector<vector<int32_t>> edges1 = {{0, 1}, {0, 2}, {0, 3}, {0, 4}};
    vector<vector<int32_t>> edges2 = {{0, 1}, {1, 2}, {2, 3}};

    vector<int32_t> expect = {3, 6, 6, 6, 6};
    RunTest(edges1, edges2, expect);
}
