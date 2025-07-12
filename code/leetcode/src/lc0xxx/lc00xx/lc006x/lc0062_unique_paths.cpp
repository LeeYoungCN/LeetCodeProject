/*
 * Time : 2025-06-20 16:59:36
 * URL  : https://leetcode.cn/problems/unique-paths/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#include "lc0xxx/lc00xx/lc006x/lc0062_unique_paths.h"

#include <cstdint>
#include <vector>

using namespace std;

int LC0062_UniquePaths::uniquePaths(int m, int n)
{
    const auto rowCnt = static_cast<uint32_t>(m);
    const auto colCnt = static_cast<uint32_t>(n);

    vector<vector<int32_t>> dp(rowCnt, vector<int32_t>(colCnt, 0));

    for (uint32_t i = 0; i < rowCnt; ++i) {
        for (uint32_t j = 0; j < colCnt; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[rowCnt - 1][colCnt - 1];
}
