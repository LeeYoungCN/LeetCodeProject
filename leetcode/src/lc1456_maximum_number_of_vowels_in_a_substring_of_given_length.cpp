/*
 * Time : 2025-05-31 22:04:33
 * URL  : https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
 */
#include "lc1456_maximum_number_of_vowels_in_a_substring_of_given_length.h"

#include <algorithm>
#include <cstdint>
#include <functional>
#include <string>

using namespace std;

int LC1456_MaximumNumberOfVowelsInASubstringOfGivenLength::maxVowels(string s, int k)
{
    const auto length = static_cast<uint32_t>(s.size());

    function<bool(char)> isVowels = [](char c) -> bool {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    };

    uint32_t start = 0;
    uint32_t tmp = 0;
    uint32_t ans = 0;
    for (uint32_t i = 0; i < length; i++) {
        char c = s.at(i);
        uint32_t end = i + 1;
        if (isVowels(c)) {
            tmp++;
        }
        if (end - start > static_cast<uint32_t>(k)) {
            if (isVowels(s.at(start))) {
                tmp--;
            }
            start++;
        }
        ans = max(ans, tmp);
        if (ans >= static_cast<uint32_t>(k)) {
            return k;
        }
    }
    return static_cast<int32_t>(ans);
}
