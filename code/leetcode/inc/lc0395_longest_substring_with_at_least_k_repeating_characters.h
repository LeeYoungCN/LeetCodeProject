/*
 * Time : 2025-06-28 15:40:11
 * URL  : https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/
 */
#ifndef LC0395_LONGEST_SUBSTRING_WITH_AT_LEAST_K_REPEATING_CHARACTERS_H
#define LC0395_LONGEST_SUBSTRING_WITH_AT_LEAST_K_REPEATING_CHARACTERS_H

#include <string>

class LC0395_LongestSubstringWithAtLeastKRepeatingCharacters {
public:
    LC0395_LongestSubstringWithAtLeastKRepeatingCharacters() = default;
    virtual ~LC0395_LongestSubstringWithAtLeastKRepeatingCharacters() = default;
    int longestSubstring(std::string s, int k);
};

#endif  // LC0395_LONGEST_SUBSTRING_WITH_AT_LEAST_K_REPEATING_CHARACTERS_H
