/*
 * Time : 2025-07-13 17:59:31
 * URL  : https://leetcode.cn/problems/combination-sum-ii/description/
 */
#ifndef LC0040_COMBINATION_SUM_II_H
#define LC0040_COMBINATION_SUM_II_H

#include <cstddef>
#include <cstdint>
#include <vector>

class LC0040_CombinationSumII {
public:
    LC0040_CombinationSumII() = default;
    virtual ~LC0040_CombinationSumII() = default;
    std::vector<std::vector<int32_t>> combinationSum2(std::vector<int32_t>& candidates, int32_t target);

private:
    void dfs(size_t idx, int32_t target);

private:
    std::vector<int32_t> candidates;
    std::vector<std::vector<int32_t>> ans;
    std::vector<int32_t> currVec;
};

#endif  // LC0040_COMBINATION_SUM_II_H
