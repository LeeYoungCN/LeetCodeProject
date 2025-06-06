/*
 * Time : 2025-06-06 11:46:02
 * URL  : https://leetcode.cn/problems/longest-consecutive-sequence/description/
 */
#ifndef LC0128_LONGEST_CONSECUTIVE_SEQUENCE_H
#define LC0128_LONGEST_CONSECUTIVE_SEQUENCE_H

#include <vector>

class LC0128_LongestConsecutiveSequence {
public:
    LC0128_LongestConsecutiveSequence() = default;
    virtual ~LC0128_LongestConsecutiveSequence() = default;
    int longestConsecutive(std::vector<int>& nums);
};

#endif  // LC0128_LONGEST_CONSECUTIVE_SEQUENCE_H
