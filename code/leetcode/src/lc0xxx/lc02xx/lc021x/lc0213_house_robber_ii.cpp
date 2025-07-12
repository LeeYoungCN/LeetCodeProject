/*
 * Time : 2025-05-24 14:22:36
 * URL  : https://leetcode.cn/problems/house-robber-ii/
 */
#include "lc0xxx/lc02xx/lc021x/lc0213_house_robber_ii.h"

#include <cstdint>
#include <vector>

using namespace std;

int32_t robSubArray(const vector<int32_t> nums, uint32_t start, uint32_t end)
{
    vector<int32_t> dp(end);
    if (end - start >= 1) {
        dp[start] = nums[start];
    }

    if (end - start >= 2) {
        dp[start + 1] = max(nums[start], nums[start + 1]);
    }

    for (uint32_t i = start + 2; i < end; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[end - 1];
}

int LC0213_HouseRobberII::rob(std::vector<int>& nums)
{
    auto length = static_cast<uint32_t>(nums.size());

    if (length == 1) {
        return nums[0];
    }

    return max(robSubArray(nums, 0, length - 1), robSubArray(nums, 1, length));
}
