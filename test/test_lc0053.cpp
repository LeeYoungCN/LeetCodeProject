// https://leetcode.cn/problems/maximum-subarray/
#include <vector>
#include "gtest/gtest.h"
#include "lc0053_maximum_subarray.h"

using namespace std;

class Test_Lc0053 : public testing::Test {
    protected:
        Lc0053Solution m_test;
        void RunTest(vector<int>& nums, int expectResult);
};
    
void Test_Lc0053::RunTest(vector<int>& nums, int expectResult)
{
    EXPECT_EQ(expectResult, m_test.maxSubArray(nums));
}

TEST_F(Test_Lc0053, Case1)
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    RunTest(nums, 6);
}

TEST_F(Test_Lc0053, Case2)
{
    vector<int> nums = {1};
    RunTest(nums, 1);
}

TEST_F(Test_Lc0053, Case3)
{
    vector<int> nums = {5, 4, -1, 7, 8};
    RunTest(nums, 23);
}
