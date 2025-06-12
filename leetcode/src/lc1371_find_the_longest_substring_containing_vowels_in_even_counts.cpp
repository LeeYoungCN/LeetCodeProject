/*
 * Time : 2025-06-11 13:21:38
 * URL  : https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/
 */
#include "lc1371_find_the_longest_substring_containing_vowels_in_even_counts.h"

#include <cstdint>
#include <vector>

using namespace std;

int32_t LC1371_FindTheLongestSubstringContainingVowelsInEvenCounts::findTheLongestSubstring(string s)
{
    const auto length = static_cast<uint32_t>(s.size());
    vector<uint32_t> position(1 << 5, length);
    position[0] = 0;

    uint32_t ans = 0;
    uint32_t status = 0;

    for (uint32_t i = 0; i < length; i++) {
        switch (s[i]) {
            case 'a':
                status ^= 1;
                break;
            case 'e':
                status ^= 2;
                break;
            case 'i':
                status ^= 4;
                break;
            case 'o':
                status ^= 8;
                break;
            case 'u':
                status ^= 16;
                break;
            default:
                break;
        }

        printf("i = %u, status = %u\n", i, status);

        if (position[status] == length) {
            position[status] = i + 1;
        } else {
            ans = max(ans, i - position[status] + 1);
        }
    }

    return static_cast<int32_t>(ans);
}
