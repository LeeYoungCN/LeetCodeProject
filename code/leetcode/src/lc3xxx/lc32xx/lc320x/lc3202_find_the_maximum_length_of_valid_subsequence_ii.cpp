/*
 * Time : 2025-07-17 15:26:19
 * URL  :
 * https://leetcode.cn/problems/find-the-maximum-length-of-valid-subsequence-ii/description/?envType=daily-question&envId=2025-07-17
 */
#include "lc3xxx/lc32xx/lc320x/lc3202_find_the_maximum_length_of_valid_subsequence_ii.h"

#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;

int32_t LC3202_FindTheMaximumLengthOfValidSubsequenceII_DP::maximumLength(std::vector<int32_t>& nums, int32_t k)
{
    int32_t ans = 0;
    vector<vector<int32_t>> dp(static_cast<uint32_t>(k), vector<int32_t>(static_cast<uint32_t>(k), 0));

    for (const auto& num : nums) {
        const auto remainder = static_cast<uint32_t>(num % k);
        for (uint32_t i = 0; i < static_cast<uint32_t>(k); ++i) {
            dp[i][remainder] = dp[remainder][i] + 1;
            ans = max(ans, dp[i][remainder]);
        }
    }

    return ans;
}

int32_t LC3202_FindTheMaximumLengthOfValidSubsequenceII_Enum::maximumLength(std::vector<int32_t>& nums, int32_t k)
{
    int32_t ans = 0;
    const auto K = static_cast<uint32_t>(k);
    for (uint32_t i = 0; i < K; ++i) {
        vector<int32_t> dp(K, 0);
        for (const auto& num : nums) {
            const auto remainder = static_cast<uint32_t>(num % k);
            dp[remainder] = dp[(K + i - remainder) % K] + 1;
            ans = max(ans, dp[remainder]);
        }
    }
    return ans;
}
