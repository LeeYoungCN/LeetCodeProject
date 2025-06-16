/*
 * Time : 2025-06-16 16:45:34
 * URL  : https://leetcode.cn/problems/search-a-2d-matrix/description/?envType=problem-list-v2URL_STRenvId=binary-search
 */

#include <cstdint>
#include <vector>

#include "gtest/gtest.h"
#include "lc0074_search_a_2d_matrix.h"

using namespace std;

class TEST_LC0074 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC0074_SearchA2dMatrix*> m_testList;
    void RunTest(vector<vector<int>>& matrix, int target, const bool& expect);
};

void TEST_LC0074::SetUp()
{
    m_testList.push_back(new LC0074_SearchA2dMatrix());
}

void TEST_LC0074::TearDown()
{
    for (LC0074_SearchA2dMatrix* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC0074::RunTest(vector<vector<int>>& matrix, int target, const bool& expect)
{
    for (LC0074_SearchA2dMatrix* inst : m_testList) {
        bool result = inst->searchMatrix(matrix, target);
        EXPECT_EQ(expect, result);
    }
}

TEST_F(TEST_LC0074, case1)
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int32_t target = 3;

    const bool expect = true;
    RunTest(matrix, target, expect);
}

TEST_F(TEST_LC0074, case2)
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int32_t target = 13;

    const bool expect = false;
    RunTest(matrix, target, expect);
}
