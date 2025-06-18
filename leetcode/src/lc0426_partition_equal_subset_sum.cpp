/*
 * Time : 2025-05-27 18:47:36
 * URL  : https://leetcode.cn/problems/partition-equal-subset-sum/
 */
#include "lc0426_partition_equal_subset_sum.h"

#include <algorithm>
#include <cstdint>
#include <numeric>
#include <vector>

using namespace std;

bool LC0426_PartitionEqualSubsetSum_DP1::canPartition(std::vector<int>& nums)
{
    auto numCnt = static_cast<uint32_t>(nums.size());
    if (numCnt < 2) {
        return false;
    }

    int32_t sum = accumulate(nums.begin(), nums.end(), 0);
    const auto maxItr = max_element(nums.begin(), nums.end());

    if (sum % 2 == 1) {
        return false;
    }

    const uint32_t target = static_cast<uint32_t>(sum) / 2;
    if (target < static_cast<uint32_t>(*maxItr)) {
        return false;
    }

    vector<vector<bool>> dp(numCnt, vector<bool>((target + 1), false));

    dp[0][static_cast<uint32_t>(nums[0])] = true;
    for (uint32_t i = 1; i < numCnt; i++) {
        auto n = static_cast<uint32_t>(nums[i]);
        for (uint32_t j = 0; j <= target; j++) {
            if (j == 0) {
                dp[i][j] = true;
                continue;
            }

            if (j < n) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - n];
            }
        }
    }

    return dp[numCnt - 1][target];
}

bool LC0426_PartitionEqualSubsetSum_DP2::canPartition(std::vector<int>& nums)
{
    const auto numCnt = static_cast<uint32_t>(nums.size());
    if (numCnt < 2) {
        return false;
    }

    int32_t sum = accumulate(nums.begin(), nums.end(), 0);
    const auto maxItr = max_element(nums.begin(), nums.end());

    if (sum % 2 == 1) {
        return false;
    }
    uint32_t target = static_cast<uint32_t>(sum) / 2;
    if (target < static_cast<uint32_t>(*maxItr)) {
        return false;
    }
    vector<bool> dp(target + 1, false);

    dp[0] = true;
    for (uint32_t i = 1; i < numCnt; i++) {
        auto n = static_cast<uint32_t>(nums[i]);
        dp[n] = true;
        for (uint32_t j = target; j > n; --j) {
            dp[j] = dp[j] || dp[j - n];
        }
    }

    return dp[target];
}
