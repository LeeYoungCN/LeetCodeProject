/*
 * Time : 2025-06-28 00:18:24
 * URL  :
 * https://leetcode.cn/problems/find-subsequence-of-length-k-with-the-largest-sum/?envType=daily-question&envId=2025-06-28
 */
#ifndef LC2099_FIND_SUBSEQUENCE_OF_LENGTH_K_WITH_THE_LARGEST_SUM_H
#define LC2099_FIND_SUBSEQUENCE_OF_LENGTH_K_WITH_THE_LARGEST_SUM_H

#include <vector>

class LC2099_FindSubsequenceOfLengthKWithTheLargestSum {
public:
    LC2099_FindSubsequenceOfLengthKWithTheLargestSum() = default;
    virtual ~LC2099_FindSubsequenceOfLengthKWithTheLargestSum() = default;
    std::vector<int> maxSubsequence(std::vector<int>& nums, int k);
};

#endif  // LC2099_FIND_SUBSEQUENCE_OF_LENGTH_K_WITH_THE_LARGEST_SUM_H
