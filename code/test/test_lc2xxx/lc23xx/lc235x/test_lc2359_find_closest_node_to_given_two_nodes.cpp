/*
 * Time : 2025-05-30 21:17:28
 * URL  :
 * https://leetcode.cn/problems/find-closest-node-to-given-two-nodes/description/?envType=daily-questionURL_STRenvId=2025-05-30
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc2xxx/lc23xx/lc235x/lc2359_find_closest_node_to_given_two_nodes.h"

using namespace std;

class TEST_LC2359 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2359_FindClosestNodeToGivenTwoNodes *> m_testList;
    void RunTest(vector<int> &edges, int node1, int node2, int expect);
};

void TEST_LC2359::SetUp()
{
    m_testList.push_back(new LC2359_FindClosestNodeToGivenTwoNodes());
}

void TEST_LC2359::TearDown()
{
    for (LC2359_FindClosestNodeToGivenTwoNodes *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2359::RunTest(vector<int> &edges, int node1, int node2, int expect)
{
    for (LC2359_FindClosestNodeToGivenTwoNodes *inst : m_testList) {
        EXPECT_EQ(expect, inst->closestMeetingNode(edges, node1, node2));
    }
}

TEST_F(TEST_LC2359, case1)
{
    vector<int> edges = {2, 2, 3, -1};
    int node1 = 0;
    int node2 = 1;
    int expect = 2;
    RunTest(edges, node1, node2, expect);
}

TEST_F(TEST_LC2359, case2)
{
    vector<int> edges = {1, 2, -1};
    int node1 = 0;
    int node2 = 2;
    int expect = 2;
    RunTest(edges, node1, node2, expect);
}

TEST_F(TEST_LC2359, case3)
{
    vector<int> edges = {4, 3, 0, 5, 3, -1};
    int node1 = 4;
    int node2 = 0;
    int expect = 4;
    RunTest(edges, node1, node2, expect);
}

TEST_F(TEST_LC2359, case4)
{
    vector<int> edges = {4, 4, 4, 5, 1, 2, 2};
    int node1 = 1;
    int node2 = 1;
    int expect = 1;
    RunTest(edges, node1, node2, expect);
}

TEST_F(TEST_LC2359, case5)
{
    vector<int> edges = {4, 4, 8, -1, 9, 8, 4, 4, 1, 1};
    int node1 = 5;
    int node2 = 6;
    int expect = 1;
    RunTest(edges, node1, node2, expect);
}
