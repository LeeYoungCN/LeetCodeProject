/*
 * Time : 2025-05-20 01:28:53
 * URL  : https://leetcode.cn/problems/maximum-subarray/description/
 */
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include "lc0053_maximum_subarray.h"

using namespace std;

int LC0053_MaximumSubarray::maxSubArray(vector<int>& nums)
{
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
