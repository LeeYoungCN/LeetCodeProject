// https://leetcode.cn/problems/maximum-subarray/
#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = INT32_MIN;
        const uint32_t length = nums.size();
        // dp[i] 表示包含nums[i]时的从左到右最大子数组的大小
        vector<int> dp = vector<int>(length);
        for (uint32_t i = 0; i < length; i++) {
            if (i == 0) {
                dp[i] = nums[i];
            } else {
                dp[i] = max(0, dp[i - 1]) + nums[i];
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

class Test_Lc0053 : public testing::Test {
protected:
    Solution m_test;
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
