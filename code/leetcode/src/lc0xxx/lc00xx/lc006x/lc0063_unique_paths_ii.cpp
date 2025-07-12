/*
 * Time : 2025-06-20 22:02:04
 * URL  : https://leetcode.cn/problems/unique-paths-ii/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#include "lc0xxx/lc00xx/lc006x/lc0063_unique_paths_ii.h"

#include <cstdint>
#include <vector>

using namespace std;

int32_t LC0063_UniquePathsII::uniquePathsWithObstacles(vector<vector<int32_t>>& obstacleGrid)
{
    const auto rowCnt = static_cast<uint32_t>(obstacleGrid.size());
    const auto colCnt = static_cast<uint32_t>(obstacleGrid[0].size());

    vector<vector<int32_t>> dp(rowCnt, vector<int32_t>(colCnt, 0));
    dp[0][0] = (obstacleGrid[0][0] == 0 ? 1 : 0);

    for (uint32_t i = 1; i < rowCnt; ++i) {
        dp[i][0] = (obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0]);
    }

    for (uint32_t j = 1; j < colCnt; ++j) {
        dp[0][j] = (obstacleGrid[0][j] == 1 ? 0 : dp[0][j - 1]);
    }

    for (uint32_t i = 1; i < rowCnt; ++i) {
        for (uint32_t j = 1; j < colCnt; ++j) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }

            if (i == 0 || j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[rowCnt - 1][colCnt - 1];
}
