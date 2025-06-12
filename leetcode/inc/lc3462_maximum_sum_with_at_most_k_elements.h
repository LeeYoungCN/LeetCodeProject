/*
 * Time : 2025-06-02 03:20:20
 * URL  : https://leetcode.cn/problems/maximum-sum-with-at-most-k-elements/description/
 */
#ifndef LC3462_MAXIMUM_SUM_WITH_AT_MOST_K_ELEMENTS_H
#define LC3462_MAXIMUM_SUM_WITH_AT_MOST_K_ELEMENTS_H

#include <vector>

class LC3462_MaximumSumWithAtMostKElements {
public:
    LC3462_MaximumSumWithAtMostKElements() = default;
    virtual ~LC3462_MaximumSumWithAtMostKElements() = default;
    virtual long long maxSum(std::vector<std::vector<int>>& grid, std::vector<int>& limits, int k) = 0;
};

class LC3462_MaximumSumWithAtMostKElements_Sort : public LC3462_MaximumSumWithAtMostKElements {
public:
    LC3462_MaximumSumWithAtMostKElements_Sort() = default;
    ~LC3462_MaximumSumWithAtMostKElements_Sort() override = default;
    long long maxSum(std::vector<std::vector<int>>& grid, std::vector<int>& limits, int k) final;
};

class LC3462_MaximumSumWithAtMostKElements_NthElement : public LC3462_MaximumSumWithAtMostKElements {
public:
    LC3462_MaximumSumWithAtMostKElements_NthElement() = default;
    ~LC3462_MaximumSumWithAtMostKElements_NthElement() override = default;
    long long maxSum(std::vector<std::vector<int>>& grid, std::vector<int>& limits, int k) final;
};

#endif  // LC3462_MAXIMUM_SUM_WITH_AT_MOST_K_ELEMENTS_H
