/*
 * Time : 2025-06-20 22:43:05
 * URL  : https://leetcode.cn/problems/edit-distance/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#include "lc0072_edit_distance.h"

#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

int LC0072_EditDistance::minDistance(string word1, string word2)
{
    const auto rowCnt = static_cast<uint32_t>(word1.length());
    const auto colCnt = static_cast<uint32_t>(word2.length());

    if (rowCnt == 0 || colCnt == 0) {
        return static_cast<int32_t>(rowCnt + colCnt);
    }

    vector<vector<uint32_t>> dp(rowCnt + 1, vector<uint32_t>(colCnt + 1, 0));

    for (uint32_t i = 0; i <= rowCnt; ++i) {
        dp[i][0] = i;
    }

    for (uint32_t j = 0; j <= colCnt; ++j) {
        dp[0][j] = j;
    }

    for (uint32_t i = 1; i <= rowCnt; ++i) {
        for (uint32_t j = 1; j <= colCnt; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1]});
            } else {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
    }

    return static_cast<int32_t>(dp[rowCnt][colCnt]);
}
