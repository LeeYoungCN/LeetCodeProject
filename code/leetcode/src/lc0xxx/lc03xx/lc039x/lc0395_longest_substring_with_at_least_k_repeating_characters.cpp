/*
 * Time : 2025-06-28 15:40:11
 * URL  : https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/
 */
#include "lc0xxx/lc03xx/lc039x/lc0395_longest_substring_with_at_least_k_repeating_characters.h"

#include <algorithm>
#include <cstdint>
#include <string>

using namespace std;

int LC0395_LongestSubstringWithAtLeastKRepeatingCharacters::longestSubstring(std::string s, int k)
{
    constexpr uint32_t CHAR_CNT = 26;
    uint32_t ans = 0;

    for (uint32_t maxCharTypeCnt = 1; maxCharTypeCnt <= CHAR_CNT; ++maxCharTypeCnt) {
        uint32_t charCount[CHAR_CNT] = {0};
        uint32_t left = 0;
        uint32_t currCharTypeCnt = 0;
        uint32_t invalidCharCnt = 0;
        for (uint32_t right = 1; right <= s.length(); right++) {
            char rightChar = s[right - 1];
            charCount[rightChar - 'a']++;

            if (charCount[rightChar - 'a'] == 1) {
                invalidCharCnt++;
                currCharTypeCnt++;
            }

            if (charCount[rightChar - 'a'] >= static_cast<uint32_t>(k)) {
                if (charCount[rightChar - 'a'] == static_cast<uint32_t>(k)) {
                    invalidCharCnt--;
                }
                if (invalidCharCnt == 0) {
                    ans = max(ans, right - left);
                }
            }

            for (; currCharTypeCnt > maxCharTypeCnt && left < right; left++) {
                char leftChar = s[left];
                charCount[leftChar - 'a']--;
                if (charCount[leftChar - 'a'] == 0) {
                    currCharTypeCnt--;
                    invalidCharCnt--;
                } else if (charCount[leftChar - 'a'] == static_cast<uint32_t>(k - 1)) {
                    invalidCharCnt++;
                }
            }
        }
    }

    return static_cast<int32_t>(ans);
}
