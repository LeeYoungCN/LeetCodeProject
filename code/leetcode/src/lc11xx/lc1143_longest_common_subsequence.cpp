/*
 * Time : 2025-06-21 19:36:30
 * URL  : https://leetcode.cn/problems/longest-common-subsequence/description/
 */
#include "lc11xx/lc1143_longest_common_subsequence.h"

#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

int LC1143_LongestCommonSubsequence::longestCommonSubsequence(std::string text1, std::string text2)
{
    const auto rowCnt = static_cast<uint32_t>(text1.length());
    const auto colCnt = static_cast<uint32_t>(text2.length());

    if (rowCnt == 0 || colCnt == 0) {
        return 0;
    }

    vector<vector<int32_t>> dp(rowCnt + 1, vector<int32_t>(colCnt + 1, 0));
    for (uint32_t i = 1; i <= rowCnt; i++) {
        for (uint32_t j = 1; j <= colCnt; j++) {
            if (text2[j - 1] == text1[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[rowCnt][colCnt];
}
