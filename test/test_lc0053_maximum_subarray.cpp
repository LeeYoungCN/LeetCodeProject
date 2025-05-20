/*
 * Time : 2025-05-20 01:28:53
 * URL  : https://leetcode.cn/problems/maximum-subarray/description/
 */

#include <vector>
#include "gtest/gtest.h"
#include "lc0053_maximum_subarray.h"

using namespace std;

class TEST_LC0053 : public testing::Test {
    protected:
        LC0053_MaximumSubarray m_test;
        void RunTest(vector<int>& nums, int expectResult);
};
    
void TEST_LC0053::RunTest(vector<int>& nums, int expectResult)
{
    EXPECT_EQ(expectResult, m_test.maxSubArray(nums));
}

TEST_F(TEST_LC0053, case1)
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    RunTest(nums, 6);
}

TEST_F(TEST_LC0053, case2)
{
    vector<int> nums = {1};
    RunTest(nums, 1);
}

TEST_F(TEST_LC0053, case3)
{
    vector<int> nums = {5, 4, -1, 7, 8};
    RunTest(nums, 23);
}
