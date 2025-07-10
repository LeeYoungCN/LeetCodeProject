/*
 * Time : 2025-05-26 10:28:20
 * URL  :
 * https://leetcode.cn/problems/largest-color-value-in-a-directed-graph/description/?envType=daily-questionURL_STRenvId=2025-05-26
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc18xx/lc1847_largest_color_value_in_a_directed_graph.h"

using namespace std;

class TEST_LC1847 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC1847_LargestColorValueInADirectedGraph *> m_testList;
    void RunTest(string colors, vector<vector<int>> &edges, int expect);
};

void TEST_LC1847::SetUp()
{
    m_testList.push_back(new LC1847_LargestColorValueInADirectedGraph_DFS());
    m_testList.push_back(new LC1847_LargestColorValueInADirectedGraph_BFS());
}

void TEST_LC1847::TearDown()
{
    for (LC1847_LargestColorValueInADirectedGraph *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC1847::RunTest(string colors, vector<vector<int>> &edges, int expect)
{
    for (LC1847_LargestColorValueInADirectedGraph *inst : m_testList) {
        EXPECT_EQ(expect, inst->largestPathValue(colors, edges));
    }
}

TEST_F(TEST_LC1847, case1)
{
    string colors = "abaca";
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {3, 4}};
    RunTest(colors, edges, 3);
}

TEST_F(TEST_LC1847, case2)
{
    string colors = "a";
    vector<vector<int>> edges = {{0, 0}};
    RunTest(colors, edges, -1);
}

TEST_F(TEST_LC1847, case3)
{
    string colors = "nnllnzznn";
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {2, 4}, {3, 5}, {4, 6}, {3, 6}, {5, 6}, {6, 7}, {7, 8}};
    RunTest(colors, edges, 5);
}

TEST_F(TEST_LC1847, case4)
{
    string colors = "bbbhb";
    vector<vector<int>> edges = {{0, 2}, {3, 0}, {1, 3}, {4, 1}};
    RunTest(colors, edges, 4);
}

TEST_F(TEST_LC1847, case5)
{
    string colors = "hhqhuqhqff";
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {2, 3}, {3, 4}, {3, 5}, {5, 6}, {2, 7}, {6, 7}, {7, 8}, {3, 8}, {5, 8}, {8, 9}, {3, 9}, {6, 9}};
    RunTest(colors, edges, 3);
}
