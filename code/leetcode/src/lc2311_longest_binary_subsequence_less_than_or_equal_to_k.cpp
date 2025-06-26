/*
 * Time : 2025-06-26 18:52:09
 * URL  :
 * https://leetcode.cn/problems/longest-binary-subsequence-less-than-or-equal-to-k/description/?envType=daily-question&envId=2025-06-26
 */
#include "lc2311_longest_binary_subsequence_less_than_or_equal_to_k.h"

#include <bit>
#include <cstddef>
#include <cstdint>
#include <string>

using namespace std;

int LC2311_LongestBinarySubsequenceLessThanOrEqualToK::longestSubsequence(std::string s, int k)
{
    auto maxBitLen = static_cast<size_t>(bit_width(static_cast<uint32_t>(k)));
    if (maxBitLen > s.length()) {
        return static_cast<int32_t>(s.length());
    }

    int32_t suffixVal = stoi(s.substr(s.length() - maxBitLen, maxBitLen), nullptr, 2);
    size_t ans = maxBitLen - (suffixVal > k ? 1 : 0);
    for (size_t i = 0; i < s.length() - maxBitLen; i++) {
        if (s[i] == '0') {
            ans++;
        }
    }

    return static_cast<int32_t>(ans);
}
