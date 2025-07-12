/*
 * Time : 2025-06-21 00:09:29
 * URL  :
 * https://leetcode.cn/problems/minimum-deletions-to-make-string-k-special/description/?envType=daily-question&envId=2025-06-21
 */
#include "lc3xxx/lc30xx/lc308x/lc3085_minimum_deletions_to_make_string_k_special.h"

#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

int LC3085_MinimumDeletionsToMakeStringKSpecial::minimumDeletions(string word, int k)
{
    constexpr uint32_t CHAR_NUM = 26;
    vector<int32_t> charCntList(CHAR_NUM, 0);

    for (char c : word) {
        charCntList[static_cast<uint32_t>(c - 'a')]++;
    }

    sort(charCntList.begin(), charCntList.end());

    int32_t ans = INT32_MAX;
    uint32_t start = 0;

    while (word[start] == 0) {
        start++;
    }

    for (uint32_t i = start; i < CHAR_NUM; i++) {
        int32_t minCnt = charCntList[i];
        int32_t maxCnt = charCntList[i] + k;
        int32_t tmp = 0;
        for (uint32_t j = start; j < CHAR_NUM; j++) {
            tmp += (charCntList[j] < minCnt ? charCntList[j] : 0);
            tmp += (charCntList[j] > maxCnt ? charCntList[j] - maxCnt : 0);
        }
        ans = min(ans, tmp);
    }
    return ans;
}
