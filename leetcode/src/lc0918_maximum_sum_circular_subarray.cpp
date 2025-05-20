// https://leetcode.cn/problems/maximum-sum-circular-subarray/
#include <cstdint>
#include <vector>
#include <algorithm>
#include "lc0918_maximum_sum_circular_subarray.h"

using namespace std;


int LC0918Solution::maxSubarraySumCircular(vector<int>& nums) {
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

