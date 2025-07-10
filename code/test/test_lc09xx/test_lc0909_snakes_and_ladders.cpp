/*
 * Time : 2025-05-31 00:34:07
 * URL  : https://leetcode.cn/problems/snakes-and-ladders/description/?envType=daily-questionURL_STRenvId=2025-05-31
 */
#include <vector>

#include "gtest/gtest.h"
#include "lc09xx/lc0909_snakes_and_ladders.h"

using namespace std;

class TEST_LC0909 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0909_SnakesAndLadders *> m_testList;
    void RunTest(vector<vector<int>> &board, int expect);
};

void TEST_LC0909::SetUp()
{
    m_testList.push_back(new LC0909_SnakesAndLadders_Path());
    m_testList.push_back(new LC0909_SnakesAndLadders_XY());
}

void TEST_LC0909::TearDown()
{
    for (LC0909_SnakesAndLadders *inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0909::RunTest(vector<vector<int>> &board, int expect)
{
    for (LC0909_SnakesAndLadders *inst : m_testList) {
        EXPECT_EQ(expect, inst->snakesAndLadders(board));
    }
}

TEST_F(TEST_LC0909, case1)
{
    vector<vector<int>> board = {{-1, -1, -1, -1, -1, -1},
                                 {-1, -1, -1, -1, -1, -1},
                                 {-1, -1, -1, -1, -1, -1},
                                 {-1, 35, -1, -1, 13, -1},
                                 {-1, -1, -1, -1, -1, -1},
                                 {-1, 15, -1, -1, -1, -1}};
    int32_t expect = 4;
    RunTest(board, expect);
}

TEST_F(TEST_LC0909, case2)
{
    vector<vector<int>> board = {{-1, -1}, {-1, 3}};
    int32_t expect = 1;
    RunTest(board, expect);
}

TEST_F(TEST_LC0909, case3)
{
    vector<vector<int>> board = {{-1, -1}, {-1, 1}};
    int32_t expect = 1;
    RunTest(board, expect);
}

TEST_F(TEST_LC0909, case4)
{
    vector<vector<int>> board = {
        {2, -1, -1, -1, -1}, {-1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1}};
    int32_t expect = 4;
    RunTest(board, expect);
}
