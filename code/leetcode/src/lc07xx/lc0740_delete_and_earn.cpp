/*
 * Time : 2025-06-03 14:12:55
 * URL  : https://leetcode.cn/problems/delete-and-earn/description/
 */

#include "lc07xx/lc0740_delete_and_earn.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

int LC0740_DeleteAndEarn::deleteAndEarn(std::vector<int>& nums)
{
    const auto pair = minmax_element(nums.begin(), nums.end());

    const int32_t maxNum = *(pair.second);
    const int32_t minNum = *(pair.first);

    const auto length = static_cast<uint32_t>(maxNum - minNum + 1);

    vector<int32_t> sumArray(length, 0);
    for (int32_t n : nums) {
        sumArray[static_cast<uint32_t>(n - minNum)] += n;
    }

    vector<int32_t> dp(length, 0);

    dp[0] = sumArray[0];
    if (length > 1) {
        dp[1] = max(sumArray[1], sumArray[0]);
    }

    for (uint32_t i = 2; i < length; i++) {
        dp[i] = max(dp[i - 2] + sumArray[i], dp[i - 1]);
    }

    return dp.back();
}
