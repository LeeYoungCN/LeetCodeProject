/*
 * Time : 2025-07-18 16:36:45
 * URL  :
 * https://leetcode.cn/problems/count-sorted-vowel-strings/description/?envType=problem-list-v2&envId=dynamic-programming
 */
#include "lc1xxx/lc16xx/lc164x/lc1641_count_sorted_vowel_strings.h"

#include <cstdint>
#include <numeric>
#include <vector>

using namespace std;

int32_t LC1641_CountSortedVowelStrings::countVowelStrings(int32_t n)
{
    constexpr uint32_t VOWEL_CNT = 5;
    vector<vector<int32_t>> dp(2, vector<int32_t>(VOWEL_CNT, 0));
    uint32_t prev = 0;
    uint32_t curr = 1;
    for (uint32_t i = 0; i < static_cast<uint32_t>(n); i++) {
        for (uint32_t j = 0; j < VOWEL_CNT; j++) {
            if (i == 0 || j == 0) {
                dp[curr][j] = 1;
            } else {
                dp[curr][j] = dp[curr][j - 1] + dp[prev][j];
            }
        }
        curr = 1 - curr;
        prev = 1 - prev;
    }
    return accumulate(dp[prev].begin(), dp[prev].end(), 0);
}
