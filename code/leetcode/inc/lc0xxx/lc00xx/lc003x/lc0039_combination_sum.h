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
    virtual std::vector<std::vector<int32_t>> combinationSum(std::vector<int32_t>& candidates, int32_t target) = 0;
};

class LC0039_CombinationSum_DFS : public LC0039_CombinationSum {
public:
    LC0039_CombinationSum_DFS() = default;
    ~LC0039_CombinationSum_DFS() override = default;
    std::vector<std::vector<int32_t>> combinationSum(std::vector<int32_t>& candidates, int32_t target) override;

private:
    void dfs(const std::vector<int32_t>& candidates, std::vector<std::vector<int32_t>>& ans,
             std::vector<int32_t>& currVec, int32_t target, uint32_t startIdx);
};

class LC0039_CombinationSum_Stack : public LC0039_CombinationSum {
public:
    LC0039_CombinationSum_Stack() = default;
    ~LC0039_CombinationSum_Stack() override = default;
    std::vector<std::vector<int32_t>> combinationSum(std::vector<int32_t>& candidates, int32_t target) override;
};

#endif  // LC0039_COMBINATION_SUM_H
