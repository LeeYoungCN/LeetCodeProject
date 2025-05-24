/*
 * Time : 2025-05-24 13:37:13
 * URL  : https://leetcode.cn/problems/house-robber/
 */
#include "lc0198_house_robber.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <vector>

using namespace std;

int LC0198_HouseRobber::rob(std::vector<int>& nums)
{
    uint32_t length = nums.size();
    vector<int32_t> dp(length);

    if (length == 1) {
        return nums[0];
    }
    if (length == 2) {
        return max(nums[0], nums[1]);
    }
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (uint32_t i = 2; i < length; i++) {
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }
    return dp.back();
}
