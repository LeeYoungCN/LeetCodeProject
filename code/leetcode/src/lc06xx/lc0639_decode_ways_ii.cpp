/*
 * Time : 2025-06-22 23:57:26
 * URL  : https://leetcode.cn/problems/decode-ways-ii/
 */
#include "lc06xx/lc0639_decode_ways_ii.h"

#include <cstdint>
#include <string>
#include <vector>

using namespace std;

int LC0639_DecodeWaysII::numDecodings(std::string s)
{
    constexpr int32_t MOD = 1000000007;

    if (s[0] == '0') {
        return 0;
    }
    const auto length = static_cast<uint32_t>(s.length());
    vector<int64_t> dp(length, 0);

    int32_t range1 = ('9' - '1' + 1);
    int32_t range2 = ('6' - '1' + 1);

    dp[0] = (s[0] == '*' ? range1 : 1);
    for (uint32_t i = 1; i < length; i++) {
        if (s[i] != '0') {
            dp[i] = (s[i] == '*' ? range1 : 1) * dp[i - 1];
        }

        if (s[i] == '*') {
            // ** 15
            // 1* 9
            // 2* 6
            if (s[i - 1] == '1' || s[i - 1] == '*') {
                dp[i] += range1 * (i >= 2 ? dp[i - 2] : 1);
            }
            if (s[i - 1] == '2' || s[i - 1] == '*') {
                dp[i] += range2 * (i >= 2 ? dp[i - 2] : 1);
            }
        } else {
            if (s[i - 1] == '*') {
                // *[0~6]: 2
                // *(7~9]: 1
                dp[i] += (s[i] <= '6' ? 2 : 1) * (i >= 2 ? dp[i - 2] : 1);
            } else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                // xy     1
                dp[i] += (i >= 2 ? dp[i - 2] : 1);
            }
        }
        dp[i] %= MOD;
    }

    return static_cast<int32_t>(dp[length - 1]);
}
