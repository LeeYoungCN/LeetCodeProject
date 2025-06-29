/*
 * Time : 2025-06-29 18:45:48
 * URL  : https://leetcode.cn/problems/combination-sum/
 */
#ifndef LC0039_COMBINATION_SUM_H
#define LC0039_COMBINATION_SUM_H

#include <cstdint>
#include <vector>

class LC0039_CombinationSum {
public:
    LC0039_CombinationSum() = default;
    virtual ~LC0039_CombinationSum() = default;
    std::vector<std::vector<int32_t>> combinationSum(std::vector<int32_t>& candidates, int32_t target);
};

#endif  // LC0039_COMBINATION_SUM_H
