/*
 * Time : 2025-05-27 18:47:36
 * URL  : https://leetcode.cn/problems/partition-equal-subset-sum/
 */
#include "lc0426_partition_equal_subset_sum.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool LC0426_PartitionEqualSubsetSum_DP1::canPartition(std::vector<int>& nums)
{
    int32_t numCnt = nums.size();
    if (numCnt < 2) {
        return false;
    }

    int32_t sum = accumulate(nums.begin(), nums.end(), 0);
    vector<int32_t>::iterator maxItr = max_element(nums.begin(), nums.end());

    if (sum % 2 == 1) {
        return false;
    }

    int32_t target = sum / 2;
    if (target < *maxItr) {
        return false;
    }

    // i 数组当前的长度
    // j 刚好达到的值
    vector<vector<bool>> dp(numCnt, vector<bool>(target + 1, false));

    dp[0][nums[0]] = true;
    for (int32_t i = 1; i < numCnt; i++) {
        int32_t n = nums[i];
        for (int32_t j = 0; j <= target; j++) {
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
    int32_t numCnt = nums.size();
    if (numCnt < 2) {
        return false;
    }

    int32_t sum = accumulate(nums.begin(), nums.end(), 0);
    vector<int32_t>::iterator maxItr = max_element(nums.begin(), nums.end());

    if (sum % 2 == 1) {
        return false;
    }
    int32_t target = sum / 2;
    if (target < *maxItr) {
        return false;
    }
    vector<bool> dp(target + 1, false);

    dp[0] = true;
    for (int32_t i = 1; i < numCnt; i++) {
        int32_t n = nums[i];
        dp[n] = true;
        for (int32_t j = target; j > n; --j) {
            dp[j] = dp[j] || dp[j - n];
        }
    }

    return dp[target];
}
