// https://leetcode.cn/problems/maximum-sum-circular-subarray/
#include <vector>
#include "gtest/gtest.h"
#include "lc0918_maximum_sum_circular_subarray.h"

using namespace std;

class TEST_LC0918 : public testing::Test {
    protected:
        LC0918Solution m_test;
        void RunTest(vector<int> &nums, int expectResult);
};

void TEST_LC0918::RunTest(vector<int>& nums, int expectResult)
{
    EXPECT_EQ(expectResult, m_test.maxSubarraySumCircular(nums));
}

TEST_F(TEST_LC0918, case1)
{
    vector<int> nums = {1, -2, 3, -2};
    RunTest(nums, 3);
}

TEST_F(TEST_LC0918, case2)
{
    vector<int> nums = {5,-3,5};
    RunTest(nums, 10);
}

TEST_F(TEST_LC0918, case3)
{
    vector<int> nums = {3,-2, 2,-3};
    RunTest(nums, 3);
}
    