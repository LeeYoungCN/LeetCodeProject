/*
 * Time : 2025-05-20 01:28:53
 * URL  : https://leetcode.cn/problems/maximum-subarray/description/
 */
#include "lc0053_maximum_subarray.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

int LC0053_MaximumSubarray_dp::maxSubArray(vector<int>& nums)
{
    int ret = INT32_MIN;
    const uint32_t length = (uint32_t)nums.size();
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

int LC0053_MaximumSubarray_stack::maxSubArray(vector<int>& nums)
{
    const uint32_t length = (uint32_t)nums.size();
    vector<int32_t> stack;
    stack.reserve(length + 1);
    stack.push_back(0);

    int32_t sum = 0;
    int32_t ret = nums[0];
    for (int32_t n : nums) {
        sum += n;
        ret = max(ret, sum - stack[0]);
        while (!stack.empty() && *(stack.end() - 1) > sum) {
            stack.pop_back();
        }
        stack.push_back(sum);
    }
    return ret;
}
