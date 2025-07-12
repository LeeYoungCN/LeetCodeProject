/*
 * Time : 2025-06-20 22:02:04
 * URL  : https://leetcode.cn/problems/unique-paths-ii/description/?envType=problem-list-v2&envId=dynamic-programming
 */

#include <vector>

#include "gtest/gtest.h"
#include "lc0xxx/lc00xx/lc006x/lc0063_unique_paths_ii.h"

using namespace std;

class TEST_LC0063 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0063_UniquePathsII*> m_testList;
    void RunTest(vector<vector<int>>& obstacleGrid, const int& expect);
};

void TEST_LC0063::SetUp()
{
    m_testList.push_back(new LC0063_UniquePathsII());
}

void TEST_LC0063::TearDown()
{
    for (LC0063_UniquePathsII* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0063::RunTest(vector<vector<int>>& obstacleGrid, const int& expect)
{
    for (LC0063_UniquePathsII* inst : m_testList) {
        int result = inst->uniquePathsWithObstacles(obstacleGrid);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC0063, case1)
{
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    const int expect = 2;
    RunTest(obstacleGrid, expect);
}

TEST_F(TEST_LC0063, case2)
{
    vector<vector<int>> obstacleGrid = {{0, 1}, {0, 0}};
    const int expect = 1;
    RunTest(obstacleGrid, expect);
}

TEST_F(TEST_LC0063, case3)
{
    vector<vector<int>> obstacleGrid = {{1, 0}};
    const int expect = 0;
    RunTest(obstacleGrid, expect);
}
