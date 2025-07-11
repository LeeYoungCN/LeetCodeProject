/*
 * Time : 2025-07-11 10:44:22
 * URL  : https://leetcode.cn/problems/merge-intervals/
 */
#ifndef LC0056_MERGE_INTERVALS_H
#define LC0056_MERGE_INTERVALS_H

#include <cstdint>
#include <vector>

class LC0056_MergeIntervals {
public:
    LC0056_MergeIntervals() = default;
    virtual ~LC0056_MergeIntervals() = default;
    std::vector<std::vector<int32_t>> merge(std::vector<std::vector<int32_t>>& intervals);
};

#endif  // LC0056_MERGE_INTERVALS_H
