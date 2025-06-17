/*
 * Time : 2025-06-18 00:22:48
 * URL  :
 * https://leetcode.cn/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-questionURL_STRenvId=2025-06-18
 */

#include <vector>

#include "gtest/gtest.h"
#include "lc2966_divide_array_into_arrays_with_max_difference.h"

using namespace std;

class TEST_LC2966 : public testing::Test {
protected:
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override;
    void TearDown() override;

    vector<LC2966_DivideArrayIntoArraysWithMaxDifference*> m_testList;
    void RunTest(vector<int>& nums, int k, const vector<vector<int>>& expect);
};

void TEST_LC2966::SetUp()
{
    m_testList.push_back(new LC2966_DivideArrayIntoArraysWithMaxDifference());
}

void TEST_LC2966::TearDown()
{
    for (LC2966_DivideArrayIntoArraysWithMaxDifference* inst : m_testList) {
        delete inst;
    }
}

void TEST_LC2966::RunTest(vector<int>& nums, int k, const vector<vector<int>>& expect)
{
    for (LC2966_DivideArrayIntoArraysWithMaxDifference* inst : m_testList) {
        vector<vector<int>> result = inst->divideArray(nums, k);
        ASSERT_EQ(expect.size(), result.size());
        for (uint32_t i = 0; i < expect.size(); i++) {
            for (uint32_t j = 0; j < expect[i].size(); j++) {
                EXPECT_EQ(expect[i][j], result[i][j]);
            }
        }
    }
}

TEST_F(TEST_LC2966, case1)
{
    vector<int> nums = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    int k = 2;
    const vector<vector<int>> expect = {{1, 1, 3}, {3, 4, 5}, {7, 8, 9}};
    RunTest(nums, k, expect);
}

TEST_F(TEST_LC2966, case2)
{
    vector<int> nums = {2, 4, 2, 2, 5, 2};
    int k = 2;
    const vector<vector<int>> expect = {};
    RunTest(nums, k, expect);
}
