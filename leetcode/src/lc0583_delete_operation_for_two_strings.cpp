/*
 * Time : 2025-06-21 18:03:05
 * URL  : https://leetcode.cn/problems/delete-operation-for-two-strings/
 */
#include "lc0583_delete_operation_for_two_strings.h"

#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

int LC0583_DeleteOperationForTwoStrings_MinDelete::minDistance(std::string word1, std::string word2)
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
                dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2});
            }
        }
    }

    return static_cast<int32_t>(dp[rowCnt][colCnt]);
}

int LC0583_DeleteOperationForTwoStrings_MaxCommon::minDistance(std::string word1, std::string word2)
{
    const auto rowCnt = static_cast<uint32_t>(word1.length());
    const auto colCnt = static_cast<uint32_t>(word2.length());

    if (rowCnt == 0 || colCnt == 0) {
        return static_cast<int32_t>(rowCnt + colCnt);
    }

    vector<vector<uint32_t>> dp(rowCnt + 1, vector<uint32_t>(colCnt + 1, 0));

    for (uint32_t i = 1; i <= rowCnt; ++i) {
        for (uint32_t j = 1; j <= colCnt; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return static_cast<int32_t>(rowCnt + colCnt - 2 * dp[rowCnt][colCnt]);
}
