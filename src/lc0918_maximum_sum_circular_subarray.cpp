// https://leetcode.cn/problems/maximum-sum-circular-subarray/
#include <cstdint>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        const uint32_t numCnt = nums.size();
        int sum = 0;
        vector<int> maxSubArray = vector<int>(numCnt);
        vector<int> minSubArray = vector<int>(numCnt);
        int maxSubArraySum = INT32_MIN;
        int minSubArraySum = __INT32_MAX__;
        for (uint32_t i = 0; i < numCnt; i++) {
            sum += nums[i];
            if (i == 0) {
                maxSubArray[i] = nums[i];
                minSubArray[i] = nums[i];
            } else {
                maxSubArray[i] = max(maxSubArray[i - 1], 0) + nums[i];
                minSubArray[i] = min(minSubArray[i - 1], 0) + nums[i];
            }
            maxSubArraySum = max(maxSubArraySum, maxSubArray[i]);
            minSubArraySum = min(minSubArraySum, minSubArray[i]);
        }
        return (sum == minSubArraySum ? maxSubArraySum : max(maxSubArraySum, sum - minSubArraySum));
    }
};

class Test_Lc0918 : public testing::Test {
protected:
    Solution m_test;
    void RunTest(vector<int> &nums, int expectResult);
};

void Test_Lc0918::RunTest(vector<int>& nums, int expectResult)
{
    EXPECT_EQ(expectResult, m_test.maxSubarraySumCircular(nums));
}

TEST_F(Test_Lc0918, Case1)
{
    vector<int> nums = {1, -2, 3, -2};
    RunTest(nums, 3);
}

TEST_F(Test_Lc0918, Case2)
{
    vector<int> nums = {5,-3,5};
    RunTest(nums, 10);
}

TEST_F(Test_Lc0918, Case3)
{
    vector<int> nums = {3,-2, 2,-3};
    RunTest(nums, 3);
}
