/*
 * Time : 2025-06-23 21:08:36
 * URL  :
 * https://leetcode.cn/problems/interleaving-string/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#include "lc0xxx/lc00xx/lc009x/lc0097_interleaving_string.h"

#include <cstdint>
#include <string>
#include <vector>

using namespace std;

bool LC0097_InterleavingString::isInterleave(std::string s1, std::string s2, std::string s3)
{
    const auto length1 = static_cast<uint32_t>(s1.size());
    const auto length2 = static_cast<uint32_t>(s2.size());

    if (length1 + length2 != s3.size()) {
        return false;
    }

    vector<vector<bool>> dp(length1 + 1, vector<bool>(length2 + 1, false));

    dp[0][0] = true;

    for (uint32_t i = 0; i <= length1; ++i) {
        for (uint32_t j = 0; j <= length2; ++j) {
            uint32_t p = i + j - 1;
            if (i > 0) {
                dp[i][j] = dp[i][j] || ((s1[i - 1] == s3[p]) && dp[i - 1][j]);
            }

            if (j > 0) {
                dp[i][j] = dp[i][j] || ((s2[j - 1] == s3[i + j - 1]) && dp[i][j - 1]);
            }
        }
    }

    return dp[length1][length2];
}
